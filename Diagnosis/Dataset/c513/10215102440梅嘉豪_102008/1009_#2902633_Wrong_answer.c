//用scanf他不读空格
//用getchar他不处理汉字
//我没法了wwwww
#include <stdio.h>
#include <string.h>
int num_of_one(char *s);
int GCD(int a,int b);
int main()
{
    int n,a,b,d;
    char s[1000];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int i=0;
        while((s[i++]=getchar())!='\n');
        s[i-1]='\0';
        printf("%s\n",s);
        a=num_of_one(s);
        printf("aaa\n");
        b=8*strlen(s);
        printf("bbb\n");
        d=GCD(a,b);
        // printf("%d %d %d\n",a,b,d);
        // printf("%s",s);
        a=a/d;b=b/d;
        printf("%d/%d\n",a,b);
    }
}
int num_of_one(char *s)
{
    int ans=0;
    char *p,c;
    p=s;
    while(*p)
    {
        c=*p;
        while(c!=0)
        {
            if(c&1) ans++;
            c=c>>1;
        }
        p++;
    }
    return ans;
}
int GCD(int a,int b)
{
    int n=a;
    for(;n>0;n--)
    {
        if((b%n)==0&&(a%n)==0)    return n;
    }
} 


