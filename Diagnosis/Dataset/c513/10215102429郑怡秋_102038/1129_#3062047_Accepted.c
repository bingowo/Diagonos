#include <stdio.h>
#include <stdlib.h>
int main()
{
    char A[15000];
    int i=0;
    char c;
    while(1)
    {
        c=getchar();
        int temp=c-'0';

        if(isalpha(c))
        {
            A[i++]=c;
        }
        else if(isdigit(c))
        {
            while(isdigit(c=getchar())) temp=temp*10+(c-'0');
            ungetc(c,stdin);
            A[i]="\0";
            for(int j=0;j<temp;j++) for(int k=0;k<i;k++) printf("%c",A[k]);
            i=0;
            memset(A,0,sizeof(A));
        }
        else
        {
            if(A[0]!='0') printf("%s",A);
            printf("\n");
            break;
        }
    }
    return 0;
}
