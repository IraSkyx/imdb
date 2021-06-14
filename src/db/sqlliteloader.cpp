#include "sqlliteloader.h"

QVector<Movie *> SqlLiteLoader::loadMovies()
{
    db = Sql.LocalStorage.openDatabaseSync('data/movies.db', "1.0", "description", 1000000, "QSQLITE")
}
