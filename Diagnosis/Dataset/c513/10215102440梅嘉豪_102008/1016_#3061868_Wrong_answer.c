#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,n,r;
    char s[1000]={0},ans[1000]={0};
    scanf("%d %d",&n,&r);
    while(n!=0)
    {
        a=n/r;
        b=n%r;
        if(b<0)
        {
            a++;
            b=b-r;
        }
        n=a;
        ans[strlen(ans)]=b>=10?b-10+'A':b+'0';
        
    }
    for(int i=strlen(ans)-1;i>=0;i--) printf("%c",ans[i]);


}