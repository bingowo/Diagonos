int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){

        char s[2001];
        char s0[2001];
        int M;
        scanf("%d",&M);
        gets(s0);
        gets(s);
        unsigned long int L=strlen(s);
        int i,start,l,p,space;
        for(i=0;s[i]==' ';i++);
        printf("case #%d:\n",t);
        while(i<L){
            start=i;
            int words_len=0,words_num=0;
            for(;words_len+words_num<=M&&i<L;){
                for(l=0,p=i;s[p]!=' '&&p<L;p++,l++);
                if(words_len+words_num<=M){
                    words_len+=l;words_num++;
                    for(i=p;s[i]==' ';i++);
                }else break;
            }
            space=M-words_len;
            int j=start;
            words_num--;
            while(j<i){
                while(s[j]!=' '&&j<L)printf("%c",s[j++]);
                while(s[j]==' '&&j<L)j++;
                if(i==L&&words_num)printf(" ");
                else{
                    for(p=0;words_num&&p<space/words_num;p++)printf(" ");
                    space-=p;
                }
                words_num--;
            }printf("\n");
        }
    }
    return 0;
}
