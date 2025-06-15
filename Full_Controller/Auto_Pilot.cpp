//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Auto_Pilot.cpp
//
// Code generated for Simulink model 'Auto_Pilot'.
//
// Model version                  : 2.43
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Sun Jun 15 15:05:03 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Auto_Pilot.h"
#include "rtwtypes.h"

Auto_Pilot::P_Auto_Pilot_T Auto_Pilot::Auto_Pilot_rtP{
  // Mask Parameter: PIGSxController_InitialConditio
  //  Referenced by: '<S93>/Integrator'

  0.0,

  // Mask Parameter: PIGSyController_InitialConditio
  //  Referenced by: '<S145>/Integrator'

  0.0,

  // Mask Parameter: PIPitchController_InitialCondit
  //  Referenced by: '<S197>/Integrator'

  0.0,

  // Mask Parameter: PIRollController_InitialConditi
  //  Referenced by: '<S249>/Integrator'

  0.0,

  // Mask Parameter: PIYawController_InitialConditio
  //  Referenced by: '<S301>/Integrator'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.016666666666666666,

  // Expression: 0
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S93>/Integrator'

  0.016666666666666666,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S145>/Integrator'

  0.016666666666666666,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S197>/Integrator'

  0.016666666666666666,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S249>/Integrator'

  0.016666666666666666,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S301>/Integrator'

  0.016666666666666666
};

// System initialize for referenced model: 'Auto_Pilot'
void Auto_Pilot::init(void)
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  Auto_Pilot_DW.DiscreteTimeIntegrator_DSTATE =
    Auto_Pilot_rtP.DiscreteTimeIntegrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S93>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE =
    Auto_Pilot_rtP.PIGSxController_InitialConditio;

  // InitializeConditions for DiscreteIntegrator: '<S145>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_m =
    Auto_Pilot_rtP.PIGSyController_InitialConditio;

  // InitializeConditions for DiscreteIntegrator: '<S197>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_i =
    Auto_Pilot_rtP.PIPitchController_InitialCondit;

  // InitializeConditions for DiscreteIntegrator: '<S249>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_o =
    Auto_Pilot_rtP.PIRollController_InitialConditi;

  // InitializeConditions for DiscreteIntegrator: '<S301>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_c =
    Auto_Pilot_rtP.PIYawController_InitialConditio;
}

