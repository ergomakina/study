#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	switch (n){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 21:
		case 22:
		case 23:
			printf("おやすみなさい");
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			printf("おはようございます");
			break;
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
			printf("こんばんは");
			break;
		case 18:
		case 19:
		case 20:
			printf("こんばんは");
			break;
		default:
			printf("時刻を指定してください");
			break;
	}
}
