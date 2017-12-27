#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
#include<fstream>
int E[48]= {32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
int Pc[32]= {9,17,23,31,13,28,2,18,24,16,30,6,26,20,10,1,8,14,25,3,4,29,11,19,32,12,22,7,5,27,15,21};
int S[8][4][16]= {{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}}\
    ,{{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}}\
    ,{{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}}\
    ,{{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}}\
    ,{{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}}\
    ,{{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}}\
    ,{{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}}\
    ,{{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
};
int PC2c[56]={5,24,7,16,6,10,20,18,49,12,3,15,23,1,9,19,2,50,14,22,11,51,13,4,52,17,21,8,47,31,27,48,35,41,53,46,28,54,39,32,25,44,55,37,34,43,29,36,38,45,33,26,42,56,30,40};
using namespace std;
class hexbin//16进制的数转换为2进制的数
{
private:
    char a[26],count,i,j,e;
    int bin[16][4];
public:
    int c[64];
    int*bina(int n)
    {
        count=0;
        cout<<"请输入16进制的数"<<n<<"：";
        cin>>a;
        for(i=0; a[i]!='\0'; i++)//每个字符对应相应的四位的二进制数
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
        e=0;
        for(i=0; i<16; i++) //组合成一个数组
        {
            for(j=0; j<4; j++)
            {
                c[e]=bin[i][j];
                e++;
            }
        }
        memset(bin,0,sizeof(int)*64);//重置数组
        memset(a,0,sizeof(char)*26);
        return c;
    }
};
int main()
{
    int i,j,e,b,a[10][64],L0[10][32],L3[10][32],R3[10][32],EL3[10][48],ELc[5][48],Ec[5][8][6],R3c[5][32],L0c[5][32],R3L0[5][32];
    int d,CSS,js,hang,lie,dd,ee,jj,CD[56],CDc[56],Cc[5][32],Ccf[5][8][4],bin[6],bina[6],CS,CS1,binar[6],bin1[4],bin2[4],BIN[4],binary[8][64][6],Bbin[6],count[8][64];
    hexbin hbin;
    for(j=0; j<6; j++) //将16进制明文转换为二进制
    {
        int*c=hbin.bina(j+1);
        for(i=0; i<64; i++)
        {
            a[j][i]=c[i];
        }
    }
    for(j=0; j<6; j++)
    {
        cout<<"\n明文"<<j+1<<"是：";
        for(i=0; i<64; i++)
        {
            cout<<a[j][i];
            if((i+1)==32)
                cout<<"\t";
        }
    }
    for(j=0; j<6; j++) //生成L0
    {
        for(i=0; i<32; i++)
        {
            L0[j][i]=a[j][i];
        }
    }
    memset(a,0,sizeof(int)*640);
    cout<<endl;
    for(j=0; j<6; j++) //将16进制密文转换为二进制
    {
        int*c=hbin.bina(j+1);
        for(i=0; i<64; i++)
        {
            a[j][i]=c[i];
        }
    }
    for(j=0; j<6; j++) //生成L3
    {
        cout<<"\n密文L"<<j+1<<"是：";
        for(i=0; i<32; i++)
        {
            L3[j][i]=a[j][i];
            cout<<L3[j][i];
        }
    }
    cout<<endl;
    for(j=0; j<6; j++) //生成R3
    {
        cout<<"\n密文R"<<j+1<<"是：";
        for(i=32; i<64; i++)
        {
            R3[j][i-32]=a[j][i];
            cout<<R3[j][i-32];
        }
    }
    cout<<endl;
    for(i=0; i<6; i++) //进行E扩展置换
    {
        cout<<"\n进行E扩展置换后的值ER"<<i+1<<"是：";
        for(j=0; j<48; j++)
        {
            EL3[i][j]=L3[i][E[j]-1];
            cout<<EL3[i][j];
        }
    }
    cout<<endl;
    for(i=0; i<6;) //计算输入差分
    {
        for(j=0; j<48; j++)
        {
            if(EL3[i][j]==EL3[i+1][j])
                ELc[i/2][j]=0;
            else
                ELc[i/2][j]=1;
        }
        i=i+2;
    }
    for(i=0; i<3; i++)
    {
        cout<<"\n第"<<i+1<<"对输入异或是：";
        for(j=0; j<48; j++)
        {
            cout<<ELc[i][j];
        }
    }
    for(i=0; i<3; i++) //分组，每组6bit
    {
        for(j=0; j<48;)
        {
            for(e=0; e<6; e++)
            {
                Ec[i][j/6][e]=ELc[i][e+j];
            }
            j=j+6;
        }
    }
    for(i=0; i<6;) //计算差分R3c
    {
        for(j=0; j<32; j++)
        {
            if(R3[i][j]==R3[i+1][j])
                R3c[i/2][j]=0;
            else
                R3c[i/2][j]=1;
        }
        i=i+2;
    }
    for(i=0; i<6;) //计算差分L0c
    {
        for(j=0; j<32; j++)
        {
            if(L0[i][j]==L0[i+1][j])
                L0c[i/2][j]=0;
            else
                L0c[i/2][j]=1;
        }
        i=i+2;
    }
    for(i=0; i<3; i++) //计算R3c和L0c的差分
    {
        for(j=0; j<32; j++)
        {
            if(R3c[i][j]==L0c[i][j])
                R3L0[i][j]=0;
            else
                R3L0[i][j]=1;
        }
    }
    for(i=0; i<3; i++) //P逆置换计算输出差分Cc
    {
        for(j=0; j<32; j++)
        {
            Cc[i][j]=R3L0[i][Pc[j]-1];
        }
    }
    cout<<endl;
    for(i=0; i<3; i++) //P逆置换计算输出差分Cc
    {
        cout<<"\n第"<<i+1<<"对输出异或是：";
        for(j=0; j<32; j++)
        {
            cout<<Cc[i][j];
        }
    }
    for(i=0; i<3; i++) //分组，每组4bit
    {
        for(j=0; j<32;)
        {
            for(e=0; e<4; e++)
            {
                Ccf[i][j/4][e]=Cc[i][e+j];
            }
            j=j+4;
        }
    }
    cout<<endl;
    for(i=0; i<3; i++) //分段输出 输入异或
    {
        cout<<"\n第"<<i+1<<"对输入异或\n";
        cout<<1<<"\t"<<2<<"\t"<<3<<"\t"<<4<<"\t"<<5<<"\t"<<6<<"\t"<<7<<"\t"<<8<<"\n";
        for(j=0; j<8; j++)
        {
            for(e=0; e<6; e++)
            {
                cout<<Ec[i][j][e];
            }
            cout<<"\t";
        }
    }
    cout<<endl;
    for(i=0; i<3; i++) //分段输出 输出异或
    {
        cout<<"\n第"<<i+1<<"对输出异或\n";
        cout<<1<<"\t"<<2<<"\t"<<3<<"\t"<<4<<"\t"<<5<<"\t"<<6<<"\t"<<7<<"\t"<<8<<"\n";
        for(j=0; j<8; j++)
        {
            for(e=0; e<4; e++)
            {
                cout<<Ccf[i][j][e];
            }
            cout<<"\t";
        }
    }
    cout<<endl;
    memset(count,0,sizeof(int)*512);
    for(dd=0; dd<8; dd++) //依次按照S盒来检验找出合适的输入
    {
        for(i=0; i<64; i++)//测试输入6bit，循环检验，找出符合IN（）的输入
        {
            CSS=i;
            memset(bina,0,sizeof(int)*6);
            memset(bin,0,sizeof(int)*6);
            memset(Bbin,0,sizeof(int)*6);
            for(j=0; j<6; j++) //把值转换为二进制
            {
                b=CSS/2;
                bin[j]=CSS%2;
                CSS=b;
                if(CSS==0)//化到最后都会从2或1化到0
                {
                    for(d=j+1; d<6; d++) //补位添0,成为6bit
                    {
                        bin[d]=0;
                    }
                    for(e=5; e>=0; e--)
                    {
                        bina[5-e]=bin[e];
                    }
                    break;
                }
            }
            for(j=0; j<6; j++)
            {
                Bbin[j]=bina[j];
            }
            memset(bin,0,sizeof(int)*6);
            hang=bina[0]*2+bina[5];
            lie=bina[1]*8+bina[2]*4+bina[3]*2+bina[4];
            CS=S[dd][hang][lie];
            memset(bina,0,sizeof(int)*6);
            memset(bin,0,sizeof(int)*6);
            memset(bin1,0,sizeof(int)*4);
            for(j=0; j<4; j++) //把值转换为二进制
            {
                b=CS/2;
                bin[j]=CS%2;
                CS=b;
                if(CS==0)//化到最后都会从2或1化到0
                {
                    for(d=j+1; d<4; d++) //补位添0,成为4bit
                    {
                        bin[d]=0;
                    }
                    for(e=3; e>=0; e--)
                    {
                        bina[3-e]=bin[e];
                    }
                    break;
                }
            }
            for(j=0; j<4; j++)
            {
                bin1[j]=bina[j];
            }
            for(jj=0; jj<3; jj++)//检验不同对的值
            {
                for(j=0; j<6; j++) //输入和输入异或两者异或
                {
                    if(Bbin[j]==Ec[jj][dd][j])
                        binar[j]=0;
                    else
                        binar[j]=1;
                }
                hang=binar[0]*2+binar[5];
                lie=binar[1]*8+binar[2]*4+binar[3]*2+binar[4];
                CS1=S[dd][hang][lie];
                memset(bin2,0,sizeof(int)*4);
                memset(bin,0,sizeof(int)*6);
                memset(bina,0,sizeof(int)*6);
                for(j=0; j<4; j++) //把值转换为二进制
                {
                    b=CS1/2;
                    bin[j]=CS1%2;
                    CS1=b;
                    if(CS1==0)//化到最后都会从2或1化到0
                    {
                        for(d=j+1; d<4; d++) //补位添0,成为4bit
                        {
                            bin[d]=0;
                        }
                        for(e=3; e>=0; e--)
                        {
                            bina[3-e]=bin[e];
                        }
                        break;
                    }
                }
                for(j=0; j<4; j++)
                {
                    bin2[j]=bina[j];
                }
                memset(BIN,0,sizeof(int)*4);
                for(j=0; j<4; j++)
                {
                    if(bin1[j]==bin2[j])
                        BIN[j]=0;
                    else
                        BIN[j]=1;
                }
                if((BIN[0]==Ccf[jj][dd][0])&&(BIN[1]==Ccf[jj][dd][1])&&(BIN[2]==Ccf[jj][dd][2])&&(BIN[3]==Ccf[jj][dd][3]))//判断是不是满足IN的条件
                {
                    for(j=0; j<6; j++)
                    {
                        if(Bbin[j]==EL3[2*jj][(dd*6+j)])//满足的话和Ei异或得到密钥
                            binary[dd][i][j]=0;
                        else
                            binary[dd][i][j]=1;
                    }
                    js=binary[dd][i][0]*32+binary[dd][i][1]*16+binary[dd][i][2]*8+binary[dd][i][3]*4+binary[dd][i][4]*2+binary[dd][i][5];
                    count[dd][js]=count[dd][js]+1;//计数器，计算可能密钥出现的位置和次数
                }
            }
        }
    }
    cout<<endl;
    for(dd=0; dd<8; dd++)
    {
        cout<<"\n\nS"<<dd+1<<":\n";
        for(i=0; i<64; i++)
        {
            cout<<count[dd][i];
            if((i+1)%16==0)
                cout<<"\n";
        }
    }
    cout<<endl<<"得到的第3轮加密的48bit密钥为：\n";
    for(dd=0; dd<8; dd++)//输出二进制结果
    {
        for(i=0; i<64; i++)
        {
            if(count[dd][i]==3)
            {
                CSS=i;
                for(j=0; j<6; j++) //把值转换为二进制
                {
                    b=CSS/2;
                    bin[j]=CSS%2;
                    CSS=b;
                    if(CSS==0)//化到最后都会从2或1化到0
                    {
                        for(d=j+1; d<6; d++) //补位添0,成为6bit
                        {
                            bin[d]=0;
                        }
                        for(e=5; e>=0; e--)
                        {
                            bina[5-e]=bin[e];
                        }
                        break;
                    }
                }
                for(e=0;e<6;e++)
                {
                    cout<<bina[e];
                }
                cout<<"\t";
            }
        }
        for(jj=0;jj<6;jj++)//合并为一个数组
        {
            CDc[(jj+6*dd)]=bina[jj];
        }
    }
    for(i=48;i<56;i++)//赋值给数组以便逆置换得到56bit的中间密钥
    {
        CDc[i]=6;
    }
    for(i=0;i<56;i++)//PC2逆置换得到中间值
    {
        CD[i]=CDc[PC2c[i]-1];
    }
    dd=CD[27];
    jj=CD[26];
    e=CD[25];
    CSS=CD[24];
    for(i=27;i>=4;i--)
    {
        CD[i]=CD[i-4];
    }
    CD[3]=dd;
    CD[2]=jj;
    CD[1]=e;
    CD[0]=CSS;
    dd=CD[55];
    jj=CD[54];
    e=CD[53];
    CSS=CD[52];
    for(i=55;i>=32;i--)
    {
        CD[i]=CD[i-4];
    }
    CD[31]=dd;
    CD[30]=jj;
    CD[29]=e;
    CD[28]=CSS;
    cout<<endl<<"最初加密的56bit密钥为：\n";
    for(i=0;i<56;i++)
    {
        cout<<CD[i];
        if((i+1)%14==0)
            cout<<"\t";
    }
    system("PAUSE");
    return 0;
}
