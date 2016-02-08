#include "SorterClass.h"
#include "DateType.h"
#include "SimpleVector.h"
#include "SimpleVector.cpp"
#include "SorterClass.cpp"
#include "TestSorter.h"


using namespace std;
 
 
 
//template <typename DataType>
TestSorter::TestSorter()
        : SorterClass<DateType>()
        {
 
        }
 
//template <typename DataType>
TestSorter::~TestSorter()
{
 
}
 
//template <typename DataType>
bool TestSorter::sort()
{
    DateType one, two, temp;
        int index = 0;
        while(index != this->getSize()-1)
        {
                this->getValueAt(index, one);
                this->getValueAt(index+1, two);
                if(compareTo(one,two))
                {
                        temp = one;
                        this->setValueAt(index, two);
                        this->setValueAt(index+1, temp);
                        index = 0;
                }
                else
                {
                        index++;
                }
        }
        return true;
    /*
        //getValueAt 2 indexes, compare, then keep going till the end
        DateType lhs;
        DateType rhs;
        int pivot = 0;
        int checker = 1;
        bool sorted = false;
        vector1.getValueAt(pivot, lhs);
        vector1.getValueAt(checker, rhs);
        while(sorted==false)
        {
                while(!compareTo(lhs,rhs))//while there are no swaps
                {
                    checker++;
                    vector1.getValueAt(checker, rhs);   
                }
                swap(lhs, rhs, pivot, checker);
                pivot++;
                vector1.getValueAt(pivot, lhs);
                if(pivot == vector1.getSize()-1 && checker == pivot)
                {
                    sorted = true;
                    return true;
                }
                else if(pivot == vector1.getSize()-1)
                {
                    pivot = 0;
                    vector1.getValueAt(pivot, lhs);
                }
                checker = pivot + 1;
        }
        return true;
    */
}
 
//template <typename DataType>
bool TestSorter::compareTo(const DateType lhs, const DateType rhs) //works a single swap,after the swap happens, return true
{
        if(Year(lhs) < Year(rhs))
        {
                return false;
        }
        if(Year(lhs) > Year(rhs))
        {
                return true; 
        }
        if(Year(lhs) == Year(rhs))
        {
                if(Month(lhs) > Month(rhs))
                {
                        return true;                                  
                }
                else if(Month(lhs) == Month(rhs))
                {
                        if(Day(lhs) > Day(rhs))
                        {
                               return true; 
                        }    
                        else if (Day(lhs) == Day(rhs))
                        {
                            return false;
                        }
                        return false;
                }
                return false;
        }
        return false;
}
 
void TestSorter::swap(const DateType lhs, const DateType rhs, int pivot, int checker)
{
        DateType hold;
        vector1.getValueAt(pivot, hold);
        vector1.setValueAt(pivot, rhs);
        vector1.setValueAt(checker, hold);
}
 
int TestSorter::findIndex(const DateType container)
{
        DateType compare;
        char tempArr[25];
        int index = 0;
        while(container.date[index] != '\0')
        {
                tempArr[index] = container.date[index];
                index++;
        }
        tempArr[index] = '\0';
        for(int i = 0; i < vector1.getSize()-1; i++)
        {
                vector1.getValueAt(i, compare);
                if(stringComp(tempArr, compare.date))
                {
                        return i;
                }
        }
        return 0;
}
 
bool TestSorter::stringComp(char* give, char* check)
{
         int index = 0;
        while(give[index] != '\0' && check[index] != '\0')
        {
                if(give[index] != check[index])
                {
                        return false;
                }
        index ++;
        }
        return true;
}
 
void TestSorter::add(const DateType &item)
{
    int index = 0;
    char dateArr[25];
    char quit[] = "QUIT";
    while(item.date[index] != '\0')
    {
        dateArr[index] = item.date[index];
        index++;
    }
    dateArr[index] = '\0';
    if(stringComp(dateArr, quit))
    {
        return;
    }
    if( vector1.getSize() == vector1.getCapacity() )
      {
       if( vector1.getCapacity() > 0 )
          {
           vector1.grow( vector1.getCapacity() ); // double capacity
          }
 
       else
          {
           vector1.grow( vector1.DEFAULT_CAPACITY );
          }
      }
    vector1.setValueAt(vector1.getSize(), item);
    vector1.incrementSize();
}
 
