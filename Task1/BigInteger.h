#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using ElemType = int32_t;

static constexpr ElemType gl_base        = 1000000000;
static constexpr ElemType gl_upper_bound = 999999999;
static constexpr ElemType gl_digit_count = 9;

inline static ldiv_t divide(long num, long denom)
{
    ldiv_t result;
    result.quot = num / denom;
    result.rem = num - denom * result.quot;
    return result;
}

class BigInterger
{
    friend std::ostream& operator<<(std::ostream &s, const BigInterger &n);
    friend std::istream& operator>>(std::istream &s, BigInterger &val);

public:
    BigInterger();
    BigInterger(const char* c);
    BigInterger(const std::string& s);

    const BigInterger& operator=(const char* c);
    const BigInterger& operator=(const std::string& s);

    const BigInterger& operator+=(const BigInterger& rhs);

    BigInterger operator+(const BigInterger& rhs) const;

    std::string toString() const;

private:
    void correct(bool disableTruncate = false);
    void fromString(const std::string& s);
    void truncateToBase();
    void removeLeadingZeros();

    std::vector<ElemType> m_value;
};

BigInterger::BigInterger()
{
    m_value.push_back(0);
}

inline BigInterger::BigInterger(const char* c)
{
    fromString(c);
}

inline BigInterger::BigInterger(const std::string& s)
{
    fromString(s);
}

inline const BigInterger& BigInterger::operator=(const char* c)
{
    fromString(c);
    return *this;
}

inline const BigInterger& BigInterger::operator=(const std::string& s)
{
    fromString(s);
    return *this;
}

inline const BigInterger& BigInterger::operator+=(const BigInterger& rhs)
{
    if (rhs.m_value.size() > m_value.size())
        m_value.resize(rhs.m_value.size(), 0);

    for (size_t i = 0; i < m_value.size(); ++i)
        m_value[i] += (i < rhs.m_value.size()) ? rhs.m_value[i] : 0;

    correct();
    return *this;
}

inline BigInterger BigInterger::operator+(const BigInterger& rhs) const
{
    BigInterger result;
    result.m_value.resize(std::max(m_value.size(), rhs.m_value.size()), 0);

    for (size_t i = 0; i < m_value.size() || i < rhs.m_value.size(); ++i)
        result.m_value[i] = (i < m_value.size() ? m_value[i] : 0) + (i < rhs.m_value.size() ? rhs.m_value[i] : 0);

    result.correct();
    return result;
}

inline std::string BigInterger::toString() const
{
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

inline void BigInterger::truncateToBase()
{
    for (size_t i = 0; i < m_value.size(); ++i)
    {
        if (m_value[i] >= gl_base)
        {
            auto dt = divide(m_value[i], gl_base);
            m_value[i] = dt.rem;

            if (i + 1 >= m_value.size())
                m_value.push_back(dt.quot);
            else
                m_value[i + 1] += dt.quot;
        }
    }
}

inline void BigInterger::removeLeadingZeros()
{
    for (int32_t i = static_cast<int32_t>(m_value.size()) - 1; i > 0; --i) // remove leading 0's
    {
        if (m_value[i] != 0)
            return;

        m_value.erase(m_value.begin() + i);
    }
}

inline void BigInterger::correct(bool disableTruncate)
{
    if (!disableTruncate)
        truncateToBase();
    removeLeadingZeros();
}

inline void BigInterger::fromString(const std::string& s)
{
    m_value.clear();
    m_value.reserve(s.size() / gl_digit_count + 1);

    int32_t i = (int32_t) s.size() - gl_digit_count;
    for (; i >= 0; i -= gl_digit_count)
        m_value.push_back(std::stoul(s.substr(i, gl_digit_count).c_str()));

    if (i > -gl_digit_count)
    {
        std::string ss = s.substr(0, i + gl_digit_count);
        m_value.push_back(std::stoul(ss.c_str()));
    }

    correct(true);
}

inline std::istream& operator>>(std::istream &s, BigInterger &n)
{
    std::string str;
    s >> str;
    n.fromString(str);
    return s;
}

inline std::ostream& operator<<(std::ostream &s, const BigInterger &n)
{
    bool first = true;
    for (int32_t i = (int32_t) n.m_value.size() - 1; i >= 0; --i)
    {
        if (first)
        {
            s << n.m_value[i];
            first = false;
        }
        else
            s << std::setfill('0') << std::setw(gl_digit_count) << n.m_value[i];
    }
    return s;
}
