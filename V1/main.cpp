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
    cout<<"�w��ϥΤl�����B�n�p���"<<endl;
    while (1)
    {
        cout<<endl<<"(1) �B�n�PCIDR�C��"<<endl;        //print list
        cout<<"(2) ���Ѷ��`"<<endl;
        cout<<"(3) IP��}�P�l�����B�n����"<<endl;
        cout<<"(4) IP��}�B�l�����B�n�Ӽƭp��"<<endl;
        cout<<"��J 0 �Y�i�����{��"<<endl;

        cout<<"�п�J�Ʀr: ";
        cin>>in;
        if (in[1]=='\0')
        {
            if (isdigit(in[0]))
            {
                int inn=0;
                inn=in[0]-48;       //char �� int

                if(inn==1)      //�i�J���
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
    cout<<"�Э��s��J"<<endl;
    system("pause");
    system("cls");
}
