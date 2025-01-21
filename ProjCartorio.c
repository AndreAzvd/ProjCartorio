#include <stdio.h> //comunicação com usuario
#include <stdlib.h> //alocação de espaço em memoria
#include <locale.h> //alocação de texto por região
#include <string.h> // responsavel por cuidar das strings

int registro() // função de cadastrar usuarios no sistema
{
	char arquivo[40]; // variaveis da função registro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado:  "); // coleta de informações do usuario
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //string copy, copia o valor de uma string para outra
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, o "w" significa write
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta() // função de consultar os usuarios ja cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // seleção de idioma 
	
	char cpf[40]; // variaveis de consulta
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:  "); // coleta de informações 
	scanf("%s",cpf);
	
	FILE *file; // abrir arquivo para consultar
	file = fopen(cpf,"r");
	
	if(file == NULL) // laço de repetição para caso o usuario não exista
	{
		printf("Não foi possível localizar este cpf!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() // função de deletar usuarios cadastrados no sistema
{
	char cpf[40]; // strings da função deletar
	
	printf("Digite o CPF do usuário ser deletado:  "); // coleta de informação 
	scanf("%s",cpf);
	
	remove(cpf); // exclusão do usuario
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // para caso o usuario nao exista no sistema
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main() // função principal do sistema
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
		printf("Cartório do André\n\n");
		printf("Login de administrador!\n\nDigite sua senha: ");
		scanf("%s", senhadigitada);
		
		comparacao= strcmp(senhadigitada, "admin");
		
		if(comparacao == 0)
		{
			for(laco=1;laco=1;)
			{	
				system("cls"); // Limpar tela
    			setlocale(LC_ALL, "Portuguese"); // Definindo idioma
    	
    			printf("Cartório do André\n\n"); // Inicio menu
    			printf("Escolha a opção desejada:\n");
    			printf("1- Novo Cadastro\n");
    			printf("2- Consultar Cadastro\n");
    			printf("3- Deletar Cadastro\n");
    			printf("4- Sair do Sistema\n");
    			printf("Opção: "); // fim do menu
    			scanf("%d", &opcao); // Armazenamento de escolha
    
    
    	
    			switch(opcao) // Seleção do menu
				{
					case 1: 
					registro(); // chamada de funções
    				break;
    		
    				case 2: 
					consulta();
					break;
			
					case 3: 
					deletar();
					break;
					
					case 4:
					printf("Obrigado por utilizar nosso sistema!\n");
					return 0;
					break;
		
					default:
					printf("Esta opção não existe\n");
					system("pause");
					break;
				}		
    
			}	
		}
	
}
