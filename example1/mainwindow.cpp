#include <QList>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "viewport1.h"
#include "DICOMRead.h"


class MainWindowData {
    MainWindow *parent;
public:
    MainWindowData(MainWindow *prent) : parent(parent)
    {}

    QList<Viewport1 *> active_viewports;
    QList<QWidget *>   active_docks;
};




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    d(new MainWindowData(this))
{

    ui->setupUi(this);

    Viewport1* vp = new Viewport1(ui->centralWidget);
    ui->label->hide();
    ui->centralWidget->layout()->addWidget(vp);
    vp->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete d;
}

QToolBar *MainWindow::getToolBar() const
{
    return ui->mainToolBar;
}

QStatusBar *MainWindow::getStatusBar() const
{
    return ui->statusBar;
}




// SLOTS //

void MainWindow::loadDICOM()
{
    std::string dir_name = QFileDialog::getExistingDirectory(this,tr("Open DICOM dir"),".").toUtf8().constData();
    std::cout << "loading form: " << dir_name << std::endl;
    
    DICOMRead *reader = new DICOMRead(0,dir_name.c_str());
    reader->setParent(this->getToolBar());
    this->getToolBar()->addWidget(reader);
    d->active_docks.append(reader);
    reader->show();
}

