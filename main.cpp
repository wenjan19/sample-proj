#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

//TicTacToe variables:


char spc[3][3] = {{'1', '2', '3',}, { '4', '5', '6'}, {'7', '8', '9'}};
char token = 'x';
bool tie = false;
int row, column;
string p1 = "Player 1", p2 = "Player 2";

void TTTtable() {
    cout << " " << endl;
    cout << "TIC TAC TOE" << endl;
    cout << "-----------" << endl;

cout << "   |   |   " << endl;
             cout << " " << spc [0][0] << " | " << spc [0][1] << " | " << spc [0][2] << endl;
cout << "___|___|___" << endl;
             cout << " " << spc [1][0] << " | " << spc [1][1] << " | " << spc [1][2] << endl;
cout << "___|___|___" << endl;
             cout << " " << spc [2][0] << " | " << spc [2][1] << " | " << spc [2][2] << endl;
cout << "   |   |   " << endl;
}

void TTTvalues() {

    int digit;

if (token == 'x')
    {
        cout << p1 << " pick your number: ";
        cin >> digit;
    }
     if (token == 'o')
    {
        cout << p2 << " pick your number: ";
        cin >> digit;
    }

if (digit == 1)
    {
        row = 0;
        column = 0;
    }
     if (digit == 2)
    {
        row = 0;
        column = 1;
    }
if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
if (digit == 9)
    {
        row = 2;
        column = 2;
    }


if (digit >= 10 || digit < 1)
    {
        cout << "Invalid input." << endl;
    }

    if (token == 'x' && spc[row][column] != 'x' && spc[row][column] != 'o')
    {
        spc[row][column] = 'x';
        token = 'o';
    }

else if (token == 'o' && spc[row][column] != 'x' && spc[row][column] != 'o')
    {
        spc[row][column] = 'o';
        token = 'x';
    }

    else
    {
        cout << "no more available space" << endl;
    }

}

bool TTTturns() {

    for (int i = 0; i < 3; i++) {
        if (spc[i][0] == spc[i][1] && spc[i][0] == spc[i][2] || spc[0][i] == spc[1][i] && spc[0][i] == spc[2][i])
        return true;
    }
    if (spc[0][0] == spc[1][1] && spc[1][1] == spc[2][2] || spc[0][2] == spc[1][1] && spc[1][1] == spc[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (spc[i][j] != 'x' && spc[i][j] != 'o')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;

}

//Board Dimension variables:
int columns, rows;

void Bdlines(int columns)
{
    cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        cout << " ---";
    }
    cout << endl;
}

void Bdnums(int columns)
{
    cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        cout << "  " << i + 1 << " ";
    }
    cout << endl;
}

void Bdtable(int rows, int columns)
{
    Bdnums(columns);
    Bdlines(columns);
    for (int i = 0; i < rows; i++)
    {
        cout << " " << char('A' + i);
        for (int j = 0; j < columns; j++)
        {
            cout << " |  ";
        }
        cout << " | " << char('A' + i) << endl;
        Bdlines(columns);
    }
    Bdnums(columns);
}

// Rock, Paper, Scissors functions:

int CPUchoice() {
    srand (time(0));

    int num = rand() % 3 + 1;

    return num;

}

int Userchoice() {

    int pick;
    promptRPS:
    cout << " " << endl;
    cout << "ROCK, PAPER, SCISSORS" << endl;
    cout << "---------------------" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;

    cout << "You pick: ";
    cin >> pick;

    if (pick < 1 || pick > 3)
    {
        cout << "invalid input. try again" << endl;
        goto promptRPS;
    }

    return pick;
}

void showpick(int pick) {
    if (pick == 1)
    {
        cout << "1. Rock" << endl;
    }
    else if (pick == 2)
    {
        cout << "2. Paper" << endl;
    }
    else if (pick == 3)
    {
        cout << "3. Scissors" << endl;
    }
}

void RPSresult(int player, int comp) {

        if (player == 3 && comp == 1)
    {
        cout << "You Lose! Rock crushes Scissors." << endl;
    }
else if (player == 1 && comp == 2)
    {
        cout << "You Lose! Paper defeats Rock." << endl;
    }
       else if (player == 2 && comp == 3)
    {
        cout << "You Lose! Scissors cuts Paper." << endl;
    }

else if (player == 2 && comp == 1)
    {
        cout << "YOU WIN! Paper defeats Rock." << endl;
    }
      else if (player == 3 && comp == 2)
    {
        cout << "YOU WIN! Scissors slashes Paper." << endl;
    }
else if (player == 1 && comp == 3)
    {
        cout << "YOU WIN! Rock crushes Scissors." << endl;
    }
     else
    {
        cout << "IT'S A TIE!" << endl;
    }
}

