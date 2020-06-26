//============================================================================
// Name        : infix_to_prefix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int isOperator(char input)
{
	switch (input) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 1;
	case '%':
		return 1;
	case '/':
		return 1;
	case '(':
		return 1;
	}
	return 0;
}

int isOperand(char input) {
	if(input>=65 && input<=90 || input>=97 && input<=122 || input >= 48 && input <= 57 )
		return 1;
	return 0;
}
int priority(char input) {
	switch(input) {
	case ')': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 5;
	}
}



//void strrev(char *str)
//{
//	char *left = str;
//	char *right = str;
//
//	while( *right )
//		right++;
//
//	right--;
//
//	while( left <= right )
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//
//		left++;
//		right--;
//	}
//}


void inToPre(char *input, char *pre) {
	stack<char> s;
	int j=0;
	for(int i=strlen(input)-1; i>=0; i--) {
		if(isOperand(input[i]))
			pre[j++] = input[i];
		else {  // it is an operator
			while(!s.empty() && priority(input[i])<priority(s.top())) {
				pre[j++] = s.top();
				s.pop();
			}
			s.push(input[i]);
		}
	}

	while(!s.empty()) {
		pre[j++] = s.top();
		s.pop();
	}

	pre[j] = '\0';

	strrev(pre);
}


int main() {
	//char input[] = "a*b/c*d+e*f-g/h";

	char input[64] = "(a*b)*(c+d)/e*f+g-h";
	// char input[64] = "4*6+3/8*7-6";
	char pre[64] ="";
	inToPre(input, pre);
	cout<<"prefix expression is: "<<pre<<endl;


	return 0;
}

