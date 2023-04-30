#pragma once
#include <iostream>
using namespace std;

struct node
{
    InCount data;
    node* next;
}

class queue
{
    private:
        node* front;
        node* rear;
        int count;
    public:
        queue();
        void enqueue(InCount);
        InCount dequeue();
}

queue::queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

void queue::enqueue(InCount item)
{
    node* temp = new node;
    temp->data = item;
    temp->next = nullptr;
    if(front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    count++;
}

InCount queue::dequeue()
{
    InCount item;
    if(front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return item;
    }
    else
    {
        node* temp = front;
        item = temp->data;
        front = front->next;
        delete temp;
        count--;
        return item;
    }
}


