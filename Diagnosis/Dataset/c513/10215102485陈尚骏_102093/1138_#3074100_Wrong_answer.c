#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

void numchange(int x,int y)
{
    int n;
    if(x)
    {
        numchange(x/y,y);
        n=x%y;
        if(n<10) printf("%d",n);
        else printf("%c",n+55);
    }
}

int main()
{
    int A,B;
    int w=0;
    char n[101]={'\0'};
    scanf("%d %s %d",&A,n,&B);
    if(n[0]-'0'==0&&n[1]=='\0') {printf("0"); return 0;}
    if(A<=10)
    {
        int len=strlen(n);
        for(int i=0;i<strlen(n);i++)
        {
            w+=(n[i]-'0')*pow(A,len-1);
            len--;
        }
    }
    else
    {
        int len=strlen(n);
        for(int i=0;i<strlen(n);i++)
        {
            if(n[i]>='a'&&n[i]<='z')
            {
            w+=(n[i]-'a'+10)*pow(A,len-1);
            }
            else
                w+=(n[i]-'A'+10)*pow(A,len-1);
            len--;
        }
    }
    numchange(w,B);
    return 0;
}
