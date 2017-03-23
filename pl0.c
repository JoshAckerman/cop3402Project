//This is the virtual machine.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_STACK_HEIGHT 2000
#define MAX_CODE_LENGTH 500
#define MAX_LEXI_LEVELS 3

int op[MAX_CODE_LENGTH];	// opcode
int r[16]; 	// reg
int  l[MAX_CODE_LENGTH];	// L
int  m[MAX_CODE_LENGTH];	// M
int rHelp[MAX_CODE_LENGTH]; //Takes in all the registers.
int count=1;
int stack[MAX_STACK_HEIGHT];
int stackDiv[MAX_STACK_HEIGHT];
int sp = 0, bp = 1, pc = 0, ir  = 0, divCount=0;

void main1()
{
    stack[1] =0;
    stack[2] =0;
    stack[3] =0;
    stackDiv[0]=10000000;
//    printf("c");
    read();
    FILE* fw;
    fw=fopen("output.txt","w");
    fprintf(fw, "Line OP  R   L   M\n");
    int i=0, change=0;
    char word[3];
    for(i=0; i<count; i++)
    {
        //fprintf(fw, "%4d", i);
        //printf("%d\n", op[i]);
        if(op[i]==1)
        {
            strcpy(word, "lit");
        }
        else if(op[i]==2)
        {
            strcpy(word, "rtn");
        }
        else if(op[i]==3)
        {
            strcpy(word, "lod");
        }
        else if(op[i]==4)
        {
            strcpy(word, "sto");
        }
        else if(op[i]==5)
        {
            strcpy(word, "cal");
        }
        else if (op[i]==6)
        {
            strcpy(word, "inc");
        }
        else if(op[i]==7)
        {
            strcpy(word, "jmp");
        }
        else if (op[i]==8)
        {
            strcpy(word, "jpc");
        }
        else if (op[i]==9)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==10)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==11)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==12)
        {
            strcpy(word, "neg");
        }else if (op[i]==13)
        {
            strcpy(word, "add");
        }else if (op[i]==14)
        {
            strcpy(word, "sub");
        }else if (op[i]==15)
        {
            strcpy(word, "mul");
        }else if (op[i]==16)
        {
            strcpy(word, "div");
        }else if (op[i]==17)
        {
            strcpy(word, "odd");
        }else if (op[i]==18)
        {
            strcpy(word, "mod");
        }else if (op[i]==19)
        {
            strcpy(word, "eql");
        }else if (op[i]==20)
        {
            strcpy(word, "neq");
        }
        else if (op[i]==21)
        {
            strcpy(word, "les");
        }
        else if (op[i]==22)
        {
            strcpy(word, "leq");
        }else if (op[i]==23)
        {
            strcpy(word, "gtr");
        }else if (op[i]==24)
        {
            strcpy(word, "geq");
        }

        //printf("%s", word);
        fprintf(fw, "%4d %3s %3d %3d %d\n", i, word, rHelp[i], l[i], m[i]);
        //fclose(fw);
       // printf("d");
    }
    //fprintf(fw, "d");
    //printf("d");
    fprintf(fw, "Initial Values        pc bp sp\n");
    //printf("f");
