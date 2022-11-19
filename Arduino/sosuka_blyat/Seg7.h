#ifndef Seg7_h
#define Seg7_h

class Seg7 {
  public:
    Seg7(int datpin, int clkpin, int opepin, bool disping, bool updown);
    void change(int which,int disp);
    void display(bool enbl);
    virtual void reflect();

  protected:
    int status[2];
    bool enable;
    bool ud;
    int pins[3];
    byte digits[];
};

#endif
