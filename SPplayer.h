#ifndef SPPLAYER_H
#define SPPLAYER_H

#include <QObject>
#include "SPmusicItem.h"
#include"QMediaPlayer"
#include"QMediaContent"
#include"QMediaPlaylist"
#include"QFile"
#include"QDir"

class SPplayer : public QObject
{
    Q_OBJECT
public:
    explicit SPplayer(QObject *parent = 0);

signals:

private:
    QString musicDir;
    void findMusic();
    SPmusicItem playList;
    QMediaPlayer player;

public slots:
    void setMusicDir(QString url);
    void playMusic(QString url,int vol);
    void changeVolume(int v);
};

#endif // SPPLAYER_H
