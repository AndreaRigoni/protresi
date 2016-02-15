#include "viewport1.h"
#include "ui_viewport1.h"

#include "vtkSmartPointer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"

#include "vtkVolume.h"
#include "vtkSmartVolumeMapper.h"


class Viewport1Data {
public:
    Viewport1Data()  {}
    
    vtkRenderer          *renderer;
};



Viewport1::Viewport1(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Viewport1),
    d(new Viewport1Data)
{
    ui->setupUi(this);
    d->renderer = ui->qvtk_viewport->GetRenderWindow();
}

Viewport1::~Viewport1()
{
    delete ui;
    delete d;
}

vtkRenderWindow *Viewport1::getRenderWindow() const
{
    return ui->qvtk_viewport->GetRenderWindow();
}

vtkRenderWindowInteractor *Viewport1::getInteractor() const
{
    return ui->qvtk_viewport->GetInteractor();
}
