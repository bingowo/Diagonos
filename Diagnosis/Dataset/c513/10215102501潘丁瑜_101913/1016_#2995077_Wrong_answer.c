#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void NtoR(int N,int R,char number[])
{
    int i=0;
    while(N != 0)
    {
        if(N%R >= 0)
        {
            if(N%R <= 9)
                number[i++]=N%R+'0';
            else
                number[i++]=N%R-10+'A';
            N=N/R;
        }
        else
        {
            if(N%R-R <= 9)
                number[i++] = ((N%R)-R) +'0';
            else
                number[i++] = (N%R)-R -10+'A';
            N=N/R+1;
        }

    }
}
int main()
{
    int N;
    int R;
    int i,j;
    char number[101]={0};
    char number2[101]={0};
    scanf("%d",&N);
    scanf("%d",&R);
    NtoR(N,R,number);
    j=strlen(number)-1;
    for(i=0;i<strlen(number);i++,j--)
        number2[i]=number[j];
    printf("%s",number2);
    return 0;
}
