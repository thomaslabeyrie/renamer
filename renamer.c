#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Downcases all letters and replaces space with underscores
char* format(const char* name)
{
    int length = strlen(name);
    char* formatted = malloc(length + 1);

    if (!formatted)
    {
        perror("malloc");
        exit(1);
    }
    
    for (int i = 0; i < length; i++)
    {
        if (name[i] == ' ')
        {
            formatted[i] = '_';
        }
        else
        {
            formatted[i] = tolower(name[i]);
        }
    }

    formatted[length] = '\0';
    return formatted;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./renamer file\n");
        return 1;
    }

    char* old_name = argv[1];
    char* new_name = format(old_name);

    if (strcmp(old_name, new_name) == 0)
    {
        printf("File name is already formatted.\n");
    }
    else if (rename(old_name, new_name) == 0)
    {
        printf("File renamed: %s\n", new_name);
    }
    else
    { 
        perror("Error");
    }

    free(new_name);
}
