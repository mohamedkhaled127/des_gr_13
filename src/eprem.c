#include <stdio.h>

int out_Array[48];
int in_Array[32] = {1,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1};
int E_per[] =
{
    32,  1,  2,  3,  4,  5,
    4,  5,  6,  7,  8,  9,
    8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};


int exp_Permutation(int in_Array[]){
    for(int i = 0;i<48;i++){
        out_Array[i] = in_Array[E_per[i]-1];
    }
}
int main(){
    exp_Permutation(in_Array);
    for (int i = 0; i < 32; i++)
    {
        printf("%d",out_Array[i]);
    }
    return 0;
}