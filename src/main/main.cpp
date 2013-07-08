#include "maindialog.h"
#include <QApplication>

#include <QTextCodec>
#include <QTranslator>
#include <QLocale>

#include "src/defines/defines.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName(D_PROG_NAME);

    QTextCodec * codec = QTextCodec::codecForName("UTF-8"); // set encoding for prog
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);

    MainDialog w;
    w.show();

    return a.exec();
}
