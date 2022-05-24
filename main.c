#include <stdio.h>
#include <string.h>



int main()
{
    char* words[] = {"dogs", "ziyadBs7nyaka",};			
    char dots[20];
    char* word;
    int random;             // random number to choose word from set of words			
    int len;				//len is the length of the word entered.
    char ch;				//ch is a temporary character variable.
    int strikes=0;			//strikes counts how many wrong characters the user has guessed.
    int trigger = 0;			//The trigger variable serves as a flag in the for loops bellow.
    int wincounter=0;			//wincounter keeps track of the number of correct guesses.
    int i;				//Another counter variable to be used in for loops.

    printf("Enter random number between 1 and 10 to choose random word from set of words\n");
    scanf("%d", &random);
    word = words[random];

   
    len = strlen(word);					//Make len equal to the length of the word.


    //Fill the stars string with * according to the input word length (len)
    for(int counter=0; counter<len; counter++)
    {
        dots[counter]='.';
    }


    dots[len]='\0';					//Insert the terminating string character at the end of the stars string.


    //Enter main program loop where guessing and checking happens. this condition is for length of the word  + 10 wrong guess.
    for(int counter = 0; counter< len + 10; counter++)
    {

        if(wincounter==len)			    	//If the number of correct guesses matches the length of the word it means that the user won.
        {
            printf("The word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }


        if(strikes== 10 )				    	//If the user makes 10 wrong guesses it means that he lost.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }

        printf("%s", dots);			//Print the stars string (i.e: h*ll* for hello).

	printf("Guess a letter:");			//Have the user guess a letter.
        scanf(" %c",&ch);

        for(i=0; i<len; i++)            		//Run through the string checking the characters.
        {
            if(word[i]==ch)
            {
                dots[i]=ch;		    		//If the guess is correct, replace it in the stars string.
                trigger++;			   	//If a character the user entered matches one of the initial word, change the trigger to a non zero value.
                wincounter++;		    		//Increase the number of correct guesses.
            }
        }

        if(trigger==0)
        {
            strikes++;				    	//If the trigger is not a non zero value, increase the strikes counter because that means that the user input character didn't match any character of the word.
        }

        trigger = 0;				    	//Set the trigger to 0 again so the user can guess a new character.
    }

   
}