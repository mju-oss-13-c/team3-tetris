lude <stdio.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h>

#include <time.h>



int a,b,c,d; // Àü¿ªº¯Œö!!

//Œ³ží

//ºó°ø°£(0) º®(1) I(2) T(3) O(4) L(5) J(6) S(7) Z(8) 

//º¯Œö

int matrix[26][12]={{1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1}};

int w, x, y, z, p, q, r, s;//ºí·Ï À§Ä¡ 

//int a, b, c, d; //°íœºÆ® À§Ä¡ 



double score; //Á¡Œö

int harddrop; //ÇÏµåµå·ÓœÃ Á¡Œö 

int level; //·¹º§

double blocknum; //ÃÑ ºí·Ï °¹Œö 

double linesclrd; //ÃÑ Áö¿î ÁÙ °¹Œö 



int rotation; //ºí·Ï ÈžÀü 



int keyboard; //Å°ºžµå ÀÔ·Â 



int next1, next2, next3, now; //³ØœºÆ®Ã¢ 



double times; //ºí·ÏŽç œÃ°£°æ°ú 

double totimes; //ÃÑ œÃ°£°æ°ú

double blocktouch; //ºí·°ÀÌ ¹ÙŽÚ¿¡ ŽêÀº °æ¿ì œÃ°£ °æ°úœÃ ÇÏµåµå·Ó 

int floorkick; //ÇÃ·ÎŸîÅ±Àº ŒŒ¹ø±îÁöžž Çã¿ëÇÒ °ÍÀÓ 



double whenTSpin; //ÆŒœºÇÉ ±ÛÀÚÁö¿ì±â¿ë

double IsTspin, Turns, TTurns, moves; //TœºÇÉ ¿©ºÎ 

int useskick; //T-œºÇÉœÃ KickÀ» »ç¿ë ÇÏŽÀ³ÄÀÇ ¿©ºÎ 



int delay; //ºí·Ï ³»·Á¿ÀŽÂ ŒÓµµ 



int holding; //Ã³Àœ¿¡ ÈŠµåµÇŸî ÀÖŽÂ °Í : ŸøÀœ 

int justhold;

double firsthold;



int blocktype; //ºí·ÏžðŸç(»ö±ò) 

int row, height; //žÅÆ®ž¯œº ±×ž± ¶§ »ç¿ë

int clrdheight; //ÁÙ Áö¿öÁú ¶§ »ç¿ë 

int repeatclr; //ÇÑ¹ø¿¡ ³×ÁÙ±îÁö Áö¿öÁö°Ô

int howmanyclr; //ÇÑ¹ø¿¡ žîÁÙ Áö¿öÁö³ª? 

double whenclr; //ŸðÁŠ Áö¿öÁ³³ª? 



int BTB; //¹éÅõ¹é

int combo; //ÄÄºž 



int GOx, GOy; //°ÔÀÓ¿À¹öœÃ ÀÌÆåÆ® ÁÂÇ¥ 

int GOkey; //°ÔÀÓ¿À¹öœÃ ÀÔ·Â ¹ÞŽÂ°÷ 

int restart; //0ÀÏœÃ ÀÏ¹ÝÀûÀÎ, 1ÀÏœÃ ÀçœÃÀÛ

int resX, resY; //ÀçœÃÀÛœÃ žÅÆ®ž¯œº ÃÊ±âÈ­ 



int pfcX, pfcY; //ÆÛÆåÆ®Å¬ž®Ÿî X,YÁÂÇ¥ 



int whethercolor;

int whatcolor;





 

//Ä¿Œ­°šÃßŽÂÇÔŒö 

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c)

{

     CONSOLE_CURSOR_INFO CurInfo;

     switch (c) {

     case NOCURSOR:

          CurInfo.dwSize=1;

          CurInfo.bVisible=FALSE;

          break;

     case SOLIDCURSOR:

          CurInfo.dwSize=100;

          CurInfo.bVisible=TRUE;

          break;

     case NORMALCURSOR:

          CurInfo.dwSize=20;

          CurInfo.bVisible=TRUE;

          break;

     }

     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);}

     

//Ä¿Œ­ÀÌµ¿ÇÔŒö 

void gotoxy(int x, int y)

{

     COORD Cur;

     Cur.X=x;

     Cur.Y=y;

     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);

}



//±×ž®ŽÂ ÇÔŒö 

void draw(void)

