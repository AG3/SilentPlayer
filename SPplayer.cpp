#include "SPplayer.h"

SPplayer::SPplayer(QObject *parent) :
    QObject(parent)
{
    connect(&player,SIGNAL(durationChanged(qint64)),this,SLOT(totalTime(qint64)));
    connect(&player,SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    connect(&player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(autoNext(QMediaPlayer::MediaStatus)));
    totalDuration=0;
}


void SPplayer::playMusic(int index, int vol=-1)
{
    if(playList.size()>0)
    {
    if(vol==-1)
    {
        vol=player.volume();
    }
    if(index==-1)
    {
        index=curInd;
    }
    if(curInd==index && player.state()==QMediaPlayer::PlayingState)
    {
        player.pause();
        qDebug()<<"pause";
    }
    else if(curInd==index  && player.state()==QMediaPlayer::PausedState)
    {
        player.play();
        qDebug()<<"continue";
    }
    else
    {
        player.setMedia(QUrl::fromLocalFile(playList.getUrlbyIndex(index)));
        player.setVolume(vol);
        player.play();
        curInd=index;
        qDebug()<<"played";
    }
    }
}

void SPplayer::setMusicDir(QString url)
{
    musicDir=url;
    findMusic();
}

void SPplayer::findMusic()
{
    playList.clear();
    QDir dir(musicDir);
    QStringList t=dir.entryList(QDir::Files);
    for(int i=0;i<t.size();i++)
    {
        playList.addSPmusic(SPmusicInfo(t[i],dir.absolutePath()+"/"+t[i],i,0));
    }
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

void SPplayer::nextMusic()
{
    player.stop();
    if(curInd+1<playList.size())
    {
        curInd++;
    }
    else
    {
        curInd=0;
    }
    playMusic(curInd);
}

void SPplayer::perMusic()
{
    player.stop();
    if(curInd-1>=0)
    {
        curInd--;
    }
    else
    {
        curInd=playList.size()-1;
    }
    playMusic(curInd);
}

void SPplayer::autoNext(QMediaPlayer::MediaStatus s)
{
    if(s==QMediaPlayer::EndOfMedia)
    {
        nextMusic();
    }
}
