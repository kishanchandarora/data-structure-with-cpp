//============================================================================
// Name        : postfix_evalution.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int isOperand(char input) {
	if(input>=65 && input<=90 || input>=97 && input<=122 || input>=48 && input<=57)
		return 1;
	return 0;
}

int calculate(int op1, int op2, char opr)
{
	switch(opr)
	{
	case '+': return ( op1 + op2 );
	case '-': return ( op1 - op2 );
	case '*': return ( op1 * op2 );
	case '/': return ( op1 / op2 );
	case '%': return ( op1 % op2 );
	}
}

int postfixEvaluation(char *post)
{
	int i;
	int result;
	stack<char> s;


	//start scanning postfix string from left to right
	for( i = 0 ; post[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand push it into the stack
		if( isOperand(post[i]))
		{
			s.push(post[i]-'0');
		}
		else//if the cur ele is an operator
		{
			//pop two ele's from the stack
			//first popped ele will be the second operand
			int op2 = s.top(); s.pop();
			//second popped ele will be the first operand
			int op1 = s.top(); s.pop();
			result = calculate(op1, op2, post[i]);
			//push result into the stack
			s.push(result);
		}
	}//end of for loop
	//pop the the final result from the stack
	result = s.top(); s.pop();
	return result;//return the final result to the calling function
}

int main() {
	char input[] = "231*+9-";

	cout<<postfixEvaluation(input)<<endl;;
	return 0;
}
