#include <iostream>
#include <string>

using namespace std;

template <typename Key, typename Info>
class Sequence{
    struct Node{
        Key key;
        Info info;
        Node *next;
    };
    Node *head = nullptr;

    public:

    //Somewhere here should be const but i dont remember where exactly(prolly in operator + and -):
    Sequence(); //Constructor
    ~Sequence(); //Deconstructor
    Sequence(const Sequence<Key, Info> &x);
    Sequence<Key,Info>& operator=(const Sequence<Key,Info> &x); 
    Sequence<Key, Info>& operator+=(const Sequence<Key, Info> &x); //adds elements from right list to the end of the left list
    Sequence<Key, Info>& operator-=(const Sequence<Key, Info> &x); //deletes all elements and their occurances from left that are on the right
    //both of them WITHOUT & since it changes:
    Sequence<Key,Info>& operator+(const Sequence<Key,Info> &x);  //adds elements to one list
    Sequence<Key, Info>& operator-(const Sequence<Key, Info> &x); //deletes all elements and their occurances from left that are on the right 

    bool isEmpty() const; //Checks if the list is empty
    Key getKey(int i) const;
    Info getInfo(int i) const;

    //Remove methods:
    bool removeAll(); //Removes all elements from list
    bool remove(const Key &which, int occur=1); //Removes one element given by user and only one occurance of it
    bool removeAllKeys(const Key &which); //Removes all occurances of an element given by user
    bool removeFirst(); //Removes first element on the list
    bool removeLast(); //Removes last element on the list
    bool removePosition(int position); //Removes given (numerical) position on the list where position = 1 is the beginning of the list
    bool removeKeyAndInfo(const Key &which, const Info info); //Removes first occurance of given key and info

    //Insert methods:
    bool insertEnd(const Key &what, const Info &i); //Inserts new element on the end of the list
    bool insertBegin(const Key &what, const Info &i); //Inserts new element on the beginning of the list
    bool insertAfter(const Key &what, const Info &i, const Key &where, int occur); //Inserts new element after given element on the list and its occurance
    bool insertBefore(const Key &what, const Info &i, const Key &where, int occur); //Inserts new element before given element on the list and its occurance 
    bool insertPosition(const Key &what, const Info &i, int position); //Inserts new element on given position (key and info that were before are disappearing)

    //Printing methods:
    void print(); //Prints the whole list
    void reversePrint(); //Prints the whole list in reversed order (by using private function reversePrint)

    //Search methods:
    void search(const Key &where, int occur) const;//Searches for the element and its occurance on the list
    void searchAll(const Key &where) const; //Searches for all elements of given key
    
    //Other methods:
    int count(const Key &what);//Counts how many elements given by user are on the list
    int length() const; //length of list
    void reverse(); //reverses whole list
    void keyandinfo(int i)const; //prints key and info for given position on the list

    private:
    void reversePrint(Node *point); //recursive function that reverse prints list

};

//IMPLEMENTATION:

template <typename Key, typename Info>
Sequence<Key,Info>::Sequence(){
    head = nullptr; 
}

template <typename Key, typename Info>
Sequence<Key,Info>::~Sequence(){
    removeAll();
}

template <typename Key, typename Info>
Sequence<Key,Info>::Sequence(const Sequence<Key, Info> &x){
    Node *current = x.head;
    while(current!=nullptr){
        this->insertEnd(current->key, current->info);
        current=current->next;
    }
}

//HERE shouldnt be this->removeAll(), only checking if the list is empty
template <typename Key, typename Info>
Sequence<Key,Info>& Sequence<Key,Info>::operator=(const Sequence<Key,Info> &x){
    this->removeAll();
    Node *current = x.head;
    while(current!=nullptr){
        this->insertEnd(current->key, current->info);
        current=current->next;
    }
    return *this;
}

template <typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key,Info>::operator+=(const Sequence<Key, Info> &x){
    Node *current = x.head;
    while(current!=nullptr){
        this->insertEnd(current->key, current->info);
        current=current->next;
    }
    return *this;    
}

