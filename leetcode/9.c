#include <stdlib.h>
#include <string.h>

char* reverseString(char* string)
{
    char* reversedString;
    int stringLenght, i, j;
    
    stringLenght = strlen(string);
    
    for (i=0,j=stringLenght; i<stringLenght,j>0; i++,j--)
    {
        reversedString[i] = string[j];
    }
    
    return reversedString;
}

bool isPalindrome(int x) {
    char* string, reversedString;
    
    itoa(x, string, DECIMAL);
    reversedString = reverseString(string);
    
    if (strcmp(string, reversedString)) 
    {
        return false;
    }
    
    return true;
}
