#pragma once // time.h

#include <ctime>
#include <iostream>

namespace myTime {

class TimeSpan {
private:
    int seconds_;

public:
    void setTime(const int& time)
    {
        this->seconds_ = time;
    }

    const int& getTime() const
    {
        return seconds_;
    }

    int getSec() const
    {
        return seconds_;
    }

    int getMin() const
    {
        return seconds_ / (60);
    }

    int getHours() const
    {
        return seconds_ / (60 * 60);
    }

    int getDay() const
    {
        return seconds_ / (24 * 60 * 60);
    }

    TimeSpan operator-(const TimeSpan& ts)
    {
        return TimeSpan(this->seconds_ - ts.seconds_);
    }

    TimeSpan operator+(const TimeSpan& ts)
    {
        return TimeSpan(this->seconds_ + ts.seconds_);
    }

    TimeSpan(int sec) : seconds_(sec)
    {
    }

    TimeSpan(const TimeSpan& ts)
    {
        this->seconds_ = ts.seconds_;
    }

    TimeSpan(TimeSpan&& ts)
    {
        this->seconds_ = ts.seconds_;
    }

    ~TimeSpan() = default;
};

class Time {
private:
    int seconds_;

public:
    void setTime(const int& time)
    {
        this->seconds_ = time;
    }

    const int& getTime() const
    {
        return seconds_;
    }

    int getSec() const
    {
        return (seconds_ - getDay() * (24 * 60 * 60) - getHours() * (60 * 60)
                - getMin() * 60);
    }

    int getMin() const
    {
        return ((seconds_ - getDay() * (24 * 60 * 60) - getHours() * (60 * 60))
                / (60));
    }

    int getHours() const
    {
        return ((seconds_ - getDay() * (24 * 60 * 60)) / (60 * 60));
    }

    int getDay() const
    {
        return (seconds_ / (24 * 60 * 60));
    }

    Time operator+(const TimeSpan& ts)
    {
        return Time(this->seconds_ + ts.getTime());
    }

    Time operator-(const TimeSpan& ts)
    {
        if ((this->seconds_ - ts.getTime()) < 0)
            return Time(0);
        else
            return Time(this->seconds_ - ts.getTime());
    }
    TimeSpan operator-(const Time& time)
    {
        return TimeSpan(this->seconds_ - time.seconds_);
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& time);

    Time(int sec = static_cast<int>(time(NULL))) : seconds_(sec)
    {
    }
    Time(const TimeSpan& ts) : seconds_(ts.getSec())
    {
        
    }
    ~Time() = default;
};

namespace literals {

TimeSpan operator"" _d(unsigned long long days)
{
    return TimeSpan(days * 24 * 60 * 60);
}

TimeSpan operator"" _h(unsigned long long hours)
{
    return TimeSpan(hours * 60 * 60);
}

TimeSpan operator"" _m(unsigned long long mins)
{
    return TimeSpan(mins * 60);
}

TimeSpan operator"" _s(unsigned long long sec)
{
    return TimeSpan(sec);
}

}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
    out << time.getDay() << "d " << time.getHours() << "h " << time.getMin()
        << "m " << time.getSec() << "s" << '\n';
    return out;
}

}