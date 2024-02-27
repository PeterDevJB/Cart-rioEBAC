#include <stdio.h> //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria.
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das string.

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
		printf("Esse CPF n�o foi registrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Essas s�o as informa��es do usu�rio:\n");
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
		printf("Este CPF n�o � cadastrado no sistema.\n");
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

	int opcao=0; //Definindo vari�veis.
	
	int laco=1;

	for (laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem.
		
		printf("Cart�rio da EBAC\n\n"); //Inicio do menu.
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nome.\n");
		printf("\t2 - Consultar nome.\n");
		printf("\t3 - Deletar nome.\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio.
		
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
			printf("Essa op��o n�o existe!\n");
			system("pause");
			break;
		}
			
	}
}
