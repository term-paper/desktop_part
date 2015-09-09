#include "serializedbase.h"
#include <QDebug>
SerializedBase::SerializedBase(QObject *parent) : QObject(parent)
{
}

SerializedBase::~SerializedBase()
{
}

bool SerializedBase::Serialize(QDataStream *dataStream)
{
  if (dataStream == NULL)
    return false;
  for (int i = 1; i < this->metaObject()->propertyCount(); i++)
  {
     QMetaProperty prop = this->metaObject()->property(i);
     const char* propName = prop.name();
     *dataStream << (this->property(propName));
  }
  return true;
}

bool SerializedBase::DeSerialize(QDataStream *dataStream)
{
  if (dataStream == NULL)
    return false;
  for (int i = 1; i < this->metaObject()->propertyCount(); i++)
  {
     QMetaProperty prop = this->metaObject()->property(i);
     const char* propName = prop.name();
     QVariant v;
     *dataStream >> v;
     this->setProperty(propName, v);
  }
  return true;
}
