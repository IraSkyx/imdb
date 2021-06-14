#ifndef SQLLITELOADER_H
#define SQLLITELOADER_H

#include <QVector>
#include "../domain/movie.h"

class SqlLiteLoader
{
public:
    SqlLiteLoader() = delete;
    static QVector<Movie*> loadMovies();
};

#endif // SQLLITELOADER_H
