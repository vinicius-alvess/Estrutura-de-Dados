//
//  BibBuscas.c
//  EDABuscaSeqBin
//
//  Created by Nilton Correia da Silva on 22/03/21.
//

#include <stdlib.h>
#include "BibBuscas.h"


void GeraAleatorioInt(int *pvetor, int pTAM){
    int pind, ppos, paux;
    for(pind=0;pind<pTAM;pind++){
        pvetor[pind] = pind+1;
    }
//Randomizando (Algoritmo de Fischer-Yates)
    for(pind=(pTAM-1);pind>0;pind--){
        ppos = rand() % pind;
        if(ppos != pind){
            paux = pvetor[pind];
            pvetor[pind] = pvetor[ppos];
            pvetor[ppos] = paux;
        }
    }
}

void GeraOrdenadoInt(int *pvetor, int pTAM){
    int pind;
    for(pind=0;pind<pTAM;pind++){
        pvetor[pind] = pind+1;
    }
}


//Buscas:

int BuscaAleatoriaInt(int *pvetor, int pTAM, int pvalor){
   //SEU CÓDIGO AQUI


}

int BuscaBinariaInt(int *pvetor, int pTAM, int pvalor){
 //SEU CÓDIGO AQUI

}
