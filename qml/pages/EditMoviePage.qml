import QtQuick 2.0
import Sailfish.Silica 1.0

import MovieLib 1.0

Page {
    id: page

    property Movie movie : null

    SilicaFlickable {
        anchors.fill: parent

        PageHeader {
            id: header
            title: "Editing " + movie.title
            description: movie.year
        }

        Column {
            x: Theme.paddingLarge
            anchors.top: header.bottom
            width: parent.width - 4 * Theme.paddingLarge

            Column {
                Column {
                    Text {
                        text: "Title :"
                        color: Theme.highlightColor
                    }

                    TextInput {
                        text: movie.title
                        onTextChanged: movie.setTitle(text)
                        color: Theme.secondaryColor
                    }
                }

                Column {
                    Text {
                        text: "Director :"
                        color: Theme.highlightColor
                    }

                    TextInput {
                        text: movie.director
                        onTextChanged: movie.setDirector(text)
                        color: Theme.secondaryColor
                    }
                }

                Column {
                    Text {
                        text: "Genres :"
                        color: Theme.highlightColor
                    }

                    TextInput {
                        text: movie.genres
                        onTextChanged: movie.setGenres(text)
                        color: Theme.secondaryColor
                    }
                }
            }
        }

        PushUpMenu {
            MenuItem {
                text: qsTr("Edit")
                onClicked: pageStack.push(Qt.resolvedUrl("EditMoviePage.qml"))
            }
        }
    }
}
