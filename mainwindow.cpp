#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new Context();
    strategy_ = Strategy::Folder;

    QString homePath = QDir::homePath();
    dirModel =  new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(homePath);
    fileModel = new FileBrowserDataModel();

    ui->treeView->setModel(dirModel);
    ui->tableView->setModel(fileModel);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::ChoiceStrategy);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this,  &MainWindow::selectionChangedSlot);
}

void MainWindow::ChoiceStrategy(int index) // изменяется группировка в combobox
{
    switch (index)
    {
    case 0:
        strategy_ = Strategy::Folder;
        break;
    case 1:
        strategy_ = Strategy::Type;
        break;
    }

    if (strategy_ == Strategy::Type)
        p->setStrategy(new TypeSize);
    else
        p->setStrategy(new FolderSize);

    data = p->Browse(path);
    fileModel->setModel(data);
}

void MainWindow::selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexes = selected.indexes(); // получаем индекс выделенных элементов
    path = dirModel->filePath(indexes[0]); // вычисляем путь по индексу в моделе
    if (path.isEmpty())
        return;
    if (strategy_ == Strategy::Type)
        p->setStrategy(new TypeSize);
    else
        p->setStrategy(new FolderSize);
    data = p->Browse(path);
    fileModel->setModel(data);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p;
    delete dirModel;
    delete fileModel;
}
