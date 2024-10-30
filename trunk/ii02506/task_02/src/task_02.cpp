#include <iostream>

class PIDController {
private:
    double kp;  // Пропорциональный коэффициент
    double ki;  // Интегральный коэффициент
    double kd;  // Дифференциальный коэффициент

    double previous_error;  // Предыдущее значение ошибки
    double integral;        // Сумма интеграла ошибки

    // Новые параметры
    double K;
    double T;
    double TD;
    double T0;

public:
    PIDController(double kp, double ki, double kd, double K, double T, double TD, double T0)
        : kp(kp), ki(ki), kd(kd), K(K), T(T), TD(TD), T0(T0), previous_error(0.0), integral(0.0) {}

    double calculate(double setpoint, double measured_value, double dt) {
        double error = setpoint - measured_value; // Отклонение
        integral += error * dt;                   // Интегральная ошибка
        double derivative = (error - previous_error) / dt; // Дифференциальная ошибка

        // Расчет управляющего воздействия
        double output = kp * error + ki * integral + kd * derivative;

        previous_error = error;
        return output;
    }
};

int main() {
    // Передаем значения K, T, TD, T0 при создании объекта
    PIDController pid(1.0, 0.1, 0.05, 0.0001, 100, 100, 1);

    double setpoint = 100.0;   // Желаемое значение
    double measured_value = 90.0;  // Измеренное значение
    double dt = 0.1;           // Интервал времени

    for (int i = 0; i < 100; ++i) {
        double control = pid.calculate(setpoint, measured_value, dt);
        std::cout << control << std::endl;

        // Симуляция изменения измеренного значения
        measured_value += control * 0.1;
    }

    return 0;
}
