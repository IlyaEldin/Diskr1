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
    bool l=i((!x||!y),(!(z^x)));//вводимаая функция
    return l;
}

string SDNF()
{
    cout<<"СДНФ функции: ";
    string SD="(";
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
        if (f==1) {
            if (x==1) {
                SD=SD+"x";
            } else {
                SD=SD+"!x";
            }
            if (y==1) {
                SD=SD+"y";
            } else {
                SD=SD+"!y";
            }
            if (z==1) {
                SD=SD+"z";
            } else {
                SD=SD+"!z";
            }
            SD=SD+")+(";
        }
    }
    SD=SD.substr (0,SD.length()-2);
    return SD;

}
string SKNF()
{
    cout<<"СКНФ функции: ";
    string SD="(";
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
    }
    SD=SD.substr (0,SD.length()-1);
    return SD;

}
string polzhe()
{
    cout<<"ПОЛИНОМ ЖЕГАЛКИНА функции: "<<endl;
    string SD="(";
    bool znach8[8];
    bool znach7[7];
    bool znach6[6];
    bool znach5[5];
    bool znach4[4];
    bool znach3[3];
    bool znach2[2];
    bool znach;
    bool x,y,z,f,r;
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
        for(int i=0; i<=7; i++)
            f=f1(x,y,z);
        if (f==1) {
            znach8[i]=true;
        } else {
            znach8[i]=false;
        };
        r=znach8[0];
        cout<<znach8[i];
    }
    if (r==1) {
        SD=SD+"1)+(";
    }
    cout<<endl;
    for (int i=0; i<7; i++) {
        znach7[i]=znach8[i]^znach8[i+1];
        cout<<znach7[i];
    }



    if (znach7[0]==1) {
        SD=SD+"z"+")+(";

    }
    cout<<endl;
    for (int i=0; i<6; i++) {
        znach6[i]=znach7[i]^znach7[i+1];
        cout<<znach6[i];
    }
    if (znach6[0]==1) {
        SD=SD+"y"+")+(";
    }
    cout<<endl;
    for (int i=0; i<5; i++) {
        znach5[i]=znach6[i]^znach6[i+1];
        cout<<znach5[i];
    }
    if (znach5[0]==1) {
        SD=SD+"yz"+")+(";
    }
    cout<<endl;
    for (int i=0; i<4; i++) {
        znach4[i]=znach5[i]^znach5[i+1];
        cout<<znach4[i];
    }
    if (znach4[0]==1) {
        SD=SD+"x"+")+(";
    }
    cout<<endl;
    for (int i=0; i<3; i++) {
        znach3[i]=znach4[i]^znach4[i+1];
        cout<<znach3[i];
    }
    if (znach3[0]==1) {
        SD=SD+"xz"+")+(";
    }
    cout<<endl;
    for (int i=0; i<2; i++) {
        znach2[i]=znach3[i]^znach3[i+1];
        cout<<znach2[i];
    }
    if (znach2[0]==1) {
        SD=SD+"xy"+")+(";

    }
    cout<<endl;
    znach=znach2[0]^znach2[1];
    if (znach==1) {
        SD=SD+"xyz"+")+(";
    }
    cout<<znach<<endl;
    SD=SD.substr (0,SD.length()-2);
    return SD;
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
    cout<<SDNF()<<endl;
    cout<<SKNF()<<endl;
    cout<<polzhe()<<endl;
    return 0;
}
// & & — логическое «И» или логическое умножение (конъюнкция). Оператор И возвращает истину, если верны оба утверждения.
// || — логическое «ИЛИ» или логическое сложение (дизъюнкция). Оператор ИЛИ возвращает истину, если верно хотя бы одно утверждение.
// ! — логическое отрицание. Возвращает истину, если утверждение ложно.
// ^ + по модулю 2
// !(&&) - антиконьюнкция
// ! (||) -антидизъюнкция
