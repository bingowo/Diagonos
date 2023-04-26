#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_first(char *a, char *b)
{
    int b_len = strlen(b) , a_len = strlen(a) ;
    int idx = -1 ;
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
    return idx ;
}

int find_last(char *a, char *b)
{
    int b_len = strlen(b) , a_len = strlen(a) ;
    int idx = -1 ;
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
        int idx1_f, idx1_l, idx2_f, idx2_l ;
        idx1_f = find_first(s1,s); idx1_l = find_last(s1,s) ;
        idx2_f = find_first(s2,s); idx2_l = find_last(s2,s) ;
        int d1 = idx2_l - idx1_f - strlen(s1) ;
        int d2 = idx1_l - idx2_f - strlen(s2) ;
        int d = d1 > d2 ? d1 : d2 ;
        if(idx1_l == -1 || idx2_l == -1)
            d = 0 ;
        printf("case #%d:\n%d\n",i,d) ;
    }
}