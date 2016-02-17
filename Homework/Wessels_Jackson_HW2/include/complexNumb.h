#ifndef COMPLEXNUMB_H
#define COMPLEXNUMB_H
//FILE: complexNumb.h
//CLASS PROVIDED: complexNumb

//CONSTRUCTOR for the complexNumb class:
//    complexNumb(double rl = 0, double img = 0)
//        Postcondition: creates a new complexNumb using rl and img as values.
//
//CONSTANT MEMBER FUNCTIONS for complexNumb class:
//    double getReal() const
//        Postcondition: returns the real number portion of the complex number.
//    double getImaginary() const
//        Postcondition: returns the imaginary number portion of the complex number.
//NON-MEMBER FUNCTIONS for complexNumb class:
//    complexNumb operator +(const complexNumb& p1, const complexNumb& p2)
//        Postcondition: adds two complex numbers and returns the result.
//    complexNumb operator -(const complexNumb& p1, const complexNumb& p2)
//        Postcondition: subtracts two complex numbers and returns the result.
//    complexNumb operator *(const complexNumb& p1, const complexNumb& p2)
//        Postcondition: multiplies two complex numbers and returns the result.
//    complexNumb operator /(const complexNumb& p1, const complexNumb& p2)
//        Postcondition: divides two complex numbers and returns the result.

namespace main_wessels_3
{

class complexNumb
{
    public:
        //CONSTRUCTOR
        complexNumb(double rl = 0, double img = 0);
        //CONSTANT MEMBER FUNCTIONS
        double getReal() const {return real;}
        double getImaginary() const {return imaginary;}
    protected:
    private:
        double real, imaginary;
};
        //NON-MEMBER FUNCTIONS
        complexNumb operator +(const complexNumb& p1, const complexNumb& p2);
        complexNumb operator -(const complexNumb& p1, const complexNumb& p2);
        complexNumb operator *(const complexNumb& p1, const complexNumb& p2);
        complexNumb operator /(const complexNumb& p1, const complexNumb& p2);
}
#endif // COMPLEXNUMB_H
