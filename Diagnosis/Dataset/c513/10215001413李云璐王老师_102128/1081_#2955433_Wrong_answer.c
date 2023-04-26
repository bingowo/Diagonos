#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int s[1010]={1};
        int a,n;
        scanf("%d%d",&a,&n);
        int k,l=1;
        for(int k=1;k<n;k++)
        {
            for(int j=0;j<k;j++)
            s[j]*=a;
            for(int j=0;j<l;j++)
            {
                s[j+1]+=s[j]/10;
                s[j]=s[j]%10;
            }
            if(s[l]!=0) l++;
        }
        printf("case #%d:\n",i);
        for(int j=l-1;j>=0;j--)
        printf("%d",s[j]);
        printf("\n");
            
    }
    return 0;
        
    
}