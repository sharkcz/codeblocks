AM_CPPFLAGS = $(WX_CXXFLAGS) \
		-I$(top_srcdir)/src/include \
		-I$(top_srcdir)/src/sdk/wxscintilla/include

pluginlibdir = $(pkglibdir)/plugins

pluginlib_LTLIBRARIES = libAutoVersioning.la

libAutoVersioning_la_LDFLAGS = @MODULE_SHARED_LDFLAGS@ -version-info 0:1:0 -no-undefined -avoid-version

libAutoVersioning_la_LIBADD = ../../../sdk/libcodeblocks.la \
			$(WX_LIBS)

libAutoVersioning_la_SOURCES = AutoVersioning.cpp \
            avChangesDlg.cpp \
            avHeader.cpp \
            avSvnRevision.cpp \
            avVersionEditorDlg.cpp


noinst_HEADERS = AutoVersioning.h \
            avChangesDlg.h \
            avConfig.h \
            avHeader.h \
            avSvnRevision.h \
            avVersionEditorDlg.h

EXTRA_DIST = wxsmith/avChangesDlg.wxs \
            wxsmith/avVersionEditorDlg.wxs \
            $(srcdir)/*.cbp \
            manifest.xml

pkgdata_DATA = AutoVersioning.zip
CLEANFILES = $(pkgdata_DATA)

AutoVersioning.zip: manifest.xml
	PWD=`pwd` cd $(srcdir) && zip $(PWD)/AutoVersioning.zip manifest.xml > /dev/null
