/*
  2D matrix functions
  copy paste below code
*/

template <typename T> struct M2D  { // Matrix 2D
  int R, C;
  vector<T>  m;
  int SZ()                                      { return R*C;                    }
  M2D(int _R, int _C, T initval) : R(_R), C(_C) { m = vector<T> (SZ(), initval); }
  M2D(int _R, int _C) : R(_R), C(_C)            { m = vector<T> (SZ());          }
  ~M2D()                                        {                                }
  void set(int r, int c, T val)                 { m[r*C + c] = val;              }
  T get(int r, int c)                           { return m[r*C + c];             }
  void print() {
    for(int r=0; r<R; r++) {
      for (int c=0; c<C; c++)
        printf("%10d\t", get(r, c));
      printf("\n");
    }
  }
}; // template <typename T> struct M2D