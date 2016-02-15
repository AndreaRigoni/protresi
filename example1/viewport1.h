#ifndef VIEWPORT1_H
#define VIEWPORT1_H

#include <QFrame>


#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"


namespace Ui {
class Viewport1;
}


class Viewport1 : public QFrame
{
    Q_OBJECT

public:
    explicit Viewport1(QWidget *parent = 0);
    ~Viewport1();

    vtkRenderWindow * getRenderWindow() const;
    vtkRenderWindowInteractor * getInteractor() const;
    
private:
    friend class Viewport1Data;
    class Viewport1Data *d;
    Ui::Viewport1 *ui;
};

#endif // VIEWPORT1_H
