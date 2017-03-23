#include <stdio.h>
#include <stdlib.h>

int TOKEN = 0;
int tArray[1000];
int newCount = 0;
char variableList[1000][11];
int VarNum=0;
int stack[1000]=0;
int num2=0;

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

void main3()
{
    FILE* file;
    file = fopen("i.txt","r");
    char* word = (char*)malloc(sizeof(char) * 128);
    char space[2] = " ";

    //Gets the information from the file.
    fgets(word, 128, file);
    tArray[0] = atoi(strtok(word, space));
    //printf("%d\n",tArray[0]);
    int j = 0;

   /* while(fgets(word, 128, file) != NULL)
	{
        tArray[j] = atoi(strtok(word, space));
        j++;
        //printf("%d\n",tArray[j]);
    }*/
	while( fscanf(file, "%d", TOKEN) ==1) {
            tArray[j] = TOKEN;
            if (TOKEN==2)
			{
			memset(&varName, 0, sizeof(varName));//reset unstruction
			fscanf(file, "%s", varName);
			strcpy(variableList[VarNum], varName);
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

	return 0;
}

void BLOCK()
{
	if(TOKEN == constsym)
	{
		while(TOKEN != commasym)
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR(4);
			GETTOKEN();
			if(TOKEN != eqlsym)
				ERROR(3);
			//May be wrong
			GETTOKEN();
			if(TOKEN != numbersym)
				ERROR(2);
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



		while(TOKEN == procsym)
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR(4);
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
	// printf("p%dj",TOKEN);
	if(TOKEN == identsym)
	{
		num2++;//tells where on the list of string to find current one
		GETTOKEN();
		if(TOKEN != becomessym)
			ERROR(13);
		GETTOKEN();
		//printf("p%dp",TOKEN);
		EXPRESSION();
		//printf("p%dp",TOKEN);
	}
	else if(TOKEN == callsym)
	{
		GETTOKEN();
		if (TOKEN != identsym)
			ERROR(14);
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
		GETTOKEN();
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
