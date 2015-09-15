#ifndef CLASS_WITH_INFO_H
#define CLASS_WITH_INFO_H

#include <QObject>
#include "serializedbase.h"
class class_with_info : public SerializedBase
{
    Q_OBJECT
public:
    Q_PROPERTY(int id_info READ readInfo WRITE SetInfo)//связывание set/get function с свойством
    Q_PROPERTY(double price READ GetPrice WRITE SetPrice)

    class_with_info();
    ~class_with_info();

    void print();
    void set_info(int i_var,double d_var);

    int readInfo();//ф-ии чтения и записи
    void SetInfo(int);
    double GetPrice();
    void SetPrice(double);

private:
    int id_info;//поля с данными
    double price;
};

#endif // CLASS_WITH_INFO_H
