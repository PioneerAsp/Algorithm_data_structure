#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

void imprimir_lista(int L[10]);
void bubbles();
void anima(int i, int L[10]);
void blink(int i, int L[10], int x,int y, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6);
void elegidos(int i, int L[10]);
void flecha (int x, int y,  int relleno, int color);
void triangulo(int x, int y, int relleno, int color);
void box(int x1, int y1, int x2, int y2, int relleno, int color);
void bbm(int L[10]);


void imp(int list[10]){
    for(int i=0; i<10; i++){
      printf("%d, ", list[i] );


    }

}

void bbm(int L[10]){
  int i=0, BAND=1, aux;
  while(i<9 && BAND==1)
  {
    BAND=0;
   for(int j=0;j<9-i;j++)
   {
     flecha((j*64)+30,340,1,RED);
     flecha(((j+1)*64)+30,340,1,RED);
     elegidos(j,L);
    if(L[j] > L[j+1])
    {
      anima(j,L);
      BAND=1;
      aux = L[j+1];
      L[j+1] = L[j];
      L[j] = aux;
    }
    flecha((j*64)+30,340,1,DARKGRAY);
    flecha(((j+1)*64)+30,340,1,DARKGRAY);

   }
   i++;
  }


  getch();
}

void inicializa()
  {
    int gm,gd=DETECT;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  }

void main()
{
 inicializa();
 setbkcolor(DARKGRAY);
 int list[10]={12,15,48,70,2,64,19,9,12,67};
 settextstyle(0,0,6);
 outtextxy(50,50,"BUBBLE SORT");

 //setcolor(WHITE);
 bubbles();
 imprimir_lista(list);
 //BUBBLE_SORT(list);
   bbm(list);
   imp(list);

 getch();
 closegraph();

}

void bubbles(){
int i=0;
 for(i=0;i<10;i++)
 {
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285, 5, 5);
 }
}

void BUBBLE_SORT(int L[10]){
int aux,i,j, BAND=0;


  while(i<9 && BAND==1)
  {
    BAND=0;
   for(j=0;j<9-i;j++)
   {
     flecha((j*64)+30,340,1,RED);
     flecha(((j+1)*64)+30,340,1,RED);
     elegidos(j,L);
    if(L[j] > L[j+1])
    {
      anima(j,L);
      BAND=1;
      aux = L[j+1];
      L[j+1] = L[j];
      L[j] = aux;
    }
    flecha((j*64)+30,340,1,DARKGRAY);
    flecha(((j+1)*64)+30,340,1,DARKGRAY);

   }
   i++;
  }
  printf("IMPRIMI BURBUJAS");
  bubbles();
  setcolor(WHITE);
  imprimir_lista(L);

  getch();

}

void imprimir_lista(int L[10])
{
  int i;
  char *letra;
  for(i=0;i<10;i++)
  {
    setcolor(BLUE);
    settextstyle(0,0,2);
    outtextxy(18+(i*64),295, itoa(L[i],letra,10));
  }
}

void anima(int i, int L[10])
{
  char *letra;
  int time=100;

  for(int j=0;j<64;j=j+16)
 {
   //PRIMERA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285-j, 5, 5);
   setcolor(BLUE);

   //primer NUMERO
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j, itoa(L[i],letra,10));
   setcolor(WHITE);

   delay(time);

   //DESAPARECE
   ///PRIMER BURBUJA
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse((i*64)+30,300-j, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse((i*64)+45,285-j, 5, 5);

   //PRIMER NUMERO
   setcolor(DARKGRAY);
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j, itoa(L[i],letra,10));
   setcolor(DARKGRAY);

 }

  for(int K=0;K<64;K=K+16)
 {
   //PRIMERA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30+K,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45+K,285-j, 5, 5);

   //NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64)+K,295-j, itoa(L[i],letra,10));
   setcolor(WHITE);

   //SEGUNDA FIGURA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30-K,300, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45-K,285, 5, 5);

   //segundo numero
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64)-K,295, itoa(L[i+1],letra,10));
   setcolor(WHITE);

   delay(time);
   //DESAPARECE
   //PRIMERA BURBUJA
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse((i*64)+30+K,300-j, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse((i*64)+45+K,285-j, 5, 5);

   //PRIMER NUMERO
   settextstyle(0,0,2);
   outtextxy(18+(i*64)+K,295-j, itoa(L[i],letra,10));

   //SEGUNDA BURBUJA
   setfillstyle(1,DARKGRAY);
   fillellipse(((i+1)*64)+30-K,300, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(((i+1)*64)+45-K,285, 5, 5);

   //segundo numero
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64)-K,295, itoa(L[i+1],letra,10));

 }
   ///SEGUNDA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30-K,300, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45-K,285, 5, 5);

   ///segundo numero
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64)-K,295, itoa(L[i+1],letra,10));
  // setcolor(WHITE);

  for(int B=0;B<64;B=B+16)
 {
   //primera burbuja
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30+K,300-j+B, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45+K,285-j+B, 5, 5);

   //PRIMER NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64)+K,295-j+B, itoa(L[i],letra,10));
   setcolor(WHITE);

   delay(time);

   //DESAPARECE
   //PRIMERA BURBUJA
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse((i*64)+30+K,300-j+B, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse((i*64)+45+K,285-j+B, 5, 5);

   //primer texto
   settextstyle(0,0,2);
   outtextxy(18+(i*64)+K,295-j, itoa(L[i],letra,10));
 }
   //primera burbuja
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30+K,300-j+B, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45+K,285-j+B, 5, 5);

   //primer numero
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64)+K,295-j+B, itoa(L[i],letra,10));
   //setcolor(WHITE);
}

