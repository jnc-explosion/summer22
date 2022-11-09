#ifndef Seg7_h
#define Seg7_h

class Seg7 {
  public:
    Seg7(int datpin, int clkpin, int opepin, int numof, int &dispval[], bool disping);
    void change(int which,int disp);
    void display(bool enbl);
    void reflect();

  private:
    int numdig;
    int *status;
    bool enable;
    int pins[3];
    const byte digits[] = {
      0b11111100, // 0
      0b01100000, // 1
      0b11011010, // 2
      0b11110010, // 3
      0b01100110, // 4
      0b10110110, // 5
      0b10111110, // 6
      0b11100100, // 7
      0b11111110, // 8
      0b11110110, // 9
    };
}

#endif
