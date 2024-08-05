#include <stdio.h>
#include <stdlib.h>

#define MAXINPUT 3

#include "printfcolor.h"
#define COLORS

typedef enum {ARITHMETIC,GEOMETRIC,PRIME,UNKNOWN} Sequence;

unsigned int i,position,count;
float raised,number,term,numbers[10];

void
getInput()
{
    printf("Kindly input ");
    printfc_fg(RED, "first three ");
    printf("numbers of sequence ");
    printfc_fg(YELLOW, "below ");
    printf("using <");
    printfc_fg(GREEN, "spacebar");
    printf("> to separate\n");
	for (i = 0; i < MAXINPUT; i++){
        if(!scanf("%f",&number)){
		printfc_fg(RED, "ERROR: ");
		printf("Unable to get input\n");
		exit(EXIT_FAILURE);
		}
        numbers[i] = number;
    }
}

unsigned int
checkPrime
(unsigned int number)
{
    count = 1;
    for(i=2; i<=number/2; i++){
        if(number%i == 0){
            count=0;
            break;
        }
    }
    if(number == 1) count = 0;
    return count;
}

Sequence
determineSequence()
{
	numbers[MAXINPUT] = numbers[MAXINPUT - 1] - numbers[MAXINPUT - 2];
	numbers[MAXINPUT + 1] = numbers[MAXINPUT - 2] - numbers[MAXINPUT - 3];
	if (numbers[MAXINPUT] == numbers[MAXINPUT + 1])return ARITHMETIC;
	numbers[MAXINPUT] = numbers[MAXINPUT - 1]/numbers[MAXINPUT - 2];
	numbers[MAXINPUT + 1] = numbers[MAXINPUT - 2]/numbers[MAXINPUT - 3];
	if (numbers[MAXINPUT] == numbers[MAXINPUT + 1])return GEOMETRIC;
	if (checkPrime((unsigned int)numbers[0]))return PRIME;
	else return UNKNOWN;
}

void
prompt()
{
	printfc_fg(MAGENTA, "Position ");
	printf("of term: ");
	if(!scanf("%u",&position)){
		printfc_fg(RED, "ERROR: ");
		printf("Unable to get input\n");
        exit(EXIT_FAILURE);
	}
}
float
raise
(float base, unsigned int exponent)
{
	raised = 1;
	for (i = 0; i < exponent; i++) raised *= base;
	return raised;
}

/*=======================WIP=======================
unsigned int
primeAtN(unsigned int number,unsigned int position)
{
	i = 0;
	while(i != position){
		if(checkPrime(number)){
			number++;
			i++;
		}
		else number++;
	}
	return number;
}
==================================================*/

int
sequencer()
{
	switch (determineSequence()){
	case ARITHMETIC:
		prompt();
		term = numbers[0] + (position - 1) * numbers[MAXINPUT];
	break;

	case GEOMETRIC:
		prompt();
		term = numbers[0] * raise(numbers[MAXINPUT],position - 1);
	break;

	case PRIME:
		prompt();
		printfc_fg(RED, "WIP:");
		printf("prime number finder not in its prime yet ;)\n");
	return 0;

	case UNKNOWN:
		printfc_fg(YELLOW, "Sorry,");
		printf(" could ");
		printfc_fg(RED, "not");
		printf("determine type of");
		printfc_fg(BLUE, " sequence\n");
	return 0;
	}

	printfc_fg(BLUE, "Term ");
	printf("is: ");
	printfc_fg(GREEN, "%g\n", term);
	return 0;
}

int
main()
{
	getInput();
	sequencer();
	return 0;
}
