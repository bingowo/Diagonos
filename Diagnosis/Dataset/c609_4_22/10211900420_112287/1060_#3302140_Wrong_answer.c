#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(char x[],int n,char a)
{
    x[strlen(x)]='\0';
    for(int i=strlen(x)-1;i>=n;i--)
    {
        x[i+1]=x[i];
    }
    x[n]=a;

}
int main()
{
    int j;
    char x[202]={0};
    scanf("%s",x);
    for(int i=0;i<strlen(x);i++)
    {
        if(x[i]=='A' && i!=strlen(x)-1)
        {
            add(x,i,'A');
            i++;
        }
        if(x[i]=='B')
        {
            j=i;
            while(x[j]=='B' && j!=strlen(x)-1)
            {
                j++;
            }
            if(x[j]=='C')
            {
                add(x,i,'B');
                i++;
            }
        }
    }
    printf("%s",x);
    return 0;
}
