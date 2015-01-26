#include "SPmusicItem.h"

SPmusicInfo::SPmusicInfo(QString name, QString url, int rank, int duration)
{
    musicName=name;
    fileUrl=url;
    playIndex=rank;
    musicDuration=duration;
}

int SPmusicInfo::getDuration() const
{
    return musicDuration;
}

int SPmusicInfo::getIndex() const
{
    return playIndex;
}

QString SPmusicInfo::getUrl() const
{
    return fileUrl;
}

QString SPmusicInfo::getName() const
{
    return musicName;
}

//***************************************

SPmusicItem::SPmusicItem()
{
}

void SPmusicItem::addSPmusic(const SPmusicInfo &aFileInfo)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    musicInfoList << aFileInfo;
    endInsertRows();
}

int SPmusicItem::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return musicInfoList.count();
}

QVariant SPmusicItem::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= musicInfoList.count())
        return QVariant();

    const SPmusicInfo &fileInfo = musicInfoList[index.row()];
    if (role == DurationRole)
        return fileInfo.getDuration();
    else if (role == UrlRole)
        return fileInfo.getUrl();
    else if (role == RankRole)
        return fileInfo.getIndex();
    else if(role == NameRole)
        return fileInfo.getName();
    return QVariant();
}

QHash<int, QByteArray> SPmusicItem::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DurationRole] = "musicDuration";
    roles[UrlRole] = "fileUrl";
    roles[RankRole]="playIndex";
    roles[NameRole]="musicName";
    return roles;
}

QString SPmusicItem::getUrlbyIndex(int d)
{
    return musicInfoList.at(d).getUrl();
}

int SPmusicItem::size()
{
    return musicInfoList.size();
}
