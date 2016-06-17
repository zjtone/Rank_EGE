#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
using namespace std;
template<typename T>
int update(T a[],int n,double x1,double x2,double x3,double y1,double y2)
{
	int i;
	for(i=0;i<n;i++)a[i]=rand()%10+1;
	cleardevice();
	setfillcolor(LIGHTBLUE);
	for(i=0;i<n;i++)
		bar(x1+i*(x2+x3),a[i]*y1,x1+x2+i*(x2+x3),y2);
	return 0;
}
//将p数组的值与f数组比较并将f数组的值移到相应位置，以此达到重置的效果
template<typename T>
int recycle(T a[],int b[],int n,double x1,double x2,double x3,double y1,double y2)
{
	int i,j,k;
	double x,y;
	T temp;
	setfillcolor(LIGHTBLUE);
	for(i=0;i<n;i++)
		bar(x1+i*(x2+x3),a[i]*y1,(x2+x3)+i*(x2+x3),y2);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[i]==a[j])
			{
				//以下部分为选择排序的代码直接拷贝，可能存在未知问题
				x=j;y=i;
				temp=a[i];a[i]=a[j];a[j]=temp;
				for(;is_run();delay_fps((x2+x3)))
				{
					cleardevice();
					setfillcolor(GREEN);

					if(x>=i)bar(x1+x*(x2+x3),a[i]*y1,(x2+x3)+x*(x2+x3),y2);
					else bar(x1+j*(x2+x3),a[i]*y1,(x2+x3)+j*(x2+x3),y2);
					if(y<=j)bar(x1+y*(x2+x3),a[j]*y1,(x2+x3)+y*(x2+x3),y2);
					else bar(x1+i*(x2+x3),a[j]*y1,(x2+x3)+i*(x2+x3),y2);
					x=x-0.1;
					y=y+0.1;
					setfillcolor(LIGHTBLUE);
					for(k=0;k<i;k++)
						bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					if(j-i!=1)
						for(k=i+1;k<j;k++)
							bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					for(k=j+1;k<n;k++)
						bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					if(y>j&&x<i)break;
				}
			}
			else 
			{
				for(;is_run();delay_fps((x2+x3)))
				{
					cleardevice();
					setfillcolor(GREEN);
					bar(x1+j*(x2+x3),a[j]*y1,(x2+x3)+j*(x2+x3),y2);
					bar(x1+i*(x2+x3),a[i]*y1,(x2+x3)+i*(x2+x3),y2);
					setfillcolor(LIGHTBLUE);
					for(k=0;k<i;k++)
						bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					if(j-i!=1)
						for(k=i+1;k<j;k++)
							bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					for(k=j+1;k<n;k++)
						bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					delay_ms(200);
					cleardevice();
					for(k=0;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,(x2+x3)+k*(x2+x3),y2);
					break;
				}
			}
		}
	}
	cleardevice();
	setfillcolor(LIGHTBLUE);
	for(i=0;i<n;i++)
		bar(x1+i*(x2+x3),a[i]*y1,(x2+x3)+i*(x2+x3),y2);
	return 0;
}
