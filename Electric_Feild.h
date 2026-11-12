//this is where i make my class for the Electric field
#ifndef eletric_Feild_h
#define eletric_Feild_h
#include <cmath>
#include "fields.h"
using namespace std;

class Electric_Feild : public Field {
private:
    double calc_E; //this is the varibale that calulates the eleteric field.


public:
    // defualt constructor
    Electric_Feild() : Field() , calc_E(0){}
    //component constructor
    Electric_Feild(double x, double y, double z) : Field(x,y,z) , calc_E(0) {}

    Electric_Feild(const Electric_Feild &other ) : Field(other) , calc_E(other.calc_E) {}


    //getter functions
    double getX() const {
        return value[0];
    }
    double getY() const {
        return value[1];
    }
    double getZ() const {
        return value[2];
    }

    //setters
    void setX(double x) {
        value[0] = x;
    }

    void setY(double y) {
        value[1] = y;
    }

    void setZ(double z) {
        value[2] = z;
    }


    //calculations.
    double CalculateMagnitude() {
        return sqrt(value[0]*value[0] + value[1]*value[1] + value[2]*value[2]);
    }

    double Calculate_Inner_Product() {
        return value[0]*value[0] + value[1]*value[1] + value[2]*value[2];
    }

    //gausses law calculations
    void CalculateElectric_Field(double Q , double r) {
        const double eplison_O = 8.854187817e-12;
        if (r <= 0) {
            cout << "ERROR distnace must be greater than 0 "<< endl;
        }
        calc_E = Q /(4.0 * M_PI * r * r * eplison_O);
    }

    //this is for the + overload operator
    Electric_Feild operator+(const Electric_Feild & f) const {
        return Electric_Feild(this->value[0] + f.value[0], this->value[1] + f.value[1], this->value[2] + f.value[2]);
    }

    // this is for the << overload operator.
    friend ostream & operator<<(ostream & os, const Electric_Feild &ef) {
        os << "" << ef.value[0] << ", " << ef.value[1] << ", " << ef.value[2] << endl;
        if (ef.calc_E != 0) {
            os <<"calculated E Gauss Law: " << ef.calc_E <<" N/C" <<endl;
        }

        return os;
    }




};

#endif