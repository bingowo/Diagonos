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

    long long* res = (long long*)malloc(2*sizeof(long long));
    memset(res,0,2*sizeof(long long));
    //printf("%lld, %lld\n",res[0],res[1]);
    int i = 0;
    while(s[i]!=0)
    {
        long long temp = res[0];
        res[0] = (-1)*temp - res[1];
        res[1] = temp - res[1];
        res[0] += s[i] - '0';
        //printf("%lld, %lld, s[%d] = %c\n",res[0],res[1],i,s[i]);
        i++;

    }

    //printf("%s\n",s);
    int flag1 = 0,flag2 = 0,flagi = 0;//a = 0,b = 0,b = i

    if(res[0] == 0){flag1 = 1;}
    if(res[1] == 0){flag2 = 1;}
    if(res[1] == 1){flagi = 1;}

    if(flag1 == 1)
    {
        if(res[1]>0)
        {
            if(res[1] == 1){printf("i");free(s);free(res);return 0;}
            else{printf("%lldi",res[1]);free(s);free(res);return 0;}
        }
        else if(res[1]==0){printf("0");free(s);free(res);return 0;}
        else{printf("%lld",res[1]);free(s);free(res);return 0;}
    }
    else
    {
        printf("%lld",res[0]);
        if(res[1]>0)
        {
            if(res[1] == 1){printf("+i");free(s);free(res);return 0;}
            else if(res[1] == -1){printf("i");free(s);free(res);return 0;}
            else{printf("+%lldi",res[i]);}
        }
        else if(res[1] == 0){free(s);free(res);return 0;}
        else{printf("%lldi",res[1]);}
    }

    free(s);
    free(res);
    return 0;
}
