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
    int cnt_1,total;
    char c;
    scanf("%d",&n);
    getchar(); //读取一行的回车
    while(i<n)
    {
        //char s[250];
        j=0,cnt_1=0,total=0;
        //fgets(s,250,stdin);
        while((c=getchar())!='\n')
        {
            do{
                if(c%2==1||c%2==-1)cnt_1++;
                else continue;
            }while(c=(unsigned char)c>>1);
            j++;
        }
        total=j*sizeof(char)*8;
        int gcd=GCD(cnt_1,total);
        printf("%d/%d\n",cnt_1/gcd,total/gcd);
        i++;
    }
    return 0;
}
