#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
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
    bool l=i((!x||!y),(!(z^x)));//вводимаая функция
    return l;
}
string SKNFSDNF()
{
    cout<<"СКНФ функции: ";
    string SD="(";
    string SD1="(";
    bool x,y,z,f;
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
        f=f1(x,y,z);
        if (f==0) {
            if (x==0) {
                SD=SD+"x+";
            } else {
                SD=SD+"!x+";
            }
            if (y==0) {
                SD=SD+"y";
            } else {
                SD=SD+"!y";
            }
            if (z==0) {
                SD=SD+"+z";
            } else {
                SD=SD+"+!z";
            }
            SD=SD+")(";
        }
        if (f==1) {
            if (x==1) {
                SD1=SD1+"x";
            } else {
                SD1=SD1+"!x";
            }
            if (y==1) {
                SD1=SD1+"y";
            } else {
                SD1=SD1+"!y";
            }
            if (z==1) {
                SD1=SD1+"z";
            } else {
                SD1=SD1+"!z";
            }
            SD1=SD1+")+(";
        }
    }
    SD=SD.substr (0,SD.length()-1);
    cout<<SD<<endl;
    cout<<"СДНФ функции: ";
    SD1=SD1.substr (0,SD1.length()-2);
    return SD1;
}
string polzhev2()
{
    cout<<"ПОЛИНОМ ЖЕГАЛКИНА функции: "<<endl;
    string G="(";
    bool zna[8],znach[8],znach1[8];
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
        znach[i]=f1(x,y,z);
        cout<<znach[i];
    }
    cout<<endl;
    zna[7]=znach[0];
    int k=7;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            cout<<znach1[i];
            zna[k-1]=znach1[0];
        }
        cout<<endl;
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+8);
    for(int i=0; i<8; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"z"+")+(";
                break;
            case 2:
                G=G+"y"+")+(";
                break;
            case 3:
                G=G+"yz"+")+(";
                break;
            case 4:
                G=G+"x"+")+(";
                break;
            case 5:
                G=G+"xz"+")+(";
                break;
            case 6:
                G=G+"xy"+")+(";
                break;
            case 7:
                G=G+"xyz"+")+(";
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    return G;
}
void xyz ()
{
    cout<<"Таблица истинности: "<<endl;
    cout<<setw(5)<<"x";
    cout<<setw(5)<<"y";
    cout<<setw(5)<<"z";
    cout<<setw(5)<<"f1"<<endl;
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
        cout<<setw(5)<<f1(x,y,z)<<endl;

    }
}
int main()
{
    xyz();
    cout<<SKNFSDNF()<<endl;
    cout<<polzhev2();
    return 0;
}
// & & — логическое «И» или логическое умножение (конъюнкция). Оператор И возвращает истину, если верны оба утверждения.
// || — логическое «ИЛИ» или логическое сложение (дизъюнкция). Оператор ИЛИ возвращает истину, если верно хотя бы одно утверждение.
// ! — логическое отрицание. Возвращает истину, если утверждение ложно.
// ^ + по модулю 2
// !(&&) - антиконьюнкция
// ! (||) -антидизъюнкция
