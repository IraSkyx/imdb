import QtQuick 2.0
import Sailfish.Silica 1.0
import ActorLib 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    Column {
        id: headerContainer
        width: page.width

        PageHeader {
            title: qsTr("IMDb actors")
        }

        SearchField {
            id: searchField
            width: parent.width
            placeholderText: qsTr("Search...")
        }
    }

    SilicaListView {
        id: listView
        width: parent.width - 4 * Theme.paddingLarge

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

        header: Item {
            id: header
            width: headerContainer.width
            height: headerContainer.height
            Component.onCompleted: headerContainer.parent = header
        }

        model: ActorFilter {
            nameCriteria: searchField.text
            sourceModel: ActorModel {
            }
        }

        Component.onCompleted: {
            model.sourceModel.setList(actorList)
        }

        anchors.fill: parent

        delegate: BackgroundItem {
            id: delegate
            width: listView.width
            height: l_title.height * 2

            Row {
                x: Theme.horizontalPageMargin

                Button {
                    icon.source: listView.model.sourceModel.isFavorite(id) ? "qrc:/images/yellow_star.png" : "qrc:/images/star.png"
                    icon.width: l_title.height
                    icon.height: l_title.height
                    onClicked: listView.model.sourceModel.isFavorite(id) ? listView.model.sourceModel.removeFromFavorite(id) :  listView.model.sourceModel.addToFavorite(id)
                }

                Column {
                    id: col

                    Label {
                        id: l_title
                        x: Theme.horizontalPageMargin
                        text: name
                        color: Theme.highlightColor
                    }
                }
            }

            onClicked: {
                pageStack.push("ActorPage.qml", {
                                   actor: fullActor,
                                   movie: movieList.find(movie_id)
                               } )
            }

        }

        VerticalScrollDecorator {}
    }
}
