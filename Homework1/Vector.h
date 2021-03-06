//
// Created by;
// Batuhan Faik Derinbay 
// 150180705
// on 3/17/19.
//
#ifndef OOP_HW1_VECTOR_H
#define OOP_HW1_VECTOR_H

#include <iostream>
using namespace std;

class Vector {
    int size;
    float* value_array;
public:
    // Default constructor
    Vector():size(0),value_array(nullptr){}

    // Constructor
    Vector(int size,const float * value_arr):size(size) {
        // Allocate memory
        value_array = new float[size];

        // Copy values of the array
        for (int i = 0; i < size; ++i) {
            value_array[i] = value_arr[i];
        }
    }

    // Copy constructor
    Vector(const Vector& vector_in) {
        size = vector_in.size;
        // Allocate memory for the new array
        value_array = new float[size];
        // Copy the values over
        for (int i = 0; i < size; ++i) {
            value_array[i] = vector_in.value_array[i];
        }
    }

    // Getter methods
    int getSize() const{
        return size;
    }
    float getValueArray(int i) const{
        return value_array[i];
    }

    // Operator overload +
    Vector operator+(const Vector& vector_in) const{
        // If sizes match
        if (size == vector_in.size){
            float* new_value_array;
            new_value_array = new float[size];
            // Do the addition
            for (int i = 0; i < size; ++i) {
                new_value_array[i] = value_array[i] + vector_in.value_array[i];
            }
            // Return the resulting vector
            return Vector(size, new_value_array);
        // If sizes don't match
        } else {
            cout << "Vector sizes don't match" << endl;
            // Return an empty vector
            return Vector(0,nullptr);
        }
    }

    // Operator overload * (Dot product)
    float operator*(const Vector& vector_in) const{
        // If sizes match
        if (size == vector_in.size){
            // Do the addition
            float sum = 0;
            for (int i = 0; i < size; ++i) {
                sum += value_array[i] * vector_in.value_array[i];
            }
            // Return the resulting vector
            return sum;
        // If sizes don't match
        } else {
            cout << "Vector sizes don't match" << endl;
            // Return 0
            return 0;
        }
    }

    // Operator overload * (Scalar multiplication)
    Vector operator*(const float scalar) const{
        // Create a new value array
        float* new_value_array;
        new_value_array = new float[size];
        // Multiply values by the scalar
        for (int i = 0; i < size; ++i) {
            new_value_array[i] = value_array[i]*scalar;
        }
        // Return the new vector
        return Vector(size, new_value_array);
    }

    // Operator overload <<
    friend ostream& operator<<(ostream& stream, const Vector& vector_in){
        vector_in.print();
        return stream;
    }

    // Print function
    const void print() const{
        cout << "(";
        for (int i = 0; i < (size - 1); ++i) {
            cout << value_array[i] << ", ";
        }
        cout << value_array[size - 1] << ")" << endl;
    }

    // Destructor
    ~Vector(){
//        delete [] value_array;
    }
};


#endif //OOP_HW1_VECTOR_H
