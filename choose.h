//ѡ��
#include<iostream>
#include<graphics.h>
using namespace std;
//x1��ʾ��ʼʱ����ʼ���꣬x2��ʾ����Ŀ�ȣ�x3��ʾ�������Ҽ����y1��ʾ���ȵı�����y2��ʾ�����·�����
//x1=20,x2=40,x3=20,y1=10,y2=150;
template <typename T>
int choose(T a[],int n,double x1,double x2,double x3,double y1,double y2)
{
	int i,j,k;
	T temp;
	double x,y;
	setfillcolor(LIGHTBLUE);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				y=i;x=j;
				//��ʵ������������޸�ֵ��ȽϺ�
				temp=a[i];a[i]=a[j];a[j]=temp;
				for(;is_run();delay_fps(60))
				{
					cleardevice();
					setfillcolor(GREEN);
					//����(y!=j)��(x!=i)�˴�����ѭ����ԭ����double�����
					//�޸�Ϊ�Ƚϴ�С�����ٳ���
					if(x>=i)bar(x1+x*(x2+x3),a[i]*y1,x1+x2+x*(x2+x3),y2);
					else bar(x1+j*(x2+x3),a[i]*y1,x1+x2+j*(x2+x3),y2);
					if(y<=j)bar(x1+y*(x2+x3),a[j]*y1,x1+x2+y*(x2+x3),y2);
					else bar(x1+i*(x2+x3),a[j]*y1,x1+x2+i*(x2+x3),y2);
					x=x-0.1;
					y=y+0.1;
					setfillcolor(LIGHTBLUE);
					for(k=0;k<i;k++)
						bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					if(j-i!=1)
						for(k=i+1;k<j;k++)
							bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					for(k=j+1;k<n;k++)
						bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					if(y>j&&x<i)break;
				}
			}
			else 
			{
				for(;is_run();delay_fps(60))
				{
					cleardevice();
					setfillcolor(GREEN);
					bar(x1+j*(x2+x3),a[j]*y1,x1+x2+j*(x2+x3),y2);
					bar(x1+i*(x2+x3),a[i]*y1,x1+x2+i*(x2+x3),y2);
					setfillcolor(LIGHTBLUE);
					for(k=0;k<i;k++)
						bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					if(j-i!=1)
						for(k=i+1;k<j;k++)
							bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					for(k=j+1;k<n;k++)
						bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					delay_ms(200);
					cleardevice();
					for(k=0;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
					break;
				}
			}
		}
	}
	cleardevice();
	setfillcolor(LIGHTBLUE);
	for(k=0;k<n;k++)
		bar(x1+k*(x2+x3),a[k]*y1,x1+x2+k*(x2+x3),y2);
	return 0;
}