#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initialization of a variable of the type struct dog.
 * @d: Pointer to struct dog for initialization
 * @name: Name to initialize.
 * @age: Age to initialize.
 * @owner: Owner to initialize.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