void blink(int i, int L[10], int x,int y, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6)
{
   char *letra;
   int time=40;
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x,y-4, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x2,y2-4, 5, 5);

   ///SEGUNDA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x3,y3+4, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x4,y4+4, 5, 5);

   //primer NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x5,y5-4, itoa(L[i],letra,10));
   setcolor(WHITE);

   //SEGUNDO NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x6,y6+4, itoa(L[i+1],letra,10));
   setcolor(WHITE);

   delay(time);
   ////////
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse(x,y-4, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(x2,y2-4, 5, 5);

   ///SEGUNDA
   setfillstyle(1,DARKGRAY);
   fillellipse(x3,y3+4, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(x4,y4+4, 5, 5);

      //primer NUMERO
   settextstyle(0,0,2);
   outtextxy(x5,y5-4, itoa(L[i],letra,10));

   //SEGUNDO NUMERO
   settextstyle(0,0,2);
   outtextxy(x6,y6+4, itoa(L[i+1],letra,10));

   //delay(10);

   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x,y, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x2,y2, 5, 5);

   ///SEGUNDA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x3,y3, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x4,y4, 5, 5);

    //primer NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x5,y5, itoa(L[i],letra,10));
   setcolor(WHITE);

   //SEGUNDO NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x6,y6, itoa(L[i+1],letra,10));
   setcolor(WHITE);

   delay(time);
   ////////
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse(x,y, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(x2,y2, 5, 5);

   ///SEGUNDA
   setfillstyle(1,DARKGRAY);
   fillellipse(x3,y3, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(x4,y4, 5, 5);

    //primer NUMERO
   settextstyle(0,0,2);
   outtextxy(x5,y5, itoa(L[i],letra,10));

   //SEGUNDO NUMERO
   settextstyle(0,0,2);
   outtextxy(x6,y6, itoa(L[i+1],letra,10));

   //delay(150);

   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x,y, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x2,y2, 5, 5);

   ///SEGUNDA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(x3,y3, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(x4,y4, 5, 5);

      //primer NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x5,y5, itoa(L[i],letra,10));
   setcolor(WHITE);

   //SEGUNDO NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(x6,y6, itoa(L[i+1],letra,10));
   setcolor(WHITE);
}

void elegidos(int i, int L[10]){
  char *letra;
  int time=100;

  for(int j=0;j<80;j=j+16)
 {
   //PRIMERA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285-j, 5, 5);

   //primer NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j, itoa(L[i],letra,10));
   setcolor(WHITE);

   //SEGUNDA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45,285-j, 5, 5);

   //SEGUNDO NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j, itoa(L[i+1],letra,10));
   setcolor(WHITE);

   delay(time);

   //DESAPARECE
   ///PRIMER BURBUJA
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse((i*64)+30,300-j, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse((i*64)+45,285-j, 5, 5);

   //PRIMER NUMERO
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j, itoa(L[i],letra,10));

   ///SEGUNDA BURBUJA
   setfillstyle(1,DARKGRAY);
   fillellipse(((i+1)*64)+30,300-j, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(((i+1)*64)+45,285-j, 5, 5);

   //SEGUNDO NUMERO
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j, itoa(L[i+1],letra,10));


 }

   //////////////////////////
   for(int H=0;H<3;H++)
 {
     blink(i, L,(i*64)+30,300-j,(i*64)+45,285-j,((i+1)*64)+30,300-j,((i+1)*64)+45,285-j,18+(i*64),295-j,18+((i+1)*64),295-j);

   }
   //PRIMERA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285-j, 5, 5);

   //primer NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j, itoa(L[i],letra,10));
   setcolor(WHITE);

   ///SEGUNDA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30,300-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45,285-j, 5, 5);

   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j, itoa(L[i+1],letra,10));

    setcolor(RED);
   settextstyle(0,0,3);
   outtextxy((i*64)+12,150,itoa(L[i],letra,10));
   outtextxy(((i+1)*64)+15,150,itoa(L[i+1],letra,10));
   outtextxy((i*64)+59,150,">");

   delay(400);
   int corr;
   if(L[i]>L[i+1]){
    setcolor(GREEN);
   settextstyle(0,0,3);
   outtextxy((i*64)+12,150,itoa(L[i],letra,10));
   outtextxy(((i+1)*64)+15,150,itoa(L[i+1],letra,10));
   outtextxy((i*64)+59,150,">");

   }


   delay(1000);
   setcolor(DARKGRAY);
   box(0,130,680,180,1,DARKGRAY);
  ////////////////////
  for(int k=0;k<80;k=k+16)
 {
   //PRIMERA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300+k-j, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285+k-j, 5, 5);
   setcolor(BLUE);

   //primer NUMERO
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295+k-j, itoa(L[i],letra,10));
   setcolor(WHITE);

   ///SEGUNDA BURBUJA
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30,300-j+k, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45,285-j+k, 5, 5);

   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j+k, itoa(L[i+1],letra,10));
   setcolor(WHITE);


   delay(time);

   //DESAPARECE
   ///PRIMER BURBUJA
   setcolor(DARKGRAY);
   setfillstyle(1,DARKGRAY);
   fillellipse((i*64)+30,300+k-j, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse((i*64)+45,285+k-j, 5, 5);

   //PRIMER NUMERO
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j+k, itoa(L[i],letra,10));
   setcolor(DARKGRAY);

   //SEGUNDA BURBUJA
   setfillstyle(1,DARKGRAY);
   fillellipse(((i+1)*64)+30,300-j+k, 30, 30);
   setfillstyle(1, DARKGRAY);
   fillellipse(((i+1)*64)+45,285-j+k, 5, 5);

   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j+k, itoa(L[i+1],letra,10));

 }
   setcolor(WHITE);
   setfillstyle(1,CYAN);
   fillellipse((i*64)+30,300-j+k, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse((i*64)+45,285-j+k, 5, 5);

   setfillstyle(1,CYAN);
   fillellipse(((i+1)*64)+30,300-j+k, 30, 30);
   setfillstyle(1, WHITE);
   fillellipse(((i+1)*64)+45,285-j+k, 5, 5);

   //PRIMER NUMERO
   setcolor(BLUE);
   settextstyle(0,0,2);
   outtextxy(18+(i*64),295-j+k, itoa(L[i],letra,10));

   ///SEGUNDO NUMERO
   settextstyle(0,0,2);
   outtextxy(18+((i+1)*64),295-j+k, itoa(L[i+1],letra,10));
   setcolor(WHITE);
}

void box(int x1, int y1, int x2, int y2, int relleno, int color)
{
   int poly[8];
   poly[0] = x1 ; poly [1] = y1;
   poly[2] = x2 ; poly [3] = y1;
   poly[4] = x2 ; poly [5] = y2;
   poly[6] = x1 ; poly [7] = y2;
   setfillstyle(relleno,color);
   fillpoly( 4, poly);
}

void flecha (int x, int y, int relleno, int color){
    triangulo(x,y,relleno, color);
    box(x-5, y+15,x+5,y+35,relleno, color);
    setcolor(WHITE);
}

void triangulo(int x, int y, int relleno, int color){
   int tri[6];
   tri[0]=x;     tri[1]=y;
   tri[2]=x+10;  tri[3]=y+15;
   tri[4]=x-10;  tri[5]=y+15;
   setcolor(color);
   setfillstyle(relleno, color);
   fillpoly(3,tri);
}







