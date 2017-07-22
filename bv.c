# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct bitV {
	uint32_t  *vector;
	uint32_t length;
} bitV;

bitV *newVec(uint32_t p){
	bitV *bvp = malloc(sizeof(bitV));
	bvp->length = p;
	bvp->vector = malloc(bvp->length * sizeof(uint32_t));
	return bvp;
}
void delVec(bitV *bvp){
	free(bvp);
}

void oneVec(bitV *bvp){
uint32_t *vec_ptr = bvp->vector;
for(int i = 0; i < bvp->length; i++){
*(vec_ptr) = ~(*vec_ptr & 0);
vec_ptr++;
}
//printf("oneVEC : %d\n", sizeof(*bvp->vector));
}

void setBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;	
	//printf("%d\n", *(vec_ptr));
	uint32_t i = k/32;
	uint32_t pos = k%32;
	vec_ptr += i;
	*(vec_ptr) |= 1 << pos;
}

void clrBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;
	//printf("%d\n", *(vec_ptr));
	uint32_t i = k/32;
	uint32_t pos = k%32;
	uint32_t flag = 1;
	vec_ptr += i;
	flag = flag << pos;
	flag = ~flag;
	*(vec_ptr) &= flag;
}	

uint32_t valBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;
	uint32_t i = k/32;
	vec_ptr += i;
	return (*(vec_ptr)&(1 << k)) >> k;
}

uint32_t lenVec(bitV *bvp){
	return (bvp->length/32 + 1) * 32;
}

