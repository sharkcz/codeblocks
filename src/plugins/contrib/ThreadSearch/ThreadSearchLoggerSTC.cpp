#include <sdk.h> // Code::Blocks SDK
#ifndef CB_PRECOMP
    #include <wx/wxscintilla.h>
#endif

#include "cbcolourmanager.h"

#include "ThreadSearchEvent.h"
#include "ThreadSearchFindData.h"
#include "ThreadSearchLoggerSTC.h"

namespace
{

enum STCStyles : int
{
    File = 2,
    LineNo,
    Text,
    TextMatching
};
} // anonymous namespace

ThreadSearchLoggerSTC::ThreadSearchLoggerSTC(ThreadSearchView& threadSearchView,
                                             ThreadSearch& threadSearchPlugin,
                                             InsertIndexManager::eFileSorting fileSorting,
                                             wxWindow* parent, long id) :
    ThreadSearchLoggerBase(parent, threadSearchView, threadSearchPlugin, fileSorting)
{
    ColourManager *colours = Manager::Get()->GetColourManager();

    m_stc = new wxScintilla(this, id, wxDefaultPosition, wxDefaultSize);
    m_stc->SetCaretLineVisible(true);
    m_stc->SetCaretLineBackground(colours->GetColour(wxT("thread_search_selected_line_back")));
    m_stc->SetCaretWidth(0);
    m_stc->SetReadOnly(true);

    m_stc->StyleSetForeground(wxSCI_STYLE_DEFAULT,
                              colours->GetColour(wxT("thread_search_text_fore")));
    m_stc->StyleSetBackground(wxSCI_STYLE_DEFAULT,
                              colours->GetColour(wxT("thread_search_text_back")));

    // Spread the default colours to all styles.
    m_stc->StyleClearAll();

    m_stc->StyleSetForeground(STCStyles::File,
                              colours->GetColour(wxT("thread_search_file_fore")));
    m_stc->StyleSetBackground(STCStyles::File,
                              colours->GetColour(wxT("thread_search_file_back")));

    m_stc->StyleSetForeground(STCStyles::LineNo,
                              colours->GetColour(wxT("thread_search_lineno_fore")));
    m_stc->StyleSetBackground(STCStyles::LineNo,
                              colours->GetColour(wxT("thread_search_lineno_back")));

    m_stc->StyleSetForeground(STCStyles::Text,
                              colours->GetColour(wxT("thread_search_text_fore")));
    m_stc->StyleSetBackground(STCStyles::Text,
                              colours->GetColour(wxT("thread_search_text_back")));

    m_stc->StyleSetForeground(STCStyles::TextMatching,
                              colours->GetColour(wxT("thread_search_match_fore")));
    m_stc->StyleSetBackground(STCStyles::TextMatching,
                              colours->GetColour(wxT("thread_search_match_back")));

    SetupSizer(m_stc);
}

