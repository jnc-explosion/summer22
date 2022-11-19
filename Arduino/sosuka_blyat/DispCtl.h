#ifndef DispCtl_h
#define DispCtl_h

class DispCtl {
  public:
    DispCtl();
    void change(int type,int s1,int s2);
    void chika(int wait);
  private:
    void reflect(int type);
};

#endif
