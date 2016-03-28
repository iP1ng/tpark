#include <stdio.h>

// Dynamic stair alg

size_t Stair(size_t block_number, size_t *result, size_t *cache) {
	size_t A = 0; 
	size_t B =0;
	for (int i = 0; i < N/2 +1; i++){
		A = N - i; B = i;
		if ( B < 3)
		result += 1;
		else 
			if (cached[i] == 0)
				cache[i] = Stair[B];
			else 
				result +=cache[i];
	}
	return *result;
}

int main () {
	size_t *result = NULL;
	size_t N = 0;
	size_t *cache = NULL;
	
	scanf("%lu", &N);
	
	cache = new size_t(N/2);
	for (int i = 0; i < N / 2; ++i)
		cache[i] = 0;
	printf("%lu", Stair(N, result, cache));
	
}
