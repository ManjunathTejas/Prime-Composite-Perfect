#include "bv.h"
#include <stdio.h>
#include <math.h>
#include <complex.h>
void sieve(bitV *v){
	oneVec(v);
	for(int j = (v->length/32+1)*32; j >= 0; j--){
		//printf("%d", valBit(v, j));
	}
		//printf("\n");
	clrBit(v, 0);
	for(int j = (v->length/32+1)*32; j >= 0; j--){
		//printf("%d", valBit(v, j));
	}
		//printf("\n");
	clrBit(v, 1);
	for(int j = (v->length/32+1)*32; j >= 0; j--){
		//printf("%d", valBit(v, j));
	}	
		//printf("\n");
	setBit(v, 2);
	for(int j = (v->length/32+1)*32; j >= 0; j--){
		//printf("%d", valBit(v, j));
	}
		//printf("\n");	
	for(uint32_t i = 2; i <= sqrt(lenVec(v)); i++)
	{
		if(valBit(v,i ))
		{
		//printf("%d\n", valBit(v,i));
			for(uint32_t k = 0; (k+i) * i <= lenVec(v); k++)
			{
				clrBit(v, (k + i) * i);
			}
		}	
	}
	for(int j = (v->length/32 + 1)*32; j >= 0; j--){
		//printf("%d", valBit(v, j));
	}
		//printf("\n");	
	return;
	
}

