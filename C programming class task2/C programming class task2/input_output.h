#pragma once
#ifndef	INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

void output(int* g, int* f, int* s, double* ave, double* sd, int* p_fin, int n);
void input_stu_data(struct Student* students);
void histogram(int* n);

// ����һ����ʾѧ����Ϣ�Ľṹ������
struct Student 
{
	int id; // ѧ��
	int general_proformance; // ƽʱ�ɼ�
	int final_proforamnce; // ��ĩ�ɼ�
	double score; // �ɼ�
} ;


#endif // !INPUT_H

