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
#include "model/moviemodel.h"

MovieList* stub_movielist() {
    MovieList* movies = new MovieList;

    movies->push_back(new Movie(
                          1,
                          "tt0050083",
                          "12 Angry Men",
                          "Sidney Lumet",
                          1957,
                          "APPROVED",
                          "Crime, Drama",
                          96,
                          "USA",
                          "English",
                          8.9,
                          551194,
                          96
                  ));

    movies->push_back(new Movie(
                          2,
                          "tt0062622",
                          "2001: A Space Odyssey",
                          "Stanley Kubrick",
                          1968,
                          "G",
                          "Adventure, Sci-Fi",
                          149,
                          "UK, USA",
                          "English, Russian",
                          8.3,
                          508060,
                          82
                  ));

    return movies;
}

/*QStringList readTables(const char *path)
{
    QStringList tables;

    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Opening " << path << " : " << file.errorString();
            return tables;
        }
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);
    if (!db.open())
    {
        qDebug() << "La bdd n'est pas ouverte" << db.lastError();
        return tables;
    }

    QSqlQuery
        query("SELECT name FROM sqlite_master WHERE type IN ('table','view') AND name NOT LIKE "
              "'sqlite_%' ORDER BY 1",
              db);

    while (query.next()) {
        tables.push_back(query.value(0).toString());
        qDebug() << tables.last();
    }
    if (query.lastError().type()
        != QSqlError::NoError) // NoError en fin de parcours => ne rien afficher
        qDebug() << "After next" << query.lastError();

    db.close();

    return tables;
}*/


int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app (SailfishApp::application(argc, argv));

    qmlRegisterType<MovieModel>("MovieLib", 1, 0, "MovieModel");
    qmlRegisterUncreatableType<MovieList>("MovieLib", 1, 0, "MovieList", "Le métier crée les données, pas la vue!");
    qmlRegisterType<Movie>("MovieLib", 1, 0, "Movie");

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->setSource(SailfishApp::pathToMainQml());

    QScopedPointer<MovieList> movies(stub_movielist());
    view->rootContext()->setContextProperty("movieList", movies.data());

    view->show();
    return app->exec();
}
