

/************************************************************************************
	Implementation of Binary Heap Utility functions
	Author:             Ashis Kumar Das
	Email:              akd.bracu@gmail.com
	GitHub:             https://github.com/AKD92
*************************************************************************************/






#include "binheap.h"
#include <string.h>
#include <stdlib.h>





int binheap_init(BinHeap *heap, void *array, unsigned int nCount,
			unsigned int nSize, int (*compare) (const void *arg1, const void *arg2))
{
	
	heap->pElemArray = array;
	heap->elemCount = nCount;
	heap->elemSize = nSize;
	heap->compare = compare;
	heap->tmpMemory = malloc(nSize);
	return 0;
}



void binheap_destroy(BinHeap *heap) {
	
	free(heap->tmpMemory);
	memset((void *) heap, 0, sizeof(BinHeap));
}





unsigned int binheap_parentIndex(unsigned int childIndex) {
	
	unsigned int parent;
	
	parent = (childIndex - 1) / 2;										/* From Wikipedia - Binary Heap	*/
	return parent;
}



unsigned int binheap_leftChildIndex(unsigned int parentIndex) {
	
	unsigned int left;
	
	left = (parentIndex * 2) + 1;
	return left;
}



unsigned int binheap_rightChildIndex(unsigned int parentIndex) {
	
	unsigned int right;
	
	right = (parentIndex * 2) + 2;
	return right;
}





int binheap_exchangeElement(unsigned int index1, unsigned int index2, BinHeap *heap) {
	
	char *elem1, *elem2;
	
	elem1 = (char *) binheap_array(heap) + (heap->elemSize * index1);
	elem2 = (char *) binheap_array(heap) + (heap->elemSize * index2);
	
	memcpy((void*) heap->tmpMemory,	(const void*) elem1,			heap->elemSize);
	memcpy((void*) elem1,			(const void*) elem2,			heap->elemSize);
	memcpy((void*) elem2,			(const void*) heap->tmpMemory,	heap->elemSize);
	
	return 0;
}
