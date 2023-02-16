/*
 * Interface/Wrapper for C functions generated by CasADi
 *
 * CasADi generated the following four files:
 * - auto_casadi_cost.c
 * - auto_casadi_grad.c
 * - auto_casadi_mapping_f1.c
 * - auto_casadi_mapping_f2.c
 *
 * This file is autogenerated by Optimization Engine
 * See http://doc.optimization-engine.xyz
 *
 *
 * Metadata:
 * + Optimizer
 *   + name: navi_test
 *   + version: 0.0.0
 *   + licence: MIT
 * + Problem
 *   + vars: 40
 *   + parameters: 2658
 *   + n1: 40
 *   + n2: 15
 *
 */
#include <stdlib.h>
#include "casadi_memory.h"

/* Number of input variables */
#define NU_NAVI_TEST 40

/* Number of static parameters */
#define NP_NAVI_TEST 2673

/* Dimension of F1 (number of ALM constraints) */
#define N1_NAVI_TEST 40

/* Dimension of F2 (number of PM constraints) */
#define N2_NAVI_TEST 15

/* Dimension of xi = (c, y) */
#define NXI_NAVI_TEST 41

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif


/* ------EXTERNAL FUNCTIONS (DEFINED IN C FILES)-------------------------------- */

/*
 * CasADi interface for the cost function
 */
extern int open_phi_navi_test(
    const casadi_real** arg, 
    casadi_real** res, 
    casadi_int* iw, 
    casadi_real* w, 
    void* mem);

/*
 * CasADi interface for the gradient of the cost
 */
extern int open_grad_phi_navi_test(
    const casadi_real** arg, 
    casadi_real** res, 
    casadi_int* iw, 
    casadi_real* w, 
    void* mem);

/*
 * CasADi interface for the gradient of mapping F1
 */
extern int open_mapping_f1_navi_test(
    const casadi_real** arg, 
    casadi_real** res, 
    casadi_int* iw, 
    casadi_real* w, 
    void* mem);

/*
 * CasADi interface for the gradient of mapping F2
 */
extern int open_mapping_f2_navi_test(
    const casadi_real** arg, 
    casadi_real** res, 
    casadi_int* iw, 
    casadi_real* w, 
    void* mem);


/* ------WORKSPACES------------------------------------------------------------- */

/* 
 * Integer workspaces 
 */
#if COST_SZ_IW_NAVI_TEST > 0
static casadi_int allocated_i_workspace_cost[COST_SZ_IW_NAVI_TEST];  /* cost (int )  */
#else
static casadi_int *allocated_i_workspace_cost = NULL;
#endif 

#if GRAD_SZ_IW_NAVI_TEST > 0
static casadi_int allocated_i_workspace_grad[GRAD_SZ_IW_NAVI_TEST];  /* grad (int )  */
#else
static casadi_int *allocated_i_workspace_grad = NULL;
#endif

#if F1_SZ_IW_NAVI_TEST > 0
static casadi_int allocated_i_workspace_f1[F1_SZ_IW_NAVI_TEST];      /* f1 (int )    */
#else
static casadi_int *allocated_i_workspace_f1 = NULL;
#endif

#if F2_SZ_IW_NAVI_TEST > 0
static casadi_int allocated_i_workspace_f2[F2_SZ_IW_NAVI_TEST];      /* f2 (int )    */
#else
static casadi_int *allocated_i_workspace_f2 = NULL;
#endif


/* 
 * Real workspaces 
 */
#if COST_SZ_W_NAVI_TEST > 0
static casadi_real allocated_r_workspace_cost[COST_SZ_W_NAVI_TEST];  /* cost (real)  */
#else 
static casadi_real *allocated_r_workspace_cost = NULL;
#endif


#if GRAD_SZ_W_NAVI_TEST > 0
static casadi_real allocated_r_workspace_grad[GRAD_SZ_W_NAVI_TEST];  /* grad (real ) */
#else
static casadi_real *allocated_r_workspace_grad = NULL;
#endif

#if F1_SZ_W_NAVI_TEST > 0
static casadi_real allocated_r_workspace_f1[F1_SZ_W_NAVI_TEST];      /* f1 (real )   */
#else
static casadi_real *allocated_r_workspace_f1 = NULL;
#endif

#if F2_SZ_W_NAVI_TEST > 0
static casadi_real allocated_r_workspace_f2[F2_SZ_W_NAVI_TEST];      /* f2 (real )   */
#else
static casadi_real *allocated_r_workspace_f2 = NULL;
#endif

/* 
 * Result workspaces 
 */
#if COST_SZ_RES_NAVI_TEST > 0
static casadi_real *result_space_cost[COST_SZ_RES_NAVI_TEST];       /* cost (res )  */
#else
static casadi_real **result_space_cost = NULL;
#endif

#if GRAD_SZ_RES_NAVI_TEST > 0
static casadi_real *result_space_grad[GRAD_SZ_RES_NAVI_TEST];        /* grad (res )  */
#else
static casadi_real **result_space_grad = NULL;
#endif


