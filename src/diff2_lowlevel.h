#include <Rdefines.h>
#include <R_ext/Constants.h>
#include "000.types.h"
#include "000.utils.h"
#include "000.macros.h"


static R_INLINE int diff_int(int a, int b) {
  if (X_ISNA(a) || X_ISNA(b)) return(NA_INTEGER);
  return a-b;
}
#define diff_int diff_int
/*
Native API (dynamically generated via macros):
 
void diff2_int(int *x, R_xlen_t nx, R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA R_xlen_t lag, R_xlen_t differences, int *ans, R_xlen_t nans)
void diff2_dbl(double *x, R_xlen_t nx, R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA R_xlen_t lag, R_xlen_t differences, int *ans, R_xlen_t nans)
*/

#define X_TYPE 'i'
#define X_DIFF diff_int
void diff2_int(int *x, R_xlen_t nx,
                   R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA,
                   R_xlen_t lag, R_xlen_t differences, int *ans, R_xlen_t nans){
  if(idxsHasNA) {
#define IDXS_HAS_NA
#include "diff2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else {
#include "diff2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"
#undef X_DIFF

#define X_TYPE 'r'
#define X_DIFF(a,b) a-b
void diff2_dbl(double *x, R_xlen_t nx,
               R_xlen_t *idxs, R_xlen_t nidxs, int idxsHasNA,
               R_xlen_t lag, R_xlen_t differences, double *ans, R_xlen_t nans){
  if(idxsHasNA) {
#define IDXS_HAS_NA
#include "diff2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else {
#include "diff2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"
