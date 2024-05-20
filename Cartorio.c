#include <stdio.h> //biblioeta de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioetca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistemas
{
	//inicio  da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a STRING
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo eo "w" siginifica ESCREVER
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //colocando o NOME do usu�rio
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //colocando o SOBRENOME do usu�rio
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //colocando o CARGO do usu�rio
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//Variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Consulta do CPF
	scanf("%s" ,cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //salva o valor da variavel
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Informa��es do usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	//Varivel
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a ser deletado: "); //CPF solicitado
	scanf("%s", cpf);
	
	remove(cpf); //remover o arquivo "cpf"
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir arquivo com nome igual ao "cpf"
	
	if(file != NULL) //SE o arquivo AINDA existe, ou seja, se for DIFERENTE de NULL 
	{
		printf("Usu�rio deletado com Sucesso!\n");
		system("pause");			
	}
	else // SE o arquivo n�o existir, ou seja arquivo n�o encontra/deletado do sistema
	{
		printf("Usu�rio n�o encontrado no sistema!\n");
		system("pause");
	}
}
	
int main() //definindo vari�veis
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //substitui��o do IF por SWITCH_CASE para simplificar/otimizar o c�digo
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
			
	}
		
}
