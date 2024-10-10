#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {

	int i, j, key;
	for (i = first + 1; i<= last; i++){
	myCopy(&array[i], &key);
	j= i - 1;

	while (j >= 0 && (myCompare(key, array[j]) < 0)){
	mySwap(&array[j+1], &array[j]);
	j = j-1;
    }
	myCopy(&key, &array[j+1]);
  }
}
