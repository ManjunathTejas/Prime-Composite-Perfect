# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
/**
 * @vector - the location of where the bitVector starts
 * @length - the # you're trying to find factors for
 **/
typedef struct bitV {
	uint32_t  *vector;
	uint32_t length;
} bitV;

/**
 * @p - the size of how big the vector is
 * Creates a new bitVector
 **/
bitV *newVec(uint32_t p){
	bitV *bvp = malloc(sizeof(bitV));
	bvp->length = p;
	bvp->vector = malloc(bvp->length * sizeof(uint32_t));
	return bvp;
}

/**
 * @bvp - pointer to where the vector starts
 * Deletes the vector
 **/
void delVec(bitV *bvp){
	free(bvp);
}

/**
 * @bvp - pointer to where the vector starts
 * Turns all the bits on creating a vector of all ones
 **/
void oneVec(bitV *bvp){
uint32_t *vec_ptr = bvp->vector;
	for(int i = 0; i < bvp->length; i++){
		*(vec_ptr) = ~(*vec_ptr & 0);
		vec_ptr++;
	}
}

/**
 * @bvp - pointer to where the vector starts
 * @k - the bit that needs to be set
 **/
void setBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;	
	uint32_t i = k/32;
	uint32_t pos = k%32;
	vec_ptr += i;
	*(vec_ptr) |= 1 << pos;
}

/**
 * @bvp - pointer to where the vector starts
 * @k - the bit that needs to be cleared
 **/
void clrBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;
	uint32_t i = k/32;
	uint32_t pos = k%32;
	uint32_t flag = 1;
	vec_ptr += i;
	flag = flag << pos;
	flag = ~flag;
	*(vec_ptr) &= flag;
}	

/**
 * @bvp - pointer to where the vector starts
 * @k - the value of bit k (either 1 or 0)
 **/
uint32_t valBit(bitV *bvp, uint32_t k){
	uint32_t *vec_ptr = bvp->vector;
	uint32_t i = k/32;
	vec_ptr += i;
	return (*(vec_ptr)&(1 << k)) >> k;
}

/**
 * @bvp - the pointer to where the vector starts
 * The number of bits possibly used for the vector
 **/
uint32_t lenVec(bitV *bvp){
	return (bvp->length/32 + 1) * 32;
}

