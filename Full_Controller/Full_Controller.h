//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Full_Controller.h
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
#ifndef Full_Controller_h_
#define Full_Controller_h_
#include <cmath>
#include "rtwtypes.h"
#include "Full_Controller_types.h"
#include <cstring>

// Class declaration for model Full_Controller
class Full_Controller final
{
  // public data and function members
 public:
  // Block states (default storage) for model 'Full_Controller'
  struct DW_Full_Controller_T {
    real_T LongLatFilter_states;       // '<S2>/Long Lat Filter'
    real_T LatLatFilter_states;        // '<S2>/Lat Lat Filter'
    real_T CollLatFilter_states;       // '<S2>/Coll Lat Filter'
    real_T PedLatFilter_states;        // '<S2>/Ped Lat Filter'
    real_T Integrator_DSTATE;          // '<S95>/Integrator'
    real_T Integrator_DSTATE_p;        // '<S199>/Integrator'
    real_T LongRolloffFilter_states;   // '<S2>/Long Rolloff Filter'
    real_T CollRolloffFilter_states;   // '<S2>/Coll Rolloff Filter'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S1>/Discrete-Time Integrator'
    real_T Integrator_DSTATE_e;        // '<S303>/Integrator'
    real_T PedRolloffFilter_states;    // '<S2>/Ped Rolloff Filter'
    real_T Integrator_DSTATE_f;        // '<S147>/Integrator'
    real_T Integrator_DSTATE_i;        // '<S251>/Integrator'
    real_T LatRolloffFilter_states;    // '<S2>/Lat Rolloff Filter'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Full_Controller_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Copy Constructor
  Full_Controller(Full_Controller const&) = delete;

  // Assignment Operator
  Full_Controller& operator= (Full_Controller const&) & = delete;

  // Move Constructor
  Full_Controller(Full_Controller &&) = delete;

  // Move Assignment Operator
  Full_Controller& operator= (Full_Controller &&) = delete;

  // Real-Time Model get method
  Full_Controller::RT_MODEL_Full_Controller_T * getRTM();

  // model step function
  void step(const real_T *rtu_Pilot_Controls_delta_long, const real_T
            *rtu_Pilot_Controls_delta_lat, const real_T
            *rtu_Pilot_Controls_delta_coll, const real_T
            *rtu_Pilot_Controls_delta_ped, const real_T *rtu_AP_ref_states_GS_x,
            const real_T *rtu_AP_ref_states_GS_y, const real_T
            *rtu_AP_ref_states_VS, const real_T *rtu_AP_ref_states_psi, const
            real_T *rtu_Wind_measurement_Wind_x_B, const real_T
            *rtu_Wind_measurement_Wind_y_B, const real_T
            *rtu_Wind_measurement_Wind_z_B, const boolean_T
            *rtu_Cntrl_flags_AP_enabled, const boolean_T
            *rtu_Cntrl_flags_SAS_enabled, const real_T
            *rtu_Helicopter_Response_u, const real_T *rtu_Helicopter_Response_w,
            const real_T *rtu_Helicopter_Response_q, const real_T
            *rtu_Helicopter_Response_theta, const real_T
            *rtu_Helicopter_Response_v, const real_T *rtu_Helicopter_Response_p,
            const real_T *rtu_Helicopter_Response_phi, const real_T
            *rtu_Helicopter_Response_r, real_T *rty_Helicopter_Model_Input_delt,
            real_T *rty_Helicopter_Model_Input_de_g, real_T
            *rty_Helicopter_Model_Input_de_c, real_T
            *rty_Helicopter_Model_Input_de_e);

  // Constructor
  Full_Controller();

  // Destructor
  ~Full_Controller();

  // private data and function members
 private:
  // Block states
  DW_Full_Controller_T Full_Controller_DW;

