#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
    TreeNode* insert(int arr[], int i, int n){
        TreeNode *root = NULL;
        if (i < n)
        {
            root = new TreeNode(arr[i]);
            root->left = insert(arr, 2 * i + 1, n);
            root->right = insert(arr,2 * i + 2, n);
        }
        return root;
    }
    void inOrder(TreeNode *root)
    {
        if (root != NULL) {
            inOrder(root->left);
            cout << root->val << " ";
            inOrder(root->right);
        }
    }
};

class Solution {
public:
    bool isFoldable(TreeNode *root){
        if(root == NULL)
            return true;
        return isFoldable(root->left, root->right);
    }

    bool isFoldable(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        return(isFoldable(p->left, q->right) && isFoldable(p->right, q->left));
    }

};


int main()
{
    // Constructing a tree
    TreeNode* root1;
    Solution sol;
    int arr1[5] = {1, 2, 3, 4, 5};
    root1 = root1->insert(arr1, 0, 5);
    cout << (sol.isFoldable(root1) == 1 ? "tree is foldable" : "tree is not foldable") << endl;

    // Constructing a tree
    root1 = NULL;
    int arr2[7] = {1, 2, 3, 4, NULL, NULL, 5};
    root1 = root1->insert(arr1, 0, 7);
    cout << (sol.isFoldable(root1) == 1 ? "tree is foldable" : "tree is not foldable") << endl;

    // Constructing a tree
    root1 = NULL;
    int arr3[6] = {1, 2, 3, 4, 6, 5};
    root1 = root1->insert(arr3, 0, 6);
    cout << (sol.isFoldable(root1) == 1 ? "tree is foldable" : "tree is not foldable") << endl;

    // Constructing a tree
    root1 = new TreeNode(1);
    cout << (sol.isFoldable(root1) == 1 ? "tree is foldable" : "tree is not foldable") << endl;

    // Constructing a tree
    root1 = NULL;
    int arr4[6] = {1, 2, 3, 4, NULL, 5};
    root1 = root1->insert(arr4, 0, 6);
    cout << (sol.isFoldable(root1) == 1 ? "tree is foldable" : "tree is not foldable") << endl;

    return 0;
}
