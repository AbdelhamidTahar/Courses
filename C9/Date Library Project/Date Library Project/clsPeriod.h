#pragma once
#include "clsDate.h"

class clsPeriod
{
private:
    clsDate _StartDate;
    clsDate _EndDate;
public:

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->_StartDate = StartDate;
        this-> _EndDate = EndDate;
    }

    void SetStartDate(clsDate Date)
    {
        _StartDate = Date;
    }
    clsDate GetStartDate()
    {
        return _StartDate;
    }
    __declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;

    void SetEndDate(clsDate Date)
    {
        _EndDate = Date;
    }
    clsDate GetEndDate()
    {
        return _EndDate;
    }
    __declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;


    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            || clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After)
            return false;
        else
            return true;
    }
    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

   static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }
   int PeriodLengthInDays(bool IncludeEndDate = false)
   {
       return PeriodLengthInDays(*this, IncludeEndDate);
   }

   static bool isDateInPeriod(clsDate Date, clsPeriod Period)
   {
      return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before
          || clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
   }
 
   static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
  {
      int Period1Length = PeriodLengthInDays(Period1, true);
      int Period2Length = PeriodLengthInDays(Period2, true);
      int OverlapDays = 0;

      if (!IsOverlapPeriods(Period1, Period2))
          return 0;

      if (Period1Length < Period2Length)
      {
          while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
          {
              if (isDateInPeriod(Period1.StartDate, Period2))
                  OverlapDays++;
              Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
          }
      }
      else
      {
          while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
          {
              if (isDateInPeriod(Period2.StartDate, Period1))
                  OverlapDays++;
              Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
          }
      }
      return OverlapDays;
  }
   int CountOverlapDays(clsPeriod Period2)
   {
       return CountOverlapDays(*this, Period2);
   }


   void Print()
   {
       cout << "Period Start: ";
       StartDate.Print();


       cout << "Period End: ";
       EndDate.Print();


   }

};