{if(whatcolor==1 && blocktype==2)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b);

 else if(whatcolor==1 && blocktype==3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d);

 else if(whatcolor==1 && blocktype==4)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);

 else if(whatcolor==1 && blocktype==5)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04);

 else if(whatcolor==1 && blocktype==6)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09);

 else if(whatcolor==1 && blocktype==7)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a);

 else if(whatcolor==1 && blocktype==8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);

 else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);}

 

 gotoxy(2*w+10,p-3);

 if(p-3>0)printf("¡à");

 gotoxy(2*x+10,q-3);

 if(q-3>0)printf("¡à");

 gotoxy(2*y+10,r-3);

 if(r-3>0)printf("¡à");

 gotoxy(2*z+10,s-3);

 if(s-3>0)printf("¡à");}

  

//¹ÙŽÚ¿¡ ³õŽÂ ÇÔŒö 

void putdraw(void)

{matrix[p][w]=blocktype; matrix[q][x]=blocktype; matrix[r][y]=blocktype; matrix[s][z]=blocktype;}

 

//Áö¿ìŽÂ ÇÔŒö 

void erase(void)

 {gotoxy(2*w+10,p-3);

 if(p-3>0)printf(" ");

 gotoxy(2*x+10,q-3);

 if(q-3>0)printf(" ");

 gotoxy(2*y+10,r-3);

 if(r-3>0)printf(" ");

 gotoxy(2*z+10,s-3);

 if(s-3>0)printf(" ");}

 

//°íœºÆ® ÇÔŒö

void ghost(void)

 {a=p; b=q; c=r; d=s;

 while(1)

 {if(matrix[a+1][w]!=0 || matrix[b+1][x]!=0 || matrix[c+1][y]!=0 || matrix[d+1][z]!=0)break;

  a++; b++; c++; d++;}

 if(whatcolor==1 && blocktype==2)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b);

 else if(whatcolor==1 && blocktype==3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d);

 else if(whatcolor==1 && blocktype==4)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);

 else if(whatcolor==1 && blocktype==5)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04);

 else if(whatcolor==1 && blocktype==6)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09);

 else if(whatcolor==1 && blocktype==7)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a);

 else if(whatcolor==1 && blocktype==8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);

 else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);}

 gotoxy(2*w+10,a-3);

 if(a-4>0)printf("¡à");

 gotoxy(2*x+10,b-3);

 if(b-4>0)printf("¡à");

 gotoxy(2*y+10,c-3);

 if(c-4>0)printf("¡à");

 gotoxy(2*z+10,d-3);

 if(d-4>0)printf("¡à");}

 

//°íœºÆ® Áö¿ì±âÇÔŒö

void eraseghost(void)

{gotoxy(2*w+10,a-3);

 if(a-4>0)printf(" ");

 gotoxy(2*x+10,b-3);

 if(b-4>0)printf(" ");

 gotoxy(2*y+10,c-3);

 if(c-4>0)printf(" ");

 gotoxy(2*z+10,d-3);

 if(d-4>0)printf(" ");} 

 

//ÇÔŒö¿øÇüŒ±Ÿð

void Ttet(void);

void Otet(void);

void Itet(void);

void Ltet(void);

void Jtet(void);

void Stet(void);

void Ztet(void);

void gameover(void);



//ÈŠµå ÇÔŒö 

void hold(void)

{

 if(holding==0){holding=now; justhold=1; firsthold=blocknum; if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                             else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                             else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                             else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                             else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                             else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                             else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");}}

 else if(holding==2){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Itet();}

 else if(holding==3){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Ttet();}

 else if(holding==4){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Otet();}

 else if(holding==5){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Ltet();}

 else if(holding==6){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Jtet();}

 else if(holding==7){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Stet();}

 else if(holding==8){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("¡á¡á¡á¡á");}

                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("¡á¡á"); gotoxy(4,3); printf("¡á¡á");}

                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á"); gotoxy(3,3); printf("¡á¡á¡á");}

                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("¡á¡á"); gotoxy(3,3); printf("¡á¡á");}

                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("¡á¡á"); gotoxy(5,3); printf("¡á¡á");} Ztet();}

}



int main(void)

