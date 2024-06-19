#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{	
	// Inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //salva dentro de um string, "%s" refere-se a strings
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abrir arquivo salvo, "a" significa atualizar informa��o
	fprintf(file, ","); // salva informa��o dentro do arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo,"a"); 
	fprintf(file, sobrenome); 
	fclose(file);
	
 	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file); 

	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //salva o conteudo da variavel dentro do arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Pausa para aguardar usu�rio
}

int consulta() // Fun��o responsalvel por consultar usu�rios no sistema
{
		
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	char cpf[40]; //armazenar resposta do usuario
	char conteudo[200]; //armazenar o conteudo dentro do arquivo
	
	printf("Digite o CPF a ser consultado: ");  //coletando informa��o do usu�rio
	scanf("%s",cpf); // salvando na variavel/string
	
	FILE *file; // consultar arquivo
	file = fopen(cpf, "r"); //abrir arquivo, "r" significa ler o arquivo
	
	if(file == NULL) //valida��o do arquivo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); // resposta ao usuario no caso de inexist�ncia 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while=enquanto fgets=buscar conteudo max200 enquanto estiver dentro do arquivo file parar quando for nulo  
	{
		printf("\nEssas s�o as informa��es do usuario: "); //Resposta ao usu�rio 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa para aguardar usu�rio
	
	}

int deletar() //fun��o responsavel por excluir usu�rios
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");  //coletando informa��o do usu�rio
	scanf("%s",cpf); 
	
	remove(cpf); // Responsavel por deletar usuario 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Responsavel por identificar se o arquivo n�o existe
	{
		printf("O usu�rio n�o se encontra no sistema!. \n"); //Resposta ao usu�rio 
		system("pause"); //Pausa para aguardar usu�rio
		
	}
	
	
}

int main()
    {
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
	system("cls"); // responsavel por limpar a tela 
	
    	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
        printf ("### Cart�rio da EBAC ###\n\n"); // inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o:"); // fim do menu
	
        scanf("%d", &opcao); // armazenando a escolha do usu�rio

        system("cls");
        
        switch(opcao) //inicio da sele��o do menu
        {
        	
		case 1: // chamada de fun��es
			
        	
	        registro();
	        break;
	        
	    case 2: // chamada de fun��es 
	    	
		   consulta();
           break;
           
        case 3: // chamada de fun��es
        	
        	deletar();
	        break;
	    
	    case 4:
	    	printf("Obrigado por utilizar o sistema! \n\n");
	    	return 0;
	    	break;
	    	
	    default:
	    
	        printf("Essa op��o n�o est� disponivel!\n");
            system("pause");
            break;
           // fim da sele��o
		}
    
        }
}
