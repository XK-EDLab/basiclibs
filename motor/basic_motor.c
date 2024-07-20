#include "basic_motor.h"

#include <stdint.h>
#include <errno.h>


#define BASIC_MOTOR_CORRECT(motor, x) ((motor).correction.k * (x) + (motor).correction.b)


int basic_motor_set_velocity(struct basic_motor* _this, float ang_vel)
{
        float pwm_ratio = BASIC_MOTOR_CORRECT(*_this, ang_vel);
        if (pwm_ratio > 1) {
                pwm_ratio = 1;
                return EOVERFLOW;
        }
        else if (pwm_ratio < -1) {
                pwm_ratio = -1;
                return EOVERFLOW;
        }

        _this->pwm.set_ratio(pwm_ratio);

        return 0;
}
