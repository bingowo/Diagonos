#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100005];
    scanf("%s",s);
    int len=strlen(s);
    int ans;
    int k=0;
    int a[50]= {0};
    for(int i=1; i<len; i++)
    {
        ans=-1;
        if((s[i]=='x')&&(s[i-1]=='0'))
        {
            for(int j=i+1; s[j]<='e'&&j<len; j++)
            {
                if(s[j]<='9') ans=ans*16+s[j]-'0';
                else ans=ans*16+s[j]-'a'+10;
                if(s[j+1]=='0'&&s[j+2]=='x') break;
            }
            //if(ans!=-1)
            //{
                a[k]=ans;
                k++;
            //}
        }
    }
    if(k==0) printf("-1\n");
    else
    {
        for(int i=0; i<k-1; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[k-1]);
    }
    return 0;
}
