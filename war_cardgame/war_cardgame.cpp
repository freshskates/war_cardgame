#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <ctime>

int getcard(int plus, int max) {
    return (plus) + (rand() % max);
}
void card(int number, int club, string who) {
    
    string clubname;
    switch (club) {
    case 0:
        clubname = "Spades";
        break;
    case 1:
        clubname = "Diamonds";
        break;
    case 2:
        clubname = "Hearts";
        break;
    case 3: 
        clubname = "Clubs";
        break;
    }

    if (number > 10) {

        switch (number) {
        case 11:
            cout << who << "'s card is a Jack of " << clubname << endl;
            break;
        case 12:
            cout << who << "'s card is a Queen of " << clubname << endl;
            break;
        case 13:
            cout << who << "'s card is a King of " << clubname << endl;
            break;
        case 14:
            cout << who << "'s card is a Ace of " << clubname << endl;
            break;
        }
    }

    else {

        cout << who << "'s card is a " << number <<  " of " << clubname << endl;
    }

    

}
void play() {
    bool again = false; 
    char playagain;
    int cpu, player, cpu_c, player_c;
    do {
        cpu = getcard(2, 13);
        player = getcard(2, 13);
        cpu_c = getcard(0, 3);
        player_c = getcard(0, 3);
        
        card(cpu, cpu_c, "Computer");
        card(player, player_c, "Human");


        if (cpu == player) {

            cout << "It's a tie!" << endl;

        }
        else if (cpu < player) {
            cout << "Human wins!" << endl;
        }
        else {
            cout << "Computer wins!";
        }

        cout << "Play again? Y/N: ";
        cin >> playagain;
        cin.ignore(1000, 10);
        playagain = toupper(playagain);
        if (playagain == 'Y') {
            again = true; 
        }
        else {
            again = false; 
        }

    } while (again == true);
}

int main()
{
    srand(time(0));
    play();
}