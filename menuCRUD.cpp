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
 char cpf[11];
 };
struct produto{
	int cdgprod;
	char nome[50];
	float preco;
	int qtd;
};
struct compra_venda{
 int codigo_cv; 
 char nomecli[50];
 char nomevendedor[50]; 
 int codproven; 
 int qtd; 
 
 };



int menu(void);
void incluir_cliente();

void Entrada (FILE *cliente);
char ValidaSexo();
char Validaresp();

void incluir_produto();

void Entrada_produto(FILE *Arquivo);
char Validaresp_produto();

void listagem_cliente();
void le_cliente (FILE * Arquivo);
void listagem_produto();
void le_produto (FILE * Arquivo);
void consulta_cliente();
void consulta_produto();
void alterar_cliente();
void alterar_produto();
void excluir_cliente();
void excluir_produto();
void incluir_compra();
void entrada_compra (FILE * Arquivo, FILE * Arquivo1);
void listagem_compra();
void le_compra (FILE * Arquivo);
void consulta_compra(); 
void alterar_compra (); 
void excluir_compra();
 
int main(){
	system("color 1F");
	setlocale(LC_ALL,"Portuguese");
	int opc;
	do {
	system("cls");	
	opc=menu();
	switch(opc){
		case 1:
			incluir_cliente();
		break;
		case 2:
			incluir_produto();
		break;
		case 3:
			incluir_compra();
		break;
		case 4:
			listagem_cliente();
		break;
		case 5:
			listagem_produto();
		break;
		case 6:
			listagem_compra();
		break;
		case 7:
			consulta_cliente();
		break;
		case 8:
			consulta_produto();
		break;
		case 9:
			consulta_compra(); 
		break;
		case 10:	
			alterar_cliente();
		break;
		case 11:
			alterar_produto();
		break;
		case 12:
			alterar_compra (); 
		break;
		case 13:
			excluir_cliente();
		break;
		case 14:
			excluir_produto();
		break;
		case 15:
			excluir_compra();
		break;	
		case 0:break;
	}
	}while(opc!=0);	
}


int menu (void){

int opcao;
do {
printf("\n\n========Bem vindo ao Menu CRUD!========\n\n");
printf("|1. Incluir cliente\n");
printf("|2. Incluir produto\n");
printf("|3. Incluir compra/venda\n");
printf("|4. Listar  cliente \n");
printf("|5. Listar  produto \n");
printf("|6. Listar  compra/venda \n");
printf("|7. Consultar cliente\n");
printf("|8. Consultar produto\n");
printf("|9. Consultar compra/venda\n");
printf("|10. Alterar cliente\n");
printf("|11. Alterar produto\n");
printf("|12. Alterar compra/venda\n");
printf("|13. Excluir cliente\n");
printf("|14. Excluir produto\n");
printf("|15. Excluir compra/venda\n");
printf("|0. Sair\n\n");
printf("\n==Digite uma opção: ");
scanf("%d", &opcao);
fflush(stdin);
if ((opcao < 0) || (opcao > 15))
printf ("\n>>>Opção digitada não existe!<<<\n");
} while ((opcao < 0) || (opcao > 15));
return opcao;
}

