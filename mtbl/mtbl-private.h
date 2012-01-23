/*
 * Copyright (c) 2012 by Internet Systems Consortium, Inc. ("ISC")
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef MTBL_PRIVATE_H
#define MTBL_PRIVATE_H

#ifdef HAVE_ENDIAN_H
# include <endian.h>
#else
# ifdef HAVE_SYS_ENDIAN_H
#  include <sys/endian.h>
# endif
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "mtbl.h"

#define MTBL_MAGIC		0x77846676

#define MTBL_COMP_NONE		0
#define MTBL_COMP_SNAPPY	1

#define MTBL_TRAILER_SIZE	512

struct mtbl_trailer {
	uint64_t	compression_algorithm;
	uint64_t	count_data_blocks;
	uint64_t	bytes_data_blocks_compressed;
	uint64_t	bytes_data_blocks_uncompressed;
	uint64_t	bytes_index_block;
	uint64_t	count_entries;
	uint64_t	bytes_keys;
	uint64_t	bytes_values;
};

void	trailer_write(struct mtbl_trailer *t, uint8_t *buf);
bool	trailer_read(const uint8_t *buf, struct mtbl_trailer *t);

#endif /* MTBL_PRIVATE_H */