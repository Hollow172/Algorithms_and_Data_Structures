#include <iostream>
#include <string>
#include "sequence.h"

using namespace std;

int main(){

    cout<<"---------------------------------"<<endl;
    cout<<"----TESTING FOR FLOAT AND INT----"<<endl;
    cout<<"---------------------------------"<<endl<<endl;
    
    Sequence<float, int> list1;
    list1.print(); //Showing that the list is empty
    cout<<list1.isEmpty()<<endl; //Showing that list is empy by using isEmpty() method: 1 means it is empty, 0 means it isn't

    //Adding elements to list and printing out:
    list1.insertEnd(1.5,2);
    list1.insertEnd(2.7,5);
    list1.insertEnd(4.2,2);
    list1.insertEnd(1.5,10);
    list1.insertEnd(4.2,2);
    list1.print();
    cout<<list1.isEmpty()<<endl; //Showing that the list is not empty

    //Showing getKey and getInfo methods
    cout<<list1.getKey(2)<<endl; 
    cout<<list1.getInfo(3)<<endl;

    // //Testing copy constructor and operators:
    // cout<<"Copy constructor (list2)"<<endl;
    // Sequence<float, int> list2(list1);
    // list2.print();
    
    // cout<<"Assignment operator list3 = list2"<<endl;
    // Sequence<float, int> list3;
    // list3 = list2;
    // list3.print();

    // cout<<"Operator+= for list4 after adding elements to that list with list1"<<endl;
    // Sequence<float, int> list4;
    // list4.insertEnd(-15.2, 2);
    // list4.insertEnd(7.6, 8);
    // list4.insertEnd(3.4, 19);
    // list4.insertEnd(87.4, -101);
    // list4.print();
    // list4 += list1;
    // list4.print();

    // cout<<"Operator+ for list3 = list1 + list5 after adding elements to list5"<<endl;
    // Sequence<float, int> list5;
    // list5.insertEnd(25.2, 42);
    // list5.insertEnd(101.16, 53);
    // list5.print();
    // list3 = list1 + list5;
    // list3.print();

    // cout<<"Operator-= for new list6 after adding elements to that list with list4"<<endl;
    // Sequence<float, int> list6;
    // list6.insertEnd(15.2, 2);
    // list6.insertEnd(3.4, 19);
    // list6.insertEnd(10.4, 115);
    // list6.insertEnd(15.2, 2);
    // list6.print();
    // list6 -= list4;
    // list6.print();

    // cout<<"Operator- for list6 = list7 - list5 after adding elements to list7"<<endl;
    // Sequence<float, int> list7;
    // list7.insertEnd(25.2, 42);
    // list7.insertEnd(-21.4, -73);
    // list7.insertEnd(53.1, 91);
    // list7.insertEnd(101.16, 53);
    // list6 = list7 - list5;
    // list6.print();
    

    // cout<<"The rest of the test will be done on the list1"<<endl;
    // list1.insertEnd(24.8, 76);
    // list1.insertEnd(38.19, 45);
    // list1.insertEnd(29.10, 13);
    // list1.insertEnd(30.5, 30);
    // list1.print();

    // cout<<"Tests with removing: "<<endl;
    // cout<<"Removing element with 1.5 key and 2nd occurance: "<<endl;
    // list1.print();
    // list1.remove(1.5,2);
    // list1.print();
    // cout<<"Removing all elements with 4.2 key all occurances: "<<endl;
    // list1.removeAllKeys(4.2);
    // list1.print();
    // cout<<"Removing first element: "<<endl;  
    // list1.removeFirst();
    // list1.print(); 
    // cout<<"Removing last element: "<<endl;   
    // list1.removeLast();
    // list1.print(); 
    // cout<<"Removing given position: "<<endl;   
    // list1.removePosition(3);
    // list1.print(); 
    // cout<<"Removing given element by key and info: "<<endl;    
    // list1.removeKeyAndInfo(24.8, 76);
    // list1.print(); 
    // cout<<"Removing all: "<<endl;
    // list1.removeAll();
    // list1.print();


    // cout<<"Tests with inserting: "<<endl;
    // cout<<"Insert on the end of list: "<<endl;
    // list1.insertEnd(1.5, 1);
    // list1.print();
    // cout<<"Insert on the beginning of list: "<<endl;
    // list1.insertBegin(2.3, 2);
    // list1.print();
    // cout<<"Adding more elements to showcase next insert methods"<<endl;
    // list1.insertBegin(1.5, 1);
    // list1.insertEnd(4.2, 5);
    // list1.insertEnd(5.7, 13);
    // list1.insertEnd(1.5, 1);
    // list1.insertEnd(6.7, 2);
    // list1.print();
    // cout<<"Insert after 2nd occurance of key 1.5: "<<endl;
    // list1.insertAfter(15.3, 1, 1.5, 2);
    // list1.print();
    // cout<<"Insert before 3rd occurance of key 1.5: "<<endl;
    // list1.insertBefore(25.93, 2, 1.5, 3);
    // list1.print();   
    // cout<<"Insert on given position: "<<endl;
    // list1.insertPosition(37.2, 10, 2);
    // list1.print();

    // cout<<"Reverse printing: "<<endl;
    // list1.reversePrint();
    // cout<<endl;

    // cout<<"Searching in a list element with a key 1.5 and 2nd occurance of it: "<<endl;
    // list1.print();
    // list1.search(1.5, 2);
    // cout<<"Searching for all elements with a key 1.5 on the list"<<endl;
    // list1.searchAll(1.5);
    
    // cout<<"Counting elements with 1.5 key in list: ";
    // cout<<list1.count(1.5)<<endl;
    // cout<<"Length of the whole list: ";
    // cout<<list1.length()<<endl<<endl;

    // cout<<"Reversing a list: "<<endl;
    // list1.reverse();
    // list1.print();

    // cout<<"Printing key and info for a given position 1: ";
    // list1.keyandinfo(1);
    // cout<<endl;

    // cout<<"Shuffle function for 2 new lists: "<<endl;
    // Sequence<float, int>shuff1;
    // shuff1.insertEnd(1.5,2);
    // shuff1.insertEnd(2.4,3);
    // shuff1.insertEnd(3.3,4);
    // shuff1.insertEnd(4.9,5);
    // shuff1.insertEnd(6,6);
    // shuff1.insertEnd(7.19,7);
    // cout<<"shuff1:"<<endl;
    // shuff1.print();
    // Sequence<float, int>shuff2;
    // shuff2.insertEnd(-15.4,93);
    // shuff2.insertEnd(7.19,21);
    // shuff2.insertEnd(145.01,17);
    // shuff2.insertEnd(-230.001,15);
    // cout<<"shuff2:"<<endl;
    // shuff2.print();

    // Sequence<float, int>shuff3;
    // shuff3 = shuffle(shuff1, 2, shuff2, 3, 2);
    // shuff3.print();
    // shuff3.removeLast();
    // shuff3.print();


    // cout<<"---------------------------------"<<endl;
    // cout<<"-------TESTING FOR STRINGS-------"<<endl;
    // cout<<"---------------------------------"<<endl<<endl;
    
    // Sequence<string, string> stringList1;
    // stringList1.print(); //Showing that the list is empty
    // cout<<stringList1.isEmpty()<<endl; //Showing that list is empy by using isEmpty() method: 1 means it is empty, 0 means it isn't

    // //Adding elements to list and printing out:
    // stringList1.insertEnd("abc", "def");
    // stringList1.insertEnd("test", "word");
    // stringList1.insertEnd("hello", "world");
    // stringList1.insertEnd("abc", "def");
    // stringList1.insertEnd("test", "big");
    // stringList1.print();
    // cout<<stringList1.isEmpty()<<endl; //Showing that the list is not empty

    // //Showing getKey and getInfo methods
    // cout<<stringList1.getKey(2)<<endl; 
    // cout<<stringList1.getInfo(3)<<endl;

    // //Testing copy constructor and operators:
    // cout<<"Copy constructor (stringList2)"<<endl;
    // Sequence<string, string> stringList2(stringList1);
    // stringList2.print();
    
    // cout<<"Assignment operator stringList3 = stringList2"<<endl;
    // Sequence<string, string> stringList3;
    // stringList3 = stringList2;
    // stringList3.print();

    // cout<<"Operator+= for stringList4 after adding elements to that list with stringList1"<<endl;
    // Sequence<string, string> stringList4;
    // stringList4.insertEnd("hello", "day");
    // stringList4.insertEnd("night", "day");
    // stringList4.insertEnd("abc","def");
    // stringList4.insertEnd("xyz", "giant");
    // stringList4.print();
    // stringList4 += stringList1;
    // stringList4.print();

    // cout<<"Operator+ for stringList3 = stringList1 + stringList5 after adding elements to stringList5"<<endl;
    // Sequence<string, string> stringList5;
    // stringList5.insertEnd("throne", "fish");
    // stringList5.insertEnd("night", "day");
    // stringList5.print();
    // stringList3 = stringList1 + stringList5;
    // stringList3.print();

    // cout<<"Operator-= for new stringList after adding elements to that list with stringList4"<<endl;
    // Sequence<string, string> stringList6;
    // stringList6.insertEnd("throne", "fish");
    // stringList6.insertEnd("night", "day");
    // stringList6.insertEnd("hello", "world");
    // stringList6.insertEnd("abc","def");
    // stringList6.print();
    // stringList6 -= stringList4;
    // stringList6.print();

    // cout<<"Operator- for stringList6 = stringList7 - stringList5 after adding elements to stringList7"<<endl;
    // Sequence<string, string> stringList7;
    // stringList7.insertEnd("abc", "def");
    // stringList7.insertEnd("throne", "fish");
    // stringList7.insertEnd("hello", "world");
    // stringList7.insertEnd("night", "day");
    // stringList7.print();
    // stringList6 = stringList7 - stringList5;
    // stringList6.print();
    

    // cout<<"The rest of the test will be done on the stringList1"<<endl;
    // stringList1.insertEnd("abc", "def");
    // stringList1.insertEnd("chair", "hair");
    // stringList1.insertEnd("test", "word");
    // stringList1.insertEnd("phantom", "sunlight");
    // stringList1.insertEnd("dancer", "valley");
    // stringList1.print();


    // cout<<"Tests with removing: "<<endl;
    // cout<<"Removing element with abc key and 2nd occurance: "<<endl;
    // stringList1.print();
    // stringList1.remove("abc",2);
    // stringList1.print();
    // cout<<"Removing all elements with test key all occurances: "<<endl;
    // stringList1.removeAllKeys("test");
    // stringList1.print();
    // cout<<"Removing first element: "<<endl;   
    // stringList1.removeFirst();
    // stringList1.print(); 
    // cout<<"Removing last element: "<<endl;  
    // stringList1.removeLast();
    // stringList1.print(); 
    // cout<<"Removing given position: "<<endl;   
    // stringList1.removePosition(2);
    // stringList1.print(); 
    // cout<<"Removing given element by key and info: "<<endl;   
    // stringList1.removeKeyAndInfo("chair", "hair");
    // stringList1.print(); 
    // cout<<"Removing all: "<<endl;
    // stringList1.removeAll();
    // stringList1.print();


    // cout<<"Tests with inserting: "<<endl;
    // cout<<"Insert on the end of list: "<<endl;
    // stringList1.insertEnd("hello", "world");
    // stringList1.print();
    // cout<<"Insert on the beginning of list: "<<endl;
    // stringList1.insertBegin("abc", "def");
    // stringList1.print();
    // cout<<"Adding more elements to showcase next insert methods"<<endl;
    // stringList1.insertEnd("sign", "recover");
    // stringList1.insertEnd("abc", "def");
    // stringList1.insertEnd("hello", "world");
    // stringList1.insertEnd("never", "summon");
    // stringList1.insertEnd("abc", "def");
    // stringList1.print();
    // cout<<"Insert after 2nd occurance of key abc: "<<endl;
    // stringList1.insertAfter("fire", "water", "abc", 2);
    // stringList1.print();
    // cout<<"Insert before 3rd occurance of key abc: "<<endl;
    // stringList1.insertBefore("feel", "warrior", "abc", 3);
    // stringList1.print();   
    // cout<<"Insert on given position: "<<endl;
    // stringList1.insertPosition("xyz", "kekw", 2);
    // stringList1.print();


    // cout<<"Reverse printing: "<<endl;
    // stringList1.reversePrint();
    // cout<<endl;

    // cout<<"Searching in a list element with a key abc and 2nd occurance of it: "<<endl;
    // stringList1.print();
    // stringList1.search("abc", 2);
    // cout<<"Searching for all elements with a key abc on the list"<<endl;
    // stringList1.searchAll("abc");
    
    // cout<<"Counting elements with abc key in list: ";
    // cout<<stringList1.count("abc")<<endl;
    // cout<<"Length of the whole list: ";
    // cout<<stringList1.length()<<endl<<endl;

    // cout<<"Reversing a list: "<<endl;
    // stringList1.reverse();
    // stringList1.print();

    // cout<<"Printing key and info for a given position 1: ";
    // stringList1.keyandinfo(1);
    // cout<<endl;
    

    // cout<<"Shuffle function for 2 new lists: "<<endl;
    // Sequence<string, string>strShuff1;
    // strShuff1.insertEnd("abc", "def");
    // strShuff1.insertEnd("str", "string");
    // strShuff1.insertEnd("hello", "world");
    // strShuff1.insertEnd("xyz", "kekw");
    // strShuff1.insertEnd("boom", "buy");
    // strShuff1.insertEnd("thanks", "chair");
    // cout<<"strShuff1:"<<endl;
    // strShuff1.print();
    // Sequence<string, string>strShuff2;
    // strShuff2.insertEnd("hello", "hi");
    // strShuff2.insertEnd("brb", "bop");
    // strShuff2.insertEnd("thanks", "notchair");
    // strShuff2.insertEnd("def", "kekw");
    // cout<<"strShuff2:"<<endl;
    // strShuff2.print();

    // Sequence<string, string>strShuff3;
    // strShuff3 = shuffle(strShuff1, 2, strShuff2, 3, 2);
    // strShuff3.print();
    // strShuff3.insertBefore("cat", "dog", "thanks", 1);
    // strShuff3.print();

    // cout<<"----------------------------------"<<endl;
    // cout<<"---------BORDERLINE CASES---------"<<endl;
    // cout<<"----------------------------------"<<endl<<endl;

    // Sequence<int, int> inting;
    // Sequence<int, int> emptylist;
    // inting.insertEnd(1,1);
    // inting.insertEnd(1,1);
    // inting.print();
    // cout<<"getKey - should return 0 since given parameter is less than 1: "<<inting.getKey(-2)<<endl;
    // cout<<"getKey - should return 0 since given parameter is bigger than the length of the list: "<<inting.getKey(3)<<endl;
    // cout<<"getInfo - should return 0 since given parameter is less than 1: "<<inting.getInfo(-2)<<endl;
    // cout<<"getInfo - should return 0 since given parameter is bigger than the length of the list: "<<inting.getInfo(3)<<endl;
    // cout<<"removeAll - should return 1 since the list is empty: "<<emptylist.removeAll()<<endl;
    // cout<<"remove - should return 0 since the list is empty(we cannot remove that element): "<<emptylist.remove(1,1)<<endl;
    // cout<<"remove - should return 0 since the occur is lower than 1: "<<inting.remove(1,-2)<<endl;
    // cout<<"removeAllKeys - should return 0 since the list is empty: "<<emptylist.removeAllKeys(1)<<endl;
    // cout<<"removeAllKeys - should return 0 since there are no elements with such key in the list: "<<inting.removeAllKeys(2)<<endl;
    // cout<<"removeAllKeys - checking case when the only elements on that list have 1 as a key: "<<endl;
    // inting.removeAllKeys(1);
    // inting.print();
    // inting.insertEnd(1,1);
    // cout<<"removeFirst - should return 0 since the list is empty: "<<emptylist.removeFirst()<<endl;
    // cout<<"removeLast - should return 0 since the list is empty: "<<emptylist.removeLast()<<endl;
    // cout<<"removeLast - checking case when the last element is the first element as well: "<<endl;
    // inting.removeLast();
    // inting.print();
    // inting.insertEnd(1,1);
    // cout<<"removePosition:"<<endl;
    // cout<<"Should return 0 - since the list is empty: "<<emptylist.removePosition(1)<<endl;
    // cout<<"Should return 0 - since position is lower than 1: "<<inting.removePosition(0)<<endl;
    // cout<<"Should return 0 - since position is bigger than the length of the list: "<<inting.removePosition(2)<<endl;
    // cout<<"insertAfter:"<<endl;
    // cout<<"Should return 0 - since the list is empty: "<<emptylist.insertAfter(1,1,1,1)<<endl;
    // cout<<"Should return 0 - since the occurance is lower than 1: "<<inting.insertAfter(1,1,1,0)<<endl;
    // cout<<"Should return 0 - since the element couldnt be found: "<<inting.insertAfter(1,1,2,1)<<endl;
    // cout<<"insertBefore:"<<endl;
    // cout<<"Should return 0 - since the list is empty: "<<emptylist.insertBefore(1,1,1,1)<<endl;
    // cout<<"Should return 0 - since the occurance is lower than 1: "<<inting.insertBefore(1,1,1,0)<<endl;
    // cout<<"Should return 0 - since the element couldnt be found: "<<inting.insertBefore(1,1,2,1)<<endl;
    // cout<<"insertPosition:"<<endl;
    // cout<<"Should return 0 - since the position is lower than 1: "<<emptylist.insertPosition(1,1,0)<<endl;
    // cout<<"Should return 0 - since the position is bigger than length of a list +1: "<<inting.insertPosition(1,1,3)<<endl;
    // cout<<"checking case when the list is empty: "<<endl;
    // inting.removeAll();
    // inting.insertPosition(1,1,1);
    // inting.print();
    // cout<<"checking case when given position is equal to length of list +1: "<<endl;
    // inting.insertPosition(1,1,2);
    // inting.print();
    // cout<<"Reverse printing a list that is empty: "<<endl;
    // emptylist.reversePrint();
    // cout<<endl;
    // cout<<"search:"<<endl;
    // cout<<"Searching in empty list: "<<endl;
    // emptylist.search(1,1);
    // cout<<"Searching when occurance is lower than 1: "<<endl;
    // inting.search(1,-2);
    // cout<<"Searching when the element is not on the list (either too occurance is too high or element with such key doesn't exist): "<<endl;
    // inting.search(1,3);
    // cout<<"searchAll:"<<endl;
    // cout<<"Searching in empty list: "<<endl;
    // emptylist.searchAll(1);
    // cout<<"Searching when the element with such key is not on the list: "<<endl;
    // inting.searchAll(2);
    // cout<<"count - should return 0 since the list is empty: "<<emptylist.count(1)<<endl;
    // cout<<"count - should return 0 since the list has no element with such key: "<<inting.count(2)<<endl;
    // cout<<"length - should return 0 since the list is empty: "<<emptylist.length()<<endl;
    // cout<<endl;
    // cout<<"reverse:"<<endl;
    // emptylist.reverse();
    // cout<<endl;
    // cout<<"keyandinfo:"<<endl;
    // cout<<"Case when the list is empty: "<<endl;
    // emptylist.keyandinfo(1);
    // cout<<"Case when the given position is less than 1: "<<endl;
    // inting.keyandinfo(-2);
    // cout<<"Case when the list is shorter than the given position: "<<endl;
    // inting.keyandinfo(3);
    // cout<<endl<<"Testing shuffle:"<<endl;
    // Sequence<int, int> testshuf1;
    // Sequence<int, int> testshuf2;
    // Sequence<int, int> testshuf3;
    // cout<<"Case when both of lists are empty: "<<endl;
    // testshuf3 = shuffle(testshuf1,1,testshuf2,1,1);
    // testshuf3.print();
    // testshuf1.insertEnd(1,1);
    // cout<<"Case when one or two lengths are incorrect: "<<endl;
    // testshuf3 = shuffle(testshuf1,-1,testshuf2,1,1);
    // testshuf3.print();
    // cout<<"Case when repeat is incorrect: "<<endl;
    // testshuf3 = shuffle(testshuf1,1,testshuf2,1,0);    
    // testshuf3.print();
    // cout<<"Case when one of the list is empty(will just take elements from one list and skips the other) "<<endl;
    // testshuf1.insertEnd(2,3);
    // testshuf1.insertEnd(3,5);
    // testshuf1.insertEnd(1,1);
    // testshuf1.insertEnd(5,10);
    // testshuf1.insertEnd(4,6);
    // testshuf3 = shuffle(testshuf1,2,testshuf2,1,2);    
    // testshuf3.print();
    

}