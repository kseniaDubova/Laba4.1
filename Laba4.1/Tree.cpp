#include <iostream>
#include "Tree.hpp"
using namespace std;

Tree:: Tree()
{
    root = NULL;
}
void Tree:: recursion_destructor(Node* obj)
{
    if(!obj) return;
    if(obj->_left)
        recursion_destructor(obj->_left);
    if(obj->_right)
        recursion_destructor(obj->_right);
    delete obj;
}
Tree::~Tree()
{
    recursion_destructor(root);
}
void Tree:: recursion_copy(const Node* obj)
{
    recursion_destructor(root);
    if(obj->_left)
        recursion_copy(obj->_left);
    if(obj->_right)
        recursion_copy(obj->_right);
    insert(obj->_data);
    
}
Tree::Tree(const Tree& obj)
{
    recursion_copy(obj.root);
}
void Tree:: recursion_print(const Node* obj)
{
    if(obj)
    {
        cout << obj->_data;
        recursion_print(obj->_left);
        recursion_print(obj->_right);
    }
}
void Tree:: print()
{
    if(!root) throw ("Tree is empty\n");
    recursion_print(root);
}
bool Tree:: insert(int key)//вставка элемента
{
    if(!root)
    {
        root = new Node(key);
        return true;
    }
    Node* tmp = root;
    while(tmp)
    {
        if (tmp ->_data==key)
            return true;
        if (tmp->_data < key)
        {
            if (tmp->_right)
                tmp = tmp->_right;
            else
            {
                tmp->_right = new Node(key);
                return true;
            }
        }
        else
        {
            if (tmp->_left)
                tmp = tmp->_left;
            else
            {
                tmp->_left = new Node(key);
                return true;
            }

        }
    }
    return false;
}
//bool Tree:: contains(int key)//проверка наличия элемента
//{}
//bool Tree:: erase(int key)//удаление элемента
//{}
//Tree& Tree:: operator=(const Tree& obj)
//{}
