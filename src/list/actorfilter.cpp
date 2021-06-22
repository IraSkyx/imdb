#include "actorfilter.h"

#include "../model/actormodel.h"

ActorFilter::ActorFilter(QObject* parent): QSortFilterProxyModel(parent)
{
}

QString ActorFilter::nameCriteria() const
{
    return m_name_criteria;
}

void ActorFilter::setNameCriteria(QString name_criteria)
{
    if (m_name_criteria == name_criteria)
        return;

    m_name_criteria = name_criteria;
    invalidate();
    emit nameCriteriaChanged(m_name_criteria);
}

bool ActorFilter::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(m_name_criteria.isEmpty()) {
        return true;
    }

    auto index = sourceModel()->index(source_row, 0, source_parent);
    auto actorName = index.data(ActorModel::Roles::RName);

    return actorName.toString().toLower().contains(m_name_criteria.toLower());
}
