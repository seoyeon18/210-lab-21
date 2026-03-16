#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20 ;

class Goat {
private:
    int age;
    string name;
    string color;

public:
    static const int SIZE = 15;
    static string names[SIZE];
    static string colors[SIZE];

    Goat() {
        age = rand() % 20 + 1;
        name = names[rand() % SIZE];
        color = colors[rand() % SIZE];
    }

    Goat(int a, string n, string c){
        age = a;
        name = n;
        color =c ;
    }

    int getAge() const{
         return age;
    }
    string getName() const {
        return name;
    }
    string getColor() const {
        return color;
    }
};

//Add Goat class w random and parameter constructor!

string Goat::names[Goat::SIZE] = {
    "Junior", "Milo", "Daisy", "Pepper", "Coco",
    "Bandit", "Luna", "Rocky", "Hazel", "Scout",
    "Senior", "Godlike", "Old", "Mature", "Teen"
};

string Goat::colors[Goat::SIZE] = {
    "Red", "Blue", "Green", "Yellow", "Gold",
    "White", "Black", "Brown", "Gray", "Orange",
    "Silver", "Purple", "Pink", "Mauve", "Tan"
};



class DoublyLinkedList
{
private:
    struct Node
    {
        Goat data;
        Node *prev;
        Node *next;
        Node(Goat val, Node *p = nullptr, Node *n = nullptr)
        {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node *head;
    Node *tail;

public:
    // constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push_back(Goat  value)
    {
        Node *newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(Goat value)
    {
        Node *newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void print()
    {
        Node *current = head;
        if (!current){
            cout << "List is empty" << endl;
        return;
        }
        while (current)
        {
            cout << "    " << current->data.getName()
             << " (" << current->data.getColor()
             << ", " << current->data.getAge() << ")" << endl;
            current = current->next;
        }

    }
    void print_reverse()
    {
        Node *current = tail;
        if (!current) {
        cout << "List is empty" << endl;
        return;
    }
        while (current)
        {
            cout << "    " << current->data.getName()
             << " (" << current->data.getColor()
             << ", " << current->data.getAge() << ")" << endl;
            current = current->prev;
        }
    
    }
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};
// Driver program
int main()
{
    srand(time(0));

    DoublyLinkedList list;

    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i) {
        Goat g;
        list.push_back(g);
    }
       
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();
    
    return 0;
}
