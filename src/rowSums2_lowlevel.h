#include <Rdefines.h>
#include "000.types.h"
#include "000.utils.h"
#include "000.macros.h"
#include <R_ext/Memory.h>
#include <Rmath.h>
#include "000.types.h"

/*
Native API (dynamically generated via macros):
 
void rowSums2_int(int *x, R_xlen_t nrow, R_xlen_t ncol, R_xlen_t *rows, R_xlen_t nrows, int rowsHasNA, R_xlen_t *cols, R_xlen_t ncols, int colsHasNA, int narm, int hasna, int byrow, double *ans)
void rowSums2_dbl(double *x, R_xlen_t nrow, R_xlen_t ncol, R_xlen_t *rows, R_xlen_t nrows, int rowsHasNA, R_xlen_t *cols, R_xlen_t ncols, int colsHasNA, int narm, int hasna, int byrow, double *ans)
*/

#define X_TYPE 'i'


void rowSums2_int(int *x, R_xlen_t nrow, R_xlen_t ncol, 
                   R_xlen_t *rows, R_xlen_t nrows, int rowsHasNA,
                   R_xlen_t *cols, R_xlen_t ncols, int colsHasNA,
                   int narm, int hasna, int byrow, double *ans) {
  if(rowsHasNA || colsHasNA){
#define IDXS_HAS_NA
#include "rowSums2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else{
#include "rowSums2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"

#define X_TYPE 'r'
void rowSums2_dbl(double *x, R_xlen_t nrow, R_xlen_t ncol, 
                  R_xlen_t *rows, R_xlen_t nrows, int rowsHasNA,
                  R_xlen_t *cols, R_xlen_t ncols, int colsHasNA,
                  int narm, int hasna, int byrow, double *ans) {
  if(rowsHasNA || colsHasNA){
#define IDXS_HAS_NA
#include "rowSums2_lowlevel_template.h"
#undef IDXS_HAS_NA
  }
  else{
#include "rowSums2_lowlevel_template.h"
  }
}
#include "000.templates-types_undef.h"