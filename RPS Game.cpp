#include<iostream>
#include<string>

using std:: cin;  using std:: rand;
using std:: cout; using std:: string;
using std:: endl;

//holds total number of wins
int win;
//holds total number of losses
int loss;
//holds total number of ties
int tie;
//holds total number of games
int games;
char weaponSelect();
char randomSelect();
void game(char player, char computer);
int score();

int main() {
    //used to hold input from user on how many rounds they would like to play.
    int rounds;
    //used to hold input from user on whether or not they would like to see their score.
    string s;
    cout << "This is a simple game of rock, paper, scissors." <<
    "You can pick either rock(r), paper(p), or scissors(s)" << endl;
    cout << "How many rounds would you like to play? ";
    cin >> rounds;
    //plays the set amount of rounds and stops once they're done
    while (rounds != 0) {
        char wep1 = weaponSelect();
        char wep2 = randomSelect();
        game(wep1, wep2);
        cout << endl;
        rounds--;
    }
    cout<< "Would you like a score count for the games you played? ";
    cin >> s;
    //if yes calculate the scores
    if(s == "yes") score();
    //if no print a goodbye message
    if(s == "no") {
        cout << "Alright then, have a nice day." << endl;
    }
    return 0;
}

//creates a weapon for the player
char weaponSelect() {
    char wep;
    cout << "Please choose a weapon to use against the computer: ";
    cin >> wep;
    /*makes sure that the player only picks rock,paper,or scissors
     *if not continue to ask for proper input
     */
    while (wep != 'r' && wep !='p' && wep !='s'){
        cout << endl;
        cout << "Please choose a proper weapon." <<
        "It can either be rock(r), paper(p), or scissors(s)" << endl;
        cout << "Please choose a weapon to use against the computer: ";
        cin >> wep;
    }
     return wep;
}

//randomly generates a weapon that the computer will use
char randomSelect() {
    //ensures that the weapon is randomized each round
    srand(time(0));
    //array that holds ASCII codes for 'r', 'p',and 's'
    int wepcodes[3] = {114,115,112};
    //randomly generates a number between 0-2
    int x = rand() %3;
    //initializes a char based on the ASCII code
    char wep = wepcodes[x];
    return wep;
}

//plays the game
void game(char player, char computer){
    //increment the amount of games by 1 each time this method is called
    games++;
    cout << endl;
    //prints player weapon
    cout << "You played " << player << endl;
    //prints computer weapon
    cout << "The computer played " << computer << endl;
    //checks for cases where the player won
    if ((player == 'r' && computer == 's') ||
        (player == 'p' && computer == 'r') ||
        (player == 's' && computer == 'p')) {
            ++win;
            cout << "You Won! Congratulations!" << endl;
    }
    //checks for cases where the player lost
    else if ((computer == 'r' && player == 's') ||
            (computer == 'p' && player == 'r') ||
            (computer == 's' && player == 'p')) {
                ++loss;
                cout << "You Lost, better luck next time" << endl;
    }
    //checks for cases of a tie
    else if (player == computer){
        ++tie;
        cout << "It was a tie, the mind games intensify." << endl;
    }
}

//prints out the score 
int score(){
    /*checks if player lost all of the games
     *if so print out a loser message and terminate the program
     */
    if (win == 0  && tie == 0) {
        cout << "You lost all of your games, there's not much else to say." << endl;
        return 0;
    }
    /*checks if player only had ties or losses
     *if so print out a unique messgae and terminate the program
     */
    else if (win == 0 && tie >= 1){
        cout << "Losses: " << loss << endl;
        cout << "Ties: " << tie << endl;
        cout << "You're an odd player you've only gotten ties and losses." << endl;
        return 0;
    }
    /* if player has won at least one game create an int called ratio
     * which calculates the win ratio of the player and print out
     * cases of wins, losses, and ties
     * the generate a message based on how high or low the ratio is,
     * afterwards terminate the program
     */
    else {
        int ratio = (win/games) *100;
        cout << "Wins: " << win << endl;
        cout << "Losses: " << loss << endl;
        cout << "Ties: " << tie << endl;
        cout << "Win/Loss Ratio: " << ratio << "%" << endl;
        if(ratio <= 49) {
            cout << "You might want to work on your strategy " <<
            "the computer is kicking your butt." << endl;
         }
         else if (ratio == 50) {
            cout << "Hm, you and the computer seem to have a similar playstyle." << endl;
         }
         else {
            cout << "Not bad, you're on your way to becoming a RPS master." << endl;
         }
   }
   return 0;
}
