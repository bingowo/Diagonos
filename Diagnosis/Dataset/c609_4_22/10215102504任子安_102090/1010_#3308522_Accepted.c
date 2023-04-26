#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    if(n==0) printf("0");
    char res[100]={'\0'};
    int i=0;
    while (n!=0)
    {
        int tmp=n%r;
        n=n/r;
        if(tmp<0)
        {
            tmp-=r;
            n++;
        }
        if(abs(tmp)>=0 && abs(tmp)<=9) res[i]=abs(tmp)+'0';
        else res[i]=abs(tmp)-10+'A';
        i++;
    }
    for(i=strlen(res)-1;i>=0;i--) printf("%c",res[i]);
    return 0;
}