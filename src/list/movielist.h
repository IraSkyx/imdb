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
        explicit MovieList(QObject *parent = nullptr);
        void push_back(Movie* movie);
        void remove(int index);
        Movie* operator[](int index) const;
        void insert(int index, Movie* cheese);
        Q_INVOKABLE int size() const;

        ~MovieList();
    protected:
        void registerMovie(int index);
        void unregisterMovie(int index);
        void reregisterMovie(int index);

    signals:
        void pre_insert(int index);
        void post_insert(int index);
        void itemChanged(int position);

};

#endif // MOVIELIST_H
