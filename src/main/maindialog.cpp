#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    createGUI();
    createConnects();
}
//------------------------------------------------------------------------------
MainDialog::~MainDialog()
{
    //delete GUI_AboutDialog;
    delete GUI_TestMainWindow;
    delete m_highlighter;
    delete GUI_TestDialog;
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
