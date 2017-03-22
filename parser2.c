#include <stdio.h>
#include <stdlib.h>
int TOKEN=0;
int tArray[1000];
int count=0;
int i=0;
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
    switch(i){
    case 1: printf("Use = instead of :=.");
     case 2: printf("= must be followed by a number.");
      case 3: printf("Identifier must be followed by =. ");
      case 4: printf("const, var, procedure must be followed by identifier.");
       case 5: printf("Semicolon or comma missing. ");
       case 6: printf("Incorrect symbol after procedure declaration. ");
       case 7: printf("Statement expected.");
       case 8: printf("Incorrect symbol after statement part in block.");
         case 9: printf("Period expected. ");
         case 10: printf("Semicolon between statements missing.");
          case 11: printf("Undeclared identifier. ");
          case 12: printf("Assignment to constant or procedure is not allowed.");
           case 13: printf("Assignment operator expected. ");
           case 14: printf("call must be followed by an identifier.");
            case 15: printf("Call of a constant or variable is meaningless. ");
            case 16: printf("then  expected. ");
            case 17: printf("Semicolon or } expected. ");
            case 18: printf("do expected. ");
            case 19: printf("Incorrect symbol following statement. ");
            case 20: printf("Relational operator expected. ");
            case 21: printf("Expression must not contain a procedure identifier. ");
            case 22: printf("Right parenthesis missing. ");
            case 23: printf("The preceding factor cannot begin with this symbol. ");
            case 24: printf("An expression cannot begin with this symbol. ");
    case 25: printf("This number is too large.");
}
    //printf("%d",TOKEN);
    printf("ERROR");
    exit(0);
}
