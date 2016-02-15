#ifndef DICOMREAD_H
#define DICOMREAD_H

#include <QWidget>

namespace Ui {
class DICOMRead;
} // Ui

class DICOMRead : public QWidget
{
    Q_OBJECT
public:
    explicit DICOMRead(QWidget *parent = 0, const char *dir_name = NULL);
    ~DICOMRead();

    void loadDICOM(const char *dir_name);
    
private:
    Ui::DICOMRead *ui;
    friend class DICOMReadData;
    class DICOMReadData *d;
};

#endif // DICOMREAD_H
