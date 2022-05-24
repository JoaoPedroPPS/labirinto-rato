#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#define MAX 15


void cria(char l[MAX][MAX]){
    int i,j,x,y;
    srand(time(NULL));
    for(i=0;i<MAX;i++)
    {
        for (j = 0; j < MAX; j++) 
        {
            if ((rand() % 5) == 1)
            {
                l[i][j] = '|';
            }
            else
            {
                l[i][j] = '.';
            }
        }
    }
    for(i=0;i<MAX;i++)
    {
        l[0][i]='*';
        l[MAX-1][i]='*';
        l[i][0]='*';
        l[i][MAX-1]='*';
    }

    x=  rand() % MAX;
    y=  rand() % MAX;
    l[x][y]='Q';
}
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int col){
    int i,j;
    for ( i = 0; i < linha; i++)
    {
        printf("\n");
        for ( j = 0; j < col; j++)
        {
            printf(" %c ", mat[i][j]);
        }
    }
}
     
  int funcaoSuperMouse(char lab[MAX][MAX],int i, int j){
     tpilha row, col;
     
	inicializa(&col);
    inicializa(&row);
//====================================
     while (lab[i][j] != 'Q')
     {
         lab[i][j] = 'M';

         if (lab[i][j + 1] == '.' || lab[i][j + 1] == 'Q'){
             push(&row, i);
             push(&col, j);
             j++;
         }
         else if (lab[i + 1][j] == '.' || lab[i + 1][j] == 'Q'){
             push(&row, i);
             push(&col, j);
             i++;
         }
         else if (lab[i][j - 1] == '.' || lab[i][j - 1] == 'Q'){
             push(&row, i);
             push(&col, j);
             j--;
         }
         else if (lab[i - 1][j] == '.' || lab[i - 1][j] == 'Q'){
             push(&row, i);
             push(&col, j);
             i--;
         }
         else
         {
             if (!isEmpty(row) && !isEmpty(col))
             {
                 lab[i][j] = 'V';
                 i = pop(&row);
                 j = pop(&col);
             }
             else
             {
                 printf("\nImpossível encontrar o queijo nesta rodada :c \n");
                 return;
             }
         }

         Sleep(450);
         system("cls");
         mostraLabirinto(lab, MAX, MAX);
     }

     printf("\nO Super Mouse encontrou o queijo nesta posicao: (%i, %i)\n", i, j);
 }



int main(){
    char labirinto[MAX][MAX];
    int x,y;
    cria(labirinto);
    mostraLabirinto(labirinto,MAX,MAX);
    printf("\nEntre com a posicao inicial:");
    scanf("%d %d",&x,&y);
    funcaoSuperMouse(labirinto,x,y);
    getch();
    }
