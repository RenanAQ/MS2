
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Renan de Alencar Queiroz
Student ID#: 129280326
Email      : rde-alencar-queiroz@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include "core.h"

//functions definitios

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//Function 01: inputInt
int inputInt(void)
{   
    int intNumber; //Declared local variable
    char newLine = 'x'; //Declared local variable

    while (1)
    {
        scanf("%d%c", &intNumber, &newLine);
        if (newLine != '\n') //Checking if variable newLine == \n
        {
            clearInputBuffer(); // Discard all remaining char's from the standard input buffer:
            printf("Error! Input a whole number: ");   
        }
        else
        {
            return intNumber;
        }
    }
}

//Function 02: inputIntPositive
int inputIntPositive(void)
{   
    int intPosNumber; //Declared local variable
    char newLine ='x'; //Declared local variable

    while (1)
    {
        scanf("%d%c", &intPosNumber, &newLine);
        if (newLine != '\n') //Checking if newLine == \n
        {
            clearInputBuffer(); // Discard all remaining char's from the standard input buffer:
            printf("Error! Input a whole number: ");   
        }
        else
        {
            if (intPosNumber < 0)
            {
                printf("ERROR! Value must be > 0: ");
            }
            else
                return intPosNumber;
        }
    }
}

//Function 03: inputIntRang
int inputIntRange(int lowerBound, int upperBound)
{
    int intNumber; //Declared local variable
    char newLine ='x'; //Declared local variable

    while (1)
    {
        scanf("%d%c", &intNumber, &newLine);
        if (newLine != '\n') //Checking if newLine == \n
        {
            clearInputBuffer(); // Discard all remaining char's from the standard input buffer:
            printf("Error! Input a whole number: ");   
        }
        else
        {
            if (intNumber < lowerBound || intNumber > upperBound)
            {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            }
            else
                return intNumber;
        }
    }

}

//Function 04: inputCharOption
char inputCharOption(const char validCharacteres[])
{
    char inputChar; //Declared local variable
    int isValid = 0; //Declared local variable
    int i = 0; //Declared local variable

    while (!isValid) //This loop will run until the isValid is TRUE(1)
    {
        scanf(" %c", &inputChar); //User input
        // Check if entered character is in the list of valid characters        
        for (i = 0; validCharacteres[i] != '\0'; i++) //The FOR-LOOP will stop when [i] == \0
        {
            if (inputChar == validCharacteres[i]) 
            {
                isValid = 1; //This will be true when the input matches the valid char
                break; //The loop will break when matches true
            }
        }
        if (!isValid) //if the input is not valid, this will activate
        {
            printf("ERROR: Character must be one of [qwErty]: ");
        }
    }
    clearInputBuffer(); // Discard all remaining char's from the standard input buffer:
    return inputChar;
}

//Function 05: inputCString
void inputCString(char CString[], int minChar, int maxChar)
{   
    char inputString[100]; //Size 100 so the user can input anything until the rule is clear
    int arraySize; //Size of the inputed string
    int isValid = 0; //Declared local variable
    int i = 0;
    int checkRange;

    while (!isValid) //This loop will run until the isValid is TRUE(1)
    {   
        fgets(inputString, sizeof(inputString), stdin); //fgets capture the entire input, including spaces

        // Check if entered character is in the list of valid characters        
        for (i = 0; inputString[i] != '\0'; i++)
        {
            //This loop is here just to count the size of the array
        }
        arraySize = i-1; //-1 because of the \0
        
        if (arraySize >= minChar && arraySize <= maxChar)
        {
            isValid = 1; //Check if the size of the array is between minChar and maxChar
        }
        else
        {
            checkRange = maxChar - minChar; //this will check the condition of the input

            if (checkRange == 0) //if it is zero, it means maxChar == minChar
            {
                printf("ERROR: String length must be exactly %d chars: ", minChar);
            }
            else if (arraySize > maxChar) //it means the input was greater than the maxChar
            {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
            }
            else if (arraySize < minChar) //it means the input was lesser than the minChar
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChar ,maxChar);
            }
            else //any other case that was not expected
                printf("ERROR: String length must be between %d and %d chars: ", minChar ,maxChar);
        }
    }
    //returning a C string via the 1st argument parameter
    for (i = 0; i < arraySize; i++)
    {
        CString[i] = inputString[i];
    }
    //clearInputBuffer(); // Discard all remaining char's from the standard input buffer:
}

//Function 06 displayFormattedPhone
void displayFormattedPhone(const char* CString)
{
    int sizeCString = 0; // size of the array
    int i = 0;

    if (CString == NULL) //Handles the NULL case
    {
        printf("(___)___-____");
        return;
    }
    //check the size of the array
    for (i = 0; CString[i] != '\0'; i++)
    {
        //This will validade the digits (0 - 9)
        if (CString[i] >= '0' && CString[i] <= '9')
        {
            sizeCString++; //It will count only validated digits
        }
    }
    if (sizeCString != 10) //If the size is not exactly 10
    {
        printf("(___)___-____");
        return;
    }
    else //this will run only when the inout is exactly size 10
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c", CString[0],CString[1],CString[2],CString[3],
        CString[4],CString[5],CString[6],CString[7],CString[8],CString[9]);
        return;
    }
}

;