#include<stdio.h>
#include<string.h>
int change(char s[])
{
    int sum=0,length=strlen(s),weight=1;
    for(int i=length-1;i>=0;i--){
        if(s[i]=='-') s[i]=-1;
        else s[i]=s[i]-'0';
        sum+=s[i]*weight;
        weight*=3;
    }
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    int r[T];
    char s[1000];
    for(int i=0;i<T;i++){
        scanf("%s",&s);
        r[i]=change(s);
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%d\n",r[i]);
    }
    return 0;
}
