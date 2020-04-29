#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

#include <cstdlib>
#include <iostream>


template <typename T>
class Circle : public IShape
{

public:


    Circle(){}

    Circle(T radius,
           T origine_x,
           T origine_y)
    {
        this->setShape(radius,
                       origine_x,
                       origine_y);
    }

    virtual void setShape() override
    {
        std::cout<<"pas d'argument dans setShape()"<<std::endl;
    }

    void setShape(T radius,
                  T origine_x,
                  T origine_y)
    {
            this->radius     = radius;
            this->origine_x  = origine_x;
            this->origine_y  = origine_y;
    }

    virtual bool isInShape(double x,
                           double y) override
    {
        if( (x - this->origine_x) * (x - this->origine_x) + (y - this->origine_y) * (y - this->origine_y) < this->radius * this->radius)
            return true;
        else
            return false;
    }

    virtual ~Circle() {};


protected:
    T radius;
    T origine_x;
    T origine_y;
};



#endif
