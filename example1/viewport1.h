#ifndef VIEWPORT1_H
#define VIEWPORT1_H

#include <QFrame>

namespace Ui {
class Viewport1;
}


class Viewport1 : public QFrame
{
    Q_OBJECT

public:
    explicit Viewport1(QWidget *parent = 0);
    ~Viewport1();


private:
    Ui::Viewport1 *ui;
};

#endif // VIEWPORT1_H
