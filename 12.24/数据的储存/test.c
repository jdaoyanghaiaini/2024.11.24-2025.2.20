#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
struct STU {
	char a; //1  8 1
	char name[10];// 1 8 1
	int y;// 4 8 4
};
struct STU1 {
	int y;             //4   8    4
	char name[10];     //1   8    1 
	struct STU s3;     //         4
};

int main()
{
	printf("%d", sizeof(struct STU1));
	return 0;
}