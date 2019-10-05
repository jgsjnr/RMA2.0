#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/fun.h"
#include "lib/structs.h"
#include "lib/quota.h"
#include <conio.h>

#define PI 3.1415
int main()
{
    setlocale(LC_ALL, "");
    int numAluno;
    printf("Numero recebido pelo professor: ");
    scanf("%d",&numAluno);
    int vForca;
    printf("Digite o valor de forca recebido: ");
    scanf("%d",&vForca);
    int i = 0;
    /*
    PARTE REFERENTE APENAS A ASTE
    OS VALORES INSERIDOS SERÃO REFERENTES A ASTE
    */

    //ATRIBUIÇÃO DAS COTAS REFERENTES A ESTUTURA DE COTAS
    peca.cota[0] = 15+(numAluno/4); //DIAMETRO COTA DO PINO 1
    peca.cota[1] = 7+(numAluno/4); //FACE DA PEÇA A1
    peca.cota[2] = 12+(numAluno/4); //COTA DA PEÇA A2
    peca.cota[3] = 8+(numAluno/4); //COTA DE PEÇA B2
    peca.cota[4] = 6+(numAluno/2); //COTA DA PEÇA B1
    peca.cota[5] = 17+(numAluno/3); //DIAMETRO COTA DO PINO 2
    peca.cota[6] = ((36+(numAluno/4)) - peca.cota[0])/2; // COTA DA PEÇA VISTA B - DIAMETRO DO PINO / 2
    peca.cota[7] = 13+(numAluno/3); // COTA DA ALTURA DE CIMA DA PEÇA A2
    peca.cota[8] = 14+(numAluno/3); //COTA DA ALTURA DE BAIXO DA PEÇA A1
    peca.cota[9] = 12+(numAluno/3); //COTA DA ALTURA DA PEÇA B1
    peca.cota[10] = 10+numAluno; //COTA DA ALTURA DA PEÇA B1
    peca.cota[11] = ((36+(numAluno/4))- peca.cota[5])/2; //COTA AUXILIAR DAPARTE DE BAIXO DA PECA RETIRANDO O PINO
    peca.di[0] = (10 + (numAluno / 2));
    peca.di[2] = peca.di[0]/2;
    //DEMOSNTRATIVO DE TODAS AS COTAS DAS PEÇAS
        printf("O valor da cota 15+(num Aluno/4) é = %.2f \n", peca.cota[0]);
        printf("O valor da cota 7+(numAluno/4) é = %.2f \n", peca.cota[1]);
        printf("O valor da cota 12+(numAluno/4) é = %.2f \n", peca.cota[2]);
        printf("O valor da cota 8+(numAluno/4) é = %.2f \n", peca.cota[3]);
        printf("O valor da cota 6+(numAluno/2) é = %.2f \n", peca.cota[4]);
        printf("O valor da cota 17+(numAluno/3) é = %.2f \n", peca.cota[5]);
        printf("O valor da cota ((36+numAluno/4) - 15+(num Aluno/4)/2 é = %.2f \n", peca.cota[6]);
        printf("O valor da cota 13+(numAluno/3) é = %.2f \n", peca.cota[7]);
        printf("O valor da cota 14+(numAluno/3) é = %.2f \n", peca.cota[8]);
        printf("O valor da cota 12+(numAluno/3) é = %.2f \n", peca.cota[9]);
        printf("O valor da cota 10+(numAluno) é = %.2f \n", peca.cota[10]);
        printf("O valor da cota ((36+numAluno/4) - 17+num Aluno/3)/2 é = %.2f \n", peca.cota[11]);
        printf("O valor da cota do diametro da ASTE 10+(numAluno/2) é = %.2f e o RAIO %.2f \n",peca.di[0], peca.di[2]);
    //ATRIBUIÇÃO DE TODAS AS FACES NO ESQUEMA DE COTAS
    a1.faces[0] = 4;
    a1.faces[1] = 4;
    a1.faces[2] = 2;
    a2.faces[0] = 2;
    a2.faces[1] = 2;
    a2.faces[2] = 1;
    b2.faces[0] = 4;
    b2.faces[1] = 4;
    b2.faces[2] = 2;
    b1.faces[0] = 6;
    b1.faces[1] = 6;
    b1.faces[2] = 3;
    pIno1.faces[0] = 2;//FACES PARA O CISALHAMENTO
    pIno1.faces[1] = 2;//FACES PARA O ESMAGAMENTO
    pIno1.faces[2] = 1;//FACES PARA O ESMAGAMENTO SEGUNDA PARTE
    pIno2.faces[0] = 4;//FACES PARA O CISALHAMENTO
    pIno2.faces[1] = 2;//FACES PARA O ESMAGAMENTO
    pIno2.faces[2] = 3;//FACES PARA O ESMAGAMENTO SEGUNDA PARTE
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PEÇA A1===========================\n");
	printf("==============================================================================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                a1.vTens[i] = vTen(vForca,a1.faces[i],peca.cota[1],peca.cota[6]);
                break;
            case 1:
                a1.vTens[i] = vCis(vForca,a1.faces[i],peca.cota[1],peca.cota[8]);
                break;
            case 2:
                a1.vTens[i] = vEsm(vForca,a1.faces[i],peca.cota[1],peca.cota[0]);
                break;
            default:
                system("pause");
                break;
        }
    }
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PINO P1===========================\n");
	printf("============================EM RELAÇÃO A PEÇA A1==============================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                pIno1.vTens[i] = vCisPino(vForca,pIno1.faces[i],peca.cota[0],PI);
                break;
            case 1:
                pIno1.vTens[i] = vEsmPino(vForca,pIno1.faces[i],peca.cota[0],peca.cota[1]);
                break;
            default:
                getch();
                break;
        }
    }
    printf("==============================================================================\n");
    printf("============================EM RELAÇÃO A PEÇA A2==============================\n");
    pIno1.vTens[2] = vEsmPino(vForca,pIno1.faces[2],peca.cota[0],peca.cota[2]);
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PEÇA A2===========================\n");
	printf("==============================================================================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                a2.vTens[i] = vTen(vForca,a2.faces[i],peca.cota[2],peca.cota[6]);
                break;
            case 1:
                a2.vTens[i] = vCis(vForca,a2.faces[i],peca.cota[2],peca.cota[7]);
                break;
            case 2:
                a2.vTens[i] = vEsm(vForca,a2.faces[i],peca.cota[2],peca.cota[0]);
                break;
            default:
                system("pause");
                break;
        }
    }
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES ASTE==============================\n");
	printf("==============================================================================\n");
	peAste.result = vTen_Aste(vForca,peca.di[2],PI);
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PEÇA B2===========================\n");
	printf("==============================================================================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                b2.vTens[i] = vTen(vForca,b2.faces[i],peca.cota[3],peca.cota[11]);
                break;
            case 1:
                b2.vTens[i] = vCis(vForca,b2.faces[i],peca.cota[3],peca.cota[10]);
                break;
            case 2:
                b2.vTens[i] = vEsm(vForca,b2.faces[i],peca.cota[3],peca.cota[5]);
                break;
            default:
                system("pause");
                break;
        }
    }
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PINO P2===========================\n");
	printf("============================EM RELAÇÃO A PEÇA B2==============================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                pIno2.vTens[i] = vCisPino(vForca,pIno2.faces[i],peca.cota[5],PI);
                break;
            case 1:
                pIno2.vTens[i] = vEsmPino(vForca,pIno2.faces[i],peca.cota[5], peca.cota[10]);
                break;
            default:
                getch();
                break;
        }
    }
    printf("==============================================================================\n");
    printf("============================EM RELAÇÃO A PEÇA B1==============================\n");
    pIno2.vTens[2] = vEsmPino(vForca,pIno2.faces[2],peca.cota[5], peca.cota[9]);
    printf("==============================================================================\n");
	printf("=========================VALORES E EQUAÇÔES PEÇA B1===========================\n");
	printf("==============================================================================\n");
    for(i = 0; i < 3; i++){
        switch(i)
        {
            case 0:
                b1.vTens[i] = vTen(vForca,b1.faces[i],peca.cota[4],peca.cota[11]);
                break;
            case 1:
                b1.vTens[i] = vCis(vForca,b1.faces[i],peca.cota[4],peca.cota[9]);
                break;
            case 2:
                b1.vTens[i] = vEsm(vForca,b1.faces[i],peca.cota[4],peca.cota[5]);
                break;
            default:
                system("pause");
                break;
        }
    }
    return 0;
}
