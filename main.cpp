#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "function.h"
//double *G;
//double *G=(double*)malloc(sizeof(double)*N);
//double *G2=(double*)malloc(sizeof(double)*N);//G[L]为高斯噪声，G2是相关系数为detT的噪声
double *x,*v,*t;
double G[L],G2[L];
int main()
{
    double v1,v2,v3,v4,x1,x2,x3,x4;
	int i,j,k;
	double mean=0,sub=0;

	x=(double*)malloc(sizeof(double)*N);
	v=(double*)malloc(sizeof(double)*N);
	t=(double*)malloc(sizeof(double)*N);
	if(x==NULL|v==NULL|t==NULL)
        printf("NULL");
    readfile();
    FILE *fp1=fopen("result.txt","w");
	if(fp1==NULL)
    {
       printf("NULL");
        exit(0);
    }
    double detT=DETT;
    for(j=0;j<times;j++)//计算times次detT
    {
        gaussrand(detT,1.0);//产生均值为detT的高斯噪声
        sub=0;
        t[0]=0;//设定每次解方程的初始时间为0
        for(k=0;k<500000000/N;k++)
        {
                 for(i=0;i<N;i++)
            {
                t[i+1]=t[i]+h;
                v1=f1(t[i],v[i],x[i]);
                x1=v[i];
                v2=f1(t[i]+h/2,v[i]+h/2*v1,x[i]+x1*h/2);
                x2=v[i]+h/2*v1;
                v3=f1(t[i]+h/2,v[i]+h/2*v2,x[i]+x2*h/2);
                x3=v[i]+h/2*v2;
                v4=f1(t[i]+h,v[i]+v3*h,x[i]+h*x3);
                x4=v[i]+h*v3;
                v[i+1]=v[i]+h/6*(v1+2*v2+2*v3+v4);
                x[i+1]=x[i]+h/6*(x1+2*x2+2*x3+x4);
                sub+=v[i+1];
            }
            v[0]=v[N-1];
            x[0]=x[N-1];
            //printf("I am runing/n");
        }
        mean=sub/N;
        fprintf(fp1,"%.3f %f\n",detT,mean);
        printf("%.3f %f\n",detT,mean);
        detT+=DETT;
    }
	fclose(fp1);
	free(x);free(v);free(t);
	return 0;
}