template <typename Key, typename Info>
Sequence<Key,Info>& Sequence<Key,Info>::operator+(const Sequence<Key,Info> &x){
    Sequence<Key, Info> *newSeq = new Sequence<Key, Info>(*this); //should be something like Sequence<Key, Info> newSeq = (*this)
    Node *current = x.head;
    while(current!=nullptr){
        newSeq->insertEnd(current->key, current->info);
        current=current->next;
    }
    return *newSeq;
}

template <typename Key, typename Info>
Sequence<Key,Info>& Sequence<Key,Info>::operator-=(const Sequence<Key,Info> &x){
    Node *currentThis = this->head;
    Node *current = x.head;
    while(currentThis!=nullptr){
        while(current!=nullptr){
            if(current->key == currentThis->key && current->info == currentThis->info) this->removeKeyAndInfo(current->key,current->info);
            current=current->next;
        }
        current = x.head;
        currentThis=currentThis->next;
    }
    return *this;
}

template <typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key,Info>::operator-(const Sequence<Key, Info> &x){
    Sequence<Key, Info> *newSeq = new Sequence<Key, Info>(*this);
    Node *currentThis = newSeq->head;
    Node *current = x.head;
    while(currentThis!=nullptr){
        while(current!=nullptr){
            if(current->key == currentThis->key && current->info == currentThis->info) newSeq->removeKeyAndInfo(current->key,current->info);
            current=current->next;
        }
        current = x.head;
        currentThis=currentThis->next;
    }
    return *newSeq;
}



template <typename Key, typename Info>
bool Sequence<Key,Info>::isEmpty() const{
    if(head == nullptr) return true;
    return false;
}


//both in getKey and getInfo instead of checking like this (borderline case) throw an exception
template <typename Key, typename Info>
Key Sequence<Key,Info>::getKey(int i) const{
    if(i<1 || i>length()) {
        Key *keyp = new Key;
        return *keyp;
    }
    Node *current = head;
    int index = 1;
    while(current!=nullptr && index<i){
        index++;
        current = current->next;
    }
    return current->key;
}

template <typename Key, typename Info>
Info Sequence<Key,Info>::getInfo(int i) const{
    if(i<1 || i>length()) {
        Info *infop = new Info;
        return *infop;
    }
    Node *current = head;
    int index = 1;
    while(current!=nullptr && index<i){
        index++;
        current = current->next;
    }
    return current->info;
}


