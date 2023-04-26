#include <stdio.h>
#include <stdlib.h>

void f(int x,int n,char s[1000])
{
    int i=1;
    int flag=0;
    int t=0;
    s[0]='\0';
    if(x<0){
    flag=1;
    x=-x;
    }
    for(;x;i++){
        t=x%n;
        x/=n;
        if(t<10)
            s[i]=t+'0';
        else
            s[i]=t-10+'A';
    }
    if(flag)
        {s[i]='-';i++;}
    else i--;
    for(int a=0,b=i;a<b;a++,b--)
    {
        t=s[a];
        s[a]=s[b];
        s[b]=t;
    }


}
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    char s[1000];
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        f(x,y,s);
        printf("%s",s);
    }
    return 0;
}
