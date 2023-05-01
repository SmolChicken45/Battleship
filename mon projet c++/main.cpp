#include <iostream>
#include <random>
using namespace std;

int random(){
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(1, 10);
	return(distr(eng));
}
int randombool(){
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(0, 1);
	return(distr(eng));
}
int main() {

	int ship[10][10]{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	int randomshipCA(); {
		int Carrier[5][2];
		int x = random();
		int y = random();
		int rotate = randombool();//0 horizontal, 1 vertical
		while (x < 3 && y < 3 || x < 3 && y > 8 || x > 8 && y < 3 || x > 8 && y > 8) {
			x = random();
			y = random();
		}
		if (x > 3 && y > 3 || x > 3 && y < 8 || x < 8 && y > 3 || x < 8 && y < 8) {
			if (x < 3 || x> 8) {
				rotate = 0;
			}
			else if (y < 3 || y> 8) {
				rotate = 1;
			}
			if (rotate == 0) {
				Carrier[0][0] = x - 1;
				Carrier[0][1] = y - 3;
				Carrier[1][0] = x - 1;
				Carrier[1][1] = y - 2;
				Carrier[2][0] = x - 1;
				Carrier[2][1] = y - 1;
				Carrier[3][0] = x - 1;
				Carrier[3][1] = y;
				Carrier[4][0] = x - 1;
				Carrier[4][1] = y + 1;
			}
			else if (rotate == 1) {
				Carrier[0][0] = x - 3;
				Carrier[0][1] = y - 1;
				Carrier[1][0] = x - 2;
				Carrier[1][1] = y - 1;
				Carrier[2][0] = x - 1;
				Carrier[2][1] = y - 1;
				Carrier[3][0] = x;
				Carrier[3][1] = y - 1;
				Carrier[4][0] = x + 1;
				Carrier[4][1] = y - 1;
			}
			for (int i = 0; i < 5; i++) {
				ship[Carrier[i][0]][Carrier[i][1]] = 1;
			}
		}

	}
	int randomshipBS(); {
		int Battleship[4][2];
		int x = random();
		int y = random();
		int rotate = randombool();
		while (x < 3 && y < 3 || x < 3 && y > 9 || x > 9 && y < 3 || x > 9 && y > 9|| ship[x-1][y-3] == 1 || ship[x-1][y-2] == 1 || ship[x-1][y-1] == 1 || ship[x-1][y] == 1 ||ship[x-3][y-1] == 1 || ship[x-2][y-1] == 1|| ship[x][y-1] == 1) {
			x = random();
			y = random();
		}
		if (x > 3 && y > 3 || x > 3 && y < 9 || x < 9 && y > 3 || x < 9 && y < 9) {
			if (x < 3 || x> 9) {
				rotate = 0;
			}
			else if (y < 3 || y> 9) {
				rotate = 1;
			}
			if (rotate == 0) {
				Battleship[0][0] = x - 1;
				Battleship[0][1] = y - 3;
				Battleship[1][0] = x - 1;
				Battleship[1][1] = y - 2;
				Battleship[2][0] = x - 1;
				Battleship[2][1] = y - 1;
				Battleship[3][0] = x - 1;
				Battleship[3][1] = y;
			}
			else if (rotate == 1) {
				Battleship[0][0] = x - 3;
				Battleship[0][1] = y - 1;
				Battleship[1][0] = x - 2;
				Battleship[1][1] = y - 1;
				Battleship[2][0] = x - 1;
				Battleship[2][1] = y - 1;
				Battleship[3][0] = x;
				Battleship[3][1] = y - 1;
			}
			for (int i = 0; i < 4; i++) {
				ship[Battleship[i][0]][Battleship[i][1]] = 1;
			}
		}

	}
	int randomshipCR(); {
		int Cruiser[3][2];
		int x = random();
		int y = random();
		int rotate = randombool();
		while (x < 2 && y < 2 || x < 2 && y > 9 || x > 9 && y < 2 || x > 9 && y > 9 || ship[x - 1][y - 2] == 1 || ship[x - 1][y - 1] == 1 || ship[x - 1][y] == 1|| ship[x - 2][y - 1] == 1 || ship[x][y - 1] == 1) {
			x = random();
			y = random();
		}
		if (x > 2 && y > 2 || x > 2 && y < 9 || x < 9 && y > 2 || x < 9 && y < 9) {
			if (x < 2 || x> 9) {
				rotate = 0;
			}
			else if (y < 2 || y> 9) {
				rotate = 1;
			}
			if (rotate == 0) {
				Cruiser[0][0] = x - 1;
				Cruiser[0][1] = y - 2;
				Cruiser[1][0] = x - 1;
				Cruiser[1][1] = y - 1;
				Cruiser[2][0] = x - 1;
				Cruiser[2][1] = y;
			}
			else if (rotate == 1) {
				Cruiser[0][0] = x - 2;
				Cruiser[0][1] = y - 1;
				Cruiser[1][0] = x - 1;
				Cruiser[1][1] = y - 1;
				Cruiser[2][0] = x;
				Cruiser[2][1] = y - 1;
			}
			for (int i = 0; i < 3; i++) {
				ship[Cruiser[i][0]][Cruiser[i][1]] = 1;
			}
		}

	}
	int randomshipSM(); {
		int Submarine[3][2];
		int x = random();
		int y = random();
		int rotate = randombool();
		while (x < 2 && y < 2 || x < 2 && y > 9 || x > 9 && y < 2 || x > 9 && y > 9 || ship[x - 1][y - 2] == 1 || ship[x - 1][y - 1] == 1 || ship[x - 1][y] == 1 || ship[x - 2][y - 1] == 1 || ship[x][y - 1] == 1) {
			x = random();
			y = random();
		}
		if (x > 2 && y > 2 || x > 2 && y < 9 || x < 9 && y > 2 || x < 9 && y < 9) {
			if (x < 2 || x> 9) {
				rotate = 0;
			}
			else if (y < 2 || y> 9) {
				rotate = 1;
			}
			if (rotate == 0) {
				Submarine[0][0] = x - 1;
				Submarine[0][1] = y - 2;
				Submarine[1][0] = x - 1;
				Submarine[1][1] = y - 1;
				Submarine[2][0] = x - 1;
				Submarine[2][1] = y;
			}
			else if (rotate == 1) {
				Submarine[0][0] = x - 2;
				Submarine[0][1] = y - 1;
				Submarine[1][0] = x - 1;
				Submarine[1][1] = y - 1;
				Submarine[2][0] = x;
				Submarine[2][1] = y - 1;
			}
			for (int i = 0; i < 3; i++) {
				ship[Submarine[i][0]][Submarine[i][1]] = 1;
			}
		}

	}
	int randomshipDS(); {
		int Destroyer[2][2];
		int x = random();
		int y = random();
		int rotate = randombool();
		while (x < 2 && y < 2 || x < 2 && y > 10 || x > 10 && y < 2 || x > 10 && y > 10 || ship[x - 1][y - 2] == 1 || ship[x - 1][y - 1] == 1 || ship[x - 2][y - 1] == 1) {
			x = random();
			y = random();
		}
		if (x > 2 && y > 2 || x > 2 && y < 10 || x < 10 && y > 2 || x < 10 && y < 10) {
			if (x < 2 || x> 9) {
				rotate = 0;
			}
			else if (y < 2 || y> 9) {
				rotate = 1;
			}
			if (rotate == 0) {
				Destroyer[0][0] = x - 1;
				Destroyer[0][1] = y - 2;
				Destroyer[1][0] = x - 1;
				Destroyer[1][1] = y - 1;
			}
			else if (rotate == 1) {
				Destroyer[0][0] = x - 2;
				Destroyer[0][1] = y - 1;
				Destroyer[1][0] = x - 1;
				Destroyer[1][1] = y - 1;
			}
			for (int i = 0; i < 2; i++) {
				ship[Destroyer[i][0]][Destroyer[i][1]] = 1;
			}
		}

	}
	int hits = 0;
	int numberofturns = 0;
	cout << "Battleship\n";
	cout << "Debut de la partie";
	while (hits < 17) {
		int row, column;

		cout << "\n\nChoisissez les coordonnes\n";
		cout << "\tSelectionner la range (1 a 10)\n";
		cin >> row;
		row--;
		cout << "\tSelectionner la colonne (1 a 10)\n";
		cin >> column;
		column--;
		
		if (ship[row][column] == 1) {
			ship[row][column] = 3;
			hits++;
			cout << "Touche\n\n ";
		}
		else {
			ship[row][column] = 2;
			cout << "\nA l'eau\n\n";
		}
		cout << "\t1. 2. 3. 4. 5. 6. 7. 8. 9. 10\n";
		for (int i = 0; i < 10; i++) {
			
			cout << "\n";
			cout << i + 1;
			cout << ".\t";
			for (int j = 0;j < 10; j++) {
				if (ship[i][j] == 2){
					cout << "O, ";
				}
				else if (ship[i][j] == 3) {
					cout << "X, ";
				}
				else {
					cout << "0, ";
				}
			}
		}
		numberofturns++;
	}
	cout << "\nVictoire!\n";
	cout << "Vous avez gagne en " << numberofturns << " coups.";
}