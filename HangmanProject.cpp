// HANGMAN PROJECT
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string&);

int main()
{
    string name;
    char letter;
    int numOfWrongGuesses = 0;
    string word;
    string words[] = {
        "india",
        "pakistan",
        "nepal",
        "malaysia",
        "phillipines",
        "austrailia",
        "iran",
        "ethiopia",
        "oman",
        "indonesia"
    };
// CHOOSE AND COPY WORDS AT RANDOM
    srand(time(NULL));
    int n = rand() % 10;
    word = words[n];

//INTIALIZE THE SECRET WORD WITH THE * CHARACTER
    string unknown(word.length(), '*');

//WELCOME THE USER
    cout << "\n\nWelcome to Hangman!! Guess a country name: ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\nRULES: ";
    cout << "\n\n1.) Each letter is represented by an asterik (*).";
    cout << "\n\n2.) You have to type only one letter per attempt.";
    cout << "\n\n3.) You have " << MAX_TRIES << " attempts to try and guess the word!";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

//LOOP UNTIL A WRONG GUESS
    while (numOfWrongGuesses < MAX_TRIES) {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;
        //FILL WORD WITH LETTER(S) IF GUESS IS CORRECT
        //OTHER WISE INCREMENT NUMBER OF WRONG GUESSES
        if (letterFill(letter, word, unknown) == 0) {
            cout << "\n\nUH-OH.. THAT LETTER ISN'T IN THERE";
            numOfWrongGuesses++;
        }
        else {
            cout << "\n\nYOU'VE GUESSED CORRECTLY!!";
        }
        //INFORM USER OF HOW MANY TRIES THAT ARE REMAINING
        cout << "\n\nYou have " << MAX_TRIES - numOfWrongGuesses << " guesses left.";
        //CHECK IF THE USER GUESSED THE WORD
        if (word == unknown) {
            cout << word << endl;
            cout << "\n\nCongratulations! You've won!!";
            break;
        }
    }
    if (numOfWrongGuesses == MAX_TRIES) {
        cout << "Game Over. You have exceeded the maximum allowed attempts!";
        cout << "\n\nThe word was: " << word;
    }
    cin.ignore();
    cin.get();
    return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretWord, string& guessWord) {
    int i; 
    int matches = 0;
    int len = secretWord.length();
    for (int i = 0; i < len; i++) {
        //DID WE ALREADY GUESS THIS LETTER IN A PREVIOUS GUESS?
        if (guess == guessWord[i]) {
            return 0;
        }
        //IS THE GUESS IN THE SECRET WORD?
        if (guess == secretWord[i]) {
            guessWord[i] = guess;
            matches++;
        }
    }
    return matches;
}
