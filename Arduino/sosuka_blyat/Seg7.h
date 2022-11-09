#ifndef Seg7_h
#define Seg7_h

class Seg7 {
  public:
    Seg7(int datpin, int clkpin, int opepin, int numof, int dispval, bool disping);
    void change(int which,int disp);
    void display(bool enbl);
    virtual void reflect();

  protected:
    int numdig;
    int *status;
    bool enable;
    int pins[3];
    byte digits[];
};

#endif
