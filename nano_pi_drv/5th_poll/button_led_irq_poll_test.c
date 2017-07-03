
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <poll.h>

/*
PA2：led
PL11: IRQ button
button control led
*/
int main(int argc, char **argv)
{
	int fd_led;
	int fd_button;
	int ret;

	struct pollfd fds[1];
	
	int led_val = 0;
	unsigned int key_val = 0;
	unsigned int key_count = 0;
	
	fd_led = open("/dev/led", O_RDWR);
	if (fd_led < 0)
	{
		printf("can't open led!\n");
		return 0;
	}
	
	fd_button = open("/dev/button", O_RDWR);
	if (fd_button < 0)
	{
		printf("can't open button!\n");
		return 0;
	}

	fds[0].fd     = fd_button;
	fds[0].events = POLLIN;

	
	while(1)
	{
		ret = poll(fds, 1, 5000);//5s

		if(ret)
		{
			read(fd_button, &key_val, 4);
			if(key_val == 1)
			{
				led_val = !led_val;
				write(fd_led, &led_val, 4);
			}
		}
		else
		{
			printf("time out.\n");
		}		
	}
 
	return 0;
}
