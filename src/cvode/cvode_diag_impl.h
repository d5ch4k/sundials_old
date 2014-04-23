/*
 * -----------------------------------------------------------------
 * $Revision$
 * $Date$
 * ----------------------------------------------------------------- 
 * Programmer(s): Scott D. Cohen, Alan C. Hindmarsh and
 *                Radu Serban @ LLNL
 * -----------------------------------------------------------------
 * LLNS Copyright Start
 * Copyright (c) 2013, Lawrence Livermore National Security
 * This work was performed under the auspices of the U.S. Department 
 * of Energy by Lawrence Livermore National Laboratory in part under 
 * Contract W-7405-Eng-48 and in part under Contract DE-AC52-07NA27344.
 * Produced at the Lawrence Livermore National Laboratory.
 * All rights reserved.
 * For details, see the LICENSE file.
 * LLNS Copyright End
 * -----------------------------------------------------------------
 * Implementation header file for the diagonal linear solver, CVDIAG.
 * -----------------------------------------------------------------
 */

#ifndef _CVDIAG_IMPL_H
#define _CVDIAG_IMPL_H

#ifdef __cplusplus  /* wrapper to enable C++ usage */
extern "C" {
#endif

#include <cvode/cvode_diag.h>

/*
 * -----------------------------------------------------------------
 * Types: CVDiagMemRec, CVDiagMem
 * -----------------------------------------------------------------
 * The type CVDiagMem is pointer to a CVDiagMemRec.
 * This structure contains CVDiag solver-specific data.
 * -----------------------------------------------------------------
 */

typedef struct {

  realtype di_gammasv; /* gammasv = gamma at the last call to setup */
                       /* or solve                                  */

  N_Vector di_M;       /* M = (I - gamma J)^{-1} , gamma = h / l1   */

  N_Vector di_bit;     /* temporary storage vector                  */

  N_Vector di_bitcomp; /* temporary storage vector                  */

  long int di_nfeDI;   /* no. of calls to f due to difference 
                          quotient diagonal Jacobian approximation  */

  long int di_last_flag;    /* last error return flag                    */

} CVDiagMemRec, *CVDiagMem;

/* Error Messages */

#define MSGDG_CVMEM_NULL "Integrator memory is NULL."
#define MSGDG_BAD_NVECTOR "A required vector operation is not implemented."
#define MSGDG_MEM_FAIL "A memory request failed."
#define MSGDG_LMEM_NULL "CVDIAG memory is NULL."
#define MSGDG_RHSFUNC_FAILED "The right-hand side routine failed in an unrecoverable manner."

#ifdef __cplusplus
}
#endif

#endif
