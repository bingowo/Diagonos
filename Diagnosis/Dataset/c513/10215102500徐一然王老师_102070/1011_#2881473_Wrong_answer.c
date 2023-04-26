#include <stdio.h>
#include <string.h>

int main()
{
    int x=0;
    char s[100];
    char *c=s;

    int A[1000];
    int *p=A;
    p=p+999;
    long long int R1=0,I1=0;
    long long int temp;
    scanf("%s",s);
    int len;
    int count=4;
    len=strlen(s);
    c=s+len-1;

    while(len--)
    {
        if(*c=='x')
        {
            c--;
            continue;
        }
        if(*c>='A'&&*c<='F')
        {x=*c-'A'+10;}
        else if(*c>='0'&&*c<='9')
        {
            x=*c-'0';
        }
        c--;

        while(count--)
        {
            *p=x%2;
            x=x/2;
            p--;
        }
        count=4;
    }
    p++;
    while(p<=A+999)
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
    printf("%lld",R1);
    if(I1>0)
    {
        if(I1==1&&R1!=0)
        {
            printf("+i");
        }
        else if(R1==0)
        {
            printf("%lldi",I1);
        }
        else
        printf("+%lldi",I1);

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
        printf("%lldi",I1);
    }
    else return 0;

}
