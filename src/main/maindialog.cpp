#include "maindialog.h"
#include "ui_maindialog.h"

#include <QDebug>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);



    createConnects();
}
//------------------------------------------------------------------------------
MainDialog::~MainDialog()
{
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

    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(slotUpdatePreview()));
}
//------------------------------------------------------------------------------
void MainDialog::slotQuit()
{

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
    qDebug() << "update preview";
}

//------------------------------------------------------------------------------
