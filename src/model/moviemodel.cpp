#include "moviemodel.h"

#include <QSettings>

#include "../list/movielist.h"
#include "../domain/movie.h"

MovieModel::MovieModel(QObject *parent)
    : QAbstractListModel(parent), m_list(nullptr)
{

}

void MovieModel::setList(MovieList *list)
{
    beginResetModel();

    if (m_list) {
        disconnect(m_list);
    }

    m_list = list;

    if (m_list) {
        connect(m_list, &MovieList::pre_insert, [=](int index){
            this->beginInsertRows(QModelIndex(),index, index);
        } );
        connect(m_list, &MovieList::post_insert,  [=](){
            this->endInsertRows();
        } );
        connect(m_list, &MovieList::itemChanged, [=](int index){
            auto row = this->index(index);
            emit MovieModel::dataChanged(row, row);
        });
    }
    endResetModel();
}

int MovieModel::rowCount(const QModelIndex &) const
{
    return m_list ? m_list->size() : 0;
}

QVariant MovieModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    Q_ASSERT(row < m_list->size());
    Q_ASSERT(m_list);

    auto movie = (*m_list)[row];

    switch (role) {
    case RId : return movie->id();
        break;
    case RImdbId : return movie->imdbId();
        break;
    case RTitle : return movie->title();
        break;
    case RDirector : return movie->director();
        break;
    case RYear : return movie->year();
        break;
    case RGenres : return movie->genres();
        break;
    case RFull:
        return QVariant::fromValue(movie);
    }

    return QVariant();
}

QHash<int, QByteArray> MovieModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[RId]   = "id";
    roles[RImdbId] = "imdb_id";
    roles[RTitle] = "title";
    roles[RDirector] = "director";
    roles[RYear] = "year";
    roles[RGenres] = "genres";
    roles[RFull]   = "fullMovie";

    return roles;
}

void MovieModel::addToFavorite(int id)
{
    beginResetModel();

    QSettings settings;
    settings.setValue("favorites/" + QString(id), id);
    settings.sync();

    endResetModel();
}

void MovieModel::removeFromFavorite(int id)
{
    beginResetModel();

    QSettings settings;
    settings.remove("favorites/" + QString(id));
    settings.sync();

    endResetModel();
}

bool MovieModel::isFavorite(int id)
{
    QSettings settings;
    return settings.value("favorites/"+ QString(id), -1).toInt() == id;
}
