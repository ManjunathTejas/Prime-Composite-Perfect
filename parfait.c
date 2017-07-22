#include "sieve.h"
#include <stdio.h>
#include <stdlib.h>
#include "bv.h"

void list_prime_factors(bitV *bvp){
	uint32_t tmp_size = bvp->length;
	printf("%d :", bvp->length);
	if(valBit(bvp, bvp->length)){
		printf("%d, %d",bvp->length,1);
		return;
	}
	for(int i = 0; i < bvp->length; i++){
		if(valBit(bvp, i)){
			if(tmp_size % i == 0){
				while(tmp_size % i == 0){
					printf("%d, ",i);
					tmp_size = tmp_size/i;
				}
			}
		}
	}
}

void is_perfect(bitV *bvp){
	int perf_arr[bvp->length];
	int perf_sum = 0;
	int fact_count = 0;
	for(int i = 1; i < bvp->length; i++){		
		if(bvp->length % i == 0){
			perf_sum+= i;
			perf_arr[fact_count] = i;
			fact_count++;
		}
	}
	
	if(perf_sum == bvp->length){
		printf("%d E:",bvp->length);
		for(int j = 0; j < fact_count; j++){
			printf("%d, ",perf_arr[j]);
		}
	}
	return;
}

int main(){
	for(int i = 2; i < 501; i++){
		bitV *bv = newVec(i);
		sieve(bv);
		printf("\n");
		list_prime_factors(bv);
		printf("\n");
		is_perfect(bv);
		printf("\n");
		free(bv->vector);
		delVec(bv);
		printf("\n");
	}
}	
