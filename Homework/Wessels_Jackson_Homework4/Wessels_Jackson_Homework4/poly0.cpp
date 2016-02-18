//wessels_jackson hw4
#include "stdafx.h"
#include <cstdlib>
#include <climits>
#include <iostream>
#include "poly0.h"
#include "math.h"

using namespace std;
namespace main_savitch_3
{
	polynomial::polynomial(double c, unsigned int k)
	{
		data = new double[CAPACITY];
		
		for (int i = 0; i < CAPACITY; i++)
			data[i] = 0;

		data[k] = c;
		
		
		current_degree = k;
		size = 1;
	}

	polynomial::polynomial(double a0)
	{
		data = new double[CAPACITY];
		
		for (int i = 0; i < CAPACITY; i++)
			data[i] = 0;

		data[0] = a0;
		current_degree = 0;
		size = 1;
	}

	polynomial::polynomial(const polynomial& source)
	{
		data = new double[source.size - 1];
		size = source.size;
		copy(source.data, source.data + size, data);
	}

	polynomial::~polynomial()
	{
		delete [] data;
	}

	polynomial& polynomial::operator =(const polynomial& source)
	{
		if (this == &source)
			return *this;

		return *this;
	}

	polynomial& polynomial::operator =(double a0)
	{
		for (unsigned int i = 0; i < size; i++)
			data[i] = 0;

		data[0] = a0;
		current_degree = 0;
		size = 1;
		return *this;
	}

	void polynomial::add_to_coef(double amount, unsigned int k)
	{
		if (k <= current_degree)
		{
			data[k] += amount;
			if (data[k] <= 0)
				current_degree = previous_term(k);
		}
		else
		{
			data[k] += amount;
			current_degree = k;
			if (data[k] <= 0)
				current_degree = previous_term(k);
		}
	}

	void polynomial::assign_coef(double new_coefficient, unsigned int k)
	{
		if (data[k] == 0)
			size++;
		if(k > current_degree)
			current_degree = k;
		
		data[k] = new_coefficient;
		if (data[k] <= 0)
			current_degree = previous_term(k);
		
	}

	void polynomial::clear()
	{
		for (unsigned int i = 0; i < CAPACITY; i++)
			data[i] = 0;
	}

	double polynomial::coefficient(unsigned int k) const
	{
		if (k < CAPACITY)
			return data[k];
		else
			return 0;
	}

	unsigned int polynomial::degree() const
	{
		if (data[current_degree] == 0)
			return 0;
		else
			return current_degree;
	}
	
	unsigned int polynomial::next_term(unsigned int k) const
	{
		//if (k < CAPACITY)
		//{
			for (unsigned int i = k + 1; i < CAPACITY; i++)
			{
				if (data[i] > 0)
					return i;
			}
		//}
			return 0;
	}

	unsigned int polynomial::previous_term(unsigned int e) const
	{
		if (e != 0)
		{
			for (unsigned int i = e - 1; i != UINT_MAX; i--)
			{
				if (data[i] > 0)
					return i;
			}
		}
		return UINT_MAX;
	}

	double polynomial::eval(double x) const
	{
		double result = 0;
		for (int i= 0; i < CAPACITY; i++)
		{
			result += data[i] * pow(x, i);
		}
		return result;
	}


	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		polynomial answer;
		for (int i = 0; i < polynomial::CAPACITY; i++)
		{
			answer.add_to_coef(p1.coefficient(i) + p2.coefficient(i), i);
		}
		return answer;
		/*if (p1.degree() >= p2.degree())
		{
			polynomial answer;
			for (int i = 0; i > p1.degree(); i++)
			{
				answer.add_to_coef(p1.coefficient(i) + p2.coefficient(i), i);
			}
			return answer;
		}

		else
		{
			polynomial answer;
			for (int i = 0; i > p2.degree(); i++)
			{
				answer.add_to_coef(p1.coefficient(i) + p2.coefficient(i), i);
			}
			return answer;
		}*/
	}

	polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		if (p1.degree() >= p2.degree())
		{
			polynomial answer;
			for (unsigned int i = p1.degree(); i >= 0; i--)
			{
				answer.add_to_coef(p1.coefficient(i) - p2.coefficient(i), i);
			}
			return answer;
		}

		else
		{
			polynomial answer;
			for (unsigned int i = p2.degree(); i >= 0; i--)
			{
				answer.add_to_coef(p1.coefficient(i) - p2.coefficient(i), i);
			}
			return answer;
		}
	}

	ostream& operator << (ostream& out, const polynomial& p)
	{
		for (int i = p.degree(); i >= 0; i--)
		{
			out << p.coefficient(i) << "x^" << i << "+";
		}
		return out;
	}
}