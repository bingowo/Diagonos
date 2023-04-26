#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int l=0;
        scanf("%d",&l);
        char s[100][100];
        int n=0;char c;
        do{
            scanf("%s",s[n++]);
        }while((c=getchar())!='\n');
        int sum=0;int n1=0;
        for(int j=0;j<n;j++)
        {
            if(n1==0) sum+=strlen(s[j]);
            else sum+=1+strlen(s[j]);
            if(sum<l) continue;
            if(sum==l)
            {
                for(int k=l-n1;k<=j;k++)
                {
                    if(k!=j) printf("%s ",s[k]);
                    else printf("%s",s[k]);
                }
                n1=0;sum=0;
            }
            if(sum>l)
            {
                sum-=strlen(s[j])+1;int temp=l-sum;
                for(int k=l-n1;k<=j;k++)
                {
                    printf("%s",s[k]);
                    if(k!=j)
                    {
                        for(int f=0;f<temp/n1;f++)
                        {
                            printf(" ");
                            temp--;
                        }
                    }
                }
                sum=0;
            }
            n1++;
        }
    }
    return 0;
}
