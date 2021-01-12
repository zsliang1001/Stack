#include "SqStack.h"

Priority Check_Priority(char ch) {
	Priority level = Idle_Prio;
	if ('(' == ch || ')' == ch)	level = High;
	if ('*' == ch || '/' == ch)	level = Mid;
	if ('+' == ch || '-' == ch)	level = Low;
	return level;
}

Cal_Type Calculate_Type(char ch) {
	Cal_Type type = Idle_Cal;
	if ('+' == ch)	type = Add;
	if ('-' == ch)	type = Sub;
	if ('*' == ch)	type = Mul;
	if ('/' == ch)	type = Div;
	return type;
}

bool Calculate(Int_SqStack& S, Cal_Type Type) {
	int value, num_pre, num_rear;
	switch (Type)
	{
	case Add:
		PopStack(S, num_rear);
		PopStack(S, num_pre);
		value = num_pre + num_rear;
		PushStack(S, value);
		break;
	case Sub:
		PopStack(S, num_rear);
		PopStack(S, num_pre);
		value = num_pre - num_rear;
		PushStack(S, value);
		break;
	case Mul:
		PopStack(S, num_rear);
		PopStack(S, num_pre);
		value = num_pre * num_rear;
		PushStack(S, value);
		break;
	case Div:
		PopStack(S, num_rear);
		PopStack(S, num_pre);
		value = num_pre / num_rear;
		PushStack(S, value);
		break;
	default:
		return false;
		break;
	}
	return true;
}

bool Bracket_Check(char data[], int length) {
	char ch;
	Chr_SqStack S;
	InitStack(S);

	for (int i = 0; i < length; i++) {
		if ('(' == data[i] || '[' == data[i] || '{' == data[i])
			PushStack(S, data[i]);
		if (')' == data[i] || ']' == data[i] || '}' == data[i]) {
			if (EmptyStack(S))return false;
			PopStack(S, ch);
			if ('(' == ch && ')' != data[i])return false;
			if ('[' == ch && ']' != data[i])return false;
			if ('{' == ch && '}' != data[i])return false;
		}
	}
	return EmptyStack(S);
}

int Postfix_Expression(char Express[], int Length) {
	int value;
	int k, n;				//k用于记录每个数据是几位数,n用于将将data中的数据转化为整数
	int data[6] = { 0 };

	Cal_Type type = Idle_Cal;

	Int_SqStack S;
	InitStack(S);

	for (int i = 0; i < Length; i++) {
		if (' ' == Express[i])continue;
		if (Express[i] >= '0' && Express[i] <= '9') {
			k = 0;
			for (int j = i; Express[j] >= '0' && Express[j] <= '9'; j++)
				data[k++] = Express[j]-'0';
			value = 0;
			for(n = 0; n < k; n++)
				value = value * 10 + data[n];
			PushStack(S, value);
			i = i + k - 1;
		}
		else {
			if (S.top <= 0)return false;
			type = Calculate_Type(Express[i]);
			if(!Calculate(S, type))return false;
		}
	}

	PopStack(S, value);
	if (!EmptyStack(S))return false;
	
	return value;
}

int Infix_Expression(char Express[], int Length) {
	int value;
	int k, n;				//k用于记录每个数据是几位数,n用于将将data中的数据转化为整数
	int data[6] = { 0 };
	char oper;

	Cal_Type	type =	Idle_Cal;
	Priority	level = Idle_Prio;

	Int_SqStack S_Data;
	Chr_SqStack S_Chr;
	InitStack(S_Data);
	InitStack(S_Chr);
	
	for (int i = 0; i < Length; i++) {
		if (Express[i] >= '0' && Express[i] <= '9') {
			k = 0;
			for (int j = i; Express[j] >= '0' && Express[j] <= '9'; j++)
				data[k++] = Express[j] - '0';
			value = 0;
			for (n = 0; n < k; n++)
				value = value * 10 + data[n];
			PushStack(S_Data, value);
			i = i + k - 1;
		}
		else {
			level = Check_Priority(Express[i]);
			if (Idle_Prio == level)continue;
			if (')' == Express[i]) {
				while ('(' != S_Chr.chr[S_Chr.top]) {
					PopStack(S_Chr, oper);
					type = Calculate_Type(oper);
					if (!Calculate(S_Data, type))return false;
				}
				S_Chr.top--;	//将‘（’踢出去

			}
			else {
				if (EmptyStack(S_Chr))
					PushStack(S_Chr, Express[i],level);
				else {
					if (level > S_Chr.level[S_Chr.top] || '(' == S_Chr.chr[S_Chr.top])
						PushStack(S_Chr, Express[i], level);
					else {
						type = Calculate_Type(S_Chr.chr[S_Chr.top]);
						if (!Calculate(S_Data, type))return false;
						S_Chr.top--;
						PushStack(S_Chr, Express[i], level);
					}
				}
			}

		}
	}

	while (!EmptyStack(S_Chr)) {
		PopStack(S_Chr, oper);
		if (S_Data.top < 1)return false;
		type = Calculate_Type(oper);
		if (!Calculate(S_Data, type))return false;
	}

	PopStack(S_Data, value);
	if (!EmptyStack(S_Data))return false;

	return value;
}