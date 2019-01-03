/**
 * File name : server-udp.c
 * Description : Server side UDP based socket programming.
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
#define LOCALHOST 			"127.0.0.1"
#define MESSAGE_LEN 			1024
#define PORT 				7891

/*----------------------------------------------------------------------
MAIN
----------------------------------------------------------------------*/
int main(void)
{
	char messageBuffer[MESSAGE_LEN];

	int socketDescriptor;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	// Create UDP socket
	socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

	// Configure address structure
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(LOCALHOST);
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));  

	// Bind the socket with server's address
	bind(socketDescriptor, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

	addr_size = sizeof(serverStorage);

	printf("Server running....\r\n");

	while(1)
	{
		memset(messageBuffer, 0, sizeof(messageBuffer));

		// Receiving UDP datagram from the client
		recvfrom(socketDescriptor, messageBuffer, sizeof(messageBuffer), 0, (struct sockaddr *)&serverStorage, &addr_size);
		printf("\r\nMessage received from the client : %s", messageBuffer);

		// Sending the same message back to the client
		sendto(socketDescriptor, messageBuffer, sizeof(messageBuffer), 0, (struct sockaddr *)&serverStorage, addr_size);
		printf("Same message sent to the client.\r\n");
	}

	return 0;
}
