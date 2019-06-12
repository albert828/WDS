#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH

/**
 * @brief This class contains values of the platform rotation angle in degrees
 * 
 */
class Manipulator {
  /**
   * @brief _Q2_deg contains value of the vertical rotation angle in degrees
   * 
   */
  double  _Q2_deg;
  /**
   * @brief contains value of the horizontal rotation angle in degrees
   * 
   */
  double  _Q0_deg;

 public:
  /**
   * @brief Manipulator This is the constructor
   *
   * It sets up horizontal and vertical rotation angle into 0
   */
  Manipulator()
     { _Q0_deg = _Q2_deg = 0; }

  /**
   * @brief SetQ0_deg Sets value of the Horizontal rotation angle
   * @param[in] Q0_deg : rotation degree
   */
  void SetQ0_deg(double Q0_deg) { _Q0_deg = Q0_deg; }
  /**
   * @brief GetQ0_deg Gets value of the Horizontal rotation angle
   * @return Value of the Horizontal rotation angle
   */
  double GetQ0_deg() const { return _Q0_deg; }
  /**
   * @brief SetQ2_deg Sets value of the Vertical rotation angle
   * @param Q2_deg : rotation degree in degrees
   */
  void SetQ2_deg(double Q2_deg) { _Q2_deg = Q2_deg; }
  /**
   * @brief GetQ2_deg Gets value of the Vertical rotation angle
   * @return  Value of the Vertical rotation angle in degrees
   */
  double GetQ2_deg() const { return _Q2_deg; }

};

extern Manipulator  Manip;

#endif
