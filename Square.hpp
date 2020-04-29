#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape.hpp"

template <typename T>
class Square : public IShape
{
public:
    //Constructeur
    Square()
    {
        this->setShape();
    }
    Square(T x,
           T y,
           T or_x,
           T or_y)
    {
        this->length    = x;
        this->width     = y;
        this->origine_x = or_x;
        this->origine_y = or_y;
    }

    //Destructeur
    virtual ~Square() {}

    //Methods
    virtual void setShape() override
    {
        this->length    = 0;
        this->width     = 0;
        this->origine_x = 0;
        this->origine_y = 0;
    };
    void setShape(T length,
                  T width,
                  T origine_x,
                  T origine_y)
{
        this->length = length;
        this->width  = width;
        this->origine_x = origine_x;
        this->origine_y = origine_y;
};
    virtual bool isInShape(double x,
                           double y) override
    {
        if( (x >= this->origine_x) && (x <= this->origine_x + this->length) &&  ( y >= this->origine_y) && (y <= this->origine_y + this->width) )
            return true;
        else
            return false;
    };

private:
    //Attributes
    T length;
    T width;
    T origine_x;
    T origine_y;

};

#endif
