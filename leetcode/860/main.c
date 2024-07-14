#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
	struct cashRegister_t {
		int fiveBills;
		int tenBills;
	};
    
	struct cashRegister_t cashRegister = {0, 0};

	int i;
	
	if ( bills[0] > 5 ) {
		return false;
	}

	cashRegister.fiveBills += 1;

	for ( i = 1; i < billsSize; i++ ) {
		if ( bills[i] == 5 ) {
			cashRegister.fiveBills += 1;
		}
		if ( bills[i] == 10 ) {
			if ( cashRegister.fiveBills == 0 ) {
				return false;
			}
			cashRegister.fiveBills -= 1;
			cashRegister.tenBills += 1;
		}
		if ( bills[i] == 20 ) {
			if ( cashRegister.fiveBills < 1 ) {
				return false;
			}
			if ( cashRegister.tenBills < 1 ) {
				if ( cashRegister.fiveBills < 3 ) {
					return false;
				}
				cashRegister.fiveBills -= 3;
			} else {
				cashRegister.fiveBills -= 1;
				cashRegister.tenBills -= 1;
			}
		}
	}

	return true;
}


int main ( void ) {

	int bills[] = { 5,5,10,10,20 };
	int billsSize = 5;

	if ( lemonadeChange( bills, billsSize ) ) {
		printf("true\n");
		return 0;
	} 

	printf("false\n");

	return 0;
}