void incluir_cliente(){

 FILE * Arquivo;
 	int erro=0;
     char arqcli [] = {"CLIENTE.txt"};
	 Arquivo = fopen(arqcli, "ab+");
  	 if (Arquivo == NULL) {
	 printf("\n>>>Arquivo %s não existe! Caso deseje prosseguir, tecle algo para criar um novo arquivo.<<<", arqcli);
 	getch();
	 if ((Arquivo = fopen(arqcli, "wb+")) == NULL) {
	 erro = 1;
 	printf("\n>>>ERRO! Impossível criar o arquivo %s!<<<", arqcli);
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
 printf("\n==Digite o novo código (0 volta para o menu): ");
 scanf("%d", &novo.codigo);
 if (novo.codigo != 0) {
 printf("\n==Digite o nome do cliente: ");
 fflush(stdin);
 gets(novo.nomecli);
 novo.sexo = ValidaSexo();
 printf("\n==Digite o Telefone: " );
 gets(novo.telefone);
 printf("\n==Digite o CPF: ");
 gets(novo.cpf);
 vresp = Validaresp();
 if (vresp == 'S') {
 retorno = fwrite (&novo, sizeof(struct cliente) ,1,Arquivo);

 if (retorno == 1) {
 printf("\n>>>Cliente cadastrado com sucesso!<<<");
 getch();
 }
 else {
 printf ("\n>>>ERRO: Não foi possível efetuar o cadastro!<<<");
 getch();
 }
 }
 }
 } while (novo.codigo != 0);
}

char ValidaSexo() {
 char sexo;
 do {
 printf("\n==Digite o sexo [M para masculino e F para feminino]: ");
 sexo = getche();
 fflush(stdin);
 } while (sexo != 'F' && sexo != 'M');
 return sexo;
}

char Validaresp() {
	
 char vresp;
 do {
 printf("\n==Você deseja criar este cadastro [S ou N]?" );
 vresp = getche();
 fflush(stdin);
 } while (vresp != 'S' && vresp != 'N');
 return vresp;
}

void incluir_produto(){

	 FILE * Arquivo;
 	int erro=0;
     char arqprod [] = {"PRODUTO.txt"};
	 Arquivo = fopen(arqprod, "ab+");
  	 if (Arquivo == NULL) {
	 printf("\n>>>Arquivo %s não existe! Caso deseje prosseguir, tecle algo para criar um novo arquivo.<<<", arqprod);
 	getch();
	 if ((Arquivo = fopen(arqprod, "wb+")) == NULL) {
	 erro = 1;
 	printf("\n>>>ERRO! Impossível criar o arquivo %s!<<<", arqprod);
	 getch();
 }
 } 
 	if(erro==0){
 		Entrada_produto(Arquivo);
 		fclose (Arquivo);
	 }	
 }
void Entrada_produto(FILE *Arquivo){
	int retorno;
	struct produto novo;
	char resp;
	do{
	
	printf("\n==Digite o novo código (0 volta para o menu): ");
	scanf("%d",&novo.cdgprod);
	if(novo.cdgprod!=0){
	printf("\n==Digite o nome do produto: ");
	gets(novo.nome);
	fflush(stdin);
	printf("\n==Digite o preço: ");
	scanf("%f",&novo.preco);
	fflush(stdin);
	printf("\n==Digite a quantidade em estoque do produto: ");
	scanf("%d",&novo.qtd);
	fflush(stdin);
	resp=Validaresp();
	if(resp=='S'){
	retorno=fwrite(&novo,sizeof(struct produto),1,Arquivo);
	if(retorno=1){
	printf("\n>>>Produto cadastrado com sucesso!<<<");
}
		else printf("\n>>>ERRO: Não foi possível efetuar o cadastro!<<<");
		getch();
}
}
}while(novo.cdgprod!=0);	
}
char Validaresp_produto() {
 char resp;
 do {
 printf("\n==Você deseja criar este cadastro [S ou N]?");
 resp = getche();
 fflush(stdin);
 } while (resp != 'S' && resp != 'N');
 return resp;
}

void listagem_cliente(){
	int erro=0;
	    FILE *Arquivo = fopen("CLIENTE.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
        getch();
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
	if(ler.codigo==0){
 		retorno = fread(&ler, sizeof(struct cliente), 1, Arquivo);
		}
	else{
	
 cont++;
 printf("\n>>>DADOS DO CLIENTE %d<<<", cont);
 printf("\n==Código: %d==", ler.codigo);
 printf("\n==Nome: %s==", ler.nomecli);
 printf("\n==Sexo: %c==", ler.sexo);
 printf("\n==Telefone: %s==", ler.telefone);
 printf("\n==CPF: %s==\n", ler.cpf);
 retorno = fread(&ler, sizeof(struct cliente), 1, Arquivo);
 }
 }
 printf("\n\n>>>%d clientes cadastrados.<<<", cont);
 getch();
} 


void listagem_produto(){
	int erro=0;
    FILE *Arquivo = fopen("PRODUTO.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
        getch();
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
 	if(ler.cdgprod==0){
 		retorno = fread(&ler, sizeof(struct produto), 1, Arquivo);
		}
	else{
 cont++;
 printf("\n>>>DADOS DO PRODUTO %d<<<", cont);
 printf("\n==Codigo: %d==", ler.cdgprod);
 printf("\n==Nome: %s==", ler.nome);
 printf("\n==Preço: %.2f==", ler.preco);
 printf("\n==Quantidade: %d==\n", ler.qtd);
 retorno = fread(&ler, sizeof(struct produto), 1, Arquivo);
 }
}
 printf("\n\n>>>%d produtos cadastrados.<<<", cont);
 getch();
} 
void consulta_cliente(){
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("CLIENTE.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();  
    }
    
    struct cliente ler;
    int cod, encon;
    do {
    rewind (Arquivo);
    printf ("\n==Digite o codigo do cliente para consultá-lo: ");
    encon=0;
    scanf ("%d", &cod);
	fflush(stdin);
    if(cod!=0){
    while (fread (&ler, sizeof(ler), 1, Arquivo)){
    if (cod == ler.codigo) {
        encon = 1;
        printf("==Código do cliente: %d==\n==Nome: %s==\n==Telefone: %s==\nSexo: %c==\n==CPF: %s==\n",ler.codigo, ler.nomecli, ler.telefone, ler.sexo, ler.cpf);
        getch();
        }
    }
    
    if (!encon){
        printf ("\n>>>Código inexistente!<<<");
        getch();
        }
    }
}while(cod!=0); 
fclose(Arquivo);
}
void consulta_produto(){
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("PRODUTO.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
		return;  
    }
    
    struct produto ler;
    int cod, encon;
    do {
    rewind (Arquivo);
    printf ("\n==Digite o código do produto para consultá-lo: ");
    encon=0;
    scanf ("%d", &cod);
	fflush(stdin);
    if(cod!=0){
    while (fread (&ler, sizeof(ler), 1, Arquivo)){
    if (cod == ler.cdgprod) {
        encon = 1;
        printf("\n==Código do produto: %d==\n==Nome: %s==\n==Preço: %s==\n==Quantidade: %d==\n",ler.cdgprod, ler.nome, ler.preco, ler.qtd);
        getch();
        }
    }
    
    if (!encon){
        printf ("\n>>>Código inexistente!<<<");
        getch();
        }
    }
}while(cod!=0); 
fclose(Arquivo);
}

void alterar_cliente () {
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("CLIENTE.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<"); 
		getch();
		return; 
    }

struct cliente alter;
int cod, encon;
do {
rewind (Arquivo);
printf ("\n==Digite o código que deseja alterar: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if(cod!=0){

    while (fread (&alter, sizeof(alter), 1, Arquivo)){
        if (cod == alter.codigo){
    printf("\n==Código do cliente: %d==\n==Nome: %s==\n==Telefone: %s==\n==Sexo: %c==\n==CPF: %s==\n",alter.codigo, alter.nomecli, alter.telefone, alter.sexo, alter.cpf);
    encon = 1;

    fseek(Arquivo,sizeof(struct cliente)*-1, SEEK_CUR);
    printf("\n==Digite o novo nome: ");
    fflush(stdin);
    gets(alter.nomecli);
    fflush(stdin);
    printf("\n==Digite o novo telefone: ");
    gets(alter.telefone);
    fflush(stdin);
 do {
 printf("\n==Digite o sexo [M para masculino e F para feminino]: ");
 alter.sexo = getche();
 } while (alter.sexo != 'F' && alter.sexo != 'M');
    fflush(stdin);
    printf("\n==Digite o CPF: ");
    gets(alter.cpf);
    fflush(stdin);

fwrite (&alter, sizeof(alter), 1, Arquivo);
fseek(Arquivo, sizeof(alter)* 0, SEEK_END);
printf(">>>Alteração feita com sucesso!<<<");
}
}

if (!encon){
printf ("\n>>>Código inexistente!<<<");
}
}
}while(cod!=0);
}

