#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
const int h5=9999999,f4=500000,h4=20000,h3=5000,doub3=2500,c4=900,c3=200,f2=50;
          //h5��ʾ�Լ������������������ʤ
		  //f4��ʾ���ضԷ����е����ģ��ط�
		  //h4��ʾ�Լ������������ġ�����ʤ
		  //h3��ʾ���ضԷ����еĻ���
		  //c4��ʾ�Լ������������ġ����Է��ط�
const int h1=2,c1=1;
char qipan[20][20][4];
char qizi[4];//��������'X'/'O'��
int  piece[20][20]={0};//����Ϊ-1,����Ϊ1����Ϊ0//����Ϊ���� ��Ϊ����
int x,y;//����
int winn=0;//winn��ʾ���ʤ������1Ϊplayer1��2Ϊplayer2;
//char b='��',w='��';
int value[20][20]={0};//ÿ��λ�õ�Ȩ
int num_qizi=-1;//����ת��ÿһ�����µ�����,���ұ��ÿ��λ�õ���ֵ
int maxi,maxj;
int maxi1,maxj1;

void print();//���������
void play();//�������Ϸ����
void check1();//���غ���
void check3();//���غ���
void check4();//���غ���
void check_double3();//���غ���
void check21();//��������
void check31();//��������
void check41();//��������
void check51();//��������
int win();//�ж���Ӯ
bool AI();//��������Ĺ���
void draw();//��������Ӯ��Ľ���
void welcome();//������ӭ����


