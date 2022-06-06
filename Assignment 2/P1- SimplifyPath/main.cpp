#include <iostream>

using namespace std;

const int Max_Size = 1000;
class Stack{
private:
    int top;
    string Elements[Max_Size];
public:
    Stack():top(-1){};
    void push(string value){
        if(top >= Max_Size-1)   {cout << "Stack full on push" << endl; return;}
        Elements[++top] = value;
    }
    string pop(){
        int value;
        if(top == -1){
            return "The stack is empty";
        }
        value = top;
        top--;
        return Elements[value];
    }

    string getTop(){
        if(top == -1){
            return "The stack is empty";
        }
        return Elements[top];
    }

    int getSize(){
        return top+1;
    }

};

class Solution {
private:
    Stack s;
public:
    string simplifyPath(string path) {
        string res;

        for(int i = 0;  i < path.length(); i++)
        {
            if(path[i] == '/')
                continue;

            string temp;
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(s.getSize() > 0)
                    s.pop();
            }
            else
                s.push(temp);
        }

        while(s.getSize() > 0)
        {
            res = "/" + s.getTop() + res;
            s.pop();
        }

        if(res.size() == 0)
            return "/";

        return res;
    }
};
int main()
{
    cout << "Test case 1" << endl;
    Solution s1;
    cout << s1.simplifyPath("////////home/////") << endl;

    cout << "---------------------------------------------------\n";
    cout << "Test case 2" << endl;
    Solution s2;
    cout << s2.simplifyPath("/../") << endl;

    cout << "---------------------------------------------------\n";
    cout << "Test case 3" << endl;
    Solution s3;
    cout << s3.simplifyPath("/a/./b/../../c/") << endl;

    cout << "---------------------------------------------------\n";
    cout << "Test case 4" << endl;
    Solution s4;
    cout << s4.simplifyPath("/a/./b/./c/./d/") << endl;

    cout << "---------------------------------------------------\n";
    cout << "Test case 5" << endl;
    Solution s5;
    cout << s5.simplifyPath("/.././///home//foo/") << endl;

    cout << "---------------------------------------------------\n";
    Solution s6;
    string s;
    cout << "Enter your absolute path: " << endl;
    cin >> s;
    cout << s6.simplifyPath(s) << endl;
    return 0;
}
