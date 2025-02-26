#include <iostream>

int Static[101];

int memcheckFailDemo(int* arrayStack, unsigned int arrayStackLen, 
                     int* arrayHeap, unsigned int arrayHeapLen) {
    int Stack[101];

    // Safe accesses
    Static[100] = 0; 
    Stack[100] = 0;  

    for (int i = 0; i < 5; i++) Stack[i] = 0;  // Corrected loop range

    // Fix: Ensure heap allocation is used correctly
    int* array = new int[5];
    for (int i = 0; i < 5; i++) array[i] = 0;  // Prevent out-of-bounds

    // Fix: Only access valid indices in arrayStack
    if (arrayStackLen > 100) {
        std::cerr << "Error: arrayStackLen too large!" << std::endl;
    } else {
        arrayStack[arrayStackLen - 1] = 0;  // Safe last element access
    }

    // Fix: Loop properly for arrayStack
    for (unsigned int i = 0; i < arrayStackLen; i++) {
        arrayStack[i] = 0;
    }

    // Fix: Loop properly for arrayHeap
    for (unsigned int i = 0; i < arrayHeapLen; i++) {
        arrayHeap[i] = 0;
    }

    delete[] array;  // Free allocated memory

    return 0;
}

int main(void) {
    int arrayStack[5];
    int* arrayHeap = new int[5];

    memcheckFailDemo(arrayStack, 5, arrayHeap, 5);

    delete[] arrayHeap;  // Free allocated memory

    return 0;
}
