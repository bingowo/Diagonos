#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55

double Eight_float(char s[])
{
    double weight=8.0,ret=0;
    int len = strlen(s);
    for(int i=2;i<len;++i){
        ret=ret+(s[i]-'0')/weight;
        weight*=8;
    }
    return ret;
}

int isnotInt(double a) {
	int b = a;
	if (b - a != 0.00)return 1;
	else return 0;
}

int main()
{
   int T,x=0;
   scanf("%d\n",&T);
   while(x<T){
        char s[N]={0},ret[N*3]={0};
        scanf("%s",s);
        double temp = Eight_float(s);
        ret[0]='0';ret[1]='.';
        int p=2;
        while(isnotInt(temp)){
            temp*=10;
            int k = temp;
            ret[p++]=k+'0';
            temp-=k;
        }
        ret[p]=0;
        printf("case #%d:\n",x++);
        printf("%s\n",ret);
   }
   return 0;
}
