#include "Tree.hpp"
#include <iostream>
using namespace std;


void clear_monitor()
{
    for (int i=0; i<31; i++)
    {
        cout << endl;
    }
}


int check()
{
    int number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect value" << endl;
    }
    return number;
}


int muny()
{
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - add an element"<< endl;
    cout << "2 - checking an element"<< endl;
    cout << "3 - delete an element"<< endl;
    cout << "4 - print"<< endl;
    cout << "5 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 5 || n <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        n = check();
    }
    clear_monitor();
    return n;
}


void add(Tree& obj)
{
    cout << "Add an element" << endl;
    cout << "Which element?" << endl;
    int node = check();
    obj.insert(node);
}


void check_node(Tree& obj)
{
    cout << "Checking an element" << endl;
    cout << "Which element?" << endl;
    int node = check();
    if (obj.contains(node))
        cout << "The node is exist";
    else
        cout << "The node is not exist";
    getchar();
}


void delete_node(Tree& obj)
{
    cout << "Delete an element" << endl;
    cout << "Which element?" << endl;
    int node = check();
    obj.erase(node);
    getchar();
}


void print_tree(Tree& obj)
{
    obj.print();
    getchar();
}


int main()
{
    void (*operatoin[4])(Tree& obj) = {add, check_node, delete_node, print_tree};
    Tree obj;
    int n = muny();
    getchar();
    while (n < 5)
    {
        try
        {
            operatoin[n - 1](obj);
        } catch (ESetErrors& err)
        {
            err.print_error();
            getchar();
        }
        getchar();
        clear_monitor();
        cout << "What's next?" << endl;
        n = muny();
    }
}
