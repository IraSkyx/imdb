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

protected:
    enum Roles {
        RId = Qt::UserRole+1,
        RTitle,
        RDirector,
        RYear,
        RRating,
        RGenres,
        RRuntime,
        RCountry,
        RLanguage,
        RImdbScore,
        RImdbVotes,
        RMetacriticScore,
        RFull
    };
};

#endif // MOVIEMODEL_H
