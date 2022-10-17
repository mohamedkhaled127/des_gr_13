/*
 ============================================================================
 Name        : des-13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int allPC216[16][48];

int main(){
	getAllPC2Keys(allPC216);
    printf("\n");
	for(int i=0;i<16;i++){
		for(int j=0;j<48;j++){
			printf("%d",allPC216[i][j]);
		}
		printf("\n");
		}
}
