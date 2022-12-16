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


HealthPoints::HealthPoints(int maxHp) {
    if (maxHp <= 0) {
        throw HealthPoints::InvalidArgument::Bad;
    }
    max = maxHp;
    value = maxHp;
}

HealthPoints operator+(HealthPoints hp, int change){
    if (hp.value + change >= hp.max) {
        hp.value = hp.max;
        return hp;
    }
    hp.value += change;
    return hp;
}

HealthPoints operator+(int change, HealthPoints hp){
    if (hp.value + change >= hp.max) {
        hp.value = hp.max;
        return hp;
    }
    hp.value += change;
    return hp;
}

HealthPoints operator-(HealthPoints hp, int change){
    if (hp.value - change <= 0) {
        hp.value = 0;
        return hp;
    }
    hp.value -= change;
    return hp;
}

HealthPoints operator-(int change, HealthPoints hp){
    if (hp.value - change <= 0) {
        hp.value = 0;
        return hp;
    }
    hp.value -= change;
    return hp;
}

HealthPoints& HealthPoints::operator+=(const HealthPoints& other) {
    if (value += other.value >= max) {
        value = max;
    }
    else {
        value += other.value;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints& other) {
    std::cout << "value here is " << value << std::endl;
    std::cout << "max here is " << max << std::endl;

    if (value <= other.value) {
        value = 0;
        return *this;
    }
    value -= other.value;
    std::cout << "value over here is " << value << std::endl;
    std::cout << "max over here is " << max << std::endl;
    return *this;
}

bool operator==(const HealthPoints& first, const HealthPoints& second) {
    return (first.value == second.value);
}

bool operator!=(const HealthPoints& first, const HealthPoints& second) {
    return !(first == second);
}

bool operator<(const HealthPoints& first, const HealthPoints& second) {
    return (first.value < second.value);
}

bool operator>(const HealthPoints& first, const HealthPoints& second) {
    return !(first < second);
}

bool operator<=(const HealthPoints& first, const HealthPoints& second) {
    return !(first > second);
}

bool operator>=(const HealthPoints& first, const HealthPoints& second) {
    return !(first < second);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.value << '(' << hp.max << ')';
    std::cout << hp.value << '(' << hp.max << ')';
    return os;
}



#endif //HEALTH_POINTS