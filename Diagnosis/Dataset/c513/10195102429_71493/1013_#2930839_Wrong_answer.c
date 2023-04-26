#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int GCD(long long int a,long long int b)
{
if(a==0)
{
return b;
}else
{
return GCD(b % a,a);
}
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
            char s[10];
            scanf("%s",s);
            unsigned int p=0;
            long long ansA=0;
            long long ansB=0, ansC=1;
            for (;p<strlen(s);p++) {//整数部分
                if (s[p]=='.') break;
                ansA = ansA *3;
                if (s[p]=='1') ansA += 1;
                if (s[p]=='-') ansA -= 1;
             }
            p++;
           for (;p<strlen(s);p++) { //小数部分
               ansB =ansB * 3; //分子
               if (s[p]=='-') ansB -= 1;
               if (s[p]=='1') ansB += 1;
               ansC = ansC * 3; //分母
          }
          if(ansA>0&ansB<0){
            ansA--;
            ansB=ansC+ansB;
          }
          if(ansA<0&ansB>0){
            ansA++;
            ansB=ansC-ansB;
          }
          if(ansA==0){
            ansB=-ansB;
          }
    long long t=GCD(abs(ansB),abs(ansC));
    printf("case #%d:\n",cas);
    if (ansB==0) printf("%lld\n",ansA);
    else{
            if (ansA!=0) printf("%lld ",ansA);
               printf("%lld %lld\n",ansB/t,ansC/t);
}
    }

return 0;
    }
