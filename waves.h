#ifndef WAVES_H
#define WAVES_H

#define PI 3.141592653589793
#define PI_2 (PI * 2)
#define TAYLOR_SERIES_ITERS 10

typedef struct wave_s{
	double amplitude;
	double frequency;
	double phase;
	double (*wave_func)(wave_t * const, double);
} wave_t;

wave_t* wave_init(
	double amp, 
	double freq,
	double (*wf)(wave_t * const, double)
);

double powdi(const double BASE, const int POWER);
int factorial(const int INDEX);
double rad_to_deg(const double RAD);
double deg_to_rad(const double DEG);
int sign(const int NUM);
double abs(const double NUM);

double sin(wave_t * const WAVE, const double TIME);
double cos(wave_t * const WAVE, const double TIME);
double square(wave_t * const WAVE, const double TIME);
double triangle(wave_t * const WAVE, const double TIME);
double sawtooth(wave_t * const WAVE, const double TIME);

#endif