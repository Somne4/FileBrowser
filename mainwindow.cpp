#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Folders(new FolderSize()),
    Types(new TypeSize()),
    Grouping(Folders)
{
    ui->setupUi(this);

    QString homePath = QDir::homePath();
    dirModel =  new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(homePath);

    TableAdapter = new AdapterTable(ui->stackedWidget->layout());
    bar = new BarChart(ui->stackedWidget->layout());
    pie = new PieChart(ui->stackedWidget->layout());
    View = TableAdapter;
    Grouping->Attach(View);

    ui->treeView->setModel(dirModel);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::selectionDisplay);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::ChoiceStrategy);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this,  &MainWindow::selectionChangedSlot);
}

void MainWindow::ChoiceStrategy(int index) // изменяется группировка в combobox
{
    switch (index)
    {
    case 0:
        Grouping = Folders;
        break;
    case 1:
        Grouping = Types;
        break;
    }
    Grouping->Attach(View);
    Grouping->Browse(path);
}

void MainWindow::selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexes = selected.indexes(); // получаем индекс выделенных элементов
    path = dirModel->filePath(indexes[0]); // вычисляем путь по индексу в моделе
    Grouping->Browse(path);
}

void MainWindow::selectionDisplay(int index)
{
    switch(index)
    {
        case 0:
            View = TableAdapter;
            break;
        case 1:
            View = bar;
            break;
        case 2:
            View = pie;
            break;
    }
    Grouping->Attach(View);
    Grouping->Browse(path);
    ui->stackedWidget->setCurrentIndex(index);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dirModel;
    delete TableAdapter;
    delete bar;
    delete pie;
    delete Folders;
    delete Types;
}
