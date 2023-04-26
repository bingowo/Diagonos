#include <stdio.h>
#include <string.h>

char s[10010];
int zs[10010];
int xs[10010];
char s2[10010];
int zs2[10010];
int xs2[10010];
int ansz[10010];
int ansx[10010];
int N;
int sig;
int len1,len2;
int LEN1,LEN2;

int main()
{
    scanf("%s %s",s,s2);
    scanf("%d",&N);
    int len = strlen(s);
    len1 = len;
    for(int i = 0;i < len;i++){
        if(s[i] == '.'){
            len1 = i;
            len2 = len-i-1;
            break;
        }
    }
    //判断了小数点的位置
    for(int i = len1-1,j = 0;i >= 0;i--,j++)
    {
        zs[j] = s[i]-'0';
    }
    //保存了整数
    for(int i = len1+1,j = 0;i < len;i++,j++)
    {
        xs[j] = s[i]-'0';
    }
    //保存了小数
    len = strlen(s2);
    LEN1 = len;
    for(int i = 0;i < len;i++){
        if(s2[i] == '.'){
            LEN1 = i;
            LEN2 = len-i-1;
            break;
        }
    }
    //判断了小数点的位置
    for(int i = LEN1-1,j = 0;i >= 0;i--,j++)
    {
        zs2[j] = s2[i]-'0';
    }
    //保存了整数
    for(int i = LEN1+1,j = 0;i < len;i++,j++)
    {
        xs2[j] = s2[i]-'0';
    }
    int t = 0;
    int LEN = LEN2 > len2 ? LEN2 : len2;
    for(int i = LEN-1;i >= 0;i--)
    {
        t = t+xs[i]+xs2[i];
        ansx[i] = t%10;
        t /= 10;
    }
    if(t) sig = 1;
    int start = 1;
    int LENZ = LEN1 > len1 ? LEN1 : len1;
    t = 0;
    for(int i = 0;i < LENZ;i++){
        t = t+zs[i]+zs2[i];
        if(sig && start){
            t += 1;
            start = 0;
        }
        ansz[i] = t%10;
        t /= 10;
    }
    if(t) ansz[LENZ++]++;
    sig = 0;
    int fansx[10010];
    for(int i = 0;i < N;i++){
        fansx[i] = ansx[i];
    }
    if(ansx[N] >= 5){
        int t2 = 1;
        for(int i = N-1;i >= 0;i--){
            t2 = t2+ansx[i];
            fansx[i] = t2%10;
            t2 /= 10;
        }
        if(t2) sig = 1;
        if(sig)
        {
            t = 1;
            for(int i = 0;i < LENZ;i++){
                t = t+ansz[i];
                ansz[i] = t%10;
                t /= 10;
            }
        }
    }
    for(int i = LENZ-1;i >= 0;i--) printf("%d",ansz[i]);
    if(LENZ == 0) printf("0");
    printf(".");
    for(int i = 0;i < N;i++) printf("%d",fansx[i]);
}