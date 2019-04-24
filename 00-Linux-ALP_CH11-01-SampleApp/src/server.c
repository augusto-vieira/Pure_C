/*
 * server.c
 *
 *  Created on: Apr 24, 2019
 *      Author: cssouza
 */

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#include "server.h"

static char *ok_response = "HTTP/1.0 200 OK\n"
						   "Content-type: text/html\n"
						   "\n";

static char *bad_request_response = "HTTP/1.0 400 Bad Request\n"
									"Content-type: text/html\n"
									"\n"
									"<html>\n"
									"<body>\n"
									"<h1>Bad Request</h1>\n"
									"<p>This server did not understand yout request.</p>\n"
									"</body>\n"
									"</html>\n";


