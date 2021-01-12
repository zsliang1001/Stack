#include <iostream>
#include <string>
#include "SqStack.h"

using namespace std;

int main(	) {
	int Postfix_Len,Infix_Len;
	int Postfix_Value,Infix_Value;
	
	char Postfix_Chr[]	=	{ "15 7 1 1+-/3*2 1 1++-" };
	char Infix_Chr[]	=	{ "((15/(7-(1+1)))*3)-(2+(1+1))" };

	Postfix_Len = strlen(Postfix_Chr);
	Infix_Len	= strlen(Infix_Chr);

	Postfix_Value	= Postfix_Expression(Postfix_Chr, Postfix_Len);
	Infix_Value = Infix_Expression(Infix_Chr, Infix_Len);

	cout << Postfix_Value << endl;
	cout << Infix_Value << endl;
	
	return 0;
}