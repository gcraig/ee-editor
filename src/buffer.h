#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
#extern "C" {
#endif

	static const size_t BUFSIZE = 2048; // 2k single screen, page size

	typedef struct node
	{
		struct node *prev; // prev line
		struct node *next; // next line
		wchar_t	*line; // data

	} Node;

	// usage:
	// NODE *newNode = NULL;
	// NODE *head, *tail;
	// head->line
	// head->next->line
	// head->next->line

	typedef struct buffer
	{
		char	name[20];	// buffer/file name
		Node	*head;		// first line
		bool	dirty;		// buffer changed and not saved
		size_t	numlines;	// number of lines
	
	} Buffer;

	// usage:
	// BUFFER *newBuffer = NULL;
	// strcpy(newBuffer->name, "testbuffer.txt");

	extern Buffer * buffer_create();
	extern void		buffer_print(Buffer *buffer);
	extern void		buffer_save(Buffer *buf, const char *filename);
	extern void		buffer_free(Buffer *buffer);

#ifdef __cplusplus
}
#endif

#endif /* __BUFFER_H__ */