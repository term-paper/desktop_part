#ifndef SERIALIZEDBASE_H
#define SERIALIZEDBASE_H

#include <QObject>
#include <QDataStream>
#include <QMetaProperty>
class SerializedBase : public QObject
{
    Q_OBJECT
public:
    explicit SerializedBase(QObject *parent = 0);
    ~SerializedBase();
    bool Serialize(QDataStream *dataStream);
    bool DeSerialize(QDataStream *dataStream);

signals:

public slots:
};

#endif // SERIALIZEDBASE_H
