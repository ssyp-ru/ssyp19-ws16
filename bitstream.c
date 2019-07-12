#include <stdio.h>
#include <stdlib.h>
typedef struct st_bitstream bitstream;
struct st_bitstream
{
	int index;
	char buffer;
	FILE* file;
};
bitstream* bitstream_init(char* file_name)
{
	bitstream* b_stream = (bitstream*)malloc(sizeof(bitstream));
	b_stream->file = fopen("file_name", "wr");
	b_stream->index = 0;
	b_stream->buffer = '0';
	return b_stream;
}
bitstream* bitstream_dump(char bit)
{
	bit = '0';
	return bit;
}
bitstream* bitstream_put_bit(char bit, bitstream* b_stream)
{
	b_stream->buffer |= bit<<7 - b_stream->index;
	b_stream->index++;
	if (b_stream->index > 7)
	{
		bitstream_dump(bit);
		b_stream->index = 0;
	}
}
bitstream* bitstream_get_bit(bitstream* b_stream)
{
	char read, symbol;
	b_stream->buffer |= symbol<<7 - b_stream->index;
	b_stream->index++;
	if (b_stream->index > 7)
	{
		bitstream_dump(b_stream->buffer);
		b_stream->index = 0;
		read = fread(symbol, sizeof(char), 1, b_stream->file);
	}
	return b_stream->buffer;
}