#include "moviemodel.h"

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
    case RTitle : return movie->title();
        break;
    case RDirector : return movie->director();
        break;
    case RYear : return movie->year();
        break;
    case RRating : return movie->rating();
        break;
    case RGenres : return movie->genres();
        break;
    case RRuntime : return movie->runtime();
        break;
    case RCountry : return movie->country();
        break;
    case RLanguage : return movie->language();
        break;
    case RImdbScore : return movie->imdb_score();
        break;
    case RImdbVotes : return movie->imdb_votes();
        break;
    case RMetacriticScore : return movie->metacritic_score();
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
    roles[RTitle] = "title";
    roles[RDirector] = "director";
    roles[RYear] = "year";
    roles[RRating] = "rating";
    roles[RGenres] = "genres";
    roles[RRuntime] = "runtime";
    roles[RCountry] = "country";
    roles[RLanguage] = "language";
    roles[RImdbScore] = "imdb_score";
    roles[RImdbVotes] = "imdb_votes";
    roles[RMetacriticScore] = "metacritic_score";
    roles[RFull]   = "fullMovie";

    return roles;
}
