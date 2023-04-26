#include <stdio.h>

void itob(int n,char s[100],int b)
{   int tmp;
    char *p1,*p;
    p=s;
    int i=0;
    int count;
    char m[100];
    p1=m;
    if(n>=0)
    {
        count=i;
    while(n!=0)
    {
        tmp=n%b;
        if(tmp<=9) *(p1+i)=tmp+'0';
        else  *(p1+i)=tmp-10+'A';
        n/=b;
        i+=1;
    }
    }
    if(n<0)
    {
        n=-n;
        *p='-';
        i=1;
        count=i;
         while(n!=0)
    {
        tmp=n%b;
        if(tmp<=9) *(p1+i)=tmp+'0';
        else  *(p1+i)=tmp-10+'A';
        n/=b;
        i+=1;
    }
    }
    int sum=i-1;
    while(count<i)
    {
        *(p+count)=*(p1+sum);
        count++;
        sum--;
    }
    *(p+count)='\0';


}

int main()
{
    int n,b,count;
    char s[100];
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);}
    return 0;
}

