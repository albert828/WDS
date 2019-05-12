#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH


class Manipulator {
  double  _Q2_deg;
  //double  _Q1_deg;
  double  _Q0_deg;

 public:

  Manipulator()
     { _Q0_deg = _Q2_deg = 0; }

  void SetQ0_deg(double Q0_deg) { _Q0_deg = Q0_deg; }
  double GetQ0_deg() const { return _Q0_deg; }

  //void SetQ1_deg(double Q1_deg) { _Q1_deg = Q1_deg; }
  //double GetQ1_deg() const { return _Q1_deg; }

  void SetQ2_deg(double Q2_deg) { _Q2_deg = Q2_deg; }
  double GetQ2_deg() const { return _Q2_deg; }

};


extern Manipulator  Manip;

#endif
