#include "basic_motor.h"


void set_exam_motor_pwm(float ratio);


#define PWM_CC_MAX 5000


// 设电机在100%占空比工作时，转速为300rad/s,无启动死区,则
// k = 100% / 300radps = 0.0033333;
// b = 0
struct basic_motor exam_motor = {
        .correction.k = 0.0033333,
        .correction.b = 0,
        .pwm.set_ratio  = set_exam_motor_pwm
};


void set_exam_motor_pwm(float ratio)
{
        DL_TimerG_setCaptureCompareValue(PWM_0_INST, ratio * PWM_CC_MAX + 0.5, DL_TIMER_CC_0_INDEX);
}

void exam_main()
{
        deviceInit();
        
        basic_motor_set_velocity(&exam_motor, 1);
}
