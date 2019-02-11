#include<iostream>
#include<fstream>
using namespace std;

void cidrlist(){
    char line[30];
    fstream fin;
    fin.open("CIDR.txt",ios::in);
    cout<<"CIDR表示法 一般表示法 每個子網路HOST個數 子網路個數"<<endl;
    while(fin.getline(line,sizeof(line)))
        cout<<line<<endl;
    fin.close();
}
