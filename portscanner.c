/*
 * FILE: portscanner.c
 * AUTHOR: Miguel Salvá
 * ABSTRACT: Simple TCP port scanner written in C to perform a benchmark
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MIN_PORT 0
#define MAX_PORT 65535 
/* System ports: 0-1023
 * Registered ports: 1024-49151
 * Private ports: 49152-65535 */


int main(int argc, char *argv[0]) {
	int port;
	int sockfd;
	struct sockaddr_in address;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr((char *)argv[1]);

	for (port = MIN_PORT; port < MAX_PORT; port++) {
		address.sin_port = htons(port);
		if (connect(sockfd, (struct sockaddr *)&address, sizeof (address)) == 0) {
			printf("Port %d is open\n", port);
			close(sockfd);
			sockfd = socket(AF_INET, SOCK_STREAM, 0);
		}
	}
	close(sockfd);
}

