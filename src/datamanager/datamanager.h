#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QtSql/QSqlDatabase>

#include "../list/movielist.h"
#include "../list/actorlist.h"

class DataManager
{
    const QString pathname = "/usr/share/IMDb/data/movies.db";

public:
    explicit DataManager();
    MovieList* loadMovies();
    ActorList* loadActors();
    ~DataManager();
private:
    QSqlDatabase db;
};

#endif // DATAMANAGER_H
