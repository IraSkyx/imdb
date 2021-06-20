#ifndef ACTORFILTER_H
#define ACTORFILTER_H

#include <QSortFilterProxyModel>

class ActorFilter : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString nameCriteria
               READ nameCriteria
               WRITE setNameCriteria
               NOTIFY nameCriteriaChanged)
public:
    explicit ActorFilter(QObject* parent = nullptr);

    QString nameCriteria() const;

public slots:
    void setNameCriteria(QString);

signals:
    void nameCriteriaChanged(QString);

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const;
private:
    QString m_name_criteria;
};

#endif // ACTORFILTER_H
