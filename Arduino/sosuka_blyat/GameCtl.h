#ifndef GameCtl_h
#define GameCtl_h

class GameCtl {
  public:
    GameCtl(int seed);
    void change();
    void cycle();

  private:
    volatile bool swstate;
    volatile bool cycling;
    int value[2];
    int time;
    int points;
    int oper;
    bool sosumap[19];
    bool sosuka;
    int randomise(int limit);
    bool issosu();
    void exact();
    void reloadTime();
    void over();
    void swget();
};

#endif
