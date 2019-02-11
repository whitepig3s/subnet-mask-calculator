#include<iostream>
#include<fstream>
using namespace std;

void cidrlist(){
    char line[30];
    fstream fin;
    fin.open("CIDR.txt",ios::in);
    while(fin.getline(line,sizeof(line)))
        cout<<line<<endl;
    fin.close();
}
