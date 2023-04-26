/*#include<stdio.h>
#include<stdlib.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    int l=strlen(s);
    int i=0,j;
    while(i<l)
    {
        int a[128]={0};
        j=i;
        while(j<l)
        {




        }



    }
}



*/
#include<stdio.h>
int main()
{
    int a[1001]={0};
    char c;
    scanf("%c",&c);
    char c2;
    scanf("%c",&c2);
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        a[x]=1;
    }
    if(c=='A')
    {
        for(int i=0;i<1001;i++)
        {
            if(a[i]==1)printf("%d ",i);

        }

    }
    else if(c=='D')
    {
         for(int i=0;i<1001;i++)
        {
            if(a[i]==1)printf("%d ",i);

        }
    }




}
