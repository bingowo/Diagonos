#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int i=0;
    while(i<a){
        int t;
        scanf("%d",&t);
        char s[20];
        int m=0;
        while(t)
        {
            s[m]=t%2;
            t=t%2;
            m++;
        }
        int c=1,d=0;
        while(d+c<m)
        {
            if(s(d)==s(d+1))
            c++,d++;
            else
            d++,c=1;
        }
        
        printf("case #0\n");
        print("%d\n",c);
    }
}