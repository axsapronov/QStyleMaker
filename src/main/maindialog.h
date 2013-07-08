#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

protected:
    void changeEvent(QEvent *e);

private slots:
    void slotSaveStyle();
    void slotTest();
    void slotQuit();

    void slotUpdatePreview();

private:
    Ui::MainDialog *ui;

    void createConnects();
};

#endif // MAINDIALOG_H
