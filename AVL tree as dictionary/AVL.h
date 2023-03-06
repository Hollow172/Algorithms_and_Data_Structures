#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

//unique keys, insertion, delete, finding, maybe modifing, printing tree
//external method void read_file

template <typename Key, typename Info>
class Dictionary{
    struct Node{
        Key key;
        Info info;
        Node *left;
        Node *right;
    };

    Node *root = nullptr;
    public:
    Dictionary();
    ~Dictionary();
    Dictionary(const Dictionary<Key,Info> &x);
    Dictionary<Key,Info>& operator=(const Dictionary<Key,Info> &x);

    int height();
    bool search(const Key &what) const;
    bool insert(const Key &what, const Info &i);
    bool insertWOBalance(const Key &what, const Info &i);
    bool remove(const Key &what);
    void print();
    void balanceTree();
    void removeAll();
    bool incrementInfo(const Key &what);
    
    private:
    int height(Node *x);
    int balancingFactor(Node *x);
    void BalanceTheTree(Node *x);
    void print(Node *x, int space);
    void RotToLeft(Node *x, Node *prev);
    void RotToRight(Node *x, Node *prev);
    void removeAll(Node *x, Node *prev);
    void copyNodes(Node *src);

};

template <typename Key, typename Info>
Dictionary<Key,Info>::Dictionary(){
    root = nullptr; 
}

template <typename Key, typename Info>
Dictionary<Key,Info>::~Dictionary(){
    removeAll();
}

template <typename Key, typename Info>
Dictionary<Key,Info>::Dictionary(const Dictionary<Key,Info> &x){
    copyNodes(x.root);
}

template <typename Key, typename Info>
Dictionary<Key,Info>& Dictionary<Key,Info>::operator=(const Dictionary<Key,Info> &x){
    if(this == &x) return *this;
    removeAll();
    copyNodes(x.root);
    return *this;
}

template <typename Key, typename Info>
int Dictionary<Key,Info>::height(Node *x){
    if(x == nullptr) return 0;
    int l = height(x->left);
    int r = height(x->right);
    return 1+((l>r) ? l : r);
}

template <typename Key, typename Info>
int Dictionary<Key,Info>::height(){
    return height(root);
}

template <typename Key, typename Info>
bool Dictionary<Key,Info>::search(const Key &what)const{
    if(root == nullptr) return false;
    Node *x = root;
    bool foundItem = false;
    while(x!=nullptr){
        if(what > x->key) x = x->right;
        else if(what < x->key) x = x->left;
        else return foundItem = true;
    }
    return foundItem;
}

