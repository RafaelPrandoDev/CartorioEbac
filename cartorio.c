#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

//Bibliotecas são coleções de recursos usados pelo computador

//Função serve para agrupar um código
//"int main" controla a execução direcionando a chamada para outras funções

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //"%s" se refere a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo ("w" significa escrever)
	fprintf(file,"CPF: "); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cpf); //inclui o CPF digitado pelo usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,", "); //inclui uma vírgula no arquivo para separar os dados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"NOME: "); //inclui o texto para identificar o próximo dado digitado pelo usuário
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); //inclui o nome digitado pelo usuário
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"SOBRENOME: ");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,"CARGO: ");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo referente ao CPF com o comando "r" para leitura
	
	if(file == NULL) //Se não houver o CPF consultado, retorna a mensagem para o usuário
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Se houver o CPF, retorna a mensagem para o usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); 
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //remove o arquivo nomeado com o CPF digitado
	
	FILE *file; //Abre o arquivo referente ao CPF com o comando "r" para leitura
	file = fopen(cpf,"r");
	
	if(file == NULL) //Caso o número digitado não seja encontrado
	{
		printf("Usuário não encontrado no sistema!\n\n");
	}
	
	system("pause"); 
}

int main() //Função do menu principal
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Início do menu
		printf("### Cartório da EBAC ###\n \n");
		printf("Escolha a opção desejada do menu:\n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		//Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Responsável por limpar 
		
		//Início da seleção do menu
		switch(opcao)
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponível.\n");
			system("pause");
			break;
		}
		//Fim da seleção do menu		
	}
}
