#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	    char *str;
	        struct Node *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str) {
	    list_t *new_node = malloc(sizeof(list_t));
	        if (new_node == NULL) {
			        // Memory allocation failed
			        return NULL;
				    }

		    new_node->str = strdup(str); // Duplicate the input string
		        if (new_node->str == NULL) {
				        // strdup failed, free allocated memory and return NULL
				        free(new_node);
					        return NULL;
						    }

			    new_node->next = NULL;

			        if (*head == NULL) {
					        // If the list is empty, make the new node the head of the list
					        *head = new_node;
						    } else {
							            // Find the last node and append the new node
							            list_t *temp = *head;
								            while (temp->next != NULL) {
										                temp = temp->next;
												        }
									            temp->next = new_node;
										        }

				    return new_node;
}

int main() {
	    // Example usage of add_node_end function
	    list_t *head = NULL;

	        // Add nodes to the list
	        add_node_end(&head, "Hello");
		    add_node_end(&head, "World");
		        add_node_end(&head, "C Programming");

			    // Print the list
			    list_t *temp = head;
			        while (temp != NULL) {
					        printf("%s\n", temp->str);
						        temp = temp->next;
							    }

				    // Free the allocated memory (not shown in the provided function)
				    // ... Code to free the memory ...

				    return 0;
}

