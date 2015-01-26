#include <QApplication>

#include<QQuickView>
#include<QQmlContext>
#include<QQuickItem>

#include"SPplayer.h"

#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QQuickView *view=new QQuickView();
    QQmlContext *importer=view->rootContext();
    SPplayer player;
    importer->setContextProperty("player",&player);
    importer->setContextProperty("playList",&player.playList);
    view->setSource(QUrl("qrc:/qml/SPmain.qml"));

    QObject *obj=view->rootObject();
    QObject *bar = obj->findChild<QObject*>("progressBar");
    player.setBar(bar);

    view->showFullScreen();
    bar->setProperty("value",QVariant(59));


    //QQuickItem *t=importer->findChild<QQuickItem *>("progressBar");
    //qDebug()<<t->isEnabled();
    //t->setProperty("value",QVariant(50));
    return a.exec();
}