{ //Ä¿Œ­°šÃã & Ã¢Å©±â°íÁ€ 

  setcursortype(NOCURSOR);

  system("mode con:lines=23");





  

  //Èæ¹é / ÄÃ·¯ 

  system("cls");

  gotoxy(10,4);

   printf("Š£Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š€\n");

   printf("                ================TETRIS GAME==================    \n");

   printf("                    »öÀ» Œ±ÅÃÇÏŒŒ¿ä:");

   printf("Èæ(B)/»ö(C)                        \n");

   printf("		   Á¶¿ø:¿ìºŽÈÆ 60132292\n");

   printf("		   Á¶¿ø:ÀÌ±€¿ë 60132297\n");

   printf("		   Á¶¿ø:ŸÈÁŠ¿ø 60132285\n");



   printf("          ŠŠŠ¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¡Š¥\n");

   while(1)

  {whethercolor=getch();

  if(whethercolor==66 || whethercolor==98){whatcolor=0; break;}

  else if(whethercolor==67 || whethercolor==99){whatcolor=1; break;}}

  

  //ÀçœÃÀÛ À§Ä¡ 

  restarting:

  system("cls");

  resX = 1; resY = 1;

  while(resY<25)

  {while(resX<11)

  {matrix[resY][resX]=0; resX++;}

  resX=1; resY++;}



    

    

  //°ÔÀÓÆÇ 

  int boundy;

  boundy = 1;

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("====ÀúÀå===========================ŽÙÀœºí·°====");

  while(boundy<5)

  {gotoxy(0,boundy);

  printf("1");

  boundy++;}

  boundy = 1;

  while(boundy<22)

  {gotoxy(11,boundy);

  printf("1");

  gotoxy(32,boundy);

  printf("1");

  boundy++;}

  gotoxy(11,22);

  printf("======================");

  gotoxy(0,5);

  printf("===========");

  gotoxy(0,7);

  printf("  Å°ŒŒÆÃ:\n\n   ¡ç ¡æ\n ÁÂ¿ì·Î ÀÌµ¿\n    ¡é\nŒÒÇÁÆ®µå¶ø\n   SPACE\n ÇÏµåµå¶ø\n   ¡è,X\nÁ€¹æÇâÈžÀü\n     Z\n¹Ý¹æÇâÈžÀü\n     C\n   ÈŠ µå");

  boundy=1;

  while(boundy<13)

  {gotoxy(43,boundy);

  printf("1"); boundy++;}

  gotoxy(33,13);

  printf("===========");

  gotoxy(35,15);

  printf("    SCORE");

  

  gotoxy(33,17);

  printf("    Delete ");

  gotoxy(35,19);

  printf("LEVEL\n");

  printf("15°¡ žž·Ÿ");

    

  //·£Žõž¶ÀÌÀú & game

  srand((unsigned)time(NULL));

  int random;

  int randm[7]={10,11,12,13,14,15,16};

  blocknum=0;

  score=0;

  combo=0;

  justhold=0;

  holding=0;  

  delay=100;

  level = 1;

  linesclrd=0;

  IsTspin = 0;

  whenclr = 0;

  BTB = 0;

  useskick = 0;

  harddrop=0;

  totimes=0;

  restart=0;

  firsthold=-2;

  while(1)

  {

  if(justhold==1)justhold=0;

  height=4;

  row=1;

  if(whatcolor==0)

  {while(height<25)

  {row=1;

  while(row<11)

  {if(matrix[height][row]==0){gotoxy(2*row+10,height-3); printf(" ");}

   else{gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); printf("¡á");}

   row++;}

  height++;}}

  else if(whatcolor==1)

  {while(height<25)

  {row=1;

  while(row<11)

  {if(matrix[height][row]==0){gotoxy(2*row+10,height-3); printf(" ");}

   else if(matrix[height][row]==2){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); printf("¡á");}

   else if(matrix[height][row]==3){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); printf("¡á");}

   else if(matrix[height][row]==4){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); printf("¡á");}

   else if(matrix[height][row]==5){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); printf("¡á");}

   else if(matrix[height][row]==6){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); printf("¡á");}

   else if(matrix[height][row]==7){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); printf("¡á");}

   else if(matrix[height][row]==8){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); printf("¡á");}

   row++;}

  height++;}}

  

  if(combo>1)

  {gotoxy(45,4);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);

  printf("% 2dcombo",combo-1);}

  if(score<10000000)

  {gotoxy(34,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%7.0lf",score);}

  else if(score>9999999 && score<100000000)

  {gotoxy(34,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%8.0lf",score);}

  else if(score>99999999 && score<1000000000)

  {gotoxy(34,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%9.0lf",score);}

  else if(score>999999999)

  {gotoxy(34,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("999999999+");}

  gotoxy(36,18);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%4.0lf",linesclrd);

  gotoxy(37,20);

  if(level<16){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); printf("% 2d", level);}

  else if(level>15){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); printf("15+");}

  if(-1<linesclrd && linesclrd<10)level=1;

  else if(9<linesclrd && linesclrd<20){level=2; delay=900;}

  else if(19<linesclrd && linesclrd<30){level=3; delay=800;}

  else if(29<linesclrd && linesclrd<40){level=4; delay=700;}

  else if(39<linesclrd && linesclrd<50){level=5; delay=600;}

  else if(49<linesclrd && linesclrd<60){level=6; delay=500;}

  else if(59<linesclrd && linesclrd<70){level=7; delay=400;}

  else if(69<linesclrd && linesclrd<80){level=8; delay=300;}

  else if(79<linesclrd && linesclrd<90){level=9; delay=200;}

  else if(89<linesclrd && linesclrd<100){level=10; delay=150;}

  else if(99<linesclrd && linesclrd<110){level=11; delay=100;}

  else if(109<linesclrd && linesclrd<120){level=12; delay=80;}

  else if(119<linesclrd && linesclrd<130){level=13; delay=60;}

  else if(129<linesclrd && linesclrd<140){level=14; delay=40;}

  else if(139<linesclrd && linesclrd<150){level=15; delay=20;}

  else if(linesclrd>149){level=20; delay=1;}

  

  random=rand();

  randm[(int)blocknum%7]=random%7;

  if((int)blocknum%7==1){if(randm[0]==randm[(int)blocknum%7])continue;}

  if((int)blocknum%7==2){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7])continue;}

  if((int)blocknum%7==3){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7])continue;}

  if((int)blocknum%7==4){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7])continue;}

  if((int)blocknum%7==5){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7] || randm[4]==randm[(int)blocknum%7])continue;}

  if((int)blocknum%7==6){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7] || randm[4]==randm[(int)blocknum%7] || randm[5]==randm[(int)blocknum%7])continue;}

  

  if(blocknum>2){now=randm[(int)(blocknum-3)%7]+2; next1=randm[(int)(blocknum-2)%7]+2; next2=randm[(int)(blocknum-1)%7]+2; next3=randm[(int)(blocknum)%7]+2;

  

  if(next1==2){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,3); printf("¡á¡á¡á¡á");}

  else if(next1==3){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,2); printf("¡á"); gotoxy(35,3); printf("¡á¡á¡á");}

  else if(next1==4){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,2); printf("¡á¡á"); gotoxy(36,3); printf("¡á¡á");}

  else if(next1==5){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,2); printf("¡á"); gotoxy(35,3); printf("¡á¡á¡á");}

  else if(next1==6){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,2); printf("¡á"); gotoxy(35,3); printf("¡á¡á¡á");}

  else if(next1==7){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,2); printf("¡á¡á"); gotoxy(35,3); printf("¡á¡á");}

  else if(next1==8){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,2); printf("¡á¡á"); gotoxy(37,3); printf("¡á¡á");}

  

  if(next2==2){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,7); printf("¡á¡á¡á¡á");}

  else if(next2==3){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,6); printf("¡á"); gotoxy(35,7); printf("¡á¡á¡á");}

  else if(next2==4){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,6); printf("¡á¡á"); gotoxy(36,7); printf("¡á¡á");}

  else if(next2==5){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,6); printf("¡á"); gotoxy(35,7); printf("¡á¡á¡á");}

  else if(next2==6){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,6); printf("¡á"); gotoxy(35,7); printf("¡á¡á¡á");}

  else if(next2==7){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,6); printf("¡á¡á"); gotoxy(35,7); printf("¡á¡á");}

  else if(next2==8){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,6); printf("¡á¡á"); gotoxy(37,7); printf("¡á¡á");}

  

  if(next3==2){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,11); printf("¡á¡á¡á¡á");}

  else if(next3==3){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,10); printf("¡á"); gotoxy(35,11); printf("¡á¡á¡á");}

  else if(next3==4){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,10); printf("¡á¡á"); gotoxy(36,11); printf("¡á¡á");}

  else if(next3==5){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,10); printf("¡á"); gotoxy(35,11); printf("¡á¡á¡á");}

  else if(next3==6){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,10); printf("¡á"); gotoxy(35,11); printf("¡á¡á¡á");}

  else if(next3==7){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,10); printf("¡á¡á"); gotoxy(35,11); printf("¡á¡á");}

  else if(next3==8){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,10); printf("¡á¡á"); gotoxy(37,11); printf("¡á¡á");}

  

  if(now==2)Itet();

  else if(now==3)Ttet();

  else if(now==4)Otet();

  else if(now==5)Ltet();

  else if(now==6)Jtet();

  else if(now==7)Stet();

  else if(now==8)Ztet();

  

  //ÀçœÃÀÛ 

  if(restart==1)goto restarting;

  

  //ÁÙÁö¿ì±â 

  repeatclr=1;

  howmanyclr=0;

  while(repeatclr<5)

  {height=24;

  row=1;

  clrdheight=-1;

  while(height>1)

  {if(matrix[height][1]!=0 && matrix[height][2]!=0 && matrix[height][3]!=0 && matrix[height][4]!=0 && matrix[height][5]!=0 && matrix[height][6]!=0 && matrix[height][7]!=0 && matrix[height][8]!=0 && matrix[height][9]!=0 && matrix[height][10]!=0)

  {clrdheight=height; linesclrd++; howmanyclr++;

  while(clrdheight>0)

  {while(row<11)

  {if(matrix[clrdheight-1][row]!=1)matrix[clrdheight][row]=matrix[clrdheight-1][row];

  row++;}

  row=1; clrdheight--;}}

  height--;}

  repeatclr++;}}

  

  //Á¡Œö 

  if(justhold!=2){

  if(howmanyclr==1 && IsTspin==0){score=score+100*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=0; combo++;}

  else if(howmanyclr==2 && IsTspin==0){score=score+300*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=0; combo++;}

  else if(howmanyclr==3 && IsTspin==0){score=score+500*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=0; combo++;}

  else if(howmanyclr==4 && BTB==0){score=score+800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Tetris"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==4 && BTB==1){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Tetris"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==0 && IsTspin==0){combo=0;}

  else if(howmanyclr==0 && IsTspin==1 && useskick==0){score=score+400*level; combo=0;}

  else if(howmanyclr==0 && IsTspin==1 && useskick==1){score=score+100*level; combo=0;}

  else if(howmanyclr==1 && IsTspin==1 && useskick==0 && BTB==0){score=score+800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==1 && IsTspin==1 && useskick==1 && BTB==0){score=score+200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==1 && IsTspin==1 && useskick==0 && BTB==1){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==1 && IsTspin==1 && useskick==1 && BTB==1){score=score+300*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==2 && IsTspin==1 && BTB==0){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==2 && IsTspin==1 && BTB==1){score=score+1800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==3 && IsTspin==1 && BTB==0){score=score+1600*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=1; combo++;}

  else if(howmanyclr==3 && IsTspin==1 && BTB==1){score=score+2400*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=1; combo++;}}

  score=score+50*combo*level;

  

  //ÆÛÆåÆ® Å¬ž®Ÿî

  pfcX=0; pfcY=0;

  pfcYPLUS:

  pfcY++;

  if(pfcY==25)goto perfectclear;

  pfcXPLUS:

  pfcX++;

  if(pfcX==11){pfcX=0; goto pfcYPLUS;}

  if(matrix[pfcY][pfcX]==0 && blocknum>3)goto pfcXPLUS;

  else goto notpfc;

  

  perfectclear:

  score=score+5000*level;

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);

  gotoxy(46,5);

  printf("Perfect");

  gotoxy(47,6);

  printf("Clear");

  

  notpfc:

  blocknum++;}

  

  return 0;

  system("PAUSE");

}







