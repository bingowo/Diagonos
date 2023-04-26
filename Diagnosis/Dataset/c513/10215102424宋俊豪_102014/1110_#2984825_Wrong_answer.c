#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sol(int a,int b)
{   if(b==0)
      printf("0.000\n");
    else{
    if(a*b<0)
        printf("-");
    a=abs(a);b=abs(b);
    printf("%d.",b/a);
    b=b%a;
    int i=0;
    if(b>0){
    do{
        b*=10;
         printf("%d",b/a);
         b=b%a;
         i++;
    }while(b!=0&&i<=3);}
    for(i;i<3;i++)
        printf("0");
    }
}
int main()
{
    char s[100];
    scanf("%s",s);
    int loc=-1,i=0,p[128]= {0};
    int t[5]= {0};
    while(s[i])
    {
        int f=1;
        int a=0,b=0;
        if(s[i]=='=')
            {loc=1;i++;}
        else if(loc==-1)
        {
            if(s[i]=='+')i++;
            else if(s[i]=='-') f=-1,i++;
            while(isdigit(s[i]))
            {
                a=a*10+s[i]-'0';
                i++;
            }
            if(a==0)a=1;
            if(s[i]>='a'&&s[i]<='z')
            {
                p[s[i]]++;
                i++;
                t[0]+=f*a;
            }
            else
            {
                t[1]+=f*a;
            }
        }
        else if(loc==1)
        {   if(s[i]=='0'&&!s[i+1]);
              break;
            if(s[i]=='+')i++;
            else if(s[i]=='-') f=-1,i++;
            while(isdigit(s[i]))
            {
                a=a*10+s[i]-'0';
                i++;
            }
            if(a==0&&s[i-1]!='0')a=1;
            if(s[i]>='a'&&s[i]<='z')
            {
                p[s[i]]++;
                i++;
                t[2]+=f*a;
            }
            else
            {
                t[3]+=f*a;
            }
        }
    }
    t[0]=t[0]-t[2];
    t[3]=t[3]-t[1];

    i=0;
    while(p[i]==0)
        i++;
    printf("%c=",i);
    sol(t[0],t[3]);
    return 0;
}
