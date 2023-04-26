#include <stdio.h>

void itob(int n,char s[100],int b)
{   int tmp;
    char *p1,*p;
    p=s;
    int i=0;
    int count;
    char m[100];
    p1=m;
        count=i;
    while(n!=0)
    {
        tmp=n%b;
        if(tmp>=0)
        {
        if(tmp<=9) *(p1+i)=tmp+'0';
        else  *(p1+i)=tmp-10+'A';
        n/=b;
        }
        else
        {
            tmp=n-(n/b+1)*b;
            if(tmp<=9) *(p1+i)=tmp+'0';
            else  *(p1+i)=tmp-10+'A';
            n=n/b+1;
        }
        i+=1;
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
    int n,b;
    char s[100];
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);
    return 0;
}
