#include "maindialog.h"
#include "ui_maindialog.h"

#include <QDesktopServices> /// open site
#include <QUrl>
#include <QColorDialog>
#include <QFile>


#include "src/defines/defines.h"
#include "src/common/stringcommon.h"

#include "src/debug/debughelper.h"

#include "src/test/testdialog.h"
#include "src/test/testmainwindow.h"

#include "src/qsseditor/highlighter.h"

//------------------------------------------------------------------------------
void MainDialog::createConnects()
{
    connect(ui->pBSave, SIGNAL(clicked()), this, SLOT(slotSaveStyle()));
    connect(ui->pBQuit, SIGNAL(clicked()), this, SLOT(slotQuit()));
    connect(ui->pBLoad, SIGNAL(clicked()), this, SLOT(slotLoadExample()));

    connect(ui->pBTestDialog, SIGNAL(clicked()), this, SLOT(slotShowTestDialog()));
    connect(ui->pBTestMainWindow, SIGNAL(clicked()), this, SLOT(slotShowTestMainWindow()));

    // tabs
    connect(ui->pBBasicColorPicker, SIGNAL(clicked()), this, SLOT(slotPickColor()));
    connect(ui->pBBasicSave, SIGNAL(clicked()), this, SLOT(slotBasicSave()));
    connect(ui->pBBasicDefault, SIGNAL(clicked()), this, SLOT(slotBasicDefault()));

    connect(ui->pBAdvancedSave, SIGNAL(clicked()), this, SLOT(slotAdvancedSave()));
    connect(ui->pBAdvancedDefault, SIGNAL(clicked()), this, SLOT(slotAdvancedDefault()));

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(slotUpdatePreview()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(slotSelectTab(int)));


    connect(ui->pBAbout, SIGNAL(clicked()), this, SLOT(slotShowAboutDialog()));
    connect(ui->pBHomePage, SIGNAL(clicked()), this, SLOT(slotOpenHomePage()));

    connect(ui->tabs, SIGNAL(currentChanged(int)), this, SLOT(slotResizePreview(int)));


}
//------------------------------------------------------------------------------
void MainDialog::createGUI()
{
    setWindowTitle(QString("%1 - %2").arg(D_PROG_NAME).arg(D_PROG_VERSION_STR));

    QFile t_mainSettings(":/settings/txt/main_elements.txt");
    t_mainSettings.open(QIODevice::ReadOnly);
    m_listMainSettings = QTextStream(&t_mainSettings).readAll().split("\n");
    m_listMainSettings = removeEmptyQStringFromQStringList(&m_listMainSettings);
    t_mainSettings.close();

    QFile t_innerSettings(":/settings/txt/inner_elements.txt");
    t_innerSettings.open(QIODevice::ReadOnly);
    m_listInnerSettings = QTextStream(&t_innerSettings).readAll().split("\n");
    m_listInnerSettings = removeEmptyQStringFromQStringList(&m_listInnerSettings);
    t_innerSettings.close();

    GUI_TestDialog = new TestDialog();
    GUI_TestMainWindow = new TestMainWindow();

    //QSSHighlighter *highlighter = new QSSHighlighter(ui->TECode->document());
    Highlighter *highlighter = new Highlighter(ui->TECode->document());

    /*
    QPalette palette;
    palette.setBrush(ui->widgetIcon->backgroundRole(), QBrush(QImage(":/icons/images/icon.png")));
    ui->widgetIcon->setPalette(palette);
    */

    ui->widgetView->setMinimumHeight(200);
}
//------------------------------------------------------------------------------
