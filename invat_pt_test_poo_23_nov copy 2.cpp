//aplicatie gestionare activitate firma 3D printing - folosing diferite materiale (lemn, plastic, silicon etc) - pe baza modelelor primite de la clienti
//Definiti o clasa care modeleaza un aspect propriu acestei activitati
//se urmaresc atribute specifice, precum: tipul materialul, numarul de exemplare, dimensiune, categorii, costuri  etc.
// datele membre sunt private si sunt puse la dispozitie metode de acces
// clasa contine cel putin patru campuri, dintre care unul este alocat dinamic, mo
//constructori, metodele specifice claselor cu membri alocati dinamic si operatorul de afisare
//folositi un membru static sau const.

// {1} se va defini operatorul < care permite compararea a 2 obiecte si va fi utilizat in cadrul unei functii de sortare
// {2} prin intermediul operatorului += se va combina obiectul curent cu un obiect rpimit ca parametru


#include <iostream>
#include <cstring>
using namespace std;


class Printing3D {
    // atribute - prima data le declari in private (constructor default fara paramatrii)
    private:
    int numarModele;
    char* numeModel;
    char* material;
    float pret;
public:
//constructor default - public (constructor cu paramatrii)
Printing3D() {
    this->numarModele = 0;
    this->numeModel = nullptr;
    this->material = nullptr;
    this->pret = 0.0f;
    cout << "Constructor principal apelat" <<endl;
}
//constructor cu parametrii

Printing3D (const int numarModele, char* numeModel, char* material, float pret) {
    
}

};

int main () {

    cout << "testare main" <<endl;
}




