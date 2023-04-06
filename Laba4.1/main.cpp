#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
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


size_t lcg()
{
    static size_t x = 0;
    x = (1021*x+24631) % 116640;
    return x;
}


int muny()
{
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - add an element"<< endl;
    cout << "2 - checking an element"<< endl;
    cout << "3 - delete an element"<< endl;
    cout << "4 - print"<< endl;
    cout << "5 - exercise"<< endl;
    cout << "6 - exercise with time"<< endl;
    cout << "7 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 7 || n <= 0)
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


vector<int> delete_dublicate(vector<int>& data)
{
    vector<int> result;
    bool flag = false;
    for (auto it = data.begin(); it != data.end(); it++)
    {
        for (auto iter = it + 1; iter != data.end(); iter++)
        {
            if (*it == *iter)
            {
                data.erase(iter--);
                flag = true;
            }
        }
        if (!flag)
        {
            result.push_back(*it);
        }
        flag = false;
    }
    return result;
}


void exercise(Tree& obj)
{
    int number;
    bool flag = true;
    vector<int> a;
    cout << "Vector value input:" << endl;
    while (flag)
    {
        cout << "element = ";
        if (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Incorrect value" << endl;
        }
        else
        {
            a.push_back(number);
        }
        cout << "Continue entering data?" << endl;
        cout << "1 - yes" << endl;
        cout << "2 - no" << endl;
        cout << "Operation №";
        int n = check();
        while (n > 2 || n <= 0)
        {
            cout << "Incorrect value" << endl << "Operation №";
            n = check();
        }
        if (n == 1)
            flag = true;
        else
            flag = false;
    }
    vector<int> tmp;
    tmp = delete_dublicate(a);
    for (auto it = tmp.begin(); it != tmp.end(); ++it)
    {
        cout << *it;
    }
    getchar();
}


void create_v(int size)
{
    clock_t start, end;
    double mean_time = 0;
    for (int i = 0; i < 100; i += 1)
    {
        vector<int> tmp;
        start = clock();
        for (int j = 0; j < size; j++)
            tmp.push_back(int(lcg()));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Time of create vector with " << size << " elements: " << mean_time << endl;
    getchar();
}


void create_time(int size)
{
    clock_t start, end;
    double mean_time = 0;
    for (int i = 0; i < 100; i += 1)
    {
        Tree tmp;
        start = clock();
        for (int j = 0; j < size; j++)
            tmp.insert(int(lcg()));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Time of create tree with " << size << " elements: " << mean_time << endl;
    create_v(size);
    getchar();
}


void search_v(int size)
{
    clock_t start, end;
    vector<int> obj;
    double mean_time = 0;

    for (int j = 0; j < size; j++)
            obj.push_back(int(lcg()));
    
    for (int i = 0; i < 1000; i ++)
    {
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) == obj.end())
            key = int(lcg());
        start = clock();
        find(obj.begin(), obj.end(), key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Time of search element in vector with " << size << " elements: " << mean_time << endl;
    getchar();
}


void search_time(int size)
{
    clock_t start, end;
    Tree obj;
    double mean_time = 0;
    
    for (int j = 0; j < size; j++)
            obj.insert(int(lcg()));
    
    for (int i = 0; i < 1000; i ++)
    {
        int key = int(lcg());
        while (obj.contains(key) == false) key = int(lcg());
        start = clock();
        obj.contains(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Time of search element in tree with " << size << " elements: " << mean_time << endl;
    search_v(size);
    getchar();
}


void add_and_delete_v(int size)
{
    clock_t start, end;
    double mean_time = 0;
    
    
    for (int i = 0; i < 100; i ++)
    {
        vector<int> obj;
        for (int j = 0; j < size; j++)
            obj.push_back(int(lcg()));
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) != obj.end())
            key = int(lcg());
        start = clock();
        obj.push_back(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Time of insert element in vector with " << size << " elements: " << mean_time << endl;
    mean_time = 0;
    for (int i = 0; i < 100; i ++)
    {
        vector<int> obj;
        for (int j = 0; j < size; j++)
            obj.push_back(int(lcg()));
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) == obj.end())
            key = int(lcg());
        start = clock();
        obj.erase(find(obj.begin(), obj.end(), key));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Time of erase element in vector with " << size << " elements: " << mean_time << endl;
    getchar();
}


void add_and_delete_time(int size)
{
    clock_t start, end;
    double mean_time = 0;
    
    
    for (int i = 0; i < 1000; i ++)
    {
        Tree obj;
        for (int j = 0; j < size; j++)
            obj.insert(int(lcg()));
        int key = int(lcg());
        while (obj.contains(key) == true) key = int(lcg());
        start = clock();
        obj.insert(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Time of insert element in tree with " << size << " elements: " << mean_time << endl;
    mean_time = 0;
    for (int i = 0; i < 1000; i ++)
    {
        Tree obj;
        for (int j = 0; j < size; j++)
            obj.insert(int(lcg()));
        int key = int(lcg());
        while (obj.contains(key) == false) key = int(lcg());
        start = clock();
        obj.erase(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Time of erase element in tree with " << size << " elements: " << mean_time << endl;
    add_and_delete_v(size);
    getchar();
}

void muny_time(Tree& obj)
{
    cout << "What time to calculate? To press.." << endl;
    cout << "1 - create tree"<< endl;
    cout << "2 - checking an element"<< endl;
    cout << "3 - delete or add"<< endl;
    cout << "4 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 4 || n <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        n = check();
    }
    
    cout << "What about size of tree? To press.." << endl;
    cout << "1 - 1000"<< endl;
    cout << "2 - 10000"<< endl;
    cout << "3 - 100000"<< endl;
    cout << "Operation №";
    int size = check();
    while (size > 3 || size <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        size = check();
    }
    clear_monitor();
    switch (size) {
        case 1:
            size = 1000;
            break;
        case 2:
            size = 10000;
            break;
        case 3:
            size = 100000;
            break;
        default:
            break;
    }
    void (*operatoin[3])(int size) = {create_time, search_time, add_and_delete_time};
//    n = 100000;
//    create_time(n);
//    search_time(n);
//    add_and_delete_time(n);
    operatoin[n - 1](size);
}


int main()
{
    void (*operatoin[6])(Tree& obj) = {add, check_node, delete_node, print_tree, exercise, muny_time};
    Tree obj;
    int n = muny();
    getchar();
    while (n < 7)
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
/*
Время tree:
 создание:
    Time of create tree with 1000 elements: 0.00020311
    Time of create tree with 5000 elements: 0.00082857
    Time of create tree with 10000 elements: 0.00157689
    Time of create tree with 50000 elements: 0.0086182
    Time of create tree with 100000 elements: 0.0188188
 поиск:
    Time of search element in tree with 1000 elements: 2.72E-07
    Time of search element in tree with 5000 elements: 2.31E-07
    Time of search element in tree with 10000 elements: 2.30E-07
    Time of search element in tree with 50000 elements: 2.60E-07
    Time of search element in tree with 100000 elements: 2.53E-07
 удаление:
    Time of erase element in tree with 1000 elements: 7.05e-07
    Time of erase element in tree with 5000 elements: 7.83E-07
    Time of erase element in tree with 10000 elements: 9.57e-07
    Time of erase element in tree with 50000 elements: 1.08E-06
    Time of erase element in tree with 100000 elements: 1.554e-06
 добавление:
    Time of insert element in tree with 1000 elements: 3.87e-06
    Time of insert element in tree with 5000 elements: 4.06E-07
    Time of insert element in tree with 10000 elements: 8.10E-07
    Time of insert element in tree with 50000 elements: 2.01E-06
    Time of insert element in tree with 100000 elements: 7.08E-06

 Время vector:
  создание:
    Time of create vector with 1000 elements: 5.595e-05
    Time of create vector with 5000 elements: 0.00015439
    Time of create vector with 10000 elements: 0.00030383
    Time of create vector with 50000 elements: 0.00143139
    Time of create vector with 100000 elements: 0.00285573
  поиск:
    Time of search element in vector with 1000 elements: 2.614e-06
    Time of search element in vector with 5000 elements: 2.591e-06
    Time of search element in vector with 10000 elements: 2.567e-06
    Time of search element in vector with 50000 elements: 2.729e-06
    Time of search element in vector with 100000 elements: 2.742e-06
  удаление:
    Time of erase element in vector with 1000 elements: 4.6e-06
    Time of erase element in vector with 5000 elements: 1.023e-05
    Time of erase element in vector with 10000 elements: 1.49e-05
    Time of erase element in tree with 50000 elements: 1.076e-06
    Time of erase element in vector with 100000 elements: 9.03e-05
  добавление:
    Time of insert element in vector with 1000 elements: 2e-07
    Time of insert element in vector with 5000 elements: 2.7e-07
    Time of insert element in vector with 10000 elements: 2.5e-07
    Time of insert element in vector with 50000 elements: 4.9e-07
    Time of insert element in vector with 100000 elements: 8.1e-07
 
 
*/
