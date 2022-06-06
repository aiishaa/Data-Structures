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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // write you code here
        if(p == NULL && q == NULL){
            return true;
        }
        else if( p && q && p->val == q->val){
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        }
        return false;
    }
};

int main()
{
    /*                      TEST CASE 1                 */
    // Creating a tree.
    TreeNode *root1;
    int arr1[3] = {1, 2, 1};
    root1 = root1->insert(arr1, 0, 3);

    // Creating a tree.
    TreeNode *root2;
    int arr2[3] = {1, 1, 2};
    root2 = root2->insert(arr2, 0, 3);

    Solution sol;
    if (sol.isSameTree(root1, root2)){
        cout<<"The trees are the same."<<endl;
    }
    else{
        cout<<"The trees are not the same."<<endl;
    }

    /*                      TEST CASE 2                 */
    // Creating a tree.
    root1 = NULL;
    int arr3[2] = {1, 2};
    root1 = root1->insert(arr3, 0, 2);
    // Creating a tree.
    root2 = NULL;
    int arr4[3] = {1, NULL, 2};
    root2 = root2->insert(arr4, 0, 3);


    if (sol.isSameTree(root1, root2)){
        cout<<"The trees are the same."<<endl;
    }
    else{
        cout<<"The trees are not the same."<<endl;
    }


    /*                      TEST CASE 3                 */

    // Creating a tree.
    root1 = NULL;
    int arr5[5] = {1, 2, 5, 63, 4};
    root1 = root1->insert(arr5, 0, 5);

    // Creating a tree.
    root2 = NULL;
    int arr6[5] = {1, 2, 5, 63, 4};
    root2 = root2->insert(arr6, 0, 5);


    if (sol.isSameTree(root1, root2)){
        cout<<"The trees are the same."<<endl;
    }
    else{
        cout<<"The trees are not the same."<<endl;
    }


    /*                      TEST CASE 4                 */

    // Creating a tree.
    root1 = NULL;
    int arr7[8] = {1, 3, 3, 6, 3, 7, 2, 8};
    root1 = root1->insert(arr7, 0, 8);

    // Creating a tree.
    root2 = NULL;
    int arr8[8] = {1, 3, 3, 6, 3, 7, 2, 8};
    root2 = root2->insert(arr8, 0, 8);


    if (sol.isSameTree(root1, root2)){
        cout<<"The trees are the same."<<endl;
    }
    else{
        cout<<"The trees are not the same."<<endl;
    }


    /*                      TEST CASE 5                 */

    // Creating a tree.
    root1 = NULL;
    int arr9[7] = {1, 2, 2, 3, 4, 4, 3};
    root1 = root1->insert(arr9, 0, 7);

    // Creating a tree.
    root2 = NULL;
    int arr[7] = {1, 2, 2, 4, 3, 4, 3};
    root2 = root2->insert(arr, 0, 7);


    if (sol.isSameTree(root1, root2)){
        cout << "The trees are the same." << endl;
    }
    else{
        cout << "The trees are not the same." << endl;
    }
    return 0;
}
