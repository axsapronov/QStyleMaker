#include "maindialog.h"
#include "ui_maindialog.h"

#include <QDesktopServices> /// tray
#include <QUrl>

#include "src/dialogs/about/about.h"
#include "src/defines/defines.h"

#include "src/debug/debughelper.h"





MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    setWindowTitle(QString("%1 - %2").arg(D_PROG_NAME).arg(D_PROG_VERSION_STR));

    createConnects();
}
//------------------------------------------------------------------------------
MainDialog::~MainDialog()
{
    //delete GUI_AboutDialog;
    delete ui;
}
//------------------------------------------------------------------------------
void MainDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
//------------------------------------------------------------------------------
void MainDialog::createConnects()
{
    connect(ui->pBSave, SIGNAL(clicked()), this, SLOT(slotSaveStyle()));
    connect(ui->pBQuit, SIGNAL(clicked()), this, SLOT(slotQuit()));
    connect(ui->pBTest, SIGNAL(clicked()), this, SLOT(slotTest()));

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(slotUpdatePreview()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(slotSelectTab(int)));

    connect(ui->pBAbout, SIGNAL(clicked()), this, SLOT(slotShowAboutDialog()));
    connect(ui->pBHomePage, SIGNAL(clicked()), this, SLOT(slotOpenHomePage()));
}
//------------------------------------------------------------------------------
void MainDialog::slotQuit()
{
    // save or not

    qApp->quit();
}
//------------------------------------------------------------------------------
void MainDialog::slotTest()
{

}
//------------------------------------------------------------------------------
void MainDialog::slotSaveStyle()
{

}
//------------------------------------------------------------------------------
void MainDialog::slotUpdatePreview()
{
    myDebug() << "update preview";
}
//------------------------------------------------------------------------------
void MainDialog::slotShowAboutDialog()
{
    GUI_AboutDialog = new AboutDialog();
    GUI_AboutDialog->show();
}
//------------------------------------------------------------------------------
void MainDialog::slotOpenHomePage()
{
    QDesktopServices::openUrl(QUrl(D_WEB_SITE));
}
//------------------------------------------------------------------------------
void MainDialog::slotSelectTab(int f_numberTab)
{
    myDebug() << f_numberTab;
}
//------------------------------------------------------------------------------
