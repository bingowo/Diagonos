#include<stdio.h>
#include<string.h>
int count(char s[])
{
    int count_1=0;
    for(int i=0;i<strlen(s);i++){
        int x=(int)s[i];
        int count=0,y;
        do{
            y=x%2;
            x/=2;
            if(y==1) count++;
        }while(x!=0);
        count_1+=count;
    }
    return count_1;
}
int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int T;
    scanf("%d\n",&T);
    char s[120],c;
    int son[T],mom[T];
    for(int i=0;i<T;i++){
        strcpy(s,"");
        gets(s);
        son[i]=count(s);
        mom[i]=strlen(s)*8;
    }
    int c1,c10;
    for(int i=0;i<T;i++){
        c1=son[i];
        c10=mom[i];
        printf("%d/%d\n",c1/gcd(c1,c10),c10/gcd(c1,c10));
    }
    return 0;
}