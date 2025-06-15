//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SAS.h
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
#ifndef SAS_h_
#define SAS_h_
#include <cmath>
#include "rtwtypes.h"
#include "SAS_types.h"
#include <cstring>

// Model block global parameters (default storage)
extern real_T rtP_K_SAS_Feedback_Gain_Matrix[32];// Variable: K_SAS_Feedback_Gain_Matrix
                                                    //  Referenced by: '<Root>/K-Matrix Feedback'


// Class declaration for model SAS
class SAS final
{
  // public data and function members
 public:
  // Block states (default storage) for model 'SAS'
  struct DW_SAS_T {
    real_T CollLagFilter_states;       // '<Root>/Coll Lag Filter'
    real_T CollRolloffFilter_states;   // '<Root>/Coll Rolloff Filter'
    real_T LatLagFilter_states;        // '<Root>/Lat Lag Filter'
    real_T LatRolloffFilter_states;    // '<Root>/Lat Rolloff Filter'
    real_T LongLagFilter_states;       // '<Root>/Long Lag Filter'
    real_T LongRolloffFilter_states;   // '<Root>/Long Rolloff Filter'
    real_T PedLagFilter_states;        // '<Root>/Ped Lag Filter'
    real_T PedRolloffFilter_states;    // '<Root>/Ped Rolloff Filter'
  };

  // Parameters (default storage)
  struct P_SAS_T {
    real_T CollLagFilter_NumCoef;      // Expression: [1-Lag_Filter_Coll_Const]
                                          //  Referenced by: '<Root>/Coll Lag Filter'

    real_T CollLagFilter_DenCoef[2];  // Expression: [1, -Lag_Filter_Coll_Const]
                                         //  Referenced by: '<Root>/Coll Lag Filter'

    real_T CollLagFilter_InitialStates;// Expression: 0
                                          //  Referenced by: '<Root>/Coll Lag Filter'

    real_T CollRolloffFilter_NumCoef;
                                    // Expression: [1-Rolloff_Filter_Coll_Const]
                                       //  Referenced by: '<Root>/Coll Rolloff Filter'

    real_T CollRolloffFilter_DenCoef[2];
                                   // Expression: [1,-Rolloff_Filter_Coll_Const]
                                      //  Referenced by: '<Root>/Coll Rolloff Filter'

    real_T CollRolloffFilter_InitialStates;// Expression: 0
                                              //  Referenced by: '<Root>/Coll Rolloff Filter'

    real_T LatLagFilter_NumCoef;       // Expression: [1-Lag_Filter_Lat_Const]
                                          //  Referenced by: '<Root>/Lat Lag Filter'

    real_T LatLagFilter_DenCoef[2];    // Expression: [1, -Lag_Filter_Lat_Const]
                                          //  Referenced by: '<Root>/Lat Lag Filter'

    real_T LatLagFilter_InitialStates; // Expression: 0
                                          //  Referenced by: '<Root>/Lat Lag Filter'

    real_T LatRolloffFilter_NumCoef; // Expression: [1-Rolloff_Filter_Lat_Const]
                                        //  Referenced by: '<Root>/Lat Rolloff Filter'

    real_T LatRolloffFilter_DenCoef[2];
                                    // Expression: [1,-Rolloff_Filter_Lat_Const]
                                       //  Referenced by: '<Root>/Lat Rolloff Filter'

    real_T LatRolloffFilter_InitialStates;// Expression: 0
                                             //  Referenced by: '<Root>/Lat Rolloff Filter'

    real_T LongLagFilter_NumCoef;      // Expression: [1-Lag_Filter_Long_Const]
                                          //  Referenced by: '<Root>/Long Lag Filter'

    real_T LongLagFilter_DenCoef[2];  // Expression: [1, -Lag_Filter_Long_Const]
                                         //  Referenced by: '<Root>/Long Lag Filter'

    real_T LongLagFilter_InitialStates;// Expression: 0
                                          //  Referenced by: '<Root>/Long Lag Filter'

    real_T LongRolloffFilter_NumCoef;
                                    // Expression: [1-Rolloff_Filter_Long_Const]
                                       //  Referenced by: '<Root>/Long Rolloff Filter'

    real_T LongRolloffFilter_DenCoef[2];
                                  // Expression: [1, -Rolloff_Filter_Long_Const]
                                     //  Referenced by: '<Root>/Long Rolloff Filter'

    real_T LongRolloffFilter_InitialStates;// Expression: 0
                                              //  Referenced by: '<Root>/Long Rolloff Filter'

    real_T PedLagFilter_NumCoef;       // Expression: [1-Lag_Filter_Ped_Const]
                                          //  Referenced by: '<Root>/Ped Lag Filter'

    real_T PedLagFilter_DenCoef[2];    // Expression: [1, -Lag_Filter_Ped_Const]
                                          //  Referenced by: '<Root>/Ped Lag Filter'

    real_T PedLagFilter_InitialStates; // Expression: 0
                                          //  Referenced by: '<Root>/Ped Lag Filter'

    real_T PedRolloffFilter_NumCoef; // Expression: [1-Rolloff_Filter_Ped_Const]
                                        //  Referenced by: '<Root>/Ped Rolloff Filter'

    real_T PedRolloffFilter_DenCoef[2];
                                    // Expression: [1,-Rolloff_Filter_Ped_Const]
                                       //  Referenced by: '<Root>/Ped Rolloff Filter'

    real_T PedRolloffFilter_InitialStates;// Expression: 0
                                             //  Referenced by: '<Root>/Ped Rolloff Filter'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_SAS_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Initial conditions function
  void init();

  // Copy Constructor
  SAS(SAS const&) = delete;

  // Assignment Operator
  SAS& operator= (SAS const&) & = delete;

  // Move Constructor
  SAS(SAS &&) = delete;

  // Move Assignment Operator
  SAS& operator= (SAS &&) = delete;

  // Real-Time Model get method
  SAS::RT_MODEL_SAS_T * getRTM();

  // model step function
  void step(const boolean_T *rtu_Cntrl_flags_SAS_enabled, const real_T
            *rtu_w_delta_long, const real_T *rtu_w_delta_lat, const real_T
            *rtu_w_delta_coll, const real_T *rtu_w_delta_ped, const real_T
            *rtu_y_u, const real_T *rtu_y_w, const real_T *rtu_y_q, const real_T
            *rtu_y_theta, const real_T *rtu_y_v, const real_T *rtu_y_p, const
            real_T *rtu_y_phi, const real_T *rtu_y_r, real_T *rty_u_delta_long,
            real_T *rty_u_delta_lat, real_T *rty_u_delta_coll, real_T
            *rty_u_delta_ped);

  // Constructor
  SAS();

  // Destructor
  ~SAS();

  // private data and function members
 private:
  // Block states
  DW_SAS_T SAS_DW;

  // Tunable parameters
  static P_SAS_T SAS_rtP;

  // Real-Time Model
  RT_MODEL_SAS_T SAS_M;
};

extern SAS::P_SAS_T SAS_rtP;

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
//  '<Root>' : 'SAS'

#endif                                 // SAS_h_

//
// File trailer for generated code.
//
// [EOF]
//
