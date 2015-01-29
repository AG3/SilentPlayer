#ifndef SPDIRITEM_H
#define SPDIRITEM_H

#include <QObject>

class SPdirContent
{
};

class SPdirItem : public QObject
{
    Q_OBJECT
public:
    explicit SPdirItem(QObject *parent = 0);

signals:

public slots:

};

#endif // SPDIRITEM_H
