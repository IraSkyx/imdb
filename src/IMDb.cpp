#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QFile>
#include <QGuiApplication>
#include <QQuickView>
#include <QScopedPointer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include "domain/movie.h"
#include "list/movielist.h"
#include "list/moviefilter.h"
#include "model/moviemodel.h"

#include "domain/actor.h"
#include "list/actorlist.h"
#include "list/actorfilter.h"
#include "model/actormodel.h"

#include "datamanager/datamanager.h"

MovieList* stub_movielist() {
    MovieList* movies = new MovieList;

    movies->push_back(new Movie(
                          1,
                          "tt0050083",
                          "12 Angry Men",
                          "Sidney Lumet",
                          1957,
                          "Crime, Drama"
                  ));

    movies->push_back(new Movie(
                          2,
                          "tt0062622",
                          "2001: A Space Odyssey",
                          "Stanley Kubrick",
                          1968,
                          "Adventure, Sci-Fi"
                  ));

    return movies;
}

ActorList* stub_actorlist() {
    ActorList* actors = new ActorList;

    actors->push_back(new Actor(
                          1,
                          "nm0000020",
                          1,
                          "Henry Fonda"
                  ));

    actors->push_back(new Actor(
                          2,
                          "nm0000842",
                          1,
                          "Martin Balsam"
                  ));

    return actors;
}

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app (SailfishApp::application(argc, argv));

    qmlRegisterType<MovieModel>("MovieLib", 1, 0, "MovieModel");
    qmlRegisterUncreatableType<MovieList>("MovieLib", 1, 0, "MovieList", "Le métier crée les données, pas la vue!");
    qmlRegisterType<Movie>("MovieLib", 1, 0, "Movie");
    qmlRegisterType<MovieFilter>("MovieLib", 1, 0, "MovieFilter");

    qmlRegisterType<ActorModel>("ActorLib", 1, 0, "ActorModel");
    qmlRegisterUncreatableType<ActorList>("ActorLib", 1, 0, "ActorList", "Le métier crée les données, pas la vue!");
    qmlRegisterType<Actor>("ActorLib", 1, 0, "Actor");
    qmlRegisterType<ActorFilter>("ActorLib", 1, 0, "ActorFilter");

    QScopedPointer<QQuickView> view(SailfishApp::createView());

    auto dataManager = new DataManager;

    //QScopedPointer<MovieList> movies(stub_movielist());
    QScopedPointer<MovieList> movies(dataManager->loadMovies());
    view->rootContext()->setContextProperty("movieList", movies.data());

    //QScopedPointer<MovieList> movies(stub_actorlist());
    QScopedPointer<ActorList> actors(dataManager->loadActors());
    view->rootContext()->setContextProperty("actorList", actors.data());

    view->setSource(SailfishApp::pathToMainQml());

    view->show();
    return app->exec();
}
