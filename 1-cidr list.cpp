#include<iostream>
#include<fstream>
using namespace std;

void cidrlist(){
    char line[30];
    fstream fin;
    fin.open("CIDR.txt",ios::in);
    cout<<"CIDR��ܪk �@���ܪk �C�Ӥl����HOST�Ӽ� �l�����Ӽ�"<<endl;
    while(fin.getline(line,sizeof(line)))
        cout<<line<<endl;
    fin.close();
}
