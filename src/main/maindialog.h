#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>


class AboutDialog;
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
    void slotShowAboutDialog();
    void slotOpenHomePage();

    void slotSelectTab(int);

private:
    Ui::MainDialog *ui;


    AboutDialog *GUI_AboutDialog;
    void createConnects();
};

#endif // MAINDIALOG_H
