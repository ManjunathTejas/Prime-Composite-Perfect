#include "bv.h"
#include <stdio.h>
#include <math.h>
#include <complex.h>
/**
 * @v - the pointer to the bitVector
 * Clears all the composite bits
 **/
void sieve(bitV *v){
	oneVec(v);
	clrBit(v, 0);
	clrBit(v, 1);
	setBit(v, 2);
	for(uint32_t i = 2; i <= sqrt(lenVec(v)); i++)
	{
		if(valBit(v,i ))
		{
			for(uint32_t k = 0; (k+i) * i <= lenVec(v); k++)
			{
				clrBit(v, (k + i) * i);
			}
		}	
	}
	return;
	
}