  // Real-Time Model
  RT_MODEL_Full_Controller_T Full_Controller_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S204>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S256>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S308>/Proportional Gain' : Eliminated nontunable gain of 1


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
//  '<Root>' : 'Full_Controller'
//  '<S1>'   : 'Full_Controller/Auto-Pilot'
//  '<S2>'   : 'Full_Controller/SAS'
//  '<S3>'   : 'Full_Controller/Auto-Pilot/P Heave Controller'
//  '<S4>'   : 'Full_Controller/Auto-Pilot/PI GSx Controller'
//  '<S5>'   : 'Full_Controller/Auto-Pilot/PI GSy Controller'
//  '<S6>'   : 'Full_Controller/Auto-Pilot/PI Pitch Controller'
//  '<S7>'   : 'Full_Controller/Auto-Pilot/PI Roll Controller'
//  '<S8>'   : 'Full_Controller/Auto-Pilot/PI Yaw Controller'
//  '<S9>'   : 'Full_Controller/Auto-Pilot/P Heave Controller/Anti-windup'
//  '<S10>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/D Gain'
//  '<S11>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/External Derivative'
//  '<S12>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Filter'
//  '<S13>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Filter ICs'
//  '<S14>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/I Gain'
//  '<S15>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Ideal P Gain'
//  '<S16>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Ideal P Gain Fdbk'
//  '<S17>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Integrator'
//  '<S18>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Integrator ICs'
//  '<S19>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/N Copy'
//  '<S20>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/N Gain'
//  '<S21>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/P Copy'
//  '<S22>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Parallel P Gain'
//  '<S23>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Reset Signal'
//  '<S24>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Saturation'
//  '<S25>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Saturation Fdbk'
//  '<S26>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Sum'
//  '<S27>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Sum Fdbk'
//  '<S28>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tracking Mode'
//  '<S29>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tracking Mode Sum'
//  '<S30>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tsamp - Integral'
//  '<S31>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tsamp - Ngain'
//  '<S32>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/postSat Signal'
//  '<S33>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/preInt Signal'
//  '<S34>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/preSat Signal'
//  '<S35>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Anti-windup/Disabled'
//  '<S36>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/D Gain/Disabled'
//  '<S37>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/External Derivative/Disabled'
//  '<S38>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Filter/Disabled'
//  '<S39>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Filter ICs/Disabled'
//  '<S40>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/I Gain/Disabled'
//  '<S41>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Ideal P Gain/Passthrough'
//  '<S42>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Integrator/Disabled'
//  '<S44>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Integrator ICs/Disabled'
//  '<S45>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/N Copy/Disabled wSignal Specification'
//  '<S46>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/N Gain/Disabled'
//  '<S47>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/P Copy/Disabled'
//  '<S48>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Parallel P Gain/Internal Parameters'
//  '<S49>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Reset Signal/Disabled'
//  '<S50>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Saturation/Passthrough'
//  '<S51>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Saturation Fdbk/Disabled'
//  '<S52>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Sum/Passthrough_P'
//  '<S53>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Sum Fdbk/Disabled'
//  '<S54>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tracking Mode/Disabled'
//  '<S55>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/postSat Signal/Forward_Path'
//  '<S59>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/preInt Signal/Internal PreInt'
//  '<S60>'  : 'Full_Controller/Auto-Pilot/P Heave Controller/preSat Signal/Forward_Path'
//  '<S61>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Anti-windup'
//  '<S62>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/D Gain'
//  '<S63>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/External Derivative'
//  '<S64>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Filter'
//  '<S65>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Filter ICs'
//  '<S66>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/I Gain'
//  '<S67>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Ideal P Gain'
//  '<S68>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Ideal P Gain Fdbk'
//  '<S69>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Integrator'
//  '<S70>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Integrator ICs'
//  '<S71>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/N Copy'
//  '<S72>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/N Gain'
//  '<S73>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/P Copy'
//  '<S74>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Parallel P Gain'
//  '<S75>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Reset Signal'
//  '<S76>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Saturation'
//  '<S77>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Saturation Fdbk'
//  '<S78>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Sum'
//  '<S79>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Sum Fdbk'
//  '<S80>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tracking Mode'
//  '<S81>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tracking Mode Sum'
//  '<S82>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tsamp - Integral'
//  '<S83>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tsamp - Ngain'
//  '<S84>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/postSat Signal'
//  '<S85>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/preInt Signal'
//  '<S86>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/preSat Signal'
//  '<S87>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Anti-windup/Passthrough'
//  '<S88>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/D Gain/Disabled'
//  '<S89>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/External Derivative/Disabled'
//  '<S90>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Filter/Disabled'
//  '<S91>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Filter ICs/Disabled'
//  '<S92>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/I Gain/Internal Parameters'
//  '<S93>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Ideal P Gain/Passthrough'
//  '<S94>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Ideal P Gain Fdbk/Disabled'
//  '<S95>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Integrator/Discrete'
//  '<S96>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/Integrator ICs/Internal IC'
//  '<S97>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/N Copy/Disabled wSignal Specification'
//  '<S98>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/N Gain/Disabled'
//  '<S99>'  : 'Full_Controller/Auto-Pilot/PI GSx Controller/P Copy/Disabled'
//  '<S100>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Parallel P Gain/Internal Parameters'
//  '<S101>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Reset Signal/Disabled'
//  '<S102>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Saturation/Passthrough'
//  '<S103>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Saturation Fdbk/Disabled'
//  '<S104>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Sum/Sum_PI'
//  '<S105>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Sum Fdbk/Disabled'
//  '<S106>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tracking Mode/Disabled'
//  '<S107>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tracking Mode Sum/Passthrough'
//  '<S108>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S109>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/Tsamp - Ngain/Passthrough'
//  '<S110>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/postSat Signal/Forward_Path'
//  '<S111>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/preInt Signal/Internal PreInt'
//  '<S112>' : 'Full_Controller/Auto-Pilot/PI GSx Controller/preSat Signal/Forward_Path'
//  '<S113>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Anti-windup'
//  '<S114>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/D Gain'
//  '<S115>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/External Derivative'
//  '<S116>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Filter'
//  '<S117>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Filter ICs'
//  '<S118>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/I Gain'
//  '<S119>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Ideal P Gain'
//  '<S120>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Ideal P Gain Fdbk'
//  '<S121>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Integrator'
//  '<S122>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Integrator ICs'
//  '<S123>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/N Copy'
//  '<S124>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/N Gain'
//  '<S125>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/P Copy'
//  '<S126>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Parallel P Gain'
//  '<S127>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Reset Signal'
//  '<S128>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Saturation'
//  '<S129>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Saturation Fdbk'
//  '<S130>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Sum'
//  '<S131>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Sum Fdbk'
//  '<S132>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tracking Mode'
//  '<S133>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tracking Mode Sum'
//  '<S134>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tsamp - Integral'
//  '<S135>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tsamp - Ngain'
//  '<S136>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/postSat Signal'
//  '<S137>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/preInt Signal'
//  '<S138>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/preSat Signal'
//  '<S139>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Anti-windup/Passthrough'
//  '<S140>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/D Gain/Disabled'
//  '<S141>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/External Derivative/Disabled'
//  '<S142>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Filter/Disabled'
//  '<S143>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Filter ICs/Disabled'
//  '<S144>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/I Gain/Internal Parameters'
//  '<S145>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Ideal P Gain/Passthrough'
//  '<S146>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Ideal P Gain Fdbk/Disabled'
//  '<S147>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Integrator/Discrete'
//  '<S148>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Integrator ICs/Internal IC'
//  '<S149>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/N Copy/Disabled wSignal Specification'
//  '<S150>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/N Gain/Disabled'
//  '<S151>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/P Copy/Disabled'
//  '<S152>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Parallel P Gain/Internal Parameters'
//  '<S153>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Reset Signal/Disabled'
//  '<S154>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Saturation/Passthrough'
//  '<S155>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Saturation Fdbk/Disabled'
//  '<S156>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Sum/Sum_PI'
//  '<S157>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Sum Fdbk/Disabled'
//  '<S158>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tracking Mode/Disabled'
//  '<S159>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tracking Mode Sum/Passthrough'
//  '<S160>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S161>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/Tsamp - Ngain/Passthrough'
//  '<S162>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/postSat Signal/Forward_Path'
//  '<S163>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/preInt Signal/Internal PreInt'
//  '<S164>' : 'Full_Controller/Auto-Pilot/PI GSy Controller/preSat Signal/Forward_Path'
//  '<S165>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Anti-windup'
//  '<S166>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/D Gain'
//  '<S167>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/External Derivative'
//  '<S168>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Filter'
//  '<S169>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Filter ICs'
//  '<S170>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/I Gain'
//  '<S171>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Ideal P Gain'
//  '<S172>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Ideal P Gain Fdbk'
//  '<S173>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Integrator'
//  '<S174>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Integrator ICs'
//  '<S175>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/N Copy'
//  '<S176>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/N Gain'
//  '<S177>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/P Copy'
//  '<S178>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Parallel P Gain'
//  '<S179>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Reset Signal'
//  '<S180>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Saturation'
//  '<S181>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Saturation Fdbk'
//  '<S182>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Sum'
//  '<S183>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Sum Fdbk'
//  '<S184>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tracking Mode'
//  '<S185>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tracking Mode Sum'
//  '<S186>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tsamp - Integral'
//  '<S187>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tsamp - Ngain'
//  '<S188>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/postSat Signal'
//  '<S189>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/preInt Signal'
//  '<S190>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/preSat Signal'
//  '<S191>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Anti-windup/Passthrough'
//  '<S192>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/D Gain/Disabled'
//  '<S193>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/External Derivative/Disabled'
//  '<S194>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Filter/Disabled'
//  '<S195>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Filter ICs/Disabled'
//  '<S196>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/I Gain/Internal Parameters'
//  '<S197>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Ideal P Gain/Passthrough'
//  '<S198>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Ideal P Gain Fdbk/Disabled'
//  '<S199>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Integrator/Discrete'
//  '<S200>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Integrator ICs/Internal IC'
//  '<S201>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/N Copy/Disabled wSignal Specification'
//  '<S202>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/N Gain/Disabled'
//  '<S203>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/P Copy/Disabled'
//  '<S204>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Parallel P Gain/Internal Parameters'
//  '<S205>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Reset Signal/Disabled'
//  '<S206>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Saturation/Passthrough'
//  '<S207>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Saturation Fdbk/Disabled'
//  '<S208>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Sum/Sum_PI'
//  '<S209>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Sum Fdbk/Disabled'
//  '<S210>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tracking Mode/Disabled'
//  '<S211>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tracking Mode Sum/Passthrough'
//  '<S212>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S213>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/Tsamp - Ngain/Passthrough'
//  '<S214>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/postSat Signal/Forward_Path'
//  '<S215>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/preInt Signal/Internal PreInt'
//  '<S216>' : 'Full_Controller/Auto-Pilot/PI Pitch Controller/preSat Signal/Forward_Path'
//  '<S217>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Anti-windup'
//  '<S218>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/D Gain'
//  '<S219>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/External Derivative'
//  '<S220>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Filter'
//  '<S221>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Filter ICs'
//  '<S222>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/I Gain'
//  '<S223>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Ideal P Gain'
//  '<S224>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Ideal P Gain Fdbk'
//  '<S225>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Integrator'
//  '<S226>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Integrator ICs'
//  '<S227>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/N Copy'
//  '<S228>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/N Gain'
//  '<S229>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/P Copy'
//  '<S230>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Parallel P Gain'
//  '<S231>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Reset Signal'
//  '<S232>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Saturation'
//  '<S233>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Saturation Fdbk'
//  '<S234>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Sum'
//  '<S235>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Sum Fdbk'
//  '<S236>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tracking Mode'
//  '<S237>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tracking Mode Sum'
//  '<S238>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tsamp - Integral'
//  '<S239>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tsamp - Ngain'
//  '<S240>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/postSat Signal'
//  '<S241>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/preInt Signal'
//  '<S242>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/preSat Signal'
//  '<S243>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Anti-windup/Passthrough'
//  '<S244>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/D Gain/Disabled'
//  '<S245>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/External Derivative/Disabled'
//  '<S246>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Filter/Disabled'
//  '<S247>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Filter ICs/Disabled'
//  '<S248>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/I Gain/Internal Parameters'
//  '<S249>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Ideal P Gain/Passthrough'
//  '<S250>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Ideal P Gain Fdbk/Disabled'
//  '<S251>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Integrator/Discrete'
//  '<S252>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Integrator ICs/Internal IC'
//  '<S253>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/N Copy/Disabled wSignal Specification'
//  '<S254>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/N Gain/Disabled'
//  '<S255>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/P Copy/Disabled'
//  '<S256>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Parallel P Gain/Internal Parameters'
//  '<S257>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Reset Signal/Disabled'
//  '<S258>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Saturation/Passthrough'
//  '<S259>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Saturation Fdbk/Disabled'
//  '<S260>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Sum/Sum_PI'
//  '<S261>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Sum Fdbk/Disabled'
//  '<S262>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tracking Mode/Disabled'
//  '<S263>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tracking Mode Sum/Passthrough'
//  '<S264>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S265>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/Tsamp - Ngain/Passthrough'
//  '<S266>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/postSat Signal/Forward_Path'
//  '<S267>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/preInt Signal/Internal PreInt'
//  '<S268>' : 'Full_Controller/Auto-Pilot/PI Roll Controller/preSat Signal/Forward_Path'
//  '<S269>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Anti-windup'
//  '<S270>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/D Gain'
//  '<S271>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/External Derivative'
//  '<S272>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Filter'
//  '<S273>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Filter ICs'
//  '<S274>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/I Gain'
//  '<S275>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Ideal P Gain'
//  '<S276>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Ideal P Gain Fdbk'
//  '<S277>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Integrator'
//  '<S278>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Integrator ICs'
//  '<S279>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/N Copy'
//  '<S280>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/N Gain'
//  '<S281>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/P Copy'
//  '<S282>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Parallel P Gain'
//  '<S283>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Reset Signal'
//  '<S284>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Saturation'
//  '<S285>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Saturation Fdbk'
//  '<S286>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Sum'
//  '<S287>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Sum Fdbk'
//  '<S288>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tracking Mode'
//  '<S289>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tracking Mode Sum'
//  '<S290>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tsamp - Integral'
//  '<S291>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tsamp - Ngain'
//  '<S292>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/postSat Signal'
//  '<S293>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/preInt Signal'
//  '<S294>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/preSat Signal'
//  '<S295>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Anti-windup/Passthrough'
//  '<S296>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/D Gain/Disabled'
//  '<S297>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/External Derivative/Disabled'
//  '<S298>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Filter/Disabled'
//  '<S299>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Filter ICs/Disabled'
//  '<S300>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/I Gain/Internal Parameters'
//  '<S301>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Ideal P Gain/Passthrough'
//  '<S302>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Ideal P Gain Fdbk/Disabled'
//  '<S303>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Integrator/Discrete'
//  '<S304>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Integrator ICs/Internal IC'
//  '<S305>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/N Copy/Disabled wSignal Specification'
//  '<S306>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/N Gain/Disabled'
//  '<S307>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/P Copy/Disabled'
//  '<S308>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Parallel P Gain/Internal Parameters'
//  '<S309>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Reset Signal/Disabled'
//  '<S310>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Saturation/Passthrough'
//  '<S311>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Saturation Fdbk/Disabled'
//  '<S312>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Sum/Sum_PI'
//  '<S313>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Sum Fdbk/Disabled'
//  '<S314>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tracking Mode/Disabled'
//  '<S315>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tracking Mode Sum/Passthrough'
//  '<S316>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S317>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/Tsamp - Ngain/Passthrough'
//  '<S318>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/postSat Signal/Forward_Path'
//  '<S319>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/preInt Signal/Internal PreInt'
//  '<S320>' : 'Full_Controller/Auto-Pilot/PI Yaw Controller/preSat Signal/Forward_Path'

#endif                                 // Full_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
