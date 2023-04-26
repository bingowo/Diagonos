#include<stdio.h>
#include<string.h>
int main(){
int a;
scanf("%d",&a);
for(int i=0;i<a;i++){
    printf("case #%d:\n",i);
    char s[32];
    int sum=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s)-1;i++){
        if(s[i]=='-'){
           sum=3*(sum-1);
        }
        else {sum=3*(sum+s[i]-'0');
        }
    }
    int k=strlen(s)-1;
    if(s[k]=='-'){
        sum-=1;
    }
    else {sum+=s[k]-'0';}
    printf("%d\n",sum);
}
return 0;
}
