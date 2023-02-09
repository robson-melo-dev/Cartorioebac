#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //biblioteca de manipulação de strings

int registro(){ //função para executar o registro de nomes
	//início da declaração de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da declaração de variáveis
	
	printf("Difite o CPF a ser cadastrado: ");  //início da coleta de dados
	scanf("%s", cpf); //%s denota variável do tipo string
	
	strcpy(arquivo, cpf); //copiando o valor da string cpf para a string arquivo
	
	FILE *file; //chamando a função FILE para criar um arquivo
	file = fopen(arquivo, "w"); //criando um arquivo com o nome igual ao valor da variável arquivo no modo escrita ("w")
	fprintf(file, cpf); //salva o valor da variável cpf no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo atualização
	fprintf(file, ","); //insere uma vírgula no arquivo para servir como separador entre os dados
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


int consulta(){//função para executar a consulta de nomes
	setlocale (LC_ALL, "Portuguese_Brazil.1252"); //define a linguagem de saída
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo com o nome cpf no modo leitura
	
	if(file == NULL)
	{
		printf("O CPF não foi localizado ... /n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //passa o conteúdo do arquivo para a variável conteúdo enquanto não houver caracteres nulos
	{
		printf("\nEssas são as informações do usuário (CPF, Nome, Sobrenome, Cargo):\n");
		printf("%s", conteudo);
		printf("\n\n\n\n");
		
	}
	
	system("pause");	
	fclose(file);
}


int deletar(){//função para executar a deleção de nomes

	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	if(remove(cpf) == NULL) //verifica se foi possível executar a deleção. Se sim retorna mensagem de sucesso, senão retorna mensagem de erro
	{
		printf("\nO usuário com cpf %s", cpf);
		printf(" foi deletado com sucesso...");
		system("pause");
	}
	else
	{
		printf("\nErro! Não foi possivel deletar o usuário com cpf %s", cpf);
		printf(" ou ele não está cadastrado!");
		system("pause");
		
	}
	
	//FILE *file;
	//file = fopen(cpf, "r"); //Abre o arquivo com o nome equivalente ao cpf no modo leitura
	//
	//if(file == NULL)
	//{
	//	printf("O usuário não foi encontrado...\n");
	//	system("pause");
	//	
	//}
	
	
}



int main() //função principal da aplicação
{
	//definição e inicialização de variáveis
	int opcao = 0;
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		setlocale (LC_ALL, "Portuguese_Brazil.1252"); //definição da linguagem de saída
		system("cls"); //Limpeza da tela
	
	
		printf("==================================================CARTÓRIO DA EBAC==================================================\n\n");//início do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t 1- Registrar Nomes\n");
		printf("\t 2- Consultar Nomes\n");
		printf("\t 3- Deletar Nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção: "); //fim do menu
	
	
		scanf("%d", &opcao);//Entrada do usuário "%d" se refere à variável do tipo interiro

		switch(opcao) //início da seleção do menu
		{
			case 1:
				registro();	//chamada de função			
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
				printf("Esta opção é inválida!\n"); //mensagem padrão caso a opção entrada não seja nehum dos cases
				system("pause");
				break;
		}//fim da deleção do menu
	
	}	
	
}

