#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int l_find(char *a, char *b)
{
    int b_len = strlen(b) , a_len = strlen(a) ;
    int idx = 0 ;
    for(int i=0; i<b_len; i++){
        int flag = 0 ;
        if(b[i] == a[0]){
            flag = 1 ;
            int b_idx = i ;
            for(int j=0; j<a_len; j++)
                if(b[b_idx++]!=a[j]) flag = 0 ;
            if(flag){
                idx = i ;
                break ;
            }
        }
    }
    return idx + a_len ;
}

int r_find(char *a, char *b)
{
    int b_len = strlen(b) , a_len = strlen(a) ;
    int idx = 0 ;
    for(int i=0; i<b_len; i++){
        int flag = 0 ;
        if(b[i] == a[0]){
            flag = 1 ;
            int b_idx = i ;
            for(int j=0; j<a_len; j++)
                if(b[b_idx++]!=a[j]) flag = 0 ;
            if(flag)
                idx = i ;
        }
    }
    return idx ;
}

int main()
{
    int t = 0 ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        char s1[80] = {0} ;
        char s2[80] = {0} ;
        char s[80] = {0} ;
        scanf("%s%s%s",&s1,&s2,&s) ;
        int idx1 , idx2 ;
        idx1 = l_find(s1,s) ; idx2 = r_find(s2,s) ;
        printf("case #%d:\n%d\n",i,idx2-idx1) ;
    }
}