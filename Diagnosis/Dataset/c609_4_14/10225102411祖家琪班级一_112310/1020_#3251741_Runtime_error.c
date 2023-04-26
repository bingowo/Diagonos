#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int strnumcmp(const void*,const void*);
    char *s[100] = {0};
    int n = 0;
    char tmp[31];
    for(int i=0;scanf("%s",tmp) != EOF;i++){
        *(s+i) = (char *)malloc(strlen(tmp));
        strcpy(*(s+i),tmp);
        n++;
    }
    qsort(s,n,sizeof(*s),strnumcmp);
    for(int i=0;i<n;i++){
        printf("%s ",*(s+i));
    }
    for(int i=0;i<n;i++){
        free(*(s+n));
    }
    return 0;
}
int strnumcmp(const void* a,const void* b)
{
    char *pa,*pb,*numa,*numb;
    pa = *(char **)a;
    pb = *(char **)b;
    int i = 0,siga = 0,sigb = 0;
    int la = strlen(pa);
    int lb = strlen(pb);
    while(*(pa+i) >= 'A' || *(pa+i) < '0'){
        i++;
        if(i>=la){//*a has no nums
            siga = 1;
        }
    }
    if(!siga) numa = pa+i;
    i = 0;
    while(*(pb+i) >= 'A' || *(pb+i) < '0'){
        i++;
        if(i>=lb){//*b has no nums
            sigb = 1;
        }
    }
    if(!sigb) numb = pb+i;
    //printf("%s\n",numa);
    //printf("%s\n",numb);
    if(!siga && !sigb){//both of a and b have nums;
        if(strcmp(numa,numb) == 0) return strcmp(pa,pb);//the a's nums are equal to b's nums;
        else if(strlen(numa) != strlen(numb)) return strlen(numa) - strlen(numb);
        else return strcmp(numa,numb);
    }
    else if(siga && !sigb) return -1;
    else if(sigb && !siga) return 1;
    else return strcmp(pa,pb);
}
