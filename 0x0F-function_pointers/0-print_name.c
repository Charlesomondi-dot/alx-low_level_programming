#include <stdio.h>

void print_name(char *name, void (*f)(char *)) {
	    f(name);
}

void print_with_hello(char *name) {
	    printf("Hello, %s!\n", name);
}

void print_with_greetings(char *name) {
	    printf("Greetings, %s!\n", name);
}

int main() {
	    char name[] = "Charles";

	        printf("Printing with print_with_hello function:\n");
		    print_name(name, print_with_hello);

		        printf("\nPrinting with print_with_greetings function:\n");
			    print_name(name, print_with_greetings);

			        return 0;
}

