#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int lli;
#define maxn 1000001
int window[256]={0};
int main()
{
    memset(window,0,sizeof(window));
    char *s =(char*)malloc(sizeof(char)*maxn);

    int first,last=0;
    int temp,f,length=0;
    gets(s);
    window[s[0]]=1;
    for(first =0 ; first<strlen(s);first++)
    {

        if(first==last) last++;

        if(window[s[last]]==1&&first!=0)
        {
            window[s[first]]--;
            continue;
        }

        while(last<strlen(s)&&window[s[last]]==0)
        {

            window[s[last]]++;
            last++;
        }

//        printf("%c %d %d %c\n",s[first],window[s[first]],window[s[last]],s[last]);
        temp =last-first;
        if(temp>length)
        {
            length=temp;
            f=first;
        }
        window[s[first]]--;
        if(last==strlen(s)) break;
    }
    for(int i=f;i<f+length;i++)
        printf("%c",s[i]);
}

