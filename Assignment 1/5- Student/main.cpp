#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StudentName{
private:
    string name;
public:
    StudentName(){}
    int cnt_space(string sentence){
        int count = 0;
        char ch = sentence[0];
        if(sentence == " "){
            return -1;
        }
        for (int i = 0; ch != '\0'; i++) {
            ch = sentence[i];
            if (isspace(ch))
                count++;
        }
        return (count);
    }

    StudentName(string name){
        int count = cnt_space(name);
        if(count == 0) {
            name += " " + name + " " + name;
        }
        else if(count == 1){
            int index = name.find(' ');
            string added = name.substr(index);
            name += added;
        }
        this->name = name;
    }

    string getName(){
        return this->name;
    }

    bool replace(int i, int j){
        stringstream oss;
        vector<string> splits;
        stringstream X(name);
        string word;
        while(getline(X, word, ' ')){
            splits.push_back(word);
        }

        if(i < 1 || i > splits.size() || j < 1  || j > splits.size()){
            return false;
        }
        else{

            swap(splits[i-1], splits[j-1]);
            if (!splits.empty()) {
                copy(splits.begin(), splits.end(), ostream_iterator<string>(oss, " "));
            }
            name = oss.str();
        }
        splits.clear();
        return true;
    }

    void print(){
        stringstream S(name);
        string word;
        while(getline(S, word, ' ')){
            cout << word << endl;
        }
        cout << endl;
    }


};
int main()
{
    // TO TEST MANUALLY
    //string name;
    //getline(cin, name);
    //cout << name << endl;


    cout << "test case 1" << endl;
    StudentName S1("Aisha Fathy Zaki");
    cout << "Your name is: \n";
    S1.print();
    bool check = S1.replace(1,2);
    assert(check == 1);
    cout << "After replace word 1 with 2 and vice versa\n";
    S1.print();

    cout << "test case 2" << endl;
    StudentName S2("Aisha");
    cout << "Your name is: \n";
    S2.print();
    check = S2.replace(1,2);
    if(check == 0) cout << "Index is out of range" << endl;
    cout << "After replace word 1 with 2 and vice versa\n";
    S2.print();

    cout << "test case 3" << endl;
    StudentName S3("Aisha Fathy");
    cout << "Your name is: \n";
    S3.print();
    check = S3.replace(3,1);
    if(check == 0) cout << "Index is out of range" << endl;
    cout << "After replace word 1 with 3 and vice versa\n";
    S3.print();

    cout << "test case 4" << endl;
    StudentName S4("Aisha Fathy");
    cout << "Your name is: \n";
    S4.print();
    check = S4.replace(1,4);
    if(check == 0) cout << "Index is out of range" << endl;
    S4.print();

    cout << "test case 5" << endl;
    StudentName S5("Hassan Ahmed Ali");
    cout << "Your name is: \n";
    S5.print();
    check = S5.replace(1,2);
    check = S5.replace(3,1);
    if(check == 0) cout << "Index is out of range" << endl;
    cout << "After replace word 1 with 2 and 3 with 1\n";
    S5.print();
    return 0;
}
