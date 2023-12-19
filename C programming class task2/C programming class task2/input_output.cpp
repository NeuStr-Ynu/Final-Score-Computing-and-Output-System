#include"input_output.h"
#include"must_math.h"
#include<stdio.h>
#include <stdlib.h>


void input_stu_data(struct Student* students)
{
	printf_s("请输入学号\n");
	scanf_s("%d", &students->id); 
	system("cls");
	printf_s("请输入平时成绩\n");
	scanf_s("%d", &students->general_proformance);
	system("cls");
	printf_s("请输入期末成绩\n");
	scanf_s("%d", &students->final_proforamnce);
	system("cls");
}

void output(int*g,int*f,int*s,double*ave,double*sd,int*p_fin,int n)
{
	printf_s("\t分类\t项目\t不及格\t60-69\t70-79\t80-89\t90-100\t平均分\t标准差\n");
	printf_s("平时成绩\t人数\t%d\t%d\t%d\t%d\t%d\t%3.1lf\t%4.2lf\n", g[0], g[1], g[2], g[3], g[4], ave[0], sd[0]);
	printf_s("\t\t占比\t%d%%\t%d%%\t%d%%\t%d%%\t%d%%\n", 100 * g[0] / n, 100 * g[1] / n, 100 * g[2] / n, 100 * g[3] / n, 100 * g[4] / n);
	printf_s("期末成绩\t人数\t%d\t%d\t%d\t%d\t%d\t%3.1lf\t%4.2lf\n", f[0], f[1], f[2], f[3], f[4], ave[1], sd[1]);
	printf_s("\t\t占比\t%d%%\t%d%%\t%d%%\t%d%%\t%d%%\n", 100 * f[0] / n, 100 * f[1] / n, 100 * f[2] / n, 100 * f[3] / n, 100 * f[4] / n);
	printf_s("总评成绩\t人数\t%d\t%d\t%d\t%d\t%d\t%3.1lf\t%4.2lf\n", s[0], s[1], s[2], s[3], s[4], ave[2], sd[2]);
	printf_s("\t\t占比\t%d%%\t%d%%\t%d%%\t%d%%\t%d%%\n", 100 * s[0] / n, 100 * s[1] / n, 100 * s[2] / n, 100 * s[3] / n, 100 * s[4] / n);
	printf_s("期末考试卷面及格率：%d%%\t期末考试卷面最高分：%d\t期末考试卷面最低分：%d", 100 - 100 * f[0] / n, find_max(p_fin, n), find_min(p_fin, n));
}

void histogram(int* n)
{
	printf_s("不及格：\t\|");
	for (int i = 0; i < n[0]; i++)
	{
		printf_s("*");
	}
	printf_s("\n");
	printf_s(" 60-69：\t\|");
	for (int i = 0; i < n[1]; i++)
	{
		printf_s("*");
	}
	printf_s("\n");
	printf_s(" 70-79：\t\|");
	for (int i = 0; i < n[2]; i++)
	{
		printf_s("*");
	}
	printf_s("\n");
	printf_s(" 80-89：\t\|");
	for (int i = 0; i < n[3]; i++)
	{
		printf_s("*");
	}
	printf_s("\n");
	printf_s("90-100：\t\|");
	for (int i = 0; i < n[4]; i++)
	{
		printf_s("*");
	}
	printf_s("\n");
}