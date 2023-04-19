#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - free the memory that allocated for a struct dog.
 * @d: Struct dog --> free.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
