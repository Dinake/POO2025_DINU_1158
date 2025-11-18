#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Combustibil { BENZINA = 1, DIESEL = 2, ELECTRIC = 3, HIBRID = 4 };

class  Motocicleta {
public:
	char* marca = nullptr;
	string model = "Necunoscut";
	int nrKm = 0;
	Combustibil combustibil = BENZINA;

	void afisareMotocicleta() {
		cout << endl << "Motocicleta avand marca ";
		if (this->marca != nullptr) {
			cout << this->marca;
		}

		cout << ", model " << this->model << " are " << this->nrKm << " km, combustibilul fiind ";
		if (this->combustibil == BENZINA) {
			cout << "BENZINA";
		}
		else if (this->combustibil == DIESEL) {
			cout << "DIESEL";
		}
		else if (this->combustibil == ELECTRIC) {
			cout << "ELECTRIC";
		}
		else if (this->combustibil == HIBRID) {
			cout << "HIBRID";
		}

		cout << ".";
	}
};

int main() {

	Motocicleta moto1;

	moto1.marca = new char[strlen("Honda") + 1];
	strcpy(moto1.marca, "Honda");
	moto1.model = "CBR";
	moto1.nrKm = 10000;
	moto1.combustibil = BENZINA;

	moto1.afisareMotocicleta();

	Motocicleta moto2;

	moto2.marca = new char[strlen("Kawasaki") + 1];
	strcpy(moto1.marca, "Kawasaki");
	moto2.model = "Ninja 7 Hybrid";
	moto2.nrKm = 10000;
	moto2.combustibil = HIBRID;

	moto2.afisareMotocicleta();


	
	delete[] moto1.marca;
	delete[] moto2.marca;
	return 0;
}