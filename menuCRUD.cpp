void controle_estoque(FILE *Arquivo,FILE * Arquivo1){
	struct compra_venda novo;
	struct produto est;
	
	
	
	while(fread(&est,sizeof(struct produto),1,Arquivo1) and fread(&novo,sizeof(struct compra_venda),1,Arquivo) ){
		
		rewind(Arquivo);
		rewind(Arquivo1);		
			 int qnt_est = est.qtd;
	 int qnt_des =novo.qtd;
	qnt_est = qnt_est - qnt_des;
	printf("%d",qnt_est);	
		
	if(qnt_est >= 0){
		rewind(Arquivo1);
	while (fread (&est, sizeof(est), 1, Arquivo1))
	if(novo.codigoprod==est.cdgprod){
		 fseek(Arquivo1,sizeof(struct produto)*-1, SEEK_CUR);
		est.qtd=est.qtd- qnt_des;   
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
