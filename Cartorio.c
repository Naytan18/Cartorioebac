#include <stdio.h> //biblioeta de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioetca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistemas
{
	//inicio  da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a STRING
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo eo "w" siginifica ESCREVER
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //colocando o NOME do usuário
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //colocando o SOBRENOME do usuário
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //colocando o CARGO do usuário
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
		printf("Não foi possivel abrir o arquivo, não foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Informações do usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	//Varivel
	char cpf[40];
	
	printf("Digite o CPF do Usuário a ser deletado: "); //CPF solicitado
	scanf("%s", cpf);
	
	remove(cpf); //remover o arquivo "cpf"
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir arquivo com nome igual ao "cpf"
	
	if(file != NULL) //SE o arquivo AINDA existe, ou seja, se for DIFERENTE de NULL 
	{
		printf("Usuário deletado com Sucesso!\n");
		system("pause");			
	}
	else // SE o arquivo não existir, ou seja arquivo não encontra/deletado do sistema
	{
		printf("Usuário não encontrado no sistema!\n");
		system("pause");
	}
}
	
int main() //definindo variáveis
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //substituição do IF por SWITCH_CASE para simplificar/otimizar o código
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}
			
	}
		
}
