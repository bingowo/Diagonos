#include<stdio.h>
int main(){
    int t;
    int n,r;
    char s[100];
    scanf("%d",&t);
    int k=0;
    while(k<t){
        scanf("%d %d",&n,&r);
        itob(n,s,r);
        printf("%s\n",s);
        k+=1;
    }
    
}
void itob(int n,char s[100],int b)
{
    int r;int m;
    m=n;
    int i;int j=0;
    i=0;
    char c1;
    if(n<0) n=-1*n;
    while(n!=0){
        r=n%b;
        if(r<=9)
           c1=r+48;
        if(r>9)
           c1=r+55;
        n=n/b;
        s[i]=c1;
        i=i+1;
        } 
    if(m<0){s[i]='-';s[++i]='\0';}
    else s[i]='\0';
    char t[100];
    n=strlen(s);
    for(i=n-1;i>=0;i--) t[j++]=s[i];
    for(i=0;i<n;i++) s[i]=t[i];
    s[++i]='\0';
}