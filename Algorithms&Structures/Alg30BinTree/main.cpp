#include <iostream>
#include <vector>
#include <limits.h>
#include <limits>

using namespace std;

struct node
{
    long long key;
    node *left;
    node *right;
};

int isBST(node *root, long long min, long long max)
{
    if(root == nullptr) return 1;
    cout<<"key = "<<root->key<<" min="<<min<<" max="<<max<<endl;
    if( (root->key < min) || (root->key >max)) return 0;
    return isBST(root->left, min, root->key-1) &&
            isBST(root->right, root->key, max);
}

int main()
{

    cout<<sizeof(long long)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<numeric_limits<long double>::infinity();
    int n, l, r;
    cin >> n;
    vector<node> tree(n);
    for(auto & var: tree)
    {
        cin >> var.key >> l >> r;
        if(l == -1) var.left = nullptr;
        else var.left = &tree[l];
        if(r == -1) var.right=nullptr;
        else var.right= &tree[r];
    }
    if(isBST(&tree[0],LONG_MIN, LONG_MAX)) cout<<"CORRECT"<<endl;
    else cout<<"INCORRECT"<<endl;
    return 0;
}
