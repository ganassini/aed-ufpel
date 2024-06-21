bool lemonadeChange(int* bills, int billsSize) 
{
	struct cashRegister 
	{
		int fiveBills;
		int tenBills;
	};
	
	struct cashRegister cashRegister = {0, 0};

	int i;
	
	if (bills[0] > 5)
	{
		return false;
	}

	cashRegister.fiveBills += 1;

	for (i=1; i<billsSize; i++) 
	{
		if (bills[i] == 5) 
		{
			cashRegister.fiveBills += 1;
		}
		if (bills[i] == 10) 
		{
			if (cashRegister.fiveBills == 0) 
			{
				return false;
			}
			cashRegister.fiveBills -= 1;
			cashRegister.tenBills += 1;
		}
		if (bills[i] == 20) 
		{
			/* 
			 * [5,5,10,5,20,5,5,5,5,5,20,5,10,5,5,5,5,20,20,5] 
			 */
			if (cashRegister.fiveBills < 1 )
			{
				return false;
			}
			if (cashRegister.tenBills < 1) 
			{
				if (cashRegister.fiveBills < 3) 
				{
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
