#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH


class Manipulator {
  double  _Q2_deg;
  double  _Q0_deg;

 public:
  /**
   * @brief Manipulator This is the constructor
   *
   * It sets up rotation to 0
   */
  Manipulator()
     { _Q0_deg = _Q2_deg = 0; }

  /**
   * @brief SetQ0_deg Sets Horizontal rotation
   * @param[in] Q0_deg : rotation degree
   */
  void SetQ0_deg(double Q0_deg) { _Q0_deg = Q0_deg; }
  /**
   * @brief GetQ0_deg Gets Horizontal rotation
   * @return rotation degree
   */
  double GetQ0_deg() const { return _Q0_deg; }
  /**
   * @brief SetQ2_deg Sets Vertical rotation
   * @param Q2_deg : rotation degree
   */
  void SetQ2_deg(double Q2_deg) { _Q2_deg = Q2_deg; }
  /**
   * @brief GetQ2_deg Gets Vertical rotation
   * @return  rotation degree
   */
  double GetQ2_deg() const { return _Q2_deg; }

};


extern Manipulator  Manip;

#endif
