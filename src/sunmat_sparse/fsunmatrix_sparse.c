/*
 * -----------------------------------------------------------------
 * Programmer(s): Daniel Reynolds @ SMU
 *                David Gardner, Carol Woodward, Slaven Peles @ LLNL
 * -----------------------------------------------------------------
 * LLNS/SMU Copyright Start
 * Copyright (c) 2017, Southern Methodist University and 
 * Lawrence Livermore National Security
 *
 * This work was performed under the auspices of the U.S. Department 
 * of Energy by Southern Methodist University and Lawrence Livermore 
 * National Laboratory under Contract DE-AC52-07NA27344.
 * Produced at Southern Methodist University and the Lawrence 
 * Livermore National Laboratory.
 *
 * All rights reserved.
 * For details, see the LICENSE file.
 * LLNS/SMU Copyright End
 * -----------------------------------------------------------------
 * This file (companion of fsunmatrix_sparse.h) contains the
 * implementation needed for the Fortran initialization of sparse
 * vector operations.
 * -----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#include "fsunmatrix_sparse.h"

/* Define global matrix variables */

SUNMatrix F2C_CVODE_matrix;
SUNMatrix F2C_IDA_matrix;
SUNMatrix F2C_KINSOL_matrix;
SUNMatrix F2C_ARKODE_matrix;

/* Fortran callable interfaces */

void FSUNMATRIX_INITS(int *code, long int *M, long int *N,
                      long int *NNZ, int *sparsetype, int *ier)
{
  *ier = 0;

  switch(*code) {
  case FCMIX_CVODE:
    F2C_CVODE_matrix = NULL;
    F2C_CVODE_matrix = SUNMatrixNew_Sparse(*M, *N, *NNZ, *sparsetype);
    if (F2C_CVODE_matrix == NULL) *ier = -1;
    break;
  case FCMIX_IDA:
    F2C_IDA_matrix = NULL;
    F2C_IDA_matrix = SUNMatrixNew_Sparse(*M, *N, *NNZ, *sparsetype);
    if (F2C_IDA_matrix == NULL) *ier = -1;
    break;
  case FCMIX_KINSOL:
    F2C_KINSOL_matrix = NULL;
    F2C_KINSOL_matrix = SUNMatrixNew_Sparse(*M, *N, *NNZ, *sparsetype);
    if (F2C_KINSOL_matrix == NULL) *ier = -1;
    break;
  case FCMIX_ARKODE:
    F2C_ARKODE_matrix = NULL;
    F2C_ARKODE_matrix = SUNMatrixNew_Sparse(*M, *N, *NNZ, *sparsetype);
    if (F2C_ARKODE_matrix == NULL) *ier = -1;
    break;
  default:
    *ier = -1;
  }
}
