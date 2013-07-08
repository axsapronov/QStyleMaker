#include "testmainwindow.h"
#include "ui_testmainwindow.h"

#include <QDesktopWidget> /// moved to center

TestMainWindow::TestMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);

    /// moved to center desktop
    QRect rect = QApplication::desktop()->availableGeometry(this);
    this->move(rect.width() / 2 - this->width() / 2,
               rect.height() / 2 - this->height() / 2);
    /// maximized
    //this->showMaximized();
}
//------------------------------------------------------------------------------
TestMainWindow::~TestMainWindow()
{
    delete ui;
}
//------------------------------------------------------------------------------
void TestMainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
//------------------------------------------------------------------------------
