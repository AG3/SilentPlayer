#ifndef SPURLSELECTOR_H
#define SPURLSELECTOR_H

#include <QObject>
#include <QDir>
#include"QQmlContext"

class SPurlSelector : public QObject
{
    Q_OBJECT
public:
    explicit SPurlSelector(QObject *parent = 0);
    QStringList dirList;
    void setIpt(QQmlContext *cont);
    QString nowDir;
    QQmlContext *ct;

private:


public slots:
    void getIntoDir(QString dir);
    void appendDir(QString ad);
    QVariant getNowDir();

};

#endif // SPURLSELECTOR_H
