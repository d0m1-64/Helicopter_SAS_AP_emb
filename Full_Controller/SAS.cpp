//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SAS.cpp
//
// Code generated for Simulink model 'SAS'.
//
// Model version                  : 2.44
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Sun Jun 15 15:06:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "SAS.h"
#include "rtwtypes.h"
#include <emmintrin.h>

SAS::P_SAS_T SAS::SAS_rtP{
  // Expression: [1-Lag_Filter_Coll_Const]
  //  Referenced by: '<Root>/Coll Lag Filter'

  0.15000000000000002,

  // Expression: [1, -Lag_Filter_Coll_Const]
  //  Referenced by: '<Root>/Coll Lag Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Coll Lag Filter'

  0.0,

  // Expression: [1-Rolloff_Filter_Coll_Const]
  //  Referenced by: '<Root>/Coll Rolloff Filter'

  0.15000000000000002,

  // Expression: [1,-Rolloff_Filter_Coll_Const]
  //  Referenced by: '<Root>/Coll Rolloff Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Coll Rolloff Filter'

  0.0,

  // Expression: [1-Lag_Filter_Lat_Const]
  //  Referenced by: '<Root>/Lat Lag Filter'

  0.15000000000000002,

  // Expression: [1, -Lag_Filter_Lat_Const]
  //  Referenced by: '<Root>/Lat Lag Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Lat Lag Filter'

  0.0,

  // Expression: [1-Rolloff_Filter_Lat_Const]
  //  Referenced by: '<Root>/Lat Rolloff Filter'

  0.15000000000000002,

  // Expression: [1,-Rolloff_Filter_Lat_Const]
  //  Referenced by: '<Root>/Lat Rolloff Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Lat Rolloff Filter'

  0.0,

  // Expression: [1-Lag_Filter_Long_Const]
  //  Referenced by: '<Root>/Long Lag Filter'

  0.15000000000000002,

  // Expression: [1, -Lag_Filter_Long_Const]
  //  Referenced by: '<Root>/Long Lag Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Long Lag Filter'

  0.0,

  // Expression: [1-Rolloff_Filter_Long_Const]
  //  Referenced by: '<Root>/Long Rolloff Filter'

  0.15000000000000002,

  // Expression: [1, -Rolloff_Filter_Long_Const]
  //  Referenced by: '<Root>/Long Rolloff Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Long Rolloff Filter'

  0.0,

  // Expression: [1-Lag_Filter_Ped_Const]
  //  Referenced by: '<Root>/Ped Lag Filter'

  0.15000000000000002,

  // Expression: [1, -Lag_Filter_Ped_Const]
  //  Referenced by: '<Root>/Ped Lag Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Ped Lag Filter'

  0.0,

  // Expression: [1-Rolloff_Filter_Ped_Const]
  //  Referenced by: '<Root>/Ped Rolloff Filter'

  0.15000000000000002,

  // Expression: [1,-Rolloff_Filter_Ped_Const]
  //  Referenced by: '<Root>/Ped Rolloff Filter'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<Root>/Ped Rolloff Filter'

  0.0
};

// System initialize for referenced model: 'SAS'
void SAS::init(void)
{
  // InitializeConditions for DiscreteTransferFcn: '<Root>/Coll Lag Filter'
  SAS_DW.CollLagFilter_states = SAS_rtP.CollLagFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Coll Rolloff Filter'
  SAS_DW.CollRolloffFilter_states = SAS_rtP.CollRolloffFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Lat Lag Filter'
  SAS_DW.LatLagFilter_states = SAS_rtP.LatLagFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Lat Rolloff Filter'
  SAS_DW.LatRolloffFilter_states = SAS_rtP.LatRolloffFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Long Lag Filter'
  SAS_DW.LongLagFilter_states = SAS_rtP.LongLagFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Long Rolloff Filter'
  SAS_DW.LongRolloffFilter_states = SAS_rtP.LongRolloffFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Ped Lag Filter'
  SAS_DW.PedLagFilter_states = SAS_rtP.PedLagFilter_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<Root>/Ped Rolloff Filter'
  SAS_DW.PedRolloffFilter_states = SAS_rtP.PedRolloffFilter_InitialStates;
}

