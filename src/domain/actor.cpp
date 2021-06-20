#include "actor.h"

Actor::Actor()
{

}

Actor::Actor(int m_id, QString m_imdb_id, int m_movie_id, QString m_name, QObject *parent)
: QObject(parent), m_id(m_id), m_imdb_id(m_imdb_id), m_movie_id(m_movie_id), m_name(m_name)
{

}

int Actor::id() const
{
    return this->m_id;
}

QString Actor::imdbId() const
{
    return this->m_imdb_id;
}

int Actor::movieId() const
{
    return this->m_movie_id;
}

QString Actor::name() const
{
    return this->m_name;
}

void Actor::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(m_id);
}

void Actor::setImdbId(QString imdb_id)
{
    if (m_imdb_id == imdb_id)
        return;

    m_imdb_id = imdb_id;
    emit imdbIdChanged(m_imdb_id);
}

void Actor::setMovieId(int movie_id)
{
    if (m_movie_id == movie_id)
        return;

    m_movie_id = movie_id;
    emit movieIdChanged(m_movie_id);
}

void Actor::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
