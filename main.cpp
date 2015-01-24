#include <QApplication>

#include<QQuickView>
#include<QQmlContext>

#include"SPplayer.h"

#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SPplayer player;

    QQuickView *view=new QQuickView();
    QQmlContext *importer=view->rootContext();

    importer->setContextProperty("player",&player);
    importer->setContextProperty("playList",&player.playList);

    view->setSource(QUrl("qrc:/qml/SPmain.qml"));
    view->show();
    return a.exec();
}
