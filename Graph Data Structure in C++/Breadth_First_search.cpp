#include <bits/stdc++.h>
using namespace std;

struct SampleQueue
{
    int size;
    int frontpointer;
    int rearPointer;
    int *ptr; // for allocating the dynamic Memory and to store the address for the particular element in the queue.
};

void createQueue(SampleQueue *Q)
{
    Q->ptr = new int[Q->size];
}

void display_Queue(SampleQueue *Q)
{

    for (int i = Q->frontpointer; i <= Q->rearPointer; i++)
    {
        cout << Q->ptr[i]; // this is used to display the function.
        if (i == Q->rearPointer)
        {
            cout << " ";
        }
        else
        {
            cout << ",";
        }
    }
}

bool isEmpty(SampleQueue *ptr)
{
    if (ptr->frontpointer > ptr->rearPointer)
    {
        return true;
    }
    return false;
}

bool isFull(SampleQueue *ptr)
{
    if (ptr->rearPointer == ptr->size)
    {
        return true;
    }
    return false;
}
void enqueue(SampleQueue *Q, int value)
{
    if (isFull(Q))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    else
    {

        if (Q->frontpointer == -1 && Q->rearPointer == -1)
        {
            Q->frontpointer = Q->rearPointer = 0;
            Q->ptr[Q->rearPointer] = value;
        }
        else
        {
            Q->rearPointer++;
            Q->ptr[Q->rearPointer] = value;
        }
    }
}

int dequeue(SampleQueue *Q)
{
    int value;
    if (isEmpty(Q))
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    value = Q->ptr[Q->frontpointer];
    Q->frontpointer++;
    return value;
}

int main()
{
    int i = 2;
    int node;
    SampleQueue Q;
    Q.size = 7;
    Q.frontpointer = -1;
    Q.rearPointer = -1;
    createQueue(&Q);
    enqueue(&Q, i);
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // for getting the visited  node in the BFS
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}}; // intializing  the 2D Array for the graph etc.

    cout << i<<" ";      // the node which is visited is i
    visited[i] = 1; // Then we have make value for the visited which is 1 when the node is visited etc.
    enqueue(&Q, i); // Enqueue i for exploration.
    while (!isEmpty(&Q))
    {
        int node = dequeue(&Q); // the values are dequeue for the exploration
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(&Q, j);
            }
        }
    }
}
