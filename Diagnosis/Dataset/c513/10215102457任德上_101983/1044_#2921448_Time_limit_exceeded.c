#include<stdio.h>
int main(){
    char s[100001],tab[]="0123456789abcdef",*s1,*s2;
    scanf("%s",s);
    unsigned int sum =0;
    int k=0;
    s1=s;
    while(*s1){
        if(*s1=='0'&&*(s1+1)=='x'){
            s2=s1+2;
            while((*s2>=48&&*s2<=57)||(*s2>=97&&*s2<=102));{
                if(*s2>=48&&*s2<=57)sum=sum*16+*s2-'0';
                else sum=sum*16+*s2-'a'+10;
                s2++;
            }
            if(sum!=0)printf("%d ",sum);
            sum=0;
            k++;
            s1=s2;
        }
        else s1++;
    }

    if(k==0)printf("-1");
    return 0;
}