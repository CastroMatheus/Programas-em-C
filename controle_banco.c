// Aluno : Matheus Castro de Queirós

/*
 Sintese
   Objetivo: Solicitar o numero da conta de clientes de um banco e seu saldo atual e depois apresentar os clientes que 
   			 possuem o maior e o menor saldo (pode ter varios) e a quantidade de clientes com saldo abaixo da media.
 
   Entrada : quantidade de clientes(ate mil), numero da conta e saldo atual

   Saida   :  clientes que possuem o maior e o menor saldo (pode existir mais de um cliente), clientes com saldo menor que o saldo médio

*/

#include <stdio.h>
#include <conio.c>
#define MAX_CLIENTES 1000
#define MSG_ERRO printf("\nDado Invalido!\n");

int leInt(char titulo[]);
int leValidaInt(char titulo[], int min, int max);
int verificaConta(int contas[], int cont, int conta);
float leFloat(char titulo[]);
//float leValidaFloat(char titulo[], float min, float max);
void apresentaMaiorSaldo(float saldos[], int cont);
void apresentaMenorSaldo(float saldos[], int cont);
void apresentaAbaixoMedia(float media, float saldos[], int cont);


int main(void)
{
// Declaracoes
   int qtdClientes, numeroContas[MAX_CLIENTES], cont, flag;
   float saldos[MAX_CLIENTES], totalSaldo = 0, saldoMedio;
// Instrucoes
   qtdClientes = leValidaInt("Digite a quantidade de cliente no banco: ", 1, 1000);
   clrscr();
   for(cont = 0; cont < qtdClientes; cont++){
		printf("%d cliente\n", cont+1);
		do{
		  numeroContas[cont] = leValidaInt("Digite o numero da conta: ", 1, 1000);
		  flag = verificaConta(numeroContas, cont, numeroContas[cont]);
		  if(flag == 1)
		  	printf("Esta conta ja existe!\n");	
		}while(flag == 1);
		saldos[cont] = leFloat("Digite o saldo da conta: ");
		totalSaldo += saldos[cont];
		clrscr();
   }
   saldoMedio = totalSaldo/cont;
   apresentaMaiorSaldo(saldos, cont);
   apresentaMenorSaldo(saldos, cont);
   apresentaAbaixoMedia(saldoMedio, saldos, cont);

  getch();
  return 0;
}

//Objetivo: ler numero inteiro
//Parametros: referencia ao titulo
//Retorno: numero lido
int leInt(char titulo[]){
	int numero;
	printf(titulo);
	scanf("%d", &numero);
	return numero;
}

//Objetivo: validar numero inteiro
//Parametros: referencia ao titulo, min e max
//Retorno: numero validado
int leValidaInt(char titulo[], int min, int max){
	int numero;
	do{
	  numero = leInt(titulo);
	  if(numero < min || numero > max){
			MSG_ERRO
	  }
	}while(numero < min || numero > max);
	
	return numero;
}

//Objetivo: verificar se a conta ja existe
//Parametros: referencia ao vetor contas, cont e conta a ser verificada
//Retorno: 1 para existente e 0 para inexistente
int verificaConta(int contas[], int cont, int conta){
	int aux, flag;
	for (aux = 0; aux < cont; aux++){
		if(conta == contas[aux]){
			flag = 1;
			break;
		}else
			flag=0;
	}
	
	return flag;
}

//Objetivo: ler um float
//Parametros: referencia ao titulo
//Retorno: numero lido
float leFloat(char titulo[]){
	float numero;
	printf(titulo);
	scanf("%f", &numero);
	return numero;
}

/*
float leValidaFloat(char titulo[], float min, float max){
	float numero;
	do{
	  numero = leFloat(titulo);
	  if(numero < min || numero > max){
			MSG_ERRO
	  }
	}while(numero < min || numero > max);
	
	return numero;
}
*/

//Objetivo: apresenta o maior saldo e os clientes que possuem o maior saldo
//Parametros: referencia ao vetor saldos e cont
//Retorno: nenhum
void apresentaMaiorSaldo(float saldos[], int cont){
	int aux;
	float maiorSaldo;
	for (aux = 0; aux < cont; aux++){
		if(aux == 0){
		  maiorSaldo = saldos[aux];	
		}else if(maiorSaldo < saldos[aux]){
			maiorSaldo = saldos[aux];
		}	
	}
	system("color F0");
	printf("===================================\nO maior saldo e: %.2f\n===================================\nOs clientes que possuem os maiores saldos sao: \n", maiorSaldo);
	for(aux = 0; aux < cont; aux++){
		if(maiorSaldo == saldos[aux]){
			printf("O cliente %d\n\n", aux+1);
		}
	}
}

//Objetivo: apresenta o menor saldo e os clientes que possuem o menor saldo
//Parametros: referencia ao vetor saldos e cont
//Retorno: nenhum
void apresentaMenorSaldo(float saldos[], int cont){
	int aux;
	float menorSaldo;
	for (aux = 0; aux < cont; aux++){
		if(aux == 0){
		  menorSaldo = saldos[aux];	
		}else if(menorSaldo > saldos[aux]){
			menorSaldo = saldos[aux];
		}	
	}
	printf("===================================\nO menor saldo e: %.2f\n===================================\nOs clientes que possuem os menores saldos sao: \n", menorSaldo);
	for(aux = 0; aux < cont; aux++){
		if(menorSaldo == saldos[aux]){
			printf("O cliente %d\n\n", aux+1);
		}
	}
}

//Objetivo: apresenta a media dos saldo e os clientes que possuem o saldo abaixo da media
//Parametros: referencia ao vetor saldos, cont e media
//Retorno: nenhum
void apresentaAbaixoMedia(float media, float saldos[], int cont){
	int aux, flag=0;
	printf("===================================\nO saldo medio dos clientes e de: %.2f\n===================================\n", media);
	printf("Os cliente que possuem saldo abaixo da media sao: \n");
	for(aux = 0; aux < cont; aux++){
		if(media > saldos[aux]){
			printf("O cliente %d com saldo: %.2f\n", aux+1, saldos[aux]);
			flag++;
		}
	}
	if(flag == 0)
		printf("Nenhum.");
}
