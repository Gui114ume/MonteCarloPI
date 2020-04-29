#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP

#include <cstdlib>
#include <iostream>

#include "Shape.hpp"
#include "Square.hpp"

class IMonteCarlo
{
public:
    virtual ~IMonteCarlo()
    {
        std::cout<<"destructeur IMonteCarlo"<<std::endl;
    };

    virtual void ComputeArea(IShape& Shape,
                             Square<double>& CarreEnveloppant) = 0;

    virtual void SetDistributionLaw(Square<double>& Carre) = 0;

protected:
    IMonteCarlo() {};
};


#endif
