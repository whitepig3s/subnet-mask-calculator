#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;
void cidrlist();
void convergence();
void range();
void host();
void ree();

int main ()
{
    char in[3]= {0};
    cout<<"歡迎使用子網路遮罩計算機"<<endl;
    while (1)
    {
        cout<<endl<<"(1) 遮罩與CIDR列表"<<endl;        //print list
        cout<<"(2) 路由匯總"<<endl;
        cout<<"(3) IP位址與子網路遮罩對應"<<endl;
        cout<<"(4) IP位址、子網路遮罩個數計算"<<endl;
        cout<<"輸入 0 即可結束程式"<<endl;

        cout<<"請輸入數字: ";
        cin>>in;
        if (in[1]=='\0')
        {
            if (isdigit(in[0]))
            {
                int inn=0;
                inn=in[0]-48;       //char 轉 int

                if(inn==1)      //進入選單
                {
                    system("cls");
                    cidrlist();
                }
                else if (inn==2)
                {
                    system("cls");
                    convergence();
                }
                else if (inn==3)
                {
                    system("cls");
                    range ();
                }
                else if (inn==4)
                {
                    system("cls");
                    host();
                }
                else if (inn==0)
                {
                    system("cls");
                    break;
                }
                else
                    ree();
            }
            else
                ree();
        }
        else
            ree();
    }
    system("cls");
    cout<<"Bye bye!!"<<endl;
    system("pause");
    return 0;
}

void ree()       //re-enter
{
    system("cls");
    cout<<"請重新輸入"<<endl;
    system("pause");
    system("cls");
}
