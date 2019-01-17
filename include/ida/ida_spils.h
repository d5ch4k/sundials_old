/*----------------------------------------------------------------- 
 * Programmer(s): Daniel R. Reynolds @ SMU
 *         Alan Hindmarsh, Radu Serban and Aaron Collier @ LLNL
 *-----------------------------------------------------------------
 * LLNS/SMU Copyright Start
 * Copyright (c) 2018, Southern Methodist University and 
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
 *-----------------------------------------------------------------
 * Header file for the deprecated Scaled and Preconditioned 
 * Iterative Linear Solver interface in IDA; these routines now just
 * wrap the updated IDA generic linear solver interface in ida_ls.h.
 *-----------------------------------------------------------------*/

#ifndef _IDASPILS_H
#define _IDASPILS_H

#include <ida/ida_ls.h>

#ifdef __cplusplus  /* wrapper to enable C++ usage */
extern "C" {
#endif

/*=================================================================
  Function Types (typedefs for equivalent types in ida_ls.h)
  =================================================================*/
typedef IDALsPrecSetupFn IDASpilsPrecSetupFn;
typedef IDALsPrecSolveFn IDASpilsPrecSolveFn;
typedef IDALsJacTimesSetupFn IDASpilsJacTimesSetupFn;
typedef IDALsJacTimesVecFn IDASpilsJacTimesVecFn;

/*=================================================================
  Exported Functions (wrappers for equivalent routines in ida_ls.h)
  =================================================================*/

int IDASpilsSetLinearSolver(void *ida_mem, SUNLinearSolver LS);

int IDASpilsSetPreconditioner(void *ida_mem, IDASpilsPrecSetupFn pset, 
                              IDASpilsPrecSolveFn psolve);

int IDASpilsSetJacTimes(void *ida_mem, IDASpilsJacTimesSetupFn jtsetup,
                        IDASpilsJacTimesVecFn jtimes);

int IDASpilsSetEpsLin(void *ida_mem, realtype eplifac);

int IDASpilsSetIncrementFactor(void *ida_mem, realtype dqincfac);

int IDASpilsGetWorkSpace(void *ida_mem, long int *lenrwLS, long int *leniwLS);

int IDASpilsGetNumPrecEvals(void *ida_mem, long int *npevals);

int IDASpilsGetNumPrecSolves(void *ida_mem, long int *npsolves);

int IDASpilsGetNumLinIters(void *ida_mem, long int *nliters);
  
int IDASpilsGetNumConvFails(void *ida_mem, long int *nlcfails);
  
int IDASpilsGetNumJTSetupEvals(void *ida_mem, long int *njtsetups);
  
int IDASpilsGetNumJtimesEvals(void *ida_mem, long int *njvevals);
  
int IDASpilsGetNumResEvals(void *ida_mem, long int *nrevalsLS);
  
int IDASpilsGetLastFlag(void *ida_mem, long int *flag);
  
char *IDASpilsGetReturnFlagName(long int flag);

#ifdef __cplusplus
}
#endif

#endif
