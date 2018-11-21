#include <iostream>
#include <string>
#include "Node.h"
#include "HeadNode.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Calculator.h"

using namespace std;

//Group Members: Hadar Goldstein and Jan To Tong
bool isOperand(char chr);
string InfixToPostfix(string expression);
string reverse(string str);
char calcPostfix(string expression);
int main()
{
	string expression = "3 + 4 -5";
	int tester = 3 + 4 - 5;
	Calculator calculate0 = Calculator(expression);
	string* postfix = calculate0.InfixToPostfix();
	cout << "Exprssion: " << expression << endl;
	//cout << "the testers result is: " << tester << endl;
	cout << "Postfix: "<<postfix<<endl;


system("pause");
return 0;



}
/**********
string InfixToPostfix(string expression) {
	Stack<char> *stackptr;
	stackptr = new Stack<char>();
	Queue<char> *queueptr;
	queueptr = new Queue<char>();
	int size = 0;
	string postfix = "";

	//when we get to 'B' we know we are at the Bottom
	stackptr->push('B');
	int len = expression.length();
	for (int i = 0; i < len; i++) {
		if (expression[i] == ' ')continue;
		size++;
		if (isOperand(expression[i]) == true) {
			while (precedence(stackptr->stackTop()) >= precedence(expression[i]) && stackptr->stackTop() != '(') {
				queueptr->enqueue(stackptr->stackTop());
				stackptr->pop();
			}
			stackptr->push(expression[i]);
		}
		/*	else if (expression[i] == ')') {
		while (stackptr->stackTop() != '(') {
		queueptr->enqueue(stackptr->stackTop());
		stackptr->pop();
		}
		stackptr->pop();
		}*//*
		else {
			queueptr->enqueue(expression[i]);
		}
	}
	while (stackptr->stackTop() != 'B') {
		queueptr->enqueue(stackptr->stackTop());
		stackptr->pop();
	}
	for (int i = 0; i < size; i++) {
		postfix += queueptr->front();
		queueptr->dequeue();
	}
	delete stackptr;
	delete queueptr;

	return postfix;

}
char calcPostfix(string expression) {
	int ans;
	Stack<char> *stackptr;
	stackptr = new Stack<char>();

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ')continue;
		if (isOperand(expression[i]) == true) {
			cout << "operand:" << expression[i] << endl;
			char a = stackptr->stackTop();
			stackptr->pop();
			//if(a < 57 && a > 48) a -= 48;
			cout << "a:" << a << endl;
			char b = stackptr->stackTop();
			stackptr->pop();
			//if (b < 57 && b > 48)b -= 48;
			cout << "b:" << b << endl;
			char val;
			switch (expression[i]) {
			case'+': val = a + b; break;
			case'-': val = b - a; break;
			case'*': val = a*b; break;
			case'/': val = b / a; break;
			case'%':val = b%a; break;
			}
			val -= 48;
			cout << "val:" << val << endl;
			stackptr->push(val);
		}
		else {
			//cout << "operator:" << expression[i];
			stackptr->push(expression[i]);
		}
	}

	return stackptr->stackTop();
}
/*string InfixToPrefix(string expression) {
	string prefix = "";
	string postfix = InfixToPostfix(expression);
	string reversedPostfix = reverse(postfix);
	Stack<char> *stackptr;
	stackptr = new Stack<char>();
	Queue<char> *queueptr;
	queueptr = new Queue<char>();
	int len = expression.length();

	for (int i = 0; i <len; i++){
		if (expression[i] == ' ')continue;
		if (isOperand(expression[i] == false)) {
			stackptr->push(expression[i]);
		}
		else {
			char one = stackptr->stackTop();
			stackptr->pop();
			char two = stackptr->stackTop();
			stackptr->pop();
			queueptr->enqueue(expression[i]);
			queueptr->enqueue(one);
			queueptr->enqueue(two);
		}
	}
	for (int i = 0; i < len-1; i++) {
		prefix += queueptr->front();
		queueptr->dequeue();
	}
	delete stackptr;
	delete queueptr;
	return prefix;
}


bool isOperand(char chr) {
	switch (chr) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return true;
	}
	return false;
}
string reverse(string str) {
	int len = str.length();
	string rev = "";
	for (len; len >= 0; len--)rev += str[len];
	return rev;
} 
************/