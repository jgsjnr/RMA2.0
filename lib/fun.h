#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
float vTen_Aste(float forca, float diametro, float consPi); //FUN플O ESPECIFICA PARA CALCULAR A ASTE
float vTen(float forca, float faces, float ladoA,float ladoB); //FUN플O DE TRA플O
float vEsm(float forca, float faces, float ladoA, float ladoB); //FUN플O DE ESMAGAMENTO
float vCis(float forca, float faces, float ladoA, float ladoB); //FUN플O DE CISSALHAMENTO
float vEsmPino(float forca, float faces, float diametro, float cota); //FUN플O DE ESMAGAMENTO DO PINO
float vCisPino(float forca, float faces, float diametro,float constPi); //FUN플O DE CISALHAMENTO DO PINO
#endif // FUN_H_INCLUDED
