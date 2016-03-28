/***********************************************************************
* 					Soldatov A.K. APO-13                               *
*						Task 6_2                                       *
***********************************************************************/
#include <iostream>
#include <stdio.h>

long long answer(int val, long long **matrix, int height, bool stop)						
{														
	long long  res = 0;
	for (int i = 0; i <= val; ++i)
	{
		if (height == 1 && (val==1 || val ==2)){						// Only possible variant with 1 or 2 cubes
			printf("1 (1st if) \n");
			return 1;
		}
		else if (height >= val && stop){
			printf("1 (2nd if heightest >= val) \n");
			return 0;
		}

		if (matrix[val][height] != -1 && stop)
		{
			printf("%lld  (3rd if matrix[%u][%u] != -1)\n",matrix[val][height], val, height);
			for (int i = 0; i < val +1; ++i, printf ("\n"))
			for (int j = 0; j < val +1; ++j)
			printf("%lld \t", matrix[i][j]);
			return matrix[val][height];
		}
		printf("ans(%i %i) + ans(%i %i) \n ", val - height, height, val - height, height - 1);
		res += answer(val - height, matrix, height, true) + answer(val - height, matrix, height - 1, true);
		printf ("%lld res = ans()+ans() \n", res);
		if (stop)
		{
			if (matrix[val][height] == -1)
				matrix[val][height] = res;
			for (int i = 0; i < val +1; ++i, printf ("\n"))
			for (int j = 0; j < val +1; ++j)
			printf("%lld \t", matrix[i][j]);
			printf("%lld (neeeext loop round)\n", res);
			return res;
		}
		height++;
	}
	printf("%lld \n", res);
	return res;
}


int main()
{
	int value = 0;														// Number of cubes
	long long ans = 0;
	std::cin >> value;
	long long **matrix = new long long*[value + 1];						// Caching results
	for (int i = 0; i < value + 1; ++i)
		matrix[i] = new long long[value + 1]; 
	for (int i = 0; i < value + 1; ++i)									// Cached table (TODO triangle)
		for (int j = 0; j < value + 1; ++j)
		{
			matrix[i][j] = -1;
		}
	for (int i = 0; i < value + 1; ++i)									// Making borders
	{
		matrix[i][0] = 0;
		matrix[0][i] = 0;
	}
	ans = answer(value, matrix, 1,false);
	std::cout << ans;
	//for (int i = 0; i < value +1; ++i, printf ("\n"))
	//		for (int j = 0; j < value +1; ++j)
	//		printf("%lld \t", matrix[i][j]);
			
	for (int i = 0; i < value + 1; i++)
		delete matrix[i];
	delete[] matrix;
	return 0;
}
