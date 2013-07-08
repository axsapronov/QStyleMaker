#ifndef __STRINGCOMMON__H
#define __STRINGCOMMON__H

#include <QString>
#include <QStringList>

/**
 * @brief removeEmptyQStringFromQStringList
 * @param list
 * @return
 */
QStringList removeEmptyQStringFromQStringList(QStringList *list);

QStringList getListFromFile(QString f_path);

#endif // __STRINGCOMMON__H
