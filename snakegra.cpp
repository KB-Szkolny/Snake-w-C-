#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
  	
    int szerokosc, dlugosc;
    cout << "Podaj szerokosc planszy: ";
	cin >> szerokosc;
    cout << "Podaj dlugosc planszy: ";
	cin >> dlugosc;

    char plansza[szerokosc][dlugosc];
    int gwiazdki = 0;

	for (int i = 0; i < szerokosc; i++) {
        for (int j = 0; j < dlugosc; j++) {
            plansza[i][j] = ' ';
        }
    }
        
//	góra i dół - ścianki
    for (int i = 0; i < dlugosc; i++) {
        plansza[0][i] = (char)254u;
        plansza[szerokosc-1][i] = (char)254u;
    }

//	lewo i prawo - ścianki
    for (int i = 0; i < szerokosc; i++) {
        plansza[i][0] = '|';
        plansza[i][dlugosc-1] = '|';
    }

//	losowanie kordynatów gracza
    srand(time(0));
    int graczX = rand() % (szerokosc - 2) + 1, graczY = rand() % (dlugosc - 2) + 1;
    plansza[graczX][graczY] = 'o';

//	losowanie kordynatów gwiazdki
    int gwiazdkaX = rand() % (szerokosc - 2) + 1, gwiazdkaY = rand() % (dlugosc - 2) + 1;
    plansza[gwiazdkaX][gwiazdkaY] = '*';

    for (int i = 0; i < szerokosc; i++) {
        for (int j = 0; j < dlugosc; j++) {
            cout << plansza[i][j] << " ";
        }
        cout << endl;  
    }
    cout << "Zebrane gwiazdki: " << gwiazdki << endl;
        
    char sterowanie;
    while(true) {
        sterowanie = _getch();
        switch(sterowanie){
            case 72: // Strzałka w górę
                if (graczX > 1) {
					system("cls");
                    if(graczX-1==gwiazdkaX && graczY==gwiazdkaY) {
                        plansza[gwiazdkaX][gwiazdkaY] = ' ';
                        gwiazdkaX = rand() % (szerokosc - 2) + 1;
                        gwiazdkaY = rand() % (dlugosc - 2) + 1;
                        plansza[gwiazdkaX][gwiazdkaY] = '*';
                        gwiazdki++;
                    }
                    plansza[graczX][graczY] = ' ';
                    graczX--;
                    plansza[graczX][graczY] = 'o';
                }
                break;
                
            case 80: // Strzałka w dół
                if (graczX < szerokosc - 2) {
					system("cls");
                    if(graczX+1==gwiazdkaX && graczY==gwiazdkaY) {
                        plansza[gwiazdkaX][gwiazdkaY] = ' ';
                        gwiazdkaX = rand() % (szerokosc - 2) + 1;
                        gwiazdkaY = rand() % (dlugosc - 2) + 1;
                        plansza[gwiazdkaX][gwiazdkaY] = '*';
                        gwiazdki++;
                    }
                    plansza[graczX][graczY] = ' ';
                    graczX++;
                    plansza[graczX][graczY] = 'o';
                }
                break;
                
            case 75: // Strzałka w lewo
                if (graczY > 1) { system("cls");
                    if(graczX==gwiazdkaX && graczY-1==gwiazdkaY) {
                        plansza[gwiazdkaX][gwiazdkaY] = ' ';
                        gwiazdkaX = rand() % (szerokosc - 2) + 1;
                        gwiazdkaY = rand() % (dlugosc - 2) + 1;
                        plansza[gwiazdkaX][gwiazdkaY] = '*';
                        gwiazdki++;
                    }
                    plansza[graczX][graczY] = ' ';
                    graczY--;
                    plansza[graczX][graczY] = 'o';
                }
                break;
                
            case 77: // Strzałka w prawo
                if (graczY < dlugosc - 2) {system("cls");
                    if(graczX==gwiazdkaX && graczY+1==gwiazdkaY) {
                        plansza[gwiazdkaX][gwiazdkaY] = ' ';
                        gwiazdkaX = rand() % (szerokosc - 2) + 1;
                        gwiazdkaY = rand() % (dlugosc - 2) + 1;
                        plansza[gwiazdkaX][gwiazdkaY] = '*';
                        gwiazdki++;
                    }
                    plansza[graczX][graczY] = ' ';
                    graczY++;
                    plansza[graczX][graczY] = 'o';
                }
                break;           
        }
        
		system("cls");   
        for (int i = 0; i < szerokosc; i++) {
            for (int j = 0; j < dlugosc; j++) {
                cout << plansza[i][j] << " ";
            }
            cout << endl;
        } 
        cout << "Zebrane gwiazdki: " << gwiazdki << endl;
        Sleep(30);
    }
    return 0;
}