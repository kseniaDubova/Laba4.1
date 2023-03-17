//
//  Tree.hpp
//  Laba4.1
//
//  Created by Ксения Дубова on 17.03.2023.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
struct Node
{
    int _data;
    Node* _left;
    Node* _right;
    Node(int data = 0, Node* left = NULL, Node* right = NULL)
    {
        _data = data;
        _left = left;
        _right = right;
    }
};

class Tree
{
private:
    Node* root;
public:
    Tree(int data = 0);
    ~Tree();
    Tree(const Tree& obj);
    void print();
    bool insert(int key);//вставка элемента
    bool contains(int key);//проверка наличия элемента
    bool erase(int key);//удаление элемента
    Tree& operator=(const Tree& obj);

};
#endif /* Tree_hpp */
