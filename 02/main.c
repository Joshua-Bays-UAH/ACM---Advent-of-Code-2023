/*
Author: Joshua Bays
Project: Advent of Code Day 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Filename "input.txt"
#define RedMax 12
#define GreenMax 13
#define BlueMax 14

int main(){
	FILE* readfile = fopen(Filename, "r");
	char buff[256]; char line[256];
	unsigned r, g, b; _Bool valid;
	unsigned ret1 = 0; unsigned ret2 = 0;
	unsigned maxes[3];
	
	for(unsigned i = 0; i < 100; i++){
		for(unsigned j = 0; j <= sizeof(buff); j++){ buff[j] = '\0'; line[j] = '\0'; }
		for(unsigned j = 0; j < 3; j++){ maxes[j] = 0; }
		fgets(buff, sizeof(buff), readfile); buff[strlen(buff) - 1] = '\0';
		strcpy(line, strchr(buff, ':') + 2);
		printf("%s\n", line);
		r = 0; g = 0; b = 0;
		valid = 1;
		for(unsigned j = 0; j < strlen(buff); j++){
			if(line[j] == ';'){
				printf("\t%u, %u, %u\n", r, g, b);
				r = 0; g = 0; b = 0;
			}else if(line[j] >= '0' && line[j] <= '9'){
				if(line[j + 1] >= '0' && line[j + 1] <= '9'){
					switch(line[j + 3]){
						case 'r': r = (10 * (line[j] - '0')); r += (line[j + 1] - '0'); break;
						case 'g': g = (10 * (line[j] - '0')); g += (line[j + 1] - '0'); break;
						case 'b': b = (10 * (line[j] - '0')); b += (line[j + 1] - '0'); break;
					}
					j += 1;
				}else{
					switch(line[j + 2]){
						case 'r': r += (line[j] - '0'); break;
						case 'g': g += (line[j] - '0'); break;
						case 'b': b += (line[j] - '0'); break;
					}
				}
			}
			if(r > RedMax || g > GreenMax || b > BlueMax){ valid = 0; }
			if(r > maxes[0]){ maxes[0] = r; } if(g > maxes[1]){ maxes[1] = g; } if(b > maxes[2]){ maxes[2] = b; }
		}
		printf("\t%u, %u, %u\n", r, g, b);
		if(valid){ ret1 += (i + 1); }
		ret2 += (maxes[0] * maxes[1] * maxes[2]);
	}
	
	printf("%u\n", ret1);
	printf("%u\n", ret2);
	return 0;
}
