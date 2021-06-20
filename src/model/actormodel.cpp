#include "actormodel.h"

#include <QSettings>

#include "../list/actorlist.h"
#include "../domain/actor.h"

ActorModel::ActorModel(QObject *parent)
    : QAbstractListModel(parent), m_list(nullptr)
{

}

void ActorModel::setList(ActorList *list)
{
    beginResetModel();

    if (m_list) {
        disconnect(m_list);
    }

    m_list = list;

    if (m_list) {
        connect(m_list, &ActorList::pre_insert, [=](int index){
            this->beginInsertRows(QModelIndex(),index, index);
        } );
        connect(m_list, &ActorList::post_insert,  [=](){
            this->endInsertRows();
        } );
        connect(m_list, &ActorList::itemChanged, [=](int index){
            auto row = this->index(index);
            emit ActorModel::dataChanged(row, row);
        });
    }
    endResetModel();
}

int ActorModel::rowCount(const QModelIndex &) const
{
    return m_list ? m_list->size() : 0;
}

QVariant ActorModel::data(const QModelIndex &index, int role) const
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
    case RMovieId : return movie->movieId();
        break;
    case RName : return movie->name();
        break;
    case RFull:
        return QVariant::fromValue(movie);
    }

    return QVariant();
}

QHash<int, QByteArray> ActorModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[RId]   = "id";
    roles[RImdbId] = "imdb_id";
    roles[RMovieId] = "movie_id";
    roles[RName] = "name";
    roles[RFull]   = "fullActor";

    return roles;
}

void ActorModel::addToFavorite(int id)
{
    beginResetModel();

    QSettings settings;
    settings.setValue("favorites/" + QString(id), id);
    settings.sync();

    endResetModel();
}

void ActorModel::removeFromFavorite(int id)
{
    beginResetModel();

    QSettings settings;
    settings.remove("favorites/" + QString(id));
    settings.sync();

    endResetModel();
}

bool ActorModel::isFavorite(int id)
{
    QSettings settings;
    return settings.value("favorites/"+ QString(id), -1).toInt() == id;
}
