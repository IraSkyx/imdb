## IMDb

### Description

IMDb allows you to consult a fraction of the cult IMDb films on the platform as well as the greatest actors of these films in the form of Master-Detail.

### Programming techniques used

This program is written in plain C++ and QML using QT Quick and built as a Sailfish mobile app.

### DB access (SQLite)

The data comes from a SQLite dump file which contains two tables *movies* and *actors*.

#### QObject with QProperties

Each Movie and Actor entity is a QObject with several QProperties. Changing one of the properties causes it to be refreshed in the lists.

#### ListView partially editable + C++ Model + Sort + Search

The Movies and Actors lists are based on a C++ template that contains a list of QObjects. 

They are editable in the Detail by using the Push Up Menu and clicking on Edit.

The lists are sorted by default by title for movies and by name for actors. The search is also based on these criteria.

#### PullDownMenu

A PullDownMenu is present in the Movies and Actors Master, it shows the available navigation pages.

#### Click

A click on a Movie/Actor opens the detail page.

#### PushUpMenu

A PushUpMenu is present in the Movies and Actors Detail, it allows to show the options available in the Detail. It contains a button that redirects to the Edit page

### Detail: Edit

The Movie/Actor is editable. Editing a field notifies the model of its changes.

#### Favorites (QSettings)

A button to add/remove favourites is present on each element of the Master. We use QSettings to save favourites from one run to the next.


Translated with www.DeepL.com/Translator (free version)
