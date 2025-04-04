//Este arquivo é parte do programa Dim-ac

//Dim-ac é um software livre; você pode redistribuí-lo e/ou
//modificá-lo dentro dos termos da Licença Pública Geral GNU como
//publicada pela Free Software Foundation (FSF); na versão 3 da
//Licença, ou (a seu critério) qualquer versão posterior.

//Este programa é distribuído na esperança de que possa ser útil,
//mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
//a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
//Licença Pública Geral GNU para maiores detalhes.

//Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
//com este programa, Se não, veja <http://www.gnu.org/licenses/>.


#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct astma120 tamtubo (float d){
    setlocale(LC_ALL,"");
    struct astma120 tamanho, tubo[14];
    // Abrir arquivo com dados os diametros dos tubos
    FILE* tubos;
    tubos=fopen("/opt/dim-ac/data/tamtubo.csv","r");

    //Verificar se o arquivo foi aberto corretamente.
    if(tubos == NULL){
        printf("Arquivo tamtubo.csv não aberto. \n");
        exit;
    }
    //transfere dados para um struct
    for (int i = 0; i < 14; i++) {
        fscanf(tubos,"%i %s %f", &tubo[i].index , &tubo[i].nome , &tubo[i].tam);
    }
        fclose(tubos); // fecha o arquivo.

    /*
     * Verifica o tamanho superior mais proximo do encontrado no calculo
     * e adiciona os valores a um struct simples para retorno.
     */
    for (int i = 0; i < 14; i++) {
        if (d < tubo[i].tam){
            tamanho.index=tubo[i].index;
            strcpy(tamanho.nome,tubo[i].nome);
            tamanho.tam=tubo[i].tam;
            break;
        }
    }
    // Retorna o struct tamanho.
    return tamanho;
}

float tubosing(struct astma120 tamanho, char* singularidade, int conex,float un) {
    setlocale(LC_ALL,"");
    struct sing{
            int index;
            float rosq;
            float flan;

        };
    struct sing tubo[14];
    float total=0;
    char Filename[200]="/opt/dim-ac/data/";

    //Concatena o caminho absoluto ao nome do arquivo da singularidade.
    *Filename = *strcat(Filename,singularidade);

    //Abrir arquivo com dados os diametros dos tubos
    FILE* tubos;
    tubos=fopen(Filename,"r");

    //Verificar se o arquivo foi aberto corretamente.
    if(tubos == NULL){
        printf("Arquivo %s não aberto. \n",singularidade);
        exit;
    }
    //transfere dados para um struct
    for (int i = 0; i < 14; i++) {
        fscanf(tubos,"%i %f %f", &tubo[i].index , &tubo[i].rosq , &tubo[i].flan);
    }
        fclose(tubos); // fecha o arquivo.

    //Verifica se é flange ou rosca, usnado a variavel correta.
    if (conex==1){
    total=tubo[tamanho.index-1].flan*un;
    }
    if(conex==2){
        total=tubo[tamanho.index-1].rosq*un;
    }
    // Retorna o tamanho equivalente em comprimento de tubo da singularidade.
    return total;
}
