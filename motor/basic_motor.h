#ifndef BASICLIBS_MOTOR
#define BASICLIBS_MOTOR


struct basic_motor {
        // 电机修正系数
        // 电机速度: pwm_ratio = k * motor_ang_vel + b;
        struct {
                // k为PWM占空比与电机转速之比
                float k;
                // b为电机启动死区占空比
                float b;
        }correction;
        struct {
                // 电机PWM调整函数指针
                // @param       (float) ratio   电机驱动信号占空比，输入范围浮点 -1.0 ~ 1.0
                // @return      (void)          无返回值
                void (*set_ratio)(float ratio);
        }pwm;
};


// 设置电机角速度
// @param       (basic_motor *) _this   目标电机对象指针
// @param       (float)         ang_vel 浮点数，目标电机角速度，单位(rad/s)，负值为反转
// @return      (int)                   返回错误，若无错误返回 0 ,超过电机速度范围返回 EOVERFLOW
int basic_motor_set_velocity(struct basic_motor *_this, float ang_vel);


#endif //BASICLIBS_MOTOR
