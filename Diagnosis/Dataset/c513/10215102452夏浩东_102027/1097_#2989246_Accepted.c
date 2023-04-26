#include <stdio.h>
#include <string.h>
int main()
{
    char s[81];
    while(scanf("%s",s)!=EOF)
    {
        char L[200][80];
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<80;j++)
            {
                L[i][j]=' ';
            }
        }
        int m=100,n=0,k=0,min=100,max=100;
        L[m][n]=s[k++];
        while(k<(int)strlen(s))
        {
            if(s[k]>s[k-1]) L[--m][++n]=s[k];
            else if(s[k]<s[k-1]) L[++m][++n]=s[k]; 
            else L[m][++n]=s[k];
            min=m<min?m:min;
            max=m>max?m:max; 
            k++;
        }
        for(int i=min;i<=max;i++)
        {
            int j=0;
            for(j=79;L[i][j]==' ';j--) continue;
            for(int q=0;q<=j;q++) printf("%c",L[i][q]);
            printf("\n");
        }
    }
    return 0;
}