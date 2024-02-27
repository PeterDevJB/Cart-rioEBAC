#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço de memória.
#include <locale.h> //Biblioteca de alocações de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das string.

int registro()
{
	char arquivo[30];
	char cpf[30];
	char nome[30];
	char sobrenome[30];
	char cargo[30];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo ,"w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digete o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[30];
	char conteudo[200];
	
	printf("Digite o CPF a ser constultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Esse CPF não foi registrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Essas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{

	char cpf[30];

	printf("Escolha o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if (file == NULL)
	{
		printf("Este CPF não é cadastrado no sistema.\n");
		system("pause");
	}

	remove(cpf);
	
	if (file != NULL)
	{
		printf("CPF deletado com sucesso!\n");
		system("pause");
	}

}

int main()
{

	int opcao=0; //Definindo variáveis.
	
	int laco=1;

	for (laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem.
		
		printf("Cartório da EBAC\n\n"); //Inicio do menu.
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nome.\n");
		printf("\t2 - Consultar nome.\n");
		printf("\t3 - Deletar nome.\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário.
		
		system("cls");
			
		switch(opcao)
		
		{
			case 1:
			registro();
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não existe!\n");
			system("pause");
			break;
		}
			
	}
}