//IÅ×Æ®ž®¹Ì³ë 

void Itet(void)

{blocktype=2;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0 || matrix[4][7]!=0){gameover();}

 if(restart==1)return;

 w=4; x=5; y=6; z=7;

 p=4; q=4; r=4; s=4;

   while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0 && matrix[p+2][y]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][w-2]==0 && matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[p-2][y]==0 && matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation++; moves++;}}

  else if(rotation==4){if(matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0 && matrix[r][w+2]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0 && matrix[p+2][y]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][w-2]==0 && matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[p-2][y]==0 && matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation++; moves++;}}

  else if(rotation==4){if(matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0 && matrix[r][w+2]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation=1; moves++;}}

  }

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRS¹ÌÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[p-1][x]==0 && matrix[p][x]==0 && matrix[p+1][x]==0 && matrix[p+2][x]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[q][w-1]==0 && matrix[q][w]==0 && matrix[q][w+1]==0 && matrix[q][w+2]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation--; moves++;}}

 else if(rotation==3){if(matrix[p-2][x]==0 && matrix[p][x]==0 && matrix[p+1][x]==0 && matrix[p-1][x]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation--; moves++;}}

 else if(rotation==4){if(matrix[q][w-2]==0 && matrix[q][w-1]==0 && matrix[q][w]==0 && matrix[q][w+1]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();}}





 //TÅ×Æ®ž®¹Ì³ë 

