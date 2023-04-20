#ifndef WAVES_H
#define WAVES_H

typedef struct wave_s{
	double amplitude;
	double frequency;
	double (*wave_func)(wave_t*, double);
} wave_t;

wave_t wave_init(double amplitude, double frequency);
double sin(wave_t* wave, const float RADS, const int PRECISION);

double square();

#endif