#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
