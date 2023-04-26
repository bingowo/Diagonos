#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[31];
    scanf("%s",s);
    int len=strlen(s);
    long long sum=0,son=0,mother=1;
    int flag=0;
    for(int i=0;i<len;i++){
       if(s[i]!='.'&&flag==0){
        if(s[i]=='2')sum=sum*3-1;
        else sum=sum*3+(s[i]-'0');
       }
       else {
        if(!flag)i++;
        flag=1;
        if(s[i]=='2'){
            son=son*3-1;
            mother*=3;}
        else{
            son=son*3+(s[i]-'0');
            mother*=3;}
       }
    }
    if(son<0&&sum>0){sum-=1;
        son+=mother;} 
    else if(son>0&&sum<0){sum+=1;
        son=mother-son;} 
   if(sum!=0)printf("%lld%c",sum,flag?' ':'\n');
   else if(sum==0&&!flag)printf("%lld\n",sum);
   for(int i=2;i<son;i++){
    while(son%i==0&&mother%i==0){
    son/=i;mother/=i;}
   }
   if(flag)printf("%lld %lld",son ,mother);
   return 0;
}
