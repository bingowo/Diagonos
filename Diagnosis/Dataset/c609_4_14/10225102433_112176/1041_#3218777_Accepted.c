//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//    char s[17];
//}node;
//
//char *trans(char *s)
//{
//    int cnt = 0;
//    int a[128] = {0};
//    while(*s)
//    {
//        a[*s++]++;
//    }
//    for(int i = 0; i < 128;i++)
//    {
//        if(a[i] != 0)
//        {
//            char c = i;
//            s[cnt++] = c;
//        }
//    }
//    s[cnt] = '\0';
//    return s;
//}
//
//int cmp(const void *a,const void *b)
//{
//    return strcmp(((node*)a)->s,((node*)b)->s);
//}
//
//int main()
//{
//    int n;scanf("%d",&n);
//    for(int i = 0;i < n;i++)
//    {
//        printf("case #%d:\n",i);
//        char s[20] = {0};
//        scanf("%s",s);
//        char *k = trans(s);
//        int len = strlen(k);
//        int num1 = (int)pow(2,len)-1;
//        node ch[num1];
//        memset(ch,'\0',sizeof(ch));
//        int num = (1<<len)-1;
//        for(int j = 1;j <= num;j++)
//        {
//            int p = j;
//            int ans = 0;
//            char res[17] = {0};
//            for(int h = 0;h < len;h++)
//            {
//                if(p&1)
//                    res[ans++] = k[h];
//                p = p>>1;
//            }
//            strcpy(ch[j-1].s,res);
//        }
//        qsort(ch,num1,sizeof(ch[0]),cmp);
//        for(int j = 0;j < num1;j++)
//        {
//            printf("%s\n",ch[j].s);
//        }
//    }
//    return 0;
//}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char str[20];

typedef struct {char s[20];}node;
node ch[1<<17];

int cmp1(const void *a,const void *b)
{
    return *(char*)a - *(char*)b;
}

int cmp(const void* a,const void* b)
{
    return strcmp(((node*)a)->s,((node*)b)->s);
}

int main()
{
    int T;scanf("%d",&T);
    char c = getchar();
    for(int o = 0;o < T;o++)
    {
        gets(str);
        unsigned len = strlen(str),len1 = 1;
        qsort(str,len,sizeof(char),cmp1);
        for(int i = 0,j = 0;j < len;j++){
            if(str[i] != str[j]){
                str[++i] = str[j];
                len1++;
            }
        }
        int len2 = 1<<len1;
        for(int i = 1;i < len2;i++){
            int cnt = 0;
            for(int j = 0;j < len1;j++){
                if(i&(1<<j)){
                    ch[i-1].s[cnt++] = str[j];
                }
            }
        }
        qsort(ch,len2-1,sizeof(ch[0]),cmp);
        printf("case #%d:\n",o);
        for(int k = 0;k < len2-1;k++){
            printf("%s\n",ch[k].s);
        }
        memset(str,0,sizeof(str));
        memset(ch,0,sizeof(ch));
    }

    return 0;
}