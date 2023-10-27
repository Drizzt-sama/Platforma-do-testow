#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

string temat, imie, nazwisko, numeralbumu, wydział, kierunek, semestr, grupalaboratoryjna;
string tresc[5];
string odpA[5], odpB[5], odpC[5], odpD[5];
string poprawna[5];

string odpowiedz;
int punkty = 0;

int main() {

	fstream plik;
	plik.open("test.txt", ios::in);

	if (plik.good() == false) {
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}

	string linia;
	int nr_linii = 1;
	int nr_pytania = 0;

	while (getline(plik, linia)) {
		switch (nr_linii) {
		case 1: temat = linia; break;
		case 2: imie = linia; break;
		case 3: tresc[nr_pytania] = linia; break;
		case 4: odpA[nr_pytania] = linia; break;
		case 5: odpB[nr_pytania] = linia; break;
		case 6: odpC[nr_pytania] = linia; break;
		case 7: odpD[nr_pytania] = linia; break;
		case 8: poprawna[nr_pytania] = linia; break;
		}

		if (nr_linii == 8) {
			nr_linii = 2;
			nr_pytania++;
		}

		nr_linii++;
	}

	plik.close();


	for (int i = 0; i <= 4; i++) {
		cout << endl << tresc[i] << endl;
		cout << "A. " << odpA[i] << endl;
		cout << "B. " << odpB[i] << endl;
		cout << "C. " << odpC[i] << endl;
		cout << "D. " << odpD[i] << endl;

		cout << "Twoja odpowiedz: ";
		cin >> odpowiedz;

		transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);

		if (odpowiedz == poprawna[i]) {
			cout << "Odpowiedz poprawna, zdobywasz punkt!" << endl;
			punkty++;
		}
		else {
			cout << "Odpowiedz niepoprawna, nie zdobywasz punktu. Poprawna odpowiedz: " << poprawna[i] << endl;
		}
	}

	cout << endl << "Koniec testu. Zdobyles "<< punkty <<" punktow.";

	return 0;
}