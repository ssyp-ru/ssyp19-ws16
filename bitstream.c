#include "bitstream.h"

bitstream *bitstream_init(FILE *file, char rorw)
{
    bitstream *b_stream = (bitstream *) malloc(sizeof(bitstream));
    b_stream->file = file;
    if (rorw == 'r')
    {
        fread(b_stream->buffer, sizeof(char), 1, b_stream->file);
    }
    b_stream->index = 0;
    b_stream->buffer = '0';
    return b_stream;
}
void bitstream_dump(bitstream *bit)
{
    fwrite(bit->buffer, sizeof(char), 1, bit->file);
    bit->buffer = 0;
}

void bitstream_put_bit(char bit, bitstream *b_stream)
{
    b_stream->buffer |= bit << (7 - b_stream->index);
    b_stream->index++;
    if (b_stream->index > 7)
    {
        bitstream_dump(b_stream);
        b_stream->index = 0;
    }
}

char bitstream_get_bit(bitstream *b_stream)
{
    char bit;
    bit |= b_stream->buffer >> 7 - b_stream->index & 1;
    b_stream->index++;
    if (b_stream->index > 7)
    {
        b_stream->buffer = '0';
        b_stream->index = 0;
        fread(b_stream->buffer, sizeof(char), 1, b_stream->file);
    }
    return bit;
}