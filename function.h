#ifndef __FUNCTION_H_
#define __FUNCTION_H_

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define h 0.002//������������㲽������λps
#define N 10000 //��ȡN���˹���������ڹ������Ӹ�˹�ֲ����������
#define PI 3.1415926
#define times 1000/DETT//times��ѭ��
#define L 2*N//L����������
#define DETT 1 //��λps

extern double G[L],G2[L];
void gaussrand(double m,double n);
void readfile();
double xi(double t);
double V(double x);//����v(x)
double f1(double t,double v,double x);

#endif
