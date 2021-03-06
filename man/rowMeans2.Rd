% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/rowMeans2.R
\name{rowMeans2}
\alias{rowMeans2}
\alias{colMeans2}
\title{Calculates the mean for each row (column) in a matrix}
\usage{
rowMeans2(x, rows = NULL, cols = NULL, na.rm = FALSE, dim. = dim(x), ...)

colMeans2(x, rows = NULL, cols = NULL, na.rm = FALSE, dim. = dim(x), ...)
}
\arguments{
\item{x}{A \code{\link[base]{numeric}} or a \code{\link[base]{logical}}
NxK \code{\link[base]{matrix}}.}

\item{rows, cols}{A \code{\link[base]{vector}} indicating subset of rows
(and/or columns) to operate over. If \code{\link[base]{NULL}}, no subsetting
is done.}

\item{na.rm}{If \code{\link[base:logical]{TRUE}}, \code{\link[base]{NA}}s
are excluded first, otherwise not.}

\item{dim.}{An \code{\link[base]{integer}} \code{\link[base]{vector}} of
length two specifying the dimension of \code{x}, also when not a
\code{\link[base]{matrix}}.}

\item{...}{Not used.}
}
\value{
Returns a \code{\link[base]{numeric}} \code{\link[base]{vector}} of
length N (K).
}
\description{
Calculates the mean for each row (column) in a matrix.
}
\details{
The implementation of \code{rowMeans2()} and \code{colMeans2()} is
optimized for both speed and memory.
}
\author{
Henrik Bengtsson
}
\keyword{array}
\keyword{iteration}
\keyword{robust}
\keyword{univar}
