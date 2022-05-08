#include <iostream>
#include <set>
using namespace std;

set<string> permutations;

void print(set<string> const &list)
{
    for (auto const &i: list) {
        cout << i << endl;
    }
}

void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        permutations.insert(soFar);

    else{ // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            // cout << rest << endl;
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}

// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}

int main()
{
    string word = "AaaA";
    ListPermutations(word);
    print(permutations);
    return 0;
}
