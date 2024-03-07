#include<stdio.h>
#define N 500

int quantidade=0;

struct Livro {
    char titulo[100];
    char autor[100];
    int paginas;

    void ler() {
        printf("Digite o nome do titulo: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o nome do autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite a quantidade da paginas: ");
        scanf("%d%*c", &paginas);
        printf("\n");
    }

    void imprimir() {
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Paginas: %d\n\n", paginas);
    }
};

struct Biblioteca {
    Livro livros[15];
    int qtdLivros;

     void cadastrar() {
        printf("Digite a quantidade de livros a serem cadastrados: ");
        scanf("%d%*c", &qtdLivros );

        for (int i=0;i < qtdLivros;i++){
            if(quantidade<15){
                livros[quantidade].ler();
                quantidade++;
            }else{
                printf("Quantidade maxima de livros atingida!\n\n");
            }
        }
    }

    void listar(){
        for(int i=0; i<quantidade; i++){
            livros[i].imprimir();
        }
    }

    void maisPaginas(){
        int mais=0, posicaoMais=0;

        for(int i=0; i<quantidade; i++){
            if(livros[i].paginas>mais){
                mais=livros[i].paginas;
                posicaoMais=i;
            }
        }

        livros[posicaoMais].imprimir();
    }
};

int main(){
    int continuar=0;

    Biblioteca b;

    b.cadastrar();
    b.listar();
    printf("Livro com maior quantidade de paginas:\n");
    b.maisPaginas();

    return 0;
}
