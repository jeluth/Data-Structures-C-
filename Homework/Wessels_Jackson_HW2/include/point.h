#ifndef POINT_H
#define POINT_H
//FILE: point.h
//CLASS PROVIDED: point - a class for a 3-dimensional point

//CONSTRUCTOR for the point class:
//  point(double initial_x = 0.0, initial_y = 0.0, initial_z = 0.0)
//      postcondition: the point has be set to (initial_x, initial_y, initial_z).
//
//MODIFICATION MEMBER FUNCTIONS for the point class:
//  void shift(double x_amount, double y_amount, double z_amount)
//      postcondition: The point has been moved x_amount, y_amount, and/or z_amount
//          along the respective axis
//
//  void rotate(char axis, double ang)
//      precondition: either x,y, or z is entered for axis and a valid angle is entered.
//      postcondition: the point has been rotated based on entered values
//
//CONSTANT MEMBER FUNCTIONS for the point class:
//  double get_x() const
//      postcondition: the value returned at the x value of the point.
//
//  double get_y() const
//      postcondition: the value returned at the y value of the point.
//
//  double get_z() const
//      postcondition: the value returned at the z value of the point.
//
//NONMEMBER FUNCTIONS for the point class:
//ostream& operator <<(ostream& outs, const point& source)
//      postcondition:the x, y, and z coordinates of source have been written to outs.
//      The return value is the ostream outs.

using namespace std;
namespace main_wessels_1
{
    class point
    {
        public:
            //CONSTRUCTOR
            point(double initial_x = 0.0, double initial_y = 0.0, double initial_z = 0.0);
            //MODIFICATION MEMBER FUNCTIONS
            void shift(double x_amount, double y_amount, double z_amount);
            void rotate(char axis[], double ang);
            //CONSTANT MEMBER FUNCTIONS
            double get_x() const {return x;}
            double get_y() const {return y;}
            double get_z() const {return z;}
        protected:
        private:
            double x, y ,z; //x, y , and z coordinates of this point.
    };

    //NONMEMBER FUNCTIONS
    ostream& operator <<(ostream& outs, const point&source);
}
#endif // POINT_H
