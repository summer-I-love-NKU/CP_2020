#include<stdio.h>
int help_me;//为什么！！！！！！！！不能缺少全局变量？？？？？
int help;
int a[10];
int main(){
    for(int i=0;i<10;i=i+1){
        a[i]=i+1;
    // }
    // for(int i=0;i<10;i=i+1){
        printf("%d\n",a[i]);
    }
    return 0;
}