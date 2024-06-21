bool lemonadeChange(int* bills, int billsSize) {
    int i, availableExchange;

    availableExchange = bills[i];
    
    for (i=1; i<billsSize; i++)
    {
	    if (availableExchange < (bills[i] - 5)) 
	    {
	    	return false;
	    }
		
	    if (bills[i] == 5) 
	    {
	    	availableExchange += bills[i];
	    } else if (bills[i] > 5) {
		if (availableExchange < (bills[i] - 5))
		{
			return false;
		} 
		
		availableExchange -= (bills[i] - 5);
	    }
    }

    return true;
}
