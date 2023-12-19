#pragma once
#ifndef	INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

void output(int* g, int* f, int* s, double* ave, double* sd, int* p_fin, int n);
void input_stu_data(struct Student* students);
void histogram(int* n);

// 定义一个表示学生信息的结构体类型
struct Student 
{
	int id; // 学号
	int general_proformance; // 平时成绩
	int final_proforamnce; // 期末成绩
	double score; // 成绩
} ;


#endif // !INPUT_H

