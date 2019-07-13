#ifndef BITSTREAM_H_INCLUDED
#define BITSTREAM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

typedef struct st_bitstream bitstream;
struct st_bitstream
{
    int index;
    char buffer;
    FILE *file;
};

bitstream *bitstream_init(FILE *file, char rorw);

void bitstream_dump(bitstream *b_stream);

void bitstream_put_bit(char bit, bitstream *b_stream);

char bitstream_get_bit(bitstream *b_stream);

#endif