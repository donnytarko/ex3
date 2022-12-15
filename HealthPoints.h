#ifndef HEALTH_POINTS
#define HEALTH_POINTS

#include <iostream>;

class HealthPoints {
    int value, max;
    friend HealthPoints operator+(const HealthPoints& first, const HealthPoints& second);
    friend HealthPoints operator-(const HealthPoints& first, const HealthPoints& second);
    friend bool operator==(const HealthPoints& first, const HealthPoints& second);
    friend bool operator<(const HealthPoints&first, const HealthPoints& second);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);
    
    public:
    HealthPoints(int max = 100);
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    HealthPoints& operator+=(const HealthPoints& other);
    HealthPoints& operator-=(const HealthPoints& other);
    enum InvalidArgument { Bad };
};


HealthPoints::HealthPoints(int max) {
    if (max <= 0) {
        throw HealthPoints::InvalidArgument::Bad;
    }
    max = max;
    value = max;
};

HealthPoints operator+(const HealthPoints& first, const HealthPoints& second){
    HealthPoints hp(first.value + second.value);
    return hp;
}

HealthPoints operator-(const HealthPoints& first, const HealthPoints& second){
    HealthPoints hp(first.value - second.value);
    return hp;
}

HealthPoints& HealthPoints::operator+=(const HealthPoints& other) {
    value += other.value;
    return *this;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints& other) {
    value -= other.value;
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
    os << hp.value << "(" << hp.max << ")";
    return os;
}



#endif //HEALTH_POINTS