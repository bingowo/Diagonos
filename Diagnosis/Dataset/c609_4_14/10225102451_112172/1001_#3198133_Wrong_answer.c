#include <stdio.h>
#include <stdlib.h>

void f(int x,int n)
{
    char s[1000];
    int i=0;
    int flag=0;
    int t=0;
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
    for(int j=0;j<i/2+1;j++)
    {
        t=s[j];
        s[j]=s[i-j];
        s[i-j]=t;
    }
    s[i]='\0';
    printf("%s",s);

}
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        f(x,y);
    }
    return 0;
}
