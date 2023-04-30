#pragma once
using namespace std;

struct node
{
    int beg;
    int end;
    node* next;
};

class queue
{
    private:
        node* head;
        node* tail;
        int size;
    public:
        queue();
        void enqueue(int, int);
        void dequeue();
        void print();
        void printToFile(ofstream&);
        bool isEmpty() {return size == 0;}
        node* getHead() {return head;}
};

void queue::printToFile(ofstream& fout)
{
    node* temp = head;
    while(temp != nullptr)
    {
        fout << temp->beg << " ";
        temp = temp->next;
    }
}

queue::queue()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void queue::enqueue(int beg, int end)
{
    node* temp = new node;
    temp->beg = beg;
    temp->end = end;
    temp->next = nullptr;
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

void queue::dequeue()
{
    if(head == nullptr)
    {
        return;
    }
    else
    {
        node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void queue::print()
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->beg << " " << temp->end << endl;
        temp = temp->next;
    }
}