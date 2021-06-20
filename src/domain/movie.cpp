#include "movie.h"

Movie::Movie()
{

}

Movie::Movie(int m_id, QString m_imdb_id, QString m_title, QString m_director, int m_year, QString m_genres, QObject *parent)
: QObject(parent), m_id(m_id), m_imdb_id(m_imdb_id), m_title(m_title), m_director(m_director), m_year(m_year), m_genres(m_genres)
{

}

int Movie::id() const
{
    return this->m_id;
}

QString Movie::imdbId() const
{
    return this->m_imdb_id;
}

QString Movie::title() const
{
    return this->m_title;
}

QString Movie::director() const
{
    return this->m_director;
}

int Movie::year() const
{
    return this->m_year;
}

QString Movie::genres() const
{
    return this->m_genres;
}

void Movie::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(m_id);
}

void Movie::setImdbId(QString imdb_id)
{
    if (m_imdb_id == imdb_id)
        return;

    m_imdb_id = imdb_id;
    emit imdbIdChanged(m_imdb_id);
}

void Movie::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void Movie::setDirector(QString director)
{
    if (m_director == director)
        return;

    m_director = director;
    emit directorChanged(m_director);
}

void Movie::setYear(int year)
{
    if (m_year == year)
        return;

    m_year = year;
    emit yearChanged(m_year);
}

void Movie::setGenres(QString genres)
{
    if (m_genres == genres)
        return;

    m_genres = genres;
    emit genresChanged(m_genres);
}
