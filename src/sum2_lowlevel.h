#include <Rdefines.h>
#include <R_ext/Constants.h>
#include "000.types.h"
#include "000.utils.h"
#include "000.macros.h"

/*
Native API (dynamically generated via macros):
 
double sum2_int(int *x, R_xlen_t nx, R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA, int narm)
double sum2_dbl(double *x, R_xlen_t nx, R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA, int narm)
*/

#define X_TYPE 'i'
double sum2_int(int *x, R_xlen_t nx,
R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA,
int narm) {
  if(idxsHasNA){
#define IDXS_HAS_NA
#include "sum2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else {
#include "sum2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"

#define X_TYPE 'r'
double sum2_dbl(double *x, R_xlen_t nx,
                R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA,
                int narm) {
  if(idxsHasNA){
#define IDXS_HAS_NA
#include "sum2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else {
#include "sum2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"