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
		//return(NULL); // TODO: remove system exit
	}
	strcpy_s(buf->name, 20, "testfile.txt");

	
	Node *_head = malloc(sizeof(struct node));
	wchar_t *_line = L"Lorem Ipsom Epsom Dualai";
	if (_head == NULL)
	{
		fprintf(stderr, "malloc head node failed.\n");
		exit(-1);
		//return(NULL); // TODO: remove system exit
	}
	//wcscpy_s(head->line, L"Lorem Ipsom Epsom Dualai");
	buf->head = _head;
	_head->line = _line;
	
	wprintf(L"%ls\n", _head->line);
	printf("Buffer successfully created.\n");
	//printf("Buffer size: %d\n", (int) (sizeof (struct buffer)));
    return buf;
}

extern void 
buffer_save(Buffer *buf, const char *filename) 
{
	FILE *fout = fopen(filename, "w");
	if (fout == NULL)
	{
		fprintf(stderr, "Error in openinng buffer file to save: %s", filename);
		exit(-1);
	}
	size_t s = fwrite(buf->head->line, sizeof(buf->head->line), 1, fout);
	fflush(fout);
	fclose(fout);
	return;
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
	return;
}

extern void		
buffer_read(const char *filename)
{

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
	return;
}

// old
// typedef buffer wchar_t* buf;
// Buffer* buffer = calloc(BUFSIZE, sizeof(wchar_t));
// wchar_t *buf = calloc(BUFSIZE, sizeof(wchar_t));