template <typename Key, typename Info>
int Dictionary<Key,Info>::balancingFactor(Node *x){
    if(x == nullptr) return 0;
    return height(x->left) - height(x->right);
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::RotToRight(Node *x, Node *prev){
    if(x == root){
        Node *tempx = x;
        Node *lefttempx = tempx->left;
        tempx->left = lefttempx->right;
        lefttempx->right = tempx;
        root = lefttempx;
        return;
    }
    Node *tempx = x;
    Node *lefttempx = tempx->left;
    tempx->left = lefttempx->right;
    lefttempx->right = tempx;
    if(prev->left == x) prev->left = lefttempx;
    else if(prev->right == x) prev->right = lefttempx;
    return;

}

template <typename Key, typename Info>
void Dictionary<Key,Info>::RotToLeft(Node *x, Node *prev){
    if(x == root){
        Node *tempx = x;
        Node *righttempx = tempx->right;
        tempx->right = righttempx->left;
        righttempx->left = tempx;
        root = righttempx;
        return;
    }
    Node *tempx = x;
    Node *righttempx = tempx->right;
    tempx->right = righttempx->left;
    righttempx->left = tempx;
    if(prev->left == x) prev->left = righttempx;
    else if(prev->right == x) prev->right = righttempx;
    return;

}

template <typename Key, typename Info>
void Dictionary<Key,Info>::balanceTree(){
    BalanceTheTree(root);
    return;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::BalanceTheTree(Node *x){
    if(x == nullptr) return;
    if(x!=nullptr) BalanceTheTree(x->left);
    if(x!=nullptr) BalanceTheTree(x->right);
    //cases when rotating node that is not a root
    if(balancingFactor(x->left)>1) RotToRight(x->left, x);
    if(balancingFactor(x->right)>1){
        if(balancingFactor(x->right->left)<=-1)RotToLeft(x->right->left, x->right);
        RotToRight(x->right, x);
    } 
    if(balancingFactor(x->left)<-1) {
        if(balancingFactor(x->left->right) >= 1) RotToRight(x->left->right, x->left);
        RotToLeft(x->left, x);
    }
    if(balancingFactor(x->right)<-1) RotToLeft(x->right, x);
    //cases when rotating root
    if(x == root && balancingFactor(x)<-1){
        if(balancingFactor(x->right)==1) RotToRight(x->right, x); 
        RotToLeft(x, nullptr);
    } 
    if(x == root && balancingFactor(x)>1) {
        if(balancingFactor(x->left)==-1) RotToLeft(x->left,x);
        RotToRight(x, nullptr);
    }
    return;
}

template <typename Key, typename Info>
bool Dictionary<Key,Info>::insert(const Key &what, const Info &i){
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(root == nullptr){
        root = newNode;
        return true;
    }
    if(search(what)){
        // cout<<"Element found in a tree"<<endl;
        return false;
    } 
    Node *x = root;
    bool succ = false;
    while(!succ){
        if(what > x->key){
            if(x->right==nullptr){
                x->right = newNode;
                succ = true;
            } 
            x = x->right;
        }
        else if(what < x->key){
            if(x->left==nullptr){
                x->left = newNode;
                succ = true;
            } 
            x = x->left;
        } 
    }

    BalanceTheTree(root);
    return true;

}

template <typename Key, typename Info>
bool Dictionary<Key,Info>::insertWOBalance(const Key &what, const Info &i){
    Node *newNode = new Node;
    newNode->key = what;
    newNode->info = i;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(root == nullptr){
        root = newNode;
        return true;
    }
    if(search(what)){
        return false;
    } 
    Node *x = root;
    bool succ = false;
    while(!succ){
        if(what > x->key){
            if(x->right==nullptr){
                x->right = newNode;
                succ = true;
            } 
            x = x->right;
        }
        else if(what < x->key){
            if(x->left==nullptr){
                x->left = newNode;
                succ = true;
            } 
            x = x->left;
        } 
    }

    return true;

}

template <typename Key, typename Info>
void Dictionary<Key,Info>::copyNodes(Node *src){
    if(src!=nullptr){
        insertWOBalance(src->key, src->info);
        copyNodes(src->right);
        copyNodes(src->left);
    }
    return;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::print(Node *x, int space){
    if(x == nullptr) return;
    space += 3;
    print(x->right, space);
    for (int i = 3; i<space; i++) cout<<" ";
    cout<<x->key<<" "<<x->info<<endl;
    print(x->left, space);
    return;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::print(){
    if(root == nullptr){
        cout<<"The tree is empty"<<endl;
        return;
    }
    print(root, 0);
    cout<<endl;
    return;
}

template <typename Key, typename Info>
bool Dictionary<Key,Info>::remove(const Key &what){
    if(root == nullptr) return false;
    if(search(what) == false){
        cout<<"Element not found in a tree"<<endl;
        return false;
    } 
    Node *x = root;
    Node *prev = nullptr;
    bool succ = false;
    //finding the place of given node and getting what was previous
    while(!succ){
        if(root->key == what){
            succ = true;
        }
        if(what > x->key){
            if(x->right->key == what){
                prev = x;
                x = x->right;
                succ = true;
            }
            else{
                prev = x;
                x = x->right;
            }

        }
        else if(what < x->key){
            if(x->left->key == what){
                prev = x;
                x = x->left;
                succ = true;
            }
            else{
                prev = x;
                x = x->left;               
            }

        } 
    }

    //Only root in the tree
    if(x->left == nullptr && x->right == nullptr && x == root){
        delete x;
        x = nullptr;
        root = nullptr;
        return true;
    }

    //leaf has no children
    if(x->left == nullptr && x->right == nullptr){
        if(prev->left == x){
            prev->left = nullptr;
            delete x;
            x = nullptr;
            BalanceTheTree(root);
            return true;
        }
        else if(prev->right == x){
            prev->right = nullptr;
            delete x;
            x = nullptr;
            BalanceTheTree(root);
            return true;
        }
    }

    //leaf has one child
    if((x->left != nullptr && x->right == nullptr) || (x->left == nullptr && x->right != nullptr)){
        //if we want to remove root with one child
        if (x == root){
            if(x->left == nullptr){
                Node *temp = x->right;
                delete x;
                x = nullptr;
                root = temp;
                BalanceTheTree(root);
                return true;
            }
            else{
                Node *temp = x->left;
                delete x;
                x = nullptr;
                root = temp;
                BalanceTheTree(root);
                return true;
            }
        }
        else{//case where it's not a root
            if(x->left == nullptr){
                if(prev->left == x){
                    Node *temp = x->right;
                    delete x;
                    x = nullptr;
                    prev->left = temp;
                    BalanceTheTree(root);
                    return true;
                }else{
                    Node *temp = x->right;
                    delete x;
                    x = nullptr;
                    prev->right = temp;
                    BalanceTheTree(root);
                    return true;
                }
            }
            else{
                if(prev->left == x){
                    Node *temp = x->left;
                    delete x;
                    x = nullptr;
                    prev->left = temp;
                    BalanceTheTree(root);
                    return true;
                }else{
                    Node *temp = x->left;
                    delete x;
                    x = nullptr;
                    prev->right = temp;
                    BalanceTheTree(root);
                    return true; 
                }
            }
        }

    }

    //case when it has two children
    if(x->left!=nullptr && x->right!=nullptr){
        //when you want to delete root
        if(x == root){
            if(x->left->right == nullptr){ //case when the left child of root has no right child
                Node *temp1 = x->left;
                Node *temp2 = x->right;
                delete x;
                x = nullptr;
                root = temp1;
                root->right = temp2;
                BalanceTheTree(root);
                return true;
            }
            else{ //case when the left child of root has a right child (this right child has to be moved to the right side as a smallest node)
                //Moving element
                Node *smallestToRight = x->right;
                Node *toBeMoved = x->left->right;
                while(smallestToRight->left!=nullptr){
                    smallestToRight = smallestToRight->left;
                }
                x->left->right = nullptr;
                smallestToRight->left = toBeMoved;

                //deleting root
                Node *temp1 = x->left;
                Node *temp2 = x->right;
                delete x;
                x = nullptr;
                root = temp1;
                root->right = temp2;
                BalanceTheTree(root);
                return true;
            }
        }//Case when you want to delete node with two children but its not a root
        else{
            if(x->left->right == nullptr){ //case when the left child of x has no right child
                if(prev->left == x){
                    Node *temp1 = x->left;
                    Node *temp2 = x->right;
                    delete x;
                    x = nullptr;
                    temp1->right = temp2;
                    prev->left = temp1;
                    BalanceTheTree(root);
                    return true;
                }
                else{
                    Node *temp1 = x->left;
                    Node *temp2 = x->right;
                    delete x;
                    x = nullptr;
                    temp1->right = temp2;
                    prev->right = temp1;
                    BalanceTheTree(root);
                    return true;
                }
            }
            else{ //case when the left child of x has a right child (this right child has to be moved to the right side as a smallest node)
                if(prev->left == x){
                    Node *smallestToRight = x->right;
                    Node *toBeMoved = x->left->right;
                    while(smallestToRight->left!=nullptr){
                        smallestToRight = smallestToRight->left;
                    }
                    x->left->right = nullptr;
                    smallestToRight->left = toBeMoved;

                    //deleting x
                    Node *temp1 = x->left;
                    Node *temp2 = x->right;
                    delete x;
                    x = nullptr;
                    temp1->right = temp2;
                    prev->left = temp1;
                    BalanceTheTree(root);
                    return true;
                }
                else{
                    Node *smallestToRight = x->right;
                    Node *toBeMoved = x->left->right;
                    while(smallestToRight->left!=nullptr){
                        smallestToRight = smallestToRight->left;
                    }
                    x->left->right = nullptr;
                    smallestToRight->left = toBeMoved;

                    //deleting x
                    Node *temp1 = x->left;
                    Node *temp2 = x->right;
                    delete x;
                    x = nullptr;
                    temp1->right = temp2;
                    prev->right = temp1;
                    BalanceTheTree(root);
                    return true;
                }
            }
        }
    }

    return false;

}

template <typename Key, typename Info>
void Dictionary<Key,Info>::removeAll(){
    removeAll(root, nullptr);
    return;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::removeAll(Node *x, Node *prev){
    if(x == nullptr) return;
    if(x->left!=nullptr) removeAll(x->left, x);
    if(x->right!=nullptr) removeAll(x->right, x);
    if(x == root){
        x->left = nullptr;
        x->right = nullptr;
        delete x;
        x = nullptr;
        root = nullptr;
        // cout<<"deleting root";
        return;
    }
    if(prev->left == x && x!=root){
        prev->left = nullptr;
        // cout<<"deleting "<<x->key<<endl;
        x->left = nullptr;
        x->right = nullptr;
        delete x;
        x = nullptr;
        return;
    }
    else if(prev->right == x && x!=root){
        prev->right = nullptr;
        // cout<<"deleting "<<x->key<<endl;
        x->left = nullptr;
        x->right = nullptr;
        delete x;
        x = nullptr;
        return;
    }
    return;
    
}

template <typename Key, typename Info>
bool Dictionary<Key,Info>::incrementInfo(const Key &what){
    if(root == nullptr) return false;
    if(search(what) == false) return false;

    Node *x = root;
    while(x!=nullptr){
        if(what > x->key) x = x->right;
        else if(what < x->key) x = x->left;
        else{
            x->info++;
            return true;
        }
    }

    return false;

}

//in dictionary int - how many times the given text appeared
//in txt file words can be separated other characters ,.? etc
//strings only consisting of letters
void read_file (string file_name, Dictionary<string, int> &dict){

    fstream file;
    file.open(file_name, ios::in);

    if(file.good()==false){
        cout<<"File doesn't exist"<<endl;
        return;
    }

    string line;
    while(getline(file, line)){
    // cout<<line<<endl;

    int n = line.length();
    char arrayofchars[n+1];
    strcpy(arrayofchars, line.c_str());

    for(int i = 0; i < n; i++){
        if(arrayofchars[i]<65 || (arrayofchars[i]>90 && arrayofchars[i]<97) || arrayofchars[i]>122){
            arrayofchars[i] = ',';
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout<<arrayofchars[i];
    // }
    // cout<<endl;

    istringstream output(arrayofchars);
    // cout<<output<<endl;
    string input;

    while(getline(output, input, ',')){
        if(dict.insert(input,1)!=true) dict.incrementInfo(input);
    }

    }

    file.close();

    return;

}