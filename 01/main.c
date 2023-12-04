/*
Author: Joshua Bays
Project: Advent of Code Day 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Filename "input.txt"

int main(){
	FILE* readfile = fopen(Filename, "r"); char buff[64];
	unsigned f, l;
	unsigned ret = 0;
	
	for(unsigned i = 1000; i--;){
		for(unsigned j = 0; j < sizeof(buff); j++){ buff[j] = '\0'; }
		fgets(buff, sizeof(buff), readfile);
		buff[strlen(buff) - 1] = '\0';
		for(unsigned j = 0; j < strlen(buff); j++){ if(buff[j] >= '0' && buff[j] <= '9'){ f = buff[j] - '0'; break; } }
		for(unsigned j = strlen(buff) - 1; j >= 0; j--){ if(buff[j] >= '0' && buff[j] <= '9'){ l = buff[j] - '0'; break; } }
		ret += f*10; ret += l;
	}
	
	printf("%u\n", ret);
	
	return 0;
}
