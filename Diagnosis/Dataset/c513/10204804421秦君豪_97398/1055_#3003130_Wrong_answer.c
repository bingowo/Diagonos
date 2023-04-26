#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int lli;
#define maxn 1000001
int window[256]={0};
int main()
{
    char *s =(char*)malloc(sizeof(char)*maxn);
    int m,n=0;//滑动窗口

    int first,last=0;
    int temp,f,l,length=0;
    gets(s);
    window[s[0]]=1;
    for(first =0 ; first<strlen(s);first++)
    {
//        printf("%d",first);
        if(first==last) last++;
        if(window[s[first]]==1&&first!=0)
        {
            window[s[first]]--;
            continue;
        }
//        printf("%d",first);
        while(last<strlen(s)&&window[s[last]]!=1)
        {
            window[s[last]]++;
//            printf("!%c%d",s[last],window[s[last]]);
            last++;
        }
        last--;
//        printf("%d",first);
        temp = (last-first+1);
//        printf("%d\n",first);
        if(temp>length)
        {
            length = temp;
            f = first;l=last;
        }
        window[s[first]]--;
        if(last-first<length) break;
        if (last==strlen(s)) break;
    }
    for(int i=f;i<length;i++)
        printf("%c",s[i]);
}

