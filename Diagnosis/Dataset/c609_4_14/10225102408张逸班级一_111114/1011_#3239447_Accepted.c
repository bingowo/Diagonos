#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    char s[31];
    scanf("%s",s);
    int len=strlen(s);
    long long sum=0,son=0,mother=1;
    int flag=0;
    for(int i=0;i<len;i++){
       if(s[i]!='.'&&flag==0){//整数计算
        if(s[i]=='2')sum=sum*3-1;
        else sum=sum*3+(s[i]-'0');
       }
       else {
        if(!flag)i++;//跳过小数点
        flag=1;      //分数计算
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
   if(sum!=0)printf("%lld%c",sum,flag?' ':'\n');//sum不是零时输出sum
   else if(sum==0&&!flag)printf("%lld\n",sum);//单个0
   for(int i=2;i<sqrt(son);i++){//这里要用sqrt避免超时
    while(son%i==0&&mother%i==0){
    son/=i;mother/=i;}
   }
   if(flag)printf("%lld %lld",son,mother);//有小数点再输出分子分母
   return 0;
}
