#include <stdio.h>
#include <stdlib.h>



char* ToBinaryString(long long n)//返回字符串指针，便于计算数组长度
{
    char* res = (char*)malloc(10000*sizeof(char));
    memset(res,0,10000*sizeof(char));
    long long r = 0;
    int i = 0;
    while(n!=0)
    {
        r = n%2;
        n = n/2;
        res[i] = r+'0';
        //printf("n = %lld,res[%d] = %c\n",n,i,res[i]);
        i++;
    }
    int j = 0,k = 0;
    char temp = 0;
    for(j = 0,k = i-1;j<k;j++,k--)
    {
        temp = res[j];
        res[j] = res[k];
        res[k] = temp;
    }

    return res;
}

int main()
{
    long long n = 0x0;
    scanf("%x",&n);

    char* s = ToBinaryString(n);
    //long long* base = (long long*)malloc(2*sizeof(long long));
    //memset(base,0,2*sizeof(long long));
    //base[0] = -1;base[1] = 1;//base为-1+i

    long long* res = (long long*)malloc(2*sizeof(long long));
    memset(res,0,2*sizeof(long long));
    //printf("%lld, %lld\n",res[0],res[1]);
    int i = 0;
    while(s[i]!=0)
    {
        res[0] = (-1)*res[0] - res[1];
        res[1] = res[0] - res[1];
        res[0] += s[i]+'0';
        printf("%lld, %lld, s[%d] = %c\n",res[0],res[1],i,s[i]);
        i++;

    }

    //printf("%lld\n",n);
    printf("%s\n",s);
    printf("%lld, %lld\n",res[0],res[1]);
    free(s);
    //free(base);
    free(res);
    return 0;
}
