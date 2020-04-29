#include <iostream>
#include <cstdlib>

#include "Square.hpp"
#include "Circle.hpp"
#include "MonteCarloPi.hpp"

int main(int argc, char** argv)
{
    Square<double>* sq  = new Square<double>(1,1,0,0);
    Circle<double>* cir = new Circle<double>(0.5, 0.5, 0.5);

    Square<double>& ref_sq  = *sq;
    Circle<double>& ref_cir = *cir;


    MonteCarloPI<double>* mcpi = new MonteCarloPI<double>(ref_sq);

    mcpi->ComputeArea(ref_cir,
                      ref_sq);


    delete sq;
    delete cir;
    delete mcpi;


    return 0;
}
