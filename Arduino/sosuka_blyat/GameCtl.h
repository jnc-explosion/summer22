#ifndef GameCtl_h
#define GameCtl_h

class GameCtl {
  public:
    GameCtl(int seed);
    void chanval();
    void cycle();
    void reloadTime();
    void over();
    void swget();

  private:
    int randomise(int limit);
    bool sub;
    bool sosumap[19];
    volatile bool swstate;
    bool issosu();
    bool sosuka;
    volatile bool cycling;
    int value[2];
    void swcut();
    void swchange();
    void exact();
    int time;
    int points;
};

#endif
