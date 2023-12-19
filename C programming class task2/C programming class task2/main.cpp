#include<stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include"must_math.h"


int main()
{
	/*定义变量*/
	int n=5;//总人数(后面的=5是和下面一劳永逸的一块儿的)
	int gen_n=40, fin_n=60;//平时成绩占比和期末成绩占比
	int stu_general[5] = { 0 }, stu_final[5] = { 0 }, stu_sore[5] = { 0 };//各个成绩段的人数
	double ave[3] = { 0 }, sd[3] = { 0 };//每一项的
	printf_s("请输入总人数\n");//输入全班人数
	scanf_s("%d", &n);
	struct Student* students = (struct Student*)calloc(n, sizeof(struct Student));
	if (students == NULL)
	{
		printf_s("内存分配失败\n");
		return 1;
	}
	

	/*输入*/

	//输入
	system("cls");
	printf_s("请输入平时成绩与期末成绩占比(输入百分号前面的数字即可)\n");
	scanf_s("%d %d", &gen_n, &fin_n);

	for (int i = 0; i < n; i++)
	{
		printf_s("请输入第%d位学生的相关信息\n", i+1);
		input_stu_data(students + i);

		(students + i)->score = final_score((students + i)->general_proformance, gen_n, (students + i)->final_proforamnce, fin_n);
	}

	//懒得输入了一劳永逸一下
	/**(students + 0) = { {114},{80},{90},{} };
	*(students + 1) = { {115},{88},{92},{} };
	*(students + 2) = { {116},{99},{40},{} };
	*(students + 3) = { {117},{80},{82},{} };
	*(students + 4) = { {118},{80},{50},{} };
	for (int i = 0; i < n; i++)
	{
		(students + i)->score = final_score((students + i)->general_proformance, gen_n, (students + i)->final_proforamnce, fin_n);
	}*/


	/*计算*/

	//定义指向结构Students的两个成绩数据的指针
	int* p_fin = (int*)calloc(n, sizeof(int));
	int* p_gen = (int*)calloc(n, sizeof(int));
	double* p_sco = (double*)calloc(n, sizeof(double));
	if (p_sco == NULL || p_fin == NULL || p_gen == NULL)
	{
		printf_s("内存分配失败\n");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		*(p_fin + i) = (students + i)->final_proforamnce;
		*(p_gen + i) = (students + i)->general_proformance;
		*(p_sco + i) = (students + i)->score;
	}

	//检查问题用的
	/*for (int i = 0; i < n; i++)
	{
		printf("%d %d %d %lf\n", (students + i)->id, (students + i)->general_proformance, (students + i)->final_proforamnce, (students + i)->score);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %d %lf\n", *(p_fin + i), *(p_gen + i), *(p_sco + i));
	}*/

	//进行数据的计算
	for (int i = 0; i < n; i++)
	{
		stu_general[classify((students + i)->general_proformance)]++;
		stu_final[classify((students + i)->final_proforamnce)]++;
		stu_sore[classify((int)(students + i)->score)]++;
	}

	ave[0] = average(p_gen, n);
	ave[1] = average(p_fin, n);
	ave[2] = average_d(p_sco, n);

	sd[0] = standard_deviation(p_gen, n);
	sd[1] = standard_deviation(p_fin, n);
	sd[2] = standard_deviation_d(p_sco, n);

	free(p_fin);
	free(p_gen);
	free(p_sco);


	/*输出*/

	//进行数据列表的输出
	output(stu_general, stu_final, stu_sore, ave, sd, p_fin, n);

	//绘制直方图
	printf_s("平时成绩：\n");
	histogram(stu_general);
	printf_s("期末成绩：\n");
	histogram(stu_final);
	printf_s("总评成绩：\n");
	histogram(stu_sore);


	/*结束程序*/
	
	free(students);
	return 0;
}
