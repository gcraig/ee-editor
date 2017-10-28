#include <stdio.h>

#include "buffer.h"

int main(int argc, char **argv)
{
	printf("Hello world\n");
	printf("ee - simple text editor\n");
	printf("linked list wchar_t impl, gap/rope alternatives\n");

	const char *filename = argv[1];
	
    // Buffer *buf = buffer_create();
    
	// or

	Buffer *buf = buffer_read(filename);

	buffer_print(buf);

	buffer_save(buf, "d:\\tmp\\geosave.txt");

	buffer_free(buf);
	
	return (0);
}
