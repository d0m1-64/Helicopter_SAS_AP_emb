//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Auto_Pilot.h
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
#ifndef Auto_Pilot_h_
#define Auto_Pilot_h_
#include <cmath>
#include "rtwtypes.h"
#include "Auto_Pilot_types.h"
#include <cstring>

// Model block global parameters (default storage)
extern real_T rtP_AP_GSx_I;            // Variable: AP_GSx_I
                                          //  Referenced by: '<S90>/Integral Gain'

extern real_T rtP_AP_GSx_P;            // Variable: AP_GSx_P
                                          //  Referenced by: '<S98>/Proportional Gain'

extern real_T rtP_AP_GSy_I;            // Variable: AP_GSy_I
                                          //  Referenced by: '<S142>/Integral Gain'

extern real_T rtP_AP_GSy_P;            // Variable: AP_GSy_P
                                          //  Referenced by: '<S150>/Proportional Gain'

extern real_T rtP_AP_Heave_P;          // Variable: AP_Heave_P
                                          //  Referenced by: '<S46>/Proportional Gain'

extern real_T rtP_AP_Pitch_I;          // Variable: AP_Pitch_I
                                          //  Referenced by: '<S194>/Integral Gain'

extern real_T rtP_AP_Pitch_P;          // Variable: AP_Pitch_P
                                          //  Referenced by: '<S202>/Proportional Gain'

extern real_T rtP_AP_Roll_I;           // Variable: AP_Roll_I
                                          //  Referenced by: '<S246>/Integral Gain'

extern real_T rtP_AP_Roll_P;           // Variable: AP_Roll_P
                                          //  Referenced by: '<S254>/Proportional Gain'

extern real_T rtP_AP_Yaw_I;            // Variable: AP_Yaw_I
                                          //  Referenced by: '<S298>/Integral Gain'

extern real_T rtP_AP_Yaw_P;            // Variable: AP_Yaw_P
                                          //  Referenced by: '<S306>/Proportional Gain'


// Class declaration for model Auto_Pilot
class Auto_Pilot final
{
  // public data and function members
 public:
  // Block states (default storage) for model 'Auto_Pilot'
  struct DW_Auto_Pilot_T {
    real_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
    real_T Integrator_DSTATE;          // '<S93>/Integrator'
    real_T Integrator_DSTATE_m;        // '<S145>/Integrator'
    real_T Integrator_DSTATE_i;        // '<S197>/Integrator'
    real_T Integrator_DSTATE_o;        // '<S249>/Integrator'
    real_T Integrator_DSTATE_c;        // '<S301>/Integrator'
  };

  // Parameters (default storage)
  struct P_Auto_Pilot_T {
    real_T PIGSxController_InitialConditio;
                              // Mask Parameter: PIGSxController_InitialConditio
                                 //  Referenced by: '<S93>/Integrator'

    real_T PIGSyController_InitialConditio;
                              // Mask Parameter: PIGSyController_InitialConditio
                                 //  Referenced by: '<S145>/Integrator'

    real_T PIPitchController_InitialCondit;
                              // Mask Parameter: PIPitchController_InitialCondit
                                 //  Referenced by: '<S197>/Integrator'

    real_T PIRollController_InitialConditi;
                              // Mask Parameter: PIRollController_InitialConditi
                                 //  Referenced by: '<S249>/Integrator'

    real_T PIYawController_InitialConditio;
                              // Mask Parameter: PIYawController_InitialConditio
                                 //  Referenced by: '<S301>/Integrator'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<Root>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC;  // Expression: 0
                                          //  Referenced by: '<Root>/Discrete-Time Integrator'

    real_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S93>/Integrator'

    real_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S145>/Integrator'

    real_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S197>/Integrator'

    real_T Integrator_gainval_h;     // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S249>/Integrator'

    real_T Integrator_gainval_p;     // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S301>/Integrator'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_Auto_Pilot_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Initial conditions function
  void init();

  // Copy Constructor
  Auto_Pilot(Auto_Pilot const&) = delete;

  // Assignment Operator
  Auto_Pilot& operator= (Auto_Pilot const&) & = delete;

  // Move Constructor
  Auto_Pilot(Auto_Pilot &&) = delete;

  // Move Assignment Operator
  Auto_Pilot& operator= (Auto_Pilot &&) = delete;

  // Real-Time Model get method
  Auto_Pilot::RT_MODEL_Auto_Pilot_T * getRTM();

