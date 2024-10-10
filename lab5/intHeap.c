#include <stdio.h>
// Declares a function to internally print the XML representation of the heap.
extern void internalPrintXML(int index);

// "size" keeps track of the number of elements in the heap.
// "heap" is an array that stores the elements of the heap.
static int size = 0;
static int heap[100];

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete() {
    // If the heap is empty, print an error message and return -1.
    if (size == 0) {
        fprintf(stderr, "Heap is empty\n");
        return -1;
    }
    
    // Store the maximum value (heap root) and replace the root with the last element in the heap.
    int max = heap[0];
    heap[0] = heap[--size];

    // Reheapify the heap (move the new root to the correct position).
    int index = 0;
    while (1) {
        // Calculate the indices of the left and right children.
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        // Find the largest value among the current node and its children.
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        // If the current node is the largest, stop reheapifying.
        if (largest == index) {
            break;
        }

        // Swap the current node with the largest child.
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // Move to the largest child's position and continue reheapifying.
        index = largest;
    }

    // Return the maximum value that was removed from the heap.
    return max;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add) {
    // If the heap is full, print an error message and return.
    if (size >= 100) {
        fprintf(stderr, "Heap overflow\n");
        return;
    }

    // Add the new element to the end of the heap.
    int index = size++;
    heap[index] = thing2add;

    // Shift up the new element until it is in the correct position.
    while (index > 0) {
        int parent = (index - 1) / 2;
        // If the parent is greater than or equal to the new element, the new element is in the correct position.
        if (heap[parent] >= heap[index]) {
            break;
        }

        // Swap the new element with its parent.
        int temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;

        // Move to the parent's position and continue sifting up.
        index = parent;
    }
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize() {
    return size;
}

// Recursively prints the XML representation of the heap starting at the given index.
void internalPrintXML(int index) {
    // If the index is greater or equal to the heap size, return.
    if (index >= heapSize()) {
        return;
    }

// Print the opening XML tag for the current node, including its value.
printf("<node id=\"%d\">", heap[index]);

// Recursively print the XML representation of the left and right children.
internalPrintXML(2 * index + 1);
internalPrintXML(2 * index + 2);

// Print the closing XML tag for the current node.
printf("</node>");
}

// Calls the internalPrintXML function with an initial index of 0
void printXML() {
internalPrintXML(0);
}
