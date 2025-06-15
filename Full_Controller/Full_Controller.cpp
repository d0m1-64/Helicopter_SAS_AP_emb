//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Full_Controller.cpp
//
// Code generated for Simulink model 'Full_Controller'.
//
// Model version                  : 2.33
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Fri Jun 13 14:59:15 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Full_Controller.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include "Full_Controller_private.h"

// Output and update for referenced model: 'Full_Controller'
void Full_Controller::step(const real_T *rtu_Pilot_Controls_delta_long, const
  real_T *rtu_Pilot_Controls_delta_lat, const real_T
  *rtu_Pilot_Controls_delta_coll, const real_T *rtu_Pilot_Controls_delta_ped,
  const real_T *rtu_AP_ref_states_GS_x, const real_T *rtu_AP_ref_states_GS_y,
  const real_T *rtu_AP_ref_states_VS, const real_T *rtu_AP_ref_states_psi, const
  real_T *rtu_Wind_measurement_Wind_x_B, const real_T
  *rtu_Wind_measurement_Wind_y_B, const real_T *rtu_Wind_measurement_Wind_z_B,
  const boolean_T *rtu_Cntrl_flags_AP_enabled, const boolean_T
  *rtu_Cntrl_flags_SAS_enabled, const real_T *rtu_Helicopter_Response_u, const
  real_T *rtu_Helicopter_Response_w, const real_T *rtu_Helicopter_Response_q,
  const real_T *rtu_Helicopter_Response_theta, const real_T
  *rtu_Helicopter_Response_v, const real_T *rtu_Helicopter_Response_p, const
  real_T *rtu_Helicopter_Response_phi, const real_T *rtu_Helicopter_Response_r,
  real_T *rty_Helicopter_Model_Input_delt, real_T
  *rty_Helicopter_Model_Input_de_g, real_T *rty_Helicopter_Model_Input_de_c,
  real_T *rty_Helicopter_Model_Input_de_e)
{
  real_T rtu_Helicopter_Response_u_0[8];
  real_T tmp[2];
  real_T delta_coll_d;
  real_T delta_lat_c;
  real_T delta_long_o;
  real_T delta_ped_l;
  real_T rtb_Integrator_n;
  real_T rtb_KMatrixFeedback_idx_0;
  real_T rtb_KMatrixFeedback_idx_1;
  real_T rtb_KMatrixFeedback_idx_2;
  real_T rtb_KMatrixFeedback_idx_3;
  real_T rtb_Sum11;
  real_T rtb_Sum2;
  real_T rtb_Sum4;
  real_T rtb_Sum9;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_e;

  // SignalConversion generated from: '<S2>/K-Matrix Feedback'
  rtu_Helicopter_Response_u_0[0] = *rtu_Helicopter_Response_u;
  rtu_Helicopter_Response_u_0[1] = *rtu_Helicopter_Response_w;
  rtu_Helicopter_Response_u_0[2] = *rtu_Helicopter_Response_q;
  rtu_Helicopter_Response_u_0[3] = *rtu_Helicopter_Response_theta;
  rtu_Helicopter_Response_u_0[4] = *rtu_Helicopter_Response_v;
  rtu_Helicopter_Response_u_0[5] = *rtu_Helicopter_Response_p;
  rtu_Helicopter_Response_u_0[6] = *rtu_Helicopter_Response_phi;
  rtu_Helicopter_Response_u_0[7] = *rtu_Helicopter_Response_r;

  // Gain: '<S2>/K-Matrix Feedback'
  rtb_KMatrixFeedback_idx_0 = 0.0;
  rtb_KMatrixFeedback_idx_1 = 0.0;
  rtb_KMatrixFeedback_idx_2 = 0.0;
  rtb_KMatrixFeedback_idx_3 = 0.0;
  for (int32_T i{0}; i < 8; i++) {
    __m128d tmp_1;
    int32_T tmp_0;
    tmp_0 = i << 2;
    tmp_1 = _mm_set1_pd(rtu_Helicopter_Response_u_0[i]);
    _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtCP_KMatrixFeedback_Gain[tmp_0]), tmp_1), _mm_set_pd
      (rtb_KMatrixFeedback_idx_1, rtb_KMatrixFeedback_idx_0)));
    rtb_KMatrixFeedback_idx_0 = tmp[0];
    rtb_KMatrixFeedback_idx_1 = tmp[1];
    _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtCP_KMatrixFeedback_Gain[tmp_0 + 2]), tmp_1), _mm_set_pd
      (rtb_KMatrixFeedback_idx_3, rtb_KMatrixFeedback_idx_2)));
    rtb_KMatrixFeedback_idx_2 = tmp[0];
    rtb_KMatrixFeedback_idx_3 = tmp[1];
  }

  // End of Gain: '<S2>/K-Matrix Feedback'

  // Sum: '<S2>/Sum' incorporates:
  //   DiscreteTransferFcn: '<S2>/Long Lat Filter'

  rtb_KMatrixFeedback_idx_0 = Full_Controller_DW.LongLatFilter_states -
    rtb_KMatrixFeedback_idx_0;

  // Sum: '<S2>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S2>/Lat Lat Filter'

  rtb_KMatrixFeedback_idx_1 = Full_Controller_DW.LatLatFilter_states -
    rtb_KMatrixFeedback_idx_1;

  // Sum: '<S2>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<S2>/Coll Lat Filter'

  rtb_KMatrixFeedback_idx_2 = Full_Controller_DW.CollLatFilter_states -
    rtb_KMatrixFeedback_idx_2;

  // Sum: '<S2>/Sum3' incorporates:
  //   DiscreteTransferFcn: '<S2>/Ped Lat Filter'

  rtb_KMatrixFeedback_idx_3 = Full_Controller_DW.PedLatFilter_states -
    rtb_KMatrixFeedback_idx_3;

  // Sum: '<S1>/Sum' incorporates:
  //   Sum: '<S1>/Add'

  rtb_Integrator_n = *rtu_AP_ref_states_GS_x - (*rtu_Helicopter_Response_u +
    *rtu_Wind_measurement_Wind_x_B);

  // Sum: '<S1>/Sum4' incorporates:
  //   DiscreteIntegrator: '<S95>/Integrator'
  //   Gain: '<S100>/Proportional Gain'
  //   Sum: '<S104>/Sum'

  rtb_Sum4 = (1.5 * rtb_Integrator_n + Full_Controller_DW.Integrator_DSTATE) -
    *rtu_Helicopter_Response_theta;

  // Logic: '<S1>/NOT'
  rtb_NOT = !*rtu_Cntrl_flags_AP_enabled;

  // Switch generated from: '<S1>/Switch'
  if (rtb_NOT) {
    // Switch generated from: '<S1>/Switch'
    delta_long_o = *rtu_Pilot_Controls_delta_long;

    // Switch generated from: '<S1>/Switch'
    delta_coll_d = *rtu_Pilot_Controls_delta_coll;
  } else {
    // Switch generated from: '<S1>/Switch' incorporates:
    //   DiscreteIntegrator: '<S199>/Integrator'
    //   Sum: '<S208>/Sum'

    delta_long_o = rtb_Sum4 + Full_Controller_DW.Integrator_DSTATE_p;

    // Switch generated from: '<S1>/Switch' incorporates:
    //   Gain: '<S48>/Proportional Gain'
    //   Sum: '<S1>/Add2'
    //   Sum: '<S1>/Sum10'

    delta_coll_d = (*rtu_AP_ref_states_VS - (*rtu_Helicopter_Response_w +
      *rtu_Wind_measurement_Wind_z_B)) * 3.0;
  }

  // Logic: '<S2>/NOT'
  rtb_NOT_e = !*rtu_Cntrl_flags_SAS_enabled;

  // Switch generated from: '<S2>/Switch' incorporates:
  //   DiscreteTransferFcn: '<S2>/Coll Rolloff Filter'
  //   DiscreteTransferFcn: '<S2>/Long Rolloff Filter'

  if (rtb_NOT_e) {
    *rty_Helicopter_Model_Input_delt = delta_long_o;
    *rty_Helicopter_Model_Input_de_c = delta_coll_d;
  } else {
    *rty_Helicopter_Model_Input_delt = 40.0 *
      Full_Controller_DW.LongRolloffFilter_states;
    *rty_Helicopter_Model_Input_de_c = 40.0 *
      Full_Controller_DW.CollRolloffFilter_states;
  }

  // Sum: '<S1>/Sum11' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

  rtb_Sum11 = *rtu_AP_ref_states_psi -
    Full_Controller_DW.DiscreteTimeIntegrator_DSTATE;

  // Switch generated from: '<S1>/Switch'
  if (rtb_NOT) {
    // Switch generated from: '<S1>/Switch'
    delta_ped_l = *rtu_Pilot_Controls_delta_ped;
  } else {
    // Switch generated from: '<S1>/Switch' incorporates:
    //   DiscreteIntegrator: '<S303>/Integrator'
    //   Sum: '<S312>/Sum'

    delta_ped_l = rtb_Sum11 + Full_Controller_DW.Integrator_DSTATE_e;
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   DiscreteTransferFcn: '<S2>/Ped Rolloff Filter'

  if (rtb_NOT_e) {
    *rty_Helicopter_Model_Input_de_e = delta_ped_l;
  } else {
    *rty_Helicopter_Model_Input_de_e = 40.0 *
      Full_Controller_DW.PedRolloffFilter_states;
  }

  // Sum: '<S1>/Sum2' incorporates:
  //   Sum: '<S1>/Add1'

  rtb_Sum2 = *rtu_AP_ref_states_GS_y - (*rtu_Helicopter_Response_v +
    *rtu_Wind_measurement_Wind_y_B);

  // Sum: '<S1>/Sum9' incorporates:
  //   DiscreteIntegrator: '<S147>/Integrator'
  //   Gain: '<S152>/Proportional Gain'
  //   Sum: '<S156>/Sum'

  rtb_Sum9 = (6.0 * rtb_Sum2 + Full_Controller_DW.Integrator_DSTATE_f) -
    *rtu_Helicopter_Response_phi;

  // Switch generated from: '<S1>/Switch'
  if (rtb_NOT) {
    // Switch generated from: '<S1>/Switch'
    delta_lat_c = *rtu_Pilot_Controls_delta_lat;
  } else {
    // Switch generated from: '<S1>/Switch' incorporates:
    //   DiscreteIntegrator: '<S251>/Integrator'
    //   Sum: '<S260>/Sum'

    delta_lat_c = rtb_Sum9 + Full_Controller_DW.Integrator_DSTATE_i;
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   DiscreteTransferFcn: '<S2>/Lat Rolloff Filter'

  if (rtb_NOT_e) {
    *rty_Helicopter_Model_Input_de_g = delta_lat_c;
  } else {
    *rty_Helicopter_Model_Input_de_g = 40.0 *
      Full_Controller_DW.LatRolloffFilter_states;
  }

  // Update for DiscreteTransferFcn: '<S2>/Long Lat Filter'
  Full_Controller_DW.LongLatFilter_states = (delta_long_o -
    Full_Controller_DW.LongLatFilter_states) / 0.0001;

  // Update for DiscreteTransferFcn: '<S2>/Lat Lat Filter'
  Full_Controller_DW.LatLatFilter_states = (delta_lat_c -
    Full_Controller_DW.LatLatFilter_states) / 0.0001;

  // Update for DiscreteTransferFcn: '<S2>/Coll Lat Filter'
  Full_Controller_DW.CollLatFilter_states = (delta_coll_d -
    Full_Controller_DW.CollLatFilter_states) / 0.0001;

  // Update for DiscreteTransferFcn: '<S2>/Ped Lat Filter'
  Full_Controller_DW.PedLatFilter_states = (delta_ped_l -
    Full_Controller_DW.PedLatFilter_states) / 0.0001;

  // Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
  //   Gain: '<S92>/Integral Gain'

  Full_Controller_DW.Integrator_DSTATE += 0.001 * rtb_Integrator_n *
    0.016666666666666666;

  // Update for DiscreteIntegrator: '<S199>/Integrator' incorporates:
  //   Gain: '<S196>/Integral Gain'

  Full_Controller_DW.Integrator_DSTATE_p += 0.01 * rtb_Sum4 *
    0.016666666666666666;

  // Update for DiscreteTransferFcn: '<S2>/Long Rolloff Filter'
  Full_Controller_DW.LongRolloffFilter_states = rtb_KMatrixFeedback_idx_0 - 40.0
    * Full_Controller_DW.LongRolloffFilter_states;

  // Update for DiscreteTransferFcn: '<S2>/Coll Rolloff Filter'
  Full_Controller_DW.CollRolloffFilter_states = rtb_KMatrixFeedback_idx_2 - 40.0
    * Full_Controller_DW.CollRolloffFilter_states;

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  Full_Controller_DW.DiscreteTimeIntegrator_DSTATE += 0.016666666666666666 *
    *rtu_Helicopter_Response_r;

  // Update for DiscreteIntegrator: '<S303>/Integrator' incorporates:
  //   Gain: '<S300>/Integral Gain'

  Full_Controller_DW.Integrator_DSTATE_e += 0.1 * rtb_Sum11 *
    0.016666666666666666;

  // Update for DiscreteTransferFcn: '<S2>/Ped Rolloff Filter'
  Full_Controller_DW.PedRolloffFilter_states = rtb_KMatrixFeedback_idx_3 - 40.0 *
    Full_Controller_DW.PedRolloffFilter_states;

  // Update for DiscreteIntegrator: '<S147>/Integrator' incorporates:
  //   Gain: '<S144>/Integral Gain'

  Full_Controller_DW.Integrator_DSTATE_f += 0.001 * rtb_Sum2 *
    0.016666666666666666;

  // Update for DiscreteIntegrator: '<S251>/Integrator' incorporates:
  //   Gain: '<S248>/Integral Gain'

  Full_Controller_DW.Integrator_DSTATE_i += 0.01 * rtb_Sum9 *
    0.016666666666666666;

  // Update for DiscreteTransferFcn: '<S2>/Lat Rolloff Filter'
  Full_Controller_DW.LatRolloffFilter_states = rtb_KMatrixFeedback_idx_1 - 40.0 *
    Full_Controller_DW.LatRolloffFilter_states;
}

const char_T* Full_Controller::RT_MODEL_Full_Controller_T::getErrorStatus()
  const
{
  return (*(errorStatus));
}

void Full_Controller::RT_MODEL_Full_Controller_T::setErrorStatus(const char_T*
  const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Full_Controller::RT_MODEL_Full_Controller_T::
  getErrorStatusPointer() const
{
  return errorStatus;
}

void Full_Controller::RT_MODEL_Full_Controller_T::setErrorStatusPointer(const
  char_T** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Full_Controller::Full_Controller() :
  Full_Controller_DW(),
  Full_Controller_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Full_Controller::~Full_Controller() = default;

// Real-Time Model get method
Full_Controller::RT_MODEL_Full_Controller_T * Full_Controller::getRTM()
{
  return (&Full_Controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
