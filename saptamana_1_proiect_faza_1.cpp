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
    const char* tipCoperire;
    
    // Constructor 1 - fara parametri
    Polita() : idPolita(++numarTotalPolite), tipCoperire("Standard") {
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
        cout << "\n=== POLITA DE ASIGURARE ===" << endl;
        cout << "ID Polita: " << idPolita << endl;
        cout << "Numar polita: " << numarPolita << endl;
        cout << "Tip coperire: " << tipCoperire << endl;
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



int main() {
    cout << "========================================" << endl;
    cout << "  PROIECT POO - FAZA 1" << endl;
    cout << "  Domeniu: ASIGURARI ANIMALE COMPANIE" << endl;
    cout << "========================================" << endl;
    

    cout << "\n\n*** TESTARE CLASA POLITA ***\n";
    

    Polita pol1;
    pol1.afisare();
    
    return 0;
}
