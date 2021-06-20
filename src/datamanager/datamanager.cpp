#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include "datamanager.h"

#include <QFile>
#include <QGuiApplication>
#include <QQuickView>
#include <QScopedPointer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include "../domain/movie.h"
#include "../domain/actor.h"

DataManager::DataManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(pathname);

    if (!db.open())
    {
        throw "Could not open database" + db.lastError().text();
    }
}

MovieList* DataManager::loadMovies()
{
    auto list = new MovieList;
    QSqlQuery query("SELECT * FROM movies", db);

    while (query.next()) {
        list->push_back(new Movie(
                                  query.value(0).toInt(),
                                  query.value(1).toString(),
                                  query.value(2).toString(),
                                  query.value(3).toString(),
                                  query.value(4).toInt(),
                                  query.value(6).toString()
                          ));
    }

    if (query.lastError().type() != QSqlError::NoError)
        qDebug() << "After next" << query.lastError();

    return list;
}

ActorList* DataManager::loadActors()
{
    auto list = new ActorList;
    QSqlQuery query("SELECT * FROM actors", db);

    while (query.next()) {
        list->push_back(new Actor(
                                  query.value(0).toInt(),
                                  query.value(1).toString(),
                                  query.value(2).toInt(),
                                  query.value(3).toString()
                          ));
    }

    if (query.lastError().type() != QSqlError::NoError)
        qDebug() << "After next" << query.lastError();

    return list;
}


DataManager::~DataManager()
{
    db.close();
}