//Riddle me  variables:
string ans,ans2,ans3,ans4,ans5;
void RMv() {
        cout <<endl<<endl<< "    Welcome to the RIDDLE ME GAME "<<endl << endl;



    cout<< "Riddle: What goes up but never goes down?"<<endl;
    cout<<"clue: it is present everytime you fill up a form"<<endl;
    cout<< "Your answer:";

    cin>>ans;

    if (ans == "age" || ans == "AGE"){

        cout<< "YOUR ANSWER IS CORRECT!!!"<<endl<<endl;
    }
    else {

        cout<< "YOUR ANSWER IS INCORRECT!!!" <<" The correct answer is age/AGE"<<endl<<endl;
    }

    cout<< "Riddle: I'm tall when I'm young,and I'm short when I'm old. What am I?"<<endl;
    cout<<"clue: it provides light"<<endl;
    cout<< "Your answer:";


     cin>>ans2;

    if (ans2 == "candle"|| ans2 == "CANDLE"){

        cout<< "YOUR ANSWER IS CORRECT!!!"<<endl<<endl;
    }
    else {

        cout<< "YOUR ANSWER IS INCORRECT!!!" <<" The correct answer is candle/CANDLE"<<endl<<endl;
    }

    cout<< "Riddle: What has to be broken before you can use it?"<<endl;
    cout<<"clue: it is round"<<endl;
    cout<< "Your answer:";


     cin>>ans3;

    if (ans3 == "egg"|| ans3 =="EGG"){

        cout<< "YOUR ANSWER IS CORRECT!!!"<<endl<<endl;
    }
    else {

        cout<<"YOUR ANSWER IS INCORRECT!!!" <<" The correct answer is egg/EGG"<<endl<<endl;
    }

    cout<< "Riddle: What has many keys but cannot open a single lock?"<<endl;
    cout<<"clue: musical instrument"<<endl;
    cout<< "Your answer:";


     cin>>ans4;

    if (ans4 == "piano"|| ans4 =="PIANO"){

        cout<< "YOUR ANSWER IS CORRECT!!!"<<endl<<endl;
    }
    else {

        cout<<"YOUR ANSWER IS INCORRECT!!!" <<" The correct answer is piano/PIANO"<<endl<<endl;
    }

    cout<< "Riddle: Where does today come before yesterday?"<<endl;
    cout<<"clue: it contains words"<<endl;
    cout<< "Your answer:";


     cin>>ans5;

    if (ans5 == "dictionary"|| ans5 =="DICTIONARY"){

        cout<< "YOUR ANSWER IS CORRECT!!!"<<endl<<endl;
    }
    else {

        cout<<"YOUR ANSWER IS INCORRECT!!!" <<" The correct answer is dictionary/DICTIONARY"<<endl<<endl;
    }
    cout<<endl<<endl<<"    Thank you for participating!"<<endl;

}



// system selection body
int main() {

promptselect:
             int game;
             char cont;

    cout << "SYSTEM SELECTION" <<endl<<endl<<endl;
    cout << "+++++++++++++++++" <<endl<<endl<<endl;
    cout << "1. Tic Tac Toe" << endl;
    cout << "2. Board Dimensions" << endl;
    cout << "3. Rock Paper Scissors" << endl;
    cout << "4. RIDDLE ME" << endl<<endl<<endl;

    cout << "Pick a game you desire: ";
    cin >> game;

    switch (game)
    {
        case 1:
        {
            while (!TTTturns()) {
                TTTtable();
                TTTvalues();
                TTTturns();
            }
            if (token == 'x' && tie == false)
            {
                cout << p2 << " WINS !!" << endl;
            }
            else if (token == 'o' && tie == false)
            {
                cout << p1 << " WINS !!" << endl;
            }
            else if (tie == true)
            {
                cout << "IT'S A TIE!" << endl;
            }
            break;
        }
        case 2:
        {
            cout << " " << endl;
            cout << "BOARD DIMENSIONS" << endl;
            cout << "----------------" << endl;
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> columns;

            Bdtable(rows, columns);

            break;
        }
        case 3:
        {
            int player, comp;

            player = Userchoice();
            cout << "Your Choice is: "<< endl;
            showpick(player);

            comp = CPUchoice();
            cout << "The computer has chosen: " << endl;
            showpick(comp);

            RPSresult (player, comp);

            break;
        }
        case 4:
        {
            RMv();


            break;
        }
    }

    cout << "Would you like to continue using the system? (y or n):" ;
    cin >> cont;

    if (cont == 'y' || cont == 'Y') {
        goto promptselect;
    }
    else if (cont == 'n' || cont == 'N') {
        cout << "Thank you and have a good day!!!" << endl;
        return 0;
    }
}
