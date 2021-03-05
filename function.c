#include <stdio.h>
#include "function.h"
void gaussrand(double m,double n)//box muller构建服从高斯分布的随机变量  m为平均值，n为标准差
 {
    int i;
   // G[i]=(double*)malloc(sizeof(double)*N);
    double a,b;
    for (i=-1;i<L;i++)
    {
        a=rand()/(RAND_MAX+1.0);
        b=rand()/(RAND_MAX+1.0);
        if(i==-1)
        continue;
        G2[i]=(sqrt((-2)*log(a))*cos(2*PI*b)*n+m);
        G2[i]=sqrt(0.2)*sin(PI*h/G2[i])*G[i];
    }
 }

void readfile()//读取白噪声数据，t从0开始间隔1e-11
{
    FILE*fp=fopen("noise.txt","r");
    int i;
    if(fp==NULL)
    {
       printf("NULL");
        exit(0);
    }
     for(i=0;i<2*N;i++)
    {
        fscanf(fp,"%lf",&G[i]);
    }
   fclose(fp);
}
double xi(double t)//t时刻噪声项数值
{
    int n=t/(h/2);//对应第n个数据
	return G2[n]; //
}

double V(double x)//定义v(x)
{
	double m;
	int k;
	k=(int)x/3;
	if(x>0.0)
		m=x-3.0*k;
	else
		m=3+(x-3*k);
	if(m<=2.00000)
	return 1.0000;
	else
	return -2.0000;
}
double f1(double t,double v,double x)
{
	double z;//xi（t）为噪声项
	z=-0.1*v-V(x)+xi(t);
	return z;
}