void alterar_produto() {

	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("PRODUTO.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
		return;  
    }

struct produto alter;
int cod, encon;
do {
rewind (Arquivo);
printf ("\n==Digite o código que deseja alterar: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if(cod!=0){

    while (fread (&alter, sizeof(alter), 1, Arquivo)){
        if (cod == alter.cdgprod){
    printf("==Código do produto: %d==\n==Nome: %s==\n==Preço: %s==\n==Quantidade: %d==\n",alter.cdgprod, alter.nome, alter.preco, alter.qtd);
    encon = 1;

    fseek(Arquivo,sizeof(struct produto)*-1, SEEK_CUR);
    printf("\n==Digite o novo nome: ");
    fflush(stdin);
    gets(alter.nome);
    fflush(stdin);
    printf("\n==Digite o novo preço: ");
    scanf("%f",&alter.preco);
    fflush(stdin);
    printf("\n==Digite a quantidade: ");
    scanf("%d", &alter.qtd);
    fflush(stdin);

fwrite (&alter, sizeof(alter), 1, Arquivo);
fseek(Arquivo, sizeof(alter)* 0, SEEK_END);
printf(">>>Alteração feita com sucesso!<<<");
}
}

if (!encon){
printf ("\n>>>Código inexistente!<<<");
}
}
}while(cod!=0);
}
void excluir_cliente() {
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("CLIENTE.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
		return;  
    }
struct cliente excluir;    
int cod, encon;
char conf;
do {
    rewind (Arquivo);
printf ("\n==Digite o codigo que deseja EXCLUIR: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if (cod!=0){

while (fread (&excluir, sizeof(excluir), 1, Arquivo)){
if (cod == excluir.codigo){
printf("==Código do cliente: %d==\n==Nome: %s==\n==Telefone: %s==\nSexo: %c==\n==CPF: %s==\n",excluir.codigo, excluir.nomecli, excluir.telefone, excluir.sexo, excluir.cpf);
encon=1;

printf("\n>>>Tem certeza que deseja excluir este cliente? [S/N]<<< ");
fflush(stdin);
scanf("%c", &conf);
if (conf == 'S'){
memset(&excluir, 0, sizeof (struct cliente)); 

printf("\n>>>Cliente excluído com Sucesso!<<<");
fseek(Arquivo,sizeof(struct cliente)*-1, SEEK_CUR);
fwrite(&excluir, sizeof(excluir), 1, Arquivo);
fseek(Arquivo, sizeof(excluir)* 0, SEEK_END);
}
else if (conf == 'N')
printf("\n>>>Ação cancelada!<<<");
}
}

if (!encon)
printf ("\n>>>Código inexistente!<<<");
}
}while(cod!=0);
}
void excluir_produto() {
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("PRODUTO.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<"); 
		getch(); 
		return;
    }
