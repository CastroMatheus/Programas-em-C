// Aluno : Matheus Castro de Queirós

/*
 Sintese
   Objetivo: Ler a quantidade de animais de um zoologico e para cada animal deve ser informado o codigo e o peso.
 
   Entrada : quantidade de animais, codigo e peso

   Saida   :  identificação e o peso do animal mais pesado , a identificação e o peso do animal mais leve,e a quantidade de animais 
              com peso menor que o peso médio de todos os animais 

*/

#include <stdio.h>
#include <conio.c>
#define MAX_ANIMAIS 500
#define MSG_ERRO printf("Dado Invalido!\n");

int leInt(char titulo[]);
int leValidaInt(char titulo[], int min, int max);
int verificaRepeticao(int ids[], int cont, int id);
void apresentaDados(int ids[], int pesos[], int cont, int pesoLeve, int pesoPesado, int totalPeso);

int main(void)
{
// Declaracoes
   int qtdAnimais, ids[MAX_ANIMAIS], pesos[MAX_ANIMAIS], cont, aux, pesoPesado, pesoLeve, totalPesos=0;
// Instrucoes
   qtdAnimais = leValidaInt("Digite a quantidade de animais no Zoologico: ", 1, 500);
   clrscr();
   for(cont = 0; cont < qtdAnimais; cont++){
      printf("%d%c Animal\n", cont+1, 167);      
      do{
         ids[cont] = leValidaInt("Digite o id : ", 1, 500);
         aux = verificaRepeticao(ids, cont, ids[cont]);
         if(aux == 1){
           MSG_ERRO
         }
      }while(aux == 1);
      pesos[cont] = leValidaInt("Digite o peso do animal em gramas: ", 1, 9999999);
      totalPesos+= pesos[cont];
      if(cont == 0){
        pesoPesado = pesos[cont];
        pesoLeve = pesos[cont];
      }else if(pesoPesado < pesos[cont]){
        pesoPesado = pesos[cont];
      }
      if(cont > 0){
        if(pesoLeve > pesos[cont]){
          pesoLeve = pesos[cont];
        }     
      }
      clrscr();
   }
   apresentaDados(ids, pesos, cont, pesoLeve, pesoPesado, totalPesos);

  getch();
  return 0;
}

//Objetivo: ler numero inteiro
//Parametros: referencia ao titulo
//Retorno: numero lido
int leInt(char titulo[]){
    int numero, ret;
    do{
       printf(titulo);
       fflush(stdin);
       ret = scanf("%d", &numero);
       fflush(stdin);
       if(ret == 0){
         clrscr();
         MSG_ERRO         
       }
    }while(ret == 0);
    return numero;    
}

//Objetivo: validar numero inteiro
//Parametros: referencia ao titulo, min e max
//Retorno: numero validado
int leValidaInt(char titulo[], int min, int max){
    int numero;
    do{
       numero = leInt(titulo);
       if(numero < min || numero > max){clrscr();MSG_ERRO};
    }while(numero < min || numero > max);
}

//Objetivo: verificar id repetido
//Parametros: referencia ao id, cont e id sendo verificado
//Retorno: 1 para repetido 0 para nao repetido
int verificaRepeticao(int ids[], int cont, int id){
    int aux, flag=0;
    for(aux = 0; aux < cont; aux++){
      if(id == ids[aux]){
        flag = 1;
        return flag;
      }else{
        flag = 0;
      }
    }
    return flag;
}

//Objetivo: apresentar dados
//Parametros: referencia aos ids e aos pesos, cont, pesoLeve, pesoPesado, totalPeso
//Retorno: nenhum
void apresentaDados(int ids[], int pesos[], int cont, int pesoLeve, int pesoPesado, int totalPeso){
     int aux, abaixoMedia=0;
     float media;
     clrscr();
     media = (float)totalPeso/cont;
     printf("Animais mais pesados\nId\t\tPeso\n");
     for(aux = 0; aux < cont; aux++){
       if(pesos[aux] == pesoPesado){
         printf("%-8d %10d\n", ids[aux], pesos[aux]);              
       }
     }
     
     printf("Animais mais leves\nId\t\tPeso\n");
     for(aux = 0; aux < cont; aux++){
       if(pesos[aux] == pesoLeve){
         printf("%-8d %10d\n", ids[aux], pesos[aux]);              
       }
     }
     
      for(aux = 0; aux < cont; aux++){
       if(pesos[aux] < media){
         abaixoMedia++;              
       }
     }
     
     printf("A quantidade de animais com peso abaixo da media e: %d", abaixoMedia);
} 
