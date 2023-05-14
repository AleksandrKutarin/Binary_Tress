#include "ArithmeticTreeHead.h"

int main() {
    setlocale(0, "rus");
    ArthmeticTree tree;
    string infix = "((9+5)*2-(7+3))";
    string postfix = infixToPostfix(infix);

    cout << "Постфиксное выражение: " << postfix << endl;
    cout << "Инфиксное выражение: " << infix << endl;

    tree.creating_tree(postfix);

    cout << "Результат выражения: " << tree.calculation() << endl;

    return 0;
}