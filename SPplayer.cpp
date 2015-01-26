#include "SPplayer.h"

SPplayer::SPplayer(QObject *parent) :
    QObject(parent)
{
    connect(&player,SIGNAL(durationChanged(qint64)),this,SLOT(totalTime(qint64)));
    connect(&player,SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    totalDuration=0;
}


void SPplayer::playMusic(int index, int vol)
{
    if(player.media()==QMediaContent(playList.getUrlbyIndex(index)))
    {
        player.stop();
    }
    player.setMedia(QUrl::fromLocalFile(playList.getUrlbyIndex(index)));
    player.setVolume(vol);
    player.play();

    qDebug()<<"played";
}

void SPplayer::setMusicDir(QString url)
{
    musicDir=url;
    findMusic();
}

void SPplayer::findMusic()
{
    QDir dir(musicDir);
    QStringList t=dir.entryList(QDir::Files);
    for(int i=0;i<t.size();i++)
    {
        playList.addSPmusic(SPmusicInfo(t[i],dir.absolutePath()+"/"+t[i],i,0));
    }
    qDebug()<<t.size();
}

void SPplayer::changeVolume(int v)
{
    player.setVolume(v);
}

void SPplayer::totalTime(qint64 n)
{
    totalDuration=n;
}

void SPplayer::positionChanged(qint64 n)
{
    nowDuration=(n*1.0)/(totalDuration*1.0)*100;
    qDebug()<<n<<totalDuration<<nowDuration;
    cont->setProperty("value",QVariant(nowDuration));
}

int SPplayer::getPosition()
{
    return nowDuration;
}

void SPplayer::setBar(QObject *t)
{
    cont=t;
}