  // model step function
  void step(const boolean_T *rtu_Cntrl_flags_AP_enabled, const real_T
            *rtu_Pilot_Controls_delta_long, const real_T
            *rtu_Pilot_Controls_delta_lat, const real_T
            *rtu_Pilot_Controls_delta_coll, const real_T
            *rtu_Pilot_Controls_delta_ped, const real_T *rtu_AP_input_GS_x,
            const real_T *rtu_AP_input_GS_y, const real_T *rtu_AP_input_VS,
            const real_T *rtu_AP_input_psi, const real_T
            *rtu_Wind_measurements_Wind_x_B, const real_T
            *rtu_Wind_measurements_Wind_y_B, const real_T
            *rtu_Wind_measurements_Wind_z_B, const real_T *rtu_y_u, const real_T
            *rtu_y_w, const real_T *rtu_y_theta, const real_T *rtu_y_v, const
            real_T *rtu_y_phi, const real_T *rtu_y_r, real_T *rty_u_delta_long,
            real_T *rty_u_delta_lat, real_T *rty_u_delta_coll, real_T
            *rty_u_delta_ped);

  // Constructor
  Auto_Pilot();

  // Destructor
  ~Auto_Pilot();

  // private data and function members
 private:
  // Block states
  DW_Auto_Pilot_T Auto_Pilot_DW;

  // Tunable parameters
  static P_Auto_Pilot_T Auto_Pilot_rtP;

