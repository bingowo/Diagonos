#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n;
    int num[1001];
}BIGN;

void mul(BIGN* n,int x)
{
    for (int i=0;i<n->n;i++)
        n->num[i]*=x;
     for (int i=0;i<n->n;i++)
     {
         if (n->num[i]>=10)
         {
             if (i==n->n-1)
                n->n++;
             n->num[i+1]+=(n->num[i]/10);
             n->num[i]=(n->num[i]%10);
         }
     }
}


int main()
{
    char s[1010]={0};
    scanf("%s",s);
    int i;
    BIGN n;
    n.n=1; n.num[0]=1;
    if (strlen(s)==1)
        printf("1\n");
    if (strlen(s)>1)
    {
        for (i=0;i<strlen(s);i++)
        {
            if (i==0)
                if (s[i]!=s[i+1])
                    mul(&n,2);
            if (i>0 && i<strlen(s)-1)
            {
                if (s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1])
                    mul(&n,3);
                else if (s[i]==s[i-1] && s[i]!=s[i+1])
                    mul(&n,2);
                else if (s[i]==s[i+1] && s[i-1]!=s[i])
                    mul(&n,2);
                else if (s[i-1]==s[i+1] && s[i-1]!=s[i])
                    mul(&n,2);
            }
            if (i==strlen(s)-1)
                if (s[i]!=s[i-1])
                    mul(&n,2);
        }
        for (i=n.n-1;i>=0;i--)
            printf("%d",n.num[i]);
        printf("\n");
    }
    return 0;
}
