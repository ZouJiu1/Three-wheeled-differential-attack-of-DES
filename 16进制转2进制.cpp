#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    char a[256],count=0,i,j;
    int bin[256][4];
    cout<<"请输入16进制的数：";
    cin>>a;
    for(i=0;a[i]!='\0';i++)
    {
        switch(a[i])
        {
        case'0':
            bin[i][0]=0;
            bin[i][1]=0;
            bin[i][2]=0;
            bin[i][3]=0;
            break;
        case'1':
            bin[i][0]=0;
            bin[i][1]=0;
            bin[i][2]=0;
            bin[i][3]=1;
            break;
        case '2':
            bin[i][0]=0;
            bin[i][1]=0;
            bin[i][2]=1;
            bin[i][3]=0;
            break;
        case '3':
            bin[i][0]=0;
            bin[i][1]=0;
            bin[i][2]=1;
            bin[i][3]=1;
            break;
        case '4':
            bin[i][0]=0;
            bin[i][1]=1;
            bin[i][2]=0;
            bin[i][3]=0;
            break;
        case '5':
            bin[i][0]=0;
            bin[i][1]=1;
            bin[i][2]=0;
            bin[i][3]=1;
            break;
        case '6':
            bin[i][0]=0;
            bin[i][1]=1;
            bin[i][2]=1;
            bin[i][3]=0;
            break;
        case '7':
            bin[i][0]=0;
            bin[i][1]=1;
            bin[i][2]=1;
            bin[i][3]=1;
            break;
        case '8':
            bin[i][0]=1;
            bin[i][1]=0;
            bin[i][2]=0;
            bin[i][3]=0;
            break;
        case '9':
            bin[i][0]=1;
            bin[i][1]=0;
            bin[i][2]=0;
            bin[i][3]=1;
            break;
        case 'A':
            bin[i][0]=1;
            bin[i][1]=0;
            bin[i][2]=1;
            bin[i][3]=0;
            break;
        case 'B':
            bin[i][0]=1;
            bin[i][1]=0;
            bin[i][2]=1;
            bin[i][3]=1;
            break;
        case 'C':
            bin[i][0]=1;
            bin[i][1]=1;
            bin[i][2]=0;
            bin[i][3]=0;
            break;
        case 'D':
            bin[i][0]=1;
            bin[i][1]=1;
            bin[i][2]=0;
            bin[i][3]=1;
            break;
        case 'E':
            bin[i][0]=1;
            bin[i][1]=1;
            bin[i][2]=1;
            bin[i][3]=0;
            break;
        case 'F':
            bin[i][0]=1;
            bin[i][1]=1;
            bin[i][2]=1;
            bin[i][3]=1;
            break;
        default:
            exit(-1);
        }
        count++;
    }
    cout<<"16进制转换为二进制是";
    for(i=0;i<count;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<bin[i][j];
        }
    }
    system("PAUSE");
    return 0;
}
