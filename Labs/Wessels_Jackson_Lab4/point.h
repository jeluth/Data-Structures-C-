#ifndef MAIN_SAVITCH_2B
#define MAIN_SAVITCH_2B

namespace main_savitch_2B
{

class point
{
public:
	point(double initial_x =0.0, double initial_y=0.0);
	void shift(double x_amount, double y_amount);
	void rotate();

	double get_x() const { return x; }
	double get_y() const {return y; }

	private:
		double x;
		double y;


};
 point operator -(const point& p1, const point& p2);
}

#endif // MAIN_SAVITCH_POINT_
