#include <iostream>
#include <cstring>
using namespace std;


class Printing3D {
    // atribute
    private:
    int numarModele;
    char* numeModel;
    char* material;
    float pret;
public:
//constructor default
Printing3D() {
    this->numarModele = nullptr;
    this->numeModel = nullptr;
    this->material = nullptr;
    this->pret = 0.0f;
    cout << "Constructor principal apelat" <<endl;
}
//constructor cu parametrii

Printing3D (const int numarModele, char* numeModel, char* material;float pret) {
    
}

}