
        }
        for (i=0;i<strlen(str);i++){
            o[str[i]]=i;
        }
        while ((c=getchar()) !='\n'){//取第二行的各个字符串
            if (c ==' '){
                length[n]=len;
                start[n]=num-len;
                n++;
                len=0;//重置长度
                continue;
            }
            ch[num]=c;
            if (c>='a' && c<='z'){
                s[num]=1;
            }
            else if(c>='A' && c<='Z'){
                s[num]=0;
            }
            num++;
            len++;
        }
        //开始排序,使用index数组记录排序后顺序
        for (i=0;i<n;i++){
            index[i]=i;
        }
        for (i=0;i<n;i++){
            k=i;
            for (j=i+1;j<n;j++){
                flag=cmp(ch,o,s,start[index[k]],length[index[k]],start[index[j]],length[index[j]]);
                if (flag==-1)
                    k=j;
                flag=0;
            }
            if (k != i){
                swap(&index[i],&index[k]);
            }
        }
        for (i=0;i<n;i++){
            for (j=start[index[i]];j<start[index[i]]+length[index[i]];j++){
                printf("%c",ch[j]);
            }
            putchar(' ');
        }
    }
}

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int cmp(char *ch, int *o, int *s, int st1, int len1, int st2, int len2)
{
    int i=0;
    int flag=0;
    char *str1 = (char *)malloc(sizeof(char)*(len1+1));
    char *str2 = (char *)malloc(sizeof(char)*(len2+1));
    for (i=0;i<len1;i++){
        str1[i]=ch[st1+i]-32*s[ch[st1+i]];
    }
    for (i=0;i<len2;i++){
        str2[i]=ch[st2+i]-32*s[ch[st2+i]];
    }
    i=0;
    while (i<len1 && i<len2){
        if (o[str1[i]]>o[str2[i]]){
            flag=1;
            return flag;
        }
        else if (o[str1[i]]<o[str2[i]]){
            flag=-1;
            return flag;
        }
        else{
            i++;
            continue;
        }
    }
    if (len1 == len2){
        flag=0;
    }
    else if (len1 > len2){
        flag=1;
    }
    else{
        flag=-1;
    }
    free(str1);
    free(str2);
    return flag;
}