//    int i;
    int halt=0;
    //printf("%d", count);
    for(i=0; i<count; i++)
    {
        //printf("%d", op[i]);
        int temp, tempI=0;
        temp=rHelp[i];

        //printf("%d", op[i]);
        //r[temp]=temp;
        if(op[i]==1)
        {
            lit(temp, i);
        }
        else if(op[i]==2)
        {
            tempI=rtn();
            stackDiv[divCount-1]=10000000;
            divCount--;
            //fprintf(fw,"\n%d", pc);
            if(pc<=0)
            {
                halt=1;
            }
        }
        else if(op[i]==3)
        {
            lod(temp, i);
        }
        else if(op[i]==4)
        {
            sto(temp, i);
        }
        else if(op[i]==5)
        {
            tempI=cal(i);
            stackDiv[divCount]=sp;
            stackDiv[divCount+1]=100000000;
            change=1;
            divCount++;
            //fprintf(fw, "change");
        }
        else if (op[i]==6)
        {
            inc(i);
        }
        else if(op[i]==7)
        {
            tempI=jmp(i);
        }
        else if (op[i]==8)
        {
            tempI=jpc(temp,i);
        }
        else if (op[i]==9)
        {
            //printf("p");
            sio1(temp);
        }
        else if (op[i]==10)
        {
            sio2(temp);
        }
        else if (op[i]==11)
        {
            halt=1;
        }
        else if (op[i]==12)
        {
            neg(temp, i);
        }else if (op[i]==13)
        {
            add(temp, i);
        }else if (op[i]==14)
        {
            sub(temp, i);
        }else if (op[i]==15)
        {
            mul(temp, i);
        }else if (op[i]==16)
        {
            divide(temp, i);
        }else if (op[i]==17)
        {
            odd(temp);
        }else if (op[i]==18)
        {
            mod(temp, i);
        }else if (op[i]==19)
        {
            eql(temp, i);
        }else if (op[i]==20)
        {
            neq(temp, i);
        }
        else if (op[i]==21)
        {
            les(temp, i);
        }
        else if (op[i]==22)
        {
            leq(temp, i);
        }else if (op[i]==23)
        {
            gtr(temp, i);
        }else if (op[i]==24)
        {
            geq(temp, i);
        }
        else
        {
            printf("tERROR");
        }
        //if(ir==0)
        pc++;
        if(op[i]==1)
        {
            strcpy(word, "lit");
        }
        else if(op[i]==2)
        {
            strcpy(word, "rtn");
        }
        else if(op[i]==3)
        {
            strcpy(word, "lod");
        }
        else if(op[i]==4)
        {
            strcpy(word, "sto");
        }
        else if(op[i]==5)
        {
            strcpy(word, "cal");
        }
        else if (op[i]==6)
        {
            strcpy(word, "inc");
        }
        else if(op[i]==7)
        {
            strcpy(word, "jmp");
        }
        else if (op[i]==8)
        {
            strcpy(word, "jpc");
        }
        else if (op[i]==9)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==10)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==11)
        {
            strcpy(word, "sio");
        }
        else if (op[i]==12)
        {
            strcpy(word, "neg");
        }else if (op[i]==13)
        {
            strcpy(word, "add");
        }else if (op[i]==14)
        {
            strcpy(word, "sub");
        }else if (op[i]==15)
        {
            strcpy(word, "mul");
        }else if (op[i]==16)
        {
            strcpy(word, "div");
        }else if (op[i]==17)
        {
            strcpy(word, "odd");
        }else if (op[i]==18)
        {
            strcpy(word, "mod");
        }else if (op[i]==19)
        {
            strcpy(word, "eql");
        }else if (op[i]==20)
        {
            strcpy(word, "neq");
        }
        else if (op[i]==21)
        {
            strcpy(word, "les");
        }
        else if (op[i]==22)
        {
            strcpy(word, "leq");
        }else if (op[i]==23)
        {
            strcpy(word, "gtr");
        }else if (op[i]==24)
        {
            strcpy(word, "geq");
        }

        if(ir==1)
        {
            sp--;
            fprintf(fw, "%4d %3s %3d %3d   %d  %d  %d  %d  ", i, word, rHelp[i], l[i], m[i], pc, bp, sp);
            sp++;
        }
        else
        {
            fprintf(fw, "%4d %3s %3d %3d   %d  %d  %d  %d  ", i, word, rHelp[i], l[i], m[i], pc, bp, sp);
        }
        //printf("%d", sp);
        int j=0, tempDiv=0, breakIt=0;
        for(j=1; j<=sp;j++)
        {
            fprintf(fw, "%d ",stack[j]);

            if(breakIt==1)
            {

            }
            else if((divCount-1)==tempDiv&&change==1)
            {

                //fprintf(fw,"\n%d", divCount);
                //fprintf(fw,"\n%d", change);
                //fprintf(fw,"\n%d", tempDiv);
                change=0;
                breakIt=1;
            }
            else if(stackDiv[tempDiv]==j)
            {
                fprintf(fw, "| ");
                tempDiv++;
                //fprintf(fw,"\n%d", divCount);
                //fprintf(fw,"\n%d", change);
               // fprintf(fw,"\n%d", tempDiv);
            }
        }
        fprintf(fw, "\n");
        if(tempI!=0)
        {
            i=tempI;
            tempI=0;
        }
        if(halt==1)
        {
            break;
        }

        //printf("c");
    }

    return 0;
}
void read()
{
    FILE* file;
    file=fopen("input.txt","r");

    char* word = (char*)malloc(sizeof(char)*128);
    char space[2] = " ";

    //Gets the information from the file.
    fgets(word, 128, file);
    op[0]=0;
    //Clears memory for the information then fills in the information.
    //char* produce = malloc(sizeof(char)*50);
    //char* type = malloc(sizeof(char)*50);
    //char* soldBy = malloc(sizeof(char)*50);
    //printf("%c", strtok(word, space));
    op[0] = atoi(strtok(word, space));
    rHelp[0] = atoi(strtok(NULL, space));
    l[0] = atoi(strtok(NULL, space));
    m[0] = atoi(strtok(NULL, space));
    //printf("%d", op[0]);
    //printf("%d", rHelp[0]);
    //printf("%d", l[0]);
    //printf("%d", m[0]);

    int j=1;
    //Loop to input all of the data obtained from the file.
    while(fgets(word, 128, file) != NULL) {
        op[j] = atoi(strtok(word, space));
        rHelp[j]= atoi(strtok(NULL, space));
        l[j] = atoi(strtok(NULL, space));
        m[j] = atoi(strtok(NULL, space));
        //printf("%d", op[j]);
        //printf("%d", rHelp[j]);
        //printf("%d", l[j]);
        //printf("%d", m[j]);
        //printf("n%d n", j);
      //  printf("\n");
        j=j+1;
        count++;
        //printf("%d\n",produce);

    }
    //printf("%d", j);
    fclose(file);
    return 0;
}
int base(l, base) // l stand for L in the instruction format
{
  int b1; //find base L levels down
  b1 = base;
  while (l > 0)
  {
    b1 = stack[b1 + 1];
    l--;
  }
  return b1;
}
void lit(int temp, int i)
{
    r[temp]=m[i];
}
void inc(int i)
{
    sp=sp+m[i];
}
int rtn()
{
    sp=bp-1;
    bp=stack[sp+3];
    pc=stack[sp+4]-1;
    sp++;
    if(pc<=0)
    {
        //pc++;
        //sp--;
        ir=1;
    }
    return pc;
    //printf("H%dH", sp+4);
    //printf("%d", stack[sp+4]);
}
void lod(int temp, int i)
{
    r[temp]=stack[base(l[i], bp)+m[i]];
}
void sto(int temp, int i)
{
    stack[base(l[i], bp)+m[i]]=r[temp];
}
int cal(int i)
{
    stack[sp+1]=0;
    stack[sp+2]=base(l[i], bp);
    stack[sp+3]=bp;
    stack[sp+4]=pc+1;
    bp=sp+1;
    pc=m[i]-1;
    return pc;
}
int jmp(int i)
{
    pc=m[i]-1;
    return pc;
}
int jpc(int temp, int i)
{
    if(r[temp]==0)
    {
        pc=m[i]-1;
        return pc;
    }
    else{
        return 0;
    }
}
void sio1(int temp)
{
    printf("%d\n", r[temp]);
}
void sio2(int temp)
{
    scanf("%d", &r[temp]);
}
void neg(int temp, int i)
{
    r[temp]=(-1)*r[l[i]];
}
void add(int temp, int i)
{
    r[temp]=r[l[i]]+r[m[i]];
}
void sub(int temp, int i)
{
    r[temp]=r[l[i]]-r[m[i]];
}
void mul(int temp, int i)
{
    r[temp]=r[l[i]]*r[m[i]];
}
void divide(int temp, int i)
{
    r[temp]=r[l[i]]/r[m[i]];
}
void odd(temp)
{
    r[temp]=r[temp]%(2);
}
void mod(temp, i)
{
    r[temp]=r[l[i]]%r[m[i]];
}
void eql(temp, i)
{
    if(r[l[i]]==r[m[i]])
    {
        r[temp]=1;
    }
    else
    {
        r[temp]=0;
    }
}
void neq(temp, i)
{
    if(r[l[i]]==r[m[i]])
    {
        r[temp]=0;
    }
    else
    {
        r[temp]=1;
    }
}
void leq(int temp, int i)
{
    if(r[l[i]]<=r[m[i]])
    {
        r[temp]=1;
    }
    else
    {
        r[temp]=0;
    }
}
void les(int temp, int i)
{
    if(r[l[i]]<r[m[i]])
    {
        r[temp]=1;
    }
    else
    {
        r[temp]=0;
    }
}
void gtr(int temp, int i)
{
    if(r[l[i]]>r[m[i]])
    {
        r[temp]=1;
    }
    else
    {
        r[temp]=0;
    }
}
void geq(int temp, int i)
{
    if(r[l[i]]>=r[m[i]])
    {
        r[temp]=1;
    }
    else
    {
        r[temp]=0;
    }
}
