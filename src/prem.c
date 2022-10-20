#include <stdio.h>

int out_Array[32];
int in_Array[32] = {1,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1};
int P[] =
{
    16,  7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2,  8, 24, 14,
    32, 27,  3,  9,
    19, 13, 30,  6,
    22, 11,  4, 25
};


int permutation(int in_Array[]){
    for(int i = 0;i<32;i++){
        out_Array[i] = in_Array[P[i]-1];
    }
}
int main(){
    permutation(in_Array);
    for (int i = 0; i < 32; i++)
    {
        printf("%d",out_Array[i]);
    }
    return 0;
}