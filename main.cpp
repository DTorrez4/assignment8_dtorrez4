#include <iostream>
#include <iomanip> // this library helps with scientific notation.
#include "Electric_Feild.h" //calls on my header file that contains the class for the electric field
#include "Magnetic_Field.h" //calls on my header file that contains  the class for the magnetic field.
#include "fields.h" //this is the base class fields
using namespace std;
\
//this main is for printing  out the information.
int main(){

    //default constuctor printing.
    Magnetic_Field default_B_component; // this calls on the default constructor.
    Electric_Feild default_E_component;
    cout<<"--BEFORE MODIFYING THE DEFUALT CONSTRUCTOR--" << endl;
    cout<<"Default electric field before setting values: " << default_E_component.getX() << ", " << default_E_component.getY() << ", " << default_E_component.getZ() << endl;
    cout << " "<< endl;
    cout<<"Default magnetic field before setting values: " << default_B_component.getX() << ", " << default_B_component.getY() << ", " << default_B_component.getZ() << endl;
    cout << " "<< endl;

    //Setting the default construtor and giving values to it.

    //magnetic field setting the components
    default_B_component.setX(5);
    default_B_component.setY(6);
    default_B_component.setZ(7);
    //Electric  field setting the components
    default_E_component.setX(1);
    default_E_component.setY(2);
    default_E_component.setZ(3);

    //this prints out what the values are after setting using the getter functions in the classes.
    cout << "------- AFTER MODIFYING THE DEFUALT CONSTRUCTOR--------\n";
    cout << " "<< endl;
    cout<<"Default electric field after setting values: " << default_E_component.getX() << ", " << default_E_component.getY() << ", " << default_E_component.getZ() << endl;
    cout << " "<< endl;
    cout<<"Default Magnetic  field after setting values: " << default_B_component.getX() << ", " << default_B_component.getY() << ", " << default_B_component.getZ() << endl;
    cout << " "<< endl;
    //this prints out all the stuff witht he modified default constructor.
    cout<<"Electric_Field Magnitude: " << default_E_component.CalculateMagnitude() << endl;
    cout << " "<< endl;
    cout<<"Eletric Field inner product: " << default_E_component.Calculate_Inner_Product() << endl;
    cout << " "<< endl;
    cout<<"Magnetic field Magnitude: " << default_B_component.CalculateMagnitude_B() << endl;
    cout << " "<< endl;
    default_B_component.Calculate_Print_Unit_Vector();
    cout << "----------------------------------"<< endl;
    cout << " "<< endl;

    //setting the values using the other constructor class.
    Magnetic_Field B_componets(3,4,6);
    Electric_Feild E_componets(1e5,10.9,1.7e2);

    cout<<"-------COMPONETS CONSTRUCTION-------"<<endl;
    cout << " "<< endl;
    //this calls on the classes in my header file to print out the magnitude for the magnetic and electric field.
    cout << "Electric_Field Magnitude: " << E_componets.CalculateMagnitude() << endl;
    cout << " "<< endl;
    cout <<"Eletric Field inner product: " << E_componets.Calculate_Inner_Product() << endl;
    cout << " "<< endl;
    cout << "Magnetic field Magnitude: " << B_componets.CalculateMagnitude_B() << endl;
    cout << " "<< endl;
    //this calls on the print function i made for the magnetic field.
    B_componets.Calculate_Print_Unit_Vector();
    cout << "--------------------------------------------------------"<< endl;
    cout << " "<< endl;


    //added for the Laws and the overloaded operator for assingment 8.

    cout << "-------NEW FEATURE FOR ASSINGMENT 8-------" << endl;
    cout << " "<< endl;

    //this is the << operator overload

    Electric_Feild e1(1,2,3);
    Electric_Feild e2(1,2,3);
    Electric_Feild e3 = e1 + e2;

    cout<<"this is e_1 = " << e1 << endl;
    cout<<"this is e_2 = " << e2 << endl;
    cout<<"e_3 is the sum of e_1 and e_2 = " << e3 << endl;



    // this is for the gausses law calculations
    e3.CalculateElectric_Field(1e-6,0.06);
    cout << "Gausess law test: " << e3 << endl;
    cout << " "<< endl;

    // this is for Amperes law
    Magnetic_Field b1(3,4,6);
    Magnetic_Field b2(3,8,1);
    Magnetic_Field b3 = b1 + b2;

    cout<<"this is b_1 = " << b1 << endl;
    cout<<"this is b_2 = " << b2 << endl;
    cout<<"b_3 is the sum of b_1 and b_2 = " << b3 << endl;


    b3.calculateMagneticField(5,1);
    cout << "Amperes law test: " << b3 << endl;
    cout << " "<< endl;


    return 0;
}
