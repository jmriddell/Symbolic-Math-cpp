#ifndef SYMMATH_H
#define SYMMATH_H
#define UNEVAL_ERROR 55

class expression
{
public:
    virtual double evaluate();
    virtual expression reduce();
    virtual bool evaluable();
    expression **(subexpr);
    int subexpramm;
};

class realconst: public expression
{
public:
    realconst(double init);
    virtual double evaluate();
    virtual expression reduce();
    virtual bool evaluable();
    const double value;
};

class fraction: public expression
{
public:
    fraction(expression &numerator,expression &denominator);
    virtual double evaluate();
};

/*class power: public expression
{
public:

};

class sum: public expression
{

};*/

#endif // SYMMATH_H
