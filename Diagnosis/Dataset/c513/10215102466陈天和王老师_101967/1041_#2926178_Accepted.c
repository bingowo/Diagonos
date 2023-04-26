

#include <stdio.h>
int main(){
    char s[51];
    char *p,*q;
    scanf("%s",s);
    p=s;
    q=s+1;

    int max=1;
    while(*q){
        //这个循环条件很重要，看后面指针是否为零
        int cnt=1;
        while(*p!=*q && *q){
            //*q这个条件不能少，要不你指针要越界
            cnt++;
            p++;
            q++;
        }

        if(cnt>=max){
            max=cnt;
        }
        p++;
        q++;
    }
    printf("%d",max);
    return 0;
}
//max一定要赋初始值为1而不是0，不然对单个的测试节点——或｜过不了