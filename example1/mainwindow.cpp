#include <QList>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "viewport1.h"


class MainWindowData {
    MainWindow *parent;
public:
    MainWindowData(MainWindow *prent) : parent(parent)
    {}

    QList<Viewport1 *> active_viewports;
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
