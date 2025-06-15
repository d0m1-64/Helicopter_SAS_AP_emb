//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Full_Controller_data.cpp
//
// Code generated for Simulink model 'Full_Controller'.
//
// Model version                  : 2.45
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Sun Jun 15 15:06:35 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Full_Controller.h"

// Model block global parameters (default storage)
real_T rtP_AP_GSx_I{ 0.001 };          // Variable: AP_GSx_I
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_GSx_P{ 1.5 };            // Variable: AP_GSx_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_GSy_I{ 0.001 };          // Variable: AP_GSy_I
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_GSy_P{ 6.0 };            // Variable: AP_GSy_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Heave_P{ 3.0 };          // Variable: AP_Heave_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Pitch_I{ 0.01 };         // Variable: AP_Pitch_I
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Pitch_P{ 1.0 };          // Variable: AP_Pitch_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Roll_I{ 0.01 };          // Variable: AP_Roll_I
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Roll_P{ 1.0 };           // Variable: AP_Roll_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Yaw_I{ 0.1 };            // Variable: AP_Yaw_I
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_AP_Yaw_P{ 1.0 };            // Variable: AP_Yaw_P
                                          //  Referenced by: '<Root>/Auto-Pilot'


real_T rtP_K_SAS_Feedback_Gain_Matrix[32]{ -0.77166909779027737,
  -0.47481799966259353, 0.062335418545695014, 0.11023348677659243,
  0.004517194823523505, -0.0828378698290566, -0.057847448931429714,
  0.1043403644829223, 1.5721733114163838, 0.99847626415906077,
  -0.10719482863273574, -0.21472848152235482, 7.8354779310286888,
  4.7655214806489612, -2.2374381066327031, -3.920985039277034,
  0.14173796160425217, 0.1219450142228837, 0.26716304123375956,
  0.41547747323256945, -0.831918916974052, 1.1367050643291154,
  -0.02922219231684247, -0.068909635754922371, -1.4292526604279476,
  -1.8647327365785744, -4.3650356588196839, -7.6582762076774538,
  -0.21226251140811134, 0.045706373017832869, 0.77431676795418325,
  1.420098019882122 } ;                // Variable: K_SAS_Feedback_Gain_Matrix
                                          //  Referenced by: '<Root>/SAS'


//
// File trailer for generated code.
//
// [EOF]
//
