typedef struct {
    int arr[10005];
    int brr[10005];
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *a = (MinStack *)malloc(sizeof(MinStack));
    a->top = -1;
    return a;
}

void minStackPush(MinStack* obj, int x) {
    obj->arr[++obj->top] = x;
    if (obj->top == 0 || obj->arr[obj->top] < obj->brr[obj->top - 1]) {
        obj->brr[obj->top] = x;
    } else {
        obj->brr[obj->top] = obj->brr[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top < 0) return ;
    obj->top--;
}

int minStackTop(MinStack* obj) {
    if (obj->top < 0) return INT_MAX;
    return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->top < 0) return INT_MAX;
    return obj->brr[obj->top];
}

void minStackFree(MinStack* obj) {
  //  free(obj->arr);
  //  free(obj->brr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
