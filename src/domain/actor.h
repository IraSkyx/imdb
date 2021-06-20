#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

class Actor: public QObject
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
    Q_PROPERTY(int movie_id
               READ movieId
               WRITE setMovieId
               NOTIFY movieIdChanged)
    Q_PROPERTY(QString name
               READ name
               WRITE setName
               NOTIFY nameChanged)
public:
    explicit Actor();

    explicit Actor(
            int m_id,
            QString m_imdb_id,
            int m_movie_id,
            QString m_name,
            QObject *parent = nullptr
    );

    int id() const;
    QString imdbId() const;
    int movieId() const;
    QString name() const;

public slots:
    void setId(int);
    void setImdbId(QString);
    void setMovieId(int);
    void setName(QString);

signals:
    void idChanged(int);
    void imdbIdChanged(QString);
    void movieIdChanged(int);
    void nameChanged(QString);

private:
    int m_id;
    QString m_imdb_id;
    int m_movie_id;
    QString m_name;
};

#endif // ACTOR_H
