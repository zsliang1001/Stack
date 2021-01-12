#pragma once
#include <stdio.h>
#include "Calculate_Expression.h"

#define MaxSize		30


typedef struct {
	int data[MaxSize];
	int top;
}Int_SqStack;

typedef struct {
	char		chr[MaxSize];
	int			top;
	Cal_Type	type[MaxSize];
	Priority	level[MaxSize];
}Chr_SqStack;

bool InitStack(Int_SqStack& S);
bool InitStack(Chr_SqStack& S);//重载初始化

bool EmptyStack(Int_SqStack S);
bool EmptyStack(Chr_SqStack S);//重载判空

bool PushStack(Int_SqStack& S, int Data);
bool PushStack(Chr_SqStack& S, char Data);//重载入栈(char型数据)
bool PushStack(Chr_SqStack& S, char Data, Priority Level);//重载入栈(char型数据 ，优先级)

bool PopStack(Int_SqStack& S, int& Data);
bool PopStack(Chr_SqStack& S, char& Data);//重载出栈(char型数据)

bool GetTopStack(Int_SqStack S, int& Data);
bool GetTopStack(Chr_SqStack S, char& Data);//重载出栈(char型数据)