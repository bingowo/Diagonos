#include<stdio.h>
#include<string.h>

void int_(int a);
void double_(double b);
int atoi(char* a);
double atod(char* a);

int main(){
    char a[31];
    while(scanf("%s",a)!=EOF){
        if(strchr(a, '.')==0)
        int_(atoi(a));
        else
        double_(atod(a));
    }
}

void int_(int a){
    int c = sizeof(a);
    unsigned char *p = (unsigned char*)&a;
    while(c--)
    printf("%02x ",*p++);
    printf("\n");
}

void double_(double a){
    int c = sizeof(a);
    unsigned char *p = (unsigned char*)&a;
    while(c--)
    printf("%02x ",*p++);
    printf("\n");
}

int atoi(char* a){
    int s = 0,flag = 0;
    if(*a == '-'){
        flag = 1;
    }
    for(int i = flag;i < strlen(a);i++ )
    s = s*10 + *(a+i) - '0';
    if(flag == 1)return -s;
    else return s;
}

double atod(char* a){
    int s = 0;
    int i, b,flag = 0;
    double t;
    if(*a == '-')flag = 1;
    i = flag;
    while(i < strlen(a)){
        if(*(a+i)!='.')
            s = s*10 + *(a+i)-'0';
        else b = i;
        i++;
    }
    t = (double)s;
    for(int j = i-1-b;j > 0; j--)
    t = t/10;
    if(flag == 1)return -t;
    else return t;
}
