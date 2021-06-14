import QtQuick 2.0
import Sailfish.Silica 1.0
import MovieLib 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView

        PullDownMenu {
            MenuItem {
                text: qsTr("Movies")
                onClicked: pageStack.replace(Qt.resolvedUrl("MoviesPage.qml"))
            }

            MenuItem {
                text: qsTr("Actors")
                onClicked: pageStack.replace(Qt.resolvedUrl("ActorsPage.qml"))
            }
        }

        model: MovieModel {
        }

        Component.onCompleted: {
            console.log(movieList)
            model.setList(movieList)
        }

        anchors.fill: parent
        header: PageHeader {
            title: qsTr("IMDb movies")
        }
        delegate: BackgroundItem {
            id: delegate
            width: listView.width

            Label {
                id: l_title
                x: Theme.horizontalPageMargin
                text: title
                color: Theme.highlightColor
            }

            Label {
                text: genres
                anchors.right: parent.right
            }


            height: tname.height

            onClicked: {
                //pageStack.push("MoviePage.qml", { movie: fullMovie } )
            }

        }
        VerticalScrollDecorator {}
    }
}
