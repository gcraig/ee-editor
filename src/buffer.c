#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "buffer.h"

extern Buffer *
buffer_create ()
{
	Buffer *buf = malloc(sizeof(struct buffer));
	if (buf == NULL)
	{
		fprintf(stderr, "malloc buffer failed.\n");
		exit(-1);
		return(NULL); // TODO: remove system exit
	}
	strcpy(buf->name, "testfile.txt");

	
	Node *head = malloc(sizeof(struct node));
	wcscpy(head->line, L"Lorem Ipsom Epsom Dualai");
	buf->head = head;
	
	printf("Buffer successfully created.\n");
	printf("Buffer size: %d\n", sizeof (struct buffer));
    return buf;
}

extern void
//buffer_print(wchar_t* buf)
//buffer_print(BUFFER* buffer)
buffer_print(Buffer *buf)
{
    Node *n = buf->head;
    int j=0;
    while (n) 
    {
        wprintf(L"%d: %ls\n", j++, n->line);
        n = n->next;        
    }
    
    /*
    if (buffer && buffer->head)
    {
        printf("data:\n");
        wprintf(L"%ls", buffer->head->line);
    }
    if (buffer && buffer->head->next)
    {
        for (int i=0; i<; i=buffer->next->)
        wprintf(L"%ls", buffer
    }
    */

//    for (int i=0; i<2048; i++) {
//        wprintf(L"%ld", buf[i]);
//    }

//    while (buf) {
//        wprintf(L"%lc", *buf++);
//    }    

    printf("\n");
}

extern void
//buffer_free(wchar_t* buf)
//buffer_free(BUFFER* buffer)
buffer_free(Buffer *buf)
{
//  free(buffer->name);
//  free(buffer->head);
//  free(buffer->tail);
    free(buf);
}

// old
// typedef buffer wchar_t* buf;
// Buffer* buffer = calloc(BUFSIZE, sizeof(wchar_t));
// wchar_t *buf = calloc(BUFSIZE, sizeof(wchar_t));
