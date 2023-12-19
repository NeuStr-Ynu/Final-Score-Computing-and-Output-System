#include"must_math.h"
#include<stdio.h>
#include<math.h>


double final_score(int general_porformance, int gen_n, int final_porformance, int fin_n)//���������ɼ�(ռ������%��֮ǰ������)
{
	return general_porformance * gen_n * 0.01 + final_porformance * fin_n * 0.01;
}

double average(int* x,int n)//����ƽ������n��������
{
	int total_av=0;
	for (int i = 0; i < n; i++)
	{
		total_av += *(x + i);
	}
	return total_av / n;
}
double average_d(double* x, int n)//����ƽ����_double�ͣ�n��������
{
	double total_av = 0;
	for (int i = 0; i < n; i++)
	{
		total_av += *(x + i);
	}
	return total_av / n;
}

double standard_deviation(int* x, int n)//��׼�n��������
{
	int total_sd=0;
	for (int i = 0; i < n; i++)
	{
		total_sd += pow(*(x + i) - average(x, n), 2);
	}
	return sqrt(total_sd / n);
}

double standard_deviation_d(double* x, int n)//��׼��_double�ͣ�n��������
{
	double total_sd = 0;
	for (int i = 0; i < n; i++)
	{
		total_sd += pow(*(x + i) - average_d(x, n), 2);
	}
	return sqrt(total_sd / n);
}

int classify(int n)
{
	if (n < 60)return 0;
	else if (n >= 60 && n < 70)return 1;
	else if (n >= 70 && n < 80)return 2;
	else if (n >= 80 && n < 90)return 3;
	else return 4;
}

int find_max(int* x, int n)
{
	int max = *x;
	for (int i = 0; i < n; i++)
	{
		if (*(x + i) > max)max = *(x + i);
	}
	return max;
}

int find_min(int* x, int n)
{
	int min = *x;
	for (int i = 0; i < n; i++)
	{
		if (*(x + i) < min)min = *(x + i);
	}
	return min;
}