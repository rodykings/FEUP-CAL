/*
 * Partioning.cpp
 */

#include <cstring>
#include "Partitioning.h"


int s_recursive(int n,int k)
{
    return  (k==n || k==1) ? 1:s_recursive(n-1,k-1) + k* s_recursive(n-1,k);
}

int s_dynamic(int n,int k)
{
	int table[n+1][k+1];
    memset(table, {0}, sizeof table);

	for(int i=0; i < n+1; i++){
	    for (int j=0; j < k+1; j++){
	        if(j==0 || i==0){
                table[i][j] = 0;
	        }
            else if(j==1 || i==j){
                table[i][j] = 1;
            }
            else{
                table[i][j] = table[i-1][j-1] + j * table[i-1][j];
            }
	    }
	}

	return table[n][k];
}


int b_recursive(int n)
{

	return 0;
}

int b_dynamic(int n)
{
	return 0;
}


