#include<stdio.h>

int mmc(int num1, int num2, int acc){
    if(num1 % num2 == 0){
        return num1;
    }else if (num2 % num1 == 0){
       return num2;
    }else{
        if(acc != 1){
            if(acc % num1 == 0 && acc % num2 == 0){
                return acc;
            }else{
                return mmc(num1, num2, acc + 1);
            }
        }else{
            return mmc(num1, num2, acc + 1);
        }
    }
}

int main(){
    int num1;
    int num2;
    scanf("%d %d", &num1, &num2);

    printf("%d ", mmc(num1, num2, 1));
    return 0;
}