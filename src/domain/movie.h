#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id
               READ id
               CONSTANT)
    Q_PROPERTY(QString imdb_id
               READ imdb_id
               CONSTANT)
    Q_PROPERTY(QString title
               READ title
               CONSTANT)
    Q_PROPERTY(QString director
               READ director
               CONSTANT)
    Q_PROPERTY(int year
               READ year
               CONSTANT)
    Q_PROPERTY(QString rating
               READ rating
               CONSTANT)
    Q_PROPERTY(QString genres
               READ genres
               CONSTANT)
    Q_PROPERTY(int runtime
               READ runtime
               CONSTANT)
    Q_PROPERTY(QString country
               READ country
               CONSTANT)
    Q_PROPERTY(QString language
               READ language
               CONSTANT)
    Q_PROPERTY(double imdb_score
               READ imdb_score
               CONSTANT)
    Q_PROPERTY(int imdb_votes
               READ imdb_votes
               CONSTANT)
    Q_PROPERTY(int metacritic_score
               READ metacritic_score
               CONSTANT)

public:
    explicit Movie(
            int m_id,
            QString m_imdb_id,
            QString m_title,
            QString m_director,
            int m_year,
            QString m_rating,
            QString m_genres,
            int m_runtime,
            QString m_country,
            QString m_language,
            double m_imdb_score,
            int m_imdb_votes,
            int m_metacritic_score
    );

    explicit Movie(QObject *parent = Q_NULLPTR);

    int id() const;
    QString imdb_id() const;
    QString title() const;
    QString director() const;
    int year() const;
    QString rating() const;
    QString genres() const;
    int runtime() const;
    QString country() const;
    QString language() const;
    double imdb_score() const;
    int imdb_votes() const;
    int metacritic_score() const;

private:
    int m_id;
    QString m_imdb_id;
    QString m_title;
    QString m_director;
    int m_year;
    QString m_rating;
    QString m_genres;
    int m_runtime;
    QString m_country;
    QString m_language;
    double m_imdb_score;
    int m_imdb_votes;
    int m_metacritic_score;
};

#endif // MOVIE_H
