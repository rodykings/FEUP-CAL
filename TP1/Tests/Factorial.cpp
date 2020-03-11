/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
    return (n==1 | n==0) ?  1 : n * factorialRecurs(n-1);
}

int factorialDinam(int n)
{
    int result = 1;
    for(n; n>1; n--){
        result*=n;
    }
    return result;
}
