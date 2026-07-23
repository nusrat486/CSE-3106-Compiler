
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isDataType(char *w)
{
    char *t[]={"int","float","char","double","long"};
    for(int i=0;i<5;i++)
    {
        if(!strcmp(w,t[i]))
            return 1;
    }
    return 0;
}
int main()
{
    FILE *input=fopen("input.c","r");
    if(!input){
                    printf("File Error\n");
        return 1;
}
    char w[50],var[100][50];
    int c,i=0,flag=0,n=0;

    printf("Variables\n");
    while((c=fgetc(input))!=EOF)
    {
        if(isalpha(c) || c=='_')
        {
            i=0;
            while (isalnum(c) || c=='_')
            {
                w[i++]=c;
                c=fgetc(input);
            }
            w[i]=0;//word er last a 0 rekhe disi
            if (isDataType(w))
                flag=1;
                else if(flag && c!='(')//datatype er porei variavble ba function thake seta ikhne check hocche
                {
                    int dup=0;//eta mane duplicate kina check korbe.mane a variable 2 bar thakle 1 bar print hobe
                    for(int j=0;j<n;j++)
                        if(!strcmp(var[j],w))
                    dup=1;
                    if(!dup)
                    {
                        strcpy(var[n++],w);
                        printf("%s\n",w);
                    }
                }
                if(c==';')
                    flag=0;

        }
        if(c==';')
            flag=0;
    }
    fclose(input);
    return 0;

}
