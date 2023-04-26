#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    n=hui(n);
    int e =n;
    for(i=0;e>0;i++){
        e=e/10;
    }
    printf("%d %d",i,n);
    return 0;


}

int hui(int a)
{
    int c=0;
    int b= contrary(a) ;
    c=a+b;
     int result=c;
    int *s=0;

    s=(int*)malloc(sizeof(int)*10000);
    int j;
    for(j=0;c>0;j++){
        s[j]=c%10;
        c=c/10;
    }
    if(judge(s,j)==0){ free(s);return result;}
    else{ hui(result);}


}

int judge(const int*e,int len)
{


    int i=0,j=len-1;
    for(;i<j;i++,j--){
        if(e[i]!=e[j]) return -1;

    }
    return 0;





}







int contrary(int d)
{
    int sum=0;
    for(int i=0;d>0;i++){
        sum*=10;
        sum+=d%10;
        d/=10;

    }

return sum;


}

