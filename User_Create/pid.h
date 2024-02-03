#ifndef __PID_H
#define __PID_H

struct pid_params {
	float kp,ki,kd;
	float set_point, integral, last_error;
	float output;
};

void init_pid(struct pid_params *pid, float kp, float ki, float kd,float set);
float update(struct pid_params *pid, float current_value, float dt);
void update_params(float freq) ;

#endif

