#include<stdio.h>
#include<string.h>
#include<math.h>
int x;
void f(int n,int r,char s[])//f是得到倒序的n进制数组
{
    while(n/r!=0){
        
        if(n%r>9){
            s[x++]=n%r-10+'A';
        }
        else{
            s[x++]=n%r+'0';
        }n/=r;
    }
    if(n%r>9){
            s[x]=n%r-10+'A';
            s[++x]='\0';
        }
        else{
            s[x]=n%r+'0';
            s[++x]='\0';
        }

}
int main()
{
    int a,b;
    char n[33],m[33];
    scanf("%d%s%d",&a,n,&b);
    int sum=0;
    for(int i=0;i<strlen(n);i++)
    {   
        if(n[i]>='0'&&n[i]<='9')
        sum+=(n[i]-'0')*(int)pow((double)a,(double)strlen(n)-i-1);
        else if(n[i]>='a'&&n[i]<='f')sum+=(n[i]+10-'a')*(int)pow((double)a,(double)strlen(n)-i-1);
        else sum+=(n[i]+10-'A')*(int)pow((double)a,(double)strlen(n)-i-1);
    }//这时sum是十进制的该数      maybe some problems

    //接下来把十进制转化为B进制
    f(sum,b,m);
    for (int j=strlen(m)-1;j>=0;j--)
    {
        printf("%c",m[j]);
    }

    return 0;
}