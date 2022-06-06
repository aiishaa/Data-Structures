#include <iostream>

using namespace std;
template<class T>
class BSTNode{
private:
    T value;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }
    BSTNode(T val){
        value = val;
        left = right = NULL;
    }
    BSTNode(T val, BSTNode *left, BSTNode *right) : value(val), left(left),
    right(right) {}

    void setLeft(BSTNode<int> *left){
        this->left = left;
    }
    void setRight(BSTNode<int> *right){
        this->right = right;
    }
    BSTNode*getleft(){
        return left;
    }

    BSTNode*getright(){
        return right;
    }

    T getkey(){
        return value;
    }

};
template <class T>
class BSTFCI{
private:
    BSTNode<T> *root;
public:
    BSTFCI(){ root = NULL;}
    BSTFCI(BSTNode<T> *r){
        this->root = r;
    }
    BSTNode<T> *getRoot(){return root;}
    BSTNode<T> *insert(BSTNode<T> *root, T data);
    void Insert(T DATA);
    bool isSameTree(BSTNode<T> *t1, BSTNode<T>* t2);
    bool isSubTree(BSTFCI<T>* t1, BSTFCI<T>* t2);
    bool isSubTree(BSTNode<T> *root1, BSTNode<T> *root2);
    int height(BSTNode<T>* root);
    bool isBalance(BSTNode<T> *root);
    void printRange(BSTNode<T> *r, int min, int max);
    void printRange(int min, int max);
    void printInOrder(BSTNode<T> *r);
    void printInOrder();
};

template <class T>
BSTNode<T>* BSTFCI<T>::insert(BSTNode<T>* root, T data) {
    if(root == NULL){
        root = new BSTNode<T>(data);
        return root;
    }
    BSTNode<T>* temp = root;
    if(data < temp->getkey()){
        insert(temp->getleft(), data);
        if(temp->getleft() == NULL){
            temp->setLeft(new BSTNode<T>(data));
        }
    }
    else{
        insert(temp->getright(), data);
        if(temp->getright() == NULL){
            temp->setRight(new BSTNode<T>(data));
        }
    }
    return root;
}

template <class T>
void BSTFCI<T>::Insert(T DATA)
{
    root = insert(root, DATA);
}

template <class T>
bool BSTFCI<T>::isSameTree(BSTNode<T> *t1, BSTNode<T>* t2){
   if (t1 == NULL && t2 == NULL)
      return true;
   if (t1 == NULL || t2 == NULL)
      return false;
   return (t1->getkey() == t2->getkey() && isSameTree(t1->getleft(), t2->getleft()) && isSameTree(t1->getright(), t2->getright()));
}

template <class T>
bool BSTFCI<T>::isSubTree(BSTNode<T>* t1, BSTNode<T>* t2){
    bool check = false;
    if(t2 == NULL || t1 == NULL){
        return false;
    }
    if(t2 == NULL && t1 == NULL){
        return true;
    }
    if(isSameTree(t1, t2)){
        return true;
    }
    return isSubTree(t1->getleft(), t2) || isSubTree(t1->getright(), t2);
}

template <class T>
bool BSTFCI<T>::isSubTree(BSTFCI<T>* t1, BSTFCI<T>* t2){
    return isSubTree(t1->root, t2->root);
}

template <class T>
int BSTFCI<T>::height(BSTNode<T>* root){
    int l = 0;
    int r = 0;
    if(root == NULL){
        return -1;
    }
    else{
        l = height(root->getleft());
        l++;
        int r = height(root->getright());
        r++;

        if(l > r)
            return l;
        else
            return r;
    }
}

template <class T>
bool BSTFCI<T>::isBalance(BSTNode<T>* root){
    if(root == NULL)
        return true;
    if(abs(height(root->getleft()) - height(root->getright()) <= 1
           && isBalance(root->getleft()) && isBalance(root->getright())))
        return 1;

    return 0;
}

template <class T>
void BSTFCI<T>::printRange(BSTNode<T> *r, int min, int max){
    if(r == NULL)
        return;
    if(min < r->getkey())
        printRange(r->getleft(), min, max);

    if (min <= r->getkey() && max > r->getkey() )
        cout << r->getkey() << " ";

    if(max > r->getkey()){
        printRange(r->getright(), min, max);
    }
}

template <class T>
void BSTFCI<T>::printRange(int min, int max){
    printRange(root, min, max);
    cout << endl;
}

