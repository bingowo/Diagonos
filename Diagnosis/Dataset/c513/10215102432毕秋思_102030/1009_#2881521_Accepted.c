#include<stdio.h>
#include<string.h>

int all,count;

int count_one_bits(char* a)
{
    int len = strlen(a);
    int i = 0;
    count = 0;
    for (i=0;i<len;i++)
    {
        char temp = a[i];
        while(temp)
        {
            temp = temp&(temp-1);
            count++;
        }
    }
    all = 8*len;
    GCD(all,count);
}

int GCD(int m,int n)
{
    if(m>n)
    {
        int t=m;
        m=n;
        n=t;
    }
    if(n%m==0) printf("%d/%d\n",count/m,all/m);
    else return GCD(m,n%m);
}

int main()
{
    int n,i;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        char a[1000] = {'\0'};
        char c;
        int j = 0;
        while((c=getchar())!='\n')
        {
            a[j++] = c;
        }
        count_one_bits(a);
    }
    return 0;
}
