#include<stdio.h>
int help_me;//为什么！！！！！！！！不能缺少全局变量？？？？？
int help;
int main(){
    int a=0xffffffff;
    if(a==-1){
        printf("True!%d\n",a);
    }else{
        printf("False!%d\n",a);
    }
    return 0;
}

