#include <stdio.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
	    int stringSize, i, totalScore = 0, j, foundPattern, switchedPattern = 0, pointsToGive = y;
		char f_letter = 'b', s_letter = 'a';

    	stringSize = strlen(s);	
		
		// 0: aabbaaxybbaabb
		// 1: aabaxybbaabb
		// 2: aaxybbaabb
		// 3: aaxybabb
		// 4: aaxybb
		// 5: 
		
		for ( i = 0; i < stringSize; i++ ) {
			foundPattern = 0;
			if ( s[i] == f_letter ) {
				if ( s[i + 1] == s_letter ) {
					foundPattern = 1;
					totalScore += pointsToGive;
					for ( j = i; j < stringSize; j++ ) {
						if ( s[j + 2] == '\0' ) {
							s[j] = '\0';
							break;
						}
						if ( s[j + 3] == '\0' ) {
							s[j] = s[j + 2];
							s[j + 1] = '\0';
							break;
						}
							s[j] = s[j + 2];
							s[j + 1] = s[j + 3];
							j++;
						}
					}
					if ( foundPattern ) {
						if ( !switchedPattern ) {
							f_letter = 'a';
							s_letter = 'b';
							pointsToGive = x;
							i = -1;
						}
					}
					if ( switchedPattern ) {
						break;
					} 
				}
			}

			return totalScore;
}

int main() {
	char string[15] = {'a','a','b','b','a','a','x','y','b','b','a','a','b','b','\0'};
	int i;	

	printf("strlen = %ld\n", strlen(string));
	printf("score = %d\n", maximumGain(string, 5, 4));	
	printf("afterStrLen = %ld\n", strlen(string));

	for ( i = 0; i < strlen(string); i++ ) {
		printf("%c", string[i]);
	}

	return 0;
}

