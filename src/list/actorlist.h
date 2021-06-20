#ifndef ACTORLIST_H
#define ACTORLIST_H

#include <QObject>
#include <QList>

class Actor;

class ActorList : public QObject
{
    Q_OBJECT
    QList<Actor*> m_actors;

    public:
        explicit ActorList(QObject *parent = nullptr);
        void push_back(Actor* movie);
        void remove(int index);
        Actor* operator[](int index) const;
        void insert(int index, Actor* cheese);
        Q_INVOKABLE int size() const;

        ~ActorList();
    protected:
        void registerMovie(int index);
        void unregisterMovie(int index);
        void reregisterMovie(int index);

    signals:
        void pre_insert(int index);
        void post_insert(int index);
        void itemChanged(int position);
};

#endif // ACTORLIST_H
