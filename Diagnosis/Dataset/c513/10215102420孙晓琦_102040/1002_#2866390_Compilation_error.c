#include <stdio.h>
#include <stdlib.h>

void first(int l,int a[123],char s[],int k)
{
    for (int j=0;j<=123;j++)
            
        a[j]=-1;
    if(l>=2)
    {
        int i=0,n=2;
        char m=s[i++];
        a[m]=1;
        m=s[i++];
        a[m]=0;
        k=2;
        for (;i<l;i++)
        {
            char m=s[i];
            if (a[m]!=-1)
                
                continue;
            
            else 
                {
                    a[m]=n++;
                    k++;
                }
        }
    }
    else 
    {
        char m=s[0];
        a[m]=2;
        k=2;
    }
    
}

int answer(int a[123],char s[],int l,int k)
{
    l--;
    int 
}
int main()
{
    char s[60];
    int t,a[123],n=0;
    scanf("%d",&t);
    while (t>0)
    {
        scanf("%s",&s);
        int l=strlen(s),k=0;
        first (l,a[123],s,k);
        
        t--;
    }
}