struct produto excluir;    
int cod, encon;
char conf;
do {
    rewind (Arquivo);
printf ("\n==Digite o codigo que deseja EXCLUIR: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if (cod!=0){

while (fread (&excluir, sizeof(excluir), 1, Arquivo)){
if (cod == excluir.cdgprod){
printf("\n==Código do produto: %d==\n==Nome: %s==\n==Preço: %f==\n==Quantidade: %d==\n",excluir.cdgprod, excluir.nome, excluir.preco, excluir.qtd);
encon=1;

printf("\n>>>Tem certeza que deseja excluir este produto? [S/N]<<< ");
scanf("%c", &conf);
fflush(stdin);
if (conf == 'S'){
memset(&excluir, 0, sizeof (struct produto)); 

printf("\n>>>Produto excluído com Sucesso!<<<");
fseek(Arquivo,sizeof(struct produto)*-1, SEEK_CUR);
fwrite(&excluir, sizeof(excluir), 1, Arquivo);
fseek(Arquivo, sizeof(excluir)* 0, SEEK_END);
}
else if (conf == 'N')
printf("\n>>>Ação cancelada!<<<");
}
}

if (!encon)
printf ("\n>>>Código inexistente!<<<");
}
}while(cod!=0);
}


void incluir_compra(){

 FILE * Arquivo1 = fopen("PRODUTO.txt", "rb");
 FILE * Arquivo;
 	int erro=0;
     char arqcv [] = {"COMPRA.txt"};
	 Arquivo = fopen(arqcv, "ab+");
  	 if (Arquivo == NULL) {
	 printf("\n>>>Arquivo %s não existe! Caso deseje prosseguir, tecle algo para criar um novo arquivo.<<<", arqcv);
 	getch();
	 if ((Arquivo = fopen(arqcv, "wb+")) == NULL) {
	 erro = 1;
 	printf("\n>>>ERRO! Impossível criar o arquivo %s!<<<", arqcv);
	 getch();
	 return;
 }
 } 
 	if(erro==0){
 		entrada_compra(Arquivo, Arquivo1);
 		fclose (Arquivo);
		fclose (Arquivo1);
	 }	
 }
 
