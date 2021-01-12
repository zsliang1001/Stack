#include <iostream>
#include <string>
#include "SqStack.h"

using namespace std;

int main(	) {
	int Postfix_Len;
	int Postfix_Value;
	
	char Postfix_Chr[] = { "15 7 1 1+-/3*2 1 1++-" };

	Postfix_Len = strlen(Postfix_Chr);

	Postfix_Value = Postfix_Expression(Postfix_Chr, Postfix_Len);

	cout << Postfix_Value << endl;
	
	return 0;
}