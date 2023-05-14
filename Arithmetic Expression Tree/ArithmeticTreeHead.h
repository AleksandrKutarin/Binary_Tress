#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
	Node* right;
	Node* left;
	int value;
	Node(int val) {
		right = nullptr;
		left = nullptr;
		value = val;
	}
};

class ArthmeticTree {
public:
	Node* root;

	ArthmeticTree() {
		root = nullptr;
	}
	//строим дерево с помощью постфиксной записи
	void creating_tree(string& postfix) {
		stack<Node*> s;
		for (char& element : postfix)
		{
			if (element >= '0' && element <= '9')
			{
				s.push(new Node(element - '0'));
			}
			else if (element == '+' || element == '-' || element == '*' || element == '/') {
				Node* node = new Node(element);
				if (!s.empty()) {
					node->right = s.top();
					s.pop();
				}
				else
					throw logic_error("stack полон");
				if (!s.empty()) {
				node->left = s.top();
				s.pop();
				}
				else
					throw logic_error("stack полон");
				s.push(node);
			}
		}
		root = s.top();
		s.pop();
	}
	//расчет
	int calculation() {
		return rec_calculation(root);
	}
	int rec_calculation(Node* node) {
		if (!node) {
			return 0;
		}
		if (!node->left && !node->right) {
			return node->value;
		}
		int right_value = rec_calculation(node->right);
		int left_value = rec_calculation(node->left);

		switch (node->value) {
		case '+':
			cout << left_value << " + " << right_value << " = " << left_value + right_value << "\n";
			return left_value + right_value;
		case '-':
			cout << left_value << " - " << right_value << " = " << left_value - right_value << "\n";
			return left_value - right_value;
		case '*':
			cout << left_value << " * " << right_value << " = " << left_value * right_value << "\n";
			return left_value * right_value;
		case '/':
			cout << left_value << " / " << right_value << " = " << left_value / right_value << "\n";
			return left_value / right_value;
		default:
			return 0;
		}
		return 0;
	}
};
string postfixToInfix(string postfix) {
	stack<string> s;
	for (const char& ch : postfix) {
		if (isdigit(ch)) {//Если символ является числом
			s.push(string(1, ch));
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {//Иначе, если символ оператора +, -, * или /
			string operand2 = s.top();
			s.pop();
			string operand1 = s.top();
			s.pop();

			string new_expr = "(" + operand1 + ch + operand2 + ")";
			s.push(new_expr);
		}
	}
	return s.top();
}
string infixToPostfix(string infix) {
	stack<char> s;
	string postfix = "";
	for (const char& ch : infix) {
		if (isdigit(ch)) {//Если символ является числом
			postfix += ch;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {//Иначе, если символ оператора +, -, * или /
			while (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/' || ch == '+' || ch == '-')) {
				postfix += s.top();
				s.pop();
			}
			s.push(ch);
		}
		else if (ch == '(') {
			s.push(ch);
		}
		else if (ch == ')') {
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			if (!s.empty() && s.top() == '(') {
				s.pop();
			}
		}
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}