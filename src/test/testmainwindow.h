#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TestMainWindow;
}

class TestMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TestMainWindow(QWidget *parent = 0);
    ~TestMainWindow();
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::TestMainWindow *ui;
};

#endif // TESTMAINWINDOW_H
