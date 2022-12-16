#include <iostream>
#include <stack>
#define size 10
using namespace std;

struct queue {
    int items[size];
    int  front, rear;
};

void initialize(struct queue*);
int isfull(struct queue*);
void insert(struct queue*, int);
int isempty(struct queue*);
int remove(struct queue*);
void copyqueue(struct queue*, struct queue*);
void modifyqueue(struct queue*, struct queue*);
void reverse_queue(struct queue*);
void print(struct queue*);

int main() {
    struct queue test1;
    initialize(&test1);
    struct queue test2;
    initialize(&test2);
    int values = 0;

    for (int i = 1; i < size; i++) {
        cout << "Please Enter item no " << i << " you want to insert in your queue: ";
        cin >> values;
    }
    insert(&test1, values);
    cout << "These are the values in the first queue before copy: " << endl;
    print(&test1);
    cout << "These are the values in the second queue before copy: " << endl;
    print(&test2);
   /* copyqueue(&test1, &test2);
    cout<<"\nThese are the values in the first queue after copy: "<<endl;
       print(&test1);
    cout<<"\nThese are the values in the second queue after copy: "<<endl;
       print(&test2);
       */
    modifyqueue(&test1, &test2);
    cout << "These are the values in the first queue after modification: " << endl;
    print(&test1);
    cout << "These are the values in the second queue after modification: " << endl;
    print(&test2); 

    reverse_queue(&test1);
    cout << "These are the values of the first queue in reverse order: " << endl;
    print(&test1);

    system("PAUSE");
    return 0;
}

void initialize(struct queue* init) {
    init->front = init->rear = size - 1;
}

int isempty(struct queue* e) {
    if (e->front == e->rear)
        return 1;
    else
        return 0;
}

int isfull(struct queue* f) {
    if (f->rear == f->front)
        return 1;
    else
        return 0;
}

void insert(struct queue* in, int x){
    if (in->rear == size - 1)
        in->rear = 0;
    else
        (in->rear)++;
    if (isfull(in)) {
        cout << "Overflow: Queue is full";
        exit(1);
    }
    else
        in->items[in->rear] = x;
}

int remove(struct queue* rem){
    int val = 0;
    if (isempty(rem))
    {
        cout << "Underflow: Queue is Empty";
        exit(1);
    }
    else
    {
        if (rem->front == size - 1)
            rem->front = 0;
        else
            rem->front++;

        val = rem->items[rem->front];
        return val;
    }
}

void copyqueue(struct queue* src, struct queue* dest) {
    struct queue temp;
    initialize(&temp);

    int y = 0;

    while (!isempty(src)) {
        y = remove(src);
        insert(&temp, y);
    }
    while (!isempty(&temp)) {
        y = remove(&temp);
        insert(dest, y);
        insert(src, y);
    }
}

void print(struct queue* pr) {
    struct queue temp;
    initialize(&temp);
    int y=0;

    while (!isempty(pr)) {
        y = remove(pr);
        cout << y << ", ";
        insert(&temp, y);
    }
    while (!isempty(&temp)) {
        y = remove(&temp);
        insert(pr, y);
    }
    cout << endl <<endl;
}

void modifyqueue(struct queue* org, struct queue* mod) {
    struct queue temp;
    initialize(&temp);
    int z=0;

    while (!isempty(org)) {
        z = remove(org);
        insert(&temp, z);
        if (z >= 5) {
            z = 1;
            insert(mod, z);
        }
        else {
            z = 0;
            insert(mod, z);
        }
    }
    while (!isempty(&temp)) {
        z = remove(&temp);
        insert(org, z);
    }
}

void reverse_queue(struct queue* org) {
    stack<int> temp;
    int z=0;

    while (!isempty(org)) {
        z = remove(org);
        temp.push(z);
    }
    while (!temp.empty()) {
        z = temp.top();
        temp.pop();
        insert(org, z);
    }
}
