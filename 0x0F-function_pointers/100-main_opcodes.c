#include <stdio.h>
#include <stdlib.h>

void print_opcodes(char *main_opcodes, int num_bytes) {
	    for (int i = 0; i < num_bytes; i++) {
		            printf("%02x", (unsigned char)main_opcodes[i]);
			            if (i < num_bytes - 1) {
					                printf(" ");
							        }
				        }
	        printf("\n");
}

int main(int argc, char *argv[]) {
	    if (argc != 2) {
		            printf("Error\n");
			            return 1;
				        }

	        int num_bytes = atoi(argv[1]);
		    if (num_bytes <= 0) {
			            printf("Error\n");
				            return 2;
					        }

		        char main_opcodes[] = {
				        0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x10, 0x89, 0x7d, 0xfc,
					        0x8b, 0x45, 0xfc, 0x83, 0xe8, 0x01, 0x89, 0x45, 0xf8, 0x8b, 0x45,
						        0xf8, 0x48, 0x98, 0x48, 0x89, 0x45, 0xf0, 0xc7, 0x45, 0xf4, 0x00,
							        0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x00, 0x00, 0xc9, 0xc3
									    };

			    print_opcodes(main_opcodes, num_bytes);

			        return 0;
}

