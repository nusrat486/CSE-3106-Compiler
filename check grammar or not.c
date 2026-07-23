/*grammar=S->aAb|bBA//a diye suru hole onk a thate pare kintu ses hobe b diye.r b diye suru hole ses hobe a diye
A->aA|e
B->bB | e
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int belongsToGrammar(char str[])
{
    int len =strlen(str);
    int i=0;
    //case1:S->aAb
    if(str[i]=='a')
    {
        i++;
        while(str[i]=='a')
            i++;
        //must have a b at the end
        if(str[i]=='b' && i==len-1)
            return 1;
    }
    //case2:S->bBA
    else if(str[i]=='b')
    {
        i++;
        //B->bB (skip all 'b'
        while(str[i]=='b')
                 i++;
                 //A->aA(skip all 'a'
            while(str[i]=='a')
                i++;
            //should end after all 'a'
            if(i==len)
                return 1;

    }
    return 0;

}
int main()
{
    char str[100];
    printf("Grammar\n S->aAb | BbA\nA->aA|ε\nB->bB|ε\n");
    scanf("%s",str);
    if(belongsToGrammar(str))
        printf("Belongs to the grammar\n");
    else
        printf("Not belongs to grammar\n");
    return 0;
}
