#include <iostream>
#include <string.h>
#include "AVL.h"
using namespace std;

int main(){

    {
        cout<<"Showing inserting without any rotation"<<endl;
        Dictionary<int,int> d1;
        d1.insert(40,40);
        d1.insert(50,50);
        d1.insert(20,20);
        d1.insert(60,60);
        d1.insert(70,70);
        d1.insert(30,30);
        d1.insert(10,10);
        d1.print();
    }

    // cout<<"INSERTION WITH ROTATION ON ROOT:"<<endl<<endl;

    // {
    //     cout<<"Showing rotation on root when balance factor on root = 2"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("hello",40);
    //     d1.insert("book",20);
    //     d1.insert("a",10);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on root when balance factor on root = 2 and left child of root has right child"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(20,20);
    //     d1.insert(30,30);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on root when balance factor on root = -2"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("abc",40);
    //     d1.insert("bcd",50);
    //     d1.insert("you",70);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on root when balance factor on root = -2 and right child of root has left child"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(70,70);
    //     d1.insert(50,50);
    //     d1.print();
    // }

    // cout<<"INSERTION WITH ROTATION:"<<endl<<endl;

    // {
    //     cout<<"Showing rotation on left child of root when balance factor is = 2"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("e",40);
    //     d1.insert("f",50);
    //     d1.insert("c",20);
    //     d1.insert("b",10);
    //     d1.insert("a",5);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on left child of root when balance factor is = -2"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(20,20);
    //     d1.insert(25,25);
    //     d1.insert(30,30);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on right child of root when balance factor is = 2"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(20,20);
    //     d1.insert(45,45);
    //     d1.insert(42,42);
    //     d1.print();
    // }
    // {
    //     cout<<"Showing rotation on right child of root when balance factor is = -2"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("easy",32);
    //     d1.insert("fast",05);
    //     d1.insert("backpack",24);
    //     d1.insert("g",543);
    //     d1.insert("hello world",321);
    //     d1.print();
    // }

    // cout<<"REMOVING:"<<endl<<endl;

    // {
    //     cout<<"Removing root only"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("hello",40);
    //     d1.print();
    //     d1.remove("hello");
    //     d1.print();
    // }
    // {
    //     cout<<"Removing leaf with no child"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.print();
    //     d1.remove(50);
    //     d1.print();
    // }
    // {
    //     cout<<"Removing root with one child"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.print();
    //     d1.remove(40);
    //     d1.print();
    // }
    // {
    //     cout<<"Removing leaf with one child"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("def",321);
    //     d1.insert("yxz",43);
    //     d1.insert("ace",76);
    //     d1.insert("bb",9);
    //     d1.print();
    //     d1.remove("ace");
    //     d1.print();
    // }
    // {
    //     cout<<"Removing root with two children"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(30,30);
    //     d1.print();
    //     d1.remove(40);
    //     d1.print();
    // }
    // {
    //     cout<<"Removing leaf with two children"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(30,30);
    //     d1.insert(10,10);
    //     d1.insert(35,35);
    //     d1.print();
    //     d1.remove(30);
    //     d1.print();
    // }
    // {
    //     cout<<"Removing all nodes"<<endl;
    //     Dictionary<string,int> d1;
    //     d1.insert("def",321);
    //     d1.insert("yxz",43);
    //     d1.insert("ace",76);
    //     d1.insert("bb",9);
    //     d1.insert("djklas",4893);
    //     d1.print();
    //     d1.removeAll();
    //     d1.print();
    // }
    // {
    //     cout<<endl<<"Copy constructor"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(30,30);
    //     d1.insert(60,60);
    //     d1.insert(35,35);
    //     cout<<"tree d1"<<endl;
    //     d1.print();
    //     Dictionary<int,int> d2(d1);
    //     cout<<"tree d2"<<endl;
    //     d2.print();
    // }
    // {
    //     cout<<endl<<"Asignment operator"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(30,30);
    //     d1.insert(60,60);
    //     d1.insert(35,35);
    //     cout<<"tree d1"<<endl;
    //     d1.print();
    //     Dictionary<int,int> d2;
    //     d2.insert(60,60);
    //     d2.insert(35,35);
    //     cout<<"tree d2 before asignment operator"<<endl;
    //     d2.print();
    //     cout<<"tree d2 after asignment operator"<<endl;
    //     d2 = d1;
    //     d2.print();
    // }
    // {
    //     cout<<endl<<"Height of a tree"<<endl;
    //     Dictionary<int,int> d1;
    //     cout<<"Height of empty tree: "<<d1.height()<<endl;
    //     d1.insert(40,40);
    //     d1.insert(50,50);
    //     d1.insert(30,30);
    //     d1.insert(60,60);
    //     d1.insert(35,35);
    //     d1.print();
    //     cout<<"Height of nonempty tree: "<<d1.height()<<endl;
    // }    
    // {
    //     cout<<endl<<"Search function"<<endl;
    //     Dictionary<string,int> d1;
    //     cout<<"Searching in empty tree: "<<d1.search("abc")<<endl;
    //     d1.insert("def",321);
    //     d1.insert("yxz",43);
    //     d1.insert("ace",76);
    //     d1.insert("bb",9);
    //     d1.insert("hello",123);
    //     d1.print();
    //     cout<<"Search failed (key = abc): "<<d1.search("abc")<<endl;
    //     cout<<"Search successful (key = hello): "<<d1.search("hello")<<endl;
    // }
    // {
    //     cout<<endl<<"Inserting element that is already in a tree"<<endl;
    //     Dictionary<int,int> d1;
    //     d1.insert(40,40);
    //     d1.print();
    //     cout<<"Insertion failed (element with such key is already in a tree): "<<d1.insert(40,40)<<endl;
    // }
    // {
    //     cout<<endl<<"Removing from an empty tree or when element is not found"<<endl;
    //     Dictionary<int,int> d1;
    //     cout<<"Removing from empty tree: "<<d1.remove(40)<<endl;
    //     d1.print();
    //     d1.insert(40,40);
    //     cout<<"Removing when given element is not in the tree: ";
    //     d1.remove(1);
    //     cout<<endl;
    // }
    // cout<<"EXTERNAL FUNCTION read_file"<<endl<<endl;
    // {
    //     Dictionary<string,int> dct;
    //     read_file("test1.txt", dct);
    //     dct.print();
    //     dct.insert("abc", 4);
    //     cout<<"Searching for key = good "<<dct.search("good")<<endl<<endl;
    //     dct.remove("morning");
    //     dct.print();
    //     dct.print();
    //     dct.removeAll();
    //     dct.print();
    // }


    // Dictionary<int, int> d1;
    //     d1.insert(33,33);
    //     d1.insert(13,13);
    //     d1.insert(53,53);
    //     d1.insert(60,60);
    //     d1.insert(21,21);
    //     d1.insert(9,9);
    //     d1.insert(25,25);
    //     d1.insert(11,11);
    //     d1.insert(8,8);
    //     d1.insert(15,15);
    //     d1.insert(25,25);
    //     d1.print();
    //     d1.remove(13);
    //     d1.print();

        // Dictionary<int, int> d1;
        // d1.insert(13,13);
        // d1.insert(9,9);
        // d1.insert(60,60);
        // d1.insert(11,11);
        // d1.insert(8,8);
        // d1.insert(53,53);
        // d1.insert(70,70);
        // // d1.insert(80,80);
        // d1.insert(21,21);
        // d1.insert(25,25);
        // // d1.insert(25,25);
        // d1.print();
        // d1.remove(13);
        // d1.print();

        // Dictionary<int, int> d1;
        // d1.insert(4,4);
        // d1.insert(5,5);
        // d1.insert(2,2);
        // d1.insert(6,6);
        // d1.insert(7,7);
        // d1.insert(3,3);
        // d1.insert(1,1);
        // d1.print();
        // d1.remove(6);
        // d1.print();
        // d1.remove(5);
        // d1.print();
        // d1.remove(1);
        // d1.print();
        // d1.remove(4);
        // d1.print();

    // Dictionary<string, int> d1;
    // d1.insert("u", 30);
    // d1.insert("f", 20);
    // d1.insert("v", 80);
    // d1.insert("y", 10);
    // d1.insert("c", 50);
    // d1.insert("l", 90);
    // d1.insert("h", 40);
    // d1.insert("o", 60);
    // d1.print();
    // d1.insert("g", 35);
    // d1.print();




}