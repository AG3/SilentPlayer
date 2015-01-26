#ifndef SPMUSICITEM_H
#define SPMUSICITEM_H

#include <QAbstractListModel>
#include <QHash>
#include <QList>

class SPmusicInfo
{
public:
    SPmusicInfo(QString name,QString url,int rank,int duration);
    QString getName() const;
    QString getUrl() const;
    int getIndex() const;
    int getDuration() const;


private:
    QString musicName,fileUrl;
    int playIndex,musicDuration;
};

class SPmusicItem : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SPmusicItem();
    QString getUrlbyIndex(int d);
    enum SPmusicItemRoles {
            DurationRole = Qt::UserRole + 1,
            NameRole,
            RankRole,
            UrlRole
        };
    int size();
        void addSPmusic(const SPmusicInfo &aInfo);
        int rowCount(const QModelIndex & parent = QModelIndex()) const;
        QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<SPmusicInfo> musicInfoList;
};

#endif // SPMUSICITEM_H
