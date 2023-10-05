#include <stdio.h>
#include <stdlib.h>

int is_digit(char *s) {
	    while (*s) {
		            if (*s < '0' || *s > '9') {
				                return 0;
						        }
			            s++;
				        }
	        return 1;
}

void multiply(char *num1, char *num2) {
	    int len1 = 0, len2 = 0, len, i, j, carry = 0, digit1, digit2;
	        int *result;

		    while (num1[len1]) {
			            len1++;
				        }
		        while (num2[len2]) {
				        len2++;
					    }

			    len = len1 + len2;
			        result = calloc(len, sizeof(int));
				    
				    for (i = len1 - 1; i >= 0; i--) {
					            carry = 0;
						            digit1 = num1[i] - '0';

							            for (j = len2 - 1; j >= 0; j--) {
									                digit2 = num2[j] - '0';
											            result[i + j + 1] += (digit1 * digit2 + carry);
												                carry = result[i + j + 1] / 10;
														            result[i + j + 1] %= 10;
															            }

								            result[i + j + 1] += carry;
									        }

				        if (result[0] == 0) {
						        i = 1;
							    } else {
								            i = 0;
									        }

					    for (; i < len; i++) {
						            printf("%d", result[i]);
							        }

					        printf("\n");

						    free(result);
}

int main(int argc, char *argv[]) {
	    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2])) {
		            printf("Error\n");
			            return 98;
				        }

	        multiply(argv[1], argv[2]);
		    return 0;
}

