#ifndef BITSTREAM_H_INCLUDED
#define BITSTREAM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct st_bitstream bitstream;
struct st_bitstream
{
    int index;
    char buffer;
    FILE *file;
};

bitstream *bitstream_init(FILE *file, char rorw);

bitstream *bitstream_dump(bitstream *bit);

bitstream *bitstream_put_bit(bitstream *bit, bitstream *b_stream);

char bitstream_get_bit(bitstream *b_stream);

#endif // BITSTREAM_H_INCLUDED
