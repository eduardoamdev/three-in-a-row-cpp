#include <iostream>
using namespace std;

void draw(string boxes[9]) {
  cout << "-------------\n| " << boxes[0] << " | " << boxes[1] << " | " << boxes[2] << " |\n-------------\n| " << boxes[3] << " | " << boxes[4] << " | " << boxes[5] << " |\n-------------\n| " << boxes[6] << " | " << boxes[7] << " | " << boxes[8] << " |\n-------------\n";
}

int main() {
  cout << "Bienvenido al tres en raya!!! \nPulsa Enter para continuar";

  cin.get();

  cout << "Este va a ser el inicio del juego\n";

  bool finish = false;

  string player = "1";

  string boxes [9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

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

    cout << "Elige casilla\n";

    cin >> box;

    boxes[box] = symbol;

    if(player == "1") {
      player = "2";
    } else {
      player = "1";
    }
  }

  

  return 0;
}
