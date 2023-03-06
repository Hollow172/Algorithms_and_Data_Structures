#include <iostream>
using namespace std;

template <typename Key, typename Info>
class Ring{
    /* struct that holds only key and info, 
    it was necessery so that iterators will be able to show only this struct by using Data* operator-> and don't have access to showing 
    location of nodes in memory */
    struct Data{ //should be in public
        Key key;
        Info info;
    };

    struct Node{
        Node *next;
        Node *prev;
        Data data;
    };

    Node *head = nullptr;

    public:
    class iterator{
        friend class Ring<Key, Info>;
        Node *current;
        Ring<Key, Info> *owner;
        iterator(Node *c, Ring<Key, Info> *o);

        public:
        iterator();

        iterator& operator++(); //Prefix increment  
        iterator operator++(int); // Postfix increment
        iterator& operator--(); //Prefix decrement
        iterator operator--(int); //Postfix decrement
        // Node& operator*(); //not used wrong
        Data* operator->();

        bool operator== (const iterator &x) const;
        bool operator!= (const iterator& x) const;

    };

    //const_iterator it was necessary to create it for methods of ring that will use const Ring<Key, Info> as a parameter (for example copy constructor)
    class const_iterator{
        friend class Ring<Key, Info>;
        Node *current;
        const Ring<Key, Info> *owner;
        const_iterator(Node *c, const Ring<Key, Info> *o);


        public:
        const_iterator();

        const_iterator& operator++(); //Prefix increment  
        const_iterator operator++(int); // Postfix increment
        const_iterator& operator--(); //Prefix decrement
        const_iterator operator--(int); //Postfix decrement
        // const Node& operator*() const; //not used
        const Data* operator->() const;

        bool operator== (const const_iterator& x) const;
        bool operator!= (const const_iterator& x) const;

    };


    //methods for class Ring
    iterator begin(); //method that returns iterator pointing at head->next 
    iterator end(); //method that returns iterator pointing at head
    //const version of methods begin and end:
    const_iterator cbegin() const; 
    const_iterator cend() const;

    Ring();
    ~Ring();
    Ring(const Ring<Key,Info> &x);
    Ring<Key,Info>& operator=(const Ring<Key,Info> &x);

    //one of those is not necessary
    bool insertBefore(const Key &what, const Info &i, iterator it); //method that inserts before element that is pointed by iterator
    bool insertAfter(const Key &what, const Info &i, iterator it); //method that inserts after element that is pointed by iterator
    void insertBegin(const Key &what, const Info &i); //inserts at the head->next place
    void insertEnd(const Key &what, const Info &i); //inserts at the head->prev place
    bool remove(iterator it); //remove element that is pointed by iterator
    //removing methods 
    void removeFirst(); 
    void removeLast();
    void removeAll();
    //printing methods
    void printForward();
    void printBackwards();

    /* finding an element by given key, returns iterator pointing at the found element 
    failure when user gives occurance lower than 1, 
    success will be either true if method found an element, or false if method didn't found it
    forwardDirection if true then the find method will go forward and if false then it will go backwards
    if the program didn't find an element, the list was empty or occurance was lower than 1 then it returns empty iterator */
    iterator find(const Key &key, int occurance, bool &success, bool forwardDirection);


};



//Implementation for iterator class:

//addresses of them in references
template <typename Key, typename Info>
Ring<Key,Info>::iterator::iterator(Node *c, Ring<Key, Info> *o){
    current = c;
    owner = o;
}

