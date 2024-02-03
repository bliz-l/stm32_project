#include "pid.h"
#include "relocate.h"
void init_pid(struct pid_params *pid, float kp, float ki, float kd,float set)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->last_error = 0;
	pid->set_point = set;
	pid->integral = 0;
	pid->output = 0;
}

float update(struct pid_params *pid, float current_value, float dt)
{
	float error = pid->set_point - current_value;
	pid->integral += error * dt;
	float derivative = (error - pid->last_error) / dt;
	float output = (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
	pid->output = output;
	printf("IN_PID: error:%f, derivative:%f, output:%f,lasterror:%f, dt:%f\n",error, derivative, output,pid->last_error, dt);
	pid->last_error = error;

	return output;
}

//Update PID parameters according to frequency
void update_params(float freq) 
{
}
