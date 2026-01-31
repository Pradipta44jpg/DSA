#include <string.h>
#include <stdlib.h>

int calPointsStack[1000];
int top = -1;

void push(int x) {
    calPointsStack[++top] = x;
}

int pop() {
    return calPointsStack[top--];
}

int calPoints(char **operations, int operationsSize) {

    top = -1;  // reset stack

    for (int i = 0; i < operationsSize; i++) {

        if (strcmp(operations[i], "+") == 0) {  
            int a = calPointsStack[top];
            int b = calPointsStack[top - 1];
            push(a + b);
        }

        else if (strcmp(operations[i], "D") == 0) {
            push(2 * calPointsStack[top]);
        }

        else if (strcmp(operations[i], "C") == 0) {
            pop();
        }

        else {
            // it's a number
            push(atoi(operations[i]));
        }
    }

    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += calPointsStack[i];
    }

    return sum;
}
