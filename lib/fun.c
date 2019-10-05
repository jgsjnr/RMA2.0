#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

//Função de calculo de tensão
float vTen_Aste(float forca, float diametro, float consPi){
    float area;
    float result;
    area = (diametro * diametro) * consPi;
    result = forca / area;
    printf("==============================================================================\n");
	printf("===========================TENSÃO DE TRAÇÃO NA ASTE===========================\n");
	printf("==============================================================================\n");
    printf("Tensão é: T=F/A\n");
    printf("Area é: Valor da cota %.2f² x valor de PI %.2f\n", diametro, consPi);
    printf("Valor da Area %.2f \n", area);
    printf("Equação para copiar: \n");
    printf("T = F / A\n");
    printf("T = %.2f / %.2f\n", forca, area);
    printf("T = %.2f\n", result);
    printf("Valor final = %.2f kgf/u²\n", result);
    printf("Fim da equação \n");
    return result;
}
float vTen(float forca, float faces, float ladoA,float ladoB){
    float area = 0;
    float result = 0;
    area = (ladoA * ladoB) * faces;
    result = forca / area;
    printf("==============================================================================\n");
	printf("===============================TENSÃO DE TRAÇÃO===============================\n");
	printf("==============================================================================\n");
    printf("Tensão é: T=F/A\n");
    printf("Area é: Valor da cota %.2f x valor da cota %.2f x quantidade de faces %.2f\n", ladoA, ladoB, faces);
    printf("Valor da Area %.2f \n", area);
    printf("Equação para copiar: \n");
    printf("T = F / A\n");
    printf("T = %.2f / %.2f\n", forca, area);
    printf("T = %.2f\n", result);
    printf("Valor final = %.2f kgf/u²\n", result);
    printf("Fim da equação \n");
    return result;
}
float vEsm(float forca, float faces, float ladoA, float ladoB){
	float tensao; // Variável da tensão
	float area; //Variavel da áre
	float aux; //Variavel auxiliar para calcular a força;
	area = ladoA * ladoB * faces; //Variavel do valor geral da area
	aux = forca * 2.4; //Variavel auxilar da força multiplicando o valor constante de 2.4
	tensao = aux / area; //calculo final do componente
	/*
		Parte de escrita na tela com a equação do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENSÃO DO ESMAGAMENTO==============================\n");
	printf("==============================================================================\n");
	printf("Tensao é: T = 2,4 x F / A\n");
	printf("Área é: lado A x lado B x quantidade de faces\n");
	printf("Área é: ( %.2f x %.2f x %.2f ) \n", ladoA, ladoB, faces);
	printf("Área é: %.2f\n",area);
	printf("Equação para copiar: \n");
	printf("T = 2,4 x F / A\n");
	printf("T = 2,4 x %.2f / (%.2f x %.2f) x %.2f\n", forca, ladoA, ladoB, faces);
	printf("T = 2,4 x %.2f / %.2f\n",forca,area);
	printf("T = %.2f / %.2f\n", aux, area);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u²\n", tensao);
	printf("Fim da equação \n");
	return tensao;
}
float vCis(float forca, float faces, float ladoA, float ladoB){
	float tensao; // Variável da tensão
	float area; //Variavel da áre
	float aux; //Variavel auxiliar para calcular a força;
	area = ladoA * ladoB * faces; //Variavel do valor geral da area
	aux = 0.7 * area; //Equcação relacionada da area com 0.7
	tensao = forca / aux; //Valor final da tensao
	/*
		Parte de escrita na tela com a equação do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENSÃO DO CISALHAMENTO=============================\n");
	printf("==============================================================================\n");
	printf("Tensao é: T = F / 0,7 x A\n");
	printf("Area é: lado A x lado B x quantidade de faces");
	printf("Area é: (%.2f x %.2f) x %.2f\n", ladoA, ladoB, faces);
	printf("Area é: %.2f\n",area);
	printf("Equacao para copiar: \n");
	printf("T = F / 0,7 x A\n");
	printf("T = %.2f / 0,7 x (%.2f x %.2f) x %.2f\n", forca, ladoA, ladoB, faces);
	printf("T = %.2f / 0,7 x %.2f\n",forca, area);
	printf("T = %.2f / %.2f\n", forca, aux);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u²\n", tensao);
	printf("Fim da equação \n");
	return tensao;
}


/*
"=============================================================================
"===========================TENSÃO DO ESMAGAMENTO DO PINO=====================
"=============================================================================
 */

float vEsmPino(float forca, float faces, float diametro, float cota){
	float tensao; // Variável da tensão
	float aux;
	float raio = diametro/2;
	float area;
    area = diametro * cota * faces;
	aux = forca * 2.4; //Variavel auxilar da força multiplicando o valor constante de 2.4
	tensao = aux / area; //calculo final do componente
	/*
		Parte de escrita na tela com a equação do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENSÃO DO ESMAGAMENTO DO PINO======================\n");
	printf("==============================================================================\n");
	printf("Tensao é: T = 2,4 x F / A\n");
	printf("Área é: Diametro x Valor da cota esmagada x quantidade de faces\n");
	printf("Area é: Valor do diametro é %.2f x cota %.2f quantidade de faces %.2f\n",diametro, cota, faces);
	printf("Área é: %.2f\n",area);
	printf("Equação para copiar: \n");
	printf("T = 2,4 x F / A\n");
	printf("T = 2,4 x %.2f / (%.2f x %.2f) x %.2f\n", forca, diametro, cota, faces);
	printf("T = 2,4 x %.2f / %.2f\n",forca,area);
	printf("T = %.2f / %.2f\n", aux, area);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u²\n", tensao);
	printf("Fim da equação \n");
	return tensao;
}
float vCisPino(float forca, float faces, float diametro, float constPi){
	float tensao; // Variável da tensão
	float aux;
	float raio = diametro/2;
	float area;
    area = (raio * raio) * constPi;
	aux = 0.7 * area; //Equcação relacionada da area com 0.7
	tensao = forca / aux; //Valor final da tensao
	/*
		Parte de escrita na tela com a equação do componente.
	*/
	printf("==============================================================================\n");
	printf("===========================TENSÃO DO CISALHAMENTO=============================\n");
	printf("==============================================================================\n");
	printf("Tensao é: T = F / 0,7 x A\n");
	printf("Area é: raio² x valor de PI x quantidade de faces\n");
	printf("Area é: Valor do raio %.2f² x valor de PI %.2f x quantidade de faces %.2f\n", raio, constPi, faces);
	printf("Area é: %.2f\n",area);
	printf("Equacao para copiar: \n");
	printf("T = F / 0,7 x A\n");
	printf("T = %.2f / 0,7 x (%.2f² x %.2f) x %.2f\n", forca, raio, constPi, faces);
	printf("T = %.2f / 0,7 x %.2f\n",forca, area);
	printf("T = %.2f / %.2f\n", forca, aux);
	printf("T = %.2f\n", tensao);
	printf("Valor final = %.2f kgf/u²\n", tensao);
	printf("Fim da equação \n");
	return tensao;
}
