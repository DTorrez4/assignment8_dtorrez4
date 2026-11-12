//this is my headerfile where i Magnetic feild class and the functions of it.
#ifndef magnetic_field_h
#define magnetic_field_h
#include <iostream>
#include <cmath>
#include "fields.h"
using namespace std;

class Magnetic_Field : public Field {
    private:
        double Calc_B;

    public:
        //default constuctor
        Magnetic_Field() : Field() , Calc_B(0) {}

        //component constructor
        Magnetic_Field(double x , double y , double z): Field(x,y,z) , Calc_B(0) {}

    //getters
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

    //calculations
    double CalculateMagnitude_B() const {
            return sqrt(value[0]*value[0] + value[1]*value[1] + value[2]*value[2]);
        }

    void Calculate_Print_Unit_Vector() const {
            double mag = CalculateMagnitude_B();

            if (mag == 0) {
                cout<<"Magnitude Zero UNDIFINED "<<endl;
                return;
            }
            double ux = value[0]/fabs(mag); //fabs get the absolute value of the double.
            double uy = value[1]/fabs(mag);
            double uz = value[2]/fabs(mag);

            cout<<"Magnetic field unit vector: " << ux << ", " << uy << ", " << uz << endl;
        }

    void calculateMagneticField(double I , double r) {
            const double mu_0 = 4.0 * M_PI * 1e-7;
            if (r <= 0) {
                cout<<"distance of the r must be greater than 0 "<<endl;
                Calc_B = 0;
                return;
            }
            Calc_B = I / (2*M_PI*r* mu_0);

        }

    double getCalculatedMagneticField() const {
            return Calc_B;
        }

    //the overload + operator for the two magnetic fields.
    Magnetic_Field operator+(const Magnetic_Field & A) const {
            return  Magnetic_Field(this->value[0]+ A.value[0] , this->value[1]+ A.value[1] , this->value[2]+ A.value[2]);
        }

    //this the for the << overload operator.
    friend ostream& operator<<(ostream &os, const Magnetic_Field &mf) {
            os << "" << mf.value[0] << ", " << mf.value[1] << ", " << mf.value[2] << endl;
            if (mf.Calc_B != 0) {
                os << " Calculated B Amperes Law : " << mf.Calc_B << " T" <<endl;
            }
            return os;

        }



};



#endif