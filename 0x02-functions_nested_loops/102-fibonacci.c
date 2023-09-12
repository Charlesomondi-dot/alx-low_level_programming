#include <stdio.h>

int main(void)
{
	    int counter;
	        int countto = 50;
		    long a = 1;
		        long b = 2;

			    // Handle the first number separately
			    printf("%li", a);

			        int charsPrinted = 1; // Initialize with the length of the first number

				    for (counter = 2; counter <= countto; counter++)
					        {
							        long temp = a + b;
								        int numLength = snprintf(NULL, 0, "%li", temp); // Calculate the length of the next number
									        charsPrinted += numLength; // Add the length of the next number

										        if (charsPrinted + numLength + 2 <= 384) // Check if there's enough space for the next number and a comma and space
												        {
														            printf(", %li", temp); // Print numbers with a comma
															                charsPrinted += 2; // Add the length of the comma and space
																	        }
											        else
													        {
															            break; // Stop if adding the next number would exceed 384 characters
																            }

												        a = b;
													        b = temp;
														    }

				        printf("\n");

					    return 0;
}

