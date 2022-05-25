#include <stdio.h>
#include <string.h>

char *hangman[] = {"\n       \n       \n       \n       \n       \n       \n=========\n", "\n      +\n      |\n      |\n      |\n      |\n      |\n=========\n", "\n  +---+\n      |\n      |\n      |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"};

void welcome_player ();

int main()
{
    welcome_player ();
    
    char *words[10] = {"one", "hello", "dogs", "eldeeb", "ramadan", "elnady", "one", "hello", "dogs", "eldeeb"}; // set of words
    int random;                                                                                                  // random number entered by user to get random word from set of words

    char *word;             // Used to store the user word. Most words are less than 20 characters so the default size is 20.
    char wrong_letters[10]; // to keep track of each wrong letter entered by user
    int len;                // len is the length of the word entered.
    char guess_word[20];    // ch is a temporary character variable.
    int strikes = 0;        // strikes counts how many wrong characters the user has guessed.
    int trigger = 0;        // The trigger variable serves as a flag in the for loops bellow.
    int wincounter = 0;     // wincounter keeps track of the number of correct guesses.
    int i;                  // Another counter variable to be used in for loops.

    
    do
    {
        printf("Enter random number from 1 to 10: ");
        scanf("%d", &random);
        getchar();
    } while (!( random >= 1 && random <= 10));
    
    
   

    word = words[random-1];

    len = strlen(word); // Make len equal to the length of the word.

    char dots[len]; // A string full of . that are replaced upon the user entering the right letter of the word.
    // Fill the stars string with . according to the input word length (len)

    for (int counter = 0; counter < len; counter++)
        for (int counter = 0; counter < len; counter++)
        {
            dots[counter] = '.';
        }

    dots[len] = '\0'; // Insert the terminating string character at the end of the dots string.

    // Enter main program loop where guessing and checking happens. this condition is for length of the word + 10 strike characters.
    for (int counter = 0; counter < len + 10; counter++)
    {

        if (wincounter == len) // If the number of correct guesses matches the length of the word it means that the user won.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }

        if (strikes == 10) // If the user makes 10 wrong guesses it means that he lost.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }

        printf("\n\n\n\n%s", dots); // Print the dots string (i.e: h.ll. for hello).

        printf("\n\nGuess a letter or word: "); // Have the user guess a letter.
        fgets(guess_word, 20, stdin);
        if (strlen(guess_word) > 2)
        {
            if (!strncmp(word, guess_word, strlen(word)))
            {
                printf("\nYou win!\n");
            }
            else
            {
                printf("\n\nThe word was: %s\n", word);
                printf("\nYou Lose!\n");
            }

            return 0;
        }

        for (i = 0; i < len; i++) // Run through the string checking the characters.
        {
            if (word[i] == guess_word[0])
            {
                dots[i] = guess_word[0]; // If the guess is correct, replace it in the dotsdx string.
                trigger++;               // If a character the user entered matches one of the initial word, change the trigger to a non zero value.
                wincounter++;            // Increase the number of correct guesses.
            }
        }

        if (trigger == 0)
        {
            printf(hangman[strikes]);
            wrong_letters[strikes] = guess_word[0];
            strikes++; // If the trigger is not a non zero value, increase the strikes counter because that means that the user input character didn't match any character of the word.
            printf("Wrong letters are: ");
            for (int i = 0; i < strikes; i++)
            {
                printf("%c ", wrong_letters[i]);
            }
        }

        trigger = 0; // Set the trigger to 0 again so the user can guess a new character.
    }
}

void welcome_player () {
    printf(" ##::::'##::::'###::::'##::: ##::'######:::'##::::'##::::'###::::'##::: ##:\n");
    printf(" ##:::: ##:::'## ##::: ###:: ##:'##... ##:: ###::'###:::'## ##::: ###:: ##:\n");
    printf(" ##:::: ##::'##:. ##:: ####: ##: ##:::..::: ####'####::'##:. ##:: ####: ##:\n");
    printf(" #########:'##:::. ##: ## ## ##: ##::'####: ## ### ##:'##:::. ##: ## ## ##:\n");
    printf(" ##.... ##: #########: ##. ####: ##::: ##:: ##. #: ##: #########: ##. ####:\n");
    printf(" ##:::: ##: ##.... ##: ##:. ###: ##::: ##:: ##:.:: ##: ##.... ##: ##:. ###:\n");
    printf(" ##:::: ##: ##:::: ##: ##::. ##:. ######::: ##:::: ##: ##:::: ##: ##::. ##:\n");
    printf("..:::::..::..:::::..::..::::..:::......::::..:::::..::..:::::..::..::::..::\n");
}