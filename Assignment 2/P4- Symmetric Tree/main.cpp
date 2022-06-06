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
    bool isSymmetric(TreeNode *root1, TreeNode *root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        else if(root1 == NULL || root2 == NULL){
            return false;
        }
        else if(root1->val == root2->val){
            return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        // write you code here
        if(root == NULL)
            return true;
        else
            return isSymmetric(root, root);
    }
};

int main()
{
    cout << "test case 1" << endl;
    // Creating a tree.
    int arr1[7] = {1, 3, 3, 4, 6, 6, 4};
    TreeNode *root;
    root = root->insert(arr1, 0, 7);
    //root->inOrder(root);
    Solution sol;
    if (sol.isSymmetric(root)){
        cout<<"The binary tree is symmetric."<<endl;
    }
    else{
        cout<<"The binary tree is asymmetric."<<endl;
    }


    cout << "---------------------------------------------\n";
    cout << "test case 2" << endl;
    // Creating a tree.
    int arr2[7] = {1, 2, 2, NULL, 3, NULL, 3};
    root = NULL;
    root = root->insert(arr2, 0, 7);
    Solution sol2;
    if (sol2.isSymmetric(root)){
        cout<<"The binary tree is symmetric."<<endl;
    }
    else{
        cout<<"The binary tree is asymmetric."<<endl;
    }


    cout << "---------------------------------------------\n";
    cout << "test case 3" << endl;
    // Creating a tree.
    root = NULL;
    int arr3[7] = {1, 2, 2, 3, 4, 4, 3};
    root = root->insert(arr3, 0, 7);
    Solution sol3;
    if (sol3.isSymmetric(root)){
        cout<<"The binary tree is symmetric."<<endl;
    }
    else{
        cout<<"The binary tree is asymmetric."<<endl;
    }


    cout << "---------------------------------------------\n";
    cout << "test case 4" << endl;
    // Creating a tree.
    root = NULL;
    int arr4[7] = {1, 3, 3, NULL, NULL, 6, 3};
    root = root->insert(arr4, 0, 7);
    Solution sol4;
    if (sol4.isSymmetric(root)){
        cout<<"The binary tree is symmetric."<<endl;
    }
    else{
        cout<<"The binary tree is asymmetric."<<endl;
    }


    cout << "---------------------------------------------\n";
    cout << "test case 5" << endl;
    // Creating a tree.
    root = NULL;
    int arr5[11] = {1, 2, 2, 3, 4, 4, 3, 7, 4, 3, 6};
    root = root->insert(arr5, 0, 11);
    // root5->inOrder(root5);
    Solution sol5;
    if (sol5.isSymmetric(root)){
        cout << "The binary tree is symmetric." << endl;
    }
    else{
        cout << "The binary tree is asymmetric." << endl;
    }

    return 0;
}
