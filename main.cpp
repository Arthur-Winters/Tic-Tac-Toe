// Libraries
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

// Function prototype
void drawBoard( char *spaces );
void playerMove( char *spaces, char player );
void computerMove( char *spaces, char computer );
char checkWinner( char *spaces, char player, char computer );
void checkTie( char *spaces );

// Main function
int main()
{
  char spaces[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
  char player = 'X';
  char computer = 'O';
  char winner;

  drawBoard( spaces );
  while( true ){
    playerMove( spaces, player );
    drawBoard( spaces );
    winner = checkWinner( spaces, player, computer );
    if( winner == 'p' ){
      cout << "Player wins\n";
      return 0;
    }
    if( winner == 'c' ){
      cout << "Computer wins\n";
      return 0;
    }

    computerMove( spaces, computer );
    drawBoard( spaces );
    winner = checkWinner( spaces, player, computer );
    if( winner == 'p'){
      cout << "Player wins\n";
      return 0;
    }
    if( winner == 'c' ){
      cout << "Computer wins\n";
      return 0;
    }
  }
  return 0;
}
// Printing Tic-Tac-Toe board
void drawBoard( char *spaces )
{
  system( "clear" );
  cout << "     |     |     \n";
  cout << "  " << spaces[ 0 ] << "  |  " << spaces[ 1 ] << "  |  " << spaces[ 2 ] << "  \n";
  cout << "_____|_____|_____\n";
  cout << "     |     |     \n";
  cout << "  " << spaces[ 3 ] << "  |  " << spaces[ 4 ] << "  |  " << spaces[ 5 ] << "  \n";
  cout << "_____|_____|_____\n";
  cout << "     |     |     \n";
  cout << "  " << spaces[ 6 ] << "  |  " << spaces[ 7 ] << "  |  " << spaces[ 8 ] << "  \n";
  cout << "     |     |     \n";
}
void playerMove( char *spaces, char player )
{
  int num;
  cout << "Enter your move ( 1-9 ): ";
  cin >> num;
  num--;
  if( spaces[ num ] == ' ' ){
    spaces[ num ] = player;
    return;
  }
  cout << "Invalid move. Retry\n";
}
void computerMove( char *spaces, char computer )
{
  int random;
  srand( time( 0 ) );
  random = rand() % 9;
  while( true ){
    if( spaces[ random ] == ' ' ){
      spaces[ random ] = computer;
      return;
    }
    random = rand() % 9;
  }
}
char checkWinner( char *spaces, char player, char computer )
{
  int pos1, pos2, pos3;
  int winningPos[8][3] = {
    { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 },
    { 0, 3, 6 }, { 1, 4, 7 }, {2, 4, 8 },
    { 0, 4, 8 }, { 2, 4, 6 }
  };
  for( int i = 0; i < 8; i++ ){
    pos1 = winningPos[i][0];
    pos2 = winningPos[i][1];
    pos3 = winningPos[i][2];

    if( spaces[ pos1 ] != ' ' && spaces[ pos1 ] == spaces[ pos2 ] && spaces[ pos2 ] == spaces[ pos3 ] ){
      return ( spaces[pos1] == player )? 'p' : 'c';
    }
  }
  checkTie( spaces );
  return 't';
}

void checkTie( char *spaces )
{
  for( int i = 0; i < 9; i++ ){
    if( spaces[ i ] == ' ' ){
      return;
    }
  }
  cout << "It's a tie\n";
  exit( 0 );
}
