#include <stdio.h> //biblioteca de comunica��o com o usua�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biclioteca respons�vel por cuidar do string

int registro() //Fun��o responsavel por cadastros os usuarios no sistema
{
	//inicio cria��o variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crian��o
	printf("Digite o seu CPF para cadastro: "); //coletando informa��es do usuario
    scanf("%39s", cpf); //%s refere-se a strings
    
    strcpy(arquivo, cpf); //responsavel por criar os valores string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo
    if (file == NULL) { //Anula o arquivo
    perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s,", cpf); //cria o arquivo
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome para cadastro: "); //coletando informa��es do usuario
    scanf("%39s", nome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s,", nome); //cria o arquivo
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome para cadastro: "); //coletando informa��es do usuario
    scanf("%39s", sobrenome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s,", sobrenome); //cria o arquivo
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo para cadastro: "); //coletando informa��es do usuario
    scanf("%39s", cargo);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s", cargo); //coletando informa��es do usuario
    fclose(file); //fecha o arquivo
    
    printf("Cadastro conclu�do com sucesso!\n"); //coletando informa��es do usuario
    
    system("pause");
    return 0;
}
	

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite para o cpf para cadastro: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir este arquivo./n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o informa��es do usu�rio: ");
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
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL )
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
    {
	int opcao=0; //Definindo vari�veis
	int x=1; 
	 
	for(x=1;x=1;)
	 {
	 	
	 system("cls");

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem
     
	printf("### Conjuntos da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a op��o que desejar:\n\n");
	printf("\t1 - Registrar os nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar os nomes\n"); //Fim do menu
	printf("\t4 - Sair do sistema\n\n");
    printf("Op��o: ");
    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
    system("cls"); //responsavel por limpar a tela
    
    
    switch(opcao) //inicio da sele��o do menu
    {
    	case 1:
        registro(); //chamada de fun��es
		break;
		
		case 2:
		consulta();
    	break;
    	
    	case 3:
    	deletar();
		break;
		
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
		default:
		printf("Essa op��o n�o esta disponivel.");
		system("pause");
		break;
		//fim da sele��o
	}
    
    
   
}
}
    	
	
													

