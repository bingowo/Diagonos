#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b){
    char c=*(char *)a,d=*(char *)b;
    return c-d;
}

int main(){
    int t,a=0;
    char s[21],ans[10];
    int num[128];
    scanf("%d",&t);
    while(a<t){
        scanf("%s",s);
        memset(ans,0,sizeof(ans));
        memset(num,0,sizeof(num));
        int l=strlen(s),n=0;
        for(int i=0;i<l;i++)num[s[i]]++;
        if(num['Z']>0){
            while(num['Z']>0){
                ans[n++]='0';
                num['Z']--;num['E']--;num['R']--;num['O']--;
            }
        }
        if(num['W']>0){
            while(num['W']>0){
                ans[n++]='2';
                num['T']--;num['W']--;num['O']--;
            }
        }
        if(num['U']>0){
            while(num['U']>0){
                ans[n++]='4';
                num['F']--;num['O']--;num['U']--;num['R']--;
            }
        }
        if(num['X']>0){
            while(num['X']>0){
                ans[n++]='6';
                num['S']--;num['I']--;num['X']--;
            }
        }
        if(num['G']>0){
            while(num['G']>0){
                ans[n++]='8';
                num['E']--;num['I']--;num['G']--;num['H']--;num['T']--;
            }
        }
        if(num['O']>0){
            while(num['O']>0){
                ans[n++]='1';
                num['O']--;num['N']--;num['E']--;
            }
        }
        if(num['S']>0){
            while(num['S']>0){
                ans[n++]='7';
                num['S']--;num['E']--;num['V']--;num['E']--;num['N']--;
            }
        }
        if(num['F']>0){
            while(num['F']>0){
                ans[n++]='5';
                num['F']--;num['I']--;num['V']--;num['E']--;
            }
        }
        if(num['T']>0){
            while(num['T']>0){
                ans[n++]='3';
                num['T']--;num['H']--;num['R']--;num['E']--;num['E']--;
            }
        }
        if(num['I']>0){
            while(num['I']>0){
                ans[n++]='9';
                num['N']--;num['I']--;num['N']--;num['E']--;
            }
        }
        qsort(ans,n,sizeof(char),cmp);
        printf("case #%d:\n%s\n",a,ans);
        a++;
    }
}