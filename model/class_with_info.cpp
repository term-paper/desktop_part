#include "class_with_info.h"
#include <QDebug>
class_with_info::class_with_info()
{
}

class_with_info::~class_with_info()
{
}
void class_with_info::print()
{
    qDebug()<<"actual values in class"<<id_info<<" "<<price<<endl;
}

void class_with_info::set_info(int i_var,double d_var)
{
    id_info=i_var;
    price=d_var;
}

int class_with_info::readInfo()
{
    return id_info;
}

void class_with_info::SetInfo(int val)
{
    id_info=val;
}

void class_with_info::SetPrice(double pr)
{
    price=pr;
}
double class_with_info::GetPrice()
{
    return price;
}
