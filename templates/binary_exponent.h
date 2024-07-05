template <typename T>
T binpow(T a, T b)
{
    static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}