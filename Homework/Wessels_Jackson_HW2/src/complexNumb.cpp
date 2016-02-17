#include "complexNumb.h"

namespace main_wessels_3
{

complexNumb::complexNumb(double rl, double img)
{
    real = rl;
    imaginary = img;
}

complexNumb operator +(const complexNumb& p1, const complexNumb& p2)
{
    double realSum = p1.getReal() + p2.getReal();
    double imagSum = p1.getImaginary() + p2.getImaginary();
    complexNumb result(realSum, imagSum);
    return result;

}

complexNumb operator -(const complexNumb& p1, const complexNumb& p2)
{
    double realDiff = p1.getReal() - p2.getReal();
    double imagDiff = p1.getImaginary() - p2.getImaginary();
    complexNumb result(realDiff, imagDiff);
    return result;
}

complexNumb operator *(const complexNumb& p1, const complexNumb& p2)
{
    double realProd = p1.getReal() * p2.getReal();
    double imagProd = p1.getImaginary() * p2.getImaginary();
    complexNumb result(realProd, imagProd);
    return result;
}

complexNumb operator /(const complexNumb& p1, const complexNumb& p2)
{
    double realDiv = p1.getReal() / p2.getReal();
    double imagDiv = p1.getImaginary() / p2.getImaginary();
    complexNumb result(realDiv, imagDiv);
    return result;
}

}
