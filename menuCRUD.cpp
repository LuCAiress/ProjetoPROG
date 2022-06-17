#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include<string.h>
#include <conio.h>

struct cliente {
 int codigo; 
 char nomecli[50]; 
 char telefone [15]; 
 char sexo; 
 char cpf[11];};
struct produto{
	int cdgprod;
	char nome[50];
	float preco;
	int qtd;
};


int menu(void);
char incluir_cliente();

void Entrada (FILE *cliente);
char ValidaSexo();
char Validaresp();

char incluir_produto();

void Entrada_produto(FILE *Arquivo);
char Validaresp_produto();

char listagem_cliente();
void le_cliente (FILE * Arquivo);
char listagem_produto();
 void le_produto (FILE * Arquivo);
int main(){
	setlocale(LC_ALL,"Portuguese");
	int opc=menu();
	switch(opc){
		case 1:
			incluir_cliente();
		break;
		case 2:
			incluir_produto();
		break;
		case 3:break;
		case 4:
		listagem_cliente();
		break;
		case 5:
		listagem_produto();
		break;
		case 6:break;
		case 7:break;
		case 8:break;
		case 9:break;
		case 10:break;
		case 11:break;
		case 12:break;
		case 13:break;
		case 14:break;
		case 15:break;	
		case 0:break;
	}
}

int menu (void){

int opcao;
do {
printf("\n\n      MENU PARA CADASTRO DE CLIENTE;PRODUTOS:COMPRAS E VENDAS       \n\n");
printf("1. Incluir cliente\n");
printf("2. Incluir produto\n");
printf("3. Incluir compra/venda\n");
printf("4. Listar  cliente \n");
printf("5. Listar  produto \n");
printf("6. Listar  compra/venda \n");
printf("7. Consultar cliente\n");
printf("8. Consultar produto\n");
printf("9. Consultar compra/venda\n");
printf("10. Alterar cliente\n");
printf("11. Alterar produto\n");
printf("12. Alterar compra/venda\n");
printf("13. Excluir cliente\n");
printf("14. Excluir produto\n");
printf("15. Excluir compra/venda\n");
printf("0. Sair\n\n");
printf("Digite sua opção: ");
scanf("%d", &opcao);
if ((opcao < 0) || (opcao > 15))
printf ("Opção Digitada Não Existe!\n");
} while ((opcao < 0) || (opcao > 15));
return opcao;
}

char incluir_cliente(){

 FILE * Arquivo;
 	int erro=0;
     char arqcli [] = {"CLIENTE.txt"};
	 Arquivo = fopen(arqcli, "ab+");
  	 if (Arquivo == NULL) {
	 printf(" \n Arquivo %s Nao existe : Tecle algo para criar agora ! ", arqcli);
 	getch();
	 if ((Arquivo = fopen(arqcli, "wb+")) == NULL) {
	 erro = 1;
 	printf(" \n Erro grave ! Nao consigo criar o arquivo %s !!!", arqcli);
	 getch();
 }
 } 
 	if(erro==0){
 		Entrada(Arquivo);
 		fclose (Arquivo);
	 }	
 }

void Entrada (FILE * Arquivo) {
 int retorno;
 struct cliente novo;
 char vresp;
 do {
 printf("\n Digite o Codigo [Zero encerra] : " );
 scanf("%d", &novo.codigo);
 if (novo.codigo != 0) {
 printf(" \n Digite o nome : ");
 fflush(stdin);
 gets(novo.nomecli);
 novo.sexo = ValidaSexo();
 printf(" \n Digite o Telefone : " );
 gets(novo.telefone);
 printf(" \n Digite o cpf : ");
 gets(novo.cpf);
 vresp = Validaresp();
 if (vresp == 'S') {
 retorno = fwrite (&novo, sizeof(struct cliente) ,1,Arquivo);

 if (retorno == 1) {
 printf(" \n Gravacao ok ! ");
 getch();
 }
 else {
 printf (" \n Problemas : Gravacao nao efetuada !!!" );
 getch();
 }
 }
 }
 } while (novo.codigo != 0);
}

char ValidaSexo() {
 char sexo;
 do {
 printf(" \n Digite o Sexo [M ou F] : " );
 sexo = getche();
 } while (sexo != 'F' && sexo != 'M');
 return sexo;
}

