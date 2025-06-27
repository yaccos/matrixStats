/***********************************************************************
 TEMPLATE:
  void rowSums2_<int|dbl>(ARGUMENTS_LIST)

 Copyright: Henrik Bengtsson, 2017
 ***********************************************************************/
#include <R_ext/Memory.h>
#include <Rdefines.h>
#include <Rmath.h>
#include "000.types.h"

/* Expand arguments:
    X_TYPE => (X_C_TYPE, X_IN_C, X_ISNAN)
 */
#include "000.templates-types.h"

/* NOTE: Unlike the other functions in the API,
 * elements are always iterated through in-order.
 * Hence, rows and cols really mean rows and cols no matter
 * the flag byrow
 */
void CONCAT_MACROS(rowSums2, X_C_SIGNATURE)(X_C_TYPE *x, R_xlen_t nrow, R_xlen_t ncol, 
                  R_xlen_t *rows, R_xlen_t nrows, int rowsHasNA,
                  R_xlen_t *cols, R_xlen_t ncols, int colsHasNA,
                  int narm, int hasna, int byrow, double *restrict ans) {
    R_xlen_t ii, jj, idx;
    R_xlen_t colOffset;
    X_C_TYPE value;
    int nocols, norows;
    /* NOTE: SIMD does not long doubles - in case we ever go there */
    /* NOTE: For maintaining a tidy codebase, we bring variables for both
     * colsums and rowsums (accumuated directly in answer) in scope,
     * but only one of them will ever be used
     * at given call to the function */
    double colSum;
    
    /* If there are no missing values, don't try to remove them. */
    if (hasna == FALSE)
        narm = FALSE;
    
    if (cols == NULL) { nocols = 1; } else { nocols = 0; }
    if (rows == NULL) { norows = 1; } else { norows = 0; }
    
    if (byrow) {
      /*
       * Since we are accumulating directly into the answer array, we have to
       * initialize its elements to zero
       */
      /*
       * If nrows == 0, we may have a NULL pointer.
       * Calling memset() with a NULL pointer is apparently undefined behavior,
       * so we must guard for it 
       */
      if (nrows > 0 ) {
        memset(ans,0, nrows*sizeof(double));
      }
      
    }
    
    for (jj=0; jj < ncols; jj++) {
      if (!byrow) {
        colSum = 0.0;
      }
      if (nocols) {
        colOffset = jj * nrow;
      } else if (!colsHasNA) {
        colOffset = cols[jj] * nrow;
      } else {
        colOffset = R_INDEX_OP(cols[jj], *, nrow, 1, 1);
      }
      for (ii=0; ii < nrows; ii++) {
        if (!colsHasNA && norows) {
          /*
           * In this special case, we can eliminate
           * the possibility of having NA indices
           */
          idx = colOffset + ii;
          value = x[idx];
        } else if (!colsHasNA && !rowsHasNA && !norows) {
          idx = colOffset + rows[ii];
          value = x[idx];
        } else {
          if (norows) {
            idx = R_INDEX_OP(colOffset, +, ii, 1, 1);
          } else {
            idx = R_INDEX_OP(colOffset, +, rows[ii], 1, 1);
          }
          value = R_INDEX_GET(x, idx, X_NA, 1);
        }
        
#if X_TYPE == 'i'
        if (byrow) {
          if (!X_ISNAN(value)) {
            ans[ii] += (double)value;
          } else if (!narm) {
            ans[ii] = R_NaReal;
          }
        } else {
          if (!X_ISNAN(value)) {
            colSum += (double)value;
          } else if (!narm) {
            colSum = R_NaReal;
            /* This optimization is harder to make for row sums
             * as we cannot just break the loop
             */
            break;
          }  
        }
#elif X_TYPE == 'r'
        if (byrow) {
          if (!narm) {
            ans[ii] += (double)value;
          } else if (!ISNAN(value)) {
            ans[ii] += (double)value;
            }
        } else {
          if (!narm) {
            colSum += (double)value;
          } else if (!ISNAN(value)) {
            colSum += (double)value;
              if (jj % 1048576 == 0 && ISNA(colSum)) {
                break;
              }
          }
        }
#endif
      } /* for (ii ...) */
      
      if (!byrow) {      
          if (colSum > DBL_MAX) {
            ans[jj] = R_PosInf;
          } else if (colSum < -DBL_MAX) {
            ans[jj] = R_NegInf;
          } else {
            ans[jj] = (double)colSum;
          }
      }
      R_CHECK_USER_INTERRUPT(jj);
      
      } /* for (jj ...) */ 
        
}
