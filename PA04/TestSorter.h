#include "SorterClass.h"
#include "DateType.h"
#include "SimpleVector.h"
#include "SimpleVector.cpp"
#include "SorterClass.cpp"
 
class TestSorter: public SorterClass<DateType>
{
        public:
                TestSorter();
                virtual ~TestSorter();
                bool sort();
                bool compareTo(const DateType lhs, const DateType rhs);
                int Day(const DateType dateItem);
                int Month(const DateType dateItem);
                int Year(const DateType dateItem);
                int findIndex(const DateType dateItem);
                void swap(const DateType lhs, const DateType rhs, int pivot, int checker);
                void add(const DateType &item);
                int getSize() const;
                void getValueAt( int index, DateType &item ) const throw (logic_error);
                bool stringComp(char *give, char *check);
 
        private:
                SimpleVector<DateType> vector1;
};