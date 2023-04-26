#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//typedef struct{
//    char letter;
//    double frequency;
//
//}ALP;
double*input(void)
{
    double*frequency;
    frequency = (double*)malloc(sizeof(double)*26);
    for(int j = 0;j < 26;j++)
    {
        scanf("%lf",&frequency['A'+j]);
    }
    return frequency;
}
int cmp(const void*a,const void*b)
{
    if(toupper(*(char*)a) == *(char*)b)
        return 1;
    else if(*(char*)a == toupper(*(char*)b))
        return -1;
    else
        return input()[toupper(*(char*)b)] - input()[toupper(*(char*)a)];
        //alphabet[*(char*)b].frequency - alphabet[*(char*)a].frequency;

}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {

        char input1[101];
        scanf("%s",input1);
        input();
        qsort(input1,strlen(input1),sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,input1);
        free(input());

    }
    return 0;
}
