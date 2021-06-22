#include "moviefilter.h"

#include "../model/moviemodel.h"

MovieFilter::MovieFilter(QObject* parent): QSortFilterProxyModel(parent)
{
}

QString MovieFilter::titleCriteria() const
{
    return m_title_criteria;
}

void MovieFilter::setTitleCriteria(QString title_criteria)
{
    if (m_title_criteria == title_criteria)
        return;

    m_title_criteria = title_criteria;
    invalidate();
    emit titleCriteriaChanged(m_title_criteria);
}

bool MovieFilter::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(m_title_criteria.isEmpty()) {
        return true;
    }

    auto index = sourceModel()->index(source_row, 0, source_parent);
    auto movieTitle = index.data(MovieModel::Roles::RTitle);

    return movieTitle.toString().toLower().contains(m_title_criteria.toLower());
}
