#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
struct pePP{
    float vTens[5];
    float result;
    int faces[8];//quantidade de faces primeiro na forca de tração, segundo na força de cisalhamento e terceiro na força de esmagamento;

};
struct pPinos{
    float vTens[5];
    float diametro[4];
    float faces[4];
    float raio[4];
};
struct pePEAste{
    float diAste;
    float vArea;
    float result;
};
struct pePP a1;
struct pePP a2;
struct pePP b1;
struct pePP b2;
struct pePEAste peAste;
struct pPinos pIno1;
struct pPinos pIno2;
#endif // STRUCTS_H_INCLUDED
