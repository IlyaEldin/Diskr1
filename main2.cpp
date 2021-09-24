#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
bool ai(bool a, bool b)
{
    return (!(!a || b));
}//антиимпликация
bool i(bool a, bool b)
{
    return (!a || b);
}//импликация
bool eq(bool a, bool b)
{
    return (!(a^b));
}//эквивалентность
bool f1(bool x,bool y,bool z)
{
    bool l=x&&(y^z);//вводимаая функция
    return l;
}
bool f2(bool x,bool y,bool z)
{
    bool l=((x&&y)^(x&&z));//вводимаая функция
    return l;
}

void xyz ()
{
    cout<<"Таблица истинности: "<<endl;
    cout<<setw(5)<<"x";
    cout<<setw(5)<<"y";
    cout<<setw(5)<<"z";
    cout<<setw(5)<<"f1";
    cout<<setw(5)<<"f2"<<endl;
    bool x,y,z;
    int d=8;
    for (int i=0; i<d; i++) {{
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i==2)||(i==3)||(i==6)||(i==7)) {
                y=1;
            } else {
                y=0;
            }
            if ((i%2)==1) {
                z=1;
            } else {
                z=0;
            }
        }
        cout<<setw(5)<<x;
        cout<<setw(5)<<y;
        cout<<setw(5)<<z;
        cout<<setw(5)<<f1(x,y,z);
        cout<<setw(5)<<f2(x,y,z)<<endl;
        if (f1(x,y,z)!=f2(x,y,z)) {
            cout<<" - на данной строчке функции отличаются и не могут быть эквивалентными"<<endl;
            break;

        } else {
            if (i==7) {
                cout<<"f1 эквивалентна f2"<<endl;
            }
            continue;
        }


    }
}
int main()
{

    xyz();


    return 0;
}
// & & — логическое «И» или логическое умножение (конъюнкция). Оператор И возвращает истину, если верны оба утверждения.
// || — логическое «ИЛИ» или логическое сложение (дизъюнкция). Оператор ИЛИ возвращает истину, если верно хотя бы одно утверждение.
// ! — логическое отрицание. Возвращает истину, если утверждение ложно.
// ^ + по модулю 2
// !(&&) - антиконьюнкция
// ! (||) -антидизъюнкция
