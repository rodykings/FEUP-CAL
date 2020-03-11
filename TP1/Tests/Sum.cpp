/*
 * Sum.cpp
 */

#include "Sum.h"
#include <sstream>

string calcSum(int* sequence, int size)
{
    int sum [size];
    int index [size];

    for(int i=0; i < size;i++){
        int num = 0;
        for(int j=i; j < size; j++){
            num += sequence[j];
            if(i==0 || num < sum[j-i]){
                sum[j-i] = num;
                index[j-i] = i;
            }
        }
    }

    ostringstream oss;
    for(int s=0; s < size; s++){
        oss << sum[s] << "," << index[s] << ";";
    }
    return oss.str();
}

