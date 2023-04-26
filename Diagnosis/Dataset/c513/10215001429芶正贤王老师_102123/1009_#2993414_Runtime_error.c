#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
    int temp;
    while(b != 0)
    {
        temp = a%b;
        a=b;
        b=temp;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    
    for(int i = 0;i<n;i++)
    {
        char  array[120];
        scanf("%s",array);
        int top = 0,btm = 0;
        for(int j=0;j<strlen(array);j++)
        {
            char ch=array[j];
            while(ch != 0)
            {
                top += (ch & 1);
                ch >>= 1;
            }
            btm += 8;
        }
        int g;
        g = gcd(top,btm);
        printf("%d/%d\n",top/g,btm/g);
    }
    
    return 0;
}