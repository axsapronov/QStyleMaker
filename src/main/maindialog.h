#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>


class AboutDialog;
class TestMainWindow;
class TestDialog;

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
    void slotShowTestDialog();
    void slotShowTestMainWindow();
    void slotQuit();

    void slotUpdatePreview();
    void slotShowAboutDialog();
    void slotOpenHomePage();
    void slotLoadExample();


    void slotPickColor();

    void slotSelectTab(int);

private:
    Ui::MainDialog *ui;

    AboutDialog *GUI_AboutDialog;
    TestMainWindow *GUI_TestMainWindow;
    TestDialog *GUI_TestDialog;

    void createConnects();
    void createGUI();

    QStringList m_listMainSettings;
    QStringList m_listInnerSettings;

    enum m_TABS {TAB_MAIN = 0,
              TAB_INNER};
};

#endif // MAINDIALOG_H
