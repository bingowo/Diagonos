#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 110

//int check(char *s)//无重复部分返回1，否则返回0
//{
//    int ret = 1;
//    for(int i = 0; i<strlen(s)-1; i++){
//        if(s[i]==s[i+1]) {
//            ret = 0;
//            break;
//        }
//    }
//    return ret;
//}

//check正常
//int main()
//{
//    char s[] = "ababababcc",*ps = s;
//    printf("%d", check(ps));
//    return 0;
//}

int  del(char *s)//返回指向最终字串的指针
{
//    if(s=="") return 0;
    if(strlen(s)<=1) return strlen(s);
    if(strlen(s)==2)
    {
        if(s[0]==s[1]) return 0;
        else return 2;
    }
    char *v = (char*) calloc(MAXN,sizeof(char));
    int i = 0,j = 0;
    int ret = 0,Ret = 1;
    for(; i<strlen(s)-1; i++)
    {
        if(s[i]==s[i+1]){
            Ret = 0;
            ret = 1;
        }
        else{
            if(ret)
                ret = 0;
            else
                v[j++] = s[i];
        }
    }
    if(s[i]!=s[i-1]&&!ret) v[j] = s[i];
    v[j+1] = 0;
    if(Ret) return strlen(v);
    return del(v);
}
//
////该函数异常，乱码
//int main()
//{
//    char s[] = "abccaab";
//    printf("%d",del(s));
////    char *pf =(char*) malloc(MAXN*sizeof(char));
////    pf[0] = 0;
////    pf = del(s);
////    printf("%d\n", strlen(pf));
////    for(int i = 0; i< strlen(pf); i++)
////        printf("%c\n",pf[i]);
//    return 0;
//}

char* insert(int i, char c, char *s)
{
    char *v = (char*)calloc(MAXN,sizeof(char));
    for(int j = 0; j<i; j++)
    {
        v[j] = s[j];
    }
    v[i] = c;
    for(int j = i+1; j<=strlen(s); j++)
    {
        v[j] = s[j-1];
    }
    return v;
}

////函数异常，乱码
////int main()
////{
////    char s[] = "abcca",*ps = s,*pv = 0;
////    pv = insert(1,'a',ps);
////    for(int i = 0; pv[i]; i++)
////    {
////        printf("%c",pv[i]);
////    }
////    return 0;
////}
//
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        printf("case #%d:\n",i);
        char s[MAXN] = {0},*ps = s;
        scanf("%s",s);
        int len = strlen(s)+1;
        int maxdel = 0;
        for(char c = 'A'; c<='C'; c++)
        {
            for(int j = 0; j<=strlen(s); j++)
            {
                char *pp = insert(j,c,ps);
                int Len = del(pp);
                if(len-Len>maxdel) maxdel = len-Len;
            }
        }
        printf("%d\n",maxdel);
    }
    return 0;
}