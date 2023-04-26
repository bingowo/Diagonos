#include <stdio.h>
#include <string.h>
int main()
{
    char s[81];
    while(scanf("%s",s)!=EOF)
    {
        char L[80][80];
        for(int i=0;i<80;i++)
        {
            for(int j=0;j<80;j++)
            {
                L[i][j]=' ';
            }
        }
        int m=79,n=0,k=0;
        L[m][n]=s[k++];
        while(k<(int)strlen(s))
        {
            if(s[k]>s[k-1]) L[--m][++n]=s[k];
            else if(s[k]<s[k-1]) L[++m][++n]=s[k]; 
            else L[m][++n]=s[k];
            k++;
        }
        for(int i=m;i<80;i++)
        {
            int j=0;
            for(j=79;L[i][j]==' ';j--) continue;
            for(int q=0;q<=j;q++) printf("%c",L[i][q]);
            printf("\n");
        }
    }
    return 0;
}