// Output and update for referenced model: 'SAS'
void SAS::step(const boolean_T *rtu_Cntrl_flags_SAS_enabled, const real_T
               *rtu_w_delta_long, const real_T *rtu_w_delta_lat, const real_T
               *rtu_w_delta_coll, const real_T *rtu_w_delta_ped, const real_T
               *rtu_y_u, const real_T *rtu_y_w, const real_T *rtu_y_q, const
               real_T *rtu_y_theta, const real_T *rtu_y_v, const real_T *rtu_y_p,
               const real_T *rtu_y_phi, const real_T *rtu_y_r, real_T
               *rty_u_delta_long, real_T *rty_u_delta_lat, real_T
               *rty_u_delta_coll, real_T *rty_u_delta_ped)
{
  real_T rtu_y_u_0[8];
  real_T tmp[2];
  real_T rtb_KMatrixFeedback_idx_0;
  real_T rtb_KMatrixFeedback_idx_1;
  real_T rtb_KMatrixFeedback_idx_2;
  real_T rtb_KMatrixFeedback_idx_3;

  // SignalConversion generated from: '<Root>/K-Matrix Feedback'
  rtu_y_u_0[0] = *rtu_y_u;
  rtu_y_u_0[1] = *rtu_y_w;
  rtu_y_u_0[2] = *rtu_y_q;
  rtu_y_u_0[3] = *rtu_y_theta;
  rtu_y_u_0[4] = *rtu_y_v;
  rtu_y_u_0[5] = *rtu_y_p;
  rtu_y_u_0[6] = *rtu_y_phi;
  rtu_y_u_0[7] = *rtu_y_r;

  // Gain: '<Root>/K-Matrix Feedback'
  rtb_KMatrixFeedback_idx_0 = 0.0;
  rtb_KMatrixFeedback_idx_1 = 0.0;
  rtb_KMatrixFeedback_idx_2 = 0.0;
  rtb_KMatrixFeedback_idx_3 = 0.0;
  for (int32_T i{0}; i < 8; i++) {
    __m128d tmp_1;
    int32_T tmp_0;
    tmp_0 = i << 2;
    tmp_1 = _mm_set1_pd(rtu_y_u_0[i]);
    _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtP_K_SAS_Feedback_Gain_Matrix[tmp_0]), tmp_1), _mm_set_pd
      (rtb_KMatrixFeedback_idx_1, rtb_KMatrixFeedback_idx_0)));
    rtb_KMatrixFeedback_idx_0 = tmp[0];
    rtb_KMatrixFeedback_idx_1 = tmp[1];
    _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtP_K_SAS_Feedback_Gain_Matrix[tmp_0 + 2]), tmp_1), _mm_set_pd
      (rtb_KMatrixFeedback_idx_3, rtb_KMatrixFeedback_idx_2)));
    rtb_KMatrixFeedback_idx_2 = tmp[0];
    rtb_KMatrixFeedback_idx_3 = tmp[1];
  }

  // End of Gain: '<Root>/K-Matrix Feedback'

  // Switch generated from: '<Root>/Switch' incorporates:
  //   DiscreteTransferFcn: '<Root>/Coll Rolloff Filter'
  //   DiscreteTransferFcn: '<Root>/Lat Rolloff Filter'
  //   DiscreteTransferFcn: '<Root>/Long Rolloff Filter'
  //   DiscreteTransferFcn: '<Root>/Ped Rolloff Filter'
  //   Logic: '<Root>/NOT'

  if (!*rtu_Cntrl_flags_SAS_enabled) {
    *rty_u_delta_long = *rtu_w_delta_long;
    *rty_u_delta_lat = *rtu_w_delta_lat;
    *rty_u_delta_coll = *rtu_w_delta_coll;
    *rty_u_delta_ped = *rtu_w_delta_ped;
  } else {
    *rty_u_delta_long = SAS_rtP.LongRolloffFilter_NumCoef *
      SAS_DW.LongRolloffFilter_states;
    *rty_u_delta_lat = SAS_rtP.LatRolloffFilter_NumCoef *
      SAS_DW.LatRolloffFilter_states;
    *rty_u_delta_coll = SAS_rtP.CollRolloffFilter_NumCoef *
      SAS_DW.CollRolloffFilter_states;
    *rty_u_delta_ped = SAS_rtP.PedRolloffFilter_NumCoef *
      SAS_DW.PedRolloffFilter_states;
  }

  // End of Switch generated from: '<Root>/Switch'

  // Sum: '<Root>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<Root>/Coll Lag Filter'
  //   DiscreteTransferFcn: '<Root>/Coll Rolloff Filter'
  //
  _mm_storeu_pd(&tmp[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
    (SAS_rtP.CollLagFilter_NumCoef * SAS_DW.CollLagFilter_states -
     rtb_KMatrixFeedback_idx_2, *rtu_w_delta_coll), _mm_mul_pd(_mm_set_pd
    (SAS_rtP.CollRolloffFilter_DenCoef[1], SAS_rtP.CollLagFilter_DenCoef[1]),
    _mm_set_pd(SAS_DW.CollRolloffFilter_states, SAS_DW.CollLagFilter_states))),
    _mm_set_pd(SAS_rtP.CollRolloffFilter_DenCoef[0],
               SAS_rtP.CollLagFilter_DenCoef[0])));

  // Update for DiscreteTransferFcn: '<Root>/Coll Lag Filter'
  SAS_DW.CollLagFilter_states = tmp[0];

  // Update for DiscreteTransferFcn: '<Root>/Coll Rolloff Filter'
  SAS_DW.CollRolloffFilter_states = tmp[1];

  // Sum: '<Root>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<Root>/Lat Lag Filter'
  //   DiscreteTransferFcn: '<Root>/Lat Rolloff Filter'
  //
  _mm_storeu_pd(&tmp[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
    (SAS_rtP.LatLagFilter_NumCoef * SAS_DW.LatLagFilter_states -
     rtb_KMatrixFeedback_idx_1, *rtu_w_delta_lat), _mm_mul_pd(_mm_set_pd
    (SAS_rtP.LatRolloffFilter_DenCoef[1], SAS_rtP.LatLagFilter_DenCoef[1]),
    _mm_set_pd(SAS_DW.LatRolloffFilter_states, SAS_DW.LatLagFilter_states))),
    _mm_set_pd(SAS_rtP.LatRolloffFilter_DenCoef[0],
               SAS_rtP.LatLagFilter_DenCoef[0])));

  // Update for DiscreteTransferFcn: '<Root>/Lat Lag Filter'
  SAS_DW.LatLagFilter_states = tmp[0];

  // Update for DiscreteTransferFcn: '<Root>/Lat Rolloff Filter'
  SAS_DW.LatRolloffFilter_states = tmp[1];

  // Sum: '<Root>/Sum' incorporates:
  //   DiscreteTransferFcn: '<Root>/Long Lag Filter'
  //   DiscreteTransferFcn: '<Root>/Long Rolloff Filter'
  //
  _mm_storeu_pd(&tmp[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
    (SAS_rtP.LongLagFilter_NumCoef * SAS_DW.LongLagFilter_states -
     rtb_KMatrixFeedback_idx_0, *rtu_w_delta_long), _mm_mul_pd(_mm_set_pd
    (SAS_rtP.LongRolloffFilter_DenCoef[1], SAS_rtP.LongLagFilter_DenCoef[1]),
    _mm_set_pd(SAS_DW.LongRolloffFilter_states, SAS_DW.LongLagFilter_states))),
    _mm_set_pd(SAS_rtP.LongRolloffFilter_DenCoef[0],
               SAS_rtP.LongLagFilter_DenCoef[0])));

  // Update for DiscreteTransferFcn: '<Root>/Long Lag Filter'
  SAS_DW.LongLagFilter_states = tmp[0];

  // Update for DiscreteTransferFcn: '<Root>/Long Rolloff Filter'
  SAS_DW.LongRolloffFilter_states = tmp[1];

  // Sum: '<Root>/Sum3' incorporates:
  //   DiscreteTransferFcn: '<Root>/Ped Lag Filter'
  //   DiscreteTransferFcn: '<Root>/Ped Rolloff Filter'
  //
  _mm_storeu_pd(&tmp[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
    (SAS_rtP.PedLagFilter_NumCoef * SAS_DW.PedLagFilter_states -
     rtb_KMatrixFeedback_idx_3, *rtu_w_delta_ped), _mm_mul_pd(_mm_set_pd
    (SAS_rtP.PedRolloffFilter_DenCoef[1], SAS_rtP.PedLagFilter_DenCoef[1]),
    _mm_set_pd(SAS_DW.PedRolloffFilter_states, SAS_DW.PedLagFilter_states))),
    _mm_set_pd(SAS_rtP.PedRolloffFilter_DenCoef[0],
               SAS_rtP.PedLagFilter_DenCoef[0])));

  // Update for DiscreteTransferFcn: '<Root>/Ped Lag Filter'
  SAS_DW.PedLagFilter_states = tmp[0];

  // Update for DiscreteTransferFcn: '<Root>/Ped Rolloff Filter'
  SAS_DW.PedRolloffFilter_states = tmp[1];
}

const char_T* SAS::RT_MODEL_SAS_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void SAS::RT_MODEL_SAS_T::setErrorStatus(const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** SAS::RT_MODEL_SAS_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void SAS::RT_MODEL_SAS_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
SAS::SAS() :
  SAS_DW(),
  SAS_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
SAS::~SAS() = default;

// Real-Time Model get method
SAS::RT_MODEL_SAS_T * SAS::getRTM()
{
  return (&SAS_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
