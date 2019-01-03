/**
 * File name : client-udp.c
 * Description : Client side UDP based socket programming.
 **/

/*----------------------------------------------------------------------
HEADER FILES
----------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*----------------------------------------------------------------------
MACROS
----------------------------------------------------------------------*/
#define LOCALHOST 		"127.0.0.1"
#define MESSAGE_LEN 		1024
#define PORT 			7891

/*----------------------------------------------------------------------
MAIN
----------------------------------------------------------------------*/
int main(void)
{
	char messageBuffer[MESSAGE_LEN];

	int socketDescriptor;
	struct sockaddr_in serverAddr;

	// Create UDP socket
	socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

	// Configure address structure
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(LOCALHOST);
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	while(1)
	{
		printf("Enter a message : ");
		fgets(messageBuffer, MESSAGE_LEN, stdin);

		// Send message to the server
		sendto(socketDescriptor, messageBuffer, strlen(messageBuffer) + 1, 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
		printf("Message sent to the server.\r\n");

		// Receive message from the server
		recvfrom(socketDescriptor, messageBuffer, sizeof(messageBuffer), 0, NULL, NULL);
		printf("Message received from the server : %s\r\n", messageBuffer);
	}

	return 0;
}
