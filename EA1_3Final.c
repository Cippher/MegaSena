//Create by 0196611 Vinicius Daniel N. Barros
// Exercicio da mega sena feito em Programação 1 (2016/02)
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

// rotina para utilizar cor do texto (textcolor)
// e cor do fundo (textbackground) em um único comando.
// para chama-la de dentro do programa use  cores(x,y);
// onde x = numero da cor do texto  (textcolor)
//      y = numero da cor do fundo  (textbackground)
void cores(int ForgC, int BackC){   // para chamar
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
// esta rotina é só para a cor do texto
void textcolor(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
     (csbi.wAttributes & 0xf0) | newcolor);
}
// rotina para podermos utilizar o comando gotoxy(linha,coluna)
// sem precisar carregar bibliotecas não disponíveis na Feevale.
void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void imp_autor(){
  setlocale(LC_ALL, "Portuguese");
  gotoxy(27,12);
  textcolor(10);
  printf("Vinicius Daniel");
  Sleep(1500);
  system("cls");
  textcolor(15);
}

main()
{
   imp_autor();  // Rotina padrao para imprimir o nome do autor.

   int numero=0, jogos=0, i=0, j=0, k=0, a=0;
   float valor=0;

   srand(time(NULL));
    //while da quantidade de numeros a serem jogados
   do{
        printf("Digite a quantidade de números a serem jogados em cada aposta: ");
        scanf("%d", &numero);
        if (numero < 6 || numero > 15){
            printf("\n\nQuantidade de numeros invalida!\n\n");
            Sleep(2000);
            system("cls");
        }

   }while (numero < 6 || numero > 15);

   int n[numero];

   if (numero == 6){
       valor = 3.50;
   }else{
        if (numero == 7){
            valor = 24.50;
        }else{
            if (numero == 8){
                valor = 98.00;
            }else{
                if (numero == 9){
                    valor = 294.00;
                }else{
                    if (numero == 10){
                        valor = 735.00;
                    }else{
                        if (numero == 11){
                            valor = 1617.00;
                        }else{
                            if (numero == 12){
                                valor = 3234.00;
                            }else{
                                if (numero == 13){
                                    valor = 6006.00;
                                }else{
                                    if (numero == 14){
                                        valor = 10510.50;
                                    }else{
                                        if (numero == 15){
                                            valor = 17517.50;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
   }

    do{
        printf("Digite o numero de apostas que deseja fazer: ");
        scanf("%d", &jogos);
        if (jogos < 1 || jogos > 8){
            printf("Numero de apostas invalido!");
        }

    }while (jogos < 1 || jogos > 8);

    for (i=1; i<=jogos; i++){
            textcolor(10);
            printf("\nJogo %d:   ", i);
        for (j=0; j<numero; j++){
           n[j] = rand()%6+1;

           do{
            n[j] = rand()%60+1;
           a =1;
            for (k=0; k<j; k++){
                if (n[k] == n[j]){
                    a = 0;
                }
            }
           }while( a == 0 );

           textcolor(11);
           printf("%6d", n[j]);
        }
    }

    valor = valor*jogos;
    textcolor(13);
    printf("\n\nTotal a pagar: %.2f\n\n", valor);
    textcolor(12);
    printf("BOA SORTE! (^-^)/");
    textcolor(15);


   getch();
}
