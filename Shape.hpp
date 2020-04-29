#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstdlib>
#include <iostream>

class IShape
{
public:
    virtual ~IShape(){}

    virtual void setShape()  = 0;
    virtual bool isInShape(double x,
                           double y) = 0;

protected:
    IShape() {};

};

#endif
