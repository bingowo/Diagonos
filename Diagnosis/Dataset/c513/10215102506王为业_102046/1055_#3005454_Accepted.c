//string\1055.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char str[1000005];
char ans[1000005];

int arr[80];
int search(char c)
{
    int pos;
    if('0'<=c&&c<='9'){
        pos=c-'0';
    }else if('A'<=c&&c<='Z'){
        pos=c-'A'+20;
    }else if('a'<=c&&c<='z'){
        pos=c-'a'+50;
    }
    return pos;
}

int maxlen=0;
void sum_up(int i,int j)
{
    int newlen=j-i;
    if(newlen>maxlen){
        for(int k=0;k<newlen;++k){
            ans[k]=str[i+k];
        }
        ans[newlen]='\0';
        maxlen=newlen;
    }
}


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char c;
    scanf("%s",str);
    int slen=strlen(str);
    if(slen==1){
        printf("%s",str);
    }else{
        int i=0,j=1;
        arr[search(str[0])]=TRUE;
        while(j<slen){
            int tempos=search(str[j]);
            if(arr[tempos]){
                int before=i;
                while(i!=j){
                    int ipos=search(str[i]);
                    //arr[ipos]=FALSE; wrong place
                    ++i;
                    if(ipos==tempos){
                        break;
                    }
                    arr[ipos]=FALSE;
                }
                sum_up(before,j);//[)
            }else{
                arr[tempos]=TRUE;
            }
            ++j;
        }
        sum_up(i,j);
        printf("%s",ans);
    }
    return 0;
}

