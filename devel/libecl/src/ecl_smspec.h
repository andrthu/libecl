#ifndef __ECL_SMSPEC__
#define __ECL_SMSPEC__
#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdbool.h>
#include <stringlist.h>

typedef struct ecl_smspec_struct ecl_smspec_type; 

typedef enum {ECL_SMSPEC_AQUIFER_VAR, 
              ECL_SMSPEC_WELL_VAR   , 
	      ECL_SMSPEC_REGION_VAR , 
	      ECL_SMSPEC_FIELD_VAR  , 
	      ECL_SMSPEC_GROUP_VAR  , 
	      ECL_SMSPEC_BLOCK_VAR  , 
	      ECL_SMSPEC_COMPLETION_VAR ,
	      ECL_SMSPEC_LOCAL_BLOCK_VAR,
	      ECL_SMSPEC_LOCAL_COMPLETION_VAR,
	      ECL_SMSPEC_LOCAL_WELL_VAR,
	      ECL_SMSPEC_NETWORK_VAR,
	      ECL_SMSPEC_REGION_2_REGION_VAR,
	      ECL_SMSPEC_SEGMENT_VAR,
	      ECL_SMSPEC_MISC_VAR}  ecl_smspec_var_type;

ecl_smspec_var_type ecl_smspec_identify_var_type(const char * );


ecl_smspec_type * ecl_smspec_fread_alloc(const char * , bool );
void              ecl_smspec_free( ecl_smspec_type *);
void              ecl_smspec_set_time_info( const ecl_smspec_type *  , const float *  , double *  , time_t * );

int               ecl_smspec_get_well_var_index(const ecl_smspec_type * ecl_smspec , const char * well , const char *var);
bool              ecl_smspec_has_well_var(const ecl_smspec_type * ecl_smspec , const char * well , const char *var);

int               ecl_smspec_get_group_var_index(const ecl_smspec_type * ecl_smspec , const char * group , const char *var);
bool              ecl_smspec_has_group_var(const ecl_smspec_type * ecl_smspec , const char * group , const char *var);

int               ecl_smspec_get_field_var_index(const ecl_smspec_type * ecl_smspec , const char *var);
bool              ecl_smspec_has_field_var(const ecl_smspec_type * ecl_smspec , const char *var);

int               ecl_smspec_get_block_var_index(const ecl_smspec_type * ecl_smspec , const char * block_var , int block_nr);
bool              ecl_smspec_has_block_var(const ecl_smspec_type * ecl_smspec , const char * block_var , int block_nr);
int               ecl_smspec_get_block_var_index_ijk(const ecl_smspec_type * ecl_smspec , const char * block_var , int i , int j , int k);
bool              ecl_smspec_has_block_var_ijk(const ecl_smspec_type * ecl_smspec , const char * block_var , int i , int j , int k);

int               ecl_smspec_get_region_var_index(const ecl_smspec_type * ecl_smspec , int region_nr , const char *var);
bool              ecl_smspec_has_region_var(const ecl_smspec_type * ecl_smspec , int region_nr , const char *var);

int               ecl_smspec_get_misc_var_index(const ecl_smspec_type * ecl_smspec , const char *var);
bool              ecl_smspec_has_misc_var(const ecl_smspec_type * ecl_smspec , const char *var);

int               ecl_smspec_get_well_completion_var_index(const ecl_smspec_type * ecl_smspec , const char * well , const char *var, int cell_nr);
bool              ecl_smspec_has_well_completion_var(const ecl_smspec_type * ecl_smspec , const char * well , const char *var, int cell_nr);

int               ecl_smspec_get_general_var_index(const ecl_smspec_type * ecl_smspec , const char * lookup_kw);
bool              ecl_smspec_has_general_var(const ecl_smspec_type * ecl_smspec , const char * lookup_kw);

time_t            ecl_smspec_get_start_time(const ecl_smspec_type * );
/*****************************************************************/
const char      * ecl_smspec_get_simulation_case(const ecl_smspec_type * );
stringlist_type * ecl_smspec_alloc_well_list( const ecl_smspec_type * smspec );
stringlist_type * ecl_smspec_alloc_well_var_list( const ecl_smspec_type * smspec );


#ifdef __cplsplus
}
#endif
#endif
