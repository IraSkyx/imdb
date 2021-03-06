#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "../list/movielist.h"

class MovieModel : public QAbstractListModel
{
    Q_OBJECT
    MovieList * m_list;

public:
    MovieModel(QObject * parent = nullptr);
    Q_INVOKABLE void setList(MovieList * list);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    enum Roles {
        RId = Qt::UserRole+1,
        RImdbId,
        RTitle,
        RDirector,
        RYear,
        RGenres,
        RFull
    };

public slots:
    void addToFavorite(int);
    void removeFromFavorite(int);
    bool isFavorite(int);
};

#endif // MOVIEMODEL_H
