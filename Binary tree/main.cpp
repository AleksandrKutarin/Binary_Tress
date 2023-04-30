#include"binary_tree_head.h"

int main() {

    BinaryTree tree;

    tree.insert(7);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(9);
    tree.insert(8);

    cout << "In-order: ";
    tree.print_in_order(tree.root);
    cout << endl;

    tree.remove(6);
    cout << "After remove : ";
    tree.print_in_order(tree.root);
    cout << endl;

    return 0;

}