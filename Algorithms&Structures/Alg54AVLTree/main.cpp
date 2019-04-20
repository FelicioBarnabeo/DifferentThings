#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

template <typename T>
class AVLNode
{
public:
    AVLNode *right = nullptr;
    AVLNode *left = nullptr;
    AVLNode *parent = nullptr;
    T key;
    int sum;
    unsigned char height;
    AVLNode(T value): key(value), sum(value){}
    T getKey() const
    {
        return key;
    }
    void setKey(T value)
    {
        key = value;
    }
};

using Node = AVLNode<int>;

template <typename T>
class AVLTree
{
    using Node = AVLNode<int>;
private:
    Node *m_root = nullptr;
public:
    AVLTree() = default;
    explicit AVLTree(Node *root) : m_root(root){}
    explicit AVLTree(T value){
        m_root = new Node(value);
    }
    Node *insert(Node *root, const T &value);
    void add(const T& value);
    void remove(const T value);
    void remove(Node *node);
    Node *findNode(const T& value) const;
    Node *findSuccessor(const T& value) const;
    Node *successor(Node * node) const;
    Node *getMin(Node *root) const;
    Node *getMax(Node *root) const;
    Node *getRoot()const    {return m_root;}
    Node *rotateleft(Node *q);
    Node *rotateright(Node *p);
    int bfactor(Node *p) const;
    void fixheight(Node *p);
    Node *balance(Node *p);
    Node *merge(Node *v1, Node *v2);
    Node *AVLMergeWithRoot(Node *v1, Node *v2, Node* root);
    Node* mergeWithRoot(Node *v1, Node *v2, Node *root);
    void split(Node *v, T key, Node *lefttree, Node *righttree);
    void fixsum(Node *p);
    int getSum(Node *p) const;
    unsigned char getHeight(Node *p) const;
};

template<typename T>
unsigned char AVLTree<T>::getHeight(Node *p) const
{
    return p?p->height:0;
}

template<typename T>
int AVLTree<T>::getSum(Node *p) const
{
    return p?p->sum:0;
}

template<typename T>
void AVLTree<T>::fixsum(Node *p)
{
    cout<<"fixsum"<<endl;
    int sumL = getSum(p->left);
    int sumR = getSum(p->right);
    p->sum = sumL + sumR + p->getKey();
}

template<typename T>
int AVLTree<T>::bfactor(Node *p) const
{
    return getHeight(p->right)-getHeight(p->left);
}

