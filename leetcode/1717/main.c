#include <stdio.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
	    int stringSize, i, totalScore = 0, j, foundPattern, switchedPattern = 0, pointsToGive;
		char f_letter, s_letter, tmp_letter;
		
		if ( y > x ) {
			f_letter = 'b';
			s_letter = 'a';
			pointsToGive = y;
		} else if ( x > y ) {
			f_letter = 'a';
			s_letter = 'b';
			pointsToGive = x;
		}

    	stringSize = strlen(s);	
		
		for ( i = 0; i < stringSize; i++ ) {			
			foundPattern = 0;
			if ( s[i] == f_letter ) {
				if ( s[i + 1] == s_letter ) {
					foundPattern = 1;
					totalScore += pointsToGive;
					for ( j = i; j < stringSize; j++ ) {
						if ( s[j + 2] == '\0' ) {
							s[j] = '\0';
							i = -1;
							break;
						}
						if ( s[j + 3] == '\0' ) {
							s[j] = s[j + 2];
							s[j + 1] = '\0';
							i = -1;
							break;
						}
							s[j] = s[j + 2];
							s[j + 1] = s[j + 3];
							j++;
						}
					}
				if ( foundPattern ) {
					if ( !switchedPattern ) {
						switchedPattern++;
						tmp_letter = f_letter;
						f_letter = s_letter;
						s_letter = tmp_letter;
						if ( pointsToGive == x ) {
							pointsToGive == y;
						} else if ( pointsToGive == y ) {
							pointsToGive == x;
						}
						i = -1;
					} 
					if ( switchedPattern ) {
						i = -1;
						if ( switchedPattern == 2 ) {
							break;
						}
					}
				} 

			}
		}

		return totalScore;
}

int main() {
	//char string[15] = {'a','a','b','b','a','a','x','y','b','b','a','a','b','b','\0'};
	char string[13] = {'c','d','b','c','b','b','a','a','a','b','a','b','\0'};

	int i;	

	printf("strlen = %ld\n", strlen(string));
	printf("score = %d\n", maximumGain(string, 5, 4));	
	printf("afterStrLen = %ld\n", strlen(string));

	for ( i = 0; i < strlen(string); i++ ) {
		printf("%c", string[i]);
	}

	return 0;
}

