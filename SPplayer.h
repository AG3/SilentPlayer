#ifndef SPPLAYER_H
#define SPPLAYER_H

#include <QObject>
#include "SPmusicItem.h"
#include"QMediaPlayer"
#include"QMediaContent"
#include"QMediaPlaylist"
#include"QQmlContext"
#include"QFile"
#include"QDir"

class SPplayer : public QObject
{
    Q_OBJECT
public:
    explicit SPplayer(QObject *parent = 0);
    SPmusicItem playList;
    qint64 totalDuration;
    QObject *cont;
    void setBar(QObject *t);

private:
    QString musicDir;
    void findMusic();
    int curInd;
    QMediaPlayer player;
    bool flag;
    double nowDuration;

signals:
    void changeTime();

public slots:
    void nextMusic();
    void autoNext(QMediaPlayer::MediaStatus s);
    void perMusic();
    int getPosition();
    void positionChanged(qint64);
    void totalTime(qint64);
    void setMusicDir(QString url);
    void playMusic(int index,int vol);
    void changeVolume(int v);
};


#endif // SPPLAYER_H
