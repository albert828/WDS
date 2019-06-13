#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH

/**
 * @brief Manipulator class : contains values of vertical 
      and horizontal rotation angle in degress
 * 
 */
class Manipulator {
  /**
   * @brief Contains value of the vertical rotation angle in degrees
   * 
   */
  double  _Q2_deg;
  /**
   * @brief Contains value of the horizontal rotation angle in degrees
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
   * @param[in] Q0_deg : value of the horizontal rotation angle
   */
  void SetQ0_deg(double Q0_deg) { _Q0_deg = Q0_deg; }
  /**
   * @brief GetQ0_deg Gets value of the Horizontal rotation angle
   * @return Value of the Horizontal rotation angle in degrees
   */
  double GetQ0_deg() const { return _Q0_deg; }
  /**
   * @brief SetQ2_deg Sets value of the Vertical rotation angle
   * @param Q2_deg : value of the Vertical rotation angle in degrees
   */
  void SetQ2_deg(double Q2_deg) { _Q2_deg = Q2_deg; }
  /**
   * @brief GetQ2_deg Gets value of the Vertical rotation angle
   * @return  Value of the Vertical rotation angle in degrees
   */
  double GetQ2_deg() const { return _Q2_deg; }

};
/**
 * @brief Platform object
 * 
 */
extern Manipulator  Manip;

#endif
