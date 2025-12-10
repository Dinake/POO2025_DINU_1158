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
    
    friend istream& operator>>(istream& is, Polita& p) {
        char buffer[100];
        cout << "Numar polita: ";
        is >> buffer;
        delete[] p.numarPolita;
        p.numarPolita = new char[strlen(buffer) + 1];
        strcpy(p.numarPolita, buffer);
        cout << "Durata acoperire (luni): ";
        is >> p.durAcoperire;
        cout << "Prima asigurare (RON): ";
        is >> p.primaAsigurare;
        cout << "Este activa (1/0): ";
        is >> p.esteActiva;
        return is;
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
    
    // Operator de atribuire
    Asigurat& operator=(const Asigurat& other) {
        if (this != &other) {
            delete[] nume;
            delete[] cnp;
            
            nume = new char[strlen(other.nume) + 1];
            strcpy(nume, other.nume);
            cnp = new char[strlen(other.cnp) + 1];
            strcpy(cnp, other.cnp);
            varsta = other.varsta;
            istoricClaims = other.istoricClaims;
            areDiscountFidelitate = other.areDiscountFidelitate;
        }
        return *this;
    }
    
    // Operator== - compara dupa CNP
    bool operator==(const Asigurat& other) const {
        return strcmp(cnp, other.cnp) == 0;
    }
    
    // Operator[] - acces la caracterul din nume
    char operator[](int index) const {
        if (index >= 0 && index < (int)strlen(nume)) {
            return nume[index];
        }
        return '\0';
    }
    
    // Operator! - verifica daca NU are discount fidelitate
    bool operator!() const {
        return !areDiscountFidelitate;
    }
    
    friend ostream& operator<<(ostream& os, const Asigurat& a) {
        os << "Asigurat [" << a.nume << "] - CNP: " << a.cnp 
           << ", Varsta: " << a.varsta << " ani, Claims: " << a.istoricClaims << " RON";
        return os;
    }
    
    friend istream& operator>>(istream& is, Asigurat& a) {
        char buffer[100];
        cout << "Nume asigurat: ";
        is >> buffer;
        delete[] a.nume;
        a.nume = new char[strlen(buffer) + 1];
        strcpy(a.nume, buffer);
        cout << "CNP: ";
        is >> buffer;
        delete[] a.cnp;
        a.cnp = new char[strlen(buffer) + 1];
        strcpy(a.cnp, buffer);
        cout << "Varsta: ";
        is >> a.varsta;
        cout << "Istoric claims (RON): ";
        is >> a.istoricClaims;
        cout << "Are discount fidelitate (1/0): ";
        is >> a.areDiscountFidelitate;
        return is;
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
    
    // Operator de atribuire
    AnimalDeCompanie& operator=(const AnimalDeCompanie& other) {
        if (this != &other) {
            delete[] nume;
            delete[] rasa;
            
            nume = new char[strlen(other.nume) + 1];
            strcpy(nume, other.nume);
            rasa = new char[strlen(other.rasa) + 1];
            strcpy(rasa, other.rasa);
            varsta = other.varsta;
            greutate = other.greutate;
            areAfectiuniPreexistente = other.areAfectiuniPreexistente;
        }
        return *this;
    }
    
    // Operator> - compara dupa greutate
    bool operator>(const AnimalDeCompanie& other) const {
        return greutate > other.greutate;
    }
    
    // Operator++ incrementeaza varsta
    AnimalDeCompanie& operator++() {
        varsta++;
        return *this;
    }
    
    // Operator cast la float - returneaza greutatea
    operator float() const {
        return greutate;
    }
    
    friend ostream& operator<<(ostream& os, const AnimalDeCompanie& a) {
        os << "Animal [" << a.nume << "] - Rasa: " << a.rasa 
           << ", Varsta: " << a.varsta << " ani, Greutate: " << a.greutate << " kg";
        return os;
    }
    
    friend istream& operator>>(istream& is, AnimalDeCompanie& a) {
        char buffer[100];
        cout << "Nume animal: ";
        is >> buffer;
        delete[] a.nume;
        a.nume = new char[strlen(buffer) + 1];
        strcpy(a.nume, buffer);
        cout << "Rasa: ";
        is >> buffer;
        delete[] a.rasa;
        a.rasa = new char[strlen(buffer) + 1];
        strcpy(a.rasa, buffer);
        cout << "Varsta: ";
        is >> a.varsta;
        cout << "Greutate (kg): ";
        is >> a.greutate;
        cout << "Are afectiuni preexistente (1/0): ";
        is >> a.areAfectiuniPreexistente;
        return is;
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


class ContractAsigurare {
private:
    char* numarContract;
    Polita polita;
    Asigurat titular;
    AnimalDeCompanie* animale;
    int nrAnimale;
    float valoareTotala;
    bool esteValid;
    
    static int numarTotalContracte;
    const int idContract;

public:
    ContractAsigurare() : idContract(++numarTotalContracte) {
        numarContract = new char[20];
        strcpy(numarContract, "CTR000000");
        animale = nullptr;
        nrAnimale = 0;
        valoareTotala = 0.0f;
        esteValid = false;
    }
    
    ContractAsigurare(const char* numar, Polita p, Asigurat t, AnimalDeCompanie* anim, int nrAnim, float val) 
        : idContract(++numarTotalContracte), polita(p), titular(t) {
        numarContract = new char[strlen(numar) + 1];
        strcpy(numarContract, numar);
        nrAnimale = nrAnim;
        valoareTotala = val;
        esteValid = true;
        if (nrAnimale > 0 && anim != nullptr) {
            animale = new AnimalDeCompanie[nrAnimale];
            for (int i = 0; i < nrAnimale; i++) {
                animale[i] = anim[i];
            }
        } else {
            animale = nullptr;
        }
    }
    
    ContractAsigurare(const ContractAsigurare& other) 
        : idContract(other.idContract), polita(other.polita), titular(other.titular) {
        numarContract = new char[strlen(other.numarContract) + 1];
        strcpy(numarContract, other.numarContract);
        nrAnimale = other.nrAnimale;
        valoareTotala = other.valoareTotala;
        esteValid = other.esteValid;
        if (nrAnimale > 0 && other.animale != nullptr) {
            animale = new AnimalDeCompanie[nrAnimale];
            for (int i = 0; i < nrAnimale; i++) {
                animale[i] = other.animale[i];
            }
        } else {
            animale = nullptr;
        }
    }
    
    ~ContractAsigurare() {
        delete[] numarContract;
        if (animale != nullptr) {
            delete[] animale;
        }
    }
    
    ContractAsigurare& operator=(const ContractAsigurare& other) {
        if (this != &other) {
            delete[] numarContract;
            if (animale != nullptr) {
                delete[] animale;
            }
            
            numarContract = new char[strlen(other.numarContract) + 1];
            strcpy(numarContract, other.numarContract);
            polita = other.polita;
            titular = other.titular;
            nrAnimale = other.nrAnimale;
            valoareTotala = other.valoareTotala;
            esteValid = other.esteValid;
            
            if (nrAnimale > 0 && other.animale != nullptr) {
                animale = new AnimalDeCompanie[nrAnimale];
                for (int i = 0; i < nrAnimale; i++) {
                    animale[i] = other.animale[i];
                }
            } else {
                animale = nullptr;
            }
        }
        return *this;
    }
    
    const char* getNumarContract() const { return numarContract; }
    Polita getPolita() const { return polita; }
    Asigurat getTitular() const { return titular; }
    int getNrAnimale() const { return nrAnimale; }
    float getValoareTotala() const { return valoareTotala; }
    bool getEsteValid() const { return esteValid; }
    int getIdContract() const { return idContract; }
    static int getNumarTotalContracte() { return numarTotalContracte; }
    
    AnimalDeCompanie getAnimal(int index) const {
        if (index >= 0 && index < nrAnimale && animale != nullptr) {
            return animale[index];
        }
        return AnimalDeCompanie();
    }
    
    void setNumarContract(const char* numar) {
        delete[] numarContract;
        numarContract = new char[strlen(numar) + 1];
        strcpy(numarContract, numar);
    }
    void setPolita(Polita p) { polita = p; }
    void setTitular(Asigurat t) { titular = t; }
    void setValoareTotala(float val) { valoareTotala = val; }
    void setEsteValid(bool valid) { esteValid = valid; }
    
    void setAnimale(AnimalDeCompanie* anim, int nr) {
        if (animale != nullptr) {
            delete[] animale;
        }
        nrAnimale = nr;
        if (nrAnimale > 0 && anim != nullptr) {
            animale = new AnimalDeCompanie[nrAnimale];
            for (int i = 0; i < nrAnimale; i++) {
                animale[i] = anim[i];
            }
        } else {
            animale = nullptr;
        }
    }
    
    friend ostream& operator<<(ostream& os, const ContractAsigurare& c) {
        os << "Contract [" << c.numarContract << "] - Titular: " << c.titular.getNume()
           << ", Animale: " << c.nrAnimale << ", Valoare: " << c.valoareTotala << " RON";
        return os;
    }
    
    AnimalDeCompanie& operator[](int index) {
        if (index >= 0 && index < nrAnimale && animale != nullptr) {
            return animale[index];
        }
        return animale[0];
    }
    
    bool operator>(const ContractAsigurare& other) const {
        return valoareTotala > other.valoareTotala;
    }
};

int ContractAsigurare::numarTotalContracte = 0;


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
    


   
    
    float primaTotala = calculeazaPrimaTotalaAsigurare(pol1, asig1);
    cout << "Prima totala returnata: " << primaTotala << " RON" << endl;
    
    afiseazaRaportComplet(animal1, pol1);
    
    

    
    // Testare operatori Polita
    cout << "\n--- OPERATORI POLITA ---" << endl;
    
    Polita pol3;
    pol3.setNumarPolita("POL2025003");
    pol3.setDurAcoperire(12);
    pol3.setPrimaAsigurare(150.0f);
    pol3.setEsteActiva(true);
    
    cout << "\n1. Operator= (atribuire):" << endl;
    Polita pol4;
    pol4 = pol3;
    cout << "pol4 dupa atribuire: " << pol4 << endl;
    
    cout << "\n2. Operator+ (adunare durata):" << endl;
    Polita pol5 = pol3 + 6;
    cout << "pol3 original: " << pol3 << endl;
    cout << "pol5 (pol3 + 6 luni): " << pol5 << endl;
    
    cout << "\n3. Operator<< (afisare):" << endl;
    cout << "Afisare pol3: " << pol3 << endl;
    
    cout << "\n4. Operator++ (incrementare durata):" << endl;
    cout << "pol3 inainte: durata = " << pol3.getDurAcoperire() << " luni" << endl;
    ++pol3;
    cout << "pol3 dupa ++pol3: durata = " << pol3.getDurAcoperire() << " luni" << endl;
    
    
    // Testare operatori Asigurat
    cout << "\n\n--- OPERATORI ASIGURAT ---" << endl;
    
    Asigurat asig3;
    asig3.setNume("Ionescu Maria");
    asig3.setCnp("2900215401234");
    asig3.setVarsta(35);
    asig3.setIstoricClaims(300.0f);
    asig3.setAreDiscountFidelitate(true);
    
    cout << "\n5. Operator= (atribuire):" << endl;
    Asigurat asig4;
    asig4 = asig3;
    cout << "asig4.getNume() dupa atribuire: " << asig4.getNume() << endl;
    cout << "asig4.getCnp(): " << asig4.getCnp() << endl;
    
    cout << "\n6. Operator== (comparare CNP):" << endl;
    Asigurat asig5;
    asig5.setCnp("2900215401234");
    cout << "asig3 CNP: " << asig3.getCnp() << endl;
    cout << "asig5 CNP: " << asig5.getCnp() << endl;
    cout << "asig3 == asig5? " << (asig3 == asig5 ? "DA" : "NU") << endl;
    cout << "asig3 == asig1? " << (asig3 == asig1 ? "DA" : "NU") << endl;
    
    cout << "\n7. Operator[] (acces caracter nume):" << endl;
    cout << "asig3.getNume(): " << asig3.getNume() << endl;
    cout << "Primul caracter (index 0): " << asig3[0] << endl;
    cout << "Al 5-lea caracter (index 4): " << asig3[4] << endl;
    
    cout << "\n8. Operator! (verifica lipsa discount):" << endl;
    cout << "asig3 are discount? " << (asig3.getAreDiscountFidelitate() ? "DA" : "NU") << endl;
    cout << "!asig3 (nu are discount)? " << (!asig3 ? "DA" : "NU") << endl;
    cout << "asig1 are discount? " << (asig1.getAreDiscountFidelitate() ? "DA" : "NU") << endl;
    cout << "!asig1 (nu are discount)? " << (!asig1 ? "DA" : "NU") << endl;
    
    
    // Testare operatori AnimalDeCompanie
    cout << "\n\n--- OPERATORI ANIMALDECOMPANIE ---" << endl;
    
    AnimalDeCompanie animal3;
    animal3.setNume("Rex");
    animal3.setRasa("Ciobanesc German");
    animal3.setVarsta(5);
    animal3.setGreutate(35.0f);
    animal3.setAreAfectiuniPreexistente(false);
    
    cout << "\n9. Operator= (atribuire):" << endl;
    AnimalDeCompanie animal4;
    animal4 = animal3;
    cout << "animal4.getNume() dupa atribuire: " << animal4.getNume() << endl;
    cout << "animal4.getRasa(): " << animal4.getRasa() << endl;
    cout << "animal4.getGreutate(): " << animal4.getGreutate() << " kg" << endl;
    
    cout << "\n10. Operator> (comparare greutate):" << endl;
    cout << "animal3 greutate: " << animal3.getGreutate() << " kg" << endl;
    cout << "animal1 greutate: " << animal1.getGreutate() << " kg" << endl;
    cout << "animal3 > animal1? " << (animal3 > animal1 ? "DA" : "NU") << endl;
    cout << "animal1 > animal3? " << (animal1 > animal3 ? "DA" : "NU") << endl;
    
    cout << "\n11. Operator++ (incrementare varsta):" << endl;
    cout << "animal3 varsta inainte: " << animal3.getVarsta() << " ani" << endl;
    ++animal3;
    cout << "animal3 varsta dupa ++animal3: " << animal3.getVarsta() << " ani" << endl;
    
    cout << "\n12. Operator cast la float (returneaza greutate):" << endl;
    float greutateAnimal = animal3;
    cout << "Greutate obtinuta prin cast: " << greutateAnimal << " kg" << endl;
    cout << "Folosire directa in expresie: " << (float)animal1 + 5.0f << " kg" << endl;
    
    
    cout << "\n\n=== FAZA 4: VECTOR POLITE ===" << endl;
    int nrPolite;
    cout << "Cate polite doriti sa introduceti? ";
    cin >> nrPolite;
    
    Polita* vectorPolite = new Polita[nrPolite];
    for (int i = 0; i < nrPolite; i++) {
        cout << "\n--- Polita " << i + 1 << " ---" << endl;
        cin >> vectorPolite[i];
    }
    
    cout << "\n--- Afisare vector polite ---" << endl;
    for (int i = 0; i < nrPolite; i++) {
        cout << "Polita " << i + 1 << ": " << vectorPolite[i] << endl;
    }
    
    delete[] vectorPolite;
    
    
    cout << "\n\n=== FAZA 4: VECTOR ASIGURATI ===" << endl;
    int nrAsigurati;
    cout << "Cati asigurati doriti sa introduceti? ";
    cin >> nrAsigurati;
    
    Asigurat* vectorAsigurati = new Asigurat[nrAsigurati];
    for (int i = 0; i < nrAsigurati; i++) {
        cout << "\n--- Asigurat " << i + 1 << " ---" << endl;
        cin >> vectorAsigurati[i];
    }
    
    cout << "\n--- Afisare vector asigurati ---" << endl;
    for (int i = 0; i < nrAsigurati; i++) {
        cout << "Asigurat " << i + 1 << ": " << vectorAsigurati[i] << endl;
    }
    
    delete[] vectorAsigurati;
    
    
    cout << "\n\n=== FAZA 4: VECTOR ANIMALE ===" << endl;
    int nrAnimale;
    cout << "Cate animale doriti sa introduceti? ";
    cin >> nrAnimale;
    
    AnimalDeCompanie* vectorAnimale = new AnimalDeCompanie[nrAnimale];
    for (int i = 0; i < nrAnimale; i++) {
        cout << "\n--- Animal " << i + 1 << " ---" << endl;
        cin >> vectorAnimale[i];
    }
    
    cout << "\n--- Afisare vector animale ---" << endl;
    for (int i = 0; i < nrAnimale; i++) {
        cout << "Animal " << i + 1 << ": " << vectorAnimale[i] << endl;
    }
    
    delete[] vectorAnimale;
    
    
    cout << "\n\n=== FAZA 4: MATRICE POLITE ===" << endl;
    int nrLinii, nrColoane;
    cout << "Numar linii matrice: ";
    cin >> nrLinii;
    cout << "Numar coloane matrice: ";
    cin >> nrColoane;
    
    Polita** matricePolite = new Polita*[nrLinii];
    for (int i = 0; i < nrLinii; i++) {
        matricePolite[i] = new Polita[nrColoane];
    }
    
    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            cout << "\n--- Polita [" << i << "][" << j << "] ---" << endl;
            cin >> matricePolite[i][j];
        }
    }
    
    cout << "\n--- Afisare matrice polite ---" << endl;
    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            cout << "Polita [" << i << "][" << j << "]: " << matricePolite[i][j] << endl;
        }
    }
    
    for (int i = 0; i < nrLinii; i++) {
        delete[] matricePolite[i];
    }
    delete[] matricePolite;
    
    cout << "\n=== FAZA 4 FINALIZATA ===" << endl;
    
    
    cout << "\n\n=== FAZA 5: TESTARE CONTRACTASIGURARE ===" << endl;
    
    Polita pTest;
    pTest.setNumarPolita("POL2025TEST");
    pTest.setPrimaAsigurare(200.0f);
    pTest.setDurAcoperire(12);
    
    Asigurat aTest;
    aTest.setNume("TestPopescu");
    aTest.setVarsta(35);
    
    AnimalDeCompanie animTest[2];
    animTest[0].setNume("Rex");
    animTest[0].setRasa("Labrador");
    animTest[1].setNume("Miau");
    animTest[1].setRasa("Persana");
    
    ContractAsigurare contract1("CTR2025001", pTest, aTest, animTest, 2, 2400.0f);
    cout << "\nContract creat: " << contract1 << endl;
    
    cout << "\nTestare operator[]: " << endl;
    cout << "Animal 0: " << contract1[0] << endl;
    cout << "Animal 1: " << contract1[1] << endl;
    
    ContractAsigurare contract2;
    contract2.setValoareTotala(1500.0f);
    cout << "\nTestare operator>: " << endl;
    cout << "Contract1 valoare: " << contract1.getValoareTotala() << " RON" << endl;
    cout << "Contract2 valoare: " << contract2.getValoareTotala() << " RON" << endl;
    cout << "Contract1 > Contract2? " << (contract1 > contract2 ? "DA" : "NU") << endl;
    
    cout << "\n=== FAZA 5 FINALIZATA ===" << endl;

    
    return 0;
}
