#include <iostream>
using namespace std;

int numRow = 8;
int numCol = 8;
int hp = 5;
char letterRange = 'F';
int hpBoard[8][8];
char letterBoard[8][8];
int row1, col1, row2, col2;

void clear(){
    //use clear in MacOS
    system("clear");

    //use cls in Window
    //system("cls");
}

void printNumLine(){
    cout << "    ";
    for(int i=1;i<numCol+1;i++){
        cout << i << " ";
    }
    cout << endl;
}
void printHeaderLine(){
    cout << "  +-";
    for(int i=0;i<numCol*2;i++){
        cout << "-";
    }
    cout << "+" << endl;
}

void printSpaceLine(){
    cout << "  |";
    for(int i=0;i<numCol*2;i++){
        cout << " ";
    }
    cout << " |" << endl;
}

//type 0: default
//type 1: selected first piece
//type 2: selected second piece
//type 3: print ans
void printBoard(int type){
    printNumLine();
    printHeaderLine();
    printSpaceLine();
    for(int i=0;i<numRow;i++){
        cout << i+1 << " | ";
        for(int j=0;j<numCol;j++){
            if(type==3){
                cout << letterBoard[i][j]<< " ";
                continue;
            }
            if(type!=0 && row1==i && col1==j){
                cout << letterBoard[i][j]<< " ";
            }else if(type==2 && row2==i && col2==j){
                cout << letterBoard[i][j]<< " ";
            }else if(hpBoard[i][j]>0){
                cout << hpBoard[i][j] << " ";
            }else{
                cout << "  ";
            }
        } 
        cout << "| " << i+1 << endl;
        printSpaceLine();
    }
    printHeaderLine();
    printNumLine();
}


void startGame(){
    clear();
    //initialize the board
	for(int i=0;i<numRow;i++){
       for(int j=0;j<numCol;j++){
            hpBoard[i][j]= hp;
        } 
    }
    for(int i=0;i<numRow;i++){
       	for(int j=0;j<numCol;j++){
            letterBoard[i][j] = 65 + (rand() % (letterRange-65));
        } 
    }
    //main game flow
    while(true){
        printBoard(0);
        
        cout << endl << "Please select the first piece." << endl;
        cout << "Row:";
        cin >> row1;
        cout << "Column:";
        cin >> col1;
        row1--;
        col1--;
        printBoard(1);

        cout << endl << "Please select the second piece." << endl;
        cout << "Row:";
        cin >> row2;
        cout << "Column:";
        cin >> col2;
        row2--;
        col2--;
        printBoard(2);

        if(letterBoard[row1][col1]==letterBoard[row2][col2]){
            cout << endl << "Matched!" << endl << endl;
            hpBoard[row1][col1] = -1;
            hpBoard[row2][col2] = -1;
        }else{
            cout << endl << "Not Match! Decreased by one!" << endl << endl;
            hpBoard[row1][col1] -= 1;
            hpBoard[row2][col2] -= 1;
            if(hpBoard[row1][col1]==0 || hpBoard[row2][col2]==0){
                cout << endl << "You Lost!" << endl << endl;
				cout << "Sample solution:" << endl;
                printBoard(3);
                break;
            }
        }
    }

}

void changeBoardSize() {
	while(true) {
		cout << "The default board size is 8 * 8" << endl;
		cout << "(numbe of row * number of column must equal to a even number)" << endl;
		cout << "Change the row (2-9): ";
		cin >> numRow;
		cout << "Change the colum (2-9): ";
		cin >> numCol;

		if ((numRow < 2) || (numCol < 1) || (numRow > 9) || (numCol > 9) || ((numRow * numCol) % 2 == 1)) {
			cout << "Invalid value! try again" << endl;
		}else {
			cout << endl << "The board size is changed！" << endl;
			break;
		}
	}
}

void changeMaxHP() {
	while(true){
		cout << "(2 - 9, default is 5) Number of trials: " ;
		cin >> hp;
		if (hp < 2 || hp > 9) {
			cout << "Invalid value! try again" << endl;
		}else {
			cout << endl << "The max HP is changed！" << endl;
			break;
		}
	}
}

void changeLetterRange() {
	while(true) {
		cout << "(A - Z must upper case, default is A to F) Range of letters : A - ? " ;
		cin >> letterRange;
		if (letterRange == 'A') {
			cout << "Too less! try again" << endl;
		}
		else {
			cout << endl << "The letter range is changed！" << endl;
			break;
		}
	}

}
void settings() {
	int option;
	cout << endl << "*** Settings Menu ***" << endl;
	cout << "[1] Change Board Size" << endl;
	cout << "[2] Change Max HP" << endl;
	cout << "[3] Change Letter Range" << endl;
	cout << "[4] Return to Main Menu" << endl;
	cout << "*****************" << endl;
	cout << "Option(1 - 4): ";
	cin >> option;
	cout << endl << endl;

	switch (option) {
	case 1: changeBoardSize();  break;
	case 2: changeMaxHP();  break;
	case 3: changeLetterRange();  break;
	case 4: break;
	default: break;
	}
}

int main(){
    int option;
    while (true)
    {
        cout << "\n*** Main Menu ***" << endl;
		cout << "[1] Start Game" << endl;
		cout << "[2] Settings" << endl;
		cout << "[3] Exit" << endl;
		cout << "*****************" << endl;
		cout << "Option (1 - 3) : ";
		cin >> option;
		switch (option) {
            case 1: startGame();  break;
            case 2: settings(); break;
            case 3: break;
            default: cout << "Error! please enter again" << endl; break;
        }
    }

    return 0;
}
