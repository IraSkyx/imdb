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
            title: movie.title
            description: movie.year
        }

        Column {
            x: Theme.paddingLarge
            anchors.top: header.bottom
            width: parent.width - 4 * Theme.paddingLarge

            Column {
                Label {
                    text: "Director: " + movie.director
                    color: Theme.highlightColor
                }

                Label {
                    text: "Genres: " + movie.genres
                    color: Theme.lightPrimaryColor
                }
            }
        }

        PushUpMenu {
            MenuItem {
                text: qsTr("Edit")
                onClicked: pageStack.push("EditMoviePage.qml", { movie: movie })
            }
        }
    }
}