void check21()
{
	int i,j;
    for (i=3;i<=17;i++)
		for (j=3;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else 
			{
				if (piece[i][j+1]==-1&&piece[i][j+2]==0) value[i][j]+=c1;
                if (piece[i][j-1]==-1&&piece[i][j-2]==0) value[i][j]+=c1;
				if (piece[i-1][j]==-1&&piece[i-2][j]==0) value[i][j]+=c1;
                if (piece[i+1][j]==-1&&piece[i+2][j]==0) value[i][j]+=c1;
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==0) value[i][j]+=h1;
                if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==0) value[i][j]+=h1;
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==0) value[i][j]+=h1;
                if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==0) value[i][j]+=h1;
			}
		}
	
}
void check31()
{
	int i,j;
	//(*)**
	//���ŵ�
    for (i=1;i<=19;i++)
		for(j=3;j<=16;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==0&&piece[i][j-1]==0&&(piece[i][j-2]==0||piece[i][j+4]==0)) value[i][j]+=h3/3;
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==1&&piece[i][j-1]==0&&piece[i][j-2]==0) value[i][j]+=c3/3;
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==0&&piece[i][j-1]==1&&piece[i][j+4]==0) value[i][j]+=c3/3;
			    if (piece[i][j+1]==0&&piece[i][j+2]==-1&&piece[i][j+3]==-1&&piece[i][j+4]==0&&piece[i][j-1]==0) value[i][j]+=h3/3-20;
			}
		}
	for (i=1;i<=19;i++)
		for (j=4;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==0&&piece[i][j+1]==0&&(piece[i][j+2]==0||piece[i][j-4]==0)) value[i][j]+=h3/3;
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==1&&piece[i][j+1]==0&&piece[i][j+2]==0) value[i][j]+=c3/3;
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==0&&piece[i][j+1]==1&&piece[i][j-4]==0) value[i][j]+=c3/3;
			    if (piece[i][j-1]==0&&piece[i][j-2]==-1&&piece[i][j-3]==-1&&piece[i][j+1]==0&&piece[i][j-4]==0) value[i][j]+=h3/3-20;
			}
		}
	//���ŵ�
	for (i=3;i<=16;i++)
		for(j=1;j<=19;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==0&&piece[i-1][j]==0&&(piece[i-2][j]==0||piece[i+4][j]==0)) value[i][j]+=h3/3;
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==1&&piece[i-1][j]==0&&piece[i-2][j]==0) value[i][j]+=c3/3;
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==0&&piece[i-1][j]==1&&piece[i+4][j]==0) value[i][j]+=c3/3;
			    if (piece[i+1][j]==0&&piece[i+2][j]==-1&&piece[i+3][j]==-1&&piece[i+4][j]==0&&piece[i-1][j]==0) value[i][j]+=h3/3-20;
			}
		}
	for (i=4;i<=17;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==0&&piece[i+1][j]==0&&(piece[i+2][j]==0||piece[i-4][j]==0)) value[i][j]+=h3/3;
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==1&&piece[i+1][j]==0&&piece[i+2][j]==0) value[i][j]+=c3/3;
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==0&&piece[i+1][j]==1&&piece[i-4][j]==0) value[i][j]+=c3/3;
			    if (piece[i-1][j]==0&&piece[i-2][j]==-1&&piece[i-3][j]==-1&&piece[i+1][j]==0&&piece[i-4][j]==0) value[i][j]+=h3/3-20;
			}
		}
	//��б
	for (i=3;i<=16;i++)
		for (j=3;j<=16;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==0&&piece[i-1][j-1]==0&&(piece[i-2][j-2]==0||piece[i+4][j+4]==0)) value[i][j]+=h3/3;
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==1&&piece[i-1][j-1]==0&&piece[i-2][j-2]==0) value[i][j]+=c3/3;
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==0&&piece[i-1][j-1]==1&&piece[i+4][j+4]==0) value[i][j]+=c3/3;
			    if (piece[i+1][j+1]==0&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==-1&&piece[i+4][j+4]==0&&piece[i-1][j-1]==0) value[i][j]+=h3/3-20;
			}
		}
	for (i=4;i<=17;i++)
		for (j=4;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==0&&piece[i+1][j+1]==0&&(piece[i+2][j+2]==0||piece[i-4][j-4]==0)) value[i][j]+=h3/3;
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==1&&piece[i+1][j+1]==0&&piece[i+2][j+2]==0) value[i][j]+=c3/3;
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==0&&piece[i+1][j+1]==1&&piece[i-4][j-4]==0) value[i][j]+=c3/3;
			    if (piece[i-1][j-1]==0&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==-1&&piece[i+1][j+1]==0&&piece[i-4][j-4]==0) value[i][j]+=h3/3-20;
			}
		}
	//��б
	for (i=3;i<=16;i++)
		for (j=4;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==0&&piece[i-1][j+1]==0&&(piece[i-2][j+2]==0||piece[i+4][j-4]==0)) value[i][j]+=h3/3;
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==1&&piece[i-1][j+1]==0&&piece[i-2][j+2]==0) value[i][j]+=c3/3;
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==0&&piece[i-1][j+1]==1&&piece[i+4][j-4]==0) value[i][j]+=c3/3;
			    if (piece[i+1][j-1]==0&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==-1&&piece[i+4][j-4]==0&&piece[i-1][j+1]==0) value[i][j]+=h3/3-20;
			}
		}
	for (i=4;i<=17;i++)
		for (j=3;j<=16;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==0&&piece[i+1][j-1]==0&&(piece[i+2][j-2]==0||piece[i-4][j+4]==0)) value[i][j]+=h3/3;
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==1&&piece[i+1][j-1]==0&&piece[i+2][j-2]==0) value[i][j]+=c3/3;
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==0&&piece[i+1][j-1]==1&&piece[i-4][j+4]==0) value[i][j]+=c3/3;
			    if (piece[i-1][j+1]==0&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==-1&&piece[i+1][j-1]==0&&piece[i-4][j+4]==0) value[i][j]+=h3/3-20;
			}
		}
	//*(*)*
	//���ŵ�
    for (i=1;i<=19;i++)
		for(j=3;j<=17;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==0&&piece[i][j-2]==0) value[i][j]+=h3/3;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==1&&piece[i][j-2]==0) value[i][j]+=c3/3;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==0&&piece[i][j-2]==1) value[i][j]+=c3/3;
				if (piece[i][j-1]==-1&&piece[i][j+1]==0&&piece[i][j+2]==-1&&piece[i][j-2]==0&&piece[i][j+3]==0) value[i][j]+=h3/3;
				if (piece[i][j-1]==0&&piece[i][j+1]==-1&&piece[i][j+2]==0&&piece[i][j-2]==-1&&piece[i][j+3]==0) value[i][j]+=h3/3;
			}
		}
	//���ŵ�
	for (i=3;i<=17;i++)
		for(j=1;j<=19;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==0&&piece[i-2][j]==0) value[i][j]+=h3/3;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==1&&piece[i-2][j]==0) value[i][j]+=c3/3;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==0&&piece[i-2][j]==1) value[i][j]+=c3/3;
				if (piece[i-1][j]==-1&&piece[i+1][j]==0&&piece[i+2][j]==-1&&piece[i-2][j]==0&&piece[i+3][j]==0) value[i][j]+=h3/3;
				if (piece[i-1][j]==0&&piece[i+1][j]==-1&&piece[i+2][j]==0&&piece[i-2][j]==-1&&piece[i+3][j]==0) value[i][j]+=h3/3;
			}
		}
	//��б
	for (i=3;i<=17;i++)
		for (j=3;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]&&piece[i+2][j+2]==0&&piece[i-2][j-2]==0) value[i][j]+=h3/3;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]&&piece[i+2][j+2]==0&&piece[i-2][j-2]==1) value[i][j]+=c3/3;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]&&piece[i+2][j+2]==1&&piece[i-2][j-2]==0) value[i][j]+=c3/3;
				if (piece[i-1][j-1]==-1&&piece[i+1][j+1]==0&&piece[i+2][j+2]==-1&&piece[i-2][j-2]==0&&piece[i+3][j+3]==0) value[i][j]+=h3/3;
				if (piece[i-1][j-1]==0&&piece[i+1][j+1]==-1&&piece[i+2][j+2]==0&&piece[i-2][j-2]==-1&&piece[i+3][j+3]==0) value[i][j]+=h3/3;
			}
		}
	//��б
	for (i=3;i<=17;i++)
		for (j=3;j<=17;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]&&piece[i+2][j-2]==0&&piece[i-2][j+2]==0) value[i][j]+=h3/3;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]&&piece[i+2][j-2]==0&&piece[i-2][j+2]==1) value[i][j]+=c3/3;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]&&piece[i+2][j-2]==1&&piece[i-2][j+2]==0) value[i][j]+=c3/3;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==0&&piece[i-2][j+2]==-1&&piece[i+2][j-2]==0&&piece[i-3][j+3]==0) value[i][j]+=h3/3;
				if (piece[i+1][j-1]==0&&piece[i-1][j+1]==-1&&piece[i-2][j+2]==0&&piece[i+2][j-2]==-1&&piece[i-3][j+3]==0) value[i][j]+=h3/3;
			}
		}
}
void check41()
{
     int i,j;
	//(*)***/***(*)
	//���ŵ�
    for (i=1;i<=19;i++)
		for(j=2;j<=15;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==-1&&piece[i][j+4]==0&&piece[i][j-1]==0) value[i][j]+=h4;
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==-1&&piece[i][j+4]==1&&piece[i][j-1]==0) value[i][j]+=c4;
				if (piece[i][j+1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==-1&&piece[i][j+4]==0&&piece[i][j-1]==1) value[i][j]+=c4;
				if (piece[i][j+1]==0&&piece[i][j+2]==-1&&piece[i][j+3]==-1&&piece[i][j+4]==-1) value[i][j]+=c4-20;
			}
		}
	for (i=1;i<=19;i++)
		for (j=5;j<=18;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==-1&&piece[i][j-4]==0&&piece[i][j+1]==0) value[i][j]+=h4;
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==-1&&piece[i][j-4]==1&&piece[i][j+1]==0) value[i][j]+=c4;
				if (piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==-1&&piece[i][j-4]==0&&piece[i][j+1]==1) value[i][j]+=c4;
				if (piece[i][j-1]==0&&piece[i][j-2]==-1&&piece[i][j-3]==-1&&piece[i][j-4]==-1) value[i][j]+=c4-20;	
			}
		}
	//���ŵ�
	for (i=2;i<=15;i++)
		for(j=1;j<=19;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==-1&&piece[i+4][j]==0&&piece[i-1][j]==0) value[i][j]+=h4;
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==-1&&piece[i+4][j]==1&&piece[i-1][j]==0) value[i][j]+=c4;
				if (piece[i+1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==-1&&piece[i+4][j]==0&&piece[i-1][j]==1) value[i][j]+=c4;
				if (piece[i+1][j]==0&&piece[i+2][j]==-1&&piece[i+3][j]==-1&&piece[i+4][j]==-1) value[i][j]+=c4-20;
			}
		}
	for (i=5;i<=18;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==-1&&piece[i-4][j]==0&&piece[i+1][j]==0) value[i][j]+=h4;
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==-1&&piece[i-4][j]==1&&piece[i+1][j]==0) value[i][j]+=c4;
				if (piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==-1&&piece[i-4][j]==0&&piece[i+1][j]==1) value[i][j]+=c4;
				if (piece[i-1][j]==0&&piece[i-2][j]==-1&&piece[i-3][j]==-1&&piece[i-4][j]==-1) value[i][j]+=c4-20;
			}
		}
	//��б
	for (i=2;i<=15;i++)
		for (j=2;j<=15;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==-1&&piece[i+4][j+4]==0&&piece[i-1][j-1]==0) value[i][j]+=h4;
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==-1&&piece[i+4][j+4]==1&&piece[i-1][j-1]==0) value[i][j]+=c4;
				if (piece[i+1][j+1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==-1&&piece[i+4][j+4]==0&&piece[i-1][j-1]==1) value[i][j]+=c4;
				if (piece[i+1][j+1]==0&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==-1&&piece[i+4][j+4]==-1) value[i][j]+=c4-20;
			}
		}
	for (i=5;i<=18;i++)
		for (j=5;j<=18;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==-1&&piece[i-4][j-4]==0&&piece[i+1][j+1]==0) value[i][j]+=h4;
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==-1&&piece[i-4][j-4]==1&&piece[i+1][j+1]==0) value[i][j]+=c4;
				if (piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==-1&&piece[i-4][j-4]==0&&piece[i+1][j+1]==1) value[i][j]+=c4;
				if (piece[i-1][j-1]==0&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==-1&&piece[i-4][j-4]==-1) value[i][j]+=c4-20;
			}
		}
	//��б
	for (i=5;i<=18;i++)
		for (j=2;j<=15;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==-1&&piece[i-4][j+4]==0&&piece[i+1][j-1]==0) value[i][j]+=h4;
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==-1&&piece[i-4][j+4]==1&&piece[i+1][j-1]==0) value[i][j]+=c4;
				if (piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==-1&&piece[i-4][j+4]==0&&piece[i+1][j-1]==1) value[i][j]+=c4;
				if (piece[i-1][j+1]==0&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==-1&&piece[i-4][j+4]==-1) value[i][j]+=c4-20;	 
			}
		}
	for (i=2;i<=15;i++)
		for (j=5;j<=18;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==-1&&piece[i+4][j-4]==0&&piece[i-1][j+1]==0) value[i][j]+=h4;
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==-1&&piece[i+4][j-4]==1&&piece[i-1][j+1]==0) value[i][j]+=c4;
				if (piece[i+1][j-1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==-1&&piece[i+4][j-4]==0&&piece[i-1][j+1]==1) value[i][j]+=c4;
				if (piece[i+1][j-1]==0&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==-1&&piece[i+4][j-4]==-1) value[i][j]+=c4-20;
			}
		}
	//*(*)**/**(*)*
	//���ŵ�
    for (i=1;i<=19;i++)
		for(j=4;j<=16;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==0&&piece[i][j-2]==0) value[i][j]+=h4;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==0&&piece[i][j+2]==0) value[i][j]+=h4;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==1&&piece[i][j-2]==0) value[i][j]+=c4;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j+2]==-1&&piece[i][j+3]==0&&piece[i][j-2]==1) value[i][j]+=c4;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==1&&piece[i][j+2]==0) value[i][j]+=c4;
				if (piece[i][j+1]==-1&&piece[i][j-1]==-1&&piece[i][j-2]==-1&&piece[i][j-3]==0&&piece[i][j+2]==1) value[i][j]+=c4;

			}
		}
	//���ŵ�
	for (i=4;i<=16;i++)
		for(j=1;j<=19;j++)
		{
            if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==0&&piece[i-2][j]==0) value[i][j]+=h4;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==0&&piece[i+2][j]==0) value[i][j]+=h4;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==1&&piece[i-2][j]==0) value[i][j]+=c4;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i+2][j]==-1&&piece[i+3][j]==0&&piece[i-2][j]==1) value[i][j]+=c4;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==1&&piece[i+2][j]==0) value[i][j]+=c4;
				if (piece[i+1][j]==-1&&piece[i-1][j]==-1&&piece[i-2][j]==-1&&piece[i-3][j]==0&&piece[i+2][j]==1) value[i][j]+=c4;
			}
		}
	//��б
	for (i=4;i<=16;i++)
		for (j=4;j<=16;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==0&&piece[i-2][j-2]==0) value[i][j]+=h4;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==0&&piece[i+2][j+2]==0) value[i][j]+=h4;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==1&&piece[i-2][j-2]==0) value[i][j]+=c4;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i+2][j+2]==-1&&piece[i+3][j+3]==0&&piece[i-2][j-2]==1) value[i][j]+=c4;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==1&&piece[i+2][j+2]==0) value[i][j]+=c4;
				if (piece[i+1][j+1]==-1&&piece[i-1][j-1]==-1&&piece[i-2][j-2]==-1&&piece[i-3][j-3]==0&&piece[i+2][j+2]==1) value[i][j]+=c4;
			}
		}
	//��б
	for (i=4;i<=16;i++)
		for (j=4;j<=16;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==0&&piece[i-2][j+2]==0) value[i][j]+=h4;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==0&&piece[i+2][j-2]==0) value[i][j]+=h4;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==1&&piece[i-2][j+2]==0) value[i][j]+=c4;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i+2][j-2]==-1&&piece[i+3][j-3]==0&&piece[i-2][j+2]==1) value[i][j]+=c4;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==1&&piece[i+2][j-2]==0) value[i][j]+=c4;
				if (piece[i+1][j-1]==-1&&piece[i-1][j+1]==-1&&piece[i-2][j+2]==-1&&piece[i-3][j+3]==0&&piece[i+2][j-2]==1) value[i][j]+=c4;
			}
		} 
}
void check51()
{
	//���ŵ�
	int i,j,sum=0;
	for (i=1;i<=19;i++)
		for(j=1;j<=15;j++)
		{
			for (int t=0;t<=4;t++)
				sum+=piece[i][j+t];
			if (sum==-4)
			{
				for (int t=0;t<=4;t++)
					if (piece[i][j+t]==0) value[i][j+t]+=h5;
			}
			sum=0;
		}
	//���ŵ�
	for (i=1;i<=15;i++)
		for(j=1;j<=19;j++)
		{
			for (int t=0;t<=4;t++)
				sum+=piece[i+t][j];
			if (sum==-4)
			{
				for (int t=0;t<=4;t++)
					if (piece[i+t][j]==0) value[i+t][j]+=h5;
			}
			sum=0;
		}
	//��б
	for (i=1;i<=15;i++)
		for(j=1;j<=15;j++)
		{
			for (int t=0;t<=4;t++)
				sum+=piece[i+t][j+t];
			if (sum==-4)
			{
				for (int t=0;t<=4;t++)
					if (piece[i+t][j+t]==0) value[i+t][j+t]+=h5;
			}
			sum=0;
		}
	//��б
	for (i=5;i<=19;i++)
		for(j=1;j<=15;j++)
		{
			for (int t=0;t<=4;t++)
				sum+=piece[i-t][j+t];
			if (sum==-4)
			{
				for (int t=0;t<=4;t++)
					if (piece[i-t][j+t]==0) value[i-t][j+t]+=h5;
			}
			sum=0;
		}
}
void check1()
{
	int i,j;
	for (i=3;i<=17;i++)
		for (j=3;j<=17;j++)
		{
			if (piece[i][j]==0) continue;
			else
			{
				if ((piece[i-1][j-1]==0)&&(piece[i+1][j+1]==0)&&piece[i-2][j-2]==0&&piece[i+2][j+2]==0) 
				{
					value[i-1][j-1]+=h1;value[i+1][j+1]+=h1;
				}
				if ((piece[i-1][j+1]==0)&&(piece[i+1][j-1]==0)&&piece[i-2][j+2]==0&&piece[i+2][j-2]==0) 
				{
					value[i-1][j+1]+=h1;value[i+1][j-1]+=h1;
				}
			}
		}
}
void check3()//����
{
	int sum=0;
	int z=0;
	int i,j;
	//�ж�***
	  //���ŵ�
	for (i=1;i<=19;i++)
		for (j=1;j<=15;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
	         for (int t=1;t<=3;t++)
			     sum+=piece[i][j+t];
			 if ((sum==3)&&(piece[i][j+4]==0)) value[i][j]+=h3;
		     sum=0;
			}
		}
	for (i=1;i<=19;i++)
		for (j=5;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
			for (int t=1;t<=3;t++)
				sum+=piece[i][j-t];
			if ((sum==3)&&(piece[i][j-4]==0)) value[i][j]+=h3;
			sum=0;
			}
		}
	//���ŵĻ���
	for (i=5;i<=19;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
			for (int t=1;t<=3;t++)
                 sum+=piece[i-t][j];
			if ((sum==3)&&(piece[i-4][j]==0)) value[i][j]+=h3;
			sum=0;
			}
		}
	for (i=1;i<=15;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
			for (int t=1;t<=3;t++)
                 sum+=piece[i+t][j];
			if ((sum==3)&&(piece[i+4][j]==0)) value[i][j]+=h3;
			sum=0;
			}
		}
	//��б����
		for (i=5;i<=19;i++)
			for (j=5;j<=19;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				for (int t=1;t<=3;t++)
					sum+=piece[i-t][j-t];
			    if ((sum==3)&&(piece[i-4][j-4]==0)) value[i][j]+=h3;
		        sum=0;
				}
			}
		for (i=1;i<=15;i++)
			for (j=1;j<=15;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				for (int t=1;t<=3;t++)
					sum+=piece[i+t][j+t];
			    if ((sum==3)&&(piece[i+4][j+4]==0)) value[i][j]+=h3;
		        sum=0;
				}
			}
	//��б����
		for (i=1;i<=15;i++)
			for(j=5;j<=19;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				for (int t=1;t<=3;t++)
					sum+=piece[i+t][j-t];
			    if ((sum==3)&&(piece[i+4][j-4]==0)) value[i][j]+=h3;
		        sum=0;
				}
			}
		for (i=5;i<=19;i++)
			for(j=1;j<=15;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				for (int t=1;t<=3;t++)
					sum+=piece[i-t][j+t];
			    if ((sum==3)&&(piece[i-4][j+4]==0)) value[i][j]+=h3;
		        sum=0;
				}
			}
	//�ж�**_*/*_**
			//���ŵ�
		for (i=1;i<=19;i++)
			for (j=3;j<=17;j++)
			{
                 if (piece[i][j]!=0) continue;
				 else
				 {
					 if ((piece[i][j-1]+piece[i][j+1]+piece[i][j-2]==3)&&(piece[i][j-3]==0)&&(piece[i][j+2]==0))
						 value[i][j]+=h3;
					 if ((piece[i][j-1]+piece[i][j+1]+piece[i][j+2]==3)&&(piece[i][j+3]==0)&&(piece[i][j-2]==0))
						 value[i][j]+=h3;
				 }
			}
			//���ŵ�
	    for (i=3;i<=17;i++)
			for (j=1;j<=19;j++)
			{
                 if (piece[i][j]!=0) continue;
				 else
				 {
					 if ((piece[i-1][j]+piece[i+1][j]+piece[i-2][j]==3)&&(piece[i-3][j]==0)&&(piece[i+2][j]==0))
						 value[i][j]+=h3;
					 if ((piece[i-1][j]+piece[i+1][j]+piece[i+2][j]==3)&&(piece[i+3][j]==0)&&(piece[i-2][j]==0))
						 value[i][j]+=h3;
				 }
			}
			//��б
		for (i=3;i<=17;i++)
			for (j=3;j<=17;j++)
			{
                 if (piece[i][j]!=0) continue;
				 else
				 {
					 if ((piece[i-1][j-1]+piece[i+1][j+1]+piece[i-2][j-2]==3)&&(piece[i-3][j-3]==0)&&(piece[i+2][j+2]==0))
						 value[i][j]+=h3;
					 if ((piece[i-1][j-1]+piece[i+1][j+1]+piece[i+2][j+2]==3)&&(piece[i+3][j+3]==0)&&(piece[i-2][j-2]==0))
						 value[i][j]+=h3;					 
				 }
			}
			//��б
		for (i=3;i<=17;i++)
			for (j=3;j<=17;j++)
			{
                 if (piece[i][j]!=0) continue;
				 else
				 {
					 if ((piece[i-1][j+1]+piece[i+1][j-1]+piece[i-2][j+2]==3)&&(piece[i-3][j+3]==0)&&(piece[i+2][j-2]==0))
						 value[i][j]+=h3;
					 if ((piece[i+1][j-1]+piece[i-1][j+1]+piece[i+2][j-2]==3)&&(piece[i+3][j-3]==0)&&(piece[i-2][j+2]==0))
						 value[i][j]+=h3;					 
				 }
			}
}

