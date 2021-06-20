#ifndef MOVIEFILTER_H
#define MOVIEFILTER_H

#include <QSortFilterProxyModel>

class MovieFilter : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString titleCriteria
               READ titleCriteria
               WRITE setTitleCriteria
               NOTIFY titleCriteriaChanged)
public:
    explicit MovieFilter(QObject* parent = nullptr);

    QString titleCriteria() const;

public slots:
    void setTitleCriteria(QString);

signals:
    void titleCriteriaChanged(QString);

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const;
private:
    QString m_title_criteria;
};

#endif // MOVIEFILTER_H
