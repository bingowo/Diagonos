#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long long r;
    long long f;
} NUM;

NUM divide(NUM a)
{
    NUM n;
    n.f=(a.r+a.f)/(-2);
    n.r=(a.f-a.r)/2;

    return n;
}




int main()
{
    int i=0,j,k;
    char s[1000]={0}; char s1[1000]={0}; char s2[1000]={0};
    int arr[1000]={0};
    scanf("%s",s);
    NUM n,m; m.r=-1; m.f=1;
    if(strchr(s,'i')==0)
    {
        n.r=atoi(s);
        if (s[0]=='0') n.r=0;
        n.f=0;
    }
    else
    {
        if (s[0]=='i')
            {n.r=0;n.f=1;}
        else
        {
            for (i=1;i<strlen(s);i++)
            {
                if (s[i]=='+' || s[i]=='-') break;
            }
            if (i==strlen(s))
            {
                for (j=0;j<i;j++) s1[j]=s[j];
                n.r=0;
                n.f=atoi(s1);
                if (n.f==0 && s[0]=='-') n.f=-1;
            }
            else
            {
                for (j=0;j<i;j++) s1[j]=s[j];
                for (j=0,k=i;s[k]!='i';j++,k++) s2[j]=s[k];
                n.r=atoi(s1);
                n.f=atoi(s2);
                if (n.f==0 && s[i]=='+') n.f=1;
                if (n.f==0 && s[i]=='-') n.f=-1;
            }

        }

    }
    printf("%d %d\n",n.r,n.f);
    for (i=0;;i++)
    {
        if (n.r==0 && n.f==0) break;
        if ((n.r%2!=0 && n.f%2!=0) || (n.r%2==0 && n.f%2==0)) arr[i]=0;
        else
        {
            arr[i]=1;
            n.r=n.r-1;
        }
        n=divide(n);
    }
    if (i==0) printf("0\n");
    else
    {
    for (j=i-1;j>=0;j--)
        printf("%d",arr[j]);
    printf("\n");
    }

    return 0;
}
