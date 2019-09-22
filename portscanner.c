#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXPORT 1024


main (int argc, char *argv[0]) {
	int s, i;
	struct sockaddr_in sa;
	struct hostent *he;

	if ((he = gethostbyname (argv[1])) == NULL) {
		perror ("gethostbyname");
		exit(1); 
	}
	sa.sin_family = AF_INET;
	sa.sin_addr = *((struct in_addr *)he-> h_addr);

	for (i = 1; i <= MAXPORT; i++) {
		if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
			perror ("socket");
			exit (-1);
		}
		sa.sin_port = htons(i);

		if (connect (s, (struct sockaddr *)&sa, sizeof (sa)) < 0)
			close (s);
		
		else {
			printf ("Port %d is open\n",i);
			close (s);
		}
	}
}
