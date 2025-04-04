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

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#include <funcoes.h>


float lt, Q, dp, p;
float dimesionamento (float);

float dimensionamento(float , float, float, float ){
    float d;
    d=10*pow(((1.663785*0.001*pow(Q,1.85)*lt)/(dp*p)),(0.2));
    return d;
}



int main()
{
    setlocale(LC_ALL,"");
    float l1, l2=0, d1, d2, tamsing=0,quant;
    struct astma120 tamanho;
    char singularidade[50];
    int conex;
    printf( "Calculadora para calculo de dimensionamento de ar comprimido! \n" );

    /*
     * Calculo de dimensionamento de ar comprimido com
     * valor de linha sem singularidades.
    */
    printf( "Entre com o valor do tamanho da linha l1 em metros. (Sem singularidades). \n");
    scanf("%f",&l1);
    lt=l1+l2;
    printf( "Entre com o valor da vazão volumetrica em m³/h. \n");
    scanf("%f", &Q);
    printf( "Entre com o valor da queda de pressão esperada em kg/cm². \n");
    scanf("%f", &dp);
    printf( "Entre com o valor da pressão na tubulação em kg/cm². \n");
    scanf("%f", &p);
    d1=dimensionamento(lt,Q,dp,p);
    printf( "Dimetro interno da tubulçação para lt=l1 (Tamanho total da linha sem singularidades é %.2f mm: \n", d1);
    printf( "Tamanho do tubo na tabela ASTM A120 Schuled 40 para lt=l1: " );
    tamanho=tamtubo(d1);
    printf( "\n   Pol |   mm \n" );
    printf("    %s  |   %.2f \n", tamanho.nome, tamanho.tam);

    //Entrada de singularidades;
    //Curva de 90º curta;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de curvas de 90º curtas. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"c90curto.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das curvas de 90º curtas foi: %.2fm\n",tamsing);

    }

    //-----------------------------------------------------------------

    //Curva de 90º longa;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de curvas de 90º longa. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão.. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"c90longo.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das curvas de 90º longa foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Curva de 45º;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de curvas de 45º. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"c45.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das curvas de 45º foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Curva de 180º longo;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de curvas de 180º longo. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"c180longo.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das curvas de 90º curtas foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Tê com fluxo em linha;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade tês com fluxo em linha. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"teLinha.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente dos tês em linha foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //TÊ com fluxo em ramal;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade tês com fluxo em ramal. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"teRamal.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente dos tês com fluxo em ramal foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Válvula de gaveta ;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de válvulas de gaveta. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"valGav.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das válvulas de gaveta foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Válvulas globo;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de válvulas globo. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"valGlob.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das curvas de válvulas globo foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Válvula angular;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de Válvulas angulares. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"valAng.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das válvulas angulares foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Válvula retenção portinhola;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade válvulas de retenção portinhola. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"valPort.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das valvulas de retenção portinhola foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //União filtro Y;
    //---------------------------------------------------------------
    printf( "Entre com a quantidade de uniões filtro Y. \n");
    scanf("%f",&quant);
    if(quant!=0){
    printf( "Entre com o tipo de conexão. \n"
            "1-Flangeada;\n"
            "2-Rosqueada;\n");
    scanf("%i",&conex);
    *singularidade=*strcpy(singularidade,"uniaoFiltroY.csv");
    tamsing=tubosing(tamanho,singularidade,conex, quant);
    l2 = l2+tamsing;
    printf("O tamanho equivalente das uniões filtro Y foi: %.2fm\n",tamsing);
    }

    //-----------------------------------------------------------------

    //Valores totais das singularidades e linha com singularidades;
    lt=lt+l2;
    printf("O tamanho equivalente da singularidades totais foi: %.2fm.\n",l2);
    printf("O tamanho total da linha foi: %.2fm.\n",lt);

    /*
     * Calculo de dimensionamento de ar comprimido
     * com valor de linha mais singularidades.
    */

    d2=dimensionamento(lt,Q,dp,p);
    printf( "Dimetro interno da tubulçação é para lt=l1+l2 (Tamanho total da linha com singularidades): %.2f mm\n", d2 );
    if(d2>tamanho.tam){
    tamanho=tamtubo(d2);
    }
    printf( "Tamanho do tubo na tabela ASTM A120 Schuled 40 para lt=l1+l2. \n" );
    printf( "   Pol |   mm \n" );
    printf( "   %s  |   %.2f \n", tamanho.nome, tamanho.tam);
    return 0;
}

