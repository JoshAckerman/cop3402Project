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
		ERROR();
	
	return 0;
}

void BLOCK()
{
	if( TOKEN == 28)
	{
		while(TOKEN != 17)
		{
			GETTOKEN();
			if( TOKEN != 2){ERROR();}
			GETTOKEN();
			if (TOKEN != 9 ) {ERROR();}//May be wrong
			GETTOKEN();
			if (TOKEN != 3) {ERROR();}
			GETTOKEN();
		}
		
		if (TOKEN != 18) {ERROR();}
		GETTOKEN();
		
	}

	if (TOKEN == 29)
	{
		//My be wrong
		do
		{
			GETTOKEN();
			if (TOKEN != 2) { ERROR();}
			GETTOKEN();
			//printf("%dh",TOKEN);
        }
		while(TOKEN == 17)
		{

			if (TOKEN != 18){ERROR();}
			//("%d",TOKEN);
			GETTOKEN();
        }
		
		while( TOKEN == 30)
		{
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
}

void STATEMENT()
{
	// printf("p%dj",TOKEN);
	if( TOKEN == 2)
	{
		GETTOKEN();
		if (TOKEN != 20) {ERROR();}
		GETTOKEN();
		//printf("p%dp",TOKEN);
		EXPRESSION();
		//printf("p%dp",TOKEN);
	}
	else if (TOKEN == 27)
	{
		GETTOKEN();
		if (TOKEN != 2 ){ERROR();}
		GETTOKEN();
	}
    else if (TOKEN == 21)
	{
		GETTOKEN();
		STATEMENT();
		while (TOKEN == 18)
		{
			GETTOKEN();
			STATEMENT();
		}
		//printf("f");
		if (TOKEN != 22) {ERROR();}

		GETTOKEN();
	}
	else if (TOKEN == 23)
	{
		GETTOKEN();
		CONDITION();
		if (TOKEN != 24) {ERROR();}
		GETTOKEN();
		STATEMENT();
	}
	else if (TOKEN == 25)
	{
		GETTOKEN();
		CONDITION();
		if (TOKEN != 26){ERROR();}
		GETTOKEN();
		STATEMENT();
	}
	//printf("y%dj",TOKEN);
	//printf("%d",TOKEN);
}

void CONDITION()
{

	if (TOKEN == 8)
	{
		GETTOKEN();
		EXPRESSION();
	}
	else
	{
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

void EXPRESSION()
{
	//printf("h%dh",TOKEN);
	if (TOKEN == 4)
		GETTOKEN();
	
	if(TOKEN==5)
		GETTOKEN();
	
	TERM();
	
	while (TOKEN == 4 || TOKEN == 5)
	{
		GETTOKEN();
		TERM();
	}
}

void TERM()
{
	//printf("g%dp",TOKEN);
	FACTOR();
	while (TOKEN ==6 ||TOKEN ==7 )
	{
		GETTOKEN();
		FACTOR();
	}
}

void FACTOR()
{
	//printf("i%dh",TOKEN);
	if (TOKEN == 2 )
		GETTOKEN();
	else if (TOKEN == 3)
		GETTOKEN();
	else if (TOKEN == 15)
		GETTOKEN();
		EXPRESSION();
	if(TOKEN != 16)
		ERROR();
		GETTOKEN();
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
            printf("Error 22: ");
            printf("Right parenthesis missing.\n");
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
        case 26:
            printf("Error: 26 Level is larger than the maximum allowed lexicographical levels!\n");
            break;
        default:
            break;
    }
    //printf("%d",TOKEN);
    exit(0);
}
