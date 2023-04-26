#include<stdio.h>
#include<string.h>
int main()
{
    char ch[50];
    int re[50];
    int A,B;
    scanf("%d %s %d",&A,&ch,&B);
    if((A<2)||(B>16)) return 0;
    int x,y=1,sum=0;
    int l=strlen(ch);
    for(int i=l-1;i>=0;i--){
        if((ch[i]>='A')&&(ch[i]<='Z')) x=ch[i]-'A'+10;
        else if((ch[i]>='a')&&(ch[i]<='z')) x=ch[i]-'a'+10;
        else x=ch[i]-'0';
        sum=sum+x*y;
        y*=A;
    }
    int a,i=0;
    while(sum!=0){
        a=sum%B;
        sum/=B;
        re[i]=a;
        i++;
    }
    i--;
    for(;i>=0;i--){
        if(re[i]>9) printf("%c",re[i]+55);
        else printf("%d",re[i]);
    }
    return 0;
}