#define MAX_LEN 1003
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	short sgn;
    int ilen;
    int *i;
    int flen;
    int *fl;
    char sg;
}NUM;

int COMPARE_OF_SORT_A(const void *p1, const void *p2){
    NUM a = *(NUM *)p1;
    NUM b = *(NUM *)p2;

    if(a.sgn != b.sgn) return b.sgn - a.sgn;
    if(a.sgn == 0){
        if(a.ilen != b.ilen) return a.ilen - b.ilen;
        else{
            for(int v = 0; v < a.ilen; v++)
                if(a.i[v] != b.i[v]) return a.i[v] - b.i[v];
            for(int v = 0; v < a.flen || v < b.flen; v++)
                if(a.fl[v] != b.fl[v]) return a.fl[v] - b.fl[v];
            return 0;
        }
    }
    else{
        if(a.ilen != b.ilen) return b.ilen - a.ilen;
        else{
            for(int v = 0; v < a.ilen; v++)
                if(a.i[v] != b.i[v]) return b.i[v] - a.i[v];
            for(int v = 0; v < a.flen || v < b.flen; v++)
                if(a.fl[v] != b.fl[v]) return b.fl[v] - a.fl[v];
            return 0;
        }
    }
}

void sort(void *a, int size, int typesize, char sortype){
    if(sortype == 'A') qsort(a,size,typesize,COMPARE_OF_SORT_A);
    else {
        fprintf(stderr,"Sort error!\n");
        return ;
    }
}

NUM write(const char *in){//reverse integer, not float!
    NUM re;
    re.fl = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    re.i = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    const char* head = in;
    re.sgn = 0;//default positive
    re.flen = re.ilen = 0;
    re.sg = 'Q';
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }//initialize

	if(*in == '-' || *in == '+'){
        re.sg = *in;
		if(*in == '-') re.sgn = 1;//negative
		in++,head++;
	}
    for(; *in != '.' && *in != '\0'; in++) re.ilen++;//ilen
    const char *point = in-1;
    for(int v = 0; point >= head; v++,point--) re.i[v] = *point - '0';//write i

    if(*in == '.') { 
		in++;//deal with '.'
		if(*in == '\0') re.flen++;
	}
    for(int v = 0; *in != '\0'; v++,in++){//write flen and fl
        re.fl[v] = *in - '0';
        re.flen++;
    }
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 
    while(re.flen > 1 && re.fl[re.flen-1] == 0) re.flen--;//del 0

    return re;
}

void Print(const NUM *in){
    if(in->sg != 'Q') putchar(in->sg);
	
	if(in->ilen == 0) putchar('0');//print int
	for(int v = in->ilen-1; v >= 0; v--) printf("%d",in->i[v]);
	
	if(in->flen != 0) putchar('.');//print float
	for(int v = 0; v < in->flen; v++) printf("%d",in->fl[v]);
}

int main(void){
	int T;
	scanf("%d",&T);
	NUM num[T];
	for(int v = 0; v < T; v++){
		char str[MAX_LEN];
		scanf("%s",str);
		num[v] = write(str);
	}
	
	sort(num,T,sizeof(NUM),'A');
	
	for(int v = 0; v < T; v++){
		Print(&num[v]);
		putchar('\n');
		free(num[v].fl);
		free(num[v].i);
	}
	
	return 0;
}