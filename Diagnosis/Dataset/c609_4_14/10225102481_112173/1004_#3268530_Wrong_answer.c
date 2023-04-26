#include<stdio.h>
#include<string.h>
void Reserve(int before,char * num,int after)
{
    int i,j,yu,p = 1;//yu:余数
    long sum = 0;
    char tmp[30] = {0};
    for(i=strlen(num)-1;i>=0;i--)
    {//before进制->10进制
     if(num[i]>='0' && num[i]<='9')sum += (num[i] - '0') * p;//逆序也比较妙
        else if(num[i]>='A' && num[i]<='Z')sum += (num[i] - 'A' + 10) * p;
        else sum+=(num[i]-'a'+10)*p;
        p *= before;
    }
    for(i=0;sum!=0;i++){//10进制->after进制
        yu = sum % after;
        sum /= after;
        if (yu >= 10)tmp[i] = yu - 10 + 'A';
        else tmp[i] = yu + '0';
    }
    i = i-1;//Attention!
    j = 0;
    while(i >= 0)num[j++] = tmp[i--];
    num[j] = 0;
    printf("%s\n",num);
}
int main(){
    int a,b;
    char n[30];
    scanf("%d%s%d",&a,n,&b);
    if(n=='0')printf("%d",0);
    Reserve(a,n,b);
    return 0;
}
