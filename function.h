#ifndef __FUNCTION_H_
#define __FUNCTION_H_

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define h 0.002//龙格库塔法运算步长，单位ps
#define N 10000 //提取N组高斯噪声，用于构建服从高斯分布的随机变量
#define PI 3.1415926
#define times 1000/DETT//times次循环
#define L 2*N//L组噪声数据
#define DETT 1 //单位ps

extern double G[L],G2[L];
void gaussrand(double m,double n);
void readfile();
double xi(double t);
double V(double x);//定义v(x)
double f1(double t,double v,double x);

#endif
