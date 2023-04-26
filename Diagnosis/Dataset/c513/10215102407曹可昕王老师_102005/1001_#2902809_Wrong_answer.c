#include<stdio.h>
#include<string.h>
int main()
{
    int R,N,question,s,j,digit,len,i,k;
    char result[155],last[155];
    scanf("%d",&question);

    for(s=0;s<question;s++)
    {
        j=0;
        scanf("%d",&N);
        scanf("%d",&R);
        while(N!=0)
        {
            digit=N%R;
            if(digit>9&&digit<16)
               digit=digit-10+'A' ;
            else
                digit=digit+'0' ;
            N=N/R;
            result[j++]=digit;

        }
        result[j]='\0';
        len=strlen(result) -1;
        for(i = 0;len>=0;i++,len--)
        {
            last[i]=result[len];

        }

        last[i]='\0';
        printf("%s",last);
        printf("\n");

    }
    return 0;
}