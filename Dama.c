#include <stdio.h>
#include <stdlib.h>
#define N 8


//Imprime tabuleiro

void tabuleiro(char **Matriz){
     int i, j;
	 for(i=0;i<N;i++){
     	for(j=0;j<N;j++){
     		printf("[%c]",Matriz[i][j]);
     	}
     	printf("\n");

     }
}

//Aloca espaços de memória para o tabuleiro
char **initialize(){
	char **Matriz;
	int i, j;
	Matriz = (char **)calloc(N, sizeof(char *));
	for(i=0;i<N;i++)
		Matriz[i] = (char *)calloc(N, sizeof(char));

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			Matriz[i][j] = ' ';

    return Matriz;
}

//Função que aloca as peças Pretas e brancas 

void BlackOrWhite(char **Matriz){
	int i, j;
for(i=0; i<3; i++){
	if(i%2==0)
		j=1;
	else
		j=0;
	while(j<N){
		Matriz[i][j]='P';
		j+=2;
		}
	}
for (i=5; i<8; i++){
	if(i%2==1)
		j=0;
	else
		j=1;
	while(j<N){
		Matriz[i][j]='B';
		j+=2;
		}
	}
}
//Verifica se a peça selecionada é valida
int stepshow (char **Matriz, int lin, int col, char gamer){
    if(lin < 0 || lin >= N ||
       col < 0 || col >= N ||
       Matriz[lin][col] != gamer)
        return 0;
 
}

int runforest(char **Matriz, int lin, int col, int Jogador){

}
// Verifica o status do jogo
int flawesvictory(char **Matriz, char Juego, char JuegoD){
	int i, j;
 for(i=0;i<N;i++)
        if(Matriz[i][0]==Juego || Matriz[i][0]==JuegoD ||
           Matriz[i][1]==Juego || Matriz[i][1]==JuegoD ||
           Matriz[i][2]==Juego || Matriz[i][2]==JuegoD ||
           Matriz[i][3]==Juego || Matriz[i][3]==JuegoD ||
           Matriz[i][4]==Juego || Matriz[i][4]==JuegoD ||
           Matriz[i][5]==Juego || Matriz[i][5]==JuegoD ||
           Matriz[i][6]==Juego || Matriz[i][6]==JuegoD ||
           Matriz[i][7]==Juego || Matriz[i][7]==JuegoD)//Verifica todas as casas do tabuleiro para ver se tem peças
        		return 1;//Jogo continua
}
//Verifica se o ganhador são as peças B ou P(X e O são as peças que virariam dama)
int statusofgame(char **Matriz){
if (flawesvictory(Matriz, 'B', 'X'))
	return -1;//Continua o jogo
else
	return 0;//Pretas ganham

if(flawesvictory(Matriz, 'P', 'O'))
	return -1;//COntinua o jogo
else
    return 1;//Brancas ganham

}

//Executar todas as funções do programa
void game(){
	printf("Bem vindo a dama!\nAs brancas começam, dê as coordenadas:\n");
	printf("Importante: Primeiro indicar o número da linha e depois o número da coluna\n");
	char **Matriz;
	char Player = 'B';
	int Jogook = -1;
	Matriz = initialize();
	BlackOrWhite(Matriz);
	int linhaA, colunaA, linhaB, colunaB;
	
	while(Jogook==-1){
		tabuleiro(Matriz);
		printf("Caro jogador [%c], digite a linha e coluna para selecionar a peça que deseja movimentar:", Player);
		scanf("%d",&linhaA);
		scanf("%d",&colunaA);
		//SE a jogada não for possivel
		if( !stepshow(Matriz, linhaA, colunaA, Player) ){
			printf("\nJogada invalida!\n");
		    continue;


	}	 

		Jogook = statusofgame(Matriz);

		if( Player == 'B')
            Player = 'P';
        else
            Player = 'B';
    }
	
	if(Jogook = 0)
		printf("\nPretas Wins!\n");
	if(Jogook = 1)
		printf("\nBrancas Wins!\n");

}
void main(){
	game();
}

