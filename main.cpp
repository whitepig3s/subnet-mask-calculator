#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

//----- ¤À¿ëOS -----
#ifdef linux
    #define command "clear"
#endif

#ifdef _WIN32
    #define command "cls"
#endif

#ifdef _WINDOWS
    #define command "cls"
#endif
//----------

void cidrlist();
void summarization();
void range();
void host();
void ree();
void pause ();

int main ()
{
    char in[3]= {0};
    while (1)
    {
        //----- print list -----
        cout<<"########## Menu ##########"<<endl<<endl;
        cout<<"(1) List of mask and CIDR notion."<<endl;
        cout<<"(2) Routing summarization."<<endl;
        cout<<"(3) Calculate IP address and subnet mask number."<<endl;
        cout<<"(4) Calculate IP address and the number of host."<<endl;
        cout<<"Press 0 to exit the program."<<endl;
        //----------

        cout<<endl<<"Please enter a number: ";
        cin>>in;
        if (in[1]=='\0')
        {
            if (isdigit(in[0]))
            {
                int inn=0;
                inn=in[0]-'0';       //char 2 int

                //----- enter -----
                if(inn==1)
                {
                    system(command);
                    cidrlist();
                }
                else if (inn==2)
                {
                    system(command);
                    summarization();
                }
                else if (inn==3)
                {
                    system(command);
                    range ();
                }
                else if (inn==4)
                {
                    system(command);
                    host();
                }
                else if (inn==0)
                {
                    system(command);
                    break;
                }
                else
                    ree();
                //----------
            }
            else
                ree();
        }
        else
            ree();
    }
    system(command);
    cout<<"Bye bye!!"<<endl;
    pause ();
    return 0;
}

void ree()       //re-enter
{
    system(command);
    cout<<"Please re-enter the number."<<endl;
    pause ();
}

void pause ()
{
    cout<<"Press any key to continue...";
    char c=getch();
    system(command);
}
