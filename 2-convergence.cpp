#include<stdio.h>
#include<stdlib.h>
void convergence()
{
    int n,i,j;
    printf("請輸入要輸入的ip數量：\n");
    scanf("%d",&n);
    printf("請輸入ip位址：\n");

    int ip[100][100];//輸入
    for(i=0; i<n; i++)
    {
        for(j=0; j<=2; j++)
            scanf("%d.",&ip[i][j]);
        scanf("%d",&ip[i][3]);
    }

    int temp;//排序
    for(int l=0; l<4; l++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(ip[j][l]>ip[j+1][l])
                {
                    temp=ip[j+1][l];
                    ip[j+1][l]=ip[j][l];
                    ip[j][l]=temp;
                }
            }
        }
    }

    int ip2[100];//求遮罩
    for(i=0; i<4; i++)
        ip2[i]=ip[0][i];
    for(j=0; j<=3; j++)
    {
        for(i=0; i<n-1; i++)
        {
            ip2[j]=ip2[j]^ip[i+1][j];
            ip2[j]=~ip2[j];
            ip2[j]=ip2[j]&ip[i+1][j];
        }
        ip2[j]=ip2[j]^ip[n-1][j];
    }

    int ip4[4];
    for(i=0; i<4; i++)
        ip4[i]=ip2[i];

    int k=128;//轉二進位
    char ip3[100][100];
    for(int i=0; i<=3; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(ip4[i]-k>-1)
            {
                ip3[i][j]='1';
                ip4[i]-=k;
            }
            else
                ip3[i][j]='0';
            k/=2;
            if(k==0)
                k=128;
        }
    }

    int count=0;//求遮罩數
    i=0,j=0;
    while(ip3[i][j]!='1'&&i!=4)
    {
        j++;
        if(j==8)
        {
            i++;
            j=0;
        }
        count++;
        if(ip3[i][j]!='0')
            break;

    }

    int mask=count;//遮罩轉十進位
    int t[5]= {0};

    for(i=0; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            t[i]+=k;
            k/=2;
            if(k==0)
                k=128;
            count--;
            if(count==0)
                break;
        }
        if(count==0)
            break;
    }

    int ip5[5];
    for(i=0; i<4; i++)
        ip5[i]=ip[0][i];

    for(j=0; j<=3; j++) //共同IP
    {
        for(i=0; i<n-1; i++)
        {
            ip5[j]=ip5[j]^ip[i+1][j];
            ip5[j]=~ip5[j];
            ip5[j]=ip5[j]&ip[i+1][j];
        }
    }

    for(i=0; i<4; i++) //匯總
        ip5[i]=ip5[i]&t[i];

    printf("%d.%d.%d.%d/%d\n",ip5[0],ip5[1],ip5[2],ip5[3],mask);
}

