#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    FILE *input=fopen("input.c","r");
    FILE *output=fopen("output.c","w");
    if(!input || !output)
    {
        printf("File Error\n");
        return 1;
    }
    printf("Tokens are found with their attribute values:\n");
    int ch;
    while((ch=fgetc(input))!=EOF){

              if(ch==' ' || ch=='\t'){
            continue;
          }

          if(isdigit(ch))
          {
              char num[50];
              int i=0;
              int hasDecimal=0;
              //collect the complete number
              do{
                if(ch=='.')
                    hasDecimal=1;
                num[i++]=ch;
                fputc(ch,output);
                ch=fgetc(input);
              } while(isdigit(ch) || ch=='.');
              num[i]='\0';
              //display numbers with attribute
              if(hasDecimal)
              {
                  printf("<Number , floating point value %s\n ",num);
              }
              else
              {
                  printf("<Number , integer value %s\n",num);
              }
              ungetc(ch,input);
              continue;
          }
          fputc(ch,output);


          }
          fclose(input);
          fclose(output);



}
