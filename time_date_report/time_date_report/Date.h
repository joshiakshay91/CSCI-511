#ifndef DATE_H
#define DATE_H
//compile with -fno-elide-constructors
class Date {
  public:
    Date(int m, int d, int y); //3-arg ctor
    Date(const Date& d);       //copy ctor
    void display()const;
  private:
    int month;
    int day;
    int year;
};
#endif
