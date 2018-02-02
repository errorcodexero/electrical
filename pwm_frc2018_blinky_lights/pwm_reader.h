#ifndef PWM_READER_H
#define PWM_READER_H

double calculate_duty_cycle(const unsigned);

struct PWM_constants{
  static const long DEADBAND_RANGE_HIGH_END = 1520;//microseconds
  static const long DEADBAND_RANGE_LOW_END = 1480;//microseconds
  static const long FULL_FORWARD = 2004;//microseconds
  static const long  FULL_REVERSE = 997;//microseconds
};

double convert_duty_cycle(const double);

#endif
