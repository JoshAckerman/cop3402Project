#include <stdio.h>
#include <stdlib.h>
int TOKEN=0;
int tArray[1000];
int count=0;
void main()
{

    FILE* file;
    file=fopen("i.txt","r");
    char* word = (char*)malloc(sizeof(char)*128);
    char space[2] = " ";

    //Gets the information from the file.
    fgets(word, 128, file);
    tArray[0]= atoi(strtok(word, space));
    //printf("%d\n",tArray[0]);
    int j=1;
    while(fgets(word, 128, file) != NULL) {
            tArray[j] = atoi(strtok(word, space));
            j++;
            //printf("%d\n",tArray[j]);
    }

    PROGRAM();
}
void GETTOKEN()
{
    TOKEN=tArray[count];
    //printf("%d\n",count);
    count++;
}
void PROGRAM()
{
                  GETTOKEN();
                  //printf("f");
                  BLOCK();
                  //printf("f");
                  if (TOKEN != 19)
                  {
                      ERROR();
                  }
                  return 0;
              }

          void BLOCK()
          {

              if( TOKEN == 28) {
                      while(TOKEN != 17){
                          GETTOKEN();
                          if( TOKEN != 2){ERROR();}
                          GETTOKEN();
                          if (TOKEN != 9 ) {ERROR();}//May be wrong
                          GETTOKEN();
                          if (TOKEN != 3) {ERROR();}
                          GETTOKEN();
                      }
                      if (TOKEN != 18) { ERROR();}
                      GETTOKEN();
          }

                  if (TOKEN == 29) {//My be wrong

                      do{

                          GETTOKEN();
                          if (TOKEN != 2) { ERROR();}
                          GETTOKEN();
                          //printf("%dh",TOKEN);
                      }while(TOKEN == 17);

                      if (TOKEN != 18){ERROR();}
                      //("%d",TOKEN);
                      GETTOKEN();

                  }
                  while( TOKEN == 30) {
                      GETTOKEN();
                      if (TOKEN != 2){ERROR();}
                      GETTOKEN();
                      if (TOKEN != 18) { ERROR();}
                      GETTOKEN();
                      BLOCK();
                      if (TOKEN != 18) {ERROR();}
                      GETTOKEN();
                  }
                  //printf("%d",TOKEN);
                  STATEMENT();
                 // printf("j");
          }

          void STATEMENT()
              {
                 // printf("p%dj",TOKEN);
                  if( TOKEN == 2) {
                      GETTOKEN();
                      if (TOKEN != 20) {ERROR();}
                      GETTOKEN();
                      //printf("p%dp",TOKEN);
                      EXPRESSION();
                      //printf("p%dp",TOKEN);
                  }
                  else if (TOKEN == 27) {
                      GETTOKEN();
                      if (TOKEN != 2 ){ERROR();}
                      GETTOKEN();
              }
                  else if (TOKEN == 21)  {
                      GETTOKEN();
                      STATEMENT();
                      while (TOKEN == 18) {

                          GETTOKEN();

                          STATEMENT();
                      }
                     //printf("f");
                      if (TOKEN != 22) {ERROR();}

                      GETTOKEN();
                  }
                  else if (TOKEN == 23)  {
                      GETTOKEN();
                      CONDITION();
                      if (TOKEN != 24) {ERROR();}
                      GETTOKEN();
                      STATEMENT();
                  }
                  else if (TOKEN == 25) {
                      GETTOKEN();
                      CONDITION();
                      if (TOKEN != 26){ERROR();}
                      GETTOKEN();
                      STATEMENT();
                  }
                  //printf("y%dj",TOKEN);
                  //printf("%d",TOKEN);
              }

          void CONDITION(){

                  if (TOKEN == 8)  {
                      GETTOKEN();
                      EXPRESSION();
                  }
                  else {
                      EXPRESSION();
                      if (TOKEN != 9)  {ERROR();}
                      if (TOKEN != 10)  {ERROR();}
                      if (TOKEN != 11)  {ERROR();}
                      if (TOKEN != 12)  {ERROR();}
                      if (TOKEN != 13)  {ERROR();}

                      if (TOKEN != 14)  {ERROR();}
                      GETTOKEN();
                      EXPRESSION();
                  }
          }

          void EXPRESSION(){
             // printf("h%dh",TOKEN);
                  if (TOKEN == 4)
                  {GETTOKEN();}
                  if(TOKEN==5)
                  {
                      GETTOKEN();
                  }
                  TERM();
                  while (TOKEN == 4|| TOKEN == 5) {
                      GETTOKEN();
                      TERM();
          }
          }

          void TERM(){
             // printf("g%dp",TOKEN);
                  FACTOR();
                  while (TOKEN ==6 ||TOKEN ==7 ) {
                      GETTOKEN();
                      FACTOR();
                  }
          }

          void FACTOR(){
//printf("i%dh",TOKEN);
                  if (TOKEN == 2 ){
                      GETTOKEN();
                  }
                  else if (TOKEN == 3){
                      GETTOKEN();
                  }
                  else if (TOKEN == 15) {
                      GETTOKEN();
                      EXPRESSION();
                      if( TOKEN != 16){ ERROR();}
                      GETTOKEN();
                  }
                  else {ERROR();}
          }
void ERROR()
{
    //printf("%d",TOKEN);
    printf("ERROR");
    exit(0);
}
