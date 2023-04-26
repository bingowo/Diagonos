#include <stdio.h>
#include <stdlib.h>
int GCD(int a,int b)
{
    if(a==b)return b;
    else return a>b?GCD(a-b,b):GCD(a,b-a);
}
int main()
{
    int n,i=0,j;
    //char s[120];
    int cnt_1,total;
    char c;
    scanf("%d",&n);
    getchar();
    while(i<n)
    {
        j=0,cnt_1=0,total=0;
        while((c=getchar())!='\n')
        {
            //s[j++]=c;
            do{
                if(c%2==1)cnt_1++;
            }while(c/=2);
            j++;
        }
        total=j*sizeof(char)*8;
        int gcd=GCD(cnt_1,total);
        printf("%d/%d\n",cnt_1/gcd,total/gcd);
        i++;
    }
    return 0;
}
