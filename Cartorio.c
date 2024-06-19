#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{	
	// Inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //salva dentro de um string, "%s" refere-se a strings
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abrir arquivo salvo, "a" significa atualizar informação
	fprintf(file, ","); // salva informação dentro do arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
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

	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //salva o conteudo da variavel dentro do arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Pausa para aguardar usuário
}

int consulta() // Função responsalvel por consultar usuários no sistema
{
		
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	char cpf[40]; //armazenar resposta do usuario
	char conteudo[200]; //armazenar o conteudo dentro do arquivo
	
	printf("Digite o CPF a ser consultado: ");  //coletando informação do usuário
	scanf("%s",cpf); // salvando na variavel/string
	
	FILE *file; // consultar arquivo
	file = fopen(cpf, "r"); //abrir arquivo, "r" significa ler o arquivo
	
	if(file == NULL) //validação do arquivo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n"); // resposta ao usuario no caso de inexistência 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while=enquanto fgets=buscar conteudo max200 enquanto estiver dentro do arquivo file parar quando for nulo  
	{
		printf("\nEssas são as informações do usuario: "); //Resposta ao usuário 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa para aguardar usuário
	
	}

int deletar() //função responsavel por excluir usuários
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");  //coletando informação do usuário
	scanf("%s",cpf); 
	
	remove(cpf); // Responsavel por deletar usuario 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Responsavel por identificar se o arquivo não existe
	{
		printf("O usuário não se encontra no sistema!. \n"); //Resposta ao usuário 
		system("pause"); //Pausa para aguardar usuário
		
	}
	
	
}

int main()
    {
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
	system("cls"); // responsavel por limpar a tela 
	
    	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
        printf ("### Cartório da EBAC ###\n\n"); // inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção:"); // fim do menu
	
        scanf("%d", &opcao); // armazenando a escolha do usuário

        system("cls");
        
        switch(opcao) //inicio da seleção do menu
        {
        	
		case 1: // chamada de funções
			
        	
	        registro();
	        break;
	        
	    case 2: // chamada de funções 
	    	
		   consulta();
           break;
           
        case 3: // chamada de funções
        	
        	deletar();
	        break;
	    
	    case 4:
	    	printf("Obrigado por utilizar o sistema! \n\n");
	    	return 0;
	    	break;
	    	
	    default:
	    
	        printf("Essa opção não está disponivel!\n");
            system("pause");
            break;
           // fim da seleção
		}
    
        }
}
