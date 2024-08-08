int numberOfSubarrays(int* nums, int numsSize, int k){
	/* 
	 *
	 * [2,2,2,1,2,2,1,2,2,2]  ||  [1,1,2,1,1]  ||  [2,4,6]
	 *
	 */
	int i, j, subArrays, oddNumbers, lastElementIndex, kthOddNumberIndex, lastKthNumberIndex, foundSubArray, finderEndpoint;

	subArrays = 0;
	foundSubArray = 0;
	lastElementIndex = numsSize - 1;
	oddNumbers = 0;

	for ( i = 0; i < numsSize; i++ ) {
		if ( nums[i] % 2 == 1 ) {
			oddNumbers += 1;
			lastKthNumberIndex = i;
		}
		if ( oddNumbers == k ) {
			kthOddNumberIndex = i;
			foundSubArray = 1;
		}
	}

	if ( !foundSubArray ) {
		return subArrays;
	}

	for ( i = 0; i < numsSize; i++ ) {
		oddNumbers = 0;
		j = i;
		finderEndpoint = kthOddNumberIndex;
			
		while ( j <= finderEndpoint && finderEndpoint <= lastElementIndex) {
			if ( nums[j] % 2 == 1) {
				oddNumbers += 1;

				if ( oddNumbers == k ) {
					subArrays += 1;
					finderEndpoint += 1;
					j = i;
				}
			}
		}
	} 

	return subArrays;
}
