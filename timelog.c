/**
 * @author : Arun jyothish k
 * @project : skiller
 * @file : timelog.c
 *
 * @brief : This program is for logging time in an efficient time, skill, knowledge tracking
 */

#include <stdio.h>
#include <sys/stat.h>

int main(){
	printf("hello world\r\n");
	if (mkdir("august",0755) == -1) {
		printf("error creating directory !!\r\n");
	} else {
		printf("directory created !!\r\n");
	}
}

/**
 * PROJECT -- DEVELOPMENT_BOARD -- MAJOR_TECH -- TECH_DESCRIPTION -- TOOLS_REQUIRED -- TO_BE_LEARNED
 *
 */
