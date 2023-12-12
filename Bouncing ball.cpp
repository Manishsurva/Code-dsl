#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

class BouncingBall {
public:
    virtual void move() = 0;
};

class HorizontalBouncingBall : public BouncingBall {
private:
    double amplitude;
    double frequency;
    double angle;

public:
    HorizontalBouncingBall(double amp, double freq)
        : amplitude(amp), frequency(freq), angle(0.0) {}

    void move() override {
        double x = amplitude * sin(angle);
        std::cout << "Horizontal Bouncing Ball at x = " << x << std::endl;
        angle += frequency;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate time
    }
};

class VerticalBouncingBall : public BouncingBall {
private:
    double amplitude;
    double frequency;
    double angle;

public:
    VerticalBouncingBall(double amp, double freq)
        : amplitude(amp), frequency(freq), angle(0.0) {}

    void move() override {
        double y = amplitude * sin(angle);
        std::cout << "Vertical Bouncing Ball at y = " << y << std::endl;
        angle += frequency;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate time
    }
};

int main() {
    HorizontalBouncingBall horizontalBall(1.0, 0.1);
    VerticalBouncingBall verticalBall(1.0, 0.1);

    for (int i = 0; i < 50; ++i) {
        system("clear"); // Clear console (Linux/Unix)
        horizontalBall.move();
        verticalBall.move();
    }

    return 0;
}
