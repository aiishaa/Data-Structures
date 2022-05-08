#include<iostream>
using namespace std;
# include<vector>
class songs
{
private:
   vector<string> sa;
    int size, left, right, middle;
public :
    songs(vector<string> sa)
    {
        size = sa.size();
        for(int i = 0; i < size; i++)
        {
            this->sa = sa;
        }
    }

    void insertion()
    {
        for (int i=1,j ; i<size ; i++)
        {
            string temp = sa[i];
            for (j=i ; j>0 && temp < sa[j-1] ; j--)
                sa [j] = sa[j-1];
            sa [j] = temp;
        }
    }

    void func(){
        int counter = 0;
        for(int i = 0; i < size; i++){
            for(int j = 1; j < size; j++){
                if(sa[j] == "untitled"){
                    string temp = sa[j];
                    sa[j] = sa[j-1];
                    sa[j-1] = temp;
                }
            }
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << sa[i] << endl;
        }
    }
};

int main()
{
    vector<string> s{"Papaoutai","Diamonds","Helwa ya baladi","untitled","Unstoppable","untitled"};
    songs song(s);
    song.insertion();
    song.func();
    song.print();
    return 0;
}
