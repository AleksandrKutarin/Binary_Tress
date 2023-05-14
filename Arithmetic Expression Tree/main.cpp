#include "ArithmeticTreeHead.h"

int main() {
    setlocale(0, "rus");
    ArthmeticTree tree;
    string postfix = "95173*+-+";

    string infix = postfixToInfix(postfix);
    cout << "Инфиксное выражение: " << infix << endl;

    tree.creating_tree(postfix);

    cout << "Результат выражения: " << tree.calculation() << endl;

    return 0;
}