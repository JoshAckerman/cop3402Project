#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SYMBOL_TABLE_SIZE 100
int stack[MAX_SYMBOL_TABLE_SIZE];
FILE* output_file;
 FILE *file;
char LexemeTable[1000][11];
 char instruction [100];
 char instruction2 [100];
 char whatdo[3];
 int l=0;
 int m[3];
  int i=0;
 int x=0;
 int y=0;
 int counter=0;
int zident=0;
 int breaker=1, teller=0, teller2=0;
 int tempnum=0, tempnum1=0;
 int symbol_num=0;
 char then[4]="then";
 char temp[11];
 char temp2[11];
 char intToString[5];
 char printer[4000];


typedef struct
    {
	int kind; 		// const = 1, var = 2, proc = 3
	char name[11];	// name up to 11 chars
	int val; 		// number (ASCII value)
	int level; 		// L level
	int addr; 		// M address
    } symbol;

symbol symbol_table[MAX_SYMBOL_TABLE_SIZE];

void readeq(){
switch(instruction[x]){
case ';':
			 strncpy(LexemeTable[i], "18", 11);
			i++;
			m[l]++;
			//printf("seperate semi \n ");
			break;

case '+':
			strncpy(LexemeTable[i], "4", 11);
			i++;
			m[l]++;
			x++;
			break;

case '-':
			strncpy(LexemeTable[i], "5", 11);
			i++;
			m[l]++;
            x++;
			break;
case '*':
			strncpy(LexemeTable[i], "6", 11);
			i++;
			m[l]++;
			x++;
			break;
case '/':
			strncpy(LexemeTable[i], "7", 11);
			i++;
			m[l]++;
			x++;
			break;

case ':':
            if(instruction[++x]=='=')
            {

			strncpy(LexemeTable[i], "20", 11);
			i++;
			m[l]++;
			x++;
			break;
            }
 case '.':   strncpy(LexemeTable[i], "19", 11);
			i++;
			m[l]++;
			x++;
			breaker=0;
			break;
case '=':
                 strncpy(LexemeTable[i], "9", 11);
                i++;
                m[l]++;
                x++;
                break;
            case '>':
                    if (instruction[x+1]=='=')
                    {
                       strncpy(LexemeTable[i], "14", 11);
                i++;
                m[l]++;
                x=x+2;
                break;
                    }
                 strncpy(LexemeTable[i], "13", 11);
                i++;
                m[l]++;
                x++;
                break;

                case '<':
                    if (instruction[x+1]=='=')
                    {
                       strncpy(LexemeTable[i], "12", 11);
                i++;
                m[l]++;
                 x=x+2;
                break;
                    }
                    else if (instruction[x+1]=='>')
                    {
                       strncpy(LexemeTable[i], "10", 11);
                i++;
                m[l]++;
                 x=x+2;
                break;
                    }
                 strncpy(LexemeTable[i], "11", 11);
                i++;
                m[l]++;
                x++;
                break;

                case 'o':
                    if (instruction[x+1]=='d')//if it were wrong it gives error both ways so its fine
                        if (instruction[x+2]=='d')
                        if (instruction[x+3]==0)
                    {strncpy(LexemeTable[i], "8", 11);
                    x=x+3;
                i++;
                m[l]++;

                break;}



default: printf("Error invalid symbol %c", instruction[x]);
                exit(1);


}





}









