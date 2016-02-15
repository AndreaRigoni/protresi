#include <vtk/vtkSmartPointer.h>
#include <vtk/vtkDICOMImageReader.h>
#include <vtk/vtkImageViewer2.h>

#include <vtk/vtkErrorCode.h>

#include "DICOMRead.h"
#include "ui_DICOMRead.h"



class DICOMReadData {
public:
    DICOMReadData() :
        reader(0),
        vtk_status(0)
    {}
    
    vtkSmartPointer<vtkDICOMImageReader> reader;
    int vtk_status;
};



DICOMRead::DICOMRead(QWidget *parent, const char *dir_name) :
    QWidget(parent),
    ui(new Ui::DICOMRead),
    d(new DICOMReadData)
{
    ui->setupUi(this);
    if(dir_name) 
        loadDICOM(dir_name);
}

DICOMRead::~DICOMRead()
{
    delete ui;
    delete d;
}

void DICOMRead::loadDICOM(const char *dir_name)
{
    // Read all the DICOM files in the specified directory.
    d->reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    if(dir_name) {
        d->reader->SetDirectoryName(dir_name);
        d->reader->Update();        
        ui->dirEntry->setText(d->reader->GetDirectoryName());
        d->vtk_status = (int)d->reader->GetErrorCode();
        if(d->reader) {            
            ui->dirEntry->setStyleSheet("color: red");
        }
        
    }

    // Visualize
//       vtkSmartPointer<vtkImageViewer2> imageViewer =
//          vtkSmartPointer<vtkImageViewer2>::New();
//       imageViewer->SetInputConnection(d->reader->GetOutputPort());
    
}





