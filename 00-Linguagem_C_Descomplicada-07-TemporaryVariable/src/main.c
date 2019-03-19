/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef enum LEVEL{
	STATUS_INFO,
	STATUS_WARNING,
	STATUS_ERROR,
	STATUS_CRITICAL,
	STATUS_FATAL
}LEVEL;

typedef struct info{
	char *error_message;
	LEVEL level;
	uint8_t status;
}INFO;


void INFO_Print(INFO info);

int main(void) {

	//test 1
	INFO_Print((INFO) {.error_message = "It is not possible", .level = STATUS_WARNING, .status = 50});

	//test 2
	char message[30] = "Cristiano Silva";
	LEVEL level = STATUS_CRITICAL;
	uint8_t status = 255;

	INFO_Print((INFO) {.error_message = (char *)message, .level = level, .status = status});

	return EXIT_SUCCESS;
}

void INFO_Print(INFO info)
{
	char tag[8] = {0};

	switch(info.level)
	{
	case STATUS_INFO:
		strncpy(tag,"INFO", strlen("INFO"));
		break;
	case STATUS_WARNING:
		strncpy(tag,"WARNING", strlen("WARNING"));
			break;
	case STATUS_ERROR:
		strncpy(tag,"ERROR", strlen("ERROR"));
			break;
	case STATUS_CRITICAL:
		strncpy(tag,"CRITICAL", strlen("CRITICAL"));
			break;
	case STATUS_FATAL:
		strncpy(tag,"FATAL", strlen("FATAL"));
			break;
	}

	printf("%s: %s; status: %02X\n", tag, info.error_message, info.status);

}
