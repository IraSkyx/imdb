# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = IMDb

CONFIG += sailfishapp

QT += sql

SOURCES += src/IMDb.cpp \
    src/domain/actor.cpp \
    src/domain/movie.cpp \
    src/list/movielist.cpp \
    src/model/moviemodel.cpp

DISTFILES += qml/IMDb.qml \
    data/movies.db \
    qml/cover/CoverPage.qml \
    qml/pages/ActorsPage.qml \
    qml/pages/MoviesPage.qml \
    rpm/IMDb.changes.in \
    rpm/IMDb.changes.run.in \
    rpm/IMDb.spec \
    rpm/IMDb.yaml \
    translations/*.ts \
    IMDb.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/IMDb-de.ts

HEADERS += \
    src/domain/actor.h \
    src/domain/movie.h \
    src/list/movielist.h \
    src/model/moviemodel.h

database.files = data
database.path = /usr/share/$${TARGET}

RESOURCES += \
    resources.qrc

INSTALLS += database
