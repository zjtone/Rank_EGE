#include<iostream>
#include<cstdlib>
#include<ctime>
#include<graphics.h>
#include<string>
#include"popo.h"
#include"choose.h"
#include"head.h"
using namespace std;
int main()
{
	int a[10],b[10],i,x,y;
	mouse_msg msg;
	srand(time(0));
	for(i=0;i<10;i++)
		a[i]=rand()%10+1;
	memcpy(b,a,sizeof(a));
	initgraph(640,480);
	setfillcolor(LIGHTBLUE);
	for(i=0;i<10;i++)
		bar(20+i*60,a[i]*10,60+i*60,150);
	for(;is_run();delay_fps(60))
	{
		setfont(18,0,"宋体");
		outtextxy(250,250,"冒泡排序");
		outtextxy(250,280,"选择排序");
		outtextxy(250,310,"更新");
		outtextxy(250,340,"重置");
		outtextxy(250,370,"退出");
		mousepos(&x,&y);
		while(mousemsg())msg=getmouse();
		if(x>=250&&x<=322&&y>=250&&y<=270&&msg.is_left())popo(a,10,20,40,20,10,150);
		if(x>=250&&x<=322&&y>=280&&y<=300&&msg.is_left())choose(a,10,20,40,20,10,150);
		if(x>=250&&x<=296&&y>=310&&y<=330&&msg.is_left())
		{
			update(a,10,20,40,20,10,150);
			memcpy(b,a,sizeof(a));
			continue;
		}
		if(x>=250&&x<=296&&y>=340&&y<=360&&msg.is_left())
		{
			recycle(a,b,10,20,40,20,10,150);
			continue;
		}
		if(x>=250&&x<=296&&y>=370&&y<=390&&msg.is_left())break;
	}
	closegraph();
	return 0;
}
