#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //responsável por fazer o registro dos usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //comando ao usuário para inserir dados
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" sisgnifica escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar 
	fprintf(file,";"); //inseri uma vírgula após o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,";"); //inseri uma vírgula após o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,";"); //inseri uma vírgula após o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cargo); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	printf("Cadastro realizado com sucesso!\n"); //mensagem ao usuário de êxito
	fclose(file); //fecha o arquivo
	
	system("pause"); //espera de uma resposta do usuário
	
}

int consultar() //responsável por fazer a consulta dos usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usuário
	scanf("%s",cpf); //salvando na string os dados fornecidos
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" lê
	
	if(file == NULL) //se o dado fornecido for igual a NULL "nulo" 
	{
		printf("\nARQUIVO NÃO LOCALIZADO!\n"); //mensagem de fracasso de pesquisa ao usuário  
		system("pause"); // espera de resposta
		return; //retorno a main
	}
	
	while(fgets(conteudo, 200, file) != NULL); //enquanto abre o conteúdo do arquivo, se for diferente de NULL "nulo" 
	{
		printf("Essas são as informações do usuário: \n"); //mensagem de êxito enviada ao usuário
		printf("%s", conteudo); //salvando na string os dados fornecidos
		printf("\n\n");	//saltando linha para organização
	}

	system("pause"); //espera de resposta do usuário

}

int deletar() //responsável por deletar os usuário no sistema
{
		char cpf[40]; //criação de variável/string
		
		printf("Digite o CPF do usuário a ser deletado: \n"); //coletando informações do usuário
		scanf("%s",cpf); //salvando na string os dados fornecidos
		
		FILE *file; //cria arquivo
		file = fopen(cpf, "r"); //abre arquivo para "r" ler
		
		if(file == NULL) //se arquivo for igual NULL "nulo"
		{
			printf("CPF não encontrado! Por favor, tente novamente!\n"); //mensagem de fracasso ao usuário
			system("pause"); //espera de resposta
			return; //retorna a main
		}
		
		remove(cpf); //remove o usuário
		
		printf("CPF deletado com sucesso! \n"); // mensagem de êxito
		system("pause"); //espera de resposta
		
}


int main() //responsável pelo menu principal
{
	int opcao=0;//definindo variaveis
	int x=1;//definindo laco
	char senhadigitada [10] = "a"; //variável criada para inserção de senha
	int comparacao; // variável de comparação a senha de admin
	
		printf("### Registros EBAC ###\n\n"); //início da tela de login
		printf("LOGIN DE ADMINISTRADOR\n Digite sua senha:\n"); //inserir senha para continuar
		scanf("%s",senhadigitada); //coletando senha digitada
		
		comparacao = strcmp(senhadigitada, "admin"); //comparando se a senha digitada é igual a senha salva
		
		if (comparacao == 0) //se a comparação for igual a 0, entra no sistema
		{
			system ("cls");	
			for (x=1;x=1;)
			{
				system("cls"); //limpa a tela
	
				setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
					printf("### Registros EBAC ###\n\n");//inicio do menu
					printf("Selecione a opção desejada:\n\n");
					printf("\t1 - Registrar Nome\n");
					printf("\t2 - Consultar Nome\n");
					printf("\t3 - Deletar Nome\n");
					printf("\t4 - Sair do sistema\n\n");
					printf("Opção: ");//fim do menu
	
			scanf("%d", &opcao);//armazenando a escolha do usuario
	
			system("cls");
	
			switch(opcao)
			{
				case 1://inicio da selecao
					registrar();
					break;
		
				case 2:
					consultar();
					break;
			
				case 3:
					deletar();
					break;
			
				case 4:
					printf("Obrigado por utilizar nosso sistema! Até mais.\n");
					return 0;
					break;
			
				default:
					printf("Esta opção não existe!\n");
					system("pause");//fim da selecao
			}
			}
	}
	
	else 
		printf("SENHA INCORRETA!"); //se não, digite a senha correta para entrar no sistema 
}

