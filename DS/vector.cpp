#include <iostream>


// Vector implementation
class Vector {  

    // Pointer to first element of array, actual number of elements stored, and total capacity
    int* data;
    int elements;
    int capacity;

    // Resize the array if original array is no longer large enough
    int resize() {

        // Double the size of the data array to make room for more elements
        this->capacity *= 2;

        // Create a new, larger array
        int* copy = new int[this->capacity]{0};

        // Copy the elements from the old array over
        for(int i=0; i<this->capacity/2; i++) {
            copy[i] = this->data[i];
        }

        // Set the array to the larger one and free memory from old array
        delete[] data;
        this->data = copy;
    }

    public:

    // Constructor
    Vector(int capacity = 100) {
        this->data = new int[capacity]{0};
        this->elements = 0;
        this->capacity = capacity;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }


    // Add an element / push_back
    void add(int value) {
        
        // Ensure the array does not need to resize to hold an additional element
        if (elements == capacity) {
            this->resize();
        }

        // Add the new element and increase the total number of elements logged to be stored in the array
        this->data[elements] = value;
        this->elements += 1;
    }


    // Pop an element
    void pop() {
        
        if (elements > 0) {
            this->data[elements-1] = 0;
        }

        this->elements -= 1;
    }


    // Get some element within the array at some index
    int get(int index) {

        if (index < elements) {
            return this->data[index];
        }
        
        return 0;
    }


    // Get the max capacity of the current array
    int getCapacity() {
        return this->capacity;
    }

    // Get the number of elements stored in the current array
    int getElements() {
        return this->elements;
    }

};





// Tests of the array implementation
int main() {

    Vector test(5);

    std::cout << test.getCapacity() << "\n";
    std::cout << test.getElements() << "\n";
    std::cout << test.get(0) << "\n\n\n";

    test.add(0);
    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    test.add(5);
    test.add(6);
    test.add(7);
    test.add(8);
    test.add(9);

    std::cout << test.getCapacity() << "\n";
    std::cout << test.getElements() << "\n";
    std::cout << test.get(0) << "\n\n\n";

    test.add(10);

    std::cout << test.getCapacity() << "\n";
    std::cout << test.getElements() << "\n";
    std::cout << test.get(10) << "\n\n\n";

    return 0;
}
