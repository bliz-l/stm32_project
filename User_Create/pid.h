#ifndef __PID_H
#define __PID_H

struct pid_params {
	float kp,ki,kd;
	float set_point, integral, last_error;
};

void init_pid(struct pid_params *pid, float kp, float ki, float kd);
float update(struct pid_params *pid, float current_value, float dt);

#endif

