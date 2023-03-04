#include <stdio.h>
#include <stdlib.h>

#define ROWS	4
#define COLS	4

int pows [ROWS][COLS] = { { 1000, 1000, 1000, 1000},
                          {  900,  500,  400,  100},
                          {   90,   50,   40,   10},
                          {    9,    5,    4,    1} };

char *roms [ROWS][COLS] = { { "M","M", "M","M"},
                            {"CM","D","CD","C"},
                            {"XC","L","XL","X"},
                            {"IX","V","IV","I"} } ;

int main (int argc, char *argv[])
{
	int low;
	int high;
	char roman[25];
	
	if (argc < 2) {
		fprintf(stderr,"Usage: roman decimal_number\n");
		return;
	}
	high = low = atoi(argv[1]);
	checknum(low);
	if (argc > 2) {
		high = atoi(argv[2]);
		checknum(high);
		if (low > high) {
			fprintf(stderr, "low must be less than high\n");
			//exit(0);
		}
	} else
	    low = 1;
	
	for (; low <= high; low++) {
		to_roman(low, roman);
		printf("%d %s\n", low, roman);
	}
	
	printf ("Hello world!\n");
	
	return 0;
}

checknum(int value)
{
	if (value < 1 || value > 9999) {
		fprintf(stderr,"Use numbers in range 1 .. 9999\n");
		//exit(0);
	}
}

to_roman(int decimal, char roman[])
{
	int rom_pos = 0 ;
	int power;
	int indx;
	roman[0] = '\0';
	for (power=0; power < ROWS; power++)
		for (indx =0; indx < COLS; indx++)
			while (decimal >= pows[power][indx]){
				strcat(roman, roms[power][indx]);
				decimal -= pows[power][indx];
			}
}  
