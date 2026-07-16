#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    FILE *input=fopen("input.c","r");
    FILE *output=fopen("output.c","w");
    if (!input || !output)
    {
        printf("File Error!\n");
        return 1;
    }
    printf("Numbers found\n");
    int ch;
    while((ch=fgetc(input))!=EOF)
    {
        if(ch==' ' || ch=='\t')
        {
            continue;
        }
        //handle number
        if(isdigit(ch))
        {
            char num[50];
            int i=0;
            while(isdigit(ch) || ch=='.')
            {
                num[i++]=ch;
                fputc(ch,output);
                ch=fgetc(input);
            }
            num[i]='\0';
             printf("%s\n",num);
             //put back the last character

             ungetc(ch,input);
        }

        else{
        fputc(ch,output);
    }
    }
    fclose(input);
    fclose(output);
    return 0;

}
