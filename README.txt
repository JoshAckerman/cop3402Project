HW3 Parsecodegen by Josh Ackerman
		    Scott Mosher
		    Steven Campbell
      
      
To start the program you have to have an input that follows the rules of assignment 2 which
 goes into the scanner, if there are any constants they must be declared 1st with their initial value, 
next declare variables before begining the program,you can declare up to 500 variables which begin with 
a letter and are shorter than 12 characters, numbers must also be between 99,999 and -99999
(total is combined with consts).but this is highly discouraged, this is a small machine. 
The code can read a variable from the screen if given a "read" command  but otherwise will only read 
from the file, similarly it can write on the screen if given a "write" command otherwise everything 
is stored in files. if you want to storea variable use a ":=".The symbols =, >, >=, <, <=, <>, and odd,
can be used in if statements or while loops. for an if statement put if followed by the condition 
you which to happen, followed by a then which precedes the action to happen after the action the then activates 
an else can be placed, though it is not required, the else will activate if the if condition is not met.
 for a while loop begin with a while then your condition followed by do followed by the action you wish to 
occur (generally an equation). lastly there's proc calls a proc is declared initially right before the actions 
that is supposed to occur, if you want to go back to a proc call (you can only call a proc for something that 
the code has read) just put call (proc name), once the proc finishes it should hit an end/rtn which will tell it to 
go back to where it came from once the code is complete make sure there's an "end" and a "."  as without it there 
will be an error, also make sure that the const and var declarations end in a semicolon. Once all the code is 
there the scanner will catch a few error but let most pass as it turns the code into numbers before storing it
and passing it on to the parser.

The parser takes the code from the scanner and checks it for errors, if it finds one it stops the code 
and prints out what it found. otherwise it takes the code and turns it into assembly code leaving out
some of the details it may have had in its previous life but allowing the pm0 machine to do its work,
the code is stored in a new file where the pm0 machine picks it up

the pm0 machine takes assembly given out by the parser and uses it to do the actions originally 
requested all the way back in the scanner. it stores the result of this in its own outputfile


 READ THIS
in order to do this use the instructions gcc -o d pl0compiler2.c (where d is whatever you want)
afterwards use ./d -l -a -v in order to run everything, -l shows scanner, -a parser and -v vm.
Make sure to check out input, finaloutput, output, and lexemelist text files.
