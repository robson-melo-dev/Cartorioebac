#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de manipula��o de strings

int registro(){ //fun��o para executar o registro de nomes
	//in�cio da declara��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da declara��o de vari�veis
	
	printf("Difite o CPF a ser cadastrado: ");  //in�cio da coleta de dados
	scanf("%s", cpf); //%s denota vari�vel do tipo string
	
	strcpy(arquivo, cpf); //copiando o valor da string cpf para a string arquivo
	
	FILE *file; //chamando a fun��o FILE para criar um arquivo
	file = fopen(arquivo, "w"); //criando um arquivo com o nome igual ao valor da vari�vel arquivo no modo escrita ("w")
	fprintf(file, cpf); //salva o valor da vari�vel cpf no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo atualiza��o
	fprintf(file, ","); //insere uma v�rgula no arquivo para servir como separador entre os dados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}


int consulta(){//fun��o para executar a consulta de nomes
	setlocale (LC_ALL, "Portuguese_Brazil.1252"); //define a linguagem de sa�da
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo com o nome cpf no modo leitura
	
	if(file == NULL)
	{
		printf("O CPF n�o foi localizado ... /n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //passa o conte�do do arquivo para a vari�vel conte�do enquanto n�o houver caracteres nulos
	{
		printf("\nEssas s�o as informa��es do usu�rio (CPF, Nome, Sobrenome, Cargo):\n");
		printf("%s", conteudo);
		printf("\n\n\n\n");
		
	}
	
	system("pause");	
	fclose(file);
}


int deletar(){//fun��o para executar a dele��o de nomes

	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	if(remove(cpf) == NULL) //verifica se foi poss�vel executar a dele��o. Se sim retorna mensagem de sucesso, sen�o retorna mensagem de erro
	{
		printf("\nO usu�rio com cpf %s", cpf);
		printf(" foi deletado com sucesso...");
		system("pause");
	}
	else
	{
		printf("\nErro! N�o foi possivel deletar o usu�rio com cpf %s", cpf);
		printf(" ou ele n�o est� cadastrado!");
		system("pause");
		
	}
	
	//FILE *file;
	//file = fopen(cpf, "r"); //Abre o arquivo com o nome equivalente ao cpf no modo leitura
	//
	//if(file == NULL)
	//{
	//	printf("O usu�rio n�o foi encontrado...\n");
	//	system("pause");
	//	
	//}
	
	
}



int main() //fun��o principal da aplica��o
{
	//defini��o e inicializa��o de vari�veis
	int opcao = 0;
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		setlocale (LC_ALL, "Portuguese_Brazil.1252"); //defini��o da linguagem de sa�da
		system("cls"); //Limpeza da tela
	
	
		printf("==================================================CART�RIO DA EBAC==================================================\n\n");//in�cio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t 1- Registrar Nomes\n");
		printf("\t 2- Consultar Nomes\n");
		printf("\t 3- Deletar Nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: "); //fim do menu
	
	
		scanf("%d", &opcao);//Entrada do usu�rio "%d" se refere � vari�vel do tipo interiro

		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
				registro();	//chamada de fun��o			
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
				
			
			default:
				printf("Esta op��o � inv�lida!\n"); //mensagem padr�o caso a op��o entrada n�o seja nehum dos cases
				system("pause");
				break;
		}//fim da dele��o do menu
	
	}	
	
}

