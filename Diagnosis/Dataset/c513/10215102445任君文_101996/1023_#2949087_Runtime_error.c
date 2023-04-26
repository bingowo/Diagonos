#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
void swap(int* b, int* a)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
int main()
{
    int n=0;
    int f[M]={0};
    int temp=0;
    int num[M]={0};
    char s[M]={0};
    int sort[M]={0};
    char c;
    int j=0,i=0,k=0;
    while((c=getchar())!=EOF)
    {
        if(c==' ')
        {
            s[j]=strcat(s[j],'\0');
            j++;
        }
        else
        {
            if(('0'<=c)&&(c<='9'))
            {
                temp=c-'0';
                s[j]=strcat(s[j],c);
                f[j]=1;
                num[j]=num[j]*10+temp;
            }
            else
            {
                s[j]=c;
            }
        }
    }
    n=j+1;
    for(i=0;i<n;i++)
    {
        sort[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(num[j]>num[j+1])
            {
                swap(&sort[j],&sort[j+1]);
                swap(&f[j],&f[j+1]);
                swap(&num[j],&num[j+1]);
            }
            else if(num[j]==num[j+1])
            {
                if(f[j]>f[j+1])
                {
                    swap(&sort[j],&sort[j+1]);
                    swap(&f[j],&f[j+1]);
                    swap(&num[j],&num[j+1]);
                }
                else if(f[j]==f[j+1])
                {
                    if(strcmp(s[sort[j]],s[sort[j+1]]))
                    {
                        swap(&sort[j],&sort[j+1]);
                        swap(&f[j],&f[j+1]);
                        swap(&num[j],&num[j+1]);
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s ",s[sort[i]]);
    }
    printf('\n');
    return 0;
}