#include <stdio.h> //biblioteca de comunicação com o usuaário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biclioteca responsável por cuidar do string

int registro() //Função responsavel por cadastros os usuarios no sistema
{
	//inicio criação variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crianção
	printf("Digite o seu CPF para cadastro: "); //coletando informações do usuario
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
    
    printf("Digite o nome para cadastro: "); //coletando informações do usuario
    scanf("%39s", nome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s,", nome); //cria o arquivo
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome para cadastro: "); //coletando informações do usuario
    scanf("%39s", sobrenome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s,", sobrenome); //cria o arquivo
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo para cadastro: "); //coletando informações do usuario
    scanf("%39s", cargo);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); //mapeia o erro numerico contido na variavel
        return 1;
    }
    fprintf(file, "%s", cargo); //coletando informações do usuario
    fclose(file); //fecha o arquivo
    
    printf("Cadastro concluído com sucesso!\n"); //coletando informações do usuario
    
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
		printf("Não foi possivel abrir este arquivo./n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
    {
	int opcao=0; //Definindo variáveis
	int x=1; 
	 
	for(x=1;x=1;)
	 {
	 	
	 system("cls");

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem
     
	printf("### Conjuntos da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a opção que desejar:\n\n");
	printf("\t1 - Registrar os nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar os nomes\n"); //Fim do menu
	printf("\t4 - Sair do sistema\n\n");
    printf("Opção: ");
    scanf("%d", &opcao); //Armazenando a escolha do usuário
    
    system("cls"); //responsavel por limpar a tela
    
    
    switch(opcao) //inicio da seleção do menu
    {
    	case 1:
        registro(); //chamada de funções
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
		printf("Essa opção não esta disponivel.");
		system("pause");
		break;
		//fim da seleção
	}
    
    
   
}
}
    	
	
													

