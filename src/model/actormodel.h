#ifndef ACTORMODEL_H
#define ACTORMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "../list/actorlist.h"

class ActorModel : public QAbstractListModel
{
    Q_OBJECT
    ActorList * m_list;

public:
    ActorModel(QObject * parent = nullptr);
    Q_INVOKABLE void setList(ActorList * list);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    enum Roles {
        RId = Qt::UserRole+1,
        RImdbId,
        RMovieId,
        RName,
        RFull
    };

public slots:
    void addToFavorite(int);
    void removeFromFavorite(int);
    bool isFavorite(int);
};

#endif // ACTORMODEL_H
