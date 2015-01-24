#include "SPplayer.h"

SPplayer::SPplayer(QObject *parent) :
    QObject(parent)
{
}


void SPplayer::playMusic(QString url, int vol)
{
    if(player.media()==QMediaContent(url))
    {
        player.stop();
    }
    player.setMedia(QMediaContent(url));
    player.setVolume(vol);
    player.play();
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
