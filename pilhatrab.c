#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha e nó
typedef struct pilha pilha;
typedef struct no no;


//Declaração do tipo nó
struct no{
    int cpf,cpft,valor;
    char op;
    no* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    int cont;
};

//Função para inicializar nó
no* create_n(int cpf,int cpft,int valor,char op){
    no *n = (no*) malloc(sizeof(no));
    n->cpf = cpf;
    n->cpft = cpft;
    n->valor = valor;
    n->op = op;
    return n;

}
//Função para inicializar pilha
pilha* create_p(){
        pilha *p = (pilha*) malloc(sizeof(pilha));
        p->topo = NULL;
        p->cont = 0;
    return p;
}

//Função para empilhar elemento
void push_p(pilha *p, no *n){
    n->prox = p->topo;
    p->topo = n;
}

//Checa se a pilha está vazia, retorna "1" se sim e "0" caso contrário
int isEmpty_p(pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Desempilha elemento do topo da pilha referente
no* pop_p(pilha *p){
	if(p->topo == NULL){
        return NULL;
    }
    else{
        no* aux = p->topo;
        p->topo = aux->prox;
        aux->prox = NULL;
        return aux;
    }
}

//Remove a pilha e todos os dados referentes a ela
void destroy_p(pilha *p){
	while(1 == 1){
		if(p->topo==NULL) break;
		free(pop_p(p));
	}
	free(p);
}

int main(){

    pilha *p = create_p();

    printf("%p %d \n",(void*)p->topo,p->cont);

    int cpf, cpft, valor;
    char op;

    scanf("%d %d %d %c", &cpf, &cpft, &valor, &op);
    no *cliente0 = create_n(cpf, cpft, valor, op);
    no *cliente1 = create_n(cpf+1, cpft+1, valor+1, op);
    no *ax1 = cliente0;    
    /*printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);
    printf("Vazia: %d \n",isEmpty_p(p));
    no* a = pop_p(p);
    printf("%p \n", (void*) a);
    printf("Vazia: %d\n",isEmpty_p(p));*/
    no *ax2 = cliente1;
    push_p(p,ax1);
    push_p(p,ax2);
    printf("%d %d %d %c \n",ax1->cpf,ax1->cpft,ax1->valor,ax1->op);
    printf("%d %d %d %c \n",ax2->cpf,ax2->cpft,ax2->valor,ax2->op);
    destroy_p(p);
}
