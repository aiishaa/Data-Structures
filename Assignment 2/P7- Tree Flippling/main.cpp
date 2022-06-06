#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

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
};

class Solution {
public:
    TreeNode* flipTree(TreeNode* p) {
        // write you code here
        if(p == NULL){
            return NULL;
        }
        flipTree(p->left);
        flipTree(p->right);
        TreeNode* node = p->left;
        p->left = p->right;
        p->right = node;
        return p;
    }

    void printInOrder(TreeNode* p){
        if(p == NULL)
            return;
        printInOrder(p->left);
        cout << p->val << " ";
        printInOrder(p->right);
    }
};

int main()
{

    /*              TEST CASE 1             */
    Solution sol;
    TreeNode *root;
    int arr[5] = {3, 1, 5, 2, 4};
    root = root->insert(arr, 0, 5);

    sol.flipTree(root);
    sol.printInOrder(root->left);
    cout << endl;


    /*              TEST CASE 2             */
    root = NULL;
    int arr1[7] = {1, 2, 3, 4, 5, 6, 7};
    root = root->insert(arr1, 0, 7);

    sol.flipTree(root);
    sol.printInOrder(root);
    cout << endl;


    /*              TEST CASE 3             */
    root = NULL;
    int arr2[5] = {1, 2, 3, 4, 5};
    root = root->insert(arr2, 0, 5);

    sol.flipTree(root);
    sol.printInOrder(root);
    cout << endl;


    /*              TEST CASE 4             */
    root = NULL;
    int arr3[3] = {1, 2, 3};
    root = root->insert(arr3, 0, 3);

    sol.flipTree(root->left);
    sol.printInOrder(root);
    cout << endl;


    /*              TEST CASE 5             */
    root = NULL;
    int arr4[9] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    root = root->insert(arr4, 0, 9);

    sol.flipTree(root);
    sol.printInOrder(root);
    cout << endl;
    return 0;
}
