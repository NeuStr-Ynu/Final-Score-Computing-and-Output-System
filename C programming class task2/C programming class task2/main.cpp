#include<stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include"must_math.h"


int main()
{
	/*�������*/
	int n=5;//������(�����=5�Ǻ�����һ�����ݵ�һ�����)
	int gen_n=40, fin_n=60;//ƽʱ�ɼ�ռ�Ⱥ���ĩ�ɼ�ռ��
	int stu_general[5] = { 0 }, stu_final[5] = { 0 }, stu_sore[5] = { 0 };//�����ɼ��ε�����
	double ave[3] = { 0 }, sd[3] = { 0 };//ÿһ���
	printf_s("������������\n");//����ȫ������
	scanf_s("%d", &n);
	struct Student* students = (struct Student*)calloc(n, sizeof(struct Student));
	if (students == NULL)
	{
		printf_s("�ڴ����ʧ��\n");
		return 1;
	}
	

	/*����*/

	//����
	system("cls");
	printf_s("������ƽʱ�ɼ�����ĩ�ɼ�ռ��(����ٷֺ�ǰ������ּ���)\n");
	scanf_s("%d %d", &gen_n, &fin_n);

	for (int i = 0; i < n; i++)
	{
		printf_s("�������%dλѧ���������Ϣ\n", i+1);
		input_stu_data(students + i);

		(students + i)->score = final_score((students + i)->general_proformance, gen_n, (students + i)->final_proforamnce, fin_n);
	}

	//����������һ������һ��
	/**(students + 0) = { {114},{80},{90},{} };
	*(students + 1) = { {115},{88},{92},{} };
	*(students + 2) = { {116},{99},{40},{} };
	*(students + 3) = { {117},{80},{82},{} };
	*(students + 4) = { {118},{80},{50},{} };
	for (int i = 0; i < n; i++)
	{
		(students + i)->score = final_score((students + i)->general_proformance, gen_n, (students + i)->final_proforamnce, fin_n);
	}*/


	/*����*/

	//����ָ��ṹStudents�������ɼ����ݵ�ָ��
	int* p_fin = (int*)calloc(n, sizeof(int));
	int* p_gen = (int*)calloc(n, sizeof(int));
	double* p_sco = (double*)calloc(n, sizeof(double));
	if (p_sco == NULL || p_fin == NULL || p_gen == NULL)
	{
		printf_s("�ڴ����ʧ��\n");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		*(p_fin + i) = (students + i)->final_proforamnce;
		*(p_gen + i) = (students + i)->general_proformance;
		*(p_sco + i) = (students + i)->score;
	}

	//��������õ�
	/*for (int i = 0; i < n; i++)
	{
		printf("%d %d %d %lf\n", (students + i)->id, (students + i)->general_proformance, (students + i)->final_proforamnce, (students + i)->score);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %d %lf\n", *(p_fin + i), *(p_gen + i), *(p_sco + i));
	}*/

	//�������ݵļ���
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


	/*���*/

	//���������б�����
	output(stu_general, stu_final, stu_sore, ave, sd, p_fin, n);

	//����ֱ��ͼ
	printf_s("ƽʱ�ɼ���\n");
	histogram(stu_general);
	printf_s("��ĩ�ɼ���\n");
	histogram(stu_final);
	printf_s("�����ɼ���\n");
	histogram(stu_sore);


	/*��������*/
	
	free(students);
	return 0;
}
