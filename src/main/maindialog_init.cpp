#include "maindialog.h"
#include "ui_maindialog.h"

#include <QDesktopServices> /// open site
#include <QUrl>
#include <QColorDialog>
#include <QFile>


#include "src/defines/defines.h"
#include "src/common/stringcommon.h"

#include "src/debug/debughelper.h"

//------------------------------------------------------------------------------
void MainDialog::createConnects()
{
    connect(ui->pBSave, SIGNAL(clicked()), this, SLOT(slotSaveStyle()));
    connect(ui->pBQuit, SIGNAL(clicked()), this, SLOT(slotQuit()));
    connect(ui->pBTest, SIGNAL(clicked()), this, SLOT(slotTest()));
    connect(ui->pBLoad, SIGNAL(clicked()), this, SLOT(slotLoadExample()));

    // tabs
    connect(ui->pBBasicColorPicker, SIGNAL(clicked()), this, SLOT(slotPickColor()));

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(slotUpdatePreview()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(slotSelectTab(int)));

    connect(ui->pBAbout, SIGNAL(clicked()), this, SLOT(slotShowAboutDialog()));
    connect(ui->pBHomePage, SIGNAL(clicked()), this, SLOT(slotOpenHomePage()));
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
}
//------------------------------------------------------------------------------
