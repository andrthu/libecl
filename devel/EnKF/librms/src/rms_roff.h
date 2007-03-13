#ifndef __RMS_ROFF_H__
#define __RMS_ROFF_H__
#include <stdbool.h>

void rms_roff_load(const char * , const char * , float *);

typedef struct rms_roff_file_struct   rms_roff_file_type;
typedef struct rms_roff_tagkey_struct rms_roff_tagkey_type;
typedef struct rms_roff_tag_struct    rms_roff_tag_type;
typedef enum   rms_type_enum_def      rms_roff_type_enum;


rms_roff_file_type * rms_roff_open      (const char *, bool , bool );
void                 rms_roff_close     (rms_roff_file_type *);
bool                 rms_roff_at_endtag (const rms_roff_file_type *roff);

rms_roff_tag_type  * rms_roff_fread_alloc_tag(const rms_roff_file_type *, bool *);


void                 rms_roff_write_fortran_data(void       * , const void * , int , int , int , int );
void                 rms_roff_read_fortran_data (const void * ,       void * , int , int , int , int );


#endif
