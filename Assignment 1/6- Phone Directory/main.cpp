#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Contact{
private:
    string firstName;
    string lastName;
    string phoneNumber;
public:
    Contact(){}

    string getFirstName(){
        return firstName;
    }

    string getlastName(){
        return lastName;
    }

    string getPhoneNumber(){
        return phoneNumber;
    }

    void addContact(string firstname, string lastname, string number) {
        this->firstName = firstname;
        this->lastName = lastname;
        this->phoneNumber = number;
        cout << "New Entry has been added successfully.\n" << endl;
    }

    friend ostream& operator<<(ostream& out, Contact &contact){
        out << contact.getFirstName() << " " << contact.getlastName() << " " << contact.getPhoneNumber() << endl;
        return out;
    }

    ~Contact(){}

};
class PhoneDirectory{
private:
    vector<Contact> contacts;
public:
    PhoneDirectory(){}
    void addNewEntry(string firstname, string lastname, string number) {
        if (firstname.empty())
            throw "First name cannot be null";
        if (lastname.empty())
            throw "Last name cannot be null";
        if (number.empty())
            throw "Phone number cannot be null";
        if (LookUByNumber(number))
            throw "phoneNumber already exists";
        Contact contact;
        contact.addContact(firstname, lastname, number);
        contacts.push_back(contact);
      }

    void PrintDetails(){
        for (int i = 0; i < contacts.size(); i++) {
            cout << contacts[i].getFirstName() << " " << contacts[i].getlastName()
            << " " << contacts[i].getPhoneNumber() << endl;
        }
        cout << endl;
    }

    int getContact(string firstname){
        for (int i = 0; i < contacts.size(); i++) {
            if(contacts[i].getFirstName() == firstname){
                return i;
            }
        }
        return -1;
    }

    void DelByFirstName(string firstname){
        int index = getContact(firstname);
        if(index == -1){
            cout << "this name isn't in the directory.\n" << endl;
        }
        else{
            contacts.erase(contacts.begin()+index);
            cout << endl << "the entry has been deleted successfully.\n" << endl;
            cout << "Contacts after deleting: " << endl;
            PrintDetails();
        }
    }

    void InsertionSort(vector<Contact> vec, int size){
        auto start = chrono::steady_clock::now();
        for(int i = 1; i < size; i++){
            Contact temp = vec[i];
            int j = i;
            for(; j > 0 && vec[j-1].getFirstName() > temp.getFirstName(); j--){
                vec[j] = vec[j-1];
            }
            vec[j] = temp;
        }
        auto end = chrono::steady_clock::now();
        cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

        cout << "After using Insertion sort: " << endl;
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i];
        }
    }

    void SelectionSort(vector<Contact> vec, int size){
        auto start = chrono::steady_clock::now();
        for(int i = 0; i < size-1; i++){
            int least = i;
            for(int j = i+1; j < size; j++){
                if(vec[j].getFirstName() < vec[least].getFirstName()){
                    least = j;
                }
            }
            swap(vec[least], vec[i]);
        }
        auto end = chrono::steady_clock::now();

        cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

        cout << "After using Selection sort: " << endl;
        for(int i = 0; i < size; i++){
            cout << vec[i];
        }
    }

    void BubbleSort(vector<Contact> arr, int n){
        auto start = chrono::steady_clock::now();
        for(int i = 0; i < n-1; i++){
            for (int j = 1; j < n-i; j++){
                if(arr[j].getFirstName() < arr[j-1].getFirstName()){
                    swap(arr[j], arr[j-1]);
                }
            }
        }
        auto end = chrono::steady_clock::now();
        cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

        cout << "After using Bubble sort: " << endl;
        for(int i = 0; i < n; i++){
            cout << arr[i];
        }
    }

    void ListAlphByFirst(){
        srand(time(0));
        int ran = rand() % 3 + 1;
        cout << "rand = " << ran << endl;
        int n = contacts.size();
        if(ran == 1)
            //Apply Insertion sort
            InsertionSort(contacts, n);

        else if(ran == 2)
            //Apply Selection sort
            SelectionSort(contacts, n);

        else if(ran == 3)
            //Apply Bubble sort
            BubbleSort(contacts, n);
    }

    bool LookUByFirst(string firstname){
        int index = getContact(firstname);
        if(index == -1)  {return false;}
        else{
            cout << contacts[index].getFirstName() << " " << contacts[index].getlastName()
                << " " << contacts[index].getPhoneNumber() << endl;
                return true;
        }
    }

    bool LookUByNumber(string phonenumber){
        for(int i = 0; i < contacts.size(); i++){
            if(contacts[i].getPhoneNumber() == phonenumber){
                cout << contacts[i].getFirstName() << " " << contacts[i].getlastName()
                << " " << contacts[i].getPhoneNumber() << endl;
                return true;
            }
        }
        return false;
    }
};
int main()
{
    PhoneDirectory dir;
    string firstName;
    string lastName;
    string phoneNumber;
    int option;
    while(true){
        cout << "Enter your option.\n" <<
        "1. Add an entry to the directory.\n" <<
        "2. Look up a phone number.\n" <<
        "3. Look up by first name.\n" <<
        "4. Delete an entry from the directory.\n" <<
        "5. List All entries in phone directory.\n" <<
        "6. Exit form this program" << endl;

        cin >> option;
        switch(option){
        case 1:
            {
                cout << "------------------------------------------------------.\n";
                cout << "Enter the first name:\n";
                cin >> firstName;
                cout << "Enter the last name:\n";
                cin >> lastName;
                cout << "Enter the phone number:\n";
                cin >> phoneNumber;
                dir.addNewEntry(firstName, lastName, phoneNumber);
                cout << "------------------------------------------------------.\n";
                break;
            }
        case 2:
            {
                cout << "------------------------------------------------------.\n";
                cout << "Enter the phone number:\n";
                cin >> phoneNumber;
                bool look = dir.LookUByNumber(phoneNumber);
                if(look == false) cout << "This phone number isn't in directory.\n";
                cout << "------------------------------------------------------.\n";
                break;
            }
        case 3:
            {
                cout << "------------------------------------------------------.\n";
                cout << "Enter the name:\n";
                cin >> firstName;
                bool look = dir.LookUByFirst(firstName);
                if(look == false) cout << "This name isn't in directory.\n";
                cout << "------------------------------------------------------.\n";
                break;
            }
        case 4:
            {
                cout << "------------------------------------------------------.\n";
                cout << "Enter the name:\n";
                cin >> firstName;
                dir.DelByFirstName(firstName);
                cout << "------------------------------------------------------.\n";
                break;
            }
        case 5:
            {
                cout << "------------------------------------------------------.\n";
                dir.ListAlphByFirst();
                cout << "------------------------------------------------------.\n";
                break;
            }
        case 6:
            exit(1);
        }

    }
    return 0;
}
