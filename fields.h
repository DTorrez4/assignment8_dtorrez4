//class field that the other classes inharite since this is a base class.
#ifndef fields_h
#define fields_h
#include <iostream>
#include <cmath>
using namespace std;

class Field {
protected:
    double *value;


public:
    //default constructor
    Field() {
        value = new double[3]{0,0,0};
    }
    //constructor with values
    Field(double x , double y , double z) {
        value = new double[3]{x,y,z};
    }
    // deep copy of the constructor
    Field(const Field &other) {
        value = new double[3];
        for (int i = 0; i < 3; i++) {
            value[i] = other.value[i];
        }
    }
    //the virtual deconstructor.
    virtual ~Field() {
        delete[] value;
    }
    //assignment operator
    Field& operator = (const Field &other) {
        if (this !=&other) {
            return *this;
            delete [] value;
        }

        for (int i = 0; i < 3; i++) {
            value[i] = other.value[i];
        }
        return *this;
    }

    virtual void printMagnitude() const {

        double mag = sqrt(value[0]*value[0] + value[1]*value[1] + value[2]*value[2]);

        cout << "Magnitude: " << mag << endl;


    }
};






#endif