void controle_estoque(FILE *Arquivo,FILE * Arquivo1){
	struct compra_venda novo;
	struct produto est;
	
	
	
	while(fread(&est,sizeof(struct produto),1,Arquivo1) and fread(&novo,sizeof(struct compra_venda),1,Arquivo) ){
		
		

	est.qtd=est.qtd-novo.qtd
		printf("\n%d",est.qtd);
	if(est.qtd >= 0){
		rewind(Arquivo1);
	while (fread (&est, sizeof(est), 1, Arquivo1))
	if(novo.codigoprod==est.cdgprod){
		 fseek(Arquivo1,sizeof(struct produto)*-1, SEEK_CUR);
		est.qtd=est.qtd- novo.qtd  
		fwrite (&est, sizeof(est), 1, Arquivo1);
	fseek(Arquivo1, sizeof(est)* 0, SEEK_END);
	}

	printf("\n\nQuantidade disponivel em estoque!\n");
	
	}
	if(qnt_est<0){
	printf("\n\nQuantidade não disponivel em estoque!\n\nVoltando ao menu");
	fflush(stdin);
	getch();
	return ;
	}else{
		printf("codigo do produto não existe\n");
		getch();
		return ;
		} 
	}
}

