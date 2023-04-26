#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//typedef struct {char c; int times;}Var;
////typedef struct {char *s; int length} Str;
//long long Sum()
int cmp(const void* a, const void *b)
{
    return strlen((char*)a) - strlen((char*)b);
}
int main()
{
//    Str *p;
//    Var var[62]; for(int i = 0; i<62; i++) var[i].times = 0;
    int T; scanf("%d",&T);
    int ret = 1,Ret = 1;//用来判断是否中途退出
    char* Str[T];
    for(int i = 0; i<T; i++)
    {
        Str[i] = (char*) malloc(100*sizeof(char));
    }
    scanf("%s",Str[0]);
//    printf("%s\n",Str[0]);
    char Val[100] = {0};//存放字符顺序
//    for(int j = 0,k = 0; j<strlen(*Str); j++)
//    {
//        if(!var[k].times) {var[k++].c = (*Str)[j]; var[k].times = 1; cnt++}
//    }
    int i = 0;
    for(int j = 0;i< strlen(Str[0]); i++)
    {
        if(i!= strlen(Str[0])-1){
            if((Str[0])[i]!=(Str[0])[i+1]){
                Val[j++] = (Str[0])[i];
//                printf("%c\n",(Str[0])[i]);
//                printf("i = %d\n",i);
            }
        }
        else{
            {
                Val[j] = (Str[0])[i];
//                printf("%c\n",(Str[0])[i]);
            }
        }
    }
//    printf("i = %d\n",i);
//    printf("%s\n",Val);
    for(int i = 1; i<T; i++)
    {
        scanf("%s",Str[i]);
        char *si = Str[i];
        for(int j = 0,k = 0; j< strlen(si)&&k< strlen(Val); j++)
        {
            if(j!=strlen(si)-1&&si[j]==si[j+1]) continue;
            if(si[j]==Val[k]) k++;
            else{
                ret = 0; break;
            }
        }
        if(!ret) {
            printf("-1"); Ret = 0; break;
        }
    }
    long long sum = 0;
    if(Ret){
        qsort(Str,T,sizeof(char*),cmp);
        int mid = T/2;
        int length = strlen(Str[mid]);
        for(int i = 0; i<T; i++)
        {
            int dis = (strlen(Str[i])-length);
            dis = dis>0?dis:-dis;
            sum+=dis;
        }
        printf("%lld",sum);
    }
    return 0;
}
//变换次数即为到均长串的距离和
