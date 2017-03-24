#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int TOKEN = 0;
int tArray[1000];
int newCount = 0;
char variableList[1000][11];
int VarNum=0;
int stack[1000]={0};
int registers[16];
int curReg=0;
int stackLoc=0;
int num2=0;
int decCounter=0;//when procs are implemented this will become an array with proc number being part 1
FILE* output_file;
//Allows for readability of code
typedef enum
{
    nulsym = 1, identsym=2, numbersym=3, plussym=4, minussym=5,
    multsym=6,  slashsym=7, oddsym=8, eqlsym=9, neqsym=10, lessym=11, leqsym=12,
    gtrsym=13, geqsym=14, lparentsym=15, rparentsym=16, commasym=17, semicolonsym=18,
    periodsym=19, becomessym=20, beginsym=21, endsym=22, ifsym=23, thensym=24,
    whilesym=25, dosym=26, callsym=27, constsym=28, varsym=29, procsym=30, writesym=31,
    readsym=32, elsesym=33
} tokenType;
void GETTOKEN();
void PROGRAM();
void BLOCK();
void STATEMENT();
void CONDITION();
void EXPRESSION();
void TERM();
void FACTOR();
int findInStack(char MyString[11]);
void ERROR(int errorCase);

void main3()
{
    FILE* file;
    file = fopen("i.txt","r");
    output_file = fopen("output.txt", "w");
   // char* word = (char*)malloc(sizeof(char) * 128);
   // char space[2] = " ";

    //Gets the information from the file.
    //fgets(word, 128, file);
   // tArray[0] = atoi(strtok(word, space));
    //printf("%d\n",tArray[0]);
    int j = 0;

   /* while(fgets(word, 128, file) != NULL)
	{
        tArray[j] = atoi(strtok(word, space));
        j++;
        //printf("%d\n",tArray[j]);
    }*/
	while( fscanf(file, "%d", &TOKEN) ==1) {
            tArray[j] = TOKEN;
            if (TOKEN==2)
			{
		    decCounter++;
			//memset(&varName, 0, sizeof(varName));//reset unstruction
			fscanf(file, "%s", variableList[VarNum]);
			//strcpy(variableList[VarNum], varName);
			VarNum++;
			}
			j++;
    }
    PROGRAM();
}

void GETTOKEN()
{
    TOKEN = tArray[newCount];
    //printf("%d\n",newCount);
    newCount++;
}

void PROGRAM()
{
	GETTOKEN();
	//printf("f");
	BLOCK();
	//printf("f");

	if (TOKEN != periodsym)
		ERROR(9);

	return;
}

void BLOCK()
{
	stackLoc=4;
    	fprintf(output_file, "6 0 0 4\n");

    	fprintf(output_file, "6 0 0 %d\n", decCounter);
	if(TOKEN == constsym)
	{
		while(TOKEN != commasym)
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR(4);
			num2++;
			GETTOKEN();
			if(TOKEN != eqlsym)
				ERROR(3);
			//May be wrong
			GETTOKEN();
			if(TOKEN != numbersym)
				ERROR(2);
			//the register to be used is first available, since this is a const declaration 0 will always be available
			//I'm unsure of how Consts work in part 2 which may require this to change

    			fprintf(output_file, "1 0 0 %d\n", TOKEN);
			fprintf(output_file, "4 0 0 %d\n", stackLoc);
			stack[stackLoc]=TOKEN;
			stackLoc++;

			GETTOKEN();
		}

		if(TOKEN != semicolonsym)
			ERROR(5);

		GETTOKEN();
	}

	if(TOKEN == varsym)
	{
		//My be wrong
		do
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR(4);
			num2++;
			GETTOKEN();
			//printf("%dh",TOKEN);
        	}
		while(TOKEN == commasym);

        if(TOKEN != semicolonsym)
        {
				ERROR(5);
        }
			//("%d",TOKEN);
        GETTOKEN();



		while(TOKEN == procsym)//supposed to be an error so itll be invalid identifier
		{
			ERROR(11);//invalid identifier, this code can be here as its unreachable
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR(4);
			num2++;
			GETTOKEN();
			if(TOKEN != semicolonsym)
				ERROR(5);
			GETTOKEN();
			BLOCK();
			if(TOKEN != semicolonsym)
				ERROR(5);
			GETTOKEN();
		}

		//printf("%d",TOKEN);
		STATEMENT();
		// printf("j");
	}
}