//Why is it bool since it returns only true?
template <typename Key, typename Info>
bool Sequence<Key,Info>::removeAll(){ 
    if(isEmpty()) return true;
    Node *current = head;
    while(current!=nullptr){
        current = current->next;
        delete head;
        head = current;
    }
    head = nullptr;
    return true;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::remove(const Key &which, int occur){
    if(isEmpty()) return false;
    if(occur < 1) return false;
    Node *current = head;
    Node *previous = nullptr;
    int foundOccur = 1;
    while(current!=nullptr){
        if(current->key == which){
            if(foundOccur==occur){
                if(previous==nullptr) head = current->next;
                else previous->next = current->next; 
                delete current;
                return true;
            }
            foundOccur++;
        }
    previous = current;
    current = current->next;
    }
    return false;
}

//This method is not efficient since it has to go through the whole list many times
template <typename Key, typename Info>
bool Sequence<Key,Info>::removeAllKeys(const Key &which){
    if(isEmpty()) return false;
    Node *current = head;
    int counter = count(which);
    if(counter == 0) return false; //case when before the loop there is no element with such key in the list
    while(current!=nullptr){
        if(current->key == which){
            remove(which, 1);
            counter--;
        }
    current = current->next;
    }
    if(counter == 0) return true;
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::removeFirst(){
    if(isEmpty()) return false;
    Node *current = head;
    head = current->next;
    delete current;
    return true;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::removeLast(){
    if(isEmpty()) return false;
    Node *current = head;
    Node *previous = nullptr;
    while(current!=nullptr){
        if(current->next == nullptr){
            if(previous == nullptr) head = current->next;
            else previous->next = nullptr;
            delete current; 
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false; //It will never happen since the only case where it doesn't delete last element is when the list is empty
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::removePosition(int position){
    if(position<1) return false;
    if(isEmpty()) return false;
    if(position > length()) return false;
    Node *current = head;
    Node *previous = nullptr;
    int counter = 1;
    while(current!=nullptr){
        if(position == counter){
            if(previous == nullptr) head = current->next;
            else previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
        counter++;
    }
    return false;
}

//here should add something like int occurance since thats how i did previous remove
template <typename Key, typename Info>
bool Sequence<Key,Info>::removeKeyAndInfo(const Key &which, const Info info){
    if(isEmpty()) return false;
    Node *current = head;
    Node *previous = nullptr;
    while(current!=nullptr){
        if(current->key == which && current->info == info){
            if(previous == nullptr) head = current->next;
            else previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}



template <typename Key, typename Info>
bool Sequence<Key,Info>::insertEnd(const Key &what, const Info &i){
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    if(head == nullptr){
        newNode->next = nullptr;
        head = newNode;
        return true;
    }
    Node *current = head;
    while(current->next!=nullptr){
        current = current->next;
    }
    newNode->next = nullptr; 
	current->next = newNode;
	return true;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::insertBegin(const Key &what, const Info &i){
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    if(head == nullptr){
        newNode->next = nullptr; 
        head = newNode;
        return true;
    }
    newNode->next = head;
    head = newNode;
    return true;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::insertAfter(const Key &what, const Info &i, const Key &where, int occur){
    if(isEmpty()) return false;
    if(occur < 1) return false;
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    Node *current = head;
    int foundOccur = 1;
    while(current!=nullptr){
        if(current->key==where){
            if(foundOccur == occur){
                newNode->next = current->next;
                current->next = newNode;
                return true;
            }
            foundOccur++;
        }
        current=current->next;
    }
    return false;

}

template <typename Key, typename Info>
bool Sequence<Key,Info>::insertBefore(const Key &what, const Info &i, const Key &where, int occur){
    if(isEmpty()) return false;
    if(occur < 1) return false;
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    Node *current = head;
    Node *previous = nullptr;
    int foundOccur = 1;
    while(current!=nullptr){
        if(current->key==where){
            if(foundOccur == occur){
                if(previous == nullptr){
                    newNode->next = current;
                    head = newNode;
                    return true;
                } 
                else{
                    previous->next = newNode;
                    newNode->next = current;
                    return true;
                }
            }
            foundOccur++;
        }
        previous=current;
        current=current->next;
    }
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key,Info>::insertPosition(const Key &what, const Info &i, int position){
    if(position<1) return false;
    if(position > length()+1) return false;
    if(isEmpty()) insertBegin(what, i);
    if(position == length()+1) insertEnd(what, i);
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    Node *current = head;
    Node *previous = nullptr;
    int counter = 1;
    while(current!=nullptr){
        if(counter == position){
            if(previous == nullptr){
                newNode->next = current->next;
                head = newNode;
                return true;
            }else{
                previous->next = newNode;
                newNode->next = current->next;
                return true;
            }
        }
        counter++;
        previous = current;
        current = current->next;
    }
    return false;
}



template <typename Key, typename Info>
void Sequence<Key,Info>::print(){
    if(isEmpty()){
        cout<<"The list is empty"<<endl<<endl;
        return;
    }
    cout<<"Printing list:"<<endl;
    Node *current = head;
    while(current!=nullptr){
        cout<< current->key <<", "<<current->info <<endl;
        current=current->next;
    }
    cout<<endl;
}

template <typename Key, typename Info>
void Sequence<Key,Info>::reversePrint(Node *point){
    if(point->next!=nullptr) reversePrint(point->next);
    cout<<point->key<<", "<<point->info<<endl;
}

template <typename Key, typename Info>
void Sequence<Key,Info>::reversePrint(){
    if(head == nullptr){
        cout<<"Cannot reverse print a list that is empty"<<endl;
        return;
    }
    cout<<"Printing list in reversed order:"<<endl;
    reversePrint(head);

}



//Should be bool to get true/false 
template <typename Key, typename Info>
void Sequence<Key,Info>::search(const Key &where, int occur)const{
    if(isEmpty()){ 
        cout<<"I cannot search in an empty list"<<endl;
        return;
    }
    if(occur < 1){
        cout<<"It is not possible to search if occurance is less than 1"<<endl;
        return;
    }
    Node *current = head;
    int foundOccur = 1;
    int place_on_the_list = 1;
    while(current!=nullptr){
        if(current->key == where){
            if(foundOccur == occur){
                cout<<"I found wanted item with a key - "<<current->key<<" with occurance = "<<occur<<" and is in "<<place_on_the_list<<". place on the list"<<endl<<endl;
                return;
            }
            foundOccur++;
        }
        current=current->next;
        place_on_the_list++;
    }
    cout<<"There is no such item"<<endl<<endl;
    return;
}

//Prolly also bool
template <typename Key, typename Info>
void Sequence<Key,Info>::searchAll(const Key &where)const{
    if(isEmpty()){ 
        cout<<"I cannot search in an empty list"<<endl;
        return;
    }
    Node *current = head;
    int how_many = 0;
    int place_on_the_list = 1;
    while(current!=nullptr){
        if(current->key == where){
            cout<<"I found wanted item with a key - "<<current->key<<" and is in "<<place_on_the_list<<". place on the list"<<endl;
            how_many++;
        }
        current=current->next;
        place_on_the_list++;
    }
    if(how_many>0){
        cout<<"There were "<<how_many<<" elements with such key in total"<<endl<<endl;
    }
    else cout<<"There is no such item with given key"<<endl<<endl;    
}



template <typename Key, typename Info>
int Sequence<Key,Info>::count(const Key &what){
    if(isEmpty()) return 0;
    Node *current = head;
    int counter=0;
    while(current!=nullptr){
        if(current->key == what){
            counter++;
        }
        current=current->next;
    }
    return counter;
}

template <typename Key, typename Info>
int Sequence<Key,Info>::length() const{
    if(isEmpty()) return 0;
    Node *current = head;
    int length_counter = 0;
    while(current!=nullptr){
        length_counter++;
        current=current->next;
    }
    return length_counter;
}

template <typename Key, typename Info>
void Sequence<Key,Info>::reverse(){
    if(isEmpty()) {
        cout<<"I cannot reverse list that is empty"<<endl;
        return;
    }
    Node *current = head;
    Node *previous = nullptr;
    Node *next = nullptr;
    while(current!=nullptr){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

template <typename Key, typename Info>
void Sequence<Key,Info>::keyandinfo(int i)const{
    if(isEmpty()) {
        cout<<"The list is empty"<<endl;
        return;
    }
    if(i<1) {
        cout<<"Given position is less than 1"<<endl;
        return;
    }
    if(this->length()<i) {
        cout<<"Legnth of list is lower than the given position"<<endl;
        return;
    }
    Node *current = head;
    int counter = 1;
    while(current!=nullptr){
        if(i == counter) {
            cout<<current->key<<", "<<current->info<<endl;
            return;
        }
        current = current->next;
        counter++;
    }
    return;
}


template <typename Key, typename Info>
Sequence<Key,Info> shuffle(const Sequence<Key, Info> &S1, int len1, const Sequence<Key, Info> &S2, int len2, int repeat){
    Sequence<Key, Info> output;
    if(S1.isEmpty() && S2.isEmpty()) {
        cout<<"Both lists are empty - cannot shuffle"<<endl;
        return output;
    }
    if(len1<1 || len2<1) {
        cout<<"Given lengths are incorrect"<<endl;
        return output;
    }
    if(repeat<1){
        cout<<"Given repeat is lower than 1"<<endl;
        return output;
    } 
    
    int x = repeat;
    int count1 = 1;
    int count2 = 1;
    int i1 = 1;
    int i2 = 1;

    while(x>0){
        while(i1<=len1 && S1.length()>=count1){
            output.insertEnd(S1.getKey(count1), S1.getInfo(count1));
            count1++;
            i1++;
        }
        while(i2<=len2 && S2.length()>=count2){
            output.insertEnd(S2.getKey(count2), S2.getInfo(count2));
            count2++;
            i2++;
        }
        x--;
        i1=1;
        i2=1;
    }

    return output;
}



