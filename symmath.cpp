#include "symmath.h"
#include <cmath>

double expression::evaluate()
{
    throw UNEVAL_ERROR;
}

bool expression::evaluable()
{
    if(this->subexpramm > 0)
    {
        bool _evaluable = true;
        for(int i=0; i < this->subexpramm; i++)
            _evaluable = _evaluable && subexpr[i]->evaluable(); //ver si sirve &=
        return _evaluable;
    }
    else
        return false;
}
expression expression::reduce()
{
    for(int i=0; i < this->subexpramm; i++)
    {
        subexpr[i]->reduce();
        if(subexpr[i]->evaluate() == floor(subexpr[i]->evaluate()))
        {
            expression &temp = *new realconst(subexpr[i]->evaluate());
            //delete subexpr[i];
            subexpr[i] = &temp;
        }
    }

    /*if(this->evaluate() == floor(this->evaluate()))
    {
        //expression &temp = *new realconst(this->evaluate());
        //delete this;
        //this = temp;
        return temp;
    }
    else*/
    return (*this);
}



realconst::realconst(double init) :value(init)
{
    return;
}

bool realconst::evaluable()
{
    return true;
}
double realconst::evaluate()
{
    return this->value;
}
expression realconst::reduce()
{
    return (*this);
}

fraction::fraction(expression &numerator,expression &denominator)
{
    this->subexpramm = 2;
    this->subexpr = new expression*[2];
    this->subexpr[0] = &numerator;
    this->subexpr[1] = &denominator;
}
double fraction::evaluate()
{
    if(this->subexpr[0]->evaluable() && this->subexpr[1]->evaluable())
    {
        return this->subexpr[0]->evaluate()/this->subexpr[1]->evaluate();
    }
    else
        throw UNEVAL_ERROR;
}

/*double power::evaluate()
{
    return pow(base.evaluate(),exponent.evaluate());
}*/