void entrada_compra (FILE * Arquivo, FILE * Arquivo1) {
 int retorno;
 struct compra_venda novo;
 struct produto est;
 char vresp;
 do {
 printf("\n==Digite o código da compra (0 volta para o menu): ");
 scanf("%d", &novo.codigo_cv);
 fflush(stdin);
 if (novo.codigo_cv != 0) {
 printf("\n==Digite o nome do cliente: ");
 gets(novo.nomecli);
 fflush(stdin);
 printf("\n==Digite o nome do vendedor: " );
 gets(novo.nomevendedor);
 fflush(stdin);
 printf("\n==Digite o código do produto vendido: ");
 scanf("%d", &novo.codproven);
 fflush(stdin);
 while (fread (&est, sizeof(est), 1, Arquivo1)){
	rewind(Arquivo1);
   if(novo.codproven==est.cdgprod){
		 printf("\n==Digite a quantidade vendida: ");
 		scanf("%d", &novo.qtd);
 		fflush(stdin);
 		if(novo.qtd>est.qtd){
			printf("\n>>>Impossível vender mais que o estoque ou estoque indispovínel!<<<");
			getch();
			return;

	}
if(est.qtd==0){
	printf("\n>>>Impossível vender mais que o estoque ou estoque indispovínel!<<<");
	getch();
	return;
 }
 
 vresp = Validaresp();
 if (vresp == 'S') {
 retorno = fwrite (&novo, sizeof(struct compra_venda) ,1,Arquivo);

 if (retorno == 1) {
 printf("\n>>>Compra cadastrada com sucesso!<<<");
 getch();
 }
 else {
 printf ("\n>>>ERRO: Não foi possível efetuar o cadastro!<<<");
 getch();
 }
 }
 }
 else { 
 printf("\n>>>Produto inexistente!<<<");
 getch();
 return;
 }
 } 
}
}while (novo.codigo_cv != 0);
}
void listagem_compra(){
	int erro=0;
	    FILE *Arquivo = fopen("COMPRA.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		erro=1;
		getch();
		return;  
    }
 	if(erro==0){
 	 le_compra(Arquivo);
	 }	
 }

 void le_compra (FILE * Arquivo) {
 int retorno, cont = 0;
 struct compra_venda ler;
 retorno = fread(&ler, sizeof(struct compra_venda), 1, Arquivo);

 while ( retorno == 1) {
 	if(ler.codigo_cv==0){
 		retorno = fread(&ler, sizeof(struct compra_venda), 1, Arquivo);
		}
	else{
 cont++;
 printf("\n>>>DADOS De COMPRA %d<<<", cont);
 printf("\n==Código: %d==", ler.codigo_cv);
 printf("\n==Nome Cliente: %s==", ler.nomecli);
 printf("\n==Nome Vendedor: %s==", ler.nomevendedor);
 printf("\n==Código Produto: %d==", ler.codproven);
 printf("\n==Quantidade : %d==\n", ler.qtd);
 retorno = fread(&ler, sizeof(struct compra_venda), 1, Arquivo);
 }
}
 printf("\n\n>>>%d compras cadastradas.<<<", cont);
 getch();
} 
void consulta_compra(){
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("COMPRA.txt", "rb");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
	
		return;  
    }
    
    struct compra_venda ler;
    int cod, encon;
    do {
    rewind (Arquivo);
    printf ("\n==Digite o código de compra para consultá-lo: ");
    encon=0;
    scanf ("%d", &cod);
	fflush(stdin);
    if(cod!=0){
    while (fread (&ler, sizeof(ler), 1, Arquivo)){
    if (cod == ler.codigo_cv) {
        encon = 1;
        printf("==Código de compra: %d==\n==Nome Cliente: %s==\n==Nome Vendedor: %s==\nCódigo Produto: %d==\n==Quantidade: %d==\n",ler.codigo_cv, ler.nomecli, ler.nomevendedor, ler.codproven , ler.qtd);
        getch();
        }
    }
    
    if (!encon){
        printf ("\n>>>Código inexistente!<<<");
        getch();
        }
    }
}while(cod!=0); 
fclose(Arquivo);
}

