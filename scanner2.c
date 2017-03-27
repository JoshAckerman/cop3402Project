#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int stack2[100];

int main2(int printScanner) {
    int ir=0;
    int line=0;
    int cheese=100;
    int active=0;

    stack2[1]=0;
    stack2[2]=0;
    stack2[3]=0;

    FILE* file;
    file=fopen("input.txt","r");
    FILE* fw;
    fw=fopen("cleaninput.txt","w");
    FILE* ft;
    ft=fopen("lexemetable.txt","w");
    FILE* fl;
    fl=fopen("lexemelist.txt","w");
    int waitForIt=0;

    char* word = (char*)malloc(sizeof(char)*128);
//

    if(file==NULL)
        return 1;

    char character=NULL;
    char temp[12];
    int tempNum[5];
    int scount=0;
    int permaline=0;
    int something=0;
    int emergency=0;
    int tempLine=0;
    int l=0;
    char tempChar=':';
    int bE=0;
    int i=0;
    int seconded=0;
    int repeat=0;
    int d=5;
    int d4=5;
    int second=0;
    int num=0;
    int p=0;
    int w=0;
    int count=0;
    fprintf(ft,"lexeme        token type\n");
    for(ir=0; ir<11;ir++)
        {
            temp[ir]=':';
        }
        for(ir=0; ir<5;ir++)
        {
            tempNum[ir]=10000;
        }

    while(fscanf(file,"%c",&character)!=EOF)
    {

        if(d==0)
        {
            d4=0;
        }
        if(d==1)
        {
            d4=1;
        }
        d=5;

        if(character)
        {

            if(isdigit(character))
            {

                tempNum[line]=character-'0';

                line++;
                d=1;
                l=0;
            }
            else if(isspace(character))
            {


                d=2;
                if(character=='\n')
                {
                    w=1;

                    if(l==1)
                    {
                        w=2;
                    }
                    else
                    {
                        l=1;
                    }

                }
                else
                {
                    w=0;
                    something=1;
                    l=0;

                }
            }
            else if (character=='/')
            {
                d=3;

                l=0;
            }
            else if(character=='$')
            {
                printf("ERROR: Invalid Symbols");

                return 1;
            }
            else if(character=='#')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='&')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='!')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='~')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='?')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='`')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='>'&&temp[0]=='<')
            {
                temp[1]='>';

            }
            else
            {
                if(emergency==1)
                {

                }
                else
                {
                    emergency++;
                }


                if(p==0)
                {
                    temp[line]=character;
                    d=0;
                }
                else
                {
                    temp[line+1]=character;
                    p=0;
                    if(character=='=')
                    {
                        d=5;

                    }
                    else{
                            d=0;
                    }
                }

                line++;

                l=0;
            }
        }

        if(d==0)
        {
            while(fscanf(file,"%c",&character)!=EOF)
            {


                if(character)
                {
                    if(isspace(character))
                    {

                        w=0;
                        break;
                    }
                    else if(isdigit(character))
                    {

                        num=character-'0';
                        tempNum[0]=num;

                        second=1;
                        break;
                    }
                    else if(character=='$')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='#')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='&')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='!')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='~')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='?')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='`')
                    {
                        printf("ERROR: Invalid Symbols");
                        return 1;
                    }
                    else if(character=='+')
                    {
                        second=2;
                        tempChar='+';
                        break;
                    }
                    else if(character=='-')
                    {
                        second=2;
                        tempChar='-';
                        break;
                    }
                    else if(character=='*')
                    {
                        second=2;
                        tempChar='*';
                        break;
                    }
                    else if(character=='/')
                    {
                        second=2;
                        tempChar='/';
                        break;
                    }
                    else if(character=='<')
                    {

                        second=2;
                        tempChar='<';
                        break;
                    }
                    else if(character=='>'&&temp[line-1]!='<')
                    {
                        second=2;
                        if(tempChar=='<')
                        {

                        }
                        else
                        {
                            tempChar=':';
                        }
                        tempChar='>';
                        break;
                    }
                    else if(character=='='&&temp[line-1]!=':')
                    {

                        seconded=1;

                        break;
                    }
                    else if(character=='(')
                    {
                        second=2;
                        tempChar='(';
                        break;
                    }
                    else if(character==')')
                    {
                        second=2;
                        tempChar=')';
                        break;
                    }
                    else if(character==',')
                    {
                        second=2;
                        tempChar=',';
                        break;
                    }
                    else if(character==';')
                    {
                        second=2;
                        tempChar=';';
                        break;
                    }
                    else if(character=='.')
                    {
                        second=2;
                        tempChar='.';
                        break;
                    }
                    else if(character==':')
                    {
                        second=2;
                        tempChar=':';
                        break;
                    }
                    else
                    {
                        temp[line]=character;
                    }

                    line++;

                }
                if(line==12)
                {
                    w=0;
                    printf("ERROR: Name Too Long");
                    return 1;

                    break;
                }
            }


        }
        else if(d==1)
        {


            while(fscanf(file,"%c",&character)!=EOF)
            {

                if(character)
                {
                    if(isspace(character))
                    {
                        if(character=='\n')
                        {
                            w=1;
                        }
                        else
                        {
                            w=0;

                        }
                        break;
                    }
                    else if(isdigit(character))
                    {
                        tempNum[line]=character-'0';

                    }
                    else if(isalpha(character))
                    {
                        printf("ERROR: Variable does not start with letter");
                        return 1;
                        fprintf(fw,"ERROR");
                        second=1;
                        break;
                    }
                     else if(character=='$')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='#')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='&')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='!')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='~')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='?')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='`')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='+')
                    {
                        second=2;
                        tempChar='+';
                        break;
                    }
                    else if(character=='-')
                    {
                        second=2;
                        tempChar='-';
                        break;
                    }
                    else if(character=='*')
                    {
                        second=2;
                        tempChar='*';
                        break;
                    }
                    else if(character=='/')
                    {
                        second=2;
                        tempChar='/';
                        break;
                    }
                    else if(character=='<')
                    {
                        second=2;

                        tempChar='<';
                        break;
                    }
                    else if(character=='>')
                    {
                        second=2;
                        tempChar='>';
                        break;
                    }
                    else if(character=='=')
                    {
                        second=2;
                        tempChar='=';
                        break;
                    }
                    else if(character=='(')
                    {
                        second=2;
                        tempChar='(';
                        break;
                    }
                    else if(character==')')
                    {
                        second=2;
                        tempChar=')';
                        break;
                    }
                    else if(character==',')
                    {
                        second=2;
                        tempChar=',';
                        break;
                    }
                    else if(character==';')
                    {
                        second=2;
                        tempChar=';';
                        break;
                    }
                    else if(character=='.')
                    {
                        second=2;
                        tempChar='.';
                        break;
                    }
                    else if(character==':')
                    {
                        second=2;
                        tempChar=':';
                        break;
                    }
                    else
                    {
                        printf("ERROR: Invalid Symbols",character);

                        return 1;
                        temp[0]=character;
                        second=1;
                        break;
                    }
                }

                if(line==5)
                {
                    w=0;
                    printf("ERROR: Number Too Long");

                    return 1;
                }
                line++;
            }
        }
        else if(d==3)
        {
            something=1;

            fscanf(file,"%c",&character);

            if(character=='*')
            {

                while(fscanf(file,"%c",&character)!=EOF)
                {
                    if(character)
                    {
                        if(character=='*')
                        {
                            fscanf(file,"%c",&character);
                            if(character=='/')
                            {

                                break;
                            }
                             else if(character=='$')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='#')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='&')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='!')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='~')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='?')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
            else if(character=='`')
            {
                printf("ERROR: Invalid Symbols");
                return 1;
            }
                        }

                    }
                }
            }
            else{

                fprintf(fw,"/",character);
                temp[0]='/';
            }

        }
        else{

        }


        permaline=line+permaline;
        if(seconded==1)
        {

            if(temp[0]=='<')
            {
                fprintf(fw," <=");
                fprintf(ft,"<=            12\n");
                fprintf(fl,"12 ");
            }
            else if(temp[0]=='>')
            {
                fprintf(fw," >=");
                fprintf(ft,">=            14\n");
                fprintf(fl,"14 ");
            }
        }
        else if(temp[0]=='v'&&temp[1]=='a'&&temp[2]=='r'&&temp[3]==':')
        {

                    fprintf(ft,"var           29");
                    fprintf(fl,"29 ");
                    count=1;
        }
        else if(temp[0]=='o'&&temp[1]=='d'&&temp[2]=='d'&&temp[3]==':')
        {

                    fprintf(ft,"odd           8");
                    fprintf(fl,"8 ");
                    count=1;
        }
        else if(temp[0]=='+')
        {
                    fprintf(fw, " ");
                    fprintf(ft,"+             4");
                    fprintf(fl,"4 ");
                    count=1;
        }
        else if(temp[0]=='-')
        {

                    fprintf(ft,"-             5");
                    fprintf(fl,"5 ");
                    count=1;
        }
        else if(temp[0]=='*')
        {

                    fprintf(ft,"*             6");
                    fprintf(fl,"6 ");
                    count=1;
        }
        else if(temp[0]=='/')
        {

                    fprintf(ft,"/             7");
                    fprintf(fl,"7 ");
                    count=1;
        }
        else if(temp[0]=='='&&temp[1]==':')
        {

                    fprintf(ft,"=             9");
                    fprintf(fl,"9 ");
                    count=1;
        }
        else if(temp[0]=='<'&&temp[1]=='>'&&temp[2]==':')
        {

                    fprintf(ft,"<>            10");
                    fprintf(fl,"10 ");
                    count=1;
        }
        else if(temp[0]=='<'&&temp[11]==':')
        {

                    fprintf(ft,"<             11");
                    fprintf(fl,"11 ");

                    count=1;
        }
        else if(temp[0]=='<'&&temp[1]=='='&&temp[2]==':')
        {


                    bE=1;
                    fprintf(ft,"<=            12");
                    fprintf(fl,"12 ");
                    count=1;
        }
        else if(temp[0]=='>'&&temp[11]==':')
        {

                    fprintf(ft,">             13");
                    fprintf(fl,"13 ");

                    count=1;
        }
        else if(temp[0]=='>'&&temp[1]=='='&&temp[2]==':')
        {

                    bE=1;
                    fprintf(ft,">=            14");
                    fprintf(fl,"14 ");
                    count=1;
        }
        else if(temp[0]=='('&&temp[1]==':')
        {

                    fprintf(ft,"(             15");
                    fprintf(fl,"15 ");

                    count=1;
        }
        else if(temp[0]==')'&&temp[1]==':')
        {

                    fprintf(ft,")             16");
                    fprintf(fl,"16 ");

                    count=1;
        }
        else if(temp[0]==','&&temp[1]==':')
        {

                    fprintf(ft,",             17\n");
                    fprintf(fl,"17 ");
                    count=1;
        }
        else if(temp[0]==';'&&temp[1]==':')
        {


                    fprintf(ft,";             18\n");
                    fprintf(fl,"18 ");
                    count=1;
        }
        else if(temp[0]=='.'&&temp[1]==':')
        {

                    fprintf(ft,".             19");
                    fprintf(fl,"19 ");
                    waitForIt=1;
                    count=1;
        }
        else if(temp[0]==':'&&temp[1]=='='&&temp[2]==':')
        {

                    fprintf(fw," :=");
                    i=1;
                    fprintf(ft,":=            20");
                    fprintf(fl,"20 ");
                    count=1;
        }
        else if(temp[0]=='b'&&temp[1]=='e'&&temp[2]=='g'&&temp[3]=='i'&&temp[4]=='n'&&temp[5]==':')
        {
                    waitForIt=2;
                    fprintf(ft,"begin         21");
                    fprintf(fl,"21 ");
                    count=1;
        }
        else if(temp[0]=='e'&&temp[1]=='n'&&temp[2]=='d'&&temp[3]==':')
        {

                    fprintf(ft,"end           22");
                    fprintf(fl,"22 ");
                    waitForIt=1;
                    count=1;
        }
        else if(temp[0]=='i'&&temp[1]=='f'&&temp[2]==':')
        {

                    fprintf(ft,"if            23");
                    fprintf(fl,"23 ");
                    count=1;
        }
        else if(temp[0]=='t'&&temp[1]=='h'&&temp[2]=='e'&&temp[3]=='n'&&temp[4]==':')
        {

                    fprintf(ft,"then          24");
                    fprintf(fl,"24 ");
                    count=1;
        }
        else if(temp[0]=='w'&&temp[1]=='h'&&temp[2]=='i'&&temp[3]=='l'&&temp[4]=='e'&&temp[5]==':')
        {

                    fprintf(ft,"while         25");
                    fprintf(fl,"25 ");
                    count=1;
        }
        else if(temp[0]=='d'&&temp[1]=='o'&&temp[2]==':')
        {

                    fprintf(ft,"do            26");
                    fprintf(fl,"26 ");
                    count=1;
        }
        else if(temp[0]=='c'&&temp[1]=='a'&&temp[2]=='l'&&temp[3]=='l'&&temp[4]==':')
        {

                    fprintf(ft,"call          27");
                    fprintf(fl,"27 ");
                    count=1;
        }
        else if(temp[0]=='c'&&temp[1]=='o'&&temp[2]=='n'&&temp[3]=='s'&&temp[4]=='t'&&temp[5]==':')
        {

                    fprintf(ft,"const         28");
                    fprintf(fl,"28 ");
                    count=1;
        }
        else if(temp[0]=='p'&&temp[1]=='r'&&temp[2]=='o'&&temp[3]=='c'&&temp[4]=='e'&&temp[5]=='d'&&temp[6]=='u'&&temp[7]=='r'&&temp[8]=='e'&&temp[9]==':')
        {

                    fprintf(ft,"procedure     30");
                    fprintf(fl,"30 ");
                    count=1;
        }
        else if(temp[0]=='w'&&temp[1]=='r'&&temp[2]=='i'&&temp[3]=='t'&&temp[4]=='e'&&temp[5]==':')
        {

                    fprintf(ft,"write         31");
                    fprintf(fl,"31 ");
                    count=1;
        }
        else if(temp[0]=='r'&&temp[1]=='e'&&temp[2]=='a'&&temp[3]=='d'&&temp[4]==':')
        {

                    fprintf(ft,"read          32");
                    fprintf(fl,"32 ");
                    count=1;
        }
        else if(temp[0]=='e'&&temp[1]=='l'&&temp[2]=='s'&&temp[3]=='e'&&temp[4]==':')
        {

                    fprintf(ft,"else          33");
                    fprintf(fl,"33 ");
                    count=1;
        }

        if(i==0&&seconded==0)
        {
        for(ir=0; ir<line;ir++)
        {

            if(d==0)
            {
                if(waitForIt==3)
                {
                    fprintf(fw,"       %c",temp[ir]);
                    waitForIt=4;
                }
                else
                {
                    fprintf(fw,"%c",temp[ir]);
                }

                if(second==1&&line-ir==1)
                {
                    if(waitForIt==3)
                    {
                        fprintf(fw,"\n        %d",tempNum[0]);
                    }
                    else
                    {
                        fprintf(fw,"\n%d",tempNum[0]);
                    }
                }
            }
            if(d==1)
            {
                fprintf(fw,"%d",tempNum[ir]);

                if(second==1)
                {
                    if(waitForIt==3)
                    {
                        fprintf(fw,"\n       %c",temp[0]);
                    }
                    else
                    {fprintf(fw,"\n%c",temp[0]);
                    }
                }
            }


        }
        }
        else
        {
            i=0;
        }

        if(d==0&&count==0&&temp[0]!='<'&&temp[0]!='>')
        {
            fprintf(fl,"2 ");
        }
        else if(d==1)
        {
            fprintf(fl,"3 ");
        }

        if(temp[0]=='<'&&count==0)
        {
                    if(seconded==0)
                    {
                        fprintf(ft,"<             11\n");
                        fprintf(fl,"11 ");
                    }

                    count=1;
        }
        if(temp[0]=='>'&&count==0)
        {

            if(seconded==0)
            {
                    fprintf(ft,">             13\n");
                    fprintf(fl,"13 ");
            }

                    count=1;
        }

        for(ir=0; ir<line;ir++)
        {

            if(count==0&&d==0)
            {
                fprintf(ft,"%c", temp[ir]);
                fprintf(fl,"%c", temp[ir]);
                active=1;
            }
            else if(d==1)
            {
                fprintf(ft,"%d",tempNum[ir]);
                fprintf(fl,"%d",tempNum[ir]);
                active=1;

            }
        }

        if(active==1)
        {
            fprintf(fl," ");
            active=0;
        }
        if(bE==1)
        {
            fprintf(fw,"=");
            bE=0;
        }

        for(ir=0; ir<11;ir++)
        {
            temp[ir]=':';
        }
        for(ir=0; ir<5;ir++)
        {
            tempNum[ir]=10000;
        }


        if(w==1)
        {

            for(ir=permaline-3; ir<11;ir++)
            {
                if(count==0&&(d==0||d4==0))
                {
                }
                else if(count==0&&(d==1||d4==1))
                {
                    if(scount==5)
                    {
                        scount++;
                    }
                    else{

                    }
                }
            }
            if(count==0&&(d==0||d4==0))
            {

            }
            if(count==0&&(d==1||d4==1))
            {

            }

            if(waitForIt==3)
            {
                fprintf(fw, "       \n");
            }
            else
            {
                fprintf(fw,"\n");
            }


            count=0;
            permaline=0;
        }
        else if(w==2)
        {

        }
        else
        {

            if(something==0)
            {

            for(ir=permaline-3; ir<11;ir++)
            {
                if(count==0&&(d==0||d4==0))
                {
                    fprintf(ft," ", temp[ir]);
                }
                else if(d==1||d4==1)
                {
                    if(scount==5)
                    {
                        scount++;
                    }
                    else{
                        fprintf(ft," ",tempNum[ir]);
                    }
                }
            }

            if(count==0&&(d==0))
            {

            }
            else if(d==1)
            {

            }
            else if(waitForIt==1)
            {

            }
            else if(waitForIt==2)
            {
                fprintf(fw, "\n");
                waitForIt=3;
            }
            else
            {
                fprintf(fw, " ");
            }

            {

                {


                    if(count==0&&(d==0))
                    {
                        fprintf(ft,"2",count);
                    }
                    if(d==1)
                    {
                        fprintf(ft,"3");
                    }
                    fprintf(ft,"\n");
                }
            }

            permaline++;

            permaline=0;
            }
            else
            {
                something=0;
            }
        }

        if(second==2)
        {
                    if(tempChar=='+')
                    {
                        fprintf(ft,"+             4\n");
                        fprintf(fl,"4 ");
                    }
                    else if(tempChar=='-')
                    {
                        fprintf(ft,"-             5\n");
                        fprintf(fl,"5 ");
                    }
                    else if(tempChar=='*')
                    {
                        fprintf(ft,"*             6\n");
                        fprintf(fl,"6 ");
                    }
                    else if(tempChar=='/')
                    {
                        temp[0]=tempChar;
                        line=1;
                    }
                    else if(tempChar=='<')
                    {
                        temp[0]=tempChar;

                        line=1;
                    }
                    else if(tempChar=='>')
                    {
                        temp[0]=tempChar;

                        line=1;
                    }
                    else if(tempChar=='=')
                    {
                        fprintf(ft,"=             9\n");
                        fprintf(fl,"9 ");
                    }
                    else if(tempChar=='(')
                    {
                        fprintf(ft,"(             15\n");
                        fprintf(fl,"15 ");
                    }
                    else if(tempChar==')')
                    {
                        fprintf(ft,")             16\n");
                        fprintf(fl,"16 ");
                    }
                    else if(tempChar==',')
                    {
                        fprintf(fw, ", ");
                        fprintf(ft,",             17\n");
                        fprintf(fl,"17 ");
                    }
                    else if(tempChar==';')
                    {
                        if(waitForIt==4)
                        {
                            waitForIt=3;
                        }
                        fprintf(fw,";");
                        fprintf(ft,";             18\n");
                        fprintf(fl,"18 ");
                    }
                    else if(tempChar=='.')
                    {
                        fprintf(fw,".");
                        fprintf(ft,".             19\n");
                        fprintf(fl,"19 ");
                    }
                    else if(tempChar==':')
                    {
                        temp[0]=tempChar;
                        line=1;
                        p=1;
                    }
        }
        scount=0;



        seconded=0;

        w=0;
        line=0;
        second=0;
        count=0;
    }
    fclose(fl);
fclose(file);
fclose(fw);
if(printScanner==1)
    {
    fl = fopen("lexemelist.txt","r");
    char string[100];
    int length=0;
    while( fscanf(fl, "%s", &string) ==1) {
            //length=strlen(string);
            printf("%s ",string);

//			j++;
    }
    fclose(fl);
    
    }
    return 0;
}
