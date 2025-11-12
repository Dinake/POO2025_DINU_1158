// nume Dinu Alexandru - am ales domeniul: Asigurari [A]nimale [D]e companie

#include <iostream>
#include <cstring>
using namespace std;


class Polita {
private:
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
    
public:
    // Constructor 1 - fara parametri
    Polita() : idPolita(++numarTotalPolite), tipAcoperire("Standard") {
        numarPolita = new char[20];
        strcpy(numarPolita, "POL000000");
        durAcoperire = 12;
        primaAsigurare = 0.0f;
        esteActiva = false;
    }
    
    // Constructor de copiere
    Polita(const Polita& other) : idPolita(other.idPolita), tipAcoperire(other.tipAcoperire) {
        numarPolita = new char[strlen(other.numarPolita) + 1];
        strcpy(numarPolita, other.numarPolita);
        durAcoperire = other.durAcoperire;
        primaAsigurare = other.primaAsigurare;
        esteActiva = other.esteActiva;
    }
    
    // Destructor
    ~Polita() {
        delete[] numarPolita;
    }
    
    // Operator de atribuire
    Polita& operator=(const Polita& other) {
        if (this != &other) {
            delete[] numarPolita;
            
            numarPolita = new char[strlen(other.numarPolita) + 1];
            strcpy(numarPolita, other.numarPolita);
            durAcoperire = other.durAcoperire;
            primaAsigurare = other.primaAsigurare;
            esteActiva = other.esteActiva;
        }
        return *this;
    }
    
    // Operator+ - aduna durata acoperire
    Polita operator+(int luniAdaugate) const {
        Polita temp = *this;
        temp.durAcoperire += luniAdaugate;
        return temp;
    }
    
    // Operator<< - afisare
    friend ostream& operator<<(ostream& os, const Polita& p) {
        os << "Polita [" << p.numarPolita << "] - Prima: " << p.primaAsigurare 
           << " RON, Durata: " << p.durAcoperire << " luni, Activa: " 
           << (p.esteActiva ? "Da" : "Nu");
        return os;
    }
    
    // Operator++ (preincrementare) - incrementeaza durata acoperire
    Polita& operator++() {
        durAcoperire++;
        return *this;
    }
    
    // Getteri
    const char* getNumarPolita() const { return numarPolita; }
    int getDurAcoperire() const { return durAcoperire; }
    float getPrimaAsigurare() const { return primaAsigurare; }
    bool getEsteActiva() const { return esteActiva; }
    int getIdPolita() const { return idPolita; }
    const char* getTipAcoperire() const { return tipAcoperire; }
    
    // Setteri
    void setNumarPolita(const char* numar) {
        delete[] numarPolita;
        numarPolita = new char[strlen(numar) + 1];
        strcpy(numarPolita, numar);
    }
    void setDurAcoperire(int durata) { durAcoperire = durata; }
    void setPrimaAsigurare(float prima) { primaAsigurare = prima; }
    void setEsteActiva(bool activa) { esteActiva = activa; }
    
    // Functii statice pentru atribute statice
    static int getNumarTotalPolite() { return numarTotalPolite; }
    static float getComisionAgent() { return comisionAgent; }
    static void setComisionAgent(float comision) { comisionAgent = comision; }

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


int Polita::numarTotalPolite = 0;
float Polita::comisionAgent = 15.0f;


class Asigurat {
private:
    char* nume;
    char* cnp;
    int varsta;
    float istoricClaims;
    bool areDiscountFidelitate;

    static int numarTotalAsigurati;
    static float discountFidelitate;
    
    const int idAsigurat;
    const char* categorie;
    
public:
    Asigurat() : idAsigurat(++numarTotalAsigurati), categorie("Standard") {
        nume = new char[50];
        strcpy(nume, "Anonim");
        cnp = new char[14];
        strcpy(cnp, "0000000000000");
        varsta = 0;
        istoricClaims = 0.0f;
        areDiscountFidelitate = false;
    }
    
