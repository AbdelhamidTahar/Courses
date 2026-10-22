#pragma once
#include <iostream>
using namespace std;

class clsTime
{
private:

	
	short _Hour;
	short _Min  ;
	short _Sec;

public:

	void SetSec(short Sec)
	{
		_Sec = Sec;
	}
	short GetSec()
	{
		return _Sec;
	}
	__declspec(property(get = GetSec, put = SetSec))short Sec;

	void SetMin(short Min)
	{
		_Min = Min;
	}
	short GetMin()
	{
		return _Min;
	}
	__declspec(property(get = GetMin, put = SetMin))short Min;

	void SetHour(short Hour)
	{
		_Hour = Hour;
	}
	short GetHour()
	{
		return _Hour;
	}
	__declspec(property(get = GetHour, put = SetHour))short Hour;

	clsTime(short Hous, short Min, short Sec)
	{
		_Hour = Hous;
		_Min = Min;
		_Sec = Sec;
	}

	clsTime()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Sec = now->tm_sec;
		_Min = now->tm_min;
		_Hour = now->tm_hour;
	}

	static clsTime GetSystemTime()
	{
		return clsTime();
	}
	static string TimeToString(clsTime Time)
	{
		return to_string(Time.Hour) + ":" + to_string(Time.Min) + ":" + to_string(Time.Sec);
	}

};