void check4()
{
    //���ŵ�
	int i,j,sum=0;
	for (i=1;i<=19;i++)
		for (j=1;j<=15;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				for (int t=0;t<=4;t++)
					sum+=piece[i][j+t];
				if (sum==4) 
				{
					for (int t=0;t<=4;t++)
						if (piece[i][j+t]==0) value[i][j+t]+=f4;
				}
				sum=0;
			}
		}
	for (i=1;i<=19;i++)
		for (j=5;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				for (int t=0;t<=4;t++)
					sum+=piece[i][j-t];
				if (sum==4) 
				{
					for (int t=0;t<=4;t++)
						if (piece[i][j-t]==0) value[i][j-t]+=f4;
				}
				sum=0;
			}
		}
	//���ŵ�
	for (i=1;i<=15;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				for (int t=0;t<=4;t++)
					sum+=piece[i+t][j];
				if (sum==4) 
				{
					for (int t=0;t<=4;t++)
						if (piece[i+t][j]==0) value[i+t][j]+=f4;
				}
				sum=0;
			}
		}
	for (i=5;i<=19;i++)
		for (j=1;j<=19;j++)
		{
			if (piece[i][j]!=0) continue;
			else
			{
				for (int t=0;t<=4;t++)
					sum+=piece[i-t][j];
				if (sum==4) 
				{
					for (int t=0;t<=4;t++)
						if (piece[i-t][j]==0) value[i-t][j]+=f4;
				}
				sum=0;
			}
		}
	//��б
		for (i=1;i<=15;i++)
			for (j=1;j<=15;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				  for (int t=0;t<=4;t++)
				 	sum+=piece[i+t][j+t];
				   if (sum==4) 
				   {
					for (int t=0;t<=4;t++)
						if (piece[i+t][j+t]==0) value[i+t][j+t]+=f4;
				   }
				  sum=0;
			    }
			}
		for (i=5;i<=19;i++)
			for (j=5;j<=19;j++)
			{
				if (piece[i][j]!=0) continue;
			    else
			    {
				for (int t=0;t<=4;t++)
					sum+=piece[i-t][j-t];
				   if (sum==4) 
				   {
					for (int t=0;t<=4;t++)
						if (piece[i-t][j-t]==0) value[i-t][j-t]+=f4;
				   }
				sum=0;
			    }
			}
	//��б
		for (i=1;i<=15;i++)
			for (j=5;j<=19;j++)
			{
				if (piece[i][j]!=0) continue;
				else
				{
					for (int t=0;t<=4;t++)
						sum+=piece[i+t][j-t];
				   if (sum==4) 
				   {
					for (int t=0;t<=4;t++)
						if (piece[i+t][j-t]==0) value[i+t][j-t]+=f4;
				   }
					sum=0;
				}
			}
		for (i=5;i<=19;i++)
			for (j=1;j<=15;j++)
			{
				if (piece[i][j]!=0) continue;
				else
				{
					for (int t=0;t<=4;t++)
						sum+=piece[i-t][j+t];
				   if (sum==4) 
				   {
					for (int t=0;t<=4;t++)
						if (piece[i-t][j+t]==0) value[i-t][j+t]+=f4;
				   }
					sum=0;
				}
			}
	//���ŵ�
		for (i=1;i<=19;i++)
             for (j=2;j<=16;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-1;t<=3;t++)
						sum+=piece[i][j+t];
						if (sum==4)
						{
							for (int t=-1;t<=3;t++)
								if (piece[i][j+t]==0) value[i][j+t]+=f4;
						}
					sum=0;
				}
			 }
		 for (i=1;i<=19;i++)
             for (j=4;j<=18;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-1;t<=3;t++)
						sum+=piece[i][j-t];
						if (sum==4)
						{
							for (int t=-1;t<=3;t++)
								if (piece[i][j-t]==0) value[i][j-t]+=f4;
						}
						sum=0;
				}
			 }
		for (i=1;i<=19;i++)
             for (j=3;j<=17;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-2;t<=2;t++)
						sum+=piece[i][j+t];
					if (sum==4)
						{
							for (int t=-2;t<=2;t++)
								if (piece[i][j+t]==0) value[i][j+t]+=f4;
						}
					sum=0;
				}
			 }
	 //���ŵ�
		for (i=2;i<=16;i++)
             for (j=1;j<=19;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-1;t<=3;t++)
						sum+=piece[i+t][j];
						if (sum==4)
						{
							for (int t=-1;t<=3;t++)
								if (piece[i+t][j]==0) value[i+t][j]+=f4;
						}
					sum=0;
				}
			 }
		 for (i=4;i<=18;i++)
             for (j=1;j<=19;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-1;t<=3;t++)
						sum+=piece[i-t][j];
						if (sum==4)
						{
							for (int t=-1;t<=3;t++)
								if (piece[i-t][j]==0) value[i-t][j]+=f4;
						}
						sum=0;
				}
			 }
		for (i=3;i<=17;i++)
             for (j=1;j<=19;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else
				{
					for (int t=-2;t<=2;t++)
						sum+=piece[i+t][j];
					if (sum==4)
						{
							for (int t=-2;t<=2;t++)
								if (piece[i+t][j]==0) value[i+t][j]+=f4;
						}
					sum=0;
				}
			 }
		 //��б
	 for (i=2;i<=16;i++)
		 for (j=2;j<=16;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-1;t<=3;t++)
					 sum+=piece[i+t][j+t];
				 if (sum==4)
				 {
					 for (int t=-1;t<=3;t++)
						 if (piece[i+t][j+t]==0) value[i+t][j+t]+=f4;
				 }
				 sum=0;
			 }
		 }
 	 for (i=4;i<=18;i++)
		 for (j=4;j<=18;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-1;t<=3;t++)
					 sum+=piece[i-t][j-t];
				 if (sum==4)
				 {
					 for (int t=-1;t<=3;t++)
						 if (piece[i-t][j-t]==0) value[i-t][j-t]+=f4;
				 }
				 sum=0;
			 }
		 }
	 for (i=3;i<=17;i++)
		 for (j=3;j<=17;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-2;t<=2;t++)
					 sum+=piece[i+t][j+t];
				 if (sum==4)
				 {
					 for (int t=-2;t<=2;t++)
						 if (piece[i+t][j+t]==0) value[i+t][j+t]+=f4;
				 }
				 sum=0;
			 }
		 }
   //��б
	 for (i=2;i<=16;i++)
		 for (j=4;j<=18;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-1;t<=3;t++)
					 sum+=piece[i+t][j-t];
				 if (sum==4)
				 {
					 for (int t=-1;t<=3;t++)
						 if (piece[i+t][j-t]==0) value[i+t][j-t]+=f4;
				 }
				 sum=0;
			 }
		 }
 	 for (i=4;i<=18;i++)
		 for (j=2;j<=16;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-1;t<=3;t++)
					 sum+=piece[i-t][j+t];
				 if (sum==4)
				 {
					 for (int t=-1;t<=3;t++)
						 if (piece[i-t][j+t]==0) value[i-t][j+t]+=f4;
				 }
				 sum=0;
			 }
		 }
	 for (i=3;i<=17;i++)
		 for (j=3;j<=17;j++)
		 {
			 if (piece[i][j]!=0) continue;
			 else
			 {
				 for (int t=-2;t<=2;t++)
					 sum+=piece[i+t][j-t];
				 if (sum==4)
				 {
					 for (int t=-2;t<=2;t++)
						 if (piece[i+t][j-t]==0) value[i+t][j-t]+=f4;
				 }
				 sum=0;
			 }
		 }
}
void check_double3()
{
     int i,j;
	 int doub[19][19]={0};
	 //���ŵ�**_()/_**()/*_*()������
	 for (i=2;i<=18;i++)
		 for (j=3;j<=18;j++)
		 { 
             if (piece[i][j]!=0) continue;
			 else
				 if ((piece[i][j-1]+piece[i][j-2]+piece[i][j-3]==2)&&(piece[i][j-4]!=-1)&&(piece[i][j+1]!=-1)) doub[i][j]++;
		 }
	 for (i=2;i<=18;i++)
		 for (j=2;j<=17;j++)
		 { 
             if (piece[i][j]!=0) continue;
			 else
				 if ((piece[i][j+1]+piece[i][j+2]+piece[i][j+3]==2)&&(piece[i][j+4]!=-1)&&(piece[i][j-1]!=-1)) doub[i][j]++;
		 }
	 //���ŵ�
		 for (i=3;i<=18;i++)
			 for (j=2;j<=18;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else if ((piece[i-1][j]+piece[i-2][j]+piece[i-3][j]==2)&&(piece[i-4][j]!=-1)&&(piece[i+1][j]!=-1)) doub[i][j]++;
			 }
		 for (i=2;i<=17;i++)
			 for (j=2;j<=18;j++)
			 {
				 if (piece[i][j]!=0) continue;
				 else if (piece[i+1][j]+piece[i+2][j]+piece[i+3][j]==2&&(piece[i+4][j]!=-1)&&piece[i-1][j]!=-1) doub[i][j]++;
			 }
		 //��б
			 for (i=3;i<=17;i++)
				 for (j=3;j<=17;j++)
				 {
					 if (piece[i][j]!=0) continue;
					 else if (piece[i-1][j-1]+piece[i-2][j-2]+piece[i-3][j-3]==2&&(piece[i-4][j-4]!=-1)&&piece[i+1][j+1]!=-1) doub[i][j]++;
				 }
			 for (i=3;i<=16;i++)
				 for (j=3;j<=16;j++)
				 {
					 if (piece[i][j]!=0) continue;
					 else if (piece[i+1][j+1]+piece[i+2][j+2]+piece[i+3][j+3]==2&&piece[i+4][j+4]!=-1&&piece[i-1][j-1]!=-1) doub[i][j]++;
				 }
		 //��б
			 for (i=2;i<=16;i++)
				 for (j=3;j<=18;j++)
				 {
					 if (piece[i][j]!=0) continue;
					 else if (piece[i+1][j-1]+piece[i+2][j-2]+piece[i+3][j-3]==2&&piece[i+4][j-4]!=-1&&piece[i-1][j+1]!=-1) doub[i][j]++;
				 }
			 for (i=3;i<=17;i++)
				 for (j=2;j<=16;j++)
				 {
					 if (piece[i][j]!=0) continue;
					 else if (piece[i-1][j+1]+piece[i-2][j+2]+piece[i-3][j+3]==2&&piece[i-4][j+4]!=-1&&piece[i+1][j-1]!=-1) doub[i][j]++;
				 }
	 // _*()*_
	   for (i=3;i<=17;i++)
		   for (j=3;j<=17;j++)
		   {
			   if (piece[i][j]!=0) continue;
			   else
			   {
				   if (piece[i][j-1]==1&&piece[i][j+1]==1&&piece[i][j-2]==0&&piece[i][j+2]==0&&piece[i][j-3]+piece[i][j+3]<=1) doub[i][j]++;
				   if (piece[i][j-1]==1&&piece[i][j+1]==0&&piece[i][j-2]==0&&piece[i][j+2]==1&&piece[i][j-3]+piece[i][j+3]<=1) doub[i][j]++;
				   if (piece[i][j-1]==0&&piece[i][j+1]==1&&piece[i][j-2]==1&&piece[i][j+2]==0&&piece[i][j-3]+piece[i][j+3]<=1) doub[i][j]++;
			   }
		   }
	   for (i=3;i<=17;i++)
		   for (j=3;j<=17;j++)
		   {
			   if (piece[i][j]!=0) continue;
			   else
			   {
				   if (piece[i-1][j]==1&&piece[i+1][j]==1&&piece[i-2][j]==0&&piece[i+2][j]==0&&piece[i-3][j]+piece[i+3][j]<=1) doub[i][j]++;
				   if (piece[i-1][j]==1&&piece[i+1][j]==0&&piece[i-2][j]==0&&piece[i+2][j]==1&&piece[i-3][j]+piece[i+3][j]<=1) doub[i][j]++;
				   if (piece[i-1][j]==0&&piece[i+1][j]==1&&piece[i-2][j]==1&&piece[i+2][j]==0&&piece[i-3][j]+piece[i+3][j]<=1) doub[i][j]++;
			   }
		   }
	   for (i=3;i<=17;i++)
		   for (j=3;j<=17;j++)
		   {
			   if (piece[i][j]!=0) continue;
			   else
			   {
				   if (piece[i-1][j-1]==1&&piece[i+1][j+1]==1&&piece[i-2][j-2]==0&&piece[i+2][j+2]==0&&piece[i-3][j-3]+piece[i+3][j+3]<=1) doub[i][j]++;
				   if (piece[i-1][j-1]==1&&piece[i+1][j+1]==0&&piece[i-2][j-2]==0&&piece[i+2][j+2]==1&&piece[i-3][j-3]+piece[i+3][j+3]<=1) doub[i][j]++;
				   if (piece[i-1][j-1]==0&&piece[i+1][j+1]==1&&piece[i-2][j-2]==1&&piece[i+2][j+2]==0&&piece[i-3][j-3]+piece[i+3][j+3]<=1) doub[i][j]++;
			   }
		   }
	   for (i=3;i<=17;i++)
		   for (j=3;j<=17;j++)
		   {
			   if (piece[i][j]!=0) continue;
			   else
			   {
				   if (piece[i-1][j+1]==1&&piece[i+1][j-1]==1&&piece[i-2][j+2]==0&&piece[i+2][j-2]==0&&piece[i-3][j+3]+piece[i+3][j-3]<=1) doub[i][j]++;
				   if (piece[i-1][j+1]==1&&piece[i+1][j-1]==0&&piece[i-2][j+2]==0&&piece[i+2][j-2]==1&&piece[i-3][j+3]+piece[i+3][j-3]<=1) doub[i][j]++;
				   if (piece[i-1][j+1]==0&&piece[i+1][j-1]==1&&piece[i-2][j+2]==1&&piece[i+2][j-2]==0&&piece[i-3][j+3]+piece[i+3][j-3]<=1) doub[i][j]++;
			   }
		   }
      for (i=2;i<=18;i++)
		  for (j=2;j<=18;j++)
		  {
			  if (doub[i][j]==1) value[i][j]+=f2;
			  if (doub[i][j]>=2) value[i][j]+=doub3;
		  }
}
void plays()
{
	int b;
	for(int i=1;i<=19;i++)
		for (int j=1;j<=19;j++)
			strcpy(qipan[i][j],"��");
	cout<<"                                    1.First player  ��ִ�����֣�             "<<endl;
	cout<<"                                    2.First computer��ִ�׺��֣�             "<<endl;
	cin>>b;  
	if (b==1) {num_qizi*=-1;system("CLS");}
	else
	{
		system("CLS");
	strcpy(qizi,"��");
	piece[9][9]=-1;
	strcpy(qipan[9][9],qizi);
	}
	print();
	cout<<"please put your piece  (first row and second line)  "<<endl;
	cout<<"���������,�������������꣬������������";
	num_qizi=1;
	int x1,y1;
	while(cin>>x)
	{
		if (x==0)
		{
			     piece[x1][y1]=0;
				 strcpy(qipan[x1][y1],"��");
				 piece[maxi1][maxj1]=0;
				 strcpy(qipan[maxi1][maxj1],"��");
				 system("CLS");
				 print();
		}
		else if (x==-1) {memset(piece,0,sizeof(piece));system("CLS");welcome();}
		else
		{
		cin>>y;
		x1=x;y1=y;
		if (num_qizi==-1) strcpy(qizi,"��");
		else if (num_qizi==1) strcpy(qizi,"��");
		if (x>19||y>19||x<=0||y<=0) cout<<"out range"<<endl<<"please put your piece   ";
		else
		{
		     if (piece[x][y]!=0) cout<<"You have put at the wrong place"<<endl;
		     else
		         {
					strcpy(qipan[x][y],qizi);
					piece[x][y]=num_qizi;
					num_qizi*=-1;
					if (num_qizi==-1) strcpy(qizi,"��");
		            else if (num_qizi==1) strcpy(qizi,"��");
				    winn=win();
					if (winn==1)
					   {
							 cout<<"congratulations to Player"<<endl;
							 cout<<"Do you want another TRY?(Y/N)"<<endl;
							 char v;
							 cin>>v;
							 if (v=='Y'||v=='y') 
							 {
						       winn=0;
							   memset(piece,0,sizeof(piece));
							   welcome();
							 }
							 else return;
					   }
					int u;
					u=AI();
					if (u==1) return;
		            num_qizi*=-1;
			 }	
		}
	}
					 cout<<endl<<">>>>>>>>>>input '0' to regeret";
					 cout<<endl<<">>>>>>>>>>���� 0 ����"<<endl;
					 cout<<endl<<">>>>>>>>>>input '-1' to go back to the welcome windows";
					 cout<<endl<<">>>>>>>>>>���� -1 �ص���ӭ����"<<endl;
	                 cout<<endl<<"please put your piece  (first row and second line)  "<<endl;
	                 cout<<"���������,�������������꣬������������";
	}
}
void playt()
{
	for(int i=1;i<=19;i++)
		for (int j=1;j<=19;j++)
			strcpy(qipan[i][j],"��");
	system("CLS");
	num_qizi=-1; 
	int x1,y1,t;
	print();
	if (num_qizi==-1) t=1;else t=2;
	cout<<"[PLAYER "<<t<<" ]    please put your piece   "; 
	cout<<endl<<"���"<<t<<"������";
	while(cin>>x)
	{
		if (x==0) 
		{
			num_qizi*=-1;
			piece[x1][y1]=0;
			strcpy(qipan[x1][y1],"��");system("CLS");
			print();
		}
		else if (x==-1) {memset(piece,0,sizeof(piece));system("pause");welcome();}
		else{
		cin>>y;
		if (num_qizi==-1) strcpy(qizi,"��");
		else if (num_qizi==1) strcpy(qizi,"��");
		if (x>19||y>19||x<=0||y<=0) cout<<"out range"<<endl<<"please put your piece   ";
		else
		{
		     if (piece[x][y]!=0) cout<<"You have put at the wrong place"<<endl;
		     else
		         {
					strcpy(qipan[x][y],qizi);
					piece[x][y]=num_qizi;
					x1=x;y1=y;
					system("CLS");
					print();
				    winn=win();
					if (winn==-1)
					   {
							 cout<<"congratulations to Player1"<<endl;
							 cout<<"Do you want another TRY?(Y/N)"<<endl;
							 char v;
							 cin>>v;
							 if (v=='Y') 
							 {
						       winn=0;
							   memset(piece,0,sizeof(piece));
							   playt();
							 }
							 else return;
					   }
					if (winn==1)
					   {
						cout<<"congratulations to Player2"<<endl;
						cout<<"Do you want another TRY?(Y/N)"<<endl;
						char v;
						cin>>v;
						if (v=='Y') 
						{
							winn=0;
							memset(piece,0,sizeof(piece));
							playt();
						}
						else return;
					   }
		            num_qizi*=-1;

			     }	            
			 	if (num_qizi==-1) t=1;else t=2;
			 cout<<endl<<">>>>>>>>>>input '0' to regeret";
			 cout<<endl<<">>>>>>>>>>���� 0 ����"<<endl;
			 cout<<endl<<">>>>>>>>>>input '-1' to go back to the welcome windows";
			 cout<<endl<<">>>>>>>>>>���� -1 �ص���ӭ����"<<endl;
			 cout<<endl<<"[PLAYER "<<t<<" ]    please put your piece   ";
			 cout<<endl<<"���"<<t<<"������";
		}}
	}
}
void print()
{     
	  cout<<endl;
	  cout<<"     ";cout<<"  ";cout<<0<<" ";
      for (int i=1;i<20;i++)
	  {
         if (i<10) cout<<i<<"   ";
		 else cout<<i<<"  ";
	  }
	  cout<<endl;
	  cout<<"     ";cout<<0<<" "<<"��";
	  for (int i=2;i<=19;i++)
      cout<<"�Щ�";cout<<"��";
	  cout<<"��"<<endl;
	  for (int i=1;i<=18;i++)
	  { 
		  if (i<10) cout<<"     "<<i<<" ";
		  else cout<<"     "<<i;
		  cout<<"��";
		  for (int j=1;j<=19;j++)
		  {	  if (j==19) cout<<qipan[i][j];else cout<<qipan[i][j]<<"��";}	
		  cout<<"��"<<endl;			  cout<<"       ";	 
		  cout<<"��";
		  for (int j=1;j<=18;j++) cout<<"��  ";cout<<"����"; cout<<endl;
	  } int i=19;
	  cout<<"     "<<i<<"��";
		  for (int j=1;j<=19;j++)
		  {	  if (j==19) cout<<qipan[i][j];else cout<<qipan[i][j]<<"��";}	
	  cout<<"��"<<endl;		
	  cout<<"       "<<"��";
	  for (int i=2;i<=19;i++)
              cout<<"�ة�";cout<<"��";
	  cout<<"��"<<endl;
}
int win()
{
	int winner=0;
	int sum=0;
	int i=0,j=0;
    //�������ŵ�����
    for (i=0;x-i-1>0&&piece[x-i-1][y]==piece[x][y];i++);
	sum+=i;
	for (j=0;x+1+j<20&&piece[x+j+1][y]==piece[x][y];j++);
	sum+=j;
	if (abs(sum)==4) 
	{
		winner=piece[x][y];
		return winner;
	}
	//���Һ��ŵ�����;
	i=0;j=0;sum=0;
	for (i=0;y+1+i<20&&piece[x][y+i+1]==piece[x][y];i++);
	sum+=i;
	for (j=0;y-1-j>0&&piece[x][y-1-j]==piece[x][y];j++);
    sum+=j;
	if (abs(sum)==4) 
	{
		winner=piece[x][y];
		return winner;
	}
	//������б������;
	i=0;j=0;sum=0;
	for (i=0;x-1-i>0&&y-1-i>0&&piece[x-1-i][y-i-1]==piece[x][y];i++);
	sum+=i;
	for (j=0;x+j+1<20&&y+j+1<20&&piece[x+1+j][y+1+j]==piece[x][y];j++);
	sum+=j;
	if (abs(sum)==4) 
	{
		winner=piece[x][y];
		return winner;
	}
	//������б������;
	i=0;j=0;sum=0;
	for (i=0;x-1-i>0&&y+i+1<20&&piece[x-i-1][y+i+1]==piece[x][y];i++);
	sum+=i;
	for (j=0;x+1+j<20&&y-j-1>0&&piece[x+j+1][y-j-1]==piece[x][y];j++);
	sum+=j;
	if (abs(sum)==4) 
	{
		winner=piece[x][y];
		return winner;
	}
	return 0;
}
bool AI()
{
	 int max=0,maxi,maxj;
	 check51();
     check3();
	 check4();
	 check_double3();
	 check1();
	 check21();
	 check31();
	 check41();
	 
	 for (int i=1;i<=19;i++)
		 for (int j=1;j<=19;j++)
			 if (value[i][j]>max)  
			 {
				 max=value[i][j];
				 maxi=i;
				 maxj=j;
			 }
	 strcpy(qipan[maxi][maxj],qizi);
	 piece[maxi][maxj]=num_qizi;
	 maxi1=maxi;maxj1=maxj;
	 system("CLS");
	 print();
	int sum=0;
	int i=0,j=0;
    //�������ŵ�����
    for (i=0;maxi-i-1>0&&piece[maxi-i-1][maxj]==piece[maxi][maxj];i++);
	sum+=i;
	for (j=0;maxi+1+j<20&&piece[maxi+j+1][maxj]==piece[maxi][maxj];j++);
	sum+=j;
	if (sum==4) 
	{
		cout<<"What a shame! You have lost"<<endl;
		system("pause");
		system("CLS");
		draw();
	    cout<<endl<<"Do you want another TRY?(Y/N)"<<endl;
		cout<<"����������һ����(Y/N)"<<endl;
		 char v;
		 cin>>v;
		 if (v=='Y'||v=='y') 
		 {
	       winn=0;
		   memset(piece,0,sizeof(piece));
		   welcome();
		 }
		 else return 1;
	} 
	//���Һ��ŵ�����;
	i=0;j=0;sum=0;
	for (i=0;maxj+1+i<20&&piece[maxi][maxj+i+1]==piece[maxi][maxj];i++);
	sum+=i;
	for (j=0;maxj-1-j>0&&piece[maxi][maxj-1-j]==piece[maxi][maxj];j++);
    sum+=j;
	if (sum==4) 
	{
		cout<<"What a shame! You have lost"<<endl;
		system("pause");
		system("CLS");
		draw();
	    cout<<endl<<"Do you want another TRY?(Y/N)"<<endl;
		cout<<"����������һ����(Y/N)"<<endl;
		 char v;
		 cin>>v;
		 if (v=='Y'||v=='y') 
		 {
	       winn=0;
		   memset(piece,0,sizeof(piece));
		   welcome();
		 }
		 else return 1;
	} 
	//������б������;
	i=0;j=0;sum=0;
	for (i=0;maxi-1-i>0&&maxj-1-i>0&&piece[maxi-1-i][maxj-i-1]==piece[maxi][maxj];i++);
	sum+=i;
	for (j=0;maxi+j+1<20&&maxj+j+1<20&&piece[maxi+1+j][maxj+1+j]==piece[maxi][maxj];j++);
	sum+=j;
	if (sum==4) 
	{
		cout<<"What a shame! You have lost"<<endl;
		system("pause");
		system("CLS");
		draw();
	    cout<<endl<<"Do you want another TRY?(Y/N)"<<endl;
		cout<<"����������һ����(Y/N)"<<endl;
		 char v;
		 cin>>v;
		 if (v=='Y'||v=='y') 
		 {
	       winn=0;
		   memset(piece,0,sizeof(piece));
		   welcome();
		 }
		 else return 1;
	} 
    //������б������;
	i=0;j=0;sum=0;
	for (i=0;maxi-1-i>0&&maxj+i+1<20&&piece[maxi-i-1][maxj+i+1]==piece[maxi][maxj];i++);
	sum+=i;
	for (j=0;maxi+1+j<20&&maxj-j-1>0&&piece[maxi+j+1][maxj-j-1]==piece[maxi][maxj];j++);
	sum+=j;
	if (sum==4) 
	{
		cout<<"What a shame! You have lost"<<endl;
		system("pause");
		system("CLS");
		draw();
	    cout<<endl<<"Do you want another TRY?(Y/N)"<<endl;
		cout<<"����������һ����(Y/N)"<<endl;
		 char v;
		 cin>>v;
		 if (v=='Y'||v=='y') 
		 {
	       winn=0;
		   memset(piece,0,sizeof(piece));
		   welcome();
		 }
		 else return 1;
	} 
     memset(value,0,sizeof(value));
     cout<<endl<<"The computer has inserted just now at ============>>    "<<maxi<<"    "<<maxj<<endl;
	       cout<<"                        ���Ըղ�������============>>    "<<maxi<<"    "<<maxj<<endl;      
	 return 0;
}
int main()
{	
	welcome();
	system("pause");
}
void draw()
{
	cout<<"*       * ********* *       *    *   *       * *********      *         ********* ********* *********"<<endl;
	cout<<" *     *  *       * *       *    *   *       * *              *         *       * *             *    "<<endl;
	cout<<"  *   *   *       * *       *   *    *       * *              *         *       * *             *    "<<endl;
	cout<<"   * *    *       * *       *        *       * *              *         *       * *             *    "<<endl;
	cout<<"    *     *       * *       *        *       * *********      *         *       * *********     *    "<<endl;
	cout<<"    *     *       * *       *         *     *  *              *         *       *         *     *    "<<endl;
	cout<<"    *     *       * *       *          *   *   *              *         *       *         *     *    "<<endl;
	cout<<"    *     *       * *       *           * *    *              *         *       *         *     *    "<<endl;
	cout<<"    *     ********* *********            *     *********      ********* ********* *********     *    "<<endl;
}
void welcome()
{
	cout<<"                ********************************************************************"<<endl;
	cout<<"                *                                                                  *"<<endl;
	cout<<"                *     *       * ****** *       ****** ******   *     *   ******    *"<<endl;
	cout<<"                *     *   *   * *      *       *      *    *  * *   * *  *         *"<<endl;   
	cout<<"                *     *   *   * ****** *       *      *    * *   * *   * ******    *"<<endl;
	cout<<"                *      * * * *  *      *       *      *    * *    *    * *         *"<<endl;
    cout<<"                *       *   *   ****** ******  ****** ****** *    *    * ******    *"<<endl;
    cout<<"                *                                                                  *"<<endl;
	cout<<"                ********************************************************************"<<endl;
	cout<<endl<<endl<<endl<<"                             THE FIVE PIECE WORLD "<<endl;
	cout<<"                                                ----- written by 00948103 Li Jiarui"<<endl;
	cout<<endl<<endl<<endl<<endl;
	cout<<"                              Ϊ�˸��ѵĿ��ӻ�Ч�����뽫���Ĵ��ڵ������"<<endl<<endl<<endl;
	cout<<setw(50)<<"1.�˻���ս"<<endl;
	cout<<setw(50)<<"2.���˶�ս"<<endl;
	char z;
	cin>>z;
	if (z=='1'||z=='1') plays();
	else if (z=='2'||z=='2') playt();
}

