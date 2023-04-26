#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    char* q[10];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",&q[i]);
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        change(q[i]);
        printf("\n");
    }
    return 0;
}
void change(char s[])
{
    int n[6000];
    int l=strlen(s);
    for(int i=0;i<l;i++){
        int a=(int)s[i];
        if(a>=65&&a<=90) a-=65;
        else if(a>=97&&a<=122) a=a-97+26;
        else if(a>=48&&a<=57) a=a-48+52;
        int j=8*i+7;
        do{
            n[j--]=a%2;
            a/=2;
        }while(a!=0);
        while(j!=8*i){
            n[j--]=0;
        }
    }
    int L=l*8;
    while(L%6!=0){
        n[L++]=0;
    }
    int k=L/6;
    char r[1000];
    for(int i=0;i<k;i++){
        int sum=0,weight=1;
        for(int j=i*6+5;j>=i*6;j++){
            sum=n[j]*weight;
            weight*=2;
        }
        if(sum<=25) sum+=65;
        else if(sum>25&&sum<=51) sum+=97;
        else if(sum>51) sum+=48;
        r[i]=(char)sum;
    }
    while(k%4!=0){
        r(k++)='=';
    }
    for(int i=0;i<k;i++){
        printf("%c",r[i]);
    }
}