//Josh Ackerman
//Scott Mosher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tempTOKEN[1000];
int TOKEN = 0;
int tArray[1000];
int newCount = 0;
char variableList[1000][11];
char PrintmaStack[1000][20];
int VarNum = 0;
int pstack[1000];
int registers[16];
int curReg = 0;//note this is the current register to store in, if you want last register with an item in it curReg-1
int stackLoc = 0;
int num2 = 0;
int badTOKEN = 0;
int negate_flag=0;
int pc=0;
int decCounter = 0;//when procs are implemented this will become an array with proc number being part 1
FILE* output_file;

//Allows for readability of code
typedef enum
{
    nulsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5,
    multsym = 6,  slashsym = 7, oddsym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym = 12,
    gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17, semicolonsym = 18,
    periodsym = 19, becomessym = 20, beginsym = 21, endsym = 22, ifsym = 23, thensym = 24,
    whilesym = 25, dosym = 26, callsym = 27, constsym = 28, varsym = 29, procsym = 30, writesym = 31,
    readsym = 32, elsesym = 33
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

void main3(int printParser)
{
    FILE* file;
    file = fopen("lexemelist.txt","r");

    // char* word = (char*)malloc(sizeof(char) * 128);
    // char space[2] = " ";
    FILE* fs;
    fs=fopen("symbollist.txt", "w");
    //This make printing symbol list a lot easier(even though it doesn't look like it).
    char printToken[35][35];
    strcpy(printToken[0],"nulsym");
    strcpy(printToken[1],"identsym");
    strcpy(printToken[2],"numbersym");
    strcpy(printToken[3],"plussym");
    strcpy(printToken[4],"minussym");
    strcpy(printToken[5],"multsym");
    strcpy(printToken[6],"slashsym");
    strcpy(printToken[7],"oddsym");
    strcpy(printToken[8],"eqlsym");
    strcpy(printToken[9],"neqsym");
    strcpy(printToken[10],"lessym");
    strcpy(printToken[11],"leqsym");
    strcpy(printToken[12],"gtrsym");
    strcpy(printToken[13],"geqsym");
    strcpy(printToken[14],"lparentsym");
    strcpy(printToken[15],"rparentsym");
    strcpy(printToken[16],"commasym");
    strcpy(printToken[17],"semicolonsym");
    strcpy(printToken[18],"periodsym");
    strcpy(printToken[19],"becomessym");
    strcpy(printToken[20],"beginsym");
    strcpy(printToken[21],"endsym");
    strcpy(printToken[22],"ifsym");
    strcpy(printToken[23],"thensym");
    strcpy(printToken[24],"whilesym");
    strcpy(printToken[25],"dosym");
    strcpy(printToken[26],"callsym");
    strcpy(printToken[27],"constsym");
    strcpy(printToken[28],"varsym");
    strcpy(printToken[29],"procsym");
    strcpy(printToken[30],"writesym");
    strcpy(printToken[31],"readsym");
    strcpy(printToken[32],"elsesym");
    //Gets the information from the file.
    //fgets(word, 128, file);
    //tArray[0] = atoi(strtok(word, space));
    //printf("%d\n",tArray[0]);
    int j = 0;

    /*while(fgets(word, 128, file) != NULL)
	{
        tArray[j] = atoi(strtok(word, space));
        j++;
        //printf("%d\n",tArray[j]);
    }*/
	while(fscanf(file, "%d", &TOKEN) == 1)
	{
        //TOKEN=atoi(tempTOKEN);
        tArray[j] = TOKEN;
        if(badTOKEN==0)
        {
            fprintf(fs, "%s ", printToken[TOKEN - 1]);

        }
        else
        {
            fprintf(fs, "%d ", TOKEN);
            badTOKEN = 0;
        }
        if(TOKEN == 2)
		{
		 if (tArray[j-1]==17||tArray[j-1]==28||tArray[j-1]==29)
			decCounter++;
			//memset(&varName, 0, sizeof(varName));//reset unstruction
			fscanf(file, "%s", variableList[VarNum]);
			//printf( "%s 1", variableList[VarNum]);
			fprintf(fs, "%s ", variableList[VarNum]);
			//strcpy(variableList[VarNum], varName);
			VarNum++;
		}
		if(TOKEN == 3)
		{
			badTOKEN=1;
		}
		j++;
    }
    PROGRAM();
if(printParser==1)
    {
    output_file = fopen("output.txt","r");
    char string[100];
    int length=0;
printf("\n");
    while( fscanf(output_file, "%s", &string) ==1) {
            //length=strlen(string);
//printf("d");
            printf("%s ",string);
length++;
if(length==4)
{
length=0;
printf("\n");
}

//			j++;
    }
    fclose(output_file);
    output_file = fopen("output.txt", "w");
int i=0;
for (i=0;i<1000;i++)

{
    if (PrintmaStack[i]==0)//since printmaStack ismade of chars this would mean a null
    {
        break;//it should be impossible to get past printmaStacks current value, i.e. no value should be blank
    }
    fprintf(output_file, PrintmaStack[i]);
}



fclose(output_file);
}
printf("No errors, program is syntactically correct");
}

void GETTOKEN()
{
    //This is added because numbers were getting mixed in and I believe that was an error
    if(badTOKEN==0)
    {
        TOKEN = tArray[newCount];
    }
    else
    {
		//printf("%d",TOKEN);
		//newCount++;
		TOKEN = tArray[newCount];
		//printf("%d",TOKEN);
		//printf("%d",TOKEN);
		badTOKEN = 0;
		//GETTOKEN();
		//GETTOKEN();
		//printf("h%d",TOKEN);

    }
    if(TOKEN == numbersym)
    {
        badTOKEN = 1;
    }
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

    sprintf(PrintmaStack[pc], "11 0 0 3\n");
	pc++;
    fclose(output_file);

	return;
}

void BLOCK()
{
	stackLoc = 4;
    	sprintf(PrintmaStack[pc], "6 0 0 4\n");
		pc++;

    sprintf(PrintmaStack[pc], "6 0 0 %d\n", decCounter);
	pc++;
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

			sprintf(PrintmaStack[pc], "1 0 0 %d\n", TOKEN);
			pc++;
			sprintf(PrintmaStack[pc], "4 0 0 %d\n", stackLoc);
			pc++;
			pstack[stackLoc]=TOKEN;
			stackLoc++;

			GETTOKEN();
		}

		if(TOKEN != semicolonsym)
        {
            //printf("p");
			ERROR(5);
        }

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
			//printf("%dh",TOKEN);
			GETTOKEN();
			//printf("%dh",TOKEN);
        }
		while(TOKEN == commasym);

        if(TOKEN != semicolonsym)
        {
            //printf("h");
			ERROR(5);
        }
	}
	//("%d",TOKEN);
    GETTOKEN();



	while(TOKEN == procsym)//supposed to be an error so itll be invalid identifier
	{
		//ERROR(11);//invalid identifier, this code can be here as its unreachable
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

void STATEMENT()
{
	int temp = 0;
	int whereAmI = 0;
	// printf("p%dj",TOKEN);
	if(TOKEN == identsym)
	{
		GETTOKEN();
		if(TOKEN != becomessym)
			ERROR(13);
		GETTOKEN();
		//printf("p%dp",TOKEN);
		temp = num2;
		num2++;//tells where on the list of string to find current one
		EXPRESSION();
		whereAmI = findInStack(variableList[(temp)]) + 4;//needs legitamacy check

		curReg--;//always implemented before reaching here so it must always be decremented
		sprintf(PrintmaStack[pc], "4 %d 0 %d\n", curReg, whereAmI);
		pc++;
		temp = 0;
		STATEMENT();
		//printf("p%dp",TOKEN);
		//num2++;//tells where on the list of string to find current one
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
		//printf("%d",TOKEN);
		//printf("f");
		if(TOKEN != endsym)
        {
            //printf("%d",TOKEN);
			ERROR(8);//I don't know this error code
        }

		GETTOKEN();
	}
	else if (TOKEN == ifsym)
	{
	    int tempPC2;
	    int tempPC3;
		GETTOKEN();
		CONDITION();
		if (TOKEN != thensym)
			ERROR(16);
		GETTOKEN();
		sprintf(PrintmaStack[pc], "1 %d 0 1\n", (curReg+1));//load 1 into the register
			pc++;
		sprintf(PrintmaStack[pc], "14 %d %d %d\n", curReg, curReg, (curReg+1));//subtract 1 so the answer should be at 0
			pc++;
            sprintf(PrintmaStack[pc], "8 %d 0 %d\n", curReg, (pc+2));//jump past the jump that skips this part of the code
			pc++;
			tempPC2=pc;
		sprintf(PrintmaStack[pc], "7 0 0 %d\n",  (pc+4));//skip past this partof the code as if is not met, pc+4 is a holder
			pc++;
		EXPRESSION();
		sprintf(PrintmaStack[tempPC2], "7 0 0 %d\n",  (pc));//skip past this partof the code as if is not met
		if (TOKEN==elsesym)//else isn't mandatory so this can be skipped
        {

            sprintf(PrintmaStack[tempPC2], "7 0 0 %d\n",  (pc));//if there's an else change the skip to go to else then add a skip
            tempPC3=pc;
            sprintf(PrintmaStack[pc], "7 0 0 %d\n",  (pc));//need to reserve a spot for the jump past the else statement, the %d doesnt matter yet
            pc++;
            GETTOKEN();
            EXPRESSION();
            sprintf(PrintmaStack[tempPC3], "7 0 0 %d\n",  (pc));//end of the else statement which means this is the spot to jump to, change tempPC3
        }
	}
	else if (TOKEN == whilesym)
	{ int tempPC;//creates a local temp variable
	int tempPC1;
		GETTOKEN();
		tempPC1=pc;
		CONDITION();
		if(TOKEN != dosym)
			ERROR(18);
		GETTOKEN();
		sprintf(PrintmaStack[pc], "1 %d 0 1\n", (curReg+1));//load 1 into the register
                pc++;
            sprintf(PrintmaStack[pc], "14 %d %d %d\n", curReg, curReg, (curReg+1));//subtract 1 so the answer should be at 0
                pc++;
            sprintf(PrintmaStack[pc], "8 %d 0 %d\n", curReg, (pc+2));//jump past the jump that skips this part of the code
                pc++;
                tempPC=pc;
            sprintf(PrintmaStack[pc], "7 0 0 %d\n", (pc+5));//skip past this partof the code as if is not met
                pc++;
		EXPRESSION();//statement will loop right by when we implement proc this will cause issues.
		sprintf(PrintmaStack[tempPC], "7 0 0 %d\n", (pc));//changes to the real jump spot
		sprintf(PrintmaStack[pc], "7 0 0 %d\n", (tempPC1));//needs to go back to the original while condition could be 1 off

		//then up another 1 for the jpc another1 for the subtraction and another 1 for the load 1 to subtract finally your at the original comparison i think its 1 off
		//maybe a few need someone to double check this math it seems sketchy
		//STATEMENT();
	}
	else if (TOKEN == writesym)
	{
		GETTOKEN();
		if(TOKEN != identsym)
			ERROR(4);
		temp = findInStack(variableList[num2]);//since num2 says where in the identifier list we're up to its used here
		if (temp == num2 || temp == -1)//this means the variable wasn't found before it hit itself (or at all which would be worse)
			ERROR(11);
		//made it here means its legit now we need to tell the vm about it

		sprintf(PrintmaStack[pc], "9 %d 0 1\n", curReg);//write
		pc++;
		//sprintf(PrintmaStack[pc], "4 %d 0 %d\n", curReg,temp);//sroe what you wrote
		//pc++;
		num2++;
		GETTOKEN();
		STATEMENT();//checks for whatever comes next
	}
	else if (TOKEN == readsym)
	{
		GETTOKEN();
		if(TOKEN != identsym)
			ERROR(4);
		temp = findInStack(variableList[num2]);//since num2 says where in the identifier list we're up to its used here
		if (temp == num2 || temp == -1)//this means the variable wasn't found before it hit itself (or at all which would be worse)
			ERROR(11);
		temp = decCounter + 3 - temp;//how far from the end it has to go decCounter+4  gives stack height-temp gives distance from the end
		sprintf(PrintmaStack[pc], "10 %d 0 2\n", curReg);//this instruction is for vm only no more parsers
		pc++;
		sprintf(PrintmaStack[pc], "4 %d 0 %d\n", curReg, temp);//first load into register
		pc++;
		num2++;
		GETTOKEN();
		STATEMENT();//whats next
	}
	//printf("y%dj",TOKEN);
	//printf("%d",TOKEN);
}

void CONDITION()
{
    printf("o%do",TOKEN);
	int temp=0;
	if(TOKEN == oddsym)
	{
		GETTOKEN();
		EXPRESSION();//gets the first number
		curReg--;
		sprintf(PrintmaStack[pc], "17 %d %d 0\n", curReg, curReg);//this says odd it not positive on this one esp format
	pc++;
	}
	else
	{
		EXPRESSION();
		if (TOKEN != eqlsym && TOKEN != neqsym && TOKEN != lessym && TOKEN != leqsym && TOKEN != gtrsym && TOKEN != geqsym)
			ERROR(20);
		temp=TOKEN;
		GETTOKEN();
		EXPRESSION();
		curReg--;
		temp = temp + 10;
		sprintf(PrintmaStack[pc], "%d %d %d %d\n", temp, (curReg - 1), (curReg - 1), curReg);//you can pretty much always store it in the first register used
		pc++;
		//anyway you take the token (stored in temp as it moved on ) add 10 and you get the call value, use it and the registers determined in expression to get here
		temp=0;
		//sprintf(PrintmaStack[pc], "%d %d %d %d\n", temp, (curReg-1), (curReg-1), curReg);// not sure what else goes here, maybe used for a jump
	}
}

void EXPRESSION()
{
	int temp=0;
	printf("h%dh",TOKEN);
	if(TOKEN == plussym)
	{
		GETTOKEN();
		temp=TOKEN;
	}
	if(TOKEN == minussym&&(tArray[TOKEN-1]!=2&&tArray[TOKEN-2]!=3))//this means its a negation, set a flag to mark it and after it reads the next variable we can negate thator whatevers in the parenthesis
	{
		negate_flag =1;
		GETTOKEN();
	}

	else if(TOKEN == minussym)//needs attention in case of negations otherwise i wouldve combined this into the while loop
	{
		GETTOKEN();
		temp=TOKEN;
	}

	TERM();

	if(temp > 0)
    {
        curReg--;
        temp = temp + 9;//this gives the appropriate value for the first number, add instruction is 13 subtract 14, token values are 4 and 5 respectively
        sprintf(PrintmaStack[pc], "%d %d %d %d\n", temp, (curReg - 1), (curReg - 1), curReg);//1st is add or sub, second is where to store, 3rd is 1st value, 4th is 2nd value
        pc++;
		temp = 0;
        curReg--; //the last value is now meaningless as it
    }

	while(TOKEN == plussym || TOKEN == minussym)
	{
	    if(TOKEN == minussym&&(tArray[TOKEN-1]!=2&&tArray[TOKEN-2]!=3))//this means its a negation, set a flag to mark it and after it reads the next variable we can negate thator whatevers in the parenthesis
	{
		negate_flag =1;
		GETTOKEN();
	}
	else{
	    temp = TOKEN + 9;
		GETTOKEN();
		TERM();
		curReg--;
        temp = temp + 9;//this gives the appropriate value for the first number, add instruction is 13 subtract 14, token values are 4 and 5 respectively
        sprintf(PrintmaStack[pc], "%d %d %d %d\n", temp,(curReg-1),(curReg-1),curReg);//1st is add or sub, second is where to store, 3rd is 1st value, 4th is 2nd value

		pc++;
		temp = 0;
        curReg--; //the last value is now meaningless as it was just to store that 1value
	}}
	if(TOKEN == multsym || TOKEN == slashsym)//order of operations could have issues
        TERM();
}

void TERM()
{
	int temp = 0;
	printf("g%dp",TOKEN);
	if(TOKEN == multsym || TOKEN == slashsym)
	{
		while(TOKEN == multsym || TOKEN == slashsym)
		{
			temp=TOKEN+9;

			GETTOKEN();
			FACTOR();
			curReg--;
			temp = temp + 9;//this gives the appropriate value for the first number, mult instruction is 15 div 16, token values are 6 and 7 respectively
			sprintf(PrintmaStack[pc], "%d %d %d %d\n", temp,(curReg-1),(curReg-1),curReg);//1st is mult or div, second is where to store, 3rd is 1st value, 4th is 2nd value
			pc++;
			temp = 0;//clear temp
			curReg--; //the last value is now meaningless as it was just to store that 1 value
		}

		if (TOKEN == plussym || TOKEN == minussym)//order of operations could have issuesif negation this would send it where it needs to be
			EXPRESSION();
	}
	else
		FACTOR();
}

void FACTOR()
{
    int whereAmI = 0;
    int whereAmI2 = 0;
	printf("i%dh",TOKEN);
	if(TOKEN == identsym)
	{
		GETTOKEN();//pretty much just saying move on
		//if(tArray[newCount-1]==20&&tArray[newCount+1]>3&&tArray[newCount+1]<8)//previous is assignment next isn't a pemdas this is a 1off spot
		//{
	    //whereAmI=findInStack(variableList[(num2-1)])+4;
	    //make sure this isn't first time seeing this varaible create checker class or just
	    //if num2=whereAmI-4 send back an error, depends on how often we're checking idents for individual vs function
	    whereAmI2 = findInStack(variableList[num2]) + 4;//needs to be checked for initialization
		 if ((whereAmI2-4)==num2)
            ERROR(11);
	    sprintf(PrintmaStack[pc], "3 %d 0 %d\n", curReg, whereAmI2);//load whatever new value into the register or say we did that works too
pc++;
	   if (negate_flag==1)//if negation then turn the register that was just loaded (i.e.the one its about, negative
	{
	negate_flag=0;
	sprintf(PrintmaStack[pc], "12 %d %d 0\n", curReg, curReg);
	pc++;

	}
	    curReg++;
		//}
		num2++;
	}
	else if(TOKEN == numbersym)
	{
		GETTOKEN();//get the number
		printf("t%dt", TOKEN);
	if ((TOKEN/100,000)!=0)
            ERROR(25);
	    //whereAmI=findInStack(variableList[(num2-1)])+4;//make sure this isn't first time seeing this varaible create checker class or just
	    //if num2=whereAmI-4 send back an error, depends on how often we're checking idents for individual vs function
	    //whereAmI2=findInStack(num2)+4;//needs to be checked for initialization
	    sprintf(PrintmaStack[pc], "1 %d 0 %d\n", curReg, TOKEN);
		pc++;
		GETTOKEN();
		printf("g%dg",TOKEN);
	    curReg++;//TOKEN value doesn't need to be saved in this program thats for the vm
	    //sprintf(PrintmaStack[pc], "4 %d 0 %d\n", curReg, whereAmI);
	}

	else if(TOKEN == lparentsym)
    {
        int temp=0;
        if (negate_flag==1)//if negate is 1 going into parenthesis itll just negate the 1st variable it sees
        {
            negate_flag=0;
            temp=1;
        }

        while(TOKEN != rparentsym)//this can have more than 3 tokens inside so its necesary to keep going to get everything
		{
			GETTOKEN();
			EXPRESSION();
			if(TOKEN > 7)//this can only be numbers symbols or equation materials anything else gets caught here since its number >7
				ERROR(22);
		}
    if (temp==1)//its possible to get here with a negation active
	{
	negate_flag=0;
	temp=0;
	sprintf(PrintmaStack[pc], "12 %d %d 0\n", curReg, curReg);//this will still be the most recent register to contain anything so anything to be negated would be here
pc++;
	}
		GETTOKEN();
    }
	else{
            printf("%d",TOKEN);
		ERROR(23);
	}
}

int findInStack(char MyString[11])
{
	int i = 0;

	for(i = 0; i < 1000; i++)
		if(strcmp(MyString,variableList[i])==0)
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

    FILE* fw;
    fw = fopen("cleaninput.txt", "r");
    char string[100];
    int length = 0;

    while(fscanf(fw, "%s", &string) == 1)
	{
        length = strlen(string);
        printf("%s",string);

        if(string[length - 1] == ';')
        {
            printf("\n");
        }

        if(strcmp("begin", string) == 0)
        {
            printf("\n ");
        }

		//TOKEN=atoi(tempTOKEN);
		//tArray[j] = TOKEN;
		//Prints out symbols this if statement won't print if it is a number.

		if(badTOKEN == 0)
		{
			//fprintf(fs, "%s ", printToken[TOKEN-1]);
		}
		else
		{
			//fprintf(fs, "%d ", TOKEN);
			badTOKEN = 0;
		}

		if (TOKEN == 2)
		{
			decCounter++;
			//memset(&varName, 0, sizeof(varName));//reset unstruction
			//fscanf(file, "%s", variableList[VarNum]);
			//printf( "%s 1", variableList[VarNum]);
			//fprintf(fs, "%s ", variableList[VarNum]);
			//strcpy(variableList[VarNum], varName);
			VarNum++;
		}

		if (TOKEN == 3)
		{
			badTOKEN = 1;
		}
		//j++;
    }
    //printf("%d",TOKEN);
    exit(0);

}
