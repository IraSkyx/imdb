import QtQuick 2.0
import Sailfish.Silica 1.0
import MovieLib 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    Column {
        id: headerContainer
        width: page.width

        PageHeader {
            title: qsTr("IMDb movies")
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

        model: MovieFilter {
            titleCriteria: searchField.text
            sourceModel: MovieModel {
            }
        }

        Component.onCompleted: {
            model.sourceModel.setList(movieList)
        }

        anchors.fill: parent

        delegate: BackgroundItem {
            id: delegate
            width: listView.width
            height: col.height + Theme.paddingMedium

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
                        text: title
                        color: Theme.highlightColor
                    }

                    Label {
                        text: year
                        x: Theme.horizontalPageMargin
                        color: Theme.secondaryHighlightColor
                    }
                }
            }

            onClicked: {
                pageStack.push("MoviePage.qml", { movie: fullMovie } )
            }

        }

        VerticalScrollDecorator {}
    }
}
