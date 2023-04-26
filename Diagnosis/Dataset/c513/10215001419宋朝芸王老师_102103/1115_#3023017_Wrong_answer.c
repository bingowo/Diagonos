#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){  //asc
    return *(char*)a - *(char*)b;
}

void process(char in[], int len){

    int i;
    for(i = len-1; i >= 0; i--)
        if(in[i-1] < in[i]) break;

    int start = i-1, track = len-1, min = in[track];
    for(int j = start; j < len; j++)
        if(in[j] > in[start] && in[j] <= min){
            min = in[j];
            track = j;
        }

    int temp = in[start];
    in[start] = min, in[track] = temp;

    qsort(in+i,len-i,sizeof(in[0]),cmp);   //+1 /-1?
    //in[len] = '\0';
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char in[21] = {'\0'};
        scanf("%s",in);
        int len = strlen(in);

        process(in,len);
        printf("case #%d:\n%s\n",R,in);
    }
    return 0;
}