    // Constructor de copiere
    Asigurat(const Asigurat& other) : idAsigurat(other.idAsigurat), categorie(other.categorie) {
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        cnp = new char[strlen(other.cnp) + 1];
        strcpy(cnp, other.cnp);
        varsta = other.varsta;
        istoricClaims = other.istoricClaims;
        areDiscountFidelitate = other.areDiscountFidelitate;
    }
    
    // Destructor
    ~Asigurat() {
        delete[] nume;
        delete[] cnp;
    }
    
    // Getteri
    const char* getNume() const { return nume; }
    const char* getCnp() const { return cnp; }
    int getVarsta() const { return varsta; }
    float getIstoricClaims() const { return istoricClaims; }
    bool getAreDiscountFidelitate() const { return areDiscountFidelitate; }
    int getIdAsigurat() const { return idAsigurat; }
    const char* getCategorie() const { return categorie; }
    
    // Setteri
    void setNume(const char* numeNou) {
        delete[] nume;
        nume = new char[strlen(numeNou) + 1];
        strcpy(nume, numeNou);
    }
    void setCnp(const char* cnpNou) {
        delete[] cnp;
        cnp = new char[strlen(cnpNou) + 1];
        strcpy(cnp, cnpNou);
    }
    void setVarsta(int varstaNoua) { varsta = varstaNoua; }
    void setIstoricClaims(float claims) { istoricClaims = claims; }
    void setAreDiscountFidelitate(bool discount) { areDiscountFidelitate = discount; }
    
    // Functii statice pentru atribute statice
    static int getNumarTotalAsigurati() { return numarTotalAsigurati; }
    static float getDiscountFidelitate() { return discountFidelitate; }
    static void setDiscountFidelitate(float discount) { discountFidelitate = discount; }

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

class AnimalDeCompanie {
private:
    char* nume;
    char* rasa;
    int varsta;
    float greutate;
    bool areAfectiuniPreexistente;
    
    static int numarAnimaleAsigurate;
    static float tarifVeterinarMediu;

    const int idAnimal;
    const char* specie;

public:
    AnimalDeCompanie() : idAnimal(++numarAnimaleAsigurate), specie("Necunoscuta") {
        nume = new char[30];
        strcpy(nume, "Necunoscut");
        rasa = new char[30];
        strcpy(rasa, "Mestecata");
        varsta = 0;
        greutate = 0.0f;
        areAfectiuniPreexistente = false;
    }
    
    // Constructor de copiere
    AnimalDeCompanie(const AnimalDeCompanie& other) : idAnimal(other.idAnimal), specie(other.specie) {
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        rasa = new char[strlen(other.rasa) + 1];
        strcpy(rasa, other.rasa);
        varsta = other.varsta;
        greutate = other.greutate;
        areAfectiuniPreexistente = other.areAfectiuniPreexistente;
    }
    
    // Destructor
    ~AnimalDeCompanie() {
        delete[] nume;
        delete[] rasa;
    }
    
    // Getteri
    const char* getNume() const { return nume; }
    const char* getRasa() const { return rasa; }
    int getVarsta() const { return varsta; }
    float getGreutate() const { return greutate; }
    bool getAreAfectiuniPreexistente() const { return areAfectiuniPreexistente; }
    int getIdAnimal() const { return idAnimal; }
    const char* getSpecie() const { return specie; }
    
    // Setteri
    void setNume(const char* numeNou) {
        delete[] nume;
        nume = new char[strlen(numeNou) + 1];
        strcpy(nume, numeNou);
    }
    void setRasa(const char* rasaNoua) {
        delete[] rasa;
        rasa = new char[strlen(rasaNoua) + 1];
        strcpy(rasa, rasaNoua);
    }
    void setVarsta(int varstaNoua) { varsta = varstaNoua; }
    void setGreutate(float greutateNoua) { greutate = greutateNoua; }
    void setAreAfectiuniPreexistente(bool afectiuni) { areAfectiuniPreexistente = afectiuni; }
    
    // Functii statice pentru atribute statice
    static int getNumarAnimaleAsigurate() { return numarAnimaleAsigurate; }
    static float getTarifVeterinarMediu() { return tarifVeterinarMediu; }
    static void setTarifVeterinarMediu(float tarif) { tarifVeterinarMediu = tarif; }

