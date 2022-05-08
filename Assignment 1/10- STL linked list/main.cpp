#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T>*next;
    Node<T>*prev;
    Node(){}
    Node(T data)
    {
        this->data = data;
    }
};
template <class T>
class Mylist
{
private:
    Node<T>*head;
    Node<T>*tail;
    int Size;
public:
    Mylist()
    {
        head = NULL;
        tail = NULL;
        Size = 0;
    }
    Mylist(T data, int Size)
    {
        this-> Size = Size;
        head = tail = new Node<T>(data);
        for (int i = 0; i < Size - 1; i++)
        {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head = newNode;
            head->next->prev = head;
        }
    }
    int size()
    {
        return Size;
    }
    void pushFirst(T data)
    {
        if (head == NULL)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        Size++;

    }
    void pushBack(T data)
    {
        if (head == NULL)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            Node<T>*newNode = new Node<T>(data);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        Size++;

    }
    ~Mylist()
    {
        Node<T>* temp; //pointer to delete the node
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        Size = 0;

    }
    Mylist<T>& operator = (Mylist<T> another_list)
    {
        Node<T>* temp = another_list.head;
        while (temp != NULL)
        {
            this->pushBack(temp->data);
            temp = temp->next;
        }
        return *this;

    }
    class Iterator
    {
        friend class Mylist;
    private:
        Node<T>*iter;
    public:
        Iterator(){}
        Iterator(Node<T>* iter)
        {
            this->iter = iter;
        }
        void operator++()
        {
            try{
            if (iter->next == nullptr)
            {
                throw "error";
            }


            }
    catch(const char *pointer){

        cout<<"error"<<endl;
        }
         iter = iter->next;
        }

        void operator++(int)
        {

            //modify it
            try{
            if (iter->next == nullptr)
            {
                throw "error";
            }
            }


        catch(const char *pointer){

        cout<<"error"<<endl;
        }
      iter = iter->next;
        }
        void operator--()
        {
            if (iter->prev == nullptr)
            {
                throw "out of Range \n";
            }
            iter = iter->prev;
        }

        T& operator *()
        {
            return iter->data;
        }
        bool operator == (const Iterator& it)
        {
            return ( iter == it.iter);
        }

    };
      friend class Iterator;
    void insert(T data,Iterator position)
    {
       if (position == head)
        {
			pushFirst(data);

		}
		//is it last index
		else if (position == tail)
		{
		    pushBack(data);

		}
		//is it between first and last index
		else
		{
			Node<T>* tmp = new Node<T>(data);
			tmp->prev = position.iter->prev;
			tmp->next = position.iter;
			position.iter->prev->next = tmp;
			position.iter->prev = tmp;
		}

		Size++;
    }
    Iterator erase(Iterator position)
    {
       //delete the first index
		if (position == head) {
			head = head->next;
			//free memory
			delete head->prev;
		}
		//delete the last element
		else if (position == tail)
        {

			pop();
			//throw"error";


        }
		//delete middle
		else
		{
			position.iter->prev->next = position.iter->next;
			position.iter->next->prev = position.iter->prev;
			delete position.iter;


		}
		Size--;
    }
    void pop()
    {
        Node<T> *current = new Node<T>;
        current = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete current;
        Size--;
    }
    Iterator begin()
    {
        return Iterator(this->head);
    }
    Iterator end()
    {
        return Iterator(this->tail);
    }
    void display()
    {
        Node<T> *tmp = new Node<T>;
        tmp = head;
        while(tmp != tail->next)
        {
            cout<< tmp->data <<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Mylist<int> List;
    List.pushBack(1);
    List.pushBack(2);
    List.pushBack(3);
    Mylist<int>::Iterator it = List.begin();
    cout << "move the iterator one step:" << endl;
    it++;
    cout << "iteraror = " << *it <<endl;
    cout << endl;
    cout << "After push back 1,2,3:" << endl;
    List.display();
    cout << "Size = "<<List.size() << endl;
    cout << endl;
    cout << "insert 6:" << endl;
    List.insert(6, it);
    List.display();
    cout << "Size = " << List.size() << endl;
    cout << endl;
    cout << "erase iterator:" << endl;
    List.erase(it);
    List.display();
    cout << "Size = " << List.size() << endl;
    cout << endl;
    cout << "push first 4,5:" << endl;
    List.pushFirst(4);
    List.pushFirst(5);
    ++it;
    List.display();
    cout << "Size = " << List.size() << endl;
    cout << endl;
    cout << "pop:" << endl;
    List.pop();
    List.display();
    cout << "Size = " << List.size() << endl;
    return 0;
}
