#include <QApplication>

#include<QQuickView>
#include<QQmlContext>
#include<QQuickItem>

#include"SPplayer.h"
#include"SPurlSelector.h"

#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QQuickView *view=new QQuickView();

    QQmlContext *importer=view->rootContext();
    SPplayer player;
    SPurlSelector urlSelector;

    importer->setContextProperty("urlSelectorr",&urlSelector);
    importer->setContextProperty("dirList",urlSelector.dirList);
    importer->setContextProperty("player",&player);
    importer->setContextProperty("playList",&player.playList);

    view->setSource(QUrl("qrc:/qml/SPmain.qml"));
    QObject *obj=view->rootObject();
    QObject *bar = obj->findChild<QObject*>("progressBar");
    player.setBar(bar);
    urlSelector.setIpt(importer);
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->showFullScreen();
    return a.exec();
}
