#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //respons�vel por fazer o registro dos usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //comando ao usu�rio para inserir dados
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" sisgnifica escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar 
	fprintf(file,";"); //inseri uma v�rgula ap�s o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,";"); //inseri uma v�rgula ap�s o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,";"); //inseri uma v�rgula ap�s o dado fornecido
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cargo); //salvando na string os dados fornecidos
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar
	printf("Cadastro realizado com sucesso!\n"); //mensagem ao usu�rio de �xito
	fclose(file); //fecha o arquivo
	
	system("pause"); //espera de uma resposta do usu�rio
	
}

int consultar() //respons�vel por fazer a consulta dos usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usu�rio
	scanf("%s",cpf); //salvando na string os dados fornecidos
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" l�
	
	if(file == NULL) //se o dado fornecido for igual a NULL "nulo" 
	{
		printf("\nARQUIVO N�O LOCALIZADO!\n"); //mensagem de fracasso de pesquisa ao usu�rio  
		system("pause"); // espera de resposta
		return; //retorno a main
	}
	
	while(fgets(conteudo, 200, file) != NULL); //enquanto abre o conte�do do arquivo, se for diferente de NULL "nulo" 
	{
		printf("Essas s�o as informa��es do usu�rio: \n"); //mensagem de �xito enviada ao usu�rio
		printf("%s", conteudo); //salvando na string os dados fornecidos
		printf("\n\n");	//saltando linha para organiza��o
	}

	system("pause"); //espera de resposta do usu�rio

}

int deletar() //respons�vel por deletar os usu�rio no sistema
{
		char cpf[40]; //cria��o de vari�vel/string
		
		printf("Digite o CPF do usu�rio a ser deletado: \n"); //coletando informa��es do usu�rio
		scanf("%s",cpf); //salvando na string os dados fornecidos
		
		FILE *file; //cria arquivo
		file = fopen(cpf, "r"); //abre arquivo para "r" ler
		
		if(file == NULL) //se arquivo for igual NULL "nulo"
		{
			printf("CPF n�o encontrado! Por favor, tente novamente!\n"); //mensagem de fracasso ao usu�rio
			system("pause"); //espera de resposta
			return; //retorna a main
		}
		
		remove(cpf); //remove o usu�rio
		
		printf("CPF deletado com sucesso! \n"); // mensagem de �xito
		system("pause"); //espera de resposta
		
}


int main() //respons�vel pelo menu principal
{
	int opcao=0;//definindo variaveis
	int x=1;//definindo laco
	char senhadigitada [10] = "a"; //vari�vel criada para inser��o de senha
	int comparacao; // vari�vel de compara��o a senha de admin
	
		printf("### Registros EBAC ###\n\n"); //in�cio da tela de login
		printf("LOGIN DE ADMINISTRADOR\n Digite sua senha:\n"); //inserir senha para continuar
		scanf("%s",senhadigitada); //coletando senha digitada
		
		comparacao = strcmp(senhadigitada, "admin"); //comparando se a senha digitada � igual a senha salva
		
		if (comparacao == 0) //se a compara��o for igual a 0, entra no sistema
		{
			system ("cls");	
			for (x=1;x=1;)
			{
				system("cls"); //limpa a tela
	
				setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
					printf("### Registros EBAC ###\n\n");//inicio do menu
					printf("Selecione a op��o desejada:\n\n");
					printf("\t1 - Registrar Nome\n");
					printf("\t2 - Consultar Nome\n");
					printf("\t3 - Deletar Nome\n");
					printf("\t4 - Sair do sistema\n\n");
					printf("Op��o: ");//fim do menu
	
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
					printf("Obrigado por utilizar nosso sistema! At� mais.\n");
					return 0;
					break;
			
				default:
					printf("Esta op��o n�o existe!\n");
					system("pause");//fim da selecao
			}
			}
	}
	
	else 
		printf("SENHA INCORRETA!"); //se n�o, digite a senha correta para entrar no sistema 
}

