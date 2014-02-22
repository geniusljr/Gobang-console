#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
const int h5=9999999,f4=500000,h4=20000,h3=5000,doub3=2500,c4=900,c3=200,f2=50;
          //h5表示自己可以连成五个——必胜
		  //f4表示防守对方已有的连四，必防
		  //h4表示自己可以连出活四——必胜
		  //h3表示防守对方已有的活三
		  //c4表示自己可以连出冲四——对方必防
const int h1=2,c1=1;
char qipan[20][20][4];
char qizi[4];//两种棋子'X'/'O'；
int  piece[20][20]={0};//黑棋为-1,白旗为1，空为0//电脑为黑棋 人为白棋
int x,y;//坐标
int winn=0;//winn表示获得胜利的人1为player1，2为player2;
//char b='●',w='○';
int value[20][20]={0};//每个位置的权
int num_qizi=-1;//用来转换每一次所下的棋子,并且标记每个位置的数值
int maxi,maxj;
int maxi1,maxj1;

void print();//输出函数；
void play();//下棋的游戏函数
void check1();//防守函数
void check3();//防守函数
void check4();//防守函数
void check_double3();//防守函数
void check21();//进攻函数
void check31();//进攻函数
void check41();//进攻函数
void check51();//进攻函数
int win();//判断输赢
bool AI();//电脑下棋的过程
void draw();//画出电脑赢后的界面
void welcome();//画出欢迎界面


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
	//横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
	//横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
	//横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
	//横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
	//横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
