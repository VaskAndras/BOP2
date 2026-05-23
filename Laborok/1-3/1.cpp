#include <stdio.h>

 void f(int& i){
    i=i+1;
}

int main(){

    int i = 0;
    f(i);
    printf("%d", i);  

}