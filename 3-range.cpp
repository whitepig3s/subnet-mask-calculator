//無任何檢查，極度信任users
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int cidr (int mask) {
	int temp=8;
	for(int i=0; i<8; i++) {
		if (mask%2==1) {
			temp=i;
			break;
		}
		mask=mask>>1;
	}
	return temp;
}

void range () {
	int ip[4]= {0},mask[4]= {0};

	cout<<"Please input IP address: ";		//input ip address
	for (int i=0; i<3; i++)
		scanf("%d.",&ip[i]);
	cin>>ip[3];

	cout<<"Please input Mask: ";		//input mask
	for (int i=0; i<3; i++)
		scanf("%d.",&mask[i]);
	cin>>mask[3];

	int add[4]= {0};		//ip,mask 進行AND運算
	for (int i=0; i<4; i++)
		add[i]=ip[i]&mask[i];

	/*for (int i=0;i<3;i++)		//output AND result
		cout<<add[i]<<'.';
	cout<<add[3];*/

	int mc=0;		//mc-> Mask cidr表示
	for(int i=3; i>=0; i--)
		mc=mc+cidr(mask[i]);
	mc=32-mc;

	int sbnq=mc%8;		//sbnq-> subnet quantity
	int num=mc/8;
	sbnq=pow(2,sbnq);
	system("cls");
	cout<<"Subnet quantity:"<<sbnq<<endl<<endl;
	int tmp=0;
	for (int i=0; i<sbnq; i++) {
		cout<<"LAN "<<i<<endl;
		for(int j=0; j<num; j++)
			cout<<add[j]<<'.';
		cout<<add[num]<<'.';
		for(int j=num+1; j<4; j++)
			cout<<add[j];

		tmp=256/sbnq;
		cout<<endl<<'~'<<endl;

		add[num]=add[num]+tmp;
		for(int j=0; j<num; j++)
			cout<<add[j]<<'.';
		cout<<add[num]-1<<'.';
		for(int j=num+1; j<4; j++)
			cout<<add[j]+255;
		cout<<endl<<endl;
	}
}
