#include "mySort.h"

void merge(int arr[],int x1, int y1, int x2,int y2)
{
	int temp[MAX_SIZE_N_TO_SORT]; 
	int x,y,z;


	x = x1;
	y = x2;
	z = 0;

       while(x<=y1 && y<=y2) 
	{
	if(myCompare(arr[x],arr[y]) < 0)
	   temp[z++] = arr[x++];
	else
	   temp[z++] = arr[y++];
}
			
	while(x<=y1)
        myCopy(&arr[x++],&temp[z++]) ;
	

        while(y<=y2) 
        myCopy(&arr[y++],&temp[z++]);
		
	for(x=x1,z=0;x<=y2;x++,z++)
	mySwap(&arr[x],&temp[z]);
}


void mySort(int array[], unsigned int f, unsigned int l)

{ 
    int m;

    if(f < l)
    {
       m = (f+l)/2;
       mySort(array,f,m);
	   mySort(array,m+1,l);
	   merge(array,f,m,m+1,l);
    }
}


