
#include "src/common/stringcommon.h"

#include "src/debug/debughelper.h"

#include <QFile>

//-------------------------------------------------------------------------------
QStringList removeEmptyQStringFromQStringList(QStringList *list)
{
    QStringList listn;
    for(int i = 0; i < list->size(); i++)
    {
        if(!list->at(i).isEmpty()
                && list->at(i) != ""
                && list->at(i) != " ")
        {
            listn << list->at(i);
        }
    }
    //    myDebug() << listn;
    return listn;
}
//-------------------------------------------------------------------------------
QStringList getListFromFile(QString f_path)
{
    QFile t_innerSettings(f_path);
    t_innerSettings.open(QIODevice::ReadOnly);
    QStringList r_list;
    r_list << "all"
           << QTextStream(&t_innerSettings).readAll().split("\n");
    r_list = removeEmptyQStringFromQStringList(&r_list);
    t_innerSettings.close();

    return r_list;
}
