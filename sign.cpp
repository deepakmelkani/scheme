#include <cstdint>
#include <cmath>

class Float16 {
public:
    Float16() : sign(0), exponent(0), fraction(0) {}
    Float16(int s, int e, int f) : sign(s), exponent(e), fraction(f) {}

    float to_float32() const {
        // Convert to 32-bit floating point format
        uint32_t bits = (static_cast<uint32_t>(sign) << 31) | (static_cast<uint32_t>(exponent + 15) << 23) | (static_cast<uint32_t>(fraction) << 13);
        return *reinterpret_cast<float*>(&bits);
    }

private:
    int sign : 1;
    int exponent : 5;
    int fraction : 10;
};
