#include<stdio.h>
#include<stdlib.h>
void host()
{
	FILE *fPtr;
	fPtr =fopen("CDIR.txt","r");
	int a[50][10];
	int n,i,j;
	for(i=29;i>=0;i--)
	{
	fscanf(fPtr,"/%d",&a[i][0]);
	fscanf(fPtr,"%d.%d.%d.%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	fscanf(fPtr,"%d",&a[i][5]);
	fscanf(fPtr,"%d\n",&a[i][6]);
	}
	fclose(fPtr);

    printf("請輸入需要分割的數量：\n");
    scanf("%d",&n);
    printf("請輸入各區需要的數量:\n");

    int ip[100];
    for(i=0;i<n;i++)
	scanf("%d",&ip[i]);

	int temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(ip[j]>ip[j+1])
			{
			temp=ip[j+1];
			ip[j+1]=ip[j];
			ip[j]=temp;
			}
		}
	}

	i=0,j=0;
	while(j!=1)
	{
	if(ip[n-1]>a[i][5])
	i++;
	else
	j=1;
	}

	printf("/%d ",a[i][0]);
	for(j=1;j<4;j++)
    printf("%d.",a[i][j]);
    printf("%d",a[i][4]);
    printf("\n");
}
