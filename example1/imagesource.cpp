#include "imagesource.h"

#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkDICOMImageReader.h>


class ImageSourceData {
    ImageSource *parent;
public:
    ImageSourceData(ImageSource *parent) : parent(parent) {}
    vtkImageData *image;
};


ImageSource::ImageSource() :
    d(new ImageSourceData(this))
{

}

ImageSource::~ImageSource()
{
    delete d;
}


ImageSource *ImageSource::loadDICOM(const char *path)
{
    vtkSmartPointer<vtkDICOMImageReader> reader =
        vtkSmartPointer<vtkDICOMImageReader>::New();
     reader->SetDirectoryName(path);
     reader->Update();

}
