#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <QObject>
#include <QList>

class Movie;

class MovieList : public QObject
{
    Q_OBJECT
    QList<Movie*> m_movies;

public:
    explicit MovieList(QObject * = nullptr);
    void push_back(Movie*);
    void remove(int);
    Movie* operator[](int) const;
    void insert(int, Movie*);
    Q_INVOKABLE int size() const;

    ~MovieList();
protected:
    void registerMovie(int);
    void unregisterMovie(int);
    void reregisterMovie(int);

public slots:
    Q_INVOKABLE Movie* find(int);

signals:
    void pre_insert(int);
    void post_insert(int);
    void itemChanged(int);
};

#endif // MOVIELIST_H
