#include <iostream>
#include "symmath.h"
using namespace std;

int main()
{
    //realconst asdf(88);
    expression &asdf = *new fraction(*new realconst(8),*new realconst(4));
    cout << asdf.evaluate() << endl;
    return 0;
}
