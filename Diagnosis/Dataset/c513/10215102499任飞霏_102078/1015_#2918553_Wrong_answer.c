#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[]={97,91,89,83,79,73,71,67,
             61,59,53,47,43,41,37,31,
             29,23,19,17,13,11,7,5,3,2};



void add(int a[],int b[],int c[])
{
    int t=0;
    for(int i = 25;i>0;i--){
        c[i] = (a[i]+b[i]+t)%prime[i];
        t = (a[i]+b[i]+t)/prime[i];
        //printf("%d %d %d %d\n",a[i],b[i],c[i],t);
    }

}

void input(char s[],int a[])
{
    int d = 25;
    int n = 1;
    for(int i = strlen(s)-1;i>=0;i--){
        if(s[i]!=','){
            a[d] = n*(s[i]-'0');
            n*=10;
            //printf("%d",a[d]);
        }
        else{
            n = 1;
            d--;
        }
    }
}

void output(int a[])
{
    int i = 0;
    while(a[i]==0)i++;
    for(;i<26;i++){
        printf("%d",a[i]);
        if(i!=25)printf(",");
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int a[26]={0},b[26]={0},c[26] = {0},x = 0,y = 0;
        char s[100];
        scanf("%s",s);
        if(s[0]!='0')input(s,a);
        else
            x = 1;
        scanf("%s",s);
        if(s[0]!='0')input(s,b);
        else
            y = 1;
        add(a,b,c);
        printf("case #%d:\n",i);

        if(x==1&&y==1)printf("0\n");
        else
            output(c);
    }
    return 0;
}
