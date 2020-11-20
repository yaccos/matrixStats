/***************************************************************************
 Public methods:
 SEXP rowVars(SEXP x, SEXP naRm, SEXP byRow)
 SEXP colVars(SEXP x, SEXP naRm, SEXP byRow)

 Authors: Henrik Bengtsson

 Copyright Henrik Bengtsson, 2014
 **************************************************************************/
#include <Rdefines.h>
#include "000.types.h"
#include "rowVars_lowlevel.h"

SEXP rowVars(SEXP x, SEXP dim, SEXP rows, SEXP cols, SEXP naRm, SEXP byRow) {
  int narm, byrow;
  SEXP ans;
  R_xlen_t nrow, ncol;

  /* Argument 'x' and 'dim': */
  assertArgMatrix(x, dim, (R_TYPE_INT | R_TYPE_REAL), "x");
  nrow = asR_xlen_t(dim, 0);
  ncol = asR_xlen_t(dim, 1);

  /* Argument 'naRm': */
  narm = asLogicalNoNA(naRm, "na.rm");

  /* Argument 'rows' and 'cols': */
  R_xlen_t nrows, ncols;
  int rowsType, colsType;
  void *crows = validateIndices(rows, nrow, 0, &nrows, &rowsType);
  void *ccols = validateIndices(cols, ncol, 0, &ncols, &colsType);

  /* Argument 'byRow': */
  byrow = asLogical(byRow);

  int hasna = hasNA(x);

  if (!byrow) {
    SWAP(R_xlen_t, nrow, ncol);
    SWAP(void*, crows, ccols);
    SWAP(R_xlen_t, nrows, ncols);
    SWAP(int, rowsType, colsType);
  }

  /* R allocate a double vector of length 'nrow'
     Note that 'nrow' means 'ncol' if byrow=FALSE. */
  PROTECT(ans = allocVector(REALSXP, nrows));

  /* Double matrices are more common to use. */
  if (isReal(x)) {
    rowVars_dbl[rowsType][colsType](REAL(x), nrow, ncol, crows, nrows, ccols, ncols, narm, hasna, byrow, REAL(ans));
  } else if (isInteger(x)) {
    rowVars_int[rowsType][colsType](INTEGER(x), nrow, ncol, crows, nrows, ccols, ncols, narm, hasna, byrow, REAL(ans));
  }

  UNPROTECT(1);

  return(ans);
} /* rowVars() */


/***************************************************************************
 HISTORY:
 2015-06-13 [DJ]
  o Supported subsetted computation.
 2014-11-18 [HB]
 o Created from rowMads.c.
 **************************************************************************/
