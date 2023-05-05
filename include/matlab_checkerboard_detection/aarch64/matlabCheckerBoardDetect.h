//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: matlabCheckerBoardDetect.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 04-May-2023 18:30:42
//

#ifndef MATLABCHECKERBOARDDETECT_H
#define MATLABCHECKERBOARDDETECT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Variable Declarations
extern omp_nest_lock_t matlabCheckerBoardDetect_nestLockGlobal;

// Function Declarations
extern void
matlabCheckerBoardDetect(const coder::array<unsigned char, 2U> &image,
                         coder::array<double, 2U> &corners,
                         double boardSize[2]);

extern void matlabCheckerBoardDetect_initialize();

extern void matlabCheckerBoardDetect_terminate();

#endif
//
// File trailer for matlabCheckerBoardDetect.h
//
// [EOF]
//
