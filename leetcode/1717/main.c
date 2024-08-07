#include <stdio.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
	int i, j;
	int stringSize = strlen(s);
	int totalScore = 0, pointsToGive;
	int foundPattern, switchedPattern = 0;
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

	while ( switchedPattern != 2 ) {
		for ( i = 0; i < stringSize; i++ ) {
			foundPattern = 0;
			if ( s[i] == f_letter ) {
				if ( s[i + 1] == s_letter ) {
					foundPattern = 1;
					totalScore += pointsToGive;
					for ( j = i; j < stringSize; j++ ) {
						if ( s[j + 2] == '\0' ) {
							s[j] = '\0';
							stringSize -= 2;
							break;
						}
						if ( s[j + 3] == '\0' ) {
							s[j] = s[j + 2];
							s[j + 1] = '\0';
							stringSize -= 2;
							break;
						}	  
						s[j] = s[j + 2];
						s[j + 1] = s[j + 3];
						j++;
					}
				}
			}
			if ( foundPattern ) {
					i = -1;
					switchedPattern = 0;
					break;
			}
		}
		if ( !foundPattern ) {
			if ( switchedPattern == 0 || switchedPattern == 1 ) {
				tmp_letter = f_letter;
				f_letter = s_letter;
				s_letter = tmp_letter;
				if ( pointsToGive == x ) {
					pointsToGive = y;
				} else if ( pointsToGive == y ) {
					pointsToGive = x;
				}
				switchedPattern++;
				i = -1;
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
	printf("score = %d\n", maximumGain(string, 4, 5));	
	printf("afterStrLen = %ld\n", strlen(string));

	for ( i = 0; i < strlen(string); i++ ) {
		printf("%c", string[i]);
	}
	printf("\n");

	return 0;
}