void STATEMENT()
{
	int temp=0;
	// printf("p%dj",TOKEN);
	if(TOKEN == identsym)
	{

		GETTOKEN();
		if(TOKEN != becomessym)
			ERROR(13);
		GETTOKEN();
		//printf("p%dp",TOKEN);
		EXPRESSION();
		//printf("p%dp",TOKEN);
		num2++;//tells where on the list of string to find current one
	}
	else if(TOKEN == callsym)
	{
		GETTOKEN();
		if (TOKEN != identsym)
			ERROR(14);
		num2++;
		GETTOKEN();
	}
    else if(TOKEN == beginsym)
	{
		GETTOKEN();
		STATEMENT();
		while(TOKEN == semicolonsym)
		{
			GETTOKEN();
			STATEMENT();
		}
		//printf("f");
		if(TOKEN != endsym)
			ERROR(8);//I don't know this error code

		GETTOKEN();
	}
	else if (TOKEN == ifsym)
	{
		GETTOKEN();
		CONDITION();
		if (TOKEN != thensym)
			ERROR(16);
		GETTOKEN();
		STATEMENT();
	}
	else if (TOKEN == whilesym)
	{
		GETTOKEN();
		CONDITION();
		if(TOKEN != dosym)
			ERROR(18);
		GETTOKEN();
		STATEMENT();
	}
	else if (TOKEN == writesym)
	{
	GETTOKEN();
	if(TOKEN != identsym)
				ERROR(4);
				temp=findInStack(variableList[num2]);//since num2 says where in the identifier list we're up to its used here
				if (temp==num2||temp==-1)//this means the variable wasn't found before it hit itself (or at all which would be worse)
				ERROR(11);
				//made it here means its legit now we need to tell the vm about it

				fprintf(output_file, "9 %d 0 1\n", curReg);//write
				fprintf(output_file, "4 %d 0 %d\n", curReg,temp);//sroe what you wrote
			num2++;
			GETTOKEN();
			STATEMENT();//checks for whatever comes next
	}
	else if (TOKEN == readsym)
	{
	GETTOKEN();if(TOKEN != identsym)
				ERROR(4);
				temp=findInStack(variableList[num2]);//since num2 says where in the identifier list we're up to its used here
				if (temp==num2||temp==-1)//this means the variable wasn't found before it hit itself (or at all which would be worse)
				ERROR(11);
				temp=decCounter+4-temp;//how far from the end it has to go decCounter+4  gives stack height-temp gives distance from the end
				fprintf(output_file, "3 %d 0 %d\n",curReg, temp);//first load into register
				fprintf(output_file, "10 %d 0 2\n", curReg);//this instruction is for vm only no more parsers
			num2++;
			GETTOKEN();
			STATEMENT();//whats next

	}
	//printf("y%dj",TOKEN);
	//printf("%d",TOKEN);
}

void CONDITION()
{
	if(TOKEN == oddsym)
	{
		GETTOKEN();
		EXPRESSION();
	}
	else
	{
		EXPRESSION();
		if (TOKEN != eqlsym &&TOKEN != neqsym&&TOKEN != lessym&&TOKEN != leqsym&&TOKEN != gtrsym&&TOKEN != geqsym)
			ERROR(20);
		GETTOKEN();
		EXPRESSION();
	}
}

void EXPRESSION()
{
	//printf("h%dh",TOKEN);
	if(TOKEN == plussym)
		GETTOKEN();

	if(TOKEN == minussym)
		GETTOKEN();

	TERM();

	while(TOKEN == plussym || TOKEN == minussym)
	{
		GETTOKEN();
		TERM();
	}
}

void TERM()
{
	//printf("g%dp",TOKEN);
	FACTOR();

	while(TOKEN == multsym ||TOKEN == slashsym)
	{
		GETTOKEN();
		FACTOR();
	}
}

void FACTOR()
{
	//printf("i%dh",TOKEN);
	if(TOKEN == identsym)
		{GETTOKEN();
	num2++;}
	else if(TOKEN == numbersym)
		GETTOKEN();
	else if(TOKEN == lparentsym)
    {
		GETTOKEN();

        EXPRESSION();

        if(TOKEN != rparentsym)
            ERROR(22);
		GETTOKEN();
    }
	else
		ERROR(23);
}

int findInStack(char MyString[11])
	{
		int i=0;

		for (i=0;i<1000;i++)
		if (strcmp(MyString,variableList[i])==0)
			return i;
	return -1;

	}
void ERROR(int errorCase)
{
    switch (errorCase)
	{
        case 1:
            printf("Error 1: Use = instead of :=.\n");
            break;
        case 2:
            printf("Error 2: = must be followed by a number.\n");
            break;
        case 3:
            printf("Error 3: Identifier must be followed by =.\n");
            break;
        case 4:
            printf("Error 4: const, var, procedure must be followed by identifier.\n");
            break;
        case 5:
            printf("Error 5: Semicolon or comma missing.\n");
            break;
        case 6:
            printf("Error 6: Incorrect symbol after procedure declaration.\n");
            break;
        case 7:
            printf("Error 7: Statement expected\n");
            break;
        case 8:
            printf("Error 8: Incorrect symbol after statement part in block.\n");
            break;
        case 9:
            printf("Error 9: Period expected.\n");
            break;
        case 10:
            printf("Error 10: Semicolon between statements missing.\n");
            break;
        case 11:
            printf("Error 11: Undeclared identifier.\n");
            break;
        case 12:
            printf("Error 12: Assignment to constant or procedure is not allowed.\n");
            break;
        case 13:
            printf("Error 13: Assignment operator expected.\n");
            break;
        case 14:
            printf("Error 14: call must be followed by an identifier\n");
            break;
        case 15:
            printf("Error 15: Call of a constant or variable is meaningless.\n");
            break;
        case 16:
            printf("Error 16: then expected\n");
            break;
        case 17:
            printf("Error 17: Semicolon or } expected\n");
            break;
        case 18:
            printf("Error 18: do expected\n");
            break;
        case 19:
            printf("Error 19: Incorrect symbol following statement.\n");
            break;
        case 20:
            printf("Error 20: Relational operator expected.\n");
            break;
        case 21:
            printf("Error 21: Expression must not contain a procedure identifier.\n");
            break;
        case 22:
            printf("Error 22: Right parenthesis missing.\n");
            break;
        case 23:
            printf("Error 23: The preceding factor cannot begin with this symbol.\n");
            break;
        case 24:
            printf("Error 24: An expression cannot begin with this symbol.\n");
            break;
        case 25:
            printf("Error 25: This number is too large.\n");
            break;
        default:
            break;
    }
    //printf("%d",TOKEN);
    exit(0);
}
