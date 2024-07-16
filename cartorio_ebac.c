#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

// Defini��o de fun��es:
int registro() {	// Criar e registrar um cadastro.
	//Declara��o de vari�veis:
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		
	printf("-=-=-=-=-=- Registro de nomes -=-=-=-=-=-\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Input do usu�rio.
	strcpy(arquivo, cpf); // Copia valores das strings para 'arquivo'.
	
	//Cria��o de um novo arquivo:	
	FILE * file; // Chama a fun��o de gerenciamento de arquivos e referencia 'arquivo'.
	file = fopen(arquivo, "w"); // Cria arquivo.
	fprintf(file, "CPF: ");
	fprintf(file, cpf); // Salva valor da vari�vel.
	fclose(file); // Fecha o arquivo.
	
	// Adicionando dados ao arquivo:
	file = fopen(arquivo, "a"); // Abre arquivo para atualiza��o.
	fprintf(file, ", "); // Escreve uma v�rgula no arquivo.
	fclose(file);
	
	// Salvar nome:
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	// Salvar sobrenome:
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	// Salvar cargo:
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	// Mensagem final:
	printf("\nCadastro conclu�do!\n\n");
	
	system("pause");
}

int consulta() {	// Consulta um cadastro e mostra suas informa��es
	// Declara��o de vari�veis:
	char cpf[40];
	char conteudo[200];
	
	// Defini��o da linguagem:
	setlocale(LC_ALL, "Portuguese");
	
	printf("-=-=-=-=-=- Consulta de cadastros -=-=-=-=-=-\n\n");	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // Input do usu�rio.
	
	// Fazendo a leitura do arquivo:
	FILE * file;
	file = fopen(cpf, "r");
	
	// Verificando se o cadastro informado existe:
	if(file == NULL) {
		printf("N�o foi poss�vel encontrar o cadastro informado :(\n\n");
		system("pause");
	}
	
	// Exibe todas as informa��es contidas no arquivo:
	while(fgets(conteudo, 200, file) != NULL) {
		printf("\nEstas s�o as informa��es do cadastro solicitado: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
		
		fclose(file); // Fecha a leitura do arquivo.
		
		system("pause");
	}
}

int deletar() {  // Deleta arquivos no banco de dados:
	// Declara��o de vari�veis:
	char cpf[40];
	
	printf("-=-=-=-=-=- Deletar cadastro -=-=-=-=-=-\n\n");
	printf("Digite o cadastro (CPF) a ser deletado: ");
	scanf("%s", cpf); // Input do usu�rio.
	
	// Leitura do arquivo informado:
	FILE * file;
	file = fopen(cpf, "r");
	fclose(file);
	
	// Verificando se o cadastro informado existe:
	if(file == NULL) {
		printf("\nERRO - Cadastro n�o encontrado!\n\n");
		system("pause");
	}
	else { // Caso o cadastro exista, o arquivo � deletado.
		remove(cpf);
		printf("\nCadastro deletado com sucesso!\n\n");
		system("pause");
	}
}

int main() { // Fun��o principal -=-=- Menu e op��es:
	// Defini��o de vari�veis:
	int opcao = 0;
	int laco = 1;
	// Defini��o de linguagem:	
		setlocale(LC_ALL, "Portuguese");	
	// In�cio do la�o -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=:	
	for (laco = 1; laco = 1;) {
		
		system("cls"); // limpa o terminal.
	// Menu:
		printf("-=-=-=-=-=- Cart�rio - EBAC -=-=-=-=-=-\n\n");

		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu.
	// Input do usu�rio:
		scanf("%d", &opcao);
		system("cls");
	// In�cio da sele��o:	
		switch(opcao) {
			case 1:
				registro();
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
				
			default:
				printf("Op��o inv�lida :(\n\n");
				system("pause");
				break;
		} //Fim da sele��o.
	}//Fim do la�o.
}

// Cr�ditos/ licen�as:
	//Software desenvolvido por Mateus Lima para fins educacionais.

