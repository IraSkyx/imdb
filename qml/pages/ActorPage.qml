import QtQuick 2.0
import Sailfish.Silica 1.0

import ActorLib 1.0
import MovieLib 1.0

Page {
    id: page

    property Actor actor : null
    property Movie movie : null

    SilicaFlickable {
        anchors.fill: parent

        PageHeader {
            id: header
            title: actor.name
        }

        Column {
            x: Theme.paddingLarge
            anchors.top: header.bottom
            width: parent.width - 4 * Theme.paddingLarge

            Column {
                spacing: 2 * Theme.paddingLarge

                Label {
                    text: "Starred in : " + movie.title
                    color: Theme.highlightColor
                }

                Button {
                    text: "See movie details"
                    onClicked: pageStack.push("MoviePage.qml", { movie: movie } )
                }
            }
        }

        PushUpMenu {
            MenuItem {
                text: qsTr("Edit")
                onClicked: pageStack.push("EditActorPage.qml", { actor: actor })
            }
        }
    }
}