void Ttet(void)

{blocktype=3;

 moves=0;

 TTurns=-1;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}

 if(restart==1)return;

 w=5; x=4; y=5; z=6;  

 p=3; q=4; r=4; s=4;

  while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[r+1][w]==0){w++; x++; z--; p++; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][x-1]==0){w--; x++; z--; p++; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[q-1][y]==0){w--; x--; z++; p--; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[p][y+1]==0){w++; x--; z++; p--; q--; s++; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[r+1][w]==0){w++; x++; z--; p++; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][x-1]==0){w--; x++; z--; p++; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[q-1][y]==0){w--; x--; z++; p--; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[p][y+1]==0){w++; x--; z++; p--; q--; s++; rotation=1; moves++;}}}

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRSÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[r+1][y]==0){w--; x++; z--; p++; q++; s--; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[r][y-1]==0){w--; x--; z++; p--; q++; s--; rotation--; moves++;}

                      else if(matrix[q][w]==0 && matrix[r][w+1]==0){y++; z=z+2; p--; q++; s--; rotation--; moves++;}}

 else if(rotation==3){if(matrix[q-1][y]==0){w++; x--; z++; p--; q--; s++; rotation--; moves++;}

                      else if(matrix[q-1][z]==0 && matrix[p][z]==0){x=x-2; y--; p--; q--; s++; rotation--; moves++;}}

 else if(rotation==4){if(matrix[r][y+1]==0){w++; x++; z--; p++; q--; s++; rotation--; moves++;}

                      else if(matrix[r][w-1]==0 && matrix[q][w]==0){y--; z=z-2; p++; q--; s++; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();

 if(rotation==3 && matrix[s+1][z]!=0 && matrix[s+1][x]!=0 && (matrix[s-1][z]!=0 || matrix[s-1][x]!=0)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=0;}

 else if(rotation==2 && matrix[q][w]!=0 && matrix[s][w]!=0 && matrix[s][z-1]!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=0;}

 else if(TTurns==moves){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=1;}}}







