/***********************************************************************
* 					Soldatov A.K. APO-13                               *
*						Task 3_2                                       *
***********************************************************************/
#include <stdio.h>
#include <stdint.h>

int32_t find_max(int32_t *array, int32_t N);

int main(void){
	int32_t *array;
	int32_t N;
	
	scanf("%d",&N);
	
	array = new int32_t[N];
	for (int32_t i = 0; i < N; ++i)
		scanf("%d",&array[i]);
	printf("%d",find_max(array,N));										// worst, when array[0] = max. O(log n)
	delete[] array;
}

int32_t find_max(int32_t *array, int32_t N){							// binary search
	if (N == 1)															// 1 element in array
		return 0;
		
	int32_t left = 0;
	int32_t right = N - 1;
	int32_t middle = 0;	
	int32_t step = 1;	
	bool flag = true;													// for leaving loop			
	
	if (right == 1)														// special case (for example -1, 4)
		return ((array[0] > array[1])?0:1);		
		
	while ((step < N) && flag) {
		middle = step - 1;
		step *= 2;
		//printf("%u \n",step);
		if (step >= N) {
			step = N - 1;
			flag = false;
		}
		//printf("%u \n",step);
		if ((array[middle] >= array[step]) || (flag == false)){
			//flag = false;									// for O(log k)
			//printf("%u %u \n ",left, step);
			left = (step / 2) - 1;
			right = step;
			//printf("%u %u \n",left, right);
			while( !(left > right)){											// this will be always false  
				middle = left + (right - left) / 2;								// to prevent data overflow (for big arrays)
				if (middle == right)											// reached end of segment 
					return middle;				
				if ((array[middle] > array[middle+1]) && 						// found max
					(array[middle] > array[middle-1])) 
					return middle;
				if (array[middle] < array[middle-1]) 							// move left half
					right = middle;												// could not do (middle - 1) could be out of index
				else  
					left = middle + 1;											// move right half
			}
			return middle;	
		}							
	}	
	return 0;					
}
