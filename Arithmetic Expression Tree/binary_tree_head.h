#pragma once
#include <iostream>
using namespace std;

class Node {
public:
    int value; 
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root; // корень

    BinaryTree() {
        this->root = nullptr;
    }

    void insert(int value) { // метод вставки в дерево
        Node* new_node = new Node(value);
        if (this->root == nullptr) {
            this->root = new_node;
        }
        else {
            Node* current_node = this->root;
            while (true) {
                if (value < current_node->value) {
                    if (current_node->left == nullptr) {
                        current_node->left = new_node;
                        break;
                    }
                    else {
                        current_node = current_node->left;
                    }
                }
                else {
                    if (current_node->right == nullptr) {
                        current_node->right = new_node;
                        break;
                    }
                    else {
                        current_node = current_node->right;
                    }
                }
            }
        }
    }
    void remove(int value) { // метод который принимает указатель на узел и значение которое удаляется
        root = removeNode(root, value);
    }

    Node* removeNode(Node* node, int value) { // метод удаление узла
        if (node == nullptr) {
            return nullptr;
        }
        else if (value < node->value) {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->value) {
            node->right = removeNode(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
        }
        return node;
    }

    Node* search(int value) {
        Node* current_node = this->root;
        while (current_node != nullptr) {
            if (value == current_node->value) {
                return current_node;
            }
            else if (value < current_node->value) {
                current_node = current_node->left;
            }
            else {
                current_node = current_node->right;
            }
        }
        return nullptr;
    }

    void print_in_order(Node* node) {   // метод печати: левый узел - текущий узел - правый узел
        if (node != nullptr) {
            print_in_order(node->left);
            cout << node->value << " ";
            print_in_order(node->right);
        }
    }
    void print_pre_order(Node* node) {  // метод печати: текущий узел - левый узел - правый узел
        if (node != nullptr) {
            cout << node->value << " ";
            print_pre_order(node->left);
            print_pre_order(node->right);
        }
    }

    void print_post_order(Node* node) { // метод печати: левый узел - правый узел - текущий узел
        if (node != nullptr) {
            print_post_order(node->left);
            print_post_order(node->right);
            cout << node->value << " ";
        }
    }
};