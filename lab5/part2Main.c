#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern int heapDelete();
extern int heapSize();
extern void addHeap(int);
extern void printXML();

int main(int argc, char * argv[])
{
    int value;
    // Read values from the input and add them to the heap
    while (scanf("%d\n", &value) != EOF) {
        fprintf(stderr, "READING INPUT: %d\n", value);
        // Add the value to the heap
        addHeap(value);
    }

    // Print the XML representation of the heap
    printXML();
    printf("\n");

    // Delete items from the heap, print them, and push onto the stack
    while (heapSize() > 0) {
        int deleted = heapDelete();
        printf("%d\n", deleted);
        push(deleted);
    }

    // Pop items from the stack and print them
    while (!isEmpty()) {
        printf("%d\n", pop());
    }

    exit(0);
}