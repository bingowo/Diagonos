#include <stdio.h>
#include <string.h>

int main()
{
    long long int x=0;
    char s[100];
    char *c=s;
    int R1=0,I1=0;
    int R2=-1,I2=1;
    int temp;
    scanf("%s",s);
    int len;
    len=strlen(s);

    while(c<s+len)
    {
        if(*c=='x')
        {
            c++;
            continue;
        }
        if(*c>='A'&&*c<='E')
        {x=x*16+(*c-'A'+10);}
        else if(*c>='0'&&*c<='9')
        {
            x=x*16+(*c-'0');

        }
        c++;
    }

    int A[100];
    int *p=A;
    p=p+99;

    while(x)
    {
        *p=x%2;
        x=x/2;
        p--;
    }

    p++;
    while(p<=A+99)
    {   temp=R1;
        R1=-R1-I1;
        I1=temp-I1;
        R1=R1+(*p);
        p++;
    }
    if(R1==0&&I1!=0);
    else if(I1==0&&R1==0)
    {
        printf("0");
    }
    else
    printf("%d",R1);
    if(I1>0)
    {
        if(I1==1&&R1!=0)
        {
            printf("+i");
        }
        else if(I1==1&&R1==0)
        {
            printf("i");
        }
        else
        printf("+%di",I1);

    }
    else if(I1<0)
    {
        if(I1==-1&&R1!=0)
        {
            printf("-i");
        }
        else if(I1==-1&&R1==0)
        {
            printf("-i");
        }
        else
        printf("%di",I1);
    }
    else return 0;

}
