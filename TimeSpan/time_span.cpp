// Justin Singsanvong
#include "time_span.h"

//default contructor
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0)
{
}

TimeSpan::TimeSpan(float hours, float minutes, float seconds) : hours_(round(hours)), minutes_(round(minutes)), seconds_(round(seconds))
{
	//normalizing time
	hours_ += minutes_ / 60;
	minutes_ %= 60;

	minutes_ += seconds_ / 60;
	seconds_ %= 60;

	//checking for negative times
	if (hours_ < 0) {
		hours_++;
		minutes_ -= 60;
		minutes_++;
		seconds_ -= 60;
	}

	else if (minutes_ < 0) {
		minutes_ += 60;
		hours_--;
	}

	else if (seconds_ < 0) {
		seconds_ += 60;
		minutes_--;
	}
}

TimeSpan::TimeSpan(float minutes, float seconds) : hours_(0), minutes_(round(minutes)), seconds_(round(seconds))
{
	//normalizing time
	hours_ += minutes_ / 60;
	minutes_ %= 60;

	minutes_ += seconds_ / 60;
	seconds_ %= 60;

	//checking for negative times
	if (hours_ < 0) {
		hours_++;
		minutes_ -= 60;
		minutes_++;
		seconds_ -= 60;
	}

	else if (minutes_ < 0) {
		minutes_ += 60;
		hours_--;
	}

	else if (seconds_ < 0) {
		seconds_ += 60;
		minutes_--;
	}
}

TimeSpan::TimeSpan(float seconds) : hours_(0), minutes_(0), seconds_(round(seconds))
{
	//normalizing time
	hours_ += minutes_ / 60;
	minutes_ %= 60;

	minutes_ += seconds_ / 60;
	seconds_ %= 60;

	//checking for negative times
	if (hours_ < 0) {
		hours_++;
		minutes_ -= 60;
		minutes_++;
		seconds_ -= 60;
	}

	else if (minutes_ < 0) {
		minutes_ += 60;
		hours_--;
	}

	else if (seconds_ < 0) {
		seconds_ += 60;
		minutes_--;
	}
}

//getter functions
int TimeSpan::hours() const
{
	return hours_;
}

int TimeSpan::minutes() const
{
	return minutes_;
}

int TimeSpan::seconds() const
{
	return seconds_;
}

//setter function
void TimeSpan::set_time(int hours, int minutes, int seconds)
{
	hours_ = hours;
	minutes_ = minutes;
	seconds_ = seconds;
}

//operator overloads
bool TimeSpan::operator==(const TimeSpan& rhs) const
{
	if ((hours() == rhs.hours()) && (minutes() == rhs.minutes()) && (seconds() == rhs.seconds())) {
		return true;
	}
	return false;
}

TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const
{
	TimeSpan result = *this;
	result += rhs;

	return result;
}

TimeSpan TimeSpan::operator-(const TimeSpan& rhs) const
{
	TimeSpan result = *this;
	result -= rhs;

	return result;
}

TimeSpan TimeSpan::operator-() const
{
	return TimeSpan(-hours(), -minutes(), -seconds());
}

bool TimeSpan::operator!=(const TimeSpan& rhs) const
{
	return !(*this == rhs);
}

bool TimeSpan::operator<(const TimeSpan& rhs) const
{
	return ((hours() * 3600 + minutes() * 60 + seconds()) < (rhs.hours() * 3600 + rhs.minutes() * 60 + rhs.seconds()));
}

bool TimeSpan::operator<=(const TimeSpan& rhs) const
{
	if (*this < rhs || *this == rhs) {
		return true;
	}
}

bool TimeSpan::operator>(const TimeSpan& rhs) const
{
	return !(*this < rhs);
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const
{
	if (*this > rhs || *this == rhs) {
		return true;
	}
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs)
{
	int total_hours = hours() + rhs.hours();
	int total_minutes = minutes() + rhs.minutes();
	int total_seconds = seconds() + rhs.seconds();
	set_time(total_hours, total_minutes, total_seconds);

	return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs)
{
	int total_hours = hours() - rhs.hours();
	int total_minutes = minutes() - rhs.minutes();
	int total_seconds = seconds() - rhs.seconds();
	set_time(total_hours, total_minutes, total_seconds);

	return *this;
}

ostream& operator<<(ostream& stream, const TimeSpan& t)
{
	stream << "Hours: " << t.hours() << ", Minutes: " << t.minutes() << ", Seconds: " << t.seconds();
	return stream;
}

istream& operator>>(istream& stream, TimeSpan& t)
{
	char comma = ', ';
	stream >> t.hours_ >> comma >> t.minutes_ >> comma >> t.seconds_;
	return stream;
}
