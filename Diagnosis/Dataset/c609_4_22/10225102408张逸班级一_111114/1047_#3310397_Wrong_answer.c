#include<stdio.h>
#include<stdlib.h>
int ans[10000]={0};//a只是1到10之间的数而已
int record=0;
void time(int a,int n){
   for(int i=0;i<10000;i++)ans[i]=0;
   int carry=0,max=0;
   if(a==10){
      ans[n]=1;
      record=n+1;
   }
   else {
      ans[0]=1;
      while(n--){
        ans[record]=ans[record]*a+carry;
      if(ans[record]>9){carry=ans[record]/10;ans[record++]%=10;}
      else {carry=0;record++;}
      while(carry!=0||record<max){
          ans[record]=carry+ans[record]*a;
          if(ans[record]>9){
          carry=ans[record]/10;
          ans[record++]%=10;
          }
          else {record++;carry=0;}
          if(record>max){max=record;}
      }
      record=0;//重置计数器
    }
    record=max;//退出时，record要返回最高位所在的值
   }
   return;
}
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
       printf("case #%d:\n",i);
        int a,n;
       scanf("%d %d",&a,&n);
       time(a,n);
       for(int i=record-1;i>=0;i--){//倒序输出，小端存放
        printf("%d",ans[i]);
       }
       printf("\n");
        record=0;
    }
return 0;
}