template <class T>
void BSTFCI<T>::printInOrder(BSTNode<T> *r){
    if(r == NULL)
        return;
    printInOrder(r->getleft());
    cout << r->getkey() << " ";
    printInOrder(r->getright());
}

template <class T>
void BSTFCI<T>::printInOrder()
{
    printInOrder(root);
    cout << endl<<endl;
}

int main()
{
    // Creating a tree.
    //BSTNode<int> *left = new BSTNode<int>(2);
    //BSTNode<int> *right = new BSTNode<int>(3);
    //BSTNode<int> *root = new BSTNode<int>(1, left, right);
    BSTFCI <int> * FCI1 = new BSTFCI <int>();
    BSTFCI <int> * FCI2 = new BSTFCI <int>();
    BSTFCI <int> * FCI3 = new BSTFCI <int>();
    BSTFCI <int> * FCI4 = new BSTFCI <int>();
    BSTFCI <int> * FCI5 = new BSTFCI <int>();


    // Construct a tree
	FCI1->Insert(5);
	FCI1->Insert(3);
	FCI1->Insert(7);
	FCI1->Insert(2);
	FCI1->Insert(4);
	FCI1->Insert(9);
	FCI1->Insert(1);
	FCI1->Insert(8);
	FCI1->Insert(10);

	// Construct a tree
	FCI2->Insert(9);
	FCI2->Insert(8);
	FCI2->Insert(10);

	// Construct a tree
	FCI3->Insert(3);
	FCI3->Insert(2);
	FCI3->Insert(4);
	FCI3->Insert(1);

	// Construct a tree
	FCI4->Insert(8);
	FCI4->Insert(3);
	FCI4->Insert(10);
	FCI4->Insert(1);
	FCI4->Insert(6);
	FCI4->Insert(14);
	FCI4->Insert(4);
	FCI4->Insert(7);
	FCI4->Insert(13);

	// Construct a tree
	FCI5->Insert(3);
	FCI5->Insert(1);
	FCI5->Insert(6);
	FCI5->Insert(4);
	FCI5->Insert(7);

	cout << "Tree1: "; FCI1->printInOrder();
	cout << endl;
	cout << "Tree2: "; FCI2->printInOrder();
	cout << endl;
	cout << "Tree3: "; FCI3->printInOrder();
	cout << endl;
    cout << "Tree4: "; FCI4->printInOrder();
	cout << endl;
	cout << "Tree5: "; FCI5->printInOrder();
	cout << endl;

	cout << "print tree1 in a range (5 : 9) : ";
    FCI1->printRange(5, 9);
    cout << endl;

    cout << "print tree1 in a range (8 : 15) : ";
    FCI1->printRange(8, 15);
    cout << endl;

    cout << "print tree1 in a range (6 : 6) : ";
    FCI1->printRange(6, 6);
    cout << endl;

    cout << "print tree4 in a range (5 : 10) : ";
    FCI4->printRange(5, 10);
    cout << endl;

    cout << "print tree3 in a range (2 : 5) : ";
    FCI3->printRange(2, 5);
    cout << endl;

	cout << "tree1 is balanced: " << (FCI1->isBalance(FCI1->getRoot()) ? "yes" : "No"); cout << endl;
	cout << "tree2 is balanced: " << (FCI2->isBalance(FCI2->getRoot()) ? "yes" : "No"); cout << endl;
	cout << "tree3 is balanced: " << (FCI3->isBalance(FCI3->getRoot()) ? "yes" : "No"); cout << endl;
	cout << "tree4 is balanced: " << (FCI4->isBalance(FCI4->getRoot()) ? "yes" : "No"); cout << endl;
	cout << "tree5 is balanced: " << (FCI5->isBalance(FCI5->getRoot()) ? "yes" : "No"); cout << endl;

	cout << "tree2 is subtree of tree1: " << (FCI1->isSubTree(FCI1,FCI2) ? "yes" : "No"); cout << endl;
	cout << "tree3 is subtree of tree1: " << (FCI1->isSubTree(FCI1,FCI3) ? "yes" : "No"); cout << endl;
	cout << "tree5 is subtree of tree4: " << (FCI4->isSubTree(FCI4,FCI5) ? "yes" : "No"); cout << endl;
	cout << "tree2 is subtree of tree4: " << (FCI4->isSubTree(FCI4,FCI2) ? "yes" : "No"); cout << endl;
	cout << "tree5 is subtree of tree 1: " << (FCI1->isSubTree(FCI1,FCI5) ? "yes" : "No"); cout << endl;
    return 0;
}