  // Real-Time Model
  RT_MODEL_Auto_Pilot_T Auto_Pilot_M;
};

extern Auto_Pilot::P_Auto_Pilot_T Auto_Pilot_rtP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Auto_Pilot'
//  '<S1>'   : 'Auto_Pilot/P Heave Controller'
//  '<S2>'   : 'Auto_Pilot/PI GSx Controller'
//  '<S3>'   : 'Auto_Pilot/PI GSy Controller'
//  '<S4>'   : 'Auto_Pilot/PI Pitch Controller'
//  '<S5>'   : 'Auto_Pilot/PI Roll Controller'
//  '<S6>'   : 'Auto_Pilot/PI Yaw Controller'
//  '<S7>'   : 'Auto_Pilot/P Heave Controller/Anti-windup'
//  '<S8>'   : 'Auto_Pilot/P Heave Controller/D Gain'
//  '<S9>'   : 'Auto_Pilot/P Heave Controller/External Derivative'
//  '<S10>'  : 'Auto_Pilot/P Heave Controller/Filter'
//  '<S11>'  : 'Auto_Pilot/P Heave Controller/Filter ICs'
//  '<S12>'  : 'Auto_Pilot/P Heave Controller/I Gain'
//  '<S13>'  : 'Auto_Pilot/P Heave Controller/Ideal P Gain'
//  '<S14>'  : 'Auto_Pilot/P Heave Controller/Ideal P Gain Fdbk'
//  '<S15>'  : 'Auto_Pilot/P Heave Controller/Integrator'
//  '<S16>'  : 'Auto_Pilot/P Heave Controller/Integrator ICs'
//  '<S17>'  : 'Auto_Pilot/P Heave Controller/N Copy'
//  '<S18>'  : 'Auto_Pilot/P Heave Controller/N Gain'
//  '<S19>'  : 'Auto_Pilot/P Heave Controller/P Copy'
//  '<S20>'  : 'Auto_Pilot/P Heave Controller/Parallel P Gain'
//  '<S21>'  : 'Auto_Pilot/P Heave Controller/Reset Signal'
//  '<S22>'  : 'Auto_Pilot/P Heave Controller/Saturation'
//  '<S23>'  : 'Auto_Pilot/P Heave Controller/Saturation Fdbk'
//  '<S24>'  : 'Auto_Pilot/P Heave Controller/Sum'
//  '<S25>'  : 'Auto_Pilot/P Heave Controller/Sum Fdbk'
//  '<S26>'  : 'Auto_Pilot/P Heave Controller/Tracking Mode'
//  '<S27>'  : 'Auto_Pilot/P Heave Controller/Tracking Mode Sum'
//  '<S28>'  : 'Auto_Pilot/P Heave Controller/Tsamp - Integral'
//  '<S29>'  : 'Auto_Pilot/P Heave Controller/Tsamp - Ngain'
//  '<S30>'  : 'Auto_Pilot/P Heave Controller/postSat Signal'
//  '<S31>'  : 'Auto_Pilot/P Heave Controller/preInt Signal'
//  '<S32>'  : 'Auto_Pilot/P Heave Controller/preSat Signal'
//  '<S33>'  : 'Auto_Pilot/P Heave Controller/Anti-windup/Disabled'
//  '<S34>'  : 'Auto_Pilot/P Heave Controller/D Gain/Disabled'
//  '<S35>'  : 'Auto_Pilot/P Heave Controller/External Derivative/Disabled'
//  '<S36>'  : 'Auto_Pilot/P Heave Controller/Filter/Disabled'
//  '<S37>'  : 'Auto_Pilot/P Heave Controller/Filter ICs/Disabled'
//  '<S38>'  : 'Auto_Pilot/P Heave Controller/I Gain/Disabled'
//  '<S39>'  : 'Auto_Pilot/P Heave Controller/Ideal P Gain/Passthrough'
//  '<S40>'  : 'Auto_Pilot/P Heave Controller/Ideal P Gain Fdbk/Disabled'
//  '<S41>'  : 'Auto_Pilot/P Heave Controller/Integrator/Disabled'
//  '<S42>'  : 'Auto_Pilot/P Heave Controller/Integrator ICs/Disabled'
//  '<S43>'  : 'Auto_Pilot/P Heave Controller/N Copy/Disabled wSignal Specification'
//  '<S44>'  : 'Auto_Pilot/P Heave Controller/N Gain/Disabled'
//  '<S45>'  : 'Auto_Pilot/P Heave Controller/P Copy/Disabled'
//  '<S46>'  : 'Auto_Pilot/P Heave Controller/Parallel P Gain/Internal Parameters'
//  '<S47>'  : 'Auto_Pilot/P Heave Controller/Reset Signal/Disabled'
//  '<S48>'  : 'Auto_Pilot/P Heave Controller/Saturation/Passthrough'
//  '<S49>'  : 'Auto_Pilot/P Heave Controller/Saturation Fdbk/Disabled'
//  '<S50>'  : 'Auto_Pilot/P Heave Controller/Sum/Passthrough_P'
//  '<S51>'  : 'Auto_Pilot/P Heave Controller/Sum Fdbk/Disabled'
//  '<S52>'  : 'Auto_Pilot/P Heave Controller/Tracking Mode/Disabled'
//  '<S53>'  : 'Auto_Pilot/P Heave Controller/Tracking Mode Sum/Passthrough'
//  '<S54>'  : 'Auto_Pilot/P Heave Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S55>'  : 'Auto_Pilot/P Heave Controller/Tsamp - Ngain/Passthrough'
//  '<S56>'  : 'Auto_Pilot/P Heave Controller/postSat Signal/Forward_Path'
//  '<S57>'  : 'Auto_Pilot/P Heave Controller/preInt Signal/Internal PreInt'
//  '<S58>'  : 'Auto_Pilot/P Heave Controller/preSat Signal/Forward_Path'
//  '<S59>'  : 'Auto_Pilot/PI GSx Controller/Anti-windup'
//  '<S60>'  : 'Auto_Pilot/PI GSx Controller/D Gain'
//  '<S61>'  : 'Auto_Pilot/PI GSx Controller/External Derivative'
//  '<S62>'  : 'Auto_Pilot/PI GSx Controller/Filter'
//  '<S63>'  : 'Auto_Pilot/PI GSx Controller/Filter ICs'
//  '<S64>'  : 'Auto_Pilot/PI GSx Controller/I Gain'
//  '<S65>'  : 'Auto_Pilot/PI GSx Controller/Ideal P Gain'
//  '<S66>'  : 'Auto_Pilot/PI GSx Controller/Ideal P Gain Fdbk'
//  '<S67>'  : 'Auto_Pilot/PI GSx Controller/Integrator'
//  '<S68>'  : 'Auto_Pilot/PI GSx Controller/Integrator ICs'
//  '<S69>'  : 'Auto_Pilot/PI GSx Controller/N Copy'
//  '<S70>'  : 'Auto_Pilot/PI GSx Controller/N Gain'
//  '<S71>'  : 'Auto_Pilot/PI GSx Controller/P Copy'
//  '<S72>'  : 'Auto_Pilot/PI GSx Controller/Parallel P Gain'
//  '<S73>'  : 'Auto_Pilot/PI GSx Controller/Reset Signal'
//  '<S74>'  : 'Auto_Pilot/PI GSx Controller/Saturation'
//  '<S75>'  : 'Auto_Pilot/PI GSx Controller/Saturation Fdbk'
//  '<S76>'  : 'Auto_Pilot/PI GSx Controller/Sum'
//  '<S77>'  : 'Auto_Pilot/PI GSx Controller/Sum Fdbk'
//  '<S78>'  : 'Auto_Pilot/PI GSx Controller/Tracking Mode'
//  '<S79>'  : 'Auto_Pilot/PI GSx Controller/Tracking Mode Sum'
//  '<S80>'  : 'Auto_Pilot/PI GSx Controller/Tsamp - Integral'
//  '<S81>'  : 'Auto_Pilot/PI GSx Controller/Tsamp - Ngain'
//  '<S82>'  : 'Auto_Pilot/PI GSx Controller/postSat Signal'
//  '<S83>'  : 'Auto_Pilot/PI GSx Controller/preInt Signal'
//  '<S84>'  : 'Auto_Pilot/PI GSx Controller/preSat Signal'
//  '<S85>'  : 'Auto_Pilot/PI GSx Controller/Anti-windup/Passthrough'
//  '<S86>'  : 'Auto_Pilot/PI GSx Controller/D Gain/Disabled'
//  '<S87>'  : 'Auto_Pilot/PI GSx Controller/External Derivative/Disabled'
//  '<S88>'  : 'Auto_Pilot/PI GSx Controller/Filter/Disabled'
//  '<S89>'  : 'Auto_Pilot/PI GSx Controller/Filter ICs/Disabled'
//  '<S90>'  : 'Auto_Pilot/PI GSx Controller/I Gain/Internal Parameters'
//  '<S91>'  : 'Auto_Pilot/PI GSx Controller/Ideal P Gain/Passthrough'
//  '<S92>'  : 'Auto_Pilot/PI GSx Controller/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'Auto_Pilot/PI GSx Controller/Integrator/Discrete'
//  '<S94>'  : 'Auto_Pilot/PI GSx Controller/Integrator ICs/Internal IC'
//  '<S95>'  : 'Auto_Pilot/PI GSx Controller/N Copy/Disabled wSignal Specification'
//  '<S96>'  : 'Auto_Pilot/PI GSx Controller/N Gain/Disabled'
//  '<S97>'  : 'Auto_Pilot/PI GSx Controller/P Copy/Disabled'
//  '<S98>'  : 'Auto_Pilot/PI GSx Controller/Parallel P Gain/Internal Parameters'
//  '<S99>'  : 'Auto_Pilot/PI GSx Controller/Reset Signal/Disabled'
//  '<S100>' : 'Auto_Pilot/PI GSx Controller/Saturation/Passthrough'
//  '<S101>' : 'Auto_Pilot/PI GSx Controller/Saturation Fdbk/Disabled'
//  '<S102>' : 'Auto_Pilot/PI GSx Controller/Sum/Sum_PI'
//  '<S103>' : 'Auto_Pilot/PI GSx Controller/Sum Fdbk/Disabled'
//  '<S104>' : 'Auto_Pilot/PI GSx Controller/Tracking Mode/Disabled'
//  '<S105>' : 'Auto_Pilot/PI GSx Controller/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'Auto_Pilot/PI GSx Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'Auto_Pilot/PI GSx Controller/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'Auto_Pilot/PI GSx Controller/postSat Signal/Forward_Path'
//  '<S109>' : 'Auto_Pilot/PI GSx Controller/preInt Signal/Internal PreInt'
//  '<S110>' : 'Auto_Pilot/PI GSx Controller/preSat Signal/Forward_Path'
//  '<S111>' : 'Auto_Pilot/PI GSy Controller/Anti-windup'
//  '<S112>' : 'Auto_Pilot/PI GSy Controller/D Gain'
//  '<S113>' : 'Auto_Pilot/PI GSy Controller/External Derivative'
//  '<S114>' : 'Auto_Pilot/PI GSy Controller/Filter'
//  '<S115>' : 'Auto_Pilot/PI GSy Controller/Filter ICs'
//  '<S116>' : 'Auto_Pilot/PI GSy Controller/I Gain'
//  '<S117>' : 'Auto_Pilot/PI GSy Controller/Ideal P Gain'
//  '<S118>' : 'Auto_Pilot/PI GSy Controller/Ideal P Gain Fdbk'
//  '<S119>' : 'Auto_Pilot/PI GSy Controller/Integrator'
//  '<S120>' : 'Auto_Pilot/PI GSy Controller/Integrator ICs'
//  '<S121>' : 'Auto_Pilot/PI GSy Controller/N Copy'
//  '<S122>' : 'Auto_Pilot/PI GSy Controller/N Gain'
//  '<S123>' : 'Auto_Pilot/PI GSy Controller/P Copy'
//  '<S124>' : 'Auto_Pilot/PI GSy Controller/Parallel P Gain'
//  '<S125>' : 'Auto_Pilot/PI GSy Controller/Reset Signal'
//  '<S126>' : 'Auto_Pilot/PI GSy Controller/Saturation'
//  '<S127>' : 'Auto_Pilot/PI GSy Controller/Saturation Fdbk'
//  '<S128>' : 'Auto_Pilot/PI GSy Controller/Sum'
//  '<S129>' : 'Auto_Pilot/PI GSy Controller/Sum Fdbk'
//  '<S130>' : 'Auto_Pilot/PI GSy Controller/Tracking Mode'
//  '<S131>' : 'Auto_Pilot/PI GSy Controller/Tracking Mode Sum'
//  '<S132>' : 'Auto_Pilot/PI GSy Controller/Tsamp - Integral'
//  '<S133>' : 'Auto_Pilot/PI GSy Controller/Tsamp - Ngain'
//  '<S134>' : 'Auto_Pilot/PI GSy Controller/postSat Signal'
//  '<S135>' : 'Auto_Pilot/PI GSy Controller/preInt Signal'
//  '<S136>' : 'Auto_Pilot/PI GSy Controller/preSat Signal'
//  '<S137>' : 'Auto_Pilot/PI GSy Controller/Anti-windup/Passthrough'
//  '<S138>' : 'Auto_Pilot/PI GSy Controller/D Gain/Disabled'
//  '<S139>' : 'Auto_Pilot/PI GSy Controller/External Derivative/Disabled'
//  '<S140>' : 'Auto_Pilot/PI GSy Controller/Filter/Disabled'
//  '<S141>' : 'Auto_Pilot/PI GSy Controller/Filter ICs/Disabled'
//  '<S142>' : 'Auto_Pilot/PI GSy Controller/I Gain/Internal Parameters'
//  '<S143>' : 'Auto_Pilot/PI GSy Controller/Ideal P Gain/Passthrough'
//  '<S144>' : 'Auto_Pilot/PI GSy Controller/Ideal P Gain Fdbk/Disabled'
//  '<S145>' : 'Auto_Pilot/PI GSy Controller/Integrator/Discrete'
//  '<S146>' : 'Auto_Pilot/PI GSy Controller/Integrator ICs/Internal IC'
//  '<S147>' : 'Auto_Pilot/PI GSy Controller/N Copy/Disabled wSignal Specification'
//  '<S148>' : 'Auto_Pilot/PI GSy Controller/N Gain/Disabled'
//  '<S149>' : 'Auto_Pilot/PI GSy Controller/P Copy/Disabled'
//  '<S150>' : 'Auto_Pilot/PI GSy Controller/Parallel P Gain/Internal Parameters'
//  '<S151>' : 'Auto_Pilot/PI GSy Controller/Reset Signal/Disabled'
//  '<S152>' : 'Auto_Pilot/PI GSy Controller/Saturation/Passthrough'
//  '<S153>' : 'Auto_Pilot/PI GSy Controller/Saturation Fdbk/Disabled'
//  '<S154>' : 'Auto_Pilot/PI GSy Controller/Sum/Sum_PI'
//  '<S155>' : 'Auto_Pilot/PI GSy Controller/Sum Fdbk/Disabled'
//  '<S156>' : 'Auto_Pilot/PI GSy Controller/Tracking Mode/Disabled'
//  '<S157>' : 'Auto_Pilot/PI GSy Controller/Tracking Mode Sum/Passthrough'
//  '<S158>' : 'Auto_Pilot/PI GSy Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S159>' : 'Auto_Pilot/PI GSy Controller/Tsamp - Ngain/Passthrough'
//  '<S160>' : 'Auto_Pilot/PI GSy Controller/postSat Signal/Forward_Path'
//  '<S161>' : 'Auto_Pilot/PI GSy Controller/preInt Signal/Internal PreInt'
//  '<S162>' : 'Auto_Pilot/PI GSy Controller/preSat Signal/Forward_Path'
//  '<S163>' : 'Auto_Pilot/PI Pitch Controller/Anti-windup'
//  '<S164>' : 'Auto_Pilot/PI Pitch Controller/D Gain'
//  '<S165>' : 'Auto_Pilot/PI Pitch Controller/External Derivative'
//  '<S166>' : 'Auto_Pilot/PI Pitch Controller/Filter'
//  '<S167>' : 'Auto_Pilot/PI Pitch Controller/Filter ICs'
//  '<S168>' : 'Auto_Pilot/PI Pitch Controller/I Gain'
//  '<S169>' : 'Auto_Pilot/PI Pitch Controller/Ideal P Gain'
//  '<S170>' : 'Auto_Pilot/PI Pitch Controller/Ideal P Gain Fdbk'
//  '<S171>' : 'Auto_Pilot/PI Pitch Controller/Integrator'
//  '<S172>' : 'Auto_Pilot/PI Pitch Controller/Integrator ICs'
//  '<S173>' : 'Auto_Pilot/PI Pitch Controller/N Copy'
//  '<S174>' : 'Auto_Pilot/PI Pitch Controller/N Gain'
//  '<S175>' : 'Auto_Pilot/PI Pitch Controller/P Copy'
//  '<S176>' : 'Auto_Pilot/PI Pitch Controller/Parallel P Gain'
//  '<S177>' : 'Auto_Pilot/PI Pitch Controller/Reset Signal'
//  '<S178>' : 'Auto_Pilot/PI Pitch Controller/Saturation'
//  '<S179>' : 'Auto_Pilot/PI Pitch Controller/Saturation Fdbk'
//  '<S180>' : 'Auto_Pilot/PI Pitch Controller/Sum'
//  '<S181>' : 'Auto_Pilot/PI Pitch Controller/Sum Fdbk'
//  '<S182>' : 'Auto_Pilot/PI Pitch Controller/Tracking Mode'
//  '<S183>' : 'Auto_Pilot/PI Pitch Controller/Tracking Mode Sum'
//  '<S184>' : 'Auto_Pilot/PI Pitch Controller/Tsamp - Integral'
//  '<S185>' : 'Auto_Pilot/PI Pitch Controller/Tsamp - Ngain'
//  '<S186>' : 'Auto_Pilot/PI Pitch Controller/postSat Signal'
//  '<S187>' : 'Auto_Pilot/PI Pitch Controller/preInt Signal'
//  '<S188>' : 'Auto_Pilot/PI Pitch Controller/preSat Signal'
//  '<S189>' : 'Auto_Pilot/PI Pitch Controller/Anti-windup/Passthrough'
//  '<S190>' : 'Auto_Pilot/PI Pitch Controller/D Gain/Disabled'
//  '<S191>' : 'Auto_Pilot/PI Pitch Controller/External Derivative/Disabled'
//  '<S192>' : 'Auto_Pilot/PI Pitch Controller/Filter/Disabled'
//  '<S193>' : 'Auto_Pilot/PI Pitch Controller/Filter ICs/Disabled'
//  '<S194>' : 'Auto_Pilot/PI Pitch Controller/I Gain/Internal Parameters'
//  '<S195>' : 'Auto_Pilot/PI Pitch Controller/Ideal P Gain/Passthrough'
//  '<S196>' : 'Auto_Pilot/PI Pitch Controller/Ideal P Gain Fdbk/Disabled'
//  '<S197>' : 'Auto_Pilot/PI Pitch Controller/Integrator/Discrete'
//  '<S198>' : 'Auto_Pilot/PI Pitch Controller/Integrator ICs/Internal IC'
//  '<S199>' : 'Auto_Pilot/PI Pitch Controller/N Copy/Disabled wSignal Specification'
//  '<S200>' : 'Auto_Pilot/PI Pitch Controller/N Gain/Disabled'
//  '<S201>' : 'Auto_Pilot/PI Pitch Controller/P Copy/Disabled'
//  '<S202>' : 'Auto_Pilot/PI Pitch Controller/Parallel P Gain/Internal Parameters'
//  '<S203>' : 'Auto_Pilot/PI Pitch Controller/Reset Signal/Disabled'
//  '<S204>' : 'Auto_Pilot/PI Pitch Controller/Saturation/Passthrough'
//  '<S205>' : 'Auto_Pilot/PI Pitch Controller/Saturation Fdbk/Disabled'
//  '<S206>' : 'Auto_Pilot/PI Pitch Controller/Sum/Sum_PI'
//  '<S207>' : 'Auto_Pilot/PI Pitch Controller/Sum Fdbk/Disabled'
//  '<S208>' : 'Auto_Pilot/PI Pitch Controller/Tracking Mode/Disabled'
//  '<S209>' : 'Auto_Pilot/PI Pitch Controller/Tracking Mode Sum/Passthrough'
//  '<S210>' : 'Auto_Pilot/PI Pitch Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S211>' : 'Auto_Pilot/PI Pitch Controller/Tsamp - Ngain/Passthrough'
//  '<S212>' : 'Auto_Pilot/PI Pitch Controller/postSat Signal/Forward_Path'
//  '<S213>' : 'Auto_Pilot/PI Pitch Controller/preInt Signal/Internal PreInt'
//  '<S214>' : 'Auto_Pilot/PI Pitch Controller/preSat Signal/Forward_Path'
//  '<S215>' : 'Auto_Pilot/PI Roll Controller/Anti-windup'
//  '<S216>' : 'Auto_Pilot/PI Roll Controller/D Gain'
//  '<S217>' : 'Auto_Pilot/PI Roll Controller/External Derivative'
//  '<S218>' : 'Auto_Pilot/PI Roll Controller/Filter'
//  '<S219>' : 'Auto_Pilot/PI Roll Controller/Filter ICs'
//  '<S220>' : 'Auto_Pilot/PI Roll Controller/I Gain'
//  '<S221>' : 'Auto_Pilot/PI Roll Controller/Ideal P Gain'
//  '<S222>' : 'Auto_Pilot/PI Roll Controller/Ideal P Gain Fdbk'
//  '<S223>' : 'Auto_Pilot/PI Roll Controller/Integrator'
//  '<S224>' : 'Auto_Pilot/PI Roll Controller/Integrator ICs'
//  '<S225>' : 'Auto_Pilot/PI Roll Controller/N Copy'
//  '<S226>' : 'Auto_Pilot/PI Roll Controller/N Gain'
//  '<S227>' : 'Auto_Pilot/PI Roll Controller/P Copy'
//  '<S228>' : 'Auto_Pilot/PI Roll Controller/Parallel P Gain'
//  '<S229>' : 'Auto_Pilot/PI Roll Controller/Reset Signal'
//  '<S230>' : 'Auto_Pilot/PI Roll Controller/Saturation'
//  '<S231>' : 'Auto_Pilot/PI Roll Controller/Saturation Fdbk'
//  '<S232>' : 'Auto_Pilot/PI Roll Controller/Sum'
//  '<S233>' : 'Auto_Pilot/PI Roll Controller/Sum Fdbk'
//  '<S234>' : 'Auto_Pilot/PI Roll Controller/Tracking Mode'
//  '<S235>' : 'Auto_Pilot/PI Roll Controller/Tracking Mode Sum'
//  '<S236>' : 'Auto_Pilot/PI Roll Controller/Tsamp - Integral'
//  '<S237>' : 'Auto_Pilot/PI Roll Controller/Tsamp - Ngain'
//  '<S238>' : 'Auto_Pilot/PI Roll Controller/postSat Signal'
//  '<S239>' : 'Auto_Pilot/PI Roll Controller/preInt Signal'
//  '<S240>' : 'Auto_Pilot/PI Roll Controller/preSat Signal'
//  '<S241>' : 'Auto_Pilot/PI Roll Controller/Anti-windup/Passthrough'
//  '<S242>' : 'Auto_Pilot/PI Roll Controller/D Gain/Disabled'
//  '<S243>' : 'Auto_Pilot/PI Roll Controller/External Derivative/Disabled'
//  '<S244>' : 'Auto_Pilot/PI Roll Controller/Filter/Disabled'
//  '<S245>' : 'Auto_Pilot/PI Roll Controller/Filter ICs/Disabled'
//  '<S246>' : 'Auto_Pilot/PI Roll Controller/I Gain/Internal Parameters'
//  '<S247>' : 'Auto_Pilot/PI Roll Controller/Ideal P Gain/Passthrough'
//  '<S248>' : 'Auto_Pilot/PI Roll Controller/Ideal P Gain Fdbk/Disabled'
//  '<S249>' : 'Auto_Pilot/PI Roll Controller/Integrator/Discrete'
//  '<S250>' : 'Auto_Pilot/PI Roll Controller/Integrator ICs/Internal IC'
//  '<S251>' : 'Auto_Pilot/PI Roll Controller/N Copy/Disabled wSignal Specification'
//  '<S252>' : 'Auto_Pilot/PI Roll Controller/N Gain/Disabled'
//  '<S253>' : 'Auto_Pilot/PI Roll Controller/P Copy/Disabled'
//  '<S254>' : 'Auto_Pilot/PI Roll Controller/Parallel P Gain/Internal Parameters'
//  '<S255>' : 'Auto_Pilot/PI Roll Controller/Reset Signal/Disabled'
//  '<S256>' : 'Auto_Pilot/PI Roll Controller/Saturation/Passthrough'
//  '<S257>' : 'Auto_Pilot/PI Roll Controller/Saturation Fdbk/Disabled'
//  '<S258>' : 'Auto_Pilot/PI Roll Controller/Sum/Sum_PI'
//  '<S259>' : 'Auto_Pilot/PI Roll Controller/Sum Fdbk/Disabled'
//  '<S260>' : 'Auto_Pilot/PI Roll Controller/Tracking Mode/Disabled'
//  '<S261>' : 'Auto_Pilot/PI Roll Controller/Tracking Mode Sum/Passthrough'
//  '<S262>' : 'Auto_Pilot/PI Roll Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S263>' : 'Auto_Pilot/PI Roll Controller/Tsamp - Ngain/Passthrough'
//  '<S264>' : 'Auto_Pilot/PI Roll Controller/postSat Signal/Forward_Path'
//  '<S265>' : 'Auto_Pilot/PI Roll Controller/preInt Signal/Internal PreInt'
//  '<S266>' : 'Auto_Pilot/PI Roll Controller/preSat Signal/Forward_Path'
//  '<S267>' : 'Auto_Pilot/PI Yaw Controller/Anti-windup'
//  '<S268>' : 'Auto_Pilot/PI Yaw Controller/D Gain'
//  '<S269>' : 'Auto_Pilot/PI Yaw Controller/External Derivative'
//  '<S270>' : 'Auto_Pilot/PI Yaw Controller/Filter'
//  '<S271>' : 'Auto_Pilot/PI Yaw Controller/Filter ICs'
//  '<S272>' : 'Auto_Pilot/PI Yaw Controller/I Gain'
//  '<S273>' : 'Auto_Pilot/PI Yaw Controller/Ideal P Gain'
//  '<S274>' : 'Auto_Pilot/PI Yaw Controller/Ideal P Gain Fdbk'
//  '<S275>' : 'Auto_Pilot/PI Yaw Controller/Integrator'
//  '<S276>' : 'Auto_Pilot/PI Yaw Controller/Integrator ICs'
//  '<S277>' : 'Auto_Pilot/PI Yaw Controller/N Copy'
//  '<S278>' : 'Auto_Pilot/PI Yaw Controller/N Gain'
//  '<S279>' : 'Auto_Pilot/PI Yaw Controller/P Copy'
//  '<S280>' : 'Auto_Pilot/PI Yaw Controller/Parallel P Gain'
//  '<S281>' : 'Auto_Pilot/PI Yaw Controller/Reset Signal'
//  '<S282>' : 'Auto_Pilot/PI Yaw Controller/Saturation'
//  '<S283>' : 'Auto_Pilot/PI Yaw Controller/Saturation Fdbk'
//  '<S284>' : 'Auto_Pilot/PI Yaw Controller/Sum'
//  '<S285>' : 'Auto_Pilot/PI Yaw Controller/Sum Fdbk'
//  '<S286>' : 'Auto_Pilot/PI Yaw Controller/Tracking Mode'
//  '<S287>' : 'Auto_Pilot/PI Yaw Controller/Tracking Mode Sum'
//  '<S288>' : 'Auto_Pilot/PI Yaw Controller/Tsamp - Integral'
//  '<S289>' : 'Auto_Pilot/PI Yaw Controller/Tsamp - Ngain'
//  '<S290>' : 'Auto_Pilot/PI Yaw Controller/postSat Signal'
//  '<S291>' : 'Auto_Pilot/PI Yaw Controller/preInt Signal'
//  '<S292>' : 'Auto_Pilot/PI Yaw Controller/preSat Signal'
//  '<S293>' : 'Auto_Pilot/PI Yaw Controller/Anti-windup/Passthrough'
//  '<S294>' : 'Auto_Pilot/PI Yaw Controller/D Gain/Disabled'
//  '<S295>' : 'Auto_Pilot/PI Yaw Controller/External Derivative/Disabled'
//  '<S296>' : 'Auto_Pilot/PI Yaw Controller/Filter/Disabled'
//  '<S297>' : 'Auto_Pilot/PI Yaw Controller/Filter ICs/Disabled'
//  '<S298>' : 'Auto_Pilot/PI Yaw Controller/I Gain/Internal Parameters'
//  '<S299>' : 'Auto_Pilot/PI Yaw Controller/Ideal P Gain/Passthrough'
//  '<S300>' : 'Auto_Pilot/PI Yaw Controller/Ideal P Gain Fdbk/Disabled'
//  '<S301>' : 'Auto_Pilot/PI Yaw Controller/Integrator/Discrete'
//  '<S302>' : 'Auto_Pilot/PI Yaw Controller/Integrator ICs/Internal IC'
//  '<S303>' : 'Auto_Pilot/PI Yaw Controller/N Copy/Disabled wSignal Specification'
//  '<S304>' : 'Auto_Pilot/PI Yaw Controller/N Gain/Disabled'
//  '<S305>' : 'Auto_Pilot/PI Yaw Controller/P Copy/Disabled'
//  '<S306>' : 'Auto_Pilot/PI Yaw Controller/Parallel P Gain/Internal Parameters'
//  '<S307>' : 'Auto_Pilot/PI Yaw Controller/Reset Signal/Disabled'
//  '<S308>' : 'Auto_Pilot/PI Yaw Controller/Saturation/Passthrough'
//  '<S309>' : 'Auto_Pilot/PI Yaw Controller/Saturation Fdbk/Disabled'
//  '<S310>' : 'Auto_Pilot/PI Yaw Controller/Sum/Sum_PI'
//  '<S311>' : 'Auto_Pilot/PI Yaw Controller/Sum Fdbk/Disabled'
//  '<S312>' : 'Auto_Pilot/PI Yaw Controller/Tracking Mode/Disabled'
//  '<S313>' : 'Auto_Pilot/PI Yaw Controller/Tracking Mode Sum/Passthrough'
//  '<S314>' : 'Auto_Pilot/PI Yaw Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S315>' : 'Auto_Pilot/PI Yaw Controller/Tsamp - Ngain/Passthrough'
//  '<S316>' : 'Auto_Pilot/PI Yaw Controller/postSat Signal/Forward_Path'
//  '<S317>' : 'Auto_Pilot/PI Yaw Controller/preInt Signal/Internal PreInt'
//  '<S318>' : 'Auto_Pilot/PI Yaw Controller/preSat Signal/Forward_Path'

#endif                                 // Auto_Pilot_h_

//
// File trailer for generated code.
//
// [EOF]
//
