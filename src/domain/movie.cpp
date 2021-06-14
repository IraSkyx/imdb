#include "movie.h"

Movie::Movie(QObject *parent): QObject(parent)
{

}

Movie::Movie(int m_id, QString m_imdb_id, QString m_title, QString m_director, int m_year, QString m_rating, QString m_genres, int m_runtime, QString m_country, QString m_language, double m_imdb_score, int m_imdb_votes, int m_metacritic_score)
: m_id(m_id), m_imdb_id(m_imdb_id), m_title(m_title), m_director(m_director), m_year(m_year), m_rating(m_rating), m_genres(m_genres), m_runtime(m_runtime), m_country(m_country), m_language(m_language), m_imdb_score(m_imdb_score), m_imdb_votes(m_imdb_votes), m_metacritic_score(m_metacritic_score)
{

}

int Movie::id() const
{
    return this->m_id;
}

QString Movie::imdb_id() const
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

QString Movie::rating() const
{
    return this->m_rating;
}

QString Movie::genres() const
{
    return this->m_genres;
}

int Movie::runtime() const
{
    return this->m_runtime;
}

QString Movie::country() const
{
    return this->m_country;
}

QString Movie::language() const
{
    return this->m_language;
}

double Movie::imdb_score() const
{
    return this->m_imdb_score;
}

int Movie::imdb_votes() const
{
    return this->m_imdb_votes;
}

int Movie::metacritic_score() const
{
    return this->m_metacritic_score;
}
