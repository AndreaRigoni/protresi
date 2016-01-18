#include "viewport1.h"
#include "ui_viewport1.h"

#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"



Viewport1::Viewport1(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Viewport1)
{
    ui->setupUi(this);
}

Viewport1::~Viewport1()
{
    delete ui;
}
