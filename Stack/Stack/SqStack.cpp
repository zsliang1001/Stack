#include "SqStack.h"

bool InitStack(Int_SqStack& S) {
	S.top = -1;
	return true;
}
//���س�ʼ��
bool InitStack(Chr_SqStack& S) {
	S.top = -1;
	return true;
}

bool EmptyStack(Int_SqStack S) {
	if (-1 == S.top)
		return true;
	else
		return false;
}
//�����п�
bool EmptyStack(Chr_SqStack S) {
	if (-1 == S.top)
		return true;
	else
		return false;
}

bool PushStack(Int_SqStack& S, int Data) {
	if (MaxSize - 1 == S.top)
		return false;
	S.data[++S.top] = Data;
	return true;
}
//������ջ(char������)
bool PushStack(Chr_SqStack& S, char Data) {
	if (MaxSize - 1 == S.top)
		return false;
	S.chr[++S.top] = Data;
	return true;
}
//������ջ(char������ �����ȼ�)
bool PushStack(Chr_SqStack& S, char Data, Priority Level) {
	if (MaxSize - 1 == S.top)
		return false;
	S.chr[++S.top] = Data;
	S.level[S.top] = Level;
	return true;
}

bool PopStack(Int_SqStack& S, int& Data) {
	if (EmptyStack(S))
		return false;
	Data = S.data[S.top--];
	return true;
}
//���س�ջ(char������)
bool PopStack(Chr_SqStack& S, char& Data) {
	if (EmptyStack(S))
		return false;
	Data = S.chr[S.top--];
	return true;
}

bool GetTopStack(Int_SqStack S, int& Data) {
	if (EmptyStack(S))
		return false;
	Data = S.data[S.top];
	return true;
}
//���س�ջ(char������)
bool GetTopStack(Chr_SqStack S, char& Data) {
	if (EmptyStack(S))
		return false;
	Data = S.chr[S.top];
	return true;
}