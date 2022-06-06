#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class TreeNode
{
    public:
        char data;
        TreeNode *left, *right;
        TreeNode(char data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class Stack
{
    public:
        TreeNode *treeNode;
        Stack *next;
        Stack(TreeNode *treeNode)
        {
            this->treeNode = treeNode;
            next = NULL;
        }
};


class ExpressionTree
{
    private:
        Stack *top;
    public:
        ExpressionTree()
        {
            top = NULL;
        }


        void clear()
        {
            top = NULL;
        }


        void push(TreeNode *ptr)
        {
            if (top == NULL)
                top = new Stack(ptr);
            else
            {
                Stack *temp = new Stack(ptr);
                temp->next = top;
                top = temp;
            }
        }

        TreeNode *pop()
        {
            if (top == NULL)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                TreeNode *temp = top->treeNode;
                top = top->next;
                return temp;
            }
        }

        TreeNode *getTop()
        {
            return top->treeNode;
        }

        void insert(char val)
        {
            if (isdigit(val))
            {
                TreeNode *nptr = new TreeNode(val);
                push(nptr);
            }
            else if (isOperator(val))
            {
                TreeNode *nptr = new TreeNode(val);
                nptr->left = pop();
                nptr->right = pop();
                //cout << nptr->left->data << " " << nptr->right->data << endl;
                push(nptr);
            }
            else
            {
                cout<<"Invalid Expression"<<endl;
                return;
            }
        }

        bool isOperator(char ch)
        {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }


        int toDigit(char ch)
        {
            return ch - '0';
        }


        void buildTree(string eqn)
        {
            for (int i = eqn.length() - 1; i >= 0; i--){
                if (eqn[i] == ' '){
                    continue;
                }
                insert(eqn[i]);
            }
        }


        double evaluate()
        {
            //cout << getTop()->data << endl;
            return evaluate(getTop());
        }


        double evaluate(TreeNode *ptr)
        {
            if (ptr->left == NULL && ptr->right == NULL)
                return toDigit(ptr->data);
            else
            {
                double result = 0.0;
                double left = evaluate(ptr->left);
                double right = evaluate(ptr->right);
                char op = ptr->data;
                switch (op)
                {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                default:
                    result = left + right;
                    break;
                }
                return result;
            }
        }

        void GetPrefix()
        {
            PrintPreOrder(getTop());
        }

        void PrintPreOrder(TreeNode *root)
        {
            if (root != NULL)
            {
                cout << root->data;
                PrintPreOrder(root->left);
                PrintPreOrder(root->right);
            }
        }

        void GetInfix()
        {
            PrintInOrder(getTop());
        }


        void PrintInOrder(TreeNode *root)
        {
            if (root != NULL)
            {
                PrintInOrder(root->left);
                cout << root->data;
                PrintInOrder(root->right);
            }
        }
};


int main()
{

    ExpressionTree et;
    string s1 = "-+7*45+20";
    et.buildTree(s1);
    cout << "\nPrefix  : ";
    et.GetPrefix();
    cout<<"\nInfix   : ";
    et.GetInfix();
    cout << "\nEvaluated Result : " << et.evaluate()<< endl; //25

    string s2 = "+3*4/82";
    et.buildTree(s2);
    cout << "\nPrefix  : ";
    et.GetPrefix();
    cout<<"\nInfix   : ";
    et.GetInfix();
    cout << "\nEvaluated Result : " << et.evaluate()<< endl; //19

    string s3 = "+-+7*/935/82*/625";
    et.buildTree(s3);
    cout << "\nPrefix  : ";
    et.GetPrefix();
    cout<<"\nInfix   : ";
    et.GetInfix();
    cout << "\nEvaluated Result : " << et.evaluate() << endl; //33

    string s4 = "+9*12";
    et.buildTree(s4);
    cout << "\nPrefix  : ";
    et.GetPrefix();
    cout<<"\nInfix   : ";
    et.GetInfix();
    cout << "\nEvaluated Result : " << et.evaluate() << endl; //11

    string s5 = "-+8/632";
    et.buildTree(s5);
    cout << "\nPrefix  : ";
    et.GetPrefix();
    cout<<"\nInfix   : ";
    et.GetInfix();
    cout << "\nEvaluated Result : " << et.evaluate() << endl; //8

    return 0;
}
