#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
   * new_dog - creates a new dog
    * @name: name of the dog
     * @age: age of the dog
      * @owner: owner of the dog
       * Return: pointer to the new dog, or NULL if function fails
        */
dog_t *new_dog(char *name, float age, char *owner)
{
	    dog_t *new_dog;
	        int name_len, owner_len;

		    new_dog = malloc(sizeof(dog_t));
		        if (new_dog == NULL)
				        return (NULL);

			    name_len = strlen(name) + 1;
			        owner_len = strlen(owner) + 1;

				    new_dog->name = malloc(name_len);
				        new_dog->owner = malloc(owner_len);

					    if (new_dog->name == NULL || new_dog->owner == NULL)
						        {
								        free(new_dog->name);
									        free(new_dog->owner);
										        free(new_dog);
											        return (NULL);
												    }

					        strcpy(new_dog->name, name);
						    new_dog->age = age;
						        strcpy(new_dog->owner, owner);

							    return (new_dog);
}

