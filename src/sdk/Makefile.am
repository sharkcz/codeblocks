SUBDIRS = scripting wxscintilla resources
DIST_SUBDIRS = scripting wxscintilla resources

AM_CPPFLAGS = $(WX_CXXFLAGS) \
			$(CB_GLIB2_CFLAGS) \
			$(CB_SQUIRREL_CFLAGS) \
			-I$(top_srcdir)/src/include \
			-I$(top_srcdir)/src/sdk/wxscintilla/include \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include/mfbt \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include/nsprpub/pr/include \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include/xpcom \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include/xpcom/base \
			-I$(top_srcdir)/src/sdk/mozilla_chardet/include/xpcom/glue

if CODEBLOCKS_NT
AM_CPPFLAGS += -DEXPORT_LIB -DEXPORT_EVENTS -DWXMAKINGDLL_SCI
endif

lib_LTLIBRARIES = libcodeblocks.la

libcodeblocks_la_LDFLAGS = -no-undefined -version-info @CODEBLOCKS_VERSION_INFO@

libcodeblocks_la_LIBADD = scripting/bindings/libsqbindings.la \
			wxscintilla/libwxscintilla.la \
			$(WX_LIBS) \
			$(SCINTILLA_GTK_LIBS) \
			$(CB_GLIB2_LIBS) \
			$(CB_TINYXML_LIBS) \
			$(CB_SQUIRREL_LIBS)

if CODEBLOCKS_NT
libcodeblocks_la_LIBADD += -lgdi32
endif

libcodeblocks_la_SOURCES = annoyingdialog.cpp \
						autodetectcompilers.cpp \
						base64.cpp \
						blockallocated.cpp \
						cbart_provider.cpp \
						cbauibook.cpp \
						cbcolourmanager.cpp \
						cbdebugger_interfaces.cpp \
						cbeditor.cpp \
						cbeditorprintout.cpp \
						cbexception.cpp \
						cbplugin.cpp \
						cbproject.cpp \
						cbstatusbar.cpp \
						cbstyledtextctrl.cpp \
						cbthreadpool.cpp \
						cbtreectrl.cpp \
						cbworkspace.cpp \
						ccmanager.cpp \
						compileoptionsbase.cpp \
						compiler.cpp \
						compilercommandgenerator.cpp \
						compilerfactory.cpp \
						compileroptions.cpp \
						compiletargetbase.cpp \
						configmanager-revision.cpp \
						configmanager.cpp \
						configurationpanel.cpp \
						configuretoolsdlg.cpp \
						confirmreplacedlg.cpp \
						crc32.cpp \
						cygwin.cpp \
						debuggermanager.cpp \
						editarrayfiledlg.cpp \
						editarrayorderdlg.cpp \
						editarraystringdlg.cpp \
						editor_hooks.cpp \
						editor_utils.cpp \
						editorbase.cpp \
						editorcolourset.cpp \
						editorlexerloader.cpp \
						editormanager.cpp \
						editpairdlg.cpp \
						editpathdlg.cpp \
						edittooldlg.cpp \
						encodingdetector.cpp \
						externaldepsdlg.cpp \
						filefilters.cpp \
						filegroupsandmasks.cpp \
						filemanager.cpp \
						findreplacedlg.cpp \
						genericmultilinenotesdlg.cpp \
						globals.cpp \
						importers_globals.cpp \
						incremental_select_helper.cpp \
						infowindow.cpp \
						loggers.cpp \
						logmanager.cpp \
						macrosmanager.cpp \
						manager.cpp \
						menuitemsmanager.cpp \
						multiselectdlg.cpp \
						newfromtemplatedlg.cpp \
						personalitymanager.cpp \
						pipedprocess.cpp \
						pluginmanager.cpp \
						pluginsconfigurationdlg.cpp \
						printing_types.cpp \
						projectbuildtarget.cpp \
						projectfile.cpp \
						projectfileoptionsdlg.cpp \
						projectlayoutloader.cpp \
						projectloader.cpp \
						projectloader_hooks.cpp \
						projectmanager.cpp \
						projectsfilemasksdlg.cpp \
						projecttemplateloader.cpp \
						scriptingmanager.cpp \
						scriptsecuritywarningdlg.cpp \
						scrollingdialog.cpp \
						sdk_events.cpp \
						searchresultslog.cpp \
						selecttargetdlg.cpp \
						templatemanager.cpp \
						tinywxuni.cpp \
						toolsmanager.cpp \
						uservarmanager.cpp \
						workspaceloader.cpp \
						xtra_res.cpp  \
						mozilla_chardet/src/CharDistribution.cpp \
						mozilla_chardet/src/JpCntx.cpp \
						mozilla_chardet/src/LangBulgarianModel.cpp \
						mozilla_chardet/src/LangCyrillicModel.cpp \
						mozilla_chardet/src/LangGreekModel.cpp \
						mozilla_chardet/src/LangHebrewModel.cpp \
						mozilla_chardet/src/LangHungarianModel.cpp \
						mozilla_chardet/src/LangThaiModel.cpp \
						mozilla_chardet/src/nsBig5Prober.cpp \
						mozilla_chardet/src/nsCharSetProber.cpp \
						mozilla_chardet/src/nsEscCharsetProber.cpp \
						mozilla_chardet/src/nsEscSM.cpp \
						mozilla_chardet/src/nsEUCJPProber.cpp \
						mozilla_chardet/src/nsEUCKRProber.cpp \
						mozilla_chardet/src/nsEUCTWProber.cpp \
						mozilla_chardet/src/nsGB2312Prober.cpp \
						mozilla_chardet/src/nsHebrewProber.cpp \
						mozilla_chardet/src/nsLatin1Prober.cpp \
						mozilla_chardet/src/nsMBCSGroupProber.cpp \
						mozilla_chardet/src/nsMBCSSM.cpp \
						mozilla_chardet/src/nsSBCharSetProber.cpp \
						mozilla_chardet/src/nsSBCSGroupProber.cpp \
						mozilla_chardet/src/nsSJISProber.cpp \
						mozilla_chardet/src/nsUniversalDetector.cpp \
						mozilla_chardet/src/nsUTF8Prober.cpp

