#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 100

//Estrutura de usuario
typedef struct usuario {
	char nome[10][80];
	int telefone;
	
}tipo_usuario;

//Estrutura da Lista
typedef struct lista {
	int size;
	tipo_usuario usuarios[MAX];	
}tipo_lista;


//Assinatura de funçoes
tipo_lista* cria_lista();
int insere_usuario_final(tipo_lista* li);
int exibir_lista_cadastrados(tipo_lista* li);
int ordenar_lista(tipo_lista* li);

//Função que cria lista 
tipo_lista* cria_lista() {
	
	tipo_lista* li;
	li = (tipo_lista*) malloc(sizeof(tipo_lista));
	
	if(li == NULL)
		return 0;
		
	li->size = 0;
	
	return li;
}



//Função que insere no final da lista
int insere_usuario_final(tipo_lista* li) {
	
		if(li == NULL){
			printf("\nErro na alocacao da Lista.");
			getch();
			return 0;
		}
	
		if(li->size == MAX-1){
			system("cls");
			printf("\nLista Cheia.");
			getch();
			return 0;
		}
		
		
		int i = li->size;
		
		system("cls");
		printf("\n-------------");
		printf("\n [ Cadastrar ]");
		printf("\n-------------");
		printf("\nNome: ");
		gets(li->usuarios[i].nome);
		printf("\ntelefone sem o (DDD): ");
		scanf("%d",&li->usuarios[i].telefone);
		fflush(stdin);
		
		li->size++;
		return 1;
}


//função responsavel por pesquisar usuario na lista pelo nome
int pesquisar_usuario_nome(tipo_lista* list) {
	
		if(list->size == 0) {
			system("cls");
			printf("\n Lista Vazia!");
			getch();
			return 0;
		}
			
		char nome_p[30];
		
		int k = list->size;
		int j=0;
		
		system("cls");
		printf("\n-------------");
		printf("\n [ Pesquisar ]");
		printf("\n-------------");
		printf("\nNome: ");
		gets(nome_p);
		
		for( ;j < k;j++) {
			
			if(strcmp(list->usuarios[j].nome,nome_p)  == 0 ){
					system("cls");
					printf("\n-------------");
					printf("\n [ Usuario ]");
					printf("\n-------------");
					printf("\nNome: %s",list->usuarios[j].nome);
					printf("\ntelefone: %d",list->usuarios[j].telefone);
					printf("\n\n Pressione ENTER para VOLTAR ao Menu \n");
					getch();
					return 1;
			}		
		} 
		
		printf("\nusuario nao possue cadastro!\n\n");
		getch();
}


//Funçao exibe lista completa de cadasrtados
int exibir_lista_cadastrados(tipo_lista* li) {
	int qtde = li->size -1;
	int i=0;
	if(li == NULL)
		return 0;
	
	if(li->size == 0) {
		system("cls");
		printf("\nLista vazia!");
		getch();
		return 0;
	}
	
	
		system("cls");
		printf("\n----------------------");
		printf("\n [ Lista de Usuarios ]");
		printf("\n----------------------");
		
		for(;i <= qtde; i++) {
		
			printf("\n-------------------\n");
			printf("\nNome: %s",li->usuarios[i].nome);
			printf("\ntelefone: %d",li->usuarios[i].telefone);
			
		
		}
	printf("\n\n Pressione ENTER para VOLTAR ao Menu \n");
	getch();
	return 1;		
}


//Funçao que ordena em ordem alfabética os cadastrados
int ordenar_lista(tipo_lista* li) {
	
	if(li->size == 0) {
		system("cls");
		printf("\nLista vazia!");
		getch();
		return 0;
	}
	
	
	int qtde = li->size;
	int i,y,r;
	char aux[80];
	
	for(i=0;i<qtde;i++) {
		for(y=i+1;y<qtde;y++) {
			r = strcmp(li->usuarios[i].nome,li->usuarios[y].nome);
			if(r > 0){
				strcpy(aux,li->usuarios[i].nome);
				strcpy(li->usuarios[i].nome,li->usuarios[y].nome);
				strcpy(li->usuarios[y].nome,aux);	
			}
		}
		for(i = 0; i<qtde; i++){
		printf("\n-------------------\n");
			printf("\nNome: %s",li->usuarios[i].nome);
			printf("\nTelefone: %d",li->usuarios[i].telefone);
			
			printf("\n Pressione ENTER para o Proximos Dados \n");
			getch();
		
	}	
	}
	
	
}
//programa principal
int main() {
	int op;
	
	tipo_lista* list;//ponteiro para lista
	
	list = cria_lista();
	
		
	do{
		system("cls");
		printf("\n-------------");
		printf("\n [ MENU ]");
		printf("\n-------------");
		printf("\n1-Cadastrar");
		printf("\n2-Pesquisar");
		printf("\n3-Exibir Lista completa");
		printf("\n4-Ordenar Lista");
		printf("\n0-Sair");
		printf("\nOpcao: ");
		scanf("%d",&op);
		fflush(stdin);
		
		switch(op){
	      case 1:
	        insere_usuario_final(list);
	        break;
	      case 2:
     	   pesquisar_usuario_nome(list);
	        break;
	      case 3:
	        exibir_lista_cadastrados(list);
	        break;
	  	  case 4:
	    	ordenar_lista(list);
	    	break;
    	}
  	  }while(op != 0);
  
  system("cls");
  printf("\n Saindo do sistema...\n");
}		
	
	