#include <stdio.h>
#include <stdlib.h>
void entry(FILE *fptr)
{
    char e[30], r[10], f[10];
    float s;
    printf("Enter the employ name.\n");
    gets(e);
    printf("Enter the employ role.\n");
    gets(r);
    printf("Enter the employ salray.\n");
    scanf("%f", &s);
    printf("Enter the employ feedback.\n");
    fflush(stdin);
    gets(f);
    fprintf(fptr, "%s            ", e);
    fprintf(fptr, "%s            ", r);
    fprintf(fptr, "%f            ", s);
    fprintf(fptr, "%s            ", f);
    printf("entry committed successfully.\n");
}
int main()
{
    char c[100];
    FILE *fptr;
    fptr = fopen("textfile.txt", "a+");
    if (fptr == 0)
    {
        printf("Error while loading file.\n");
        exit(0);
    }
    else
    {
        printf("file is created successfully.\n");
        fprintf(fptr, "Employ_name         role            salary          feedback.\n");
        entry(fptr);
    }
    fclose(fptr);
}