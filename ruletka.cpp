
#include <iostream>

using namespace std;
// Jakub Olchowy, Szymon Osiecki, Władysław Farat - projekt nr. 5
//Struktura odpowiadajaca za podstawowe funkcje gry, trzymanie danych o grze
struct Gra {
	//dane gry
	const int zycia[3] = { 1, 2 ,3 };
	const double ilosc_naboi[3] = { 4, 6 ,8 };
	const double prawdziwe[3] = { 50, 66, 75 };
	//dane obecnej instancji gry
	int tura = 1;
	int nr_naboju = 1;
	int* naboje = nullptr;
	//funkcja odpowiadajaca za losowe zaladowanie broni
	void zaladuj_bron(double ile, double szansa) {
		//zainicjalizowanie tabeli
		if (naboje != nullptr) rozladuj_bron();
		naboje = new int[ile];
		//obliczenie ile powinno byc naboi prawdziwych a ile falszywych
		double prawdziwe = ile * (szansa / 100);
		int falszywe = ile - prawdziwe;
		//inicjalizacja randa
		srand((unsigned)time(0));
		//wypelnienie tabeli wartosciami
		for (int i = 0; i < ile; i++) {
			int rzut = rand() % 100;
			if ((rzut < szansa && prawdziwe > 0) || falszywe == 0) {
				naboje[i] = 1;
				prawdziwe--;
			}
			else {
				naboje[i] = 0;
				falszywe--;
			}
		}
	}
	void rozladuj_bron() {
		delete[] naboje;
		naboje = nullptr;
	}
};
//struktura odpowiadajaca za gracza
struct Gracz {
	int zycia;
	int przedmioty;
};
int main() {
	Gra ruletka;
	ruletka.zaladuj_bron(ruletka.ilosc_naboi[1], ruletka.prawdziwe[1]);
	for (int i = 0; i < ruletka.ilosc_naboi[1]; i++) {
		if (ruletka.naboje[i] == 1) cout << "prawdziwy" << endl;
		else cout << "falszywy" << endl;
	}
	ruletka.rozladuj_bron();
}