#include "shell.h"
/**
 * custom_env - prints environment using environ
 * @ptr2: the token passed 
 *
 */
void custom_env(char **ptr2 __attribute__((unused)), char **ptr)
{
	extern char **environ;
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	free_strtow(ptr2);
	free_strtow(ptr);
}
