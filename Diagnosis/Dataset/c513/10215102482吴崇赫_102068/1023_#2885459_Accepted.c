#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 105

int getNum(char* s)
{
    int n=strlen(s);int ans=0;
    int p=0;
    while(!isdigit(s[p])&&p<n)p++;
    if(p==n)return -1;
    while(isdigit(s[p])&&p<n){
        ans=ans*10+s[p]-'0';
        ++p;
    }
    return ans;
}


int cmp(const void* a,const void* b)
{
    if(getNum((char*)a)!=getNum((char*)b))return getNum((char*)a)>getNum((char*)b)?1:-1;
    else return strcmp((char*)a,(char*)b);
}

int main()
{
    char input[N][35];int cnt=0;
    while(scanf("%s",input[cnt])>0)cnt++;
    qsort(input,cnt,sizeof(input[0]),cmp);
    for(int i=0;i<cnt;++i)printf("%s%c",input[i],i==cnt?'\n':' ');
    //printf("%d",getNum(s));
    return 0;
}