void alterar_compra () {
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("COMPRA.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
		return;  
    }

struct compra_venda alter;
int cod, encon;
do {
rewind (Arquivo);
printf ("\n==Digite o código que deseja alterar: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if(cod!=0){

    while (fread (&alter, sizeof(alter), 1, Arquivo)){
        if (cod == alter.codigo_cv){
      printf("==Código de compra: %d==\n==Nome Cliente: %s==\n==Nome Vendedor: %s==\nCódigo do Produto: %d==\n==Quantidade: %d==\n",alter.codigo_cv, alter.nomecli, alter.nomevendedor, alter.codproven , alter.qtd);
    encon = 1;

    fseek(Arquivo,sizeof(struct compra_venda)*-1, SEEK_CUR);
    printf("\n==Digite o novo nome do cliente: ");
    gets(alter.nomecli);
    fflush(stdin);
    printf("\n==Digite o novo nome do vendedor: ");
    gets(alter.nomevendedor);
    fflush(stdin);
	printf("\n==Digite o novo produtovendido");
	scanf("%d", alter.codproven);
    fflush(stdin);
    printf("\n==Digite a Quantidade: ");
    scanf("%d",&alter.qtd);
    fflush(stdin);

fwrite (&alter, sizeof(alter), 1, Arquivo);
fseek(Arquivo, sizeof(alter)* 0, SEEK_END);
printf(">>>Alteração feita com sucesso!<<<");
}
}
if (!encon){
printf ("\n>>>Código inexistente!<<<");
}
}
}while(cod!=0);
}
void excluir_compra() {
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("COMPRA.txt", "rb+");
    if (Arquivo == NULL){
        printf(">>>O arquivo para leitura não foi encontrado!<<<");
		getch();
		fflush(stdin);
		return;  
    }
struct compra_venda excluir;    
int cod, encon;
char conf;
do {
    rewind (Arquivo);
printf ("\n==Digite o codigo que deseja EXCLUIR: ");
encon=0;
scanf ("%d", &cod);
fflush(stdin);
if (cod!=0){

while (fread (&excluir, sizeof(excluir), 1, Arquivo)){
if (cod == excluir.codigo_cv){
 printf("==Código de compra: %d==\n==Nome Cliente: %s==\n==Nome Vendedor: %s==\nCódigo do Produto: %d==\n==Quantidade: %d==\n",excluir.codigo_cv, excluir.nomecli, excluir.nomevendedor, excluir.codproven , excluir.qtd);
encon=1;

printf("\n>>>Tem certeza que deseja excluir esta compra? [S/N]<<< ");
scanf("%c", &conf);
fflush(stdin);
if (conf == 'S'){
memset(&excluir, 0, sizeof (struct compra_venda)); 

printf("\n>>>Compra excluída com Sucesso!<<<");
fseek(Arquivo,sizeof(struct compra_venda)*-1, SEEK_CUR);
fwrite(&excluir, sizeof(excluir), 1, Arquivo);
fseek(Arquivo, sizeof(excluir)* 0, SEEK_END);
}
else if (conf == 'N')
printf("\n>>>Ação cancelada!<<<");
}
}
if (!encon)
printf ("\n>>>Código inexistente!<<<");
}
}while(cod!=0);
}
