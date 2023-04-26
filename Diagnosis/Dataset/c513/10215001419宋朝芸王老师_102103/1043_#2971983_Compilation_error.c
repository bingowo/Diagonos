#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Remove(const char *a, int len, int ori){
    return 0;
}

int Remove(const char *a, int len, int ori){
    char temp_a[101] = {0};

    int p = 0;
    temp_a[p] = a[0];
    int cnt = 1;

    for(int k = 1; k < len; k++){
        if(a[k] == temp_a[p]) continue;
        else {
            temp_a[++p] = a[k];
            cnt++;
        }
    }
    temp_a[++p] = '\0';


    if(p == len || p == 1) return(ori - p);
    else return Remove(temp_a,p,ori);
}


char* adds(const char *a, int pos, char c, int len, char *tryarray){
    char *p = tryarray;
    int i = 0, j = 0;

    while(i < pos) p[i++] = a[j++];
    p[i++] = c;
    while(i < len) p[i++] = a[j++];
    p[i] = '\0';

    return tryarray;
}


int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        char in[101];
        char tryarray[102];
        scanf("%s",in);

        int ans = 0;
        int len = strlen(in);
        for(int i = 0; i <= strlen(in); i++){
            ans = max(ans,
                      Remove(
                             adds(in,i,'A',len+1,tryarray),len+1,len+1));
            ans = max(ans,
                      Remove(
                             adds(in,i,'B',len+1,tryarray),len+1,len+1));
            ans = max(ans,
                      Remove(
                             adds(in,i,'C',len+1,tryarray),len+1,len+1));
        }

        printf("case #%d:\n%d\n",R,ans);

    }
    return 0;
}