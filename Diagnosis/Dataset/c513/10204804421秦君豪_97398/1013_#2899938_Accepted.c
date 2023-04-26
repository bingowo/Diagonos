
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

long long int GCD(long long int a,long long int b)
{
    if(b==0) return a;
	return GCD(b,a%b);

}
int main()
{
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0, ansC=1;
    char *s =(char*)malloc(sizeof(char)*300);
    scanf("%s",s);
    for (;p<strlen(s);p++) 
    {//整数部分
    if (s[p]=='.') break;
    ansA = ansA *3;
    if (s[p]=='1') ansA += 1;
    if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++)
     { //小数部分
        ansB =ansB * 3;      //分子
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;  
        ansC = ansC * 3;      //分母
    
    }
    if(ansA>0&&ansB<0)
    {
        ansA--;
        ansB=ansC+ansB;
    }
    else if ( ((ansA<0)&&(ansB>0)))
    {
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0) ansB=-ansB;
    }
    
    long long t=GCD(abs(ansB),abs(ansC));
    if(ansB==0) printf("%lld\n",ansA);
    else
    {
        if(ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    system("pause");
    return 0;
}

