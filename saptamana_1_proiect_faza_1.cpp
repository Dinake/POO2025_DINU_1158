// nume Dinu Alexandru - am ales domeniul: Asigurari [A]nimale [D]e companie

#include <iostream>
#include <cstring>
using namespace std;


class Polita {
public:
    // Atribute normale
    char* numarPolita;
    int durAcoperire;
    float primaAsigurare;
    bool esteActiva;
    
    // Atribute statice
    static int numarTotalPolite;
    static float comisionAgent;
    
    // Atribute constante
    const int idPolita;
    const char* tipAcoperire;
    
    // Constructor 1 - fara parametri
    Polita() : idPolita(++numarTotalPolite), tipAcoperire("Standard") {
        numarPolita = new char[20];
        strcpy(numarPolita, "POL000000");
        durAcoperire = 12;
        primaAsigurare = 0.0f;
        esteActiva = false;
    }
    

    // Functie statica
    static float calculeazaValoareTotalaPolite(int numarPolite, float primaMedie) {
        return numarPolite * primaMedie * 12;
    }
    
    // Functie de afisare
    void afisare() {
        cout << "\nPOLITA DE ASIGURARE" << endl;
        cout << "ID Polita: " << idPolita << endl;
        cout << "Numar polita: " << numarPolita << endl;
        cout << "Tip acoperire: " << tipAcoperire << endl;
        cout << "Durata coperire: " << durAcoperire << " luni" << endl;
        cout << "Prima asigurare: " << primaAsigurare << " RON" << endl;
        cout << "Este activa: " << (esteActiva ? "Da" : "Nu") << endl;
        cout << "Total polite emise: " << numarTotalPolite << endl;
        cout << "Comision agent: " << comisionAgent << "%" << endl;
    }
};

// Initializare atribute statice pentru Polita
int Polita::numarTotalPolite = 0;
float Polita::comisionAgent = 15.0f;



class Asigurat {
public:

    char* nume;
    char* cnp;
    int varsta;
    float istoricClaims;
    bool areDiscountFidelitate;

    static int numarTotalAsigurati;
    static float discountFidelitate;
    

    const int idAsigurat;
    const char* categorie;
    

    Asigurat() : idAsigurat(++numarTotalAsigurati), categorie("Standard") {
        nume = new char[50];
        strcpy(nume, "Anonim");
        cnp = new char[14];
        strcpy(cnp, "0000000000000");
        varsta = 0;
        istoricClaims = 0.0f;
        areDiscountFidelitate = false;
    }
    


    static float calculeazaPrimaAjustata(float primaBase, bool areDiscount) {
        if (areDiscount) {
            return primaBase * (1 - discountFidelitate / 100);
        }
        return primaBase;
    }

    void afisare() {
        cout << "\nASIGURAT" << endl;
        cout << "ID Asigurat: " << idAsigurat << endl;
        cout << "Nume: " << nume << endl;
        cout << "CNP: " << cnp << endl;
        cout << "Categorie: " << categorie << endl;
        cout << "Varsta: " << varsta << " ani" << endl;
        cout << "Istoric claims: " << istoricClaims << " RON" << endl;
        cout << "Are discount fidelitate: " << (areDiscountFidelitate ? "Da" : "Nu") << endl;
        cout << "Total asigurati: " << numarTotalAsigurati << endl;
        cout << "Discount fidelitate: " << discountFidelitate << "%" << endl;
    }
};

int Asigurat::numarTotalAsigurati = 0;
float Asigurat::discountFidelitate = 10.0f;


int main() {

    cout << "  PROIECT POO - FAZA 1" << endl;
    cout << "  Domeniu: ASIGURARI ANIMALE COMPANIE" << endl;


    cout << "\n\nTESTARE CLASA POLITA\n";
    
    Polita pol1;
    pol1.afisare();
    
    
    cout << "\n\nTESTARE CLASA ASIGURAT \n";
    
    Asigurat asig1;
    asig1.afisare();
    
    return 0;
}
