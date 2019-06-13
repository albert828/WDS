#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH

/**
 * @brief Manipulator class : contains values of vertical 
      and horizontal rotation angle in degress
 * 
 */
class Manipulator {
  /**
   * @brief Value of vertical rotation angle in degress
   * 
   */
  double  _Q2_deg;
  /**
   * @brief Value of horizontal rotation angle in degress
   * 
   */
  double  _Q0_deg;

 public:
  /**
   * @brief This is the constructor
   *
   * It sets up angles into 0
   */
  Manipulator()
     { _Q0_deg = _Q2_deg = 0; }

  /**
   * @brief SetQ0_deg Sets value of the horizontal rotation angle 
   * @param[in] Q0_deg : value of the horizontal rotation angle 
   */
  void SetQ0_deg(double Q0_deg) { _Q0_deg = Q0_deg; }
  /**
   * @brief GetQ0_deg Gets value of the horizontal rotation angle
   * @return value of the horizontal rotation angle
   */
  double GetQ0_deg() const { return _Q0_deg; }
  /**
   * @brief SetQ2_deg Sets value of the vertical rotation angle 
   * @param[in] Q2_deg : value of the vertical rotation angle
   */
  void SetQ2_deg(double Q2_deg) { _Q2_deg = Q2_deg; }
  /**
   * @brief GetQ2_deg Gets value of the vertical rotation angle 
   * @return  value of the vertical rotation angle
   */
  double GetQ2_deg() const { return _Q2_deg; }

};


extern Manipulator  Manip;

#endif
