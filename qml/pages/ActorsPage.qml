import QtQuick 2.0
import Sailfish.Silica 1.0
import MovieLib 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaFlickable {
        anchors.fill: parent

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

        contentHeight: column.height

        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge

            SilicaListView {
                id: listView
                model: MovieModel {
                }

                Component.onCompleted: {
                    model.setList(movieList)
                    console.log(movieList)
                }

                anchors.fill: parent
                header: PageHeader {
                    title: qsTr("IMDb actors")
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
                        //pageStack.push("ActorPage.qml", { movie: fullActor } )
                    }

                }
                VerticalScrollDecorator {}
            }
        }
    }
}
