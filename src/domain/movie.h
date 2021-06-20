#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id
               READ id
               WRITE setId
               NOTIFY idChanged)
    Q_PROPERTY(QString imdb_id
               READ imdbId
               WRITE setImdbId
               NOTIFY imdbIdChanged)
    Q_PROPERTY(QString title
               READ title
               WRITE setTitle
               NOTIFY titleChanged)
    Q_PROPERTY(QString director
               READ director
               WRITE setDirector
               NOTIFY directorChanged)
    Q_PROPERTY(int year
               READ year
               WRITE setYear
               NOTIFY yearChanged)
    Q_PROPERTY(QString genres
               READ genres
               WRITE setGenres
               NOTIFY genresChanged)

public:
    explicit Movie();

    explicit Movie(
            int m_id,
            QString m_imdb_id,
            QString m_title,
            QString m_director,
            int m_year,
            QString m_genres,
            QObject *parent = nullptr
    );

    int id() const;
    QString imdbId() const;
    QString title() const;
    QString director() const;
    int year() const;
    QString genres() const;

public slots:
    void setId(int);
    void setImdbId(QString);
    void setTitle(QString);
    void setDirector(QString);
    void setYear(int);
    void setGenres(QString);

signals:
    void idChanged(int);
    void imdbIdChanged(QString);
    void titleChanged(QString);
    void directorChanged(QString);
    void yearChanged(int);
    void genresChanged(QString);

private:
    int m_id;
    QString m_imdb_id;
    QString m_title;
    QString m_director;
    int m_year;
    QString m_genres;
};


#endif // MOVIE_H
