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

MainWindow::~MainWindow()
{
    delete ui;
}

