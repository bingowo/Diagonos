#include <stdio.h>
#include <stdlib.h>
//sizeof(指针名)/sizeof(int)并不会返回数组长度！！！！！！！！！！！！！！
typedef struct{
    int ct[50];
    int len;
}NUM;
//int cmp(const void*a,const void*b)
//{
//    int len1,len2,i;
//    len1 = **(int**)a,len2 = **(int**)b;
//    if(len1 < len2)
//    {
//        for(i = 1;i < len1+1;i++)
//        {
//            if(*(*(int**)a+i) != *(*(int**)b+i))
//                return *(*(int**)b+i) - *(*(int**)a+i);
//        }
//        return 1;
//    }
//    else if(len1 > len2)
//    {
//        for(i = 1;i < len2+1;i++)
//        {
//            if(*(*(int**)a+i) != *(*(int**)b+i))
//                return *(*(int**)b+i) - *(*(int**)a+i);
//        }
//        return -1;
//    }
//    else
//    {
//        for(i = 1;i < len1 + 1;i++)
//        {
//            if(*(*(int**)a+i) != *(*(int**)b+i))
//                return *(*(int**)b+i) - *(*(int**)a+i);
//        }
//    }
//}
//int main()
//{
//    int T,i;
//    scanf("%d",&T);
//    for(i = 0;i < T;i++)
//    {
//        int**input;
//        int N;
//        scanf("%d",&N);
//        input = (int**)malloc(N*sizeof(int*));
//        for(int j = 0;j < N;j++)
//        {
//            int tempt[50];
//            int count = 0;
//            while(scanf("%d",&tempt[count]))
//            {
//                if(tempt[count] == -1)
//                    break;
//                count++;
//            }
//            input[j] = (int*)malloc((count+3)*sizeof(int));
//            input[j][0] = count;
//            for(int k = 1;k < count + 1;k++)
//                input[j][k] = tempt[k - 1];
//        }
//        qsort(input,N,sizeof(int*),cmp);
//        for(int j = 0;j < N;j++)
//        {
//            for(int k = 1;k < input[j][0] + 1;k++)
//            {
//                printf("%d%c",input[j][k],(k == input[j][0])?'\n':' ');
//            }
//            free(input[j]);
//        }
//        free(input);
//
//    }
//    return 0;
//}
int cmp(const void*a,const void*b)
{
    NUM*st1,*st2;
    st1 = (NUM*)a,st2 = (NUM*)b;
    if(st1->len < st2->len)
    {
        for(int i = 0;i < st1->len - 1;i++)
        {
            if(st1->ct[i] != st2->ct[i])
                return st2->ct[i] - st1->ct[i];
        }
        return 1;
    }
    else// if(st1->len > st2->len)
    {
        for(int i = 0;i < st2->len - 1;i++)
        {
            if(st1->ct[i] != st2->ct[i])
                return st2->ct[i] - st1->ct[i];
        }
        return -1;
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N,j;
        scanf("%d",&N);
        NUM num[N];
        for(j = 0;j < N;j++)
        {
            int count = 0;
            while(scanf("%d",&num[j].ct[count++]))
            {
                if(num[j].ct[count] == -1)
                {
                    num[j].len = count;
                    break;
                }
            }
        }
        qsort(num,N,sizeof(num[0]),cmp);
        for(j = 0;j < N;j++)
        {
            for(int k = 0;k < num[j].len - 1;k++)
                printf("%d%c",num[j].ct[k],(k == num[j].len - 1)?'\n':' ');

        }
    }
    return 0;
}