    static float estimeazaCostAnualVeterinar(int numarAnimale) {
        return numarAnimale * tarifVeterinarMediu;
    }
    

    void afisare() {
        cout << "\nANIMAL DE COMPANIE" << endl;
        cout << "ID Animal: " << idAnimal << endl;
        cout << "Nume: " << nume << endl;
        cout << "Specie: " << specie << endl;
        cout << "Rasa: " << rasa << endl;
        cout << "Varsta: " << varsta << " ani" << endl;
        cout << "Greutate: " << greutate << " kg" << endl;
        cout << "Are afectiuni preexistente: " << (areAfectiuniPreexistente ? "Da" : "Nu") << endl;
        cout << "Total animale asigurate: " << numarAnimaleAsigurate << endl;
        cout << "Tarif veterinar mediu: " << tarifVeterinarMediu << " RON" << endl;
    }
    
    // Declarare functie friend
    friend void afiseazaRaportComplet(AnimalDeCompanie& animal, Polita& polita);
};


int AnimalDeCompanie::numarAnimaleAsigurate = 0;
float AnimalDeCompanie::tarifVeterinarMediu = 500.0f;


float calculeazaPrimaTotalaAsigurare(Polita& polita, Asigurat& asigurat) {
    float primaBase = polita.getPrimaAsigurare();
    
    if (asigurat.getAreDiscountFidelitate()) {
        float discount = Asigurat::getDiscountFidelitate();
        float primaFinala = primaBase * (1 - discount / 100);
        cout << "\n>>> Calcul Prima Totala <<<" << endl;
        cout << "Asigurat: " << asigurat.getNume() << endl;
        cout << "Prima de baza: " << primaBase << " RON" << endl;
        cout << "Discount fidelitate: " << discount << "%" << endl;
        cout << "Prima finala: " << primaFinala << " RON" << endl;
        return primaFinala;
    }
    
    return primaBase;
}

// Functie friend 2: Afiseaza raport complet despre animal si polita
void afiseazaRaportComplet(AnimalDeCompanie& animal, Polita& polita) {
    cout << "\n>>> RAPORT COMPLET ASIGURARE <<<" << endl;
    cout << "====================================" << endl;
    cout << "ANIMAL ASIGURAT:" << endl;
    cout << "  Nume: " << animal.getNume() << endl;
    cout << "  Specie: " << animal.getSpecie() << endl;
    cout << "  Rasa: " << animal.getRasa() << endl;
    cout << "  Varsta: " << animal.getVarsta() << " ani" << endl;
    cout << "  Greutate: " << animal.getGreutate() << " kg" << endl;
    cout << "  Are afectiuni: " << (animal.getAreAfectiuniPreexistente() ? "Da" : "Nu") << endl;
    cout << "\nPOLITA ASOCIATA:" << endl;
    cout << "  Numar polita: " << polita.getNumarPolita() << endl;
    cout << "  Prima lunara: " << polita.getPrimaAsigurare() << " RON" << endl;
    cout << "  Durata: " << polita.getDurAcoperire() << " luni" << endl;
    cout << "  Status: " << (polita.getEsteActiva() ? "Activa" : "Inactiva") << endl;
    
    float costTotal = polita.getPrimaAsigurare() * polita.getDurAcoperire();
    cout << "\nCOST TOTAL ASIGURARE: " << costTotal << " RON" << endl;
    cout << "====================================" << endl;
}


int main() {


    cout << "\n\n*** TESTARE CLASA POLITA ***\n";
    
    Polita pol1;
    pol1.afisare();
    
    cout << "\n-- Testare Setteri Polita --" << endl;
    pol1.setNumarPolita("POL2025001");
    pol1.setDurAcoperire(24);
    pol1.setPrimaAsigurare(180.0f);
    pol1.setEsteActiva(true);
    
    cout << "\n-- Testare Getteri Polita --" << endl;
    cout << "Numar polita: " << pol1.getNumarPolita() << endl;
    cout << "Durata acoperire: " << pol1.getDurAcoperire() << " luni" << endl;
    cout << "Prima asigurare: " << pol1.getPrimaAsigurare() << " RON" << endl;
    cout << "Este activa: " << (pol1.getEsteActiva() ? "Da" : "Nu") << endl;
    
    cout << "\n-- Testare Constructor de Copiere Polita --" << endl;
    Polita pol2 = pol1;
    pol2.afisare();
    
    cout << "\n-- Testare Functii Statice Polita --" << endl;
    cout << "Numar total polite: " << Polita::getNumarTotalPolite() << endl;
    cout << "Comision agent: " << Polita::getComisionAgent() << "%" << endl;
    cout << "Valoare totala pentru 100 polite (180 RON): " 
         << Polita::calculeazaValoareTotalaPolite(100, 180.0f) << " RON" << endl;
    

    cout << "\n\nTESTARE CLASA ASIGURAT\n";
    
    Asigurat asig1;
    asig1.afisare();
    
    cout << "\n-- Testare Setteri Asigurat --" << endl;
    asig1.setNume("Popescu Ion");
    asig1.setCnp("1850623401234");
    asig1.setVarsta(40);
    asig1.setIstoricClaims(500.0f);
    asig1.setAreDiscountFidelitate(true);
    
    cout << "\n-- Testare Getteri Asigurat --" << endl;
    cout << "Nume: " << asig1.getNume() << endl;
    cout << "CNP: " << asig1.getCnp() << endl;
    cout << "Varsta: " << asig1.getVarsta() << " ani" << endl;
    cout << "Istoric claims: " << asig1.getIstoricClaims() << " RON" << endl;
    cout << "Are discount: " << (asig1.getAreDiscountFidelitate() ? "Da" : "Nu") << endl;
    
    cout << "\n-- Testare Constructor de Copiere Asigurat --" << endl;
    Asigurat asig2 = asig1;
    asig2.afisare();
    
    cout << "\n-- Testare Functii Statice Asigurat --" << endl;
    cout << "Numar total asigurati: " << Asigurat::getNumarTotalAsigurati() << endl;
    cout << "Discount fidelitate: " << Asigurat::getDiscountFidelitate() << "%" << endl;
    cout << "Prima ajustata (200 RON cu discount): " 
         << Asigurat::calculeazaPrimaAjustata(200.0f, true) << " RON" << endl;
    
    
    cout << "\n\nTESTARE CLASA ANIMALDECOMPANIE\n";
    
    AnimalDeCompanie animal1;
    animal1.afisare();
    
    cout << "\n-- Testare Setteri AnimalDeCompanie --" << endl;
    animal1.setNume("Max");
    animal1.setRasa("Golden Retriever");
    animal1.setVarsta(3);
    animal1.setGreutate(28.5f);
    animal1.setAreAfectiuniPreexistente(false);
    
    cout << "\n-- Testare Getteri AnimalDeCompanie --" << endl;
    cout << "Nume: " << animal1.getNume() << endl;
    cout << "Rasa: " << animal1.getRasa() << endl;
    cout << "Varsta: " << animal1.getVarsta() << " ani" << endl;
    cout << "Greutate: " << animal1.getGreutate() << " kg" << endl;
    cout << "Are afectiuni: " << (animal1.getAreAfectiuniPreexistente() ? "Da" : "Nu") << endl;
    
    cout << "\n-- Testare Constructor de Copiere AnimalDeCompanie --" << endl;
    AnimalDeCompanie animal2 = animal1;
    animal2.afisare();
    
    cout << "\n-- Testare Functii Statice AnimalDeCompanie --" << endl;
    cout << "Numar animale asigurate: " << AnimalDeCompanie::getNumarAnimaleAsigurate() << endl;
    cout << "Tarif veterinar mediu: " << AnimalDeCompanie::getTarifVeterinarMediu() << " RON" << endl;
    cout << "Cost anual pentru 5 animale: " 
         << AnimalDeCompanie::estimeazaCostAnualVeterinar(5) << " RON" << endl;
    


    cout << "\n\nESTARE FUNCTII FRIEND\n";
    
    float primaTotala = calculeazaPrimaTotalaAsigurare(pol1, asig1);
    cout << "Prima totala returnata: " << primaTotala << " RON" << endl;
    
    afiseazaRaportComplet(animal1, pol1);
    
    
    
    return 0;
}
