#include<sdtio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	const char* srcPath = argv[1];
	const char* destPath = argv[2];

	if (srcPath == destPath) {
		printf("Same Location");
		return 0;
	}

	FILE* fpSrc;
	FILE* fpDest;

	fpSrc = fopen(srcPath, "rb");
	fpDest = fopen(destPath, "wb");
	int result = 1;
	if (fpSrc == NULL || fpDest == NULL) {
		result = 0;
	 }
	if (result != 0) {
        	for (;;) {
			if (fread(&c, sizeof(c), 1, fpSrc) < 1) {
				if (feof(fpSrc)) {
					break;
				} else {
					result = 0;
					break;
				}
			}
			if (fwrite(&c, sizeof(c), 1, fpDest) < 1) {
				result = 0;
				break;
			}
		}
	}
	
	if(result){
		printf("DONE");
	}
}