template<typename T>
void AVLTree<T>::fixheight(Node *p)
{
    unsigned char hl = getHeight(p->left);
    unsigned char hr = getHeight(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

template<typename T>
Node *AVLTree<T>::balance(Node *p)
{
    fixheight(p);
    if(bfactor(p)==2)
    {
        cout<<"Bfactor == 2"<<endl;
        if(bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if(bfactor(p)==-2)
    {
        cout<<"Bfactor == -2"<<endl;
        if(bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    //cout<<"return p from balance"<<endl;
    return p;
}

template<typename T>
Node * AVLTree<T>::rotateright(Node *p)
{
    //static_assert(p->left != nullptr && p->right !=nullptr, "Rotate right on nullptr");
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    if(p == m_root) m_root = q;
    fixheight(p);
    fixheight(q);
    fixsum(p);
    fixsum(q);
    return q;
}

template<typename T>
Node *AVLTree<T>::rotateleft(Node *q)
{
    //static_assert(q->left != nullptr && q->right !=nullptr, "Rotate left on nullptr");
    Node *p = q->right;
    q->right = p->left;
    p->left = q;
    if(q == m_root) m_root=p;
    fixheight(q);
    fixheight(p);
    fixsum(p);
    fixsum(q);
    return p;
}

template<typename T>
Node * AVLTree<T>::insert(Node *root, const T &value)
{
    if(root == nullptr)
        return new Node(value);
    if(root->getKey() > value)
    {
        cout<<"root key > value"<<root->getKey()<<" "<<value<<endl;
        root->left = insert(root->left, value);
        //return root;
    }
    else if(root->getKey() < value)
    {
        cout<<"root key > value"<<root->getKey()<<" "<<value<<endl;
        root->right = insert(root->right, value);
        //return root;
    }
    fixsum(root);
    return balance(root); // else return nullptr
}

template<typename T>
void AVLTree<T>::add(const T& value)
{
    if(m_root == nullptr)
    {
        m_root = new Node(value);
    }
    else
    {
        insert(m_root, value);
    }
}

template<typename T>
void AVLTree<T>::remove(const T value)
{
    Node *node = findNode(value);
    if(node == nullptr)
        return;
    remove(node);
}

template<typename T>
void AVLTree<T>::remove(Node *node)
{
    cout<<"remove "<<endl;
    if(node->left && node->right)
    {
        cout<<"node left && node right"<<endl;
        Node * leftmax = getMax(node->left);
        node->setKey(leftmax->getKey());
    }
    //есть только левый наследник(поддерево)
    else if(node->left)
    {
        cout<<"node left"<<endl;
        if(node == node->parent->left)
            node->parent->left = node->left;
        else node->parent->right = node->left;
    }
    //есть только правый наследник(поддерево)
    else if(node->right)
    {
        cout<<"node right"<<endl;
        if(node == node->parent->left)
            node->parent->left = node->right;
        else node->parent->right = node->right;
    }
    //нет наследников
    else
    {
        cout<<"nothing "<< node->getKey() << endl;
        if(node == node->parent->left)
            node->parent->left = nullptr;
        else node->parent->right = nullptr;
    }
    cout<<"end removing"<<endl;
    balance(node);
    fixsum(node);
    delete node;
}

template<typename T>
Node * AVLTree<T>::getMin(Node *root) const
{
    while(root->left)
        root = root->left;
    return root;
}
template<typename T>
Node *AVLTree<T>::getMax(Node *root) const
{
    while(root->right)
        root = root->right;
    return root;
}

template<typename T>
Node *AVLTree<T>::findNode(const T &value) const
{
    Node *ptr = m_root;
    while(ptr && ptr->getKey() != value)
    {
        if(ptr->getKey() > value)
            ptr = ptr->left;
        else if(ptr->getKey() < value)
            ptr = ptr->right;
    }
    if(ptr) cout<<"find node "<<ptr->getKey()<<endl;
    return ptr;
}

template<typename T>
Node *AVLTree<T>::findSuccessor(const T &value) const
{
    Node * x = findNode(value);
    return successor(x);
}

template<typename T>
Node *AVLTree<T>::successor(Node *node) const
{
    if(node->right)
        return getMin(node->right);
    else
    {
        Node *y = node->parent;
        while(y && node==y->right)
        {
            node = y;
            y = y->parent;
        }
        return y;
    }
}

const int MOD = 1000000001;
int f(int x, int lastsum)
{
    return (x+lastsum)%MOD;
}

void printout(Node * root)
{
    if(!root->left && !root->right)
    {
        cout<<root->getKey()<< " ";
        return;
    }
    cout<<root->getKey()<<" ";
    if(root->left)
        printout(root->left);
    if(root->right)
        printout(root->right);
}

template<typename T>
Node* AVLTree<T>::mergeWithRoot(Node *v1, Node *v2, Node *root)
{
    cout<<"merge with root"<<endl;
    if(root == nullptr)
    {
        cout<<"root == nullptr"<<endl;
        return root;
    }
    root->left = v1;
    root->right = v2;
    if(v1 == nullptr){
        cout<<"v1 == nullptr"<<endl;
        root->left = v1;
        return root;
    }
    v1->parent = root;
    if(v2 == nullptr){
        cout<<"v2 == nullptr"<<endl;
        root->right = v2;
        return root;
    }
    v2->parent = root;
    return root;
}

template<typename T>
Node *AVLTree<T>::merge(Node *v1, Node *v2)
{
    if(v1 == nullptr)
        return v2;
    if(v2 == nullptr)
        return v1;
    cout<<"merge"<<endl;
    Node *max = getMax(v1);
    int rootkey = max->getKey();
    remove(max);
    Node *root = new Node(rootkey);
    AVLMergeWithRoot(v1, v2, root);
    return root;
}

template<typename T>
Node *AVLTree<T>::AVLMergeWithRoot(Node *v1, Node *v2, Node* root)
{
    cout<<"AVL merge with root"<<endl;
    //if(v1 == nullptr) { cout<<"v1 == nullptr"<<endl; return root;}
    //if(v2 == nullptr) { cout<<"v2 == nullptr"<<endl; return root;}
    if(abs(v1->height - v2->height) <= 1)
    {
        cout<<"abs v1.h - v2.h <= 1"<<endl;
        mergeWithRoot(v1, v2, root);
        fixheight(root);
        return root;
    }
    else if(v1->height > v2->height)
    {
        cout<<"v1.h > v2.h"<<endl;
        Node *T1 = mergeWithRoot(v1->right, v2, root);
        v1->right = T1;
        T1->parent = v1;
        return balance(v1);
    }
    else
    {
        cout<<"v1.h <= v2.h"<<endl;
        Node *T1 = mergeWithRoot(v2->right, v1, root);
        v2->right = T1;
        T1->parent = v2;
        return balance(v2);
    }
}

struct NodePair
{
    Node *left;
    Node *right;
};

NodePair splitBST(Node *root, int key)
{
    if(root == nullptr)
        return NodePair{nullptr, nullptr};
    if(root->getKey() > key)
    {
        NodePair l = splitBST(root->left, key);
        root->left = l.right;
        return NodePair{l.left, root};
    }
    else
    {
        NodePair r = splitBST(root->right, key);
        root->right = r.left;
        return NodePair{root, r.right};
    }
}

template<typename T>
void AVLTree<T>::split(Node *v, T key, Node *lefttree, Node *righttree)
{
    if(v == nullptr)
    {
        cout<<"return NULL NULL"<<endl;
        return;
    }
    cout<<"split node( "<<v->getKey()<<")"<<endl;
    if( v->getKey() > key )
    {
        cout<<"key < v.key"<<endl;
        split(v->left, key, lefttree, righttree);
        //righttree = AVLMergeWithRoot(righttree, v->right, v);
        righttree = merge(righttree, v->right);
    }
    else
    {
        cout<<"key > v.key"<<endl;
        split(v->right, key, lefttree, righttree);
        //lefttree = AVLMergeWithRoot(v->left, lefttree, v);
        lefttree = merge(v->left, lefttree);
    }
}

int main()
{
    int n, key,key2, lastsum=0;
    char cmd;
    cin >> n;
    AVLTree<int> tree;
    while(n--)
    {
        cin >> cmd;
        switch(cmd)
        {
        case '?':
            cin >> key;
            if(tree.findNode(f(key,lastsum))) cout<<"Found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        case '+':
            cin >> key;
            tree.add(f(key, lastsum));
            break;
        case '-':
            cin >> key;
            tree.remove(f(key,lastsum));
            break;
        case 'd':
            printout(tree.getRoot());
            break;
        case 'c':
        {
            AVLTree<int> tree2;
            int a;
            for(int i=0; i<3; i++)
            {
                cin >> a;
                tree2.add(a);
            }
            Node * n = tree.AVLMergeWithRoot(tree.getRoot(), tree2.getRoot(), tree.getRoot());
            printout(tree.getRoot());
            break;
        }
        case 's':
            cin >> key >> key2;
            Node *left;// = new Node();
            Node *right;// = new Node();

//            NodePair par = splitBST(tree.getRoot(), key);
//            printout(par.left);
//            cout<<endl;
//            printout(par.right);
            tree.split(tree.getRoot(),key, left, right);
            cout<<"LEFT = "<<left->getKey() <<" Right = "<<right->getKey()<< endl;
//            Node *left2;// = new Node();
//            Node *right2;// = new Node();
//            wasfound = false;
//            tree.split(right, key2, left2, right2, wasfound );
//            cout << "SUM KEY = " << left2->getKey()<<" "<< left2->sum << endl;
            break;
        }
    }
    return 0;
}