EXTRA_DIST = \
	mozilla_chardet/include/CharDistribution.h \
	mozilla_chardet/include/JpCntx.h \
	mozilla_chardet/include/nsBig5Prober.h \
	mozilla_chardet/include/nsCharSetProber.h \
	mozilla_chardet/include/nsCodingStateMachine.h \
	mozilla_chardet/include/nsEscCharsetProber.h \
	mozilla_chardet/include/nsEUCJPProber.h \
	mozilla_chardet/include/nsEUCKRProber.h \
	mozilla_chardet/include/nsEUCTWProber.h \
	mozilla_chardet/include/nsGB2312Prober.h \
	mozilla_chardet/include/nsHebrewProber.h \
	mozilla_chardet/include/nsLatin1Prober.h \
	mozilla_chardet/include/nsMBCSGroupProber.h \
	mozilla_chardet/include/nsPkgInt.h \
	mozilla_chardet/include/nsSBCharSetProber.h \
	mozilla_chardet/include/nsSBCSGroupProber.h \
	mozilla_chardet/include/nsSJISProber.h \
	mozilla_chardet/include/nsUniversalDetector.h \
	mozilla_chardet/include/nsUTF8Prober.h \
	mozilla_chardet/include/mfbt/mozilla/Alignment.h \
	mozilla_chardet/include/mfbt/mozilla/Assertions.h \
	mozilla_chardet/include/mfbt/mozilla/Attributes.h \
	mozilla_chardet/include/mfbt/mozilla/Compiler.h \
	mozilla_chardet/include/mfbt/mozilla/Likely.h \
	mozilla_chardet/include/mfbt/mozilla/NullPtr.h \
	mozilla_chardet/include/mfbt/mozilla/TypedEnum.h \
	mozilla_chardet/include/mfbt/mozilla/Types.h \
	mozilla_chardet/include/mfbt/mozilla/Util.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg_darwin.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg_linux.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg_openbsd.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg_win95.h \
	mozilla_chardet/include/nsprpub/pr/include/prcpucfg_winnt.h \
	mozilla_chardet/include/nsprpub/pr/include/prmem.h \
	mozilla_chardet/include/nsprpub/pr/include/prtypes.h \
	mozilla_chardet/include/xpcom/base/ErrorList.h \
	mozilla_chardet/include/xpcom/base/nscore.h \
	mozilla_chardet/include/xpcom/base/nsError.h \
	mozilla_chardet/include/xpcom/glue/nsDebug.h \
	mozilla_chardet/include/xpcom/glue/nsMemory.h \
	mozilla_chardet/src/Big5Freq.tab \
	mozilla_chardet/src/EUCKRFreq.tab \
	mozilla_chardet/src/EUCTWFreq.tab \
	mozilla_chardet/src/GB2312Freq.tab \
	mozilla_chardet/src/JISFreq.tab
