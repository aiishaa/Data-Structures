#include <iostream>

using namespace std;

int findItem(string s, int key){
    for(int i = 0; i < s.length(); i++){
        if(key == s[i]){
            return i;
        }
    }
    return -1;
}

void printPostOrder(string preorder, string inorder){
    if(preorder.length() == 0 || inorder.length() == 0)
        return;

    int root = findItem(inorder, preorder[0]);

    if(inorder.size() == 1){
        cout << preorder[0] << " ";
        return;
    }

    printPostOrder(preorder.substr(1), inorder.substr(0, root));

    printPostOrder(preorder.substr(root + 1), inorder.substr(root + 1));

    //cout << preorder[0] << " ";
}

int main()
{
    printPostOrder("ABFGC", "FBGAC");
    cout << endl;
    printPostOrder("ABDECFG", "DBEAFCG");
    cout << endl;
    printPostOrder("abdgheicfj", "gdhbeiafjc");
    cout << endl;
    printPostOrder("BAC","ABC");
    cout << endl;
    printPostOrder("BA", "AB");
    cout << endl;
    return 0;
}
