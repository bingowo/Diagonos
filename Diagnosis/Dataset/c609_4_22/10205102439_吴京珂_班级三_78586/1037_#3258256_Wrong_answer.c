#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1000005];
    scanf("%s",&s);

    int ans=0,max=1;//初始下标，长度
    int a[128]= {0};
    int len=strlen(s);
    int i,j,k;

    for(i=0; i<len; i++)
    {
        for(j=i; j<len; j++)
        {
            if(a[s[j]]==0) a[s[j]]=1;//未出现标记
            else break;
        }
        if((j-i)>max)
        {
            max=j-i;
            ans=i;
        }
        for(k=0; k<128; k++) a[k]=0;
    }

    for(int i=ans; i<max; i++)
        printf("%c",s[i]);


    return 0;
}
