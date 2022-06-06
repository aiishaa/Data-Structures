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
    TreeNode *insert(TreeNode *root, int data) {
        if(root == NULL){
            root = new TreeNode(data);
            return root;
        }
        TreeNode* temp = root;
        if(data < temp->val){
            insert(temp->left, data);
            if(temp->left == NULL){
                temp->left = new TreeNode(data);
            }
        }
        else{
            insert(temp->right, data);
            if(temp->right == NULL){
                temp->right = new TreeNode(data);
            }
        }
        return root;
    }
};

int inorder(TreeNode *root, int k, int &counter){
    // Base cases
    int sum;

	if (counter > k)
		return 0;
    if(root!= NULL){
    sum = inorder(root->left, k, counter);
    if (counter >= k)
		return sum;

    sum += root->val;
    counter++;

    if(counter == k)
        return sum;

    sum += inorder(root->right, k, counter);
    }
    return sum;
}

int sum(TreeNode *root, int k){
    int counter = 0;
    int sum = inorder(root, k, counter);
    return sum;

}
int main()
{
    /*          TEST CASE 1         */
    // Creating a tree.
    TreeNode* root = NULL;
    int arr[] = { 20, 8, 22, 4, 12, 10, 14 };

    for (int x : arr)
        root = root->insert(root, x);

    cout << "sum = " << sum(root, 2) << endl;


    /*          TEST CASE 2         */
    // Creating a tree.
    root = NULL;
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    for (int x : arr2)
        root = root->insert(root, x);

    cout << "sum = " << sum(root, 3) << endl;


    /*          TEST CASE 3         */
    // Creating a tree.
    root = NULL;
    int arr3[] =  {54, 52, 51, 49, 75, 74, 85};

    for (int x : arr3)
        root = root->insert(root, x);

    cout << "sum = " << sum(root, 15) << endl;

    /*          TEST CASE 4         */
    // Creating a tree.
    root = NULL;
    int arr4[] = {100, 80};

    for (int x : arr4)
        root = root->insert(root, x);

    cout << "sum = " << sum(root, 1) << endl;


    /*          TEST CASE 5         */
    // Creating a tree.
    root = NULL;
    int arr5[] = {10, 9, 8, 7, 6, 5, 4};

    for (int x : arr5)
        root = root->insert(root, x);

    cout << "sum = " << sum(root, 3) << endl;
    return 0;
}
