
#include <iostream>

using namespace std;
// Jakub Olchowy, Szymon Osiecki, W�adys�aw Farat - projekt nr. 5

int main() {
    int wybor;
    cout << "Wprowadź '1' aby rozpocząć grę";
    cout << "Wprowadź '2' aby zakończyć grę";
    cin >> wybor;
    while (true) {
        if (cin >> wybor) {
            if (wybor == 1) {
                cout << "Wybrano rozpoczecie gry\n";
                break; // Zakończenie pętli, program idzie dalej
            }
            else if (wybor == 2) {
                cout << "Wybrano zakonczenie gry\n";
                return 0; // Zakończenie programu
            }
            else {
                cout << "Wprowadz poprawne dane\n";
            }
        }
        else {
            cout << "Wprowadz poprawne dane\n";
            cin.clear(); // Wyczyszczenie flagi błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie niepoprawnych danych
        }
    }
}