void reset(){
if (instruction[x]==0)//end of the line
                {
                    memset(&instruction, 0, sizeof(instruction));//reset unstruction
                   fscanf(file, "%s", instruction);//scan next word
                 x=0;//reset first letter
               //  printf("new instruction, %s\n %d", instruction, instruction[x]);

                }



}
void readVar()
 {tempnum=0;
              if((instruction[x]>='0')&&(instruction[x]<='9'))
                {counter=0;

                    while((instruction[x]>='0')&&(instruction[x]<='9'))
                    {
                       // printf("readvar1 while");
                        tempnum=tempnum*10+instruction[x]-'0';
                        if (instruction[x]=='0')
                            zident++;
                       x++;
                       counter++;
                            if((counter>5)) {printf("Error improper number %c", instruction[x-1] );
                                        exit(1);
                                            }
                    }

                }
              else if((instruction[x]>'A')&&(instruction[x]<'z'))
              {counter=0;
              teller=0;
                  while((((instruction[x]>'A')&&(instruction[x]<'z')))||((instruction[x]>'0')&&(instruction[x]<'9')))
                  {
                      //printf("readvar2 while");
                      if((x>11))
                                    {printf("Error improper var ");
                                    exit(1);
                                    }
                      temp[x]=instruction[x];
                      x++;
                  }

                        for (y=0;y<100;y++)
				    {
				        //printf("readvar for %s \t %s\n",temp,symbol_table[y].name);

				        if ((strcmp(temp, symbol_table[y].name) == 0))
				        {teller=y+1;
				       // printf("not ma fault\n");
				       }

				    }
				    memset(&temp, 0, sizeof(temp));
				    if (teller==0)
                         {printf("Error invalid identifier  %s\n", instruction);
                exit(1);
                        }


              }
                    else
                    {printf("Error invalid identifier  %c\n", instruction[x]);
                        exit(1);
                        }

                   // strncpy(LexemeTable[i], "9", 11);
			//i++;
			//m[l]++;

			if((tempnum!=0))
                    {strncpy(LexemeTable[i], "3", 11);
                    i++;
                    m[l]++;

                    sprintf(intToString, "%d", tempnum);



                    strncpy(LexemeTable[i], intToString, 11);
                    i++;
                    m[l]++;
            memset(&intToString, 0, sizeof(intToString));
            tempnum=0;
                    }
                 else if (zident)
                 {
                     strncpy(LexemeTable[i], "3", 11);
                    i++;
                    m[l]++;
                    strncpy(LexemeTable[i], "0", 11);
                    i++;
                    m[l]++;
            memset(&intToString, 0, sizeof(intToString));
            tempnum=0;
zident=0;
                 }



                    else{
               teller--;
                        if (symbol_table[teller].kind==3)
                        {strncpy(LexemeTable[i], "2", 11);
                    i++;
                    m[l]++;
                    strncpy(LexemeTable[i], symbol_table[teller].name, 11);
                    i++;
                    m[l]++;
                        }
                        else if (symbol_table[teller].kind==2)
                        {
                          strncpy(LexemeTable[i], "2", 11);
                    i++;
                    m[l]++;
                    strncpy(LexemeTable[i], symbol_table[teller].name, 11);
                    i++;
                    m[l]++;
                        }

                        else if (symbol_table[teller].kind==1)
                        {
                            strncpy(LexemeTable[i], "2", 11);
                    i++;
                    m[l]++;
                    strncpy(LexemeTable[i], symbol_table[teller].name, 11);
                    i++;
                    m[l]++;
                        }





                    }}

