#include <iostream>
using namespace std;

void draw(string boxes[9]) {
  cout << "-------------\n| " 
    << boxes[0] << " | " 
    << boxes[1] << " | " 
    << boxes[2] << " |\n-------------\n| " 
    << boxes[3] << " | " 
    << boxes[4] << " | " 
    << boxes[5] << " |\n-------------\n| " 
    << boxes[6] << " | " 
    << boxes[7] << " | " 
    << boxes[8] << " |\n-------------\n";
}

bool checkWinner(string player, string boxes[9]) {
  bool winner = false;

  string symbol;

  if(player == "1") {
    symbol = "x";
  }

  if(player == "2") {
    symbol = "o";
  }

  if(
    (boxes[0] == symbol && boxes[1] == symbol && boxes[2] == symbol) ||
    (boxes[3] == symbol && boxes[4] == symbol && boxes[5] == symbol) ||
    (boxes[6] == symbol && boxes[7] == symbol && boxes[8] == symbol) ||
    (boxes[0] == symbol && boxes[3] == symbol && boxes[6] == symbol) ||
    (boxes[1] == symbol && boxes[4] == symbol && boxes[7] == symbol) ||
    (boxes[2] == symbol && boxes[5] == symbol && boxes[8] == symbol) ||
    (boxes[0] == symbol && boxes[4] == symbol && boxes[8] == symbol) ||
    (boxes[2] == symbol && boxes[4] == symbol && boxes[6] == symbol)
  ) {
    winner = true;
  }

  return winner;
}

int main() {
  cout << "Welcome to three in a row!!! \nPush enter to continue";

  cin.get();

  cout << "Let's play\n";

  bool finish = false;

  string player = "1";

  string boxes [9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

  int turns = 0;

  while(finish == false){
    draw(boxes);

    int box;

    string symbol;

    if(player == "1") {
      symbol = "x";
    }

    if(player == "2") {
      symbol = "o";
    }

    bool correctInput = false;

    while(correctInput == false){
      cout << "Select a box\n";

      int input;

      cin >> input;

      bool repeated = false;

      int boxesIndex = 0;

      while(repeated == false && boxesIndex < 9) {
        if(boxesIndex == input && boxes[boxesIndex] != " ") {
          repeated = true;
        } else {
          boxesIndex++;
        }
      }

      if(input >= 0 && input < 9 && repeated == false) {
        box = input;

        correctInput = true;
      }
    }

    boxes[box] = symbol;

    bool winner = checkWinner(player, boxes);

    if(winner == true) {
      draw(boxes);

      cout << "The winner is player " << player << "\n";

      finish = true;

      break;
    }

    turns++;

    if(turns == 9){
      cout << "This is a draw\n";

      finish = true;

      break;
    }

    if(player == "1") {
      player = "2";
    } else {
      player = "1";
    }
  }

  return 0;
}
