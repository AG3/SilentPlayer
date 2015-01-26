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
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->showFullScreen();
    return a.exec();
}
