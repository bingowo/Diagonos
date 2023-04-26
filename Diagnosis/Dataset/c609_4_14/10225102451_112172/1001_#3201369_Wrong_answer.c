#include <stdio.h>
#include <stdlib.h>

int g(int n,char *s)
{
    int i=0;
    int weight=1;
    while(*(s+i)!='\0')
    {
        weight*=n;
        i++;
    }
    weight/=n;
    int answer=0;
    int j=0;
    while(*(s+j)!='\0')
    {
        if(*(s+j)<='Z'&&*(s+j)>='A')
            answer+=(*(s+j)-'A'+10)*weight;
        else if(*(s+j)<='z'&&*(s+j)>='a')
            answer+=(*(s+j)-'a'+10)*weight;
        else
            answer+=(*(s+j)-'0')*weight;
        j++;
        weight/=n;
    }
    return answer;


}
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
        {s[i]='-';}
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
    char s[100];
    scanf("%s",s);
    if(s[0]=='0'&&s[1]=='\0')
        printf("0");
    else{
    int b;
    scanf("%d",&b);
    char answer[1000];
    f(g(n,s),b,answer);
    printf("%s",answer);}
    return 0;
}