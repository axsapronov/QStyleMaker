#include "maindialog.h"
#include "ui_maindialog.h"


#include <QDesktopServices> /// open site
#include <QUrl>
#include <QColorDialog>
#include <QFile>

#include "src/dialogs/about/about.h"
#include "src/defines/defines.h"

#include "src/debug/debughelper.h"


//------------------------------------------------------------------------------
void MainDialog::slotQuit()
{
    // save or not
    myDebug() << "Quit";
    qApp->quit();
}
//------------------------------------------------------------------------------
void MainDialog::slotTest()
{
    myDebug() << "Test";
}
//------------------------------------------------------------------------------
void MainDialog::slotSaveStyle()
{
    myDebug() << "Save style";
}
//------------------------------------------------------------------------------
void MainDialog::slotLoadExample()
{
    myDebug() << "Load style";
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
    ui->comBElements->clear();
    switch ( f_numberTab )
    {
    case TAB_MAIN:
        ui->comBElements->addItems(m_listMainSettings);
        break;
    case TAB_INNER:
        ui->comBElements->addItems(m_listInnerSettings);
        break;
    default:
        myDebug() << "[ERROR]";
    }
}
//------------------------------------------------------------------------------
void MainDialog::slotPickColor()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this);
    if (color.isValid()) {
        ui->LAColor->setText(color.name());
        ui->LAColor->setPalette(QPalette(color));
        ui->LAColor->setAutoFillBackground(true);
    }
}
//------------------------------------------------------------------------------

