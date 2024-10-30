#include <iostream>

class PIDController {
private:
    double kp;
    double ki;
    double kd;

    double previous_error;
    double integral; 

    double K;
    double T;
    double TD;
    double T0;

public:
    PIDController(double kp, double ki, double kd, double K, double T, double TD, double T0)
        : kp(kp), ki(ki), kd(kd), K(K), T(T), TD(TD), T0(T0), previous_error(0.0), integral(0.0) {}

    double calculate(double setpoint, double measured_value, double dt) {
        double error = setpoint - measured_value; 
        integral += error * dt;               
        double derivative = (error - previous_error) / dt; 

        double output = kp * error + ki * integral + kd * derivative;

        previous_error = error;
        return output;
    }
};

int main() {
    PIDController pid(1.0, 0.1, 0.05, 0.0001, 100, 100, 1);

    double setpoint = 100.0;   
    double measured_value = 90.0;  
    double dt = 0.1;       

    for (int i = 0; i < 100; ++i) {
        double control = pid.calculate(setpoint, measured_value, dt);
        std::cout << control << std::endl;

        measured_value += control * 0.1;
    }

    return 0;
}
