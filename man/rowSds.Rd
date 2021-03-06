% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/rowMads.R, R/rowSds.R
\name{rowMads}
\alias{rowMads}
\alias{colMads}
\alias{rowSds}
\alias{colSds}
\title{Standard deviation estimates for each row (column) in a matrix}
\usage{
rowMads(x, rows = NULL, cols = NULL, center = NULL, constant = 1.4826,
  na.rm = FALSE, dim. = dim(x), ...)

colMads(x, rows = NULL, cols = NULL, center = NULL, constant = 1.4826,
  na.rm = FALSE, dim. = dim(x), ...)

rowSds(x, rows = NULL, cols = NULL, na.rm = FALSE, center = NULL,
  dim. = dim(x), ...)

colSds(x, rows = NULL, cols = NULL, na.rm = FALSE, center = NULL,
  dim. = dim(x), ...)
}
\arguments{
\item{x}{A \code{\link[base]{numeric}} NxK \code{\link[base]{matrix}}.}

\item{rows, cols}{A \code{\link[base]{vector}} indicating subset of rows
(and/or columns) to operate over. If \code{\link[base]{NULL}}, no subsetting
is done.}

\item{center}{(optional) The center, defaults to the row means for the
SD estimators and row medians for the MAD estimators.}

\item{constant}{A scale factor.  See \code{\link[stats]{mad}} for details.}

\item{na.rm}{If \code{\link[base:logical]{TRUE}}, \code{\link[base]{NA}}s
are excluded first, otherwise not.}

\item{dim.}{An \code{\link[base]{integer}} \code{\link[base]{vector}} of
length two specifying the dimension of \code{x}, also when not a
\code{\link[base]{matrix}}.}

\item{...}{Additional arguments passed to \code{rowMeans()} and
\code{rowSums()}.}
}
\value{
Returns a \code{\link[base]{numeric}} \code{\link[base]{vector}} of
length N (K).
}
\description{
Standard deviation estimates for each row (column) in a matrix.
}
\seealso{
\code{\link[stats]{sd}}, \code{\link[stats]{mad}} and
\code{\link[stats:cor]{var}}.  \code{\link{rowIQRs}}().
}
\author{
Henrik Bengtsson
}
\keyword{array}
\keyword{iteration}
\keyword{robust}
\keyword{univar}