int TestSorter::getSize() const
{
        return vector1.getSize();
}
 
void TestSorter::getValueAt(int index, DateType &item) const throw(logic_error)
{
         if( index >= 0 && index < vector1.getCapacity() )
       {
        vector1.getValueAt(index, item);
       }
 
    else
       {
        throw logic_error( "ERROR: Array index out of bounds" );
       }
}
 
//template <typename DataType>
int TestSorter::Day(const DateType dateItem)
{
    char dayArr[3];
        int day = 0;
        int index = 0;
        while(dateItem.date[index] != ' ')
        {
                dayArr[index] = dateItem.date[index];
                index++;
        }
        
        if(index == 2)
        {
                day = (int)(dayArr[0] - '0');
                day = (day*10);
                day += (int)(dayArr[1] - '0');
                return day;
        }
        else
        {
                day = (int)(dayArr[0] - '0');
                return day;
        }
}

 
//template <typename DataType>
int TestSorter::Month(const DateType dateItem)
{
        char monthArray[5];
        int index = 0;
        int index2;
        while(dateItem.date[index] != ' ')
        {
            index++;
        }
        index++;
        for(index2 = 0; index2 < 3; index2++)
        {
                monthArray[index2] = dateItem.date[index];
                index++;
        }
        monthArray[index2] = '\0';
       /* while(monthArray[index] != '\0')
        {
                char upper = char(monthArray[index] - 'a' + 'A');
                monthArray[index] = upper;
                index++;
        }*/
        if(stringComp(monthArray, "Jan") || stringComp(monthArray, "jan"))
        {
                return 1;
        }
        else if(stringComp(monthArray, "Feb") || stringComp(monthArray, "feb"))
        {
                return 2;
        }
        else if(stringComp(monthArray, "Mar") || stringComp(monthArray, "mar"))
        {
                return 3;
        }
        else if(stringComp(monthArray, "Apr") || stringComp(monthArray, "apr"))
        {
                return 4;
        }
        else if(stringComp(monthArray, "May") || stringComp(monthArray, "may"))
        {
                return 5;
        }
        else if(stringComp(monthArray, "Jun") || stringComp(monthArray, "jun"))
        {
                return 6;
        }
        else if(stringComp(monthArray, "Jul") || stringComp(monthArray, "jul"))
        {
                return 7;
        }
        else if(stringComp(monthArray, "Aug") || stringComp(monthArray, "aug"))
        {
                return 8;
        }
        else if(stringComp(monthArray, "Sep") || stringComp(monthArray, "sep"))
        {
                return 9;
        }
        else if(stringComp(monthArray, "Oct") || stringComp(monthArray, "oct"))
        {
                return 10;
        }
        else if(stringComp(monthArray, "Nov") || stringComp(monthArray, "nov"))
        {
                return 11;
        }
        else if(stringComp(monthArray, "Dec") || stringComp(monthArray, "dec"))
        {
                return 12;
        }
        else
        {
                return 0;
        }
}
 
//template <typename DataType>
int TestSorter::Year(const DateType dateItem)
{
        char yearArray[5];
        int year = 0;
        int index = 0;
        int index2 = 0;
        int numYear;
        while(dateItem.date[index] != ' ')
        {
                index++;
        }
        index++;
        while(dateItem.date[index] != ' ')
        {
                index++;
        }
        index++;
        while(dateItem.date[index] != '\0')
        {
                yearArray[index2] = dateItem.date[index];
                index2++;
                index++;
        }
                numYear = (int)(yearArray[0] - '0');
                year = year + (numYear*1000);
                numYear = (int)(yearArray[1] - '0');
                year = year + (numYear*100);
                numYear = (int)(yearArray[2] - '0');
                year = year + (numYear*10);
                numYear = (int)(yearArray[3] - '0');
                year += numYear;
                return year;
}