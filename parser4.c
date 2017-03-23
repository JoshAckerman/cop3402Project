#include <stdio.h>
#include <stdlib.h>

int TOKEN = 0;
int tArray[1000];
int count = 0;


//Allows for readability of code
typedef enum
{
    nulsym = 1, identsym, numbersym, plussym, minussym,
    multsym,  slashsym, oddsym, eqlsym, neqsym, lessym, leqsym,
    gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
    periodsym, becomessym, beginsym, endsym, ifsym, thensym,
    whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
    readsym, elsesym
} tokenType;

void main()
{
    FILE* file;
    file = fopen("i.txt","r");
    char* word = (char*)malloc(sizeof(char) * 128);
    char space[2] = " ";

    //Gets the information from the file.
    fgets(word, 128, file);
    tArray[0] = atoi(strtok(word, space));
    //printf("%d\n",tArray[0]);
    int j = 1;

    while(fgets(word, 128, file) != NULL)
	{
        tArray[j] = atoi(strtok(word, space));
        j++;
        //printf("%d\n",tArray[j]);
    }

    PROGRAM();
}

void GETTOKEN()
{
    TOKEN = tArray[count];
    //printf("%d\n",count);
    count++;
}

void PROGRAM()
{
	GETTOKEN();
	//printf("f");
	BLOCK();
	//printf("f");

	if (TOKEN != periodsym)
		ERROR();

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
				ERROR();
			GETTOKEN();
			if(TOKEN != eqlsym)
				ERROR();
			//May be wrong
			GETTOKEN();
			if(TOKEN != numbersym)
				ERROR();
			GETTOKEN();
		}

		if(TOKEN != semicolonsym)
			ERROR();

		GETTOKEN();
	}

	if(TOKEN == varsym)
	{
		//My be wrong
		do
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR();
			GETTOKEN();
			//printf("%dh",TOKEN);
        }
		while(TOKEN == commasym);


        if(TOKEN != semicolonsym)
        {
				ERROR();
        }
			//("%d",TOKEN);
        GETTOKEN();
        


		while(TOKEN == procsym)
		{
			GETTOKEN();
			if(TOKEN != identsym)
				ERROR();
			GETTOKEN();
			if(TOKEN != semicolonsym)
				ERROR();
			GETTOKEN();
			BLOCK();
			if(TOKEN != semicolonsym)
				ERROR();
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
		GETTOKEN();
		if(TOKEN != becomessym)
			ERROR();
		GETTOKEN();
		//printf("p%dp",TOKEN);
		EXPRESSION();
		//printf("p%dp",TOKEN);
	}
	else if(TOKEN == callsym)
	{
		GETTOKEN();
		if (TOKEN != identsym)
			ERROR();
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
			ERROR();

		GETTOKEN();
	}
	else if (TOKEN == ifsym)
	{
		GETTOKEN();
		CONDITION();
		if (TOKEN != thensym)
			ERROR();
		GETTOKEN();
		STATEMENT();
	}
	else if (TOKEN == whilesym)
	{
		GETTOKEN();
		CONDITION();
		if(TOKEN != dosym)
			ERROR();
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
		if (TOKEN != eqlsym)
			ERROR();
		if (TOKEN != neqsym)
			ERROR();
		if (TOKEN != lessym)
			ERROR();
		if (TOKEN != leqsym)
			ERROR();
		if (TOKEN != gtrsym)
			ERROR();
		if (TOKEN != geqsym)
			ERROR();
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
            ERROR();
		GETTOKEN();
    }
	else
		ERROR();
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