// Output and update for referenced model: 'Auto_Pilot'
void Auto_Pilot::step(const boolean_T *rtu_Cntrl_flags_AP_enabled, const real_T *
                      rtu_Pilot_Controls_delta_long, const real_T
                      *rtu_Pilot_Controls_delta_lat, const real_T
                      *rtu_Pilot_Controls_delta_coll, const real_T
                      *rtu_Pilot_Controls_delta_ped, const real_T
                      *rtu_AP_input_GS_x, const real_T *rtu_AP_input_GS_y, const
                      real_T *rtu_AP_input_VS, const real_T *rtu_AP_input_psi,
                      const real_T *rtu_Wind_measurements_Wind_x_B, const real_T
                      *rtu_Wind_measurements_Wind_y_B, const real_T
                      *rtu_Wind_measurements_Wind_z_B, const real_T *rtu_y_u,
                      const real_T *rtu_y_w, const real_T *rtu_y_theta, const
                      real_T *rtu_y_v, const real_T *rtu_y_phi, const real_T
                      *rtu_y_r, real_T *rty_u_delta_long, real_T
                      *rty_u_delta_lat, real_T *rty_u_delta_coll, real_T
                      *rty_u_delta_ped)
{
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_p;
  real_T rtb_ProportionalGain_a;
  real_T rtb_ProportionalGain_d;
  real_T rtb_ProportionalGain_hy;
  real_T rtb_ProportionalGain_i;
  real_T rtb_Sum11;

  // Sum: '<Root>/Sum' incorporates:
  //   Sum: '<Root>/Add'

  rtb_Sum11 = *rtu_AP_input_GS_x - (*rtu_y_u + *rtu_Wind_measurements_Wind_x_B);

  // Gain: '<S90>/Integral Gain'
  rtb_IntegralGain = rtP_AP_GSx_I * rtb_Sum11;

  // Gain: '<S98>/Proportional Gain'
  rtb_ProportionalGain_d = rtP_AP_GSx_P * rtb_Sum11;

  // Sum: '<Root>/Sum2' incorporates:
  //   Sum: '<Root>/Add1'

  rtb_Sum11 = *rtu_AP_input_GS_y - (*rtu_y_v + *rtu_Wind_measurements_Wind_y_B);

  // Gain: '<S142>/Integral Gain'
  rtb_IntegralGain_p = rtP_AP_GSy_I * rtb_Sum11;

  // Gain: '<S150>/Proportional Gain'
  rtb_ProportionalGain_hy = rtP_AP_GSy_P * rtb_Sum11;

  // Sum: '<Root>/Sum4' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'
  //   Sum: '<S102>/Sum'

  rtb_Sum11 = (rtb_ProportionalGain_d + Auto_Pilot_DW.Integrator_DSTATE) -
    *rtu_y_theta;

  // Gain: '<S194>/Integral Gain'
  rtb_ProportionalGain_d = rtP_AP_Pitch_I * rtb_Sum11;

  // Gain: '<S202>/Proportional Gain'
  rtb_ProportionalGain_a = rtP_AP_Pitch_P * rtb_Sum11;

  // Sum: '<Root>/Sum9' incorporates:
  //   DiscreteIntegrator: '<S145>/Integrator'
  //   Sum: '<S154>/Sum'

  rtb_Sum11 = (rtb_ProportionalGain_hy + Auto_Pilot_DW.Integrator_DSTATE_m) -
    *rtu_y_phi;

  // Gain: '<S246>/Integral Gain'
  rtb_ProportionalGain_hy = rtP_AP_Roll_I * rtb_Sum11;

  // Gain: '<S254>/Proportional Gain'
  rtb_ProportionalGain_i = rtP_AP_Roll_P * rtb_Sum11;

  // Sum: '<Root>/Sum11' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  rtb_Sum11 = *rtu_AP_input_psi - Auto_Pilot_DW.DiscreteTimeIntegrator_DSTATE;

  // Switch generated from: '<Root>/Switch' incorporates:
  //   DiscreteIntegrator: '<S197>/Integrator'
  //   DiscreteIntegrator: '<S249>/Integrator'
  //   DiscreteIntegrator: '<S301>/Integrator'
  //   Gain: '<S306>/Proportional Gain'
  //   Gain: '<S46>/Proportional Gain'
  //   Logic: '<Root>/NOT'
  //   Sum: '<Root>/Add2'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<S206>/Sum'
  //   Sum: '<S258>/Sum'
  //   Sum: '<S310>/Sum'

  if (!*rtu_Cntrl_flags_AP_enabled) {
    *rty_u_delta_long = *rtu_Pilot_Controls_delta_long;
    *rty_u_delta_lat = *rtu_Pilot_Controls_delta_lat;
    *rty_u_delta_coll = *rtu_Pilot_Controls_delta_coll;
    *rty_u_delta_ped = *rtu_Pilot_Controls_delta_ped;
  } else {
    *rty_u_delta_long = rtb_ProportionalGain_a +
      Auto_Pilot_DW.Integrator_DSTATE_i;
    *rty_u_delta_lat = rtb_ProportionalGain_i +
      Auto_Pilot_DW.Integrator_DSTATE_o;
    *rty_u_delta_coll = (*rtu_AP_input_VS - (*rtu_y_w +
      *rtu_Wind_measurements_Wind_z_B)) * rtP_AP_Heave_P;
    *rty_u_delta_ped = rtP_AP_Yaw_P * rtb_Sum11 +
      Auto_Pilot_DW.Integrator_DSTATE_c;
  }

  // End of Switch generated from: '<Root>/Switch'

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  Auto_Pilot_DW.DiscreteTimeIntegrator_DSTATE +=
    Auto_Pilot_rtP.DiscreteTimeIntegrator_gainval * *rtu_y_r;

  // Update for DiscreteIntegrator: '<S93>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE += Auto_Pilot_rtP.Integrator_gainval *
    rtb_IntegralGain;

  // Update for DiscreteIntegrator: '<S145>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_m += Auto_Pilot_rtP.Integrator_gainval_e *
    rtb_IntegralGain_p;

  // Update for DiscreteIntegrator: '<S197>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_i += Auto_Pilot_rtP.Integrator_gainval_b *
    rtb_ProportionalGain_d;

  // Update for DiscreteIntegrator: '<S249>/Integrator'
  Auto_Pilot_DW.Integrator_DSTATE_o += Auto_Pilot_rtP.Integrator_gainval_h *
    rtb_ProportionalGain_hy;

  // Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
  //   Gain: '<S298>/Integral Gain'

  Auto_Pilot_DW.Integrator_DSTATE_c += rtP_AP_Yaw_I * rtb_Sum11 *
    Auto_Pilot_rtP.Integrator_gainval_p;
}

const char_T* Auto_Pilot::RT_MODEL_Auto_Pilot_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void Auto_Pilot::RT_MODEL_Auto_Pilot_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Auto_Pilot::RT_MODEL_Auto_Pilot_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void Auto_Pilot::RT_MODEL_Auto_Pilot_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Auto_Pilot::Auto_Pilot() :
  Auto_Pilot_DW(),
  Auto_Pilot_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Auto_Pilot::~Auto_Pilot() = default;

// Real-Time Model get method
Auto_Pilot::RT_MODEL_Auto_Pilot_T * Auto_Pilot::getRTM()
{
  return (&Auto_Pilot_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
