#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região 
#include <string.h>//biblioteca responsavel por cuidar das string

// as bibliotecas são as primeiras coisas 


int registro()// função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variáveis(string)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis(string)
	
	printf("digite o CPF a ser cadastrado: ");// coletando as informações do usuario
	scanf("%s", cpf);// (%s refere-se as string)
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das string	
	
	FILE *file;//cria o arquivo
	file =fopen(arquivo, "w");//cria o arquivo e o "W" significa escrever 
	fprintf(file,cpf);//salva o valor da variável 
	fclose(file);// fecha o arquivo (muito importante)
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file =fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file =fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// responsavel por pausar a tela
	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");//definindo idioma 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf(" não foi possivel localizar o arquivo!\n");
	
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("/n Essas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");// responsavel por pausar a tela
	
	
	
}

int deletar()
{
	
	char cpf[40];
	
	printf("digite o cpf do usuario que irá ser deletado: ");
	scanf("%s" , cpf);
	
	remove(cpf);
	
	FILE*file;
	file =fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("o usuario não se encontra no sistema!\n");
		
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("usuario deletado!\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0;// definindo a variável
	
	int x=1;
	
	
 		for(x=1;x=1;)
 	{
 		
 		    system("cls");	// responsavel por limpar a tela
 		
			setlocale(LC_ALL,"portuguese");//definindo idioma 
	

			printf("Cartorio escolar \n\n");//titulo (começo do menu)
			printf("Escolha a opção desejada por você:\n\n");
			printf("\t1 - registrar nomes \n\n");
			printf("\t2 - consutar nomes \n\n");
			printf("\t3 - deletar nomes \n\n");// fim do menu
			printf("\t4 - sair do sistema \n\n");
			printf("Opção: ");
	
			scanf("%d", &opcao);// armazenando a escolha do usuario 
			
			system("cls");
			
				switch(opcao) // inicio da seleção de meunu
  				{
		
		   			case 1:
		   		    registro();      //chamada de funções 
		   		    break;
					
				
					case 2:
				    consulta();
					break;
					
					case 3:
				    deletar();
				    break;
				    
				    case 4:
				    printf("obrigado por usar o sistema\n");
				    return 0;
				    break;
				    
					
					default:
					printf("essa opção não está disponivel!\n");
					system("pause");
					break;
					// Fim da seleção de menu
				}
					
	 }   
	
}