//OÅ×Æ®ž®¹Ì³ë (µ¹ŸÆ°¥ ÇÊ¿ä ŸøÀž¹Ç·Î x,z,À§È­»ìÇ¥ ºÒÇÊ¿ä) 

void Otet(void)

{blocktype=4;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}

 if(restart==1)return;

 w=5; x=6; y=5; z=6; //1~10

 p=3; q=3; r=4; s=4; //0~20 

 while(1)

 {ghost();

  draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw(); times++; totimes++;}

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊÈÄ¿¡ ŽÙÀœºí·Ï 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

  

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();

 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; score=score+1;

  if(score<10000000)

  {gotoxy(34,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%7.0lf",score);}

  else if(score>9999999 && score<100000000)

  {gotoxy(35,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%8.0lf",score);}

  else if(score>99999999 && score<1000000000)

  {gotoxy(36,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("%9.0lf",score);}

  else if(score>999999999)

  {gotoxy(36,16);

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

  printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++;}

 }

    

 //œºÆäÀÌœº Ž­·¶À»¶§ 

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++;}

   score=score+2*(p-harddrop);

   break;}

      

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 

}//while(1)

 if(keyboard==67 || keyboard==99)hold();

 else putdraw();}





//LÅ×Æ®ž®¹Ì³ë 

void Ltet(void)

{blocktype=5;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}

 if(restart==1)return;

 w=6; x=4; y=5; z=6;

 p=3; q=4; r=4; s=4;

   while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[s+1][w]==0 && matrix[s+1][y]==0 && matrix[p][y]==0){x++; z--; p=p+2; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[s][z-1]==0 && matrix[r][z-1]==0 && matrix[r][w]==0){w=w-2; x++; z--; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[s-1][w]==0 && matrix[s-1][y]==0 && matrix[p][y]==0){x--; z++; p=p-2; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[p][z+1]==0 && matrix[r][z+1]==0 && matrix[r][w]==0){w=w+2; x--; z++; q--; s++; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[s+1][w]==0 && matrix[s+1][y]==0 && matrix[p][y]==0){x++; z--; p=p+2; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[s][z-1]==0 && matrix[r][z-1]==0 && matrix[r][w]==0){w=w-2; x++; z--; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[s-1][w]==0 && matrix[s-1][y]==0 && matrix[p][y]==0){x--; z++; p=p-2; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[p][z+1]==0 && matrix[r][z+1]==0 && matrix[r][w]==0){w=w+2; x--; z++; q--; s++; rotation=1; moves++;}}

  }

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRS¹ÌÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[p][x]==0 && matrix[p][y]==0 && matrix[q+1][y]==0){w=w-2; x++; z--; q++; s--; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[q][w]==0 && matrix[r][w]==0 && matrix[r][x-1]==0){x--; z++; p=p-2; q++; s--; rotation--; moves++;}}

 else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][y]==0 && matrix[p][x]==0){w=w+2; x--; z++; q--; s++; rotation--; moves++;}}

 else if(rotation==4){if(matrix[q][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x++; z--; p=p+2; q--; s++; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();}}





//JÅ×Æ®ž®¹Ì³ë 

void Jtet(void)

{blocktype=6;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}

 if(restart==1)return;

 w=4; x=4; y=5; z=6;

 p=3; q=4; r=4; s=4;

  while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][y]==0 && matrix[p][w]==0){w=w+2; x++; z--; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][x-1]==0 && matrix[r][w]==0 && matrix[s][w]==0){x++; z--; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][z]==0 && matrix[p][y]==0){w=w-2; x--; z++; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[s][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x--; z++; p=p-2; q--; s++; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][y]==0 && matrix[p][w]==0){w=w+2; x++; z--; q--; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[r][x-1]==0 && matrix[r][w]==0 && matrix[s][w]==0){x++; z--; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][z]==0 && matrix[p][y]==0){w=w-2; x--; z++; q++; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[s][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x--; z++; p=p-2; q--; s++; rotation=1; moves++;}}

  }

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRS¹ÌÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][w]==0 && matrix[q+1][y]==0){x++; z--; p=p+2; q++; s--; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[r][w]==0 && matrix[r][x-1]==0 && matrix[p][x-1]==0){w=w-2; x--; z++; q++; s--; rotation--; moves++;}}

 else if(rotation==3){if(matrix[q-1][y]==0 && matrix[q-1][w]==0 && matrix[p][y]==0){x--; z++; p=p-2; q--; s++; rotation--; moves++;}}

 else if(rotation==4){if(matrix[p][x+1]==0 && matrix[r][x+1]==0 && matrix[r][w]==0){w=w+2; x++; z--; q--; s++; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();}}





