#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

//Fun��o de calculo de tens�o
float vTen_Aste(float forca, float diametro, float consPi){
    float area;
    float result;
    area = (diametro * diametro) * consPi;
    result = forca / area;
    printf("==============================================================================\n");
	printf("===========================TENS�O DE TRA��O NA ASTE===========================\n");
	printf("==============================================================================\n");
    printf("Tens�o �: T=F/A\n");
    printf("Area �: Valor da cota %.2f� x valor de PI %.2f\n", diametro, consPi);
    printf("Valor da Area %.2f \n", area);
    printf("Equa��o para copiar: \n");
    printf("T = F / A\n");
    printf("T = %.2f / %.2f\n", forca, area);
    printf("T = %.2f\n", result);
    printf("Valor final = %.2f kgf/u�\n", result);
    printf("Fim da equa��o \n");
    return result;
}
float vTen(float forca, float faces, float ladoA,float ladoB){
    float area = 0;
    float result = 0;
    area = (ladoA * ladoB) * faces;
    result = forca / area;
    printf("==============================================================================\n");
	printf("===============================TENS�O DE TRA��O===============================\n");
	printf("==============================================================================\n");
    printf("Tens�o �: T=F/A\n");
    printf("Area �: Valor da cota %.2f x valor da cota %.2f x quantidade de faces %.2f\n", ladoA, ladoB, faces);
    printf("Valor da Area %.2f \n", area);
    printf("Equa��o para copiar: \n");
    printf("T = F / A\n");
    printf("T = %.2f / %.2f\n", forca, area);
    printf("T = %.2f\n", result);
    printf("Valor final = %.2f kgf/u�\n", result);
    printf("Fim da equa��o \n");
    return result;
}
float vEsm(float forca, float faces, float ladoA, float ladoB){
	float tensao; // Vari�vel da tens�o
	float area; //Variavel da �re
	float aux; //Variavel auxiliar para calcular a for�a;
	area = ladoA * ladoB * faces; //Variavel do valor geral da area
	aux = forca * 2.4; //Variavel auxilar da for�a multiplicando o valor constante de 2.4
	tensao = aux / area; //calculo final do componente
	/*
		Parte de escrita na tela com a equa��o do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENS�O DO ESMAGAMENTO==============================\n");
	printf("==============================================================================\n");
	printf("Tensao �: T = 2,4 x F / A\n");
	printf("�rea �: lado A x lado B x quantidade de faces\n");
	printf("�rea �: ( %.2f x %.2f x %.2f ) \n", ladoA, ladoB, faces);
	printf("�rea �: %.2f\n",area);
	printf("Equa��o para copiar: \n");
	printf("T = 2,4 x F / A\n");
	printf("T = 2,4 x %.2f / (%.2f x %.2f) x %.2f\n", forca, ladoA, ladoB, faces);
	printf("T = 2,4 x %.2f / %.2f\n",forca,area);
	printf("T = %.2f / %.2f\n", aux, area);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u�\n", tensao);
	printf("Fim da equa��o \n");
	return tensao;
}
float vCis(float forca, float faces, float ladoA, float ladoB){
	float tensao; // Vari�vel da tens�o
	float area; //Variavel da �re
	float aux; //Variavel auxiliar para calcular a for�a;
	area = ladoA * ladoB * faces; //Variavel do valor geral da area
	aux = 0.7 * area; //Equca��o relacionada da area com 0.7
	tensao = forca / aux; //Valor final da tensao
	/*
		Parte de escrita na tela com a equa��o do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENS�O DO CISALHAMENTO=============================\n");
	printf("==============================================================================\n");
	printf("Tensao �: T = F / 0,7 x A\n");
	printf("Area �: lado A x lado B x quantidade de faces");
	printf("Area �: (%.2f x %.2f) x %.2f\n", ladoA, ladoB, faces);
	printf("Area �: %.2f\n",area);
	printf("Equacao para copiar: \n");
	printf("T = F / 0,7 x A\n");
	printf("T = %.2f / 0,7 x (%.2f x %.2f) x %.2f\n", forca, ladoA, ladoB, faces);
	printf("T = %.2f / 0,7 x %.2f\n",forca, area);
	printf("T = %.2f / %.2f\n", forca, aux);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u�\n", tensao);
	printf("Fim da equa��o \n");
	return tensao;
}


/*
"=============================================================================
"===========================TENS�O DO ESMAGAMENTO DO PINO=====================
"=============================================================================
 */

float vEsmPino(float forca, float faces, float diametro, float cota){
	float tensao; // Vari�vel da tens�o
	float aux;
	float raio = diametro/2;
	float area;
    area = diametro * cota * faces;
	aux = forca * 2.4; //Variavel auxilar da for�a multiplicando o valor constante de 2.4
	tensao = aux / area; //calculo final do componente
	/*
		Parte de escrita na tela com a equa��o do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENS�O DO ESMAGAMENTO DO PINO======================\n");
	printf("==============================================================================\n");
	printf("Tensao �: T = 2,4 x F / A\n");
	printf("�rea �: Diametro x Valor da cota esmagada x quantidade de faces\n");
	printf("Area �: Valor do diametro � %.2f x cota %.2f quantidade de faces %.2f\n",diametro, cota, faces);
	printf("�rea �: %.2f\n",area);
	printf("Equa��o para copiar: \n");
	printf("T = 2,4 x F / A\n");
	printf("T = 2,4 x %.2f / (%.2f x %.2f) x %.2f\n", forca, diametro, cota, faces);
	printf("T = 2,4 x %.2f / %.2f\n",forca,area);
	printf("T = %.2f / %.2f\n", aux, area);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u�\n", tensao);
	printf("Fim da equa��o \n");
	return tensao;
}
float vCisPino(float forca, float faces, float diametro, float constPi){
	float tensao; // Vari�vel da tens�o
	float aux;
	float raio = diametro/2;
	float area;
    area = (raio * raio) * constPi;
	aux = 0.7 * area; //Equca��o relacionada da area com 0.7
	tensao = forca / aux; //Valor final da tensao
	/*
		Parte de escrita na tela com a equa��o do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENS�O DO CISALHAMENTO=============================\n");
	printf("==============================================================================\n");
	printf("Tensao �: T = F / 0,7 x A\n");
	printf("Area �: raio� x valor de PI x quantidade de faces\n");
	printf("Area �: Valor do raio %.2f� x valor de PI %.2f x quantidade de faces %.2f\n", raio, constPi, faces);
	printf("Area �: %.2f\n",area);
	printf("Equacao para copiar: \n");
	printf("T = F / 0,7 x A\n");
	printf("T = %.2f / 0,7 x (%.2f� x %.2f) x %.2f\n", forca, raio, constPi, faces);
	printf("T = %.2f / 0,7 x %.2f\n",forca, area);
	printf("T = %.2f / %.2f\n", forca, aux);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u�\n", tensao);
	printf("Fim da equa��o \n");
	return tensao;
}
