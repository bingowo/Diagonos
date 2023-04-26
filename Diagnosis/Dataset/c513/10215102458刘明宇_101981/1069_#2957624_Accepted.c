#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int judge(int m)
{
    int cnt = 0;
    int num[100001];
    while(m > 0){
        num[cnt++] = m % 10;
        m = m / 10;
    }
    int flag = 1;

    for(int i = 0;i < cnt-1;i++){
        if(num[i] != num[cnt-1-i]) flag = -1;
    }
    return flag;
}

int get_convert(int m)
{
    int cnt = 0;
    int num[100001];
    while(m > 0){
        num[cnt++] = m % 10;
        m = m / 10;
    }
    int len = cnt - 1;
    int con = 0;
    int tens = 1;
    int i = len;
    while(i>=0){
        con += tens*num[i];
        i--;
        tens*=10;
    }
    return con;
}

int main()
{
    int n;
    scanf("%d",&n);
    int flag = judge(n);
    int m = get_convert(n);
    int cnt = 0;
    while(flag == -1){
        flag = judge(m+n);
        m = m+n;
        n = get_convert(m);
        cnt++;
    }
    printf("%d %d",cnt,m);

    //printf("%d",m);

}