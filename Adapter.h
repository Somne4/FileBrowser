#ifndef ADAPTER_H
#define ADAPTER_H
#include "Browser.h"
#include <QWidget>
#include <QtCharts/QChartGlobal>
#include <memory>
#include <QtCharts/QAbstractSeries>
#include <QBarSeries>
#include <QPieSeries>
#include <QBarSet>
#include <QGraphicsLayout>
#include <QChartView>
#include <QLayout>
#include <QChartView>

using namespace QtCharts;

class ChartAdapter : public FileObserver
{
private:
    QChartView* view;
    QChart* model;
public:
    ChartAdapter() = default;
    virtual ~ChartAdapter();
    ChartAdapter(QLayout* layout);

    void setChart(QList<SomeData> dt) const;
    void addWidget(QLayout* layout); // Добавление к layout'у
    void Update(QList<SomeData> dt) const; // Сигнал передает при завершении формирования данных
    void setData(QList<SomeData> dt) const; // Данные в график
    void DeleteSeries(QChart* chart) const; // Данные из графика
    void addSeries(QAbstractSeries* series) const;
    virtual QAbstractSeries* addData( QList<SomeData> dt) const = 0;
};

class PieChart : public ChartAdapter
{
public:
    explicit PieChart(QLayout* layout);
    PieChart() = default;
    QAbstractSeries * addData(QList<SomeData> dt) const;
};

class BarChart : public ChartAdapter
{
public:
    explicit BarChart(QLayout* layout);
    BarChart() = default;
    QAbstractSeries * addData(QList<SomeData> dta) const;
};

#endif // ADAPTER_H