void check3()//活三
{
	int sum=0;
	int z=0;
	int i,j;
	//判断***
	  //横着的
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
	//竖着的活三
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
	//左斜活三
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
	//右斜活三
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
	//判断**_*/*_**
			//横着的
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
			//竖着的
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
			//左斜
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
			//右斜
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
    //横着的
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
	//竖着的
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
	//左斜
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
	//右斜
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
	//横着的
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
	 //竖着的
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
		 //左斜
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
   //右斜
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
	 //横着的**_()/_**()/*_*()及反向
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
	 //竖着的
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
		 //左斜
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
		 //右斜
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
			strcpy(qipan[i][j],"┼");
	cout<<"                                    1.First player  （执黑先手）             "<<endl;
	cout<<"                                    2.First computer（执白后手）             "<<endl;
	cin>>b;  
	if (b==1) {num_qizi*=-1;system("CLS");}
	else
	{
		system("CLS");
	strcpy(qizi,"●");
	piece[9][9]=-1;
	strcpy(qipan[9][9],qizi);
	}
	print();
	cout<<"please put your piece  (first row and second line)  "<<endl;
	cout<<"玩家请下棋,请先输入行坐标，再输入列坐标";
	num_qizi=1;
	int x1,y1;
	while(cin>>x)
	{
		if (x==0)
		{
			     piece[x1][y1]=0;
				 strcpy(qipan[x1][y1],"┼");
				 piece[maxi1][maxj1]=0;
				 strcpy(qipan[maxi1][maxj1],"┼");
				 system("CLS");
				 print();
		}
		else if (x==-1) {memset(piece,0,sizeof(piece));system("CLS");welcome();}
		else
		{
		cin>>y;
		x1=x;y1=y;
		if (num_qizi==-1) strcpy(qizi,"●");
		else if (num_qizi==1) strcpy(qizi,"○");
		if (x>19||y>19||x<=0||y<=0) cout<<"out range"<<endl<<"please put your piece   ";
		else
		{
		     if (piece[x][y]!=0) cout<<"You have put at the wrong place"<<endl;
		     else
		         {
					strcpy(qipan[x][y],qizi);
					piece[x][y]=num_qizi;
					num_qizi*=-1;
					if (num_qizi==-1) strcpy(qizi,"●");
		            else if (num_qizi==1) strcpy(qizi,"○");
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
					 cout<<endl<<">>>>>>>>>>输入 0 悔棋"<<endl;
					 cout<<endl<<">>>>>>>>>>input '-1' to go back to the welcome windows";
					 cout<<endl<<">>>>>>>>>>输入 -1 回到欢迎界面"<<endl;
	                 cout<<endl<<"please put your piece  (first row and second line)  "<<endl;
	                 cout<<"玩家请下棋,请先输入行坐标，再输入列坐标";
	}
}
void playt()
{
	for(int i=1;i<=19;i++)
		for (int j=1;j<=19;j++)
			strcpy(qipan[i][j],"┼");
	system("CLS");
	num_qizi=-1; 
	int x1,y1,t;
	print();
	if (num_qizi==-1) t=1;else t=2;
	cout<<"[PLAYER "<<t<<" ]    please put your piece   "; 
	cout<<endl<<"玩家"<<t<<"请下棋";
	while(cin>>x)
	{
		if (x==0) 
		{
			num_qizi*=-1;
			piece[x1][y1]=0;
			strcpy(qipan[x1][y1],"┼");system("CLS");
			print();
		}
		else if (x==-1) {memset(piece,0,sizeof(piece));system("pause");welcome();}
		else{
		cin>>y;
		if (num_qizi==-1) strcpy(qizi,"●");
		else if (num_qizi==1) strcpy(qizi,"○");
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
			 cout<<endl<<">>>>>>>>>>输入 0 悔棋"<<endl;
			 cout<<endl<<">>>>>>>>>>input '-1' to go back to the welcome windows";
			 cout<<endl<<">>>>>>>>>>输入 -1 回到欢迎界面"<<endl;
			 cout<<endl<<"[PLAYER "<<t<<" ]    please put your piece   ";
			 cout<<endl<<"玩家"<<t<<"请下棋";
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
	  cout<<"     ";cout<<0<<" "<<"┌";
	  for (int i=2;i<=19;i++)
      cout<<"┬─";cout<<"┬";
	  cout<<"┐"<<endl;
	  for (int i=1;i<=18;i++)
	  { 
		  if (i<10) cout<<"     "<<i<<" ";
		  else cout<<"     "<<i;
		  cout<<"├";
		  for (int j=1;j<=19;j++)
		  {	  if (j==19) cout<<qipan[i][j];else cout<<qipan[i][j]<<"─";}	
		  cout<<"┤"<<endl;			  cout<<"       ";	 
		  cout<<"│";
		  for (int j=1;j<=18;j++) cout<<"│  ";cout<<"││"; cout<<endl;
	  } int i=19;
	  cout<<"     "<<i<<"├";
		  for (int j=1;j<=19;j++)
		  {	  if (j==19) cout<<qipan[i][j];else cout<<qipan[i][j]<<"─";}	
	  cout<<"┤"<<endl;		
	  cout<<"       "<<"└";
	  for (int i=2;i<=19;i++)
              cout<<"┴─";cout<<"┴";
	  cout<<"┘"<<endl;
}
int win()
{
	int winner=0;
	int sum=0;
	int i=0,j=0;
    //查找竖着的棋子
    for (i=0;x-i-1>0&&piece[x-i-1][y]==piece[x][y];i++);
	sum+=i;
	for (j=0;x+1+j<20&&piece[x+j+1][y]==piece[x][y];j++);
	sum+=j;
	if (abs(sum)==4) 
	{
		winner=piece[x][y];
		return winner;
	}
	//查找横着的棋子;
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
	//查找左斜的棋子;
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
	//查找右斜的棋子;
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
    //查找竖着的棋子
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
		cout<<"您还想再来一盘吗？(Y/N)"<<endl;
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
	//查找横着的棋子;
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
		cout<<"您还想再来一盘吗？(Y/N)"<<endl;
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
	//查找左斜的棋子;
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
		cout<<"您还想再来一盘吗？(Y/N)"<<endl;
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
    //查找右斜的棋子;
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
		cout<<"您还想再来一盘吗？(Y/N)"<<endl;
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
	       cout<<"                        电脑刚才下子在============>>    "<<maxi<<"    "<<maxj<<endl;      
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
	cout<<"                              为了更佳的可视化效果，请将您的窗口调成最大"<<endl<<endl<<endl;
	cout<<setw(50)<<"1.人机对战"<<endl;
	cout<<setw(50)<<"2.人人对战"<<endl;
	char z;
	cin>>z;
	if (z=='1'||z=='1') plays();
	else if (z=='2'||z=='2') playt();
}

