#ifndef TIME_H
#define TIME_H
class Time {
  public:
    Time(int hr, int min);
    Time(const Time& t);
    void display()const;
  private:
    int hour;
    int minute;
};
#endif
