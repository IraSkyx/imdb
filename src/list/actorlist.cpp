#include "actorlist.h"

#include <QDebug>

#include "../domain/actor.h"


ActorList::ActorList(QObject *parent) : QObject(parent)
{

}

void ActorList::push_back(Actor *movie)
{
    int index = m_actors.size();
    m_actors.push_back(movie);
    registerMovie(index);
}

Actor *ActorList::operator[](int index) const
{
    Q_ASSERT(index < m_actors.size());
    return m_actors[index];
}

void ActorList::insert(int index, Actor *movie)
{
    emit pre_insert(index);
    m_actors.insert(index, movie);

    for ( ; index < m_actors.size() ; ++index)
        reregisterMovie(index);

    emit post_insert(index);
}

int ActorList::size() const
{
    return m_actors.size();
}

ActorList::~ActorList()
{
    for (auto movie : m_actors) {
        delete movie;
    }
}

void ActorList::registerMovie(int index)
{
    auto movie = m_actors[index];

    connect(movie,&Actor::idChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Actor::imdbIdChanged, [=](){ emit itemChanged(index); });
    connect(movie,&Actor::movieIdChanged,   [=](){ emit itemChanged(index); });
    connect(movie,&Actor::nameChanged, [=](){ emit itemChanged(index); });
}


void ActorList::unregisterMovie(int index)
{
    auto movie = (*this)[index];
    disconnect(movie);
}

void ActorList::reregisterMovie(int index)
{
    unregisterMovie(index);
    registerMovie(index);
}
