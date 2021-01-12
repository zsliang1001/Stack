#pragma once

typedef enum {
	Add			=0,
	Sub			=1,
	Mul			=2,
	Div			=3,
	Idle_Cal	=4
}Cal_Type;

typedef enum {
	Low			=0,		//�Ӽ�
	Mid			=1,		//�˳�
	High		=2,		//����
	Idle_Prio	=3
}Priority;

bool Bracket_Check(char data[], int length);
int Postfix_Expression(char Express[], int length);
int Infix_Expression(char Express[], int Length);
