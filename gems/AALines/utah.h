/*
	file:		utah.h
	description:	interface to Utah RLE toolkit
	author:		A. T. Campbell
	date:		October 30, 1989
*/

#ifndef UTAH_H
#define UTAH_H

#include <stdio.h>

/******************************************************************************/

/* include files */
/* You will have to get these from the ancient Utah Raster Toolkit,
   http://www.cs.utah.edu/gdc/projects/urt/ - best of luck! */
//#include "rle.h"
// fake rle
typedef struct rle_hdr {
	int xmax;
	FILE* rle_file;
	int xmin;
	int ymin;
	int ymax;
	int alpha;
} rle_hdr;
typedef unsigned char rle_pixel;
extern rle_hdr rle_dflt_hdr;

/******************************************************************************/

/* type definitions */
typedef rle_hdr UTAH_FILE;

int rle_get_setup(UTAH_FILE*);
void rle_getrow(UTAH_FILE*, rle_pixel*[3]);
void rle_puteof(UTAH_FILE*);
void rle_put_setup(UTAH_FILE*);

/******************************************************************************/

/* return values */
extern int		utah_read_close(UTAH_FILE*);
extern UTAH_FILE	*utah_read_init(char*, int*, int*);
extern int utah_read_pixels(UTAH_FILE *ufp, unsigned char pixels[][3]);
int utah_read_rgb(UTAH_FILE *ufp, unsigned char	r[], unsigned char g[], unsigned char b[]);
extern int		utah_write_close(UTAH_FILE *);
extern UTAH_FILE	*utah_write_init(char*, int, int);
int utah_write_pixels(UTAH_FILE *ufp, unsigned char pixels[][3]);
extern int utah_write_rgb(UTAH_FILE *ufp, unsigned char r[], unsigned char g[], unsigned char b[]);
void rle_putrow(rle_pixel *[3], int, UTAH_FILE*);

/******************************************************************************/

#endif //UTAH_H