#if F1_SZ_RES_NAVI_TEST > 0
static casadi_real *result_space_f1[F1_SZ_RES_NAVI_TEST];            /* f1 (res )    */
#else
static casadi_real **result_space_f1 = NULL;
#endif


#if F2_SZ_RES_NAVI_TEST > 0
static casadi_real *result_space_f2[F2_SZ_RES_NAVI_TEST];            /* f2 (res )    */
#else
static casadi_real **result_space_f2 = NULL;
#endif



/* ------U, XI, P--------------------------------------------------------------- */

/*
 * Space for storing (u, xi, p)
 * that is, uxip_space = [u, xi, p]
 *
 * 0        NU-1      NU          NU+NXI-1   NU+NX          NU+NXI+NP-1
 * |--- u ----|       |---- xi -------|       |----- p ----------|
 * |                                                             |
 * |------------------- uxip_space ------------------------------|
 */
static casadi_real uxip_space[NU_NAVI_TEST
                              +NXI_NAVI_TEST
                              +NP_NAVI_TEST];

/**
 * Copy (u, xi, p) into uxip_space
 *
 * Input arguments:
 * - `arg = {u, xi, p}`, where `u`, `xi` and `p` are pointer-to-double
 */
static void copy_args_into_uxip_space(const casadi_real** arg) {
    int i;
    for (i=0; i<NU_NAVI_TEST; i++)  uxip_space[i] = arg[0][i];  /* copy u  */
    for (i=0; i<NXI_NAVI_TEST; i++) uxip_space[NU_NAVI_TEST+i] = arg[1][i];  /* copy xi */
    for (i=0; i<NP_NAVI_TEST; i++)  uxip_space[NU_NAVI_TEST+NXI_NAVI_TEST+i] = arg[2][i];  /* copy p  */
}

/**
 * Copy (u, p) into uxip_space
 */
static void copy_args_into_up_space(const casadi_real** arg) {
    int i;
    for (i=0; i<NU_NAVI_TEST; i++) uxip_space[i] = arg[0][i];  /* copy u  */
    for (i=0; i<NP_NAVI_TEST; i++) uxip_space[NU_NAVI_TEST+NXI_NAVI_TEST+i] = arg[1][i];  /* copy p  */
}

/* ------COST------------------------------------------------------------------- */

int cost_function_navi_test(const casadi_real** arg, casadi_real** res) {
    const casadi_real* args__[COST_SZ_ARG_NAVI_TEST] =
             {uxip_space,  /* :u  */
              uxip_space + NU_NAVI_TEST,  /* :xi  */
              uxip_space + NU_NAVI_TEST + NXI_NAVI_TEST};  /* :p  */
    copy_args_into_uxip_space(arg);

    result_space_cost[0] = res[0];
    return open_phi_navi_test(
        args__,
        result_space_cost,
        allocated_i_workspace_cost,
        allocated_r_workspace_cost,
        (void*) 0);
}


/* ------GRADIENT--------------------------------------------------------------- */

int grad_cost_function_navi_test(const casadi_real** arg, casadi_real** res) {
    const casadi_real* args__[GRAD_SZ_ARG_NAVI_TEST] =
            { uxip_space,  /* :u  */
              uxip_space + NU_NAVI_TEST,  /* :xi  */
              uxip_space + NU_NAVI_TEST + NXI_NAVI_TEST};  /* :p   */
    copy_args_into_uxip_space(arg);
    result_space_grad[0] = res[0];
    return open_grad_phi_navi_test(
        args__,
        result_space_grad,
        allocated_i_workspace_grad,
        allocated_r_workspace_grad,
        (void*) 0);
}


/* ------MAPPING F1------------------------------------------------------------- */

int mapping_f1_function_navi_test(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[F1_SZ_ARG_NAVI_TEST] =
            {uxip_space,  /* :u   */
            uxip_space + NU_NAVI_TEST + NXI_NAVI_TEST};  /* :p  */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_f1
     * (memory has been allocated - see beginning of this file)
     */
    result_space_f1[0] = res[0];
    /*
     * Call auto-generated function open_mapping_f1_navi_test
     * Implemented in: icasadi/extern/auto_casadi_mapping_f1.c
     */
    return open_mapping_f1_navi_test(
        args__,
        result_space_f1,
        allocated_i_workspace_f1,
        allocated_r_workspace_f1,
        (void*) 0);
}


/* ------MAPPING F2------------------------------------------------------------- */

int mapping_f2_function_navi_test(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[F2_SZ_ARG_NAVI_TEST] =
            {uxip_space,  /* :u   */
             uxip_space + NU_NAVI_TEST + NXI_NAVI_TEST};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_f2
     * (memory has been allocated - see beginning of this file)
     */
    result_space_f2[0] = res[0];
    /*
     * Call auto-generated function open_mapping_f2_navi_test
     * Implemented in: icasadi/extern/auto_casadi_mapping_f2.c
     */
    return open_mapping_f2_navi_test(
        args__,
        result_space_f2,
        allocated_i_workspace_f2,
        allocated_r_workspace_f2,
        (void*) 0);
}
