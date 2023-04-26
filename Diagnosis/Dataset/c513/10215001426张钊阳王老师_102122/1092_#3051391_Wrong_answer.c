#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char w[1200];
    memset(w,'/0',sizeof(w[0])*1200);
    scanf("%s",w);
    int l=strlen(w);
    //printf("%s %d ",w,l);
    int *n=(int*)malloc(sizeof(int)*l);
    for(int z=0;z<l;z++) n[z]=1;
    int ans[1000];
    memset(ans,0,sizeof(ans[0])*1000);
    int l0;
    for(int i=0;i<l;i++)
    {
        if(i==0)
        {
            if(w[0]==w[1]) ;
            else if(w[0]!=w[1]&&w[i+1]!='\0') n[i]++;
        }
        else if(i==l-1)
        {
            if(w[i]==w[i-1]) ;
            else if(w[i]!=w[i-1]) n[i]++;
        }
        else
        {
            if(w[i-1]!=w[i]) n[i]++;
            if(w[i+1]!=w[i]) n[i]++;
            if(w[i]!=w[i+1]||w[i]!=w[i-1])
            {
                if(w[i-1]==w[i+1]) n[i]--;
            }
        }
    }
    //printf("%do",n[1]);
    ans[0]=n[0];
    l0=1;
    for(int j=1;j<l;j++)
    {
        for(int k=0;k<l0;k++)
        {
            ans[k]*=n[j];
        }
        for(int g=0;g<l0-1;g++)
        {
            if(ans[g]>=10) {ans[g]-=10;ans[g+1]++;}
        }
        if(ans[l0-1]>=10) {ans[l0-1]-=10;ans[l0]++;l0++;}
    }
    for(int j=l0-1;j>=0;j--)
    {
        printf("%d",ans[j]);
    }
    return 0;
}
