#ifndef MONTE_CARLO_PI_HPP
#define MONTE_CARLO_PI_HPP

#include <random>

#include "MonteCarlo.hpp"

template <typename T>
class MonteCarloPI : public IMonteCarlo
{
public:
    MonteCarloPI(Square<double>& carre)
    {
        this->SetDistributionLaw(carre);
    }
    virtual void ComputeArea(IShape& shape,
                             Square<double>& CarreEnveloppant) override
    {
        double shapeArea = 0;
        double pts_in_shape      = 0;
        double pts_outside_shape = 0;
        for(int i = 0 ; i < 100000 ; i++)
        {
            double x = this->gen_random_uniform(CarreEnveloppant);
            double y = this->gen_random_uniform(CarreEnveloppant);
            if( shape.isInShape(x, y) )
                pts_in_shape += 1;
            else
                pts_outside_shape += 1;
        }
        shapeArea = pts_in_shape / ( pts_outside_shape + pts_in_shape );
        std::cout<<"aire du cercle : "<<shapeArea<<std::endl;
        std::cout<<"D'après l'algorithme de monte carlo, pi vaut donc : "<<shapeArea<<" / 0.5^2 = "<<shapeArea/(0.5*0.5)<<std::endl;

    }
    virtual void SetDistributionLaw(Square<double>& carre) override
    {
        this->distribution = std::uniform_real_distribution<double>(0.0,1.0);
    }


    virtual ~MonteCarloPI() {}

protected:

    double gen_random_uniform(Square<double>& carre)
    {
        double tmp = this->distribution(this->generator);
        return tmp;
    }

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;


};

#endif