void ThreadSearchLoggerSTC::RegisterColours()
{
    ColourManager *colours = Manager::Get()->GetColourManager();

    const wxColour defaultBg = wxSystemSettings::GetColour(wxSYS_COLOUR_LISTBOX);
    const wxColour defaultFg = wxSystemSettings::GetColour(wxSYS_COLOUR_LISTBOXTEXT);

    colours->RegisterColour(wxT("Thread Search"), wxT("File foreground"),
                            wxT("thread_search_file_fore"), wxColour(255, 0, 255));
    colours->RegisterColour(wxT("Thread Search"), wxT("File background"),
                            wxT("thread_search_file_back"), defaultBg);

    colours->RegisterColour(wxT("Thread Search"), wxT("Line foreground"),
                            wxT("thread_search_lineno_fore"), wxColour(0, 0, 255));
    colours->RegisterColour(wxT("Thread Search"), wxT("Line background"),
                            wxT("thread_search_lineno_back"), defaultBg);

    colours->RegisterColour(wxT("Thread Search"), wxT("Text foreground"),
                            wxT("thread_search_text_fore"), defaultFg);
    colours->RegisterColour(wxT("Thread Search"), wxT("Text background"),
                            wxT("thread_search_text_back"), defaultBg);

    colours->RegisterColour(wxT("Thread Search"), wxT("Matching text foreground"),
                            wxT("thread_search_match_fore"), wxColor(255, 0, 0));
    colours->RegisterColour(wxT("Thread Search"), wxT("Matching text background"),
                            wxT("thread_search_match_back"), defaultBg);

    colours->RegisterColour(wxT("Thread Search"), wxT("Selected line background"),
                            wxT("thread_search_selected_line_back"),
                            wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
}

ThreadSearchLoggerBase::eLoggerTypes ThreadSearchLoggerSTC::GetLoggerType()
{
    return TypeSTC;
}

void ThreadSearchLoggerSTC::OnThreadSearchEvent(const ThreadSearchEvent& event)
{
    const wxArrayString& words = event.GetLineTextArray();
    const wxString &filename = event.GetString();
    const std::vector<int> &matchedPositions = event.GetMatchedPositions();

    ++m_fileCount;
    m_totalCount += words.size() / 2;

    m_stc->Freeze();
    m_stc->SetReadOnly(false);

    AppendStyledText(STCStyles::File, wxString::Format(wxT("%s (%d matches)\n"), filename.wx_str(),
                                                       words.size() / 2));

    // The only reason it is constructed here is to preserve the allocated space between loop
    // iterations.
    wxString justifier;

    std::vector<int>::const_iterator matchedIt = matchedPositions.begin();

    for (size_t ii = 0; ii + 1 < words.GetCount(); ii += 2)
    {
        justifier.clear();

        const wxString &lineNoStr = words[ii];
        if (lineNoStr.length() < 10)
        {
            justifier.Append(wxT(' '), 10 - lineNoStr.length());
        }

        AppendStyledText(STCStyles::LineNo, justifier + lineNoStr + wxT(':'));

        const int textStart = m_stc->GetLength() + 1;

        AppendStyledText(STCStyles::Text, wxT('\t') + words[ii + 1] + wxT('\n'));

        {
            const int matchedCount = *matchedIt;
            ++matchedIt;

            for (int ii = 0; ii < matchedCount; ++ii)
            {
                const int start = *matchedIt;
                ++matchedIt;
                const int length = *matchedIt;
                ++matchedIt;

                m_stc->StartStyling(textStart + start);
                m_stc->SetStyling(length, STCStyles::TextMatching);
            }
        }
    }

    m_stc->SetReadOnly(true);
    m_stc->Thaw();
}

void ThreadSearchLoggerSTC::Clear()
{
    m_stc->Clear();
}

void ThreadSearchLoggerSTC::OnSearchBegin(const ThreadSearchFindData& findData)
{
    m_fileCount = 0;
    m_totalCount = 0;

    m_startLine = std::max(0, m_stc->LineFromPosition(m_stc->GetLength()) - 1);

    m_stc->SetReadOnly(false);
    m_stc->AppendText(wxT("=> Searching for ") + findData.GetFindText() + wxT('\n'));
    m_stc->SetReadOnly(true);

    m_stc->SetFirstVisibleLine(m_startLine);
}

void ThreadSearchLoggerSTC::OnSearchEnd()
{
    m_stc->SetReadOnly(false);
    m_stc->AppendText(wxString::Format(wxT("=> Finished! Found: %d in %d files\n\n\n"), m_totalCount,
                                       m_fileCount));
    m_stc->SetReadOnly(true);

    m_stc->SetFirstVisibleLine(m_startLine);
}

wxWindow* ThreadSearchLoggerSTC::GetWindow()
{
    return m_stc;
}

void ThreadSearchLoggerSTC::SetFocus()
{
    m_stc->SetFocus();
}

void ThreadSearchLoggerSTC::AppendStyledText(int style, const wxString &text)
{
    m_stc->StartStyling(m_stc->GetLength());
    m_stc->AppendText(text);
    m_stc->SetStyling(text.length(), style);
}

void ThreadSearchLoggerSTC::ConnectEvents(wxEvtHandler* pEvtHandler)
{
}

void ThreadSearchLoggerSTC::DisconnectEvents(wxEvtHandler* pEvtHandler)
{
}
