%{
#include<stdio.h>
int lines=0, characters=0, words=0;
}%

%%
\n lines++;
([ ])+ characters++;
\t words++;
%%

int main()
{
    FILE * file;
    char path[100];

    printf("Enter source file path:");
    scanf("%s", path);


    file = fopen(path, "r");


    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }


    yylex();

   printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);
    fclose(file);

    return 0;

}
