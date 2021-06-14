#include "movielist.h"

#include <QDebug>

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
