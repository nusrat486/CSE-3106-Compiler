#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *kw[] = {
    "auto", "break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto", "if",
    "int", "long", "register", "return",
    "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};
int isKw(char *w)
{
    for(int i=0;i<32;i++)
        if(!strcmp(w,kw[i]))//compare kore keyword er sathe..sotto hole 1 return kore
        return 1;
    return 0;
}
int main()
{
    FILE *input=fopen("input.c","r");
    if(!input)
    {
        printf("File Error\n");
        return 1;
    }
    char w[50];
    int c;
    int n=1;
    while((c=fgetc(input))!=EOF)
          {
              if(isalpha(c))
            {
                int i=0;
                while(isalnum(c) || c=='-')
                {
                    w[i++]=c;
                    c=fgetc(input);
                }
                w[i]=0;
                if(isKw(w))
                {
                    printf("%d .%s\n",n++,w);//serial no.and keyword print
                }
            }
          }
          fclose(input);

}
