#include "movielist.h"

#include <QDebug>
#include <algorithm>

#include "../domain/movie.h"

MovieList::MovieList(QObject *parent) : QObject(parent)
{

}

void MovieList::push_back(Movie *movie)
{
    int index = m_movies.size();
    m_movies.push_back(movie);
    registerMovie(index);
}

Movie *MovieList::operator[](int index) const
{
    Q_ASSERT(index < m_movies.size());
    return m_movies[index];
}

void MovieList::insert(int index, Movie *movie)
{
    emit pre_insert(index);
    m_movies.insert(index, movie);

    for ( ; index < m_movies.size() ; ++index)
        reregisterMovie(index);

    emit post_insert(index);
}

int MovieList::size() const
{
    return m_movies.size();
}

MovieList::~MovieList()
{
    for (auto movie : m_movies) {
        delete movie;
    }
}

void MovieList::registerMovie(int index)
{
    auto movie = m_movies[index];

    connect(movie,&Movie::idChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Movie::imdbIdChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Movie::titleChanged,   [=](){ emit itemChanged(index); });
    connect(movie,&Movie::directorChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Movie::yearChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Movie::genresChanged, [=](){ emit itemChanged(index); });
}

void MovieList::unregisterMovie(int index)
{
    auto movie = (*this)[index];
    disconnect(movie);
}

void MovieList::reregisterMovie(int index)
{
    unregisterMovie(index);
    registerMovie(index);
}

Movie *MovieList::find(int id)
{
    auto itr = std::find_if(std::begin(m_movies), std::end(m_movies), [id](const Movie* m) {
        return m->id() == id;
    });

    return itr != std::end(m_movies) ? *itr : nullptr;
}
