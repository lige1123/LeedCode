/*************************************************************************
	> File Name: Leetcode_225.cpp
	> Author: zhangze
	> Mail: zhangze_8_8sina.com
	> Created Time: Fri 28 Feb 2020 05:35:06 PM CST
 ************************************************************************/


#includtruct MyQueue {
    int *data;
    int head, tail;
    int size, cnt;
} MyQueue;

MyQueue *MyQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = 0;
    q->tail = -1;
    q->cnt = 0;
    q->size = size;
    return q;
}

void MyQueuePush(MyQueue *q, int x) {
    if (q == NULL) return;
    if (q->cnt == q->size) return;
    if(++(q->tail) == q->size) q->tail == 0;
    q->data[q->tail] = x;
    q->cnt++;
}


int MyQueuePop(MyQueue *q) {
    if (q->cnt == 0) return 0;
    int element = q->data[q->head];
    q->head++;
    q->cnt--;
    if (q->head == q->size) q->head %= (q->size);
    return element;
}


int MyQueueFront(MyQueue *q) {
    return q->data[q->head];
}

bool MyQueueEmpty(MyQueue *q) {
    return q->cnt == 0;
}

void MyQueueFree(MyQueue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
}


typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = MyQueueCreate(size);
    s->q2 = MyQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj == NULL) return ;
    if (obj->q2->cnt == obj->q2->size) return ;
    MyQueuePush(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyQueue *p = obj->q1->cnt ? obj->q1 : obj->q2;
    MyQueue *q = obj->q1->cnt ? obj->q2 : obj->q1;
    int element = -1;
    if (p->cnt == 1) element =  MyQueuePop(p);
    while (!MyQueueEmpty(p)) {
        MyQueuePush(q, MyQueuePop(p));
        if (p->cnt == 1) element = MyQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = obj->q1->cnt ? obj->q1 : obj->q2;
    MyQueue *q = obj->q1->cnt ? obj->q2 : obj->q1;
    int element = -1;
    if (p->cnt == 1) element =  MyQueueFront(p);
    while (!MyQueueEmpty(p)) {
        element = MyQueuePop(p);
        MyQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return MyQueueEmpty(obj->q1) && MyQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) return ;
    MyQueueFree(obj->q1);
    MyQueueFree(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/



