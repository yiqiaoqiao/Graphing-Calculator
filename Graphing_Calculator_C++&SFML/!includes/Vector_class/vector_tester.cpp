#include "vector_tester.h"

void big_three_tester()
{
    cout << "================Big Three Tester========================" << endl;
    cout << "----------Declaring v1--------" << endl;
    Vector<int> v1;
    v1 += 1;
    v1 += 2;
    cout << "v1: " << v1 << endl;

    cout << endl << "----------Copy CTOR v2--------" << endl;
    Vector<int> v2(v1);
    cout << "v2: " << v2 << endl;

    cout << endl << "--------Assignment operator v3-----" << endl;
    Vector<int> v3 = v1;
    cout << "v3: " << v3 << endl;

    cout << "===============End of Big Three Tester================== \n";

}

void member_access_tester()
{
    cout << "================ Member Access Tester =====================" << endl;
    Vector<char> v1(3);
    v1 += 'a';
    v1 += 'b';
    v1 += 'c';
    cout << "v1: " << v1 << endl;

    cout << endl << "------- assigning second element to g ------ " << endl;
    v1[1] = 'g';
    cout << "v1: " << v1 << endl;

    cout << endl << "------- assigning third element to f --------" << endl;
    v1.at(2) = 'f';
    cout << "v1: " << v1 << endl;

    cout << endl << "The first element of the array: " << v1[0] << endl;
    cout << "The third element of the array: " << v1.at(2) << endl;

    cout << endl << "-----Changing position 0 element to h------" << endl;
    v1.front() = 'h';
    cout << "Item at position 0 is: " << v1.front() << endl;

    cout << "-------Changing last position element to p" << endl;
    v1.back() = 'p';
    cout << "Item at last position is: " << v1.back() << endl;

    cout << "v1: " << v1 << endl;
    cout << "============= End of Member Access Tester ==================" << endl;

}

void push_pop_tester()
{
    cout << "=================== Push Pop Tester ======================" << endl;
    Vector<double> v1(4);
    cout << "--------- Testing += operator ---------" << endl;
    v1 += 0.13;
    v1 += 0.45;
    cout << "v1: " << v1 << endl;

    cout << endl << "-------- Testing push back ---------- " << endl;
    v1.push_back(0.55);
    v1.push_back(1.06);
    cout << "v1: " << v1 << endl;

    cout << endl << "--------- Testing pop back ----------- " << endl;
    v1.pop_back();
    v1.pop_back();
    cout << "v1: " << v1 << endl;

    cout << "================ End of Push Pop Tester ==================" << endl;

}

void insert_erase_tester()
{
    cout << "==================== Insert Erase Tester ====================== " << endl;
    Vector<string> v1;
    v1 += "My";
    v1 += "name";
    v1 += "is";
    v1 += "May";
    cout << "v1: " << v1 << endl;

    cout << endl << "-------- Testing insert --------" << endl;
    v1.insert(1, "first");
    cout << "v1: " << v1 << endl;

    cout << endl << "-------- Testing erase ----------" << endl;
    v1.erase(3);
    cout << "v1: " << v1 << endl;

    cout << endl << "-------- Testing index of ---------" << endl;
    cout << "Index of the word 'My' is " << v1.index_of("My") << endl;

    cout << "=============== End of Insert Erase Tester ================" << endl;

}
void size_capacity_tester()
{
    cout << "=================== Size Capacity Tester ===================== " << endl;
    Vector<string> v1(6);
    v1 += "Hi";
    v1 += "GoodBye";
    cout << v1 << endl;

    cout << endl << "---------- Testing Size ----------" << endl;
    cout << "v1 size = " << v1.size() << endl;
    v1.set_size(10, "Nice");
    cout << "v1 size now = " << v1.size() << endl;
    cout << "v1: " << v1 << endl;

    cout << endl << "---------- Testing Capacity ---------" << endl;
    cout << "v1 capacity = " << v1.capacity() << endl;
    v1.set_capacity(15);
    cout << "v1 capacity now = " << v1.capacity() << endl;

    cout << "================ End of Size Capacity Tester ===================" << endl;

}
