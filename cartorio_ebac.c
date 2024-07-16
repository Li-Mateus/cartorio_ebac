#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

// Definição de funções:
int registro() {	// Criar e registrar um cadastro.
	//Declaração de variáveis:
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		
	printf("-=-=-=-=-=- Registro de nomes -=-=-=-=-=-\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Input do usuário.
	strcpy(arquivo, cpf); // Copia valores das strings para 'arquivo'.
	
	//Criação de um novo arquivo:	
	FILE * file; // Chama a função de gerenciamento de arquivos e referencia 'arquivo'.
	file = fopen(arquivo, "w"); // Cria arquivo.
	fprintf(file, "CPF: ");
	fprintf(file, cpf); // Salva valor da variável.
	fclose(file); // Fecha o arquivo.
	
	// Adicionando dados ao arquivo:
	file = fopen(arquivo, "a"); // Abre arquivo para atualização.
	fprintf(file, ", "); // Escreve uma vírgula no arquivo.
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
	printf("\nCadastro concluído!\n\n");
	
	system("pause");
}

int consulta() {	// Consulta um cadastro e mostra suas informações
	// Declaração de variáveis:
	char cpf[40];
	char conteudo[200];
	
	// Definição da linguagem:
	setlocale(LC_ALL, "Portuguese");
	
	printf("-=-=-=-=-=- Consulta de cadastros -=-=-=-=-=-\n\n");	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // Input do usuário.
	
	// Fazendo a leitura do arquivo:
	FILE * file;
	file = fopen(cpf, "r");
	
	// Verificando se o cadastro informado existe:
	if(file == NULL) {
		printf("Não foi possível encontrar o cadastro informado :(\n\n");
		system("pause");
	}
	
	// Exibe todas as informações contidas no arquivo:
	while(fgets(conteudo, 200, file) != NULL) {
		printf("\nEstas são as informações do cadastro solicitado: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
		
		fclose(file); // Fecha a leitura do arquivo.
		
		system("pause");
	}
}

int deletar() {  // Deleta arquivos no banco de dados:
	// Declaração de variáveis:
	char cpf[40];
	
	printf("-=-=-=-=-=- Deletar cadastro -=-=-=-=-=-\n\n");
	printf("Digite o cadastro (CPF) a ser deletado: ");
	scanf("%s", cpf); // Input do usuário.
	
	// Leitura do arquivo informado:
	FILE * file;
	file = fopen(cpf, "r");
	fclose(file);
	
	// Verificando se o cadastro informado existe:
	if(file == NULL) {
		printf("\nERRO - Cadastro não encontrado!\n\n");
		system("pause");
	}
	else { // Caso o cadastro exista, o arquivo é deletado.
		remove(cpf);
		printf("\nCadastro deletado com sucesso!\n\n");
		system("pause");
	}
}

int main() { // Função principal -=-=- Menu e opções:
	// Definição de variáveis:
	int opcao = 0;
	int laco = 1;
	// Definição de linguagem:	
		setlocale(LC_ALL, "Portuguese");	
	// Início do laço -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=:	
	for (laco = 1; laco = 1;) {
		
		system("cls"); // limpa o terminal.
	// Menu:
		printf("-=-=-=-=-=- Cartório - EBAC -=-=-=-=-=-\n\n");

		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu.
	// Input do usuário:
		scanf("%d", &opcao);
		system("cls");
	// Início da seleção:	
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
				printf("Opção inválida :(\n\n");
				system("pause");
				break;
		} //Fim da seleção.
	}//Fim do laço.
}

// Créditos/ licenças:
	//Software desenvolvido por Mateus Lima para fins educacionais.

