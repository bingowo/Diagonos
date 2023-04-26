
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#include<stdlib.h>
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
    {//????
    if (s[p]=='.') break;
    ansA = ansA *3;
    if (s[p]=='1') ansA += 1;
    if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++)
     { //????
        ansB =ansB * 3;      //??
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;  
        ansC = ansC * 3;      //??
    
    }
    if(ansB==0) printf("%lld\n",ansA);
    else
    {
        if(ansA>0&& ansB<0)
        {
            ansA--;
            ansB=ansC-ansB;
        }
        else if(ansA<0&&ansB>0)
        {
            ansA++;ansB=ansC-ansB;
            
        }
        if(ansA==0) ansB=-ansB;
        long long t=GCD(abs(ansB),abs(ansC));
        printf("%lld %lld %lld",ansA,ansB/t,ansC/t);
    }
    system("pause");
    return 0;
}