template <typename Key, typename Info>
Ring<Key,Info>::iterator::iterator(){
    current = nullptr;
    owner = nullptr;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator& Ring<Key,Info>::iterator::operator++(){
    if (current!=nullptr){
        current = current->next;
    }
    return *this;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator Ring<Key,Info>::iterator::operator++(int){ 
    iterator to_return = *this;
    if (current!=nullptr){
        current = current->next;
    }
    return to_return;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator& Ring<Key,Info>::iterator::operator--(){
    if (current!=nullptr){
        current = current->prev;
    }
    return *this;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator Ring<Key,Info>::iterator::operator--(int){ 
    iterator to_return = *this;
    if (current!=nullptr){
        current = current->prev;
    }
    return to_return;
}

// template <typename Key, typename Info>
// typename Ring<Key,Info>::Node& Ring<Key,Info>::iterator::operator*(){
//     if(owner == nullptr || current == nullptr) throw "Empty iterator";
//     return *current;
// }

template <typename Key, typename Info>
typename Ring<Key,Info>::Data* Ring<Key,Info>::iterator::operator->(){
    if(owner == nullptr || current == nullptr) throw "Empty iterator";
    return &(current->data);
}

template <typename Key, typename Info>
bool Ring<Key,Info>::iterator::operator== (const typename Ring<Key,Info>::iterator &x) const{ 
    return (owner == x.owner) && (current == x.current);
}

template <typename Key, typename Info>
bool Ring<Key,Info>::iterator::operator!= (const typename Ring<Key,Info>::iterator& x) const{ 
    return !operator==(x);
}



//Implementation for const_iterator class

template <typename Key, typename Info>
Ring<Key,Info>::const_iterator::const_iterator(Node *c, const Ring<Key, Info> *o){
    current = c;
    owner = o;
}

template <typename Key, typename Info>
Ring<Key,Info>::const_iterator::const_iterator(){
    current = nullptr;
    owner = nullptr;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator& Ring<Key,Info>::const_iterator::operator++(){
    if (current!=nullptr){
        current = current->next;
    }
    return *this;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator Ring<Key,Info>::const_iterator::operator++(int){ 
    const_iterator to_return = *this;
    if (current!=nullptr){
        current = current->next;
    }
    return to_return;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator& Ring<Key,Info>::const_iterator::operator--(){
    if (current!=nullptr){
        current = current->prev;
    }
    return *this;
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator Ring<Key,Info>::const_iterator::operator--(int){ 
    const_iterator to_return = *this;
    if (current!=nullptr){
        current = current->prev;
    }
    return to_return;
}

// // template <typename Key, typename Info>
// // const typename Ring<Key,Info>::Node& Ring<Key,Info>::const_iterator::operator*() const{
// //     if(owner == nullptr || current == nullptr) throw "Empty iterator";
// //     return *current;
// // }

template <typename Key, typename Info>
const typename Ring<Key,Info>::Data* Ring<Key,Info>::const_iterator::operator->() const{
    if(owner == nullptr || current == nullptr) throw "Empty iterator";
    return &(current->data);
}

template <typename Key, typename Info>
bool Ring<Key,Info>::const_iterator::operator== (const typename Ring<Key,Info>::const_iterator &x) const{ 
    return (owner == x.owner) && (current == x.current);
}

template <typename Key, typename Info>
bool Ring<Key,Info>::const_iterator::operator!= (const typename Ring<Key,Info>::const_iterator& x) const{ 
    return !operator==(x);
}



//Implementation for Ring class

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator Ring<Key,Info>::begin(){
    return iterator(head->next, this);
}

template <typename Key, typename Info>
typename Ring<Key,Info>::iterator Ring<Key,Info>::end(){
    return iterator(head, this);
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator Ring<Key,Info>::cbegin()const{
    return const_iterator(head->next, this);
}

template <typename Key, typename Info>
typename Ring<Key,Info>::const_iterator Ring<Key,Info>::cend()const{
    return const_iterator(head, this);
}

template <typename Key, typename Info>
Ring<Key,Info>::Ring(){
    Node *sentinel = new Node;
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    sentinel->data.key = Key();
    sentinel->data.info = Info();
    head = sentinel;
}

template <typename Key, typename Info>
Ring<Key,Info>::~Ring() {
    removeAll();
    delete head;
}

template <typename Key, typename Info>
Ring<Key,Info>::Ring(const Ring<Key,Info> &x){
    Node *sentinel = new Node;
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    head = sentinel;

    for(auto it = x.cbegin(); it!=x.cend(); it++){
        insertEnd(it->key, it->info);
    }
}

template <typename Key, typename Info>
Ring<Key,Info>& Ring<Key,Info>::operator=(const Ring<Key,Info> &x){
    if(this == &x) return *this;
    removeAll();
    for(auto it = x.cbegin(); it!=x.cend(); it++){
        insertEnd(it->key, it->info);
    }
    return *this;
}

template <typename Key, typename Info>
bool Ring<Key,Info>::insertBefore(const Key &what, const Info &i, iterator it){
    if(it.owner!=this) return false;

    Node *newNode = new Node;
    newNode->data.key = what;
    newNode->data.info = i;

    newNode->prev = it.current->prev;
    newNode->next = it.current;
    

    it.current->prev = newNode;
    newNode->prev->next = newNode;
    
    return true;

}

template <typename Key, typename Info>
bool Ring<Key,Info>::insertAfter(const Key &what, const Info &i, iterator it){
    if(it.owner!=this) return false;

    Node *newNode = new Node;
    newNode->data.key = what;
    newNode->data.info = i;

    Node *current = it.current;

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    newNode->next->prev = newNode;
    return true;

}

// it can be shorther
template <typename Key, typename Info>
void Ring<Key,Info>::insertBegin(const Key &what, const Info &i){
    auto it = this->begin();

    Node *newNode = new Node;
    newNode->data.key = what;
    newNode->data.info = i;

    newNode->prev = it.current->prev;
    newNode->next = it.current;

    (--it).current->next = newNode;
    newNode->next->prev = newNode;
    return;

}

template <typename Key, typename Info>
void Ring<Key,Info>::insertEnd(const Key &what, const Info &i){
    auto it = this->end();

    Node *newNode = new Node;
    newNode->data.key = what;
    newNode->data.info = i;

    newNode->next = it.current;
    newNode->prev = it.current->prev;

    it.current->prev = newNode;
    newNode->prev->next = newNode;
    return;

}

template <typename Key, typename Info>
bool Ring<Key,Info>::remove(iterator it){
    if(it.owner!=this) return false; //If given iterator has different owner
    if(it.current == head) return false; //Can't remove sentinel

    Node *current = it.current;
    Node *next = current->next; 
    Node *prev = current->prev;

    delete current;
    prev->next = next;
    next->prev = prev;

    return true;
}

template <typename Key, typename Info>
void Ring<Key,Info>::removeFirst(){
    auto it = this->begin();
    if(head == it.current) return;
    remove(it);
}

template <typename Key, typename Info>
void Ring<Key,Info>::removeLast(){
    auto it = this->end();
    --it;
    if(head == it.current) return;
    remove(it);

}

template <typename Key, typename Info>
void Ring<Key,Info>::removeAll(){
    auto it = this->begin();
    if(it.current == head) return; //Can't remove sentinel
    while(it.current!=head){
        Node *current = it.current;
        ++it;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    return;
}

template <typename Key, typename Info>
void Ring<Key,Info>::printForward(){
    if(head->next == head){
        cout<<"Ring is empty"<<endl<<endl;
        return;
    }
    
    for(auto it = this->begin(); it!=this->end(); it++){
        cout<<"("<<it->key<<", "<<it->info<<")"<<endl;
    }

    cout<<endl;
    return;
}

template <typename Key, typename Info>
void Ring<Key,Info>::printBackwards(){
    if(head->next == head){
        cout<<"Ring is empty"<<endl<<endl;
        return;
    }
    
    auto it = this->end();
    it--;

    while(it!=this->end()){
        cout<<"("<<it->key<<", "<<it->info<<")"<<endl;
        it--;
    }

    cout<<endl;
    return;

}

//empty_it can be just it with empty ring
template <typename Key, typename Info>
typename Ring<Key,Info>::iterator Ring<Key,Info>::find(const Key &key, int occurance, bool &success, bool forwardDirection){
    auto it = this->begin();
    iterator empty_it;
    if(it.current == head){
        success = false;
        cout <<"The ring is empty"<<endl;
        return empty_it;
    }

    if(occurance<1){
        success = false;
        cout <<"Occurance cannot be lower than 1"<<endl;
        return empty_it;
    }

    int counter = 1;

    if(forwardDirection == true){
        while(it.current!=head){
            if(it->key == key){
                if(occurance == counter){
                    success = true;
                    cout <<"Element found"<<endl;
                    return it;
                }
                counter++;
            }
            ++it;
        }
    }

    if(forwardDirection == false){
        it = this->end();
        it--;
        while(it.current!=head){
            if(it->key == key){
                if(occurance == counter){
                    success = true;
                    cout <<"Element found"<<endl;
                    return it;
                }
                counter++;
            }
            --it;
        }
    }

    success = false;
    cout <<"Element was not found"<<endl;
    return empty_it;

}

//external function removeAllElements
template <typename Key, typename Info>
void removeAllElements(Ring <Key, Info> &r, const Key &k){
    auto it = r.begin();
    while(it!=r.end()){
        auto temp = it;
        temp++;
        if(it->key == k){
            r.remove(it);
        }
        it = temp;
    }
}