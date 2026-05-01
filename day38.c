#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// check empty
int empty() {
    return (front == -1);
}

// push front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    dq[front] = x;
}

// push back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

// pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// rear element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

// size
void size() {
    if (empty()) printf("0\n");
    else printf("%d\n", rear - front + 1);
}

// display
void display() {
    if (empty()) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int choice, x;

        /*
        1 push_front
        2 push_back
        3 pop_front
        4 pop_back
        5 front
        6 back
        7 size
        8 display
        */

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &x);
                push_front(x);
                break;
            case 2:
                scanf("%d", &x);
                push_back(x);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_back();
                break;
            case 5:
                get_front();
                break;
            case 6:
                get_back();
                break;
            case 7:
                size();
                break;
            case 8:
                display();
                break;
        }
    }

    return 0;
}