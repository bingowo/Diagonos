#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){  //asc
    return *(char*)a - *(char*)b;
}

void process(char in[], int len, int R){

    int i;
    for(i = len-1; i >= 0; i--)
        if(in[i-1] < in[i]) break;

    //special for x000
    if(i == 0){in[len] = '0';in[++len] = '\0';i++;}

    //find max in i to len-1
    int start = i-1, track = len-1, min = in[track];
    for(int j = start+1; j < len; j++)
        if(in[j] >= min){
            min = in[j];
            track = j;
        }

    //find min in {exc}
    for(int j = start; j < len; j++)
        if(in[j] > in[start] && in[j] <= min){
            min = in[j];
            track = j;
        }

    //change in[start]
    int temp = in[start];
    in[start] = min, in[track] = temp;

    //asc
    qsort(in+i,len-i,sizeof(in[0]),cmp);   //+1 /-1?

    //del zero
    temp = 0;
    while(in[temp] == 0) {temp++;len--;}

    printf("case #%d:\n%s\n",R,in+temp);
    return;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char in[21] = {'\0'};
        scanf("%s",in);
        int len = strlen(in);

        process(in,len,R);
    }
    return 0;
}
