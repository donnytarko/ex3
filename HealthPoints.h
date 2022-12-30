#ifndef HEALTH_POINTS
#define HEALTH_POINTS

#include <iostream>

class HealthPoints {
    int value, max;
    friend HealthPoints operator+(HealthPoints hp, int change);
    friend HealthPoints operator+(int change, HealthPoints hp);
    friend HealthPoints operator-(HealthPoints hp, int change);
    friend HealthPoints operator-(int change, HealthPoints hp);
    friend bool operator==(const HealthPoints& first, const HealthPoints& second);
    friend bool operator<(const HealthPoints&first, const HealthPoints& second);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);
    
    public:
    HealthPoints(int max = 100);
    HealthPoints(const HealthPoints& other) = default;
    ~HealthPoints() = default;
    HealthPoints& operator+=(const HealthPoints& other);
    HealthPoints& operator-=(const HealthPoints& other);
    enum InvalidArgument { Bad };
};

#endif //HEALTH_POINTS