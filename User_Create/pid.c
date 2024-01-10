#include "pid.h"

void init_pid(struct pid_params *pid, float kp, float ki, float kd)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->last_error = 0;
	pid->set_point = 0;
	pid->integral = 0;
}

float update(struct pid_params *pid, float current_value, float dt)
{
	float error = pid->set_point - current_value;
	pid->integral += error * dt;
	float derivative = (error - pid->last_error) / dt;
	
	float output = (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
	return output;
}

