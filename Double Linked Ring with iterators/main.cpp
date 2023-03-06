#include <iostream>
#include "ring.h"
using namespace std;

int main(){
    cout<<"---TESTING FOR RING<double,int>---"<<endl;
    Ring<double, int> r;
    auto it = r.begin();



    //Insert methods
    cout<<"insertBefore"<<endl;
    r.insertBefore(0,0,it);
    r.insertBefore(1.5,5,it);
    r.insertBefore(2.3,0,it);
    r.insertBefore(1.5,1,it);
    r.insertBefore(16.2,10,it);
    r.printForward();

    // cout<<"insertAfter"<<endl; 
    // cout<<"changing place of iterator so will add after the first element on the ring"<<endl;
    // it++;
    // r.insertAfter(1.1,1,it);
    // r.printForward();

    // cout<<"insertBegin"<<endl;
    // r.insertBegin(7.7,9);
    // r.printForward();

    // cout<<"insertEnd"<<endl;
    // r.insertEnd(12.5,32);
    // r.printForward();


    // //Remove methods
    // cout<<"testing remove methods:"<<endl;
    // it = r.begin();
    // it++;
    // it++;
    // cout<<"remove (iterator pointing on 3rd element of the ring):"<<endl;
    // r.remove(it);
    // r.printForward();
    // cout<<"removeFirst:"<<endl;
    // r.removeFirst();
    // r.printForward();
    // cout<<"removeLast:"<<endl;
    // r.removeLast();
    // r.printForward();
    // cout<<endl;


    // //Copy constructor and assignment operator
    // cout<<"testing copy constructor and methods on the new ring to be sure everything works fine:"<<endl;
    // Ring<double, int> r1(r);
    // auto it1 = r1.begin();
    // it1++;
    // r1.printForward();
    // r1.insertAfter(42.94,43,it1);
    // r1.insertBefore(467.890,564,it1);
    // r1.insertBegin(12.7,76);
    // r1.insertEnd(85.123,94);
    // r1.printForward();
    // r1.removeFirst();
    // r1.removeLast();
    // r1.remove(it1);
    // r1.printForward();
    // cout<<endl<<"testing asignment operator and methods:"<<endl;
    // r1 = r;
    // it1 = r1.begin();
    // r1.printForward();
    // r1.insertAfter(42.94,43,it1);
    // r1.insertBefore(467.890,564,it1);
    // r1.insertBegin(12.7,76);
    // r1.insertEnd(85.123,94);
    // r1.printForward();
    // r1.removeFirst();
    // r1.removeLast();
    // r1.remove(it1);
    // r1.printForward();
    // cout<<endl;

    // //Printing backwards
    // cout<<"printing backwards (Ring r):"<<endl;
    // r.printBackwards();



    // //Find method
    // cout<<"tesing find method will look for 2nd occurance of 1.5 and forwardDirection is true:"<<endl;
    // r.printForward();
    // bool succ;

    // it = r.find(1.5, 2, succ, true);
    // try{
    //     cout<<it->key<<", "<<it->info<<endl;
    // }catch(...){
    //     cout<<"Error with iterator"<<endl;
    // }
    // cout<<"checking what value has variable succ: "<<succ<<endl<<endl;


    // cout<<"tesing find method will look for 2nd occurance of 1.5 and forwardDirection is false:"<<endl;
    // it = r.find(1.5, 2, succ, false);
    // try{
    //     cout<<it->key<<", "<<it->info<<endl;
    // }catch(...){
    //     cout<<"Error with iterator"<<endl;
    // }
    // cout<<"checking what value has variable succ: "<<succ<<endl<<endl;


    // cout<<"tesing find method when occurance is lower than 1:"<<endl;
    // it = r.find(1.5, 0, succ, false);
    // try{
    //     cout<<it->key<<", "<<it->info<<endl;
    // }catch(...){
    //     cout<<"Error with iterator"<<endl;
    // }
    // cout<<"checking what value has variable succ: "<<succ<<endl<<endl;


    // cout<<"tesing find method when methond will not find given element:"<<endl;
    // it = r.find(1.5, 3, succ, true);
    // try{
    //     cout<<it->key<<", "<<it->info<<endl;
    // }catch(...){
    //     cout<<"Error with iterator"<<endl;
    // }
    // cout<<"checking what value has variable succ: "<<succ<<endl<<endl;



    // //removeAllElements
    // cout<<"testing external function removeAllElements (removing elements with key = 1.5)"<<endl;
    // cout<<"Before removing:"<<endl;
    // r.printForward();
    // removeAllElements(r, 1.5);
    // cout<<"After removing:"<<endl;
    // r.printForward();



    // cout<<"---BORDER LINE CASES---"<<endl;
    // cout<<"testing inserts for empty ring:"<<endl<<endl;
    // cout<<"insertAfter"<<endl;
    // Ring<double, int> rempty;
    // auto itempty = rempty.begin();
    // rempty.insertAfter(1.1,1,itempty);
    // rempty.insertAfter(2.2,2,itempty);
    // rempty.printForward();
    // rempty.removeAll();

    // cout<<"insertBegin"<<endl;
    // rempty.insertBegin(3.5,3);
    // rempty.insertBegin(4.8,4);
    // rempty.printForward();
    // rempty.removeAll();

    // cout<<"insertEnd"<<endl;
    // rempty.insertEnd(5.6,5);
    // rempty.insertEnd(6.2,6);
    // rempty.printForward();
    // rempty.removeAll();

    // it = r.begin();
    // cout<<"Testing insertAfter when given wrong iterator (other owner) - should return 0: "<<rempty.insertAfter(1.1,5,it)<<endl;
    // cout<<"Testing insertBefore when given wrong iterator (other owner) - should return 0: "<<rempty.insertAfter(2.3,5,it)<<endl;
    // cout<<"Testing remove for empty ring - should return 0 since its empty: "<<rempty.remove(itempty)<<endl;
    // cout<<"Testing remove when given wrong iterator (other owner) - should return 0: "<<r.remove(itempty)<<endl;
    // cout<<"Printing forward for empty ring"<<endl;
    // rempty.printForward();
    // cout<<"Printing backwards for empty ring"<<endl;
    // rempty.printBackwards();

    // cout<<"Testing find method for empty ring"<<endl;
    // it = rempty.find(0, 1, succ, true);
    // try{
    //     cout<<it->key<<", "<<it->info<<endl;
    // }catch(...){
    //     cout<<"Error with iterator"<<endl;
    // }
    // cout<<"checking what value has variable succ: "<<succ<<endl<<endl;

    // //even though iterator it has ring r as its owner method find changes owner
    // //we can use one of the previous tests to check that
    // cout<<"Testing remove when given wrong iterator (other owner) - should return 0: "<<r.remove(it)<<endl;


}