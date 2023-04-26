#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        int s[m+1][51]={0};
        for(int k=0;k<m;k++)
        {
            int l=0;
            while((scanf("%d",&s[k][l])!=EOF&&s[k][l]!=-1) l++;
        }
        sort(s,m);
        
    }
}