//SÅ×Æ®ž®¹Ì³ë 

void Stet(void)

{blocktype=7;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][4]!=0 || matrix[4][5]!=0){gameover();}

 if(restart==1)return;

 w=5; x=6; y=4; z=5;

 p=3; q=3; r=4; s=4;

  while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[p][w]==0 && matrix[r][x]==0 && matrix[r+1][x]==0){w++; y++; p++; q=q+2; r--; rotation++; moves++;}}

  else if(rotation==2){if(matrix[p][w]==0 && matrix[q][y-1]==0 && matrix[q][y]==0){w--; x=x-2; y++; p++; r++; rotation++; moves++;}}

  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][x]==0 && matrix[p][w]==0){w--; y--; p--; q=q-2; r++; rotation++; moves++;}}

  else if(rotation==4){if(matrix[q][y]==0 && matrix[q][y+1]==0 && matrix[p][w]==0){w++; x=x+2; y--; p--; r--; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[p][w]==0 && matrix[r][x]==0 && matrix[r+1][x]==0){w++; y++; p++; q=q+2; r--; rotation++; moves++;}}

  else if(rotation==2){if(matrix[p][w]==0 && matrix[q][y-1]==0 && matrix[q][y]==0){w--; x=x-2; y++; p++; r++; rotation++; moves++;}}

  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][x]==0 && matrix[p][w]==0){w--; y--; p--; q=q-2; r++; rotation++; moves++;}}

  else if(rotation==4){if(matrix[q][y]==0 && matrix[q][y+1]==0 && matrix[p][w]==0){w++; x=x+2; y--; p--; r--; rotation=1; moves++;}}

  }

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRS¹ÌÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[p][y]==0 && matrix[r][y]==0 && matrix[r+1][w]==0){w--; x=x-2; y++; p++; r++; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[r][y]==0 && matrix[r][w]==0 && matrix[p][y-1]==0){w--; y--; p--; q=q-2; r++; rotation--; moves++;}}

 else if(rotation==3){if(matrix[r-1][w]==0 && matrix[r][y]==0 && matrix[p][y]==0){w++; x=x+2; y--; p--; r--; rotation--; moves++;}}

 else if(rotation==4){if(matrix[q][y+1]==0 && matrix[r][w]==0 && matrix[r][y]==0){w++; y++; p++; q=q+2; r--; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();}}





//ZÅ×Æ®ž®¹Ì³ë 

void Ztet(void)

