/*
 * Change.cpp
 */
#include <sstream>
#include "Change.h"


string calcChange(int m, int numCoins, int *coinValues) {

    int INF = m + 1;
    int minCoins[m + 1];
    int lastCoin[m + 1];


    // initialize for the base case of no coins used (i=0)
    minCoins[0] = 0; // empty solution
    for (int k = 1; k <= m; k++)
        minCoins[k] = INF; // no solution
    // iterate bottom up
    for (int i = 1; i <= numCoins; i++)
        for (int k = coinValues[i - 1]; k <= m; k++)
            if (minCoins[k - coinValues[i - 1]] + 1 < minCoins[k])
            {
                minCoins[k] = 1 + minCoins[k - coinValues[i - 1]];
                lastCoin[k] = coinValues[i - 1];
            }
    // produce string with the result
    if (minCoins[m] == INF)
        return "-"; // no solution
    ostringstream oss;
    for (int k = m; k > 0; k -= lastCoin[k])
        oss << lastCoin[k] << ";";
    return oss.str();
}