char Validaresp() {
	
 char vresp;
 do {
 printf(" \n Confirma Inclusao [S ou N] ? " );
 vresp = getche();
 } while (vresp != 'S' && vresp != 'N');
 return vresp;
}

char incluir_produto(){

	 FILE * Arquivo;
 	int erro=0;
     char arqprod [] = {"PRODUTO.txt"};
	 Arquivo = fopen(arqprod, "ab+");
  	 if (Arquivo == NULL) {
	 printf(" \n Arquivo %s Nao existe : Tecle algo para criar agora ! ", arqprod);
 	getch();
	 if ((Arquivo = fopen(arqprod, "wb+")) == NULL) {
	 erro = 1;
 	printf(" \n Erro grave ! Nao consigo criar o arquivo %s !!!", arqprod);
	 getch();
 }
 } 
 	if(erro==0){
 		Entrada(Arquivo);
 		fclose (Arquivo);
	 }	
 }
void Entrada_produto(FILE *Arquivo){
	int retorno;
	struct produto novo;
	char resp;
	do{
	
	printf("adicione o código do produto;ZERO FINALIZA");
	scanf("%d",&novo.cdgprod);
	if(novo.cdgprod!=0){
	printf("adicione o nome do produto\n");
	fflush(stdin);
	gets(novo.nome);
	printf("adicione o preço do produto\n");
	scanf("%f",&novo.preco);
	printf("adicione a quantidade do produto\n");
	scanf("%d",&novo.qtd);
	resp=Validaresp();
	if(resp=='S'){
	retorno=fwrite(&novo,sizeof(struct produto),1,Arquivo);
	if(retorno=1){
	printf("gravação efetuada com sucesso\n");
}
		else printf("houve um problema na gravação\n");
		getch();
}
}
}while(novo.cdgprod!=0);	
}
char Validaresp_produto() {
 char resp;
 do {
 printf(" \n Confirma Inclusao [S ou N] ? \n" );
 resp = getche();
 } while (resp != 'S' && resp != 'N');
 return resp;
}

char listagem_cliente(){
	int erro=0;
	    FILE *Arquivo = fopen("CLIENTE.txt", "rb");
    if (Arquivo == NULL){
        printf("Arquivo inexistente!");
		erro=1;  
    }
 	if(erro==0){
 	 le_cliente(Arquivo);
	 }	
 }
 void le_cliente (FILE * Arquivo) {
 int retorno, cont = 0;
 struct cliente ler;
 retorno = fread(&ler, sizeof(struct cliente), 1, Arquivo);

 while ( retorno == 1) {
 cont++;
 printf("\n\n DADOS DO CLIENTE %d \n", cont);
 printf("\n Codigo : %d", ler.codigo);
 printf("\n Nome   : %s", ler.nomecli);
 printf("\n Sexo   : %c", ler.sexo);
 printf("\n Telefone   : %s", ler.telefone);
 printf("\n CPF : %s", ler.cpf);
 retorno = fread(&ler, sizeof(struct cliente), 1, Arquivo);
 }
 printf(" \n\n %d clientes cadastrados ", cont);
 getch();
} 

char listagem_produto(){
	int erro=0;
    FILE *Arquivo = fopen("PRODUTO.txt", "rb");
    if (Arquivo == NULL){
        printf("Arquivo inexistente!");
		erro=1;  
    }
 	if(erro==0){
 	 le_produto(Arquivo);
	 }	
 }
 void le_produto (FILE * Arquivo) {
 int retorno, cont = 0;
 struct produto ler;
 retorno = fread(&ler, sizeof(struct produto), 1, Arquivo);

 while ( retorno == 1) {
 cont++;
 printf("\n\n DADOS DO PRODUTO %d \n", cont);
 printf("\n Codigo : %d", ler.cdgprod);
 printf("\n Nome   : %s", ler.nome);
 printf("\n Sexo   : %.2f", ler.preco);
 printf("\n Telefone   : %d", ler.qtd);
 retorno = fread(&ler, sizeof(struct produto), 1, Arquivo);
 }
 printf(" \n\n %d produtos cadastrados ", cont);
 getch();
} 














































