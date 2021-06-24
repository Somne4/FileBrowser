#include "Adapter.h"

ChartAdapter::ChartAdapter() {}

ChartAdapter::~ChartAdapter()
{
    delete view;
}

ChartAdapter::ChartAdapter(QLayout *layout)
{
    model = new QChart();
    view = new QChartView();
    view->setChart(model);
    addWidget(layout);
}

void ChartAdapter::setChart(QList<SomeData>& dt) const
{
    qint64 size = 0;
    for (auto x : dt)
    {
        size += x.size.toLongLong();
    }
    model->setTitle("");

    if (dt.size() > 4)
    {
        qint64 size_ = 0;
        auto p = dt.begin() + 3;
        while (p != dt.end())
        {
            size_ += p->size.toLongLong();
            p = dt.erase(p);
        }

        double percent = double(size_ * 100) / size;
        dt.push_back(SomeData("Others", QString::number(size_), QString::number(percent, 'f', 2).append(" %"), (qreal)size_ / size));
    }

    if (size == 0 || dt.isEmpty())
    {
        model->setTitle("Folder is empty");
        model->removeAllSeries();
        return;
    }

    setData(dt);
}

void ChartAdapter::addWidget(QLayout *layout)
{
    layout->addWidget(view);
}

void ChartAdapter::Update(QList<SomeData> &dt) const
{
    setChart(dt);
}

void ChartAdapter::DeleteSeries(QChart *chart) const
{
    chart->removeAllSeries();
}

void ChartAdapter::addSeries(QAbstractSeries *series) const
{
    model->addSeries(series);
}

void ChartAdapter::setData(const QList<SomeData> &dt) const
{
    DeleteSeries(model);
    QAbstractSeries* series = addData(dt);
    addSeries(series);
}

BarChart::BarChart(QLayout *layout) : ChartAdapter(layout) {}


QAbstractSeries *BarChart::addDataToSeries(const QList<SomeData> &dt) const
{
    QBarSeries* series = new QBarSeries();
    for (auto item : dt)
    {
        QBarSet* set = new QBarSet(item.name + " (" + item.percent.toHtmlEscaped() + ")");
        set->append(item.share);
        series->append(set);
    }
    return series;
}

PieChart::PieChart(QLayout *layout) : ChartAdapter(layout) {}

QAbstractSeries *PieChart::addDataToSeries(const QList<SomeData> &dt) const
{
    QPieSeries* series = new QPieSeries();
    for (auto item : dt)
    {
        series->append(item.name + " (" + item.percent.toHtmlEscaped() + ")", item.share);
    }
    return series;
}
