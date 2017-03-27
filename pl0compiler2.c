//Josh Ackerman
//Scott Mosher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Programs
//Programs
#include "pl0.c"
#include "scanner2.c"
#include "parser.c"

int main( int argc, char *argv[] )
{
    int printScanner=0;
    int printParser=0;
    int printVM=1;
    int dntdoit=0;
    if(argv[1])
    {
        if(strcmp(argv[1],"-l")==0)
        {
             printScanner=1;
        }
        else if(strcmp(argv[1],"-a")==0)
        {
            printParser=1;
        }
        else if(strcmp(argv[1],"-v")==0)
        {
            printVM=1;
        }
    }
    if(argv[2])
    {
        if(strcmp(argv[2],"-l")==0)
        {
            printScanner=1;
        }
        else if(strcmp(argv[2],"-a")==0)
        {
            printParser=1;
        }
        else if(strcmp(argv[2],"-v")==0)
        {
            printVM=1;
        }
    }
    if(argv[3])
    {
        if(strcmp(argv[3],"-l")==0)
        {
            printScanner=1;
        }
        else if(strcmp(argv[3],"-a")==0)
        {
            printParser=1;
        }
        else if(strcmp(argv[3],"-v")==0)
        {
            printVM=1;
        }
    }
    //printf("i");8
    //Main functions of programs that are scanner, parser, and vm respectively.
    //main2(printScanner);

    main2(printScanner);

    //printf("%s",pArray[0]);
    main3(printParser);

    //printf("o");
    //main3(printParser);
    //printf("p");
    main1(printVM);
}
