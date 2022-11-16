#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MASK 0b10000000000001

int bin (unsigned int num);
int print_line (unsigned int line);

int 
main (int argc, char **argv) {
	unsigned int mask  = MASK;
	unsigned int limit = MASK;
	unsigned int line;
	
	line = limit | mask;
	print_line(line);
	
	for (int n=1;;n++) {
		mask >>= (n+1);
		if (!mask) break;
		mask |= 1;
		mask <<= n;

		line = limit | mask;
		print_line(line);
	}
	
	return 0;
}

int
print_line (unsigned int line) {
	bin(line);
}

int 
bin (unsigned int num) {
	while (num != 0) {
		if (num % 2 == 1)
			printf("%c",'*');
		else
			printf("%c",' ');
		num = num >> 1;
	}
	putchar('\n');
}