int main( int argc, char *argv[] )  {
file = fopen( argv[1], "r" );
  FILE *file2 = fopen( argv[1], "r" );
    output_file = fopen( "output.txt", "w") ;

 if (file==0)
	{printf("File not found, Terminating program");
	exit(1);
	}
fscanf(file, " %s ", instruction);

	while (breaker)
	{
    //printf("main while %c\n", instruction[0]);
	x=0;
	//for (i=0;i<1000;)
	//{printf("mian 4");
	switch(instruction[0])
		{

		case '/'://just for comments
                if (instruction[1]=='*')
		for (x=2; ((instruction[x]!='*')&& (instruction[x+1]!='/'));x++)
            {
		    //printf("comment for");
		reset();



		}
            x=x+2;
            reset();
                x=0;
           // printf("instruction[o] %c\n", instruction[0]);
                break;
		case 'b':
		   // printf("ireached begin \n");
            if (instruction[1]=='e')
				{//printf("ireached e \n");
				    if (instruction[2]=='g'){
                           // printf("ireached g\n");
				if (instruction[3]=='i'){
                        //printf("ireached i \n");
				if (instruction[4]=='n'){
				   // printf("ireached n \n");
				if (instruction[5]==0)
			{l++;
			m[l]++;
			//printf("igot thru begin \n");
			strncpy(LexemeTable[i], "21", 11);
			i++;
			x=5;
			reset();
			break;
			}}}}}

		case 'c':
				if (instruction[1]=='a')
					{if (instruction[2]=='l')
					if (instruction[3]=='l')
					if (instruction[4]==0)
				{

              x=4;
              reset();


strncpy(LexemeTable[i], "27", 11);
            m[l]++;
            i++;
            readVar();
                readeq();

                reset();


                        }
                    memset(&instruction, 0, sizeof(instruction));
                    fscanf(file, " %s ", instruction);
				    break;}
		else if (instruction[1]=='o')
				if (instruction[2]=='n')
				if (instruction[3]=='s')
				if (instruction[4]=='t')
				if (instruction[5]==0)
			{
			    strncpy(LexemeTable[i], "28", 11);
                m[l]++;
                i++;
			    x=5;
			    while (instruction[x]!=';'){//this means the end
//printf("cwhile");
        reset();
         if (instruction[x]==',')
        {
        strncpy(LexemeTable[i], "17", 11);
        m[l]++;
        i++;
        x++;
        }
        reset();

        if ((instruction[x]>64)&&(instruction[x]<123))
        {
        for (y=0;((instruction[x]!=',')&&(instruction[x]!=';'));y++)
        { //printf("const for");
             reset();
            if(instruction[x]!='=')
            {
                counter++;
                temp[y]=instruction[x];
                x++;
                if ((counter>11)||((temp[y]<65)||(temp[y]>122)))
                    {

                           if (((y!=0)&&(temp[y]>='0')&&(temp[y]<='9')))
                           {
                              counter++;
                temp[y]=instruction[x];
                x++;

                        }
                       else{ printf("Error in const name %s", instruction);
                exit(1);}
                    }
            }
        if(instruction[x]=='=')
        {
            symbol_table[symbol_num].val=tempnum;
               strncpy(LexemeTable[i], "2", 11);
                m[l]++;
                i++;
strncpy(symbol_table[symbol_num].name, temp, 11);
            memset(&temp, 0, sizeof(temp));
             symbol_table[symbol_num].kind=1;
                 strncpy( LexemeTable[i],symbol_table[symbol_num].name, 11);
                 symbol_num++;
                 i++;
                 m[l]++;
            strncpy(LexemeTable[i], "9", 11);
            m[l]++;
            i++;
            x++;

              reset();
              readVar();
              //x++;
        /*for (counter=0;counter<7; counter++)
           {
    //printf("counter const for");
            if (counter==6)
            {printf("Error const too large");
                exit(1);
            }
              if((instruction[x]>'0')&&(instruction[x]<'9'))
                {
                tempnum=tempnum*10+instruction[x]-'0';

                }
                else
                    break;
                x++;
                }*/
                /*symbol_table[symbol_num].val=tempnum;
               strncpy(LexemeTable[i], "2", 11);
                m[l]++;
                i++;

                 strncpy( LexemeTable[i],symbol_table[symbol_num].name, 11);
                 symbol_num++;
                 i++;
                 m[l]++;*/
                tempnum=0;
                reset();//read the constant in to table
                //readVar();
                reset();

        }
        }
        }
        else
            {printf("invalid name");
                exit(1);
            }





			    }




memset(&instruction, 0, sizeof(instruction));
              x=0;
              fscanf(file, " %s ", instruction);
              strncpy(LexemeTable[i], "18", 11);
			i++;
			m[l]++;
			//printf("seperate semi \n ");
              break;

			}

    case 'd':
            if (instruction[1]=='o')
				if (instruction[2]==0);

                 {printf("Error Variable name is reserved for use in while loops");
                exit(1);
            }

 case 'e':
            if (instruction[1]=='l'){
				if (instruction[2]=='s')
				 if (instruction[3]=='e')
				if (instruction[4]==0)
                {printf("Error Variable name is reserved ");
                exit(1);}}
            else if (instruction[1]=='n'){
				if (instruction[2]=='d'){
                if (instruction[3]==0)
                    {l--;
                strncpy(LexemeTable[i], "22", 11);
                i++;
                m[l]++;
                    l--;
                memset(&instruction, 0, sizeof(instruction));
                x=0;
                fscanf(file, " %s ", instruction);
                    break;
                    }
			else if (instruction[3]==';')
            {
             l--;
                strncpy(LexemeTable[i], "22", 11);
                i++;
                m[l]++;
                x++;
                strncpy(LexemeTable[i], "18", 11);
                i++;
                m[l]++;
                memset(&instruction, 0, sizeof(instruction));
                x=0;
                fscanf(file, " %s ", instruction);
                break;
			}



              else if (instruction[3]=='.')
                {
                strncpy(LexemeTable[i], "22", 11);
			i++;
			m[l]++;
			x++;
			strncpy(LexemeTable[i], "19", 11);
			i++;
			m[l]++;
			x++;
			breaker=0;
			teller=0;
			break;
                }}}




        case 'i':   if (instruction[1]=='f')
				if (instruction[2]==0)
                {
                 x=2;
                 reset();
                strncpy(LexemeTable[i], "23", 11);
                m[l]++;
                i++;
                 reset();


              if (instruction[x]=='o');
              else
                readVar();
              reset();
                readeq();
                /*switch (instruction[x]){

                case '=':
                 strncpy(LexemeTable[i], "9", 11);
                i++;
                m[l]++;
                x++;
                break;
                case '>':
                    if (instruction[x+1]=='=')
                    {
                       strncpy(LexemeTable[i], "13", 11);
                i++;
                m[l]++;
                x++;
                break;
                    }
                 strncpy(LexemeTable[i], "14", 11);
                i++;
                m[l]++;
                x++;
                break;

                case '<':
                    if (instruction[x+1]=='=')
                    {
                       strncpy(LexemeTable[i], "12", 11);
                i++;
                m[l]++;
                x++;
                break;
                    }
                    else if (instruction[x+1]=='>')
                    {
                       strncpy(LexemeTable[i], "10", 11);
                i++;
                m[l]++;
                x++;
                break;
                    }
                 strncpy(LexemeTable[i], "11", 11);
                i++;
                m[l]++;
                x++;
                break;

                case 'o':
                    if (instruction[++x]=='d')//if it were wrong it gives error both ways so its fine
                        if (instruction[++x]=='d')
                        if (instruction[++x]==0)
                    {strncpy(LexemeTable[i], "8", 11);
                i++;
                m[l]++;
                break;}

                default:
                    printf("Error invalid expression ");
                exit(1);
                }*/

                  reset();
                readVar();//read second variable
                memset(&instruction, 0, sizeof(instruction));//reset cuase then is next
                  fscanf(file, " %s ", instruction);
                     x=0;
                    if ((strcmp(instruction, then) == 0))
                     {
                        strncpy(LexemeTable[i], "24", 11);
                i++;
                m[l]++;
                x++;
                reset();
                memset(&instruction, 0, sizeof(instruction));//reset cuase then is next
                  fscanf(file, " %s ", instruction);
                  x=0;
                while(instruction[x]!=';'){
                        //printf("if1while");
                readVar();

                reset();
                readeq();
                }
                x++;
                reset();
                if(instruction[x]=='e'){
                    if(instruction[x+1]=='l'){
                    if(instruction[x+2]=='s'){
                    if(instruction[x+3]=='e'){
                    if(instruction[x+4]==0)
                        {
                        strncpy(LexemeTable[i], "33", 11);
                    i++;
                    m[l]++;
                    x++;
                    reset();
                        while(instruction[x]!=';'){
                           // printf("if2while");
                    readVar();
                    reset();
                    readeq();}
                        }
                        else{;}

                        }else{;}}else{;}}else{;}}else{;}//prevents similar names from getting messed up


                    x++;
                    reset();



                     }
                    else{
                        printf("Error expected then statement ");
                exit(1);



                    }


break;



                }

       case 'p':   if (instruction[1]=='r')
				if (instruction[2]=='o')
				if (instruction[3]=='c')
				if (instruction[4]=='e')
				if (instruction[5]=='d')
				if (instruction[6]=='u')
				if (instruction[7]=='r')
				if (instruction[8]=='e')
				if (instruction[9]==0)
                {
                    x=9; reset();
                reset();
                strncpy(LexemeTable[i], "30", 11);
                m[l]++;
                i++;

                if(instruction[x]!=';')
            {
            while(instruction[x]!=';')
                {//printf("pwhile");

                    temp[x]=instruction[x];

                if ((counter>11)||((temp[x]<65)||(temp[x]>122)))
                    {
                       if((x!=0)&&((temp[x]>='0')&&(temp[x]<='9')));
                      else{
                        printf("Error in procedure name %c", instruction[x]);
                exit(1);}

                    }
                    x++;
                counter++;
                    }

                    x++;

            }
            strncpy(symbol_table[symbol_num].name, temp, 11);

            memset(&temp, 0, sizeof(temp));
             symbol_table[symbol_num].kind=3;
             symbol_table[symbol_num].level=l;
             symbol_table[symbol_num].addr=m[l];

             symbol_table[symbol_num].val=tempnum;
             strncpy(LexemeTable[i], "2", 11);
                m[l]++;
                i++;

                 strncpy( LexemeTable[i],symbol_table[symbol_num].name, 11);
                 symbol_num++;
                 i++;
                 m[l]++;
                tempnum=0;
                counter=0;
               strncpy(LexemeTable[i], "18", 11);
               x++;
               reset();
			i++;
			m[l]++;
			//printf("seperate semi \n ");
			break;

                reset();
                break;
                }

case 'o':   if (instruction[1]=='d')
				if (instruction[2]=='d')
				if (instruction[3]==0)
                {
                printf("Error reserved name ");
                exit(1);
                    }
case 'r':   if (instruction[1]=='e')
				if (instruction[2]=='a')
				if (instruction[3]=='d')
				if (instruction[4]==0)
                {
                    strncpy(LexemeTable[i], "32", 11);
                m[l]++;
                i++;
                x=4;
                reset();
                readVar();
                readeq();
                x++;
                reset();
                break;
                }

case 'v':
    //fprintf(output_file, "Lexeme Table \n ");
    if (instruction[1]=='a')
				if (instruction[2]=='r')
				if (instruction[3]==0)
                {
                    x=3;
                reset();
tempnum1=0;
             strncpy(LexemeTable[i], "29", 11);
                m[l]++;
                i++;
                counter=0;
            while(instruction[x]!=';')
                {
                   reset();
                    temp[tempnum1]=instruction[x];
                    if ((temp[tempnum1]==','))
                    { x++;//otherwise infinite oopsie
                        continue;}
                if ((counter>11)||((temp[tempnum1]<65)||(temp[tempnum1]>122)))//invalid identifier
                    {printf("Error in var name %d", temp[tempnum1]);
                exit(1);}
                    //printf("vwhile\n");
                    counter++;
                    if (instruction[x+1]==',')
                    {   // printf("got here\n");
                        temp[tempnum1]=instruction[x];
                        strncpy(symbol_table[symbol_num].name, temp, 11);//copy temp name to table


            symbol_table[symbol_num].kind=2;//set values
             symbol_table[symbol_num].level=l;
             symbol_table[symbol_num].addr=m[l];
            strncpy(LexemeTable[i], "2", 11);
                m[l]++;//increase address and i
                i++;

                 strncpy( LexemeTable[i],symbol_table[symbol_num].name, 11);//var name

                 i++;
                 m[l]++;
                symbol_num++;//doesnt increase everything gets stored in 1 spot


                   strncpy(LexemeTable[i], "17", 11);//comma
                m[l]++;
                i++;
                x++;
                tempnum1=0;
                   memset(&temp, 0, sizeof(temp));//clear temp
                reset();
                continue;
                    }

                tempnum1++;
                x++;
                reset();

                    }
if (temp[tempnum]==',')
    temp[tempnum1]=0;
else if(temp[tempnum1+1]==',')
    temp[tempnum1+1]=0;
strncpy(symbol_table[symbol_num].name, temp, 11);//basically same as for loop

                memset(&temp, 0, sizeof(temp));
            symbol_table[symbol_num].kind=2;
             symbol_table[symbol_num].level=l;
             symbol_table[symbol_num].addr=m[l];
            strncpy(LexemeTable[i], "2", 11);
                m[l]++;
                i++;

                 strncpy( LexemeTable[i],symbol_table[symbol_num].name, 11);
                 i++;
                 m[l]++;

                strncpy(LexemeTable[i], "18", 11);
                m[l]++;
                i++;

symbol_num++;
                tempnum=0;
                x++;
                reset();
                counter=0;
                break;
                }



case 'w': if (instruction[1]=='r')
				{if (instruction[2]=='i')
				if (instruction[3]=='t')
				if (instruction[4]=='e')
				if (instruction[5]==0)
            {
                   strncpy(LexemeTable[i], "31", 11);
                m[l]++;
                i++;
                x++;
                x=5;
                reset();
                readVar();
                readeq();
                x++;
                reset();
                break;
                }}
            else if (instruction[1]=='h')
				{if (instruction[2]=='i')
				if (instruction[3]=='l')
				if (instruction[4]=='e')
            if (instruction[5]==0)
            {
                strncpy(LexemeTable[i], "25", 11);
                m[l]++;
                i++;
                x++;
                x=5;
                reset();

                readVar();

                reset();
                readeq();

                reset();
                readVar();
                x++;
                reset();
                if(instruction[0]=='d')
				if (instruction[1]=='o')
                    if (instruction[2]==0)
				{
				   strncpy(LexemeTable[i], "26", 11);
                m[l]++;
                i++;
                x=2;
                reset();
				}

            }break;}
case '.': strncpy(LexemeTable[i], "19", 11);
			i++;
			m[l]++;
			x++;
			breaker=0;
			teller=0;
			break;
default: if (((instruction[x]<65)||(instruction[x]>122)))
                    {printf("Error in declaration");
                exit(1);
                    }
        else
        {

            while(instruction[x]!=';')
             {
           // printf("Error in declaration %c", instruction[x]);
                reset();
            readVar();
            reset();
            readeq();
            reset();
            }
            x++;
            reset();

        }

        reset();}

        }

























fprintf(output_file, "Source Program: \n ");
while (fgets(printer,1000, file2)!='\0')
		fputs(printer, output_file);

fprintf(output_file, " \n ");
fprintf(output_file, "Lexeme Table \n ");
fprintf(output_file, "lexeme \t token type\n ");
for(y=0;y<i;y++)
{
    if (LexemeTable[y][0]=='2')
    {
       switch(LexemeTable[y][1]){
				case '0':fprintf(output_file, ":= \t  \t 20\n");
				break;
				case '1':fprintf(output_file, "begin \t  \t 21\n");
				break;
				case '2':
				fprintf(output_file, "end \t  \t 22\n");
				break;
				case '3':
				fprintf(output_file, "if \t  \t 23\n");
				break;
				case '4':
				fprintf(output_file, "then \t  \t 24\n");
				break;
				case '5':
				fprintf(output_file, "while \t  \t 25\n");
				break;
				case '6':
				fprintf(output_file, "do \t  \t 26\n");
				break;
				case '7':
				fprintf(output_file, "call \t  \t 27\n");
				break;
				case '8':
				fprintf(output_file, "const \t  \t 28\n");
				break;
				case '9':
				fprintf(output_file, "var \t  \t 29\n");
				break;
				default:
                    y++;
                    fprintf(output_file, "%s \t  \t 2\n", LexemeTable[y]);
				break;}
    }

else if (LexemeTable[y][0]=='1')
    {
       switch(LexemeTable[y][1]){
				case '0':fprintf(output_file, "<> \t  \t 10\n");
				break;
				case '1':fprintf(output_file, "< \t  \t 11\n");
				break;
				case '2':
				fprintf(output_file, "<= \t  \t 12\n");
				break;
				case '3':
				fprintf(output_file, "> \t  \t 13\n");
				break;
				case '4':
				fprintf(output_file, ">= \t  \t 14\n");
				break;
				case '5':
				fprintf(output_file, "lparent \t  \t 15\n");
				break;
				case '6':
				fprintf(output_file, "rparent \t  \t 16\n");
				break;
				case '7':
				fprintf(output_file, ", \t  \t 17\n");
				break;
				case '8':
				fprintf(output_file, "; \t  \t 18\n");
				break;
				case '9':
				fprintf(output_file, ". \t  \t 19\n");
				break;
				default:
                    y++;
                    fprintf(output_file, "nul \t  \t 1\n");
				break;}
    }
    else if (LexemeTable[y][0]=='3')
    {
       switch(LexemeTable[y][1]){
				case '0':fprintf(output_file, "procedure \t  \t 30\n");
				break;
				case '1':fprintf(output_file, "write \t  \t 31\n");
				break;
				case '2':
				fprintf(output_file, "read \t  \t 32\n");
				break;
				case '3':
				fprintf(output_file, "else \t  \t 33\n");
				break;
				;
				default:
                    y++;
                    fprintf(output_file, "%s \t  \t 3\n", LexemeTable[y]);
				break;}
    }
 else if (LexemeTable[y][0]=='4')
 fprintf(output_file, "+ \t  \t 4\n");
     else if (LexemeTable[y][0]=='5')
     fprintf(output_file, "- \t  \t 5\n");
      else if (LexemeTable[y][0]=='6')
      fprintf(output_file, "* \t  \t 6\n");
      else if (LexemeTable[y][0]=='7')
       fprintf(output_file, "/ \t  \t 7\n");
        else if (LexemeTable[y][0]=='8')
        fprintf(output_file, "odd \t  \t 8\n");
         else if (LexemeTable[y][0]=='9')
         fprintf(output_file, "= \t  \t 9\n");}

fprintf(output_file, "Lexeme list\n");
fprintf(output_file, "%s", LexemeTable[0]);
for (x=1;x<i;x++)
{
   fprintf(output_file, ", %s", LexemeTable[x]);
}
fclose(output_file);






























return 1;

}

