#include "shell.h"

int main()
{
    char *buf = NULL, **argv, *deli = " \n";
    size_t buf_len = 0;

    while (1)
    {
		printf("$ ");
        if (getline(&buf, &buf_len, stdin) == -1)
            return (-1);
        argv = get_tokens(buf, deli);
		execute(argv);

		free(argv);
	}
}

