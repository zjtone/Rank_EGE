//ð��
#include<iostream>
#include<graphics.h>
using namespace std;
//x1��ʾ��ʼʱ����ʼ���꣬x2��ʾ����Ŀ�ȣ�x3��ʾ�������Ҽ����y1��ʾ���ȵı�����y2��ʾ�����·�����
//x1=20,x2=40,x3=20,y1=10,y2=150;
template<typename T>
int popo(T a[],int n,double x1,double x2,double x3,double y1,double y2)
{
	//i,j,k��Ϊ����λ�ÿ��Ƶı���
	//x��y������ʾ����ľ���λ��ƽ��
	int i,j,k;
	T temp;
	double x,y;
	setfillcolor(LIGHTBLUE);
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
		{

			if(a[j]<a[j+1])
			{
				x=j;y=j+1;
				//������ٶԻ����������ֵ
				for(;is_run();delay_fps(60))
				{
					cleardevice();
					setfillcolor(GREEN);
					if(x<=j+1)bar(x1+x*(x2+x3),a[j]*y1,(x1+x2)+x*(x2+x3),y2);
					else bar(x1+x*(x2+x3),a[j]*y1,(x1+x2)+x*(x2+x3),y2);
					if(y>=j)bar(x1+y*(x2+x3),a[j+1]*y1,(x1+x2)+y*(x2+x3),y2);
					else bar(x1+y*(x2+x3),a[j+1]*y1,(x1+x2)+y*(x2+x3),y2);
					//��ͨ���ı�x��y�Ӽ���ֵ�Ĵ�С�����ƶ������ٶ�
					x+=0.1;
					y-=0.1;

					setfillcolor(LIGHTBLUE);
					for(k=0;k<j;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
					for(k=j+2;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
					if(x>j+1&&y<j)break;
				}
				temp=a[j];a[j]=a[j+1];a[j+1]=temp;
			}
			//������Ҫ�Ƚϵ����ı���ɫ���ȴ�һ�����ظ�����״̬
			else 
			{
				for(;is_run();delay_fps(60))
				{
					cleardevice();
					setfillcolor(GREEN);
					bar(x1+j*(x2+x3),a[j]*y1,(x1+x2)+j*(x2+x3),y2);
					bar(x1+(j+1)*(x2+x3),a[j+1]*y1,(x1+x2)+(j+1)*(x2+x3),y2);
					setfillcolor(LIGHTBLUE);
					for(k=0;k<j;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
					for(k=j+2;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
					delay_ms(100);
					cleardevice();
					setfillcolor(LIGHTBLUE);
					for(k=0;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
					break;
				}
			}
		}
		cleardevice();
		setfillcolor(LIGHTBLUE);
		for(k=0;k<n;k++)bar(x1+k*(x2+x3),a[k]*y1,(x1+x2)+k*(x2+x3),y2);
		return 0;
}