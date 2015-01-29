#include "SPurlSelector.h"

#include"QDebug"

SPurlSelector::SPurlSelector(QObject *parent) :
    QObject(parent)
{

}

void SPurlSelector::getIntoDir(QString dir)
{
    dirList.clear();
    QDir seeker(dir);
    dirList=seeker.entryList(QDir::Dirs|QDir::NoDot);
    ct->setContextProperty("dirList",dirList);
}

void SPurlSelector::appendDir(QString ad)
{
    nowDir=nowDir+"/"+ad;
    getIntoDir(nowDir);
}

QVariant SPurlSelector::getNowDir()
{
    return QVariant(nowDir);
}

void SPurlSelector::setIpt(QQmlContext *cont)
{
    ct=cont;
    nowDir="/sdcard";
    getIntoDir(nowDir);
}