{blocktype=8;

 rotation=1;

 keyboard=0;

 times=0;

 blocktouch=0;

 IsTspin=0;

 floorkick=0;

 if(matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}

 if(restart==1)return;

 w=4; x=5; y=5; z=6;

 p=3; q=3; r=4; s=4;

  while(1)

 {ghost();

 draw();

 

 //³ÀµÑ¶§

 while(!kbhit())

 {//ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêŸÒÀ» ¶§ 

 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;

 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;

 //µô·¹ÀÌž¶ŽÙ ÇÑ¹øŸ¿ ºí·Ï ³»·Á¿ÀŽÂ 

 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}

 //TœºÇÉ ±ÛÀÚ ¶á Áö 1ÃÊ ÈÄ¿¡ »ç¶óÁö°Ô ÇÏŽÂ 

 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}

 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 Sleep(1);

 totimes++;

 times++;} 

 

 //ºí·ÏÀÌ ¹ÙŽÚ¿¡ ŽêÀºÁö 1ÃÊ°¡ Áö³µÀ» ¶§ µå·Ó 

 if(blocktouch!=0 && blocktouch==totimes-1000)break;

 

 //Å°ºžµå ÀÔ·ÂÀ» ¹ÞÀœ

 keyboard=getch();



 

 //F9Å° Ž­·¶À»¶§ : ÈŠµå ŸÈÇÏ°í ¹«œÃ 

 if(keyboard==0)

 {keyboard=getch(); 

 if(keyboard==67)continue;}

 

 //c¹öÆ° Ž­·¶À»¶§

 else if(keyboard==67 || keyboard==99)

  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}



 //œºÆäÀÌœº Ž­·¶À»¶§

 else if(keyboard==32)

  {erase(); eraseghost();

  harddrop=p;

   while(1)

   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;

   p++; q++; r++; s++; moves++;}

   score=score+2*(p-harddrop);

   break;}

 

 

 

 //¹æÇâÅ° Ž­·¶À»¶§ 

 else if(keyboard==224)

 {keyboard=getch();

 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)

 {erase(); eraseghost();}

 if(keyboard==72)

 {//SRS ¹ÌÀû¿ë 

  if(rotation==1){if(matrix[p][z]==0 && matrix[r][z]==0 && matrix[r+1][x]==0){w=w+2; x++; z--; q++; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[q][y-1]==0 && matrix[s][y]==0 && matrix[s][w]==0){x--; z--; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][z]==0 && matrix[p][z]==0){w=w-2; x--; z++; q--; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[s][w]==0 && matrix[s][y]==0 && matrix[q][y+1]==0){x++; z++; p=p-2; q--; s++; rotation=1; moves++;}}

 }

 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;

 if(score<10000000)

 {gotoxy(34,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%7.0lf",score);}

 else if(score>9999999 && score<100000000)

 {gotoxy(35,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%8.0lf",score);}

 else if(score>99999999 && score<1000000000)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("%9.0lf",score);}

 else if(score>999999999)

 {gotoxy(36,16);

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 printf("999999999+");}}

 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}

 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}

 }

 

 //x¹öÆ° Ž­·¶À»¶§ : SRS¹ÌÀû¿ë

 else if(keyboard==88 || keyboard==120)

 {erase(); eraseghost();

  if(rotation==1){if(matrix[p][z]==0 && matrix[r][z]==0 && matrix[r+1][x]==0){w=w+2; x++; z--; q++; s++; rotation++; moves++;}}

  else if(rotation==2){if(matrix[q][y-1]==0 && matrix[s][y]==0 && matrix[s][w]==0){x--; z--; p=p+2; q++; s--; rotation++; moves++;}}

  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][z]==0 && matrix[p][z]==0){w=w-2; x--; z++; q--; s--; rotation++; moves++;}}

  else if(rotation==4){if(matrix[s][w]==0 && matrix[s][y]==0 && matrix[q][y+1]==0){x++; z++; p=p-2; q--; s++; rotation=1; moves++;}}

  }

 

 

 //z¹öÆ° Ž­·¶À»¶§ (¿ª¹æÇâÈžÀü) : SRS¹ÌÀû¿ë 

 else if(keyboard==90 || keyboard==122)

 {erase(); eraseghost();

 if(rotation==1){if(matrix[p][x]==0 && matrix[r][w]==0 && matrix[r+1][w]==0){x--; z--; p=p+2; q++; s--; rotation=4; moves++;}}

 else if(rotation==2){if(matrix[p][y-1]==0 && matrix[p][y]==0 && matrix[q][w]==0){w=w-2; x--; z++; q--; s--; rotation--; moves++;}}

 else if(rotation==3){if(matrix[r-1][w]==0 && matrix[r][w]==0 && matrix[p][x]==0){x++; z++; p=p-2; q--; s++; rotation--; moves++;}}

 else if(rotation==4){if(matrix[q][w]==0 && matrix[p][y]==0 && matrix[p][y+1]==0){w=w+2; x++; z--; q++; s++; rotation--; moves++;}}}

 

}//while(1)



//C¹öÆ° Ž­·¶À» ¶§ ŸÈ±×ž®°í ¹«œÃ 

 if(keyboard==67 || keyboard==99)hold();

 else{putdraw();}}









 //°ÔÀÓ¿À¹ö

 void gameover(void)

 {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);

 GOx=12; GOy=21;

 while(GOy>0)

 {while(GOx<31)

 {gotoxy(GOx,GOy);

 printf("¡á"); GOx=GOx+2;}

 GOx=12; GOy--; Sleep(100);}

 Sleep(1000); system("cls");

 gotoxy(10,10); printf("ŽÙœÃ ÇÃ·¹ÀÌÇÏœÃ°ÚœÀŽÏ±î? Y/N");

 while(1)

 {GOkey=getch();

 if(GOkey==89 || GOkey==121){restart=1; break;}

 else if(GOkey==78 || GOkey==110){exit(0);}}} 
