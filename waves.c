#include "waves.h"

wave_t* wave_init(
	double amp, 
	double freq,
	double (*wf)(wave_t * const, double)
){
	wave_t* new_wave = (wave_t*)malloc(sizeof(wave_t));
	new_wave->amplitude = amp;
	new_wave->frequency = freq;
	new_wave->wave_func = wf;
}

double powdi(const double BASE, const int POWER){
	double prod = 1;

	for(int i = 0; i < POWER; i++)
		prod *= BASE;

	return prod;
}

int factorial(const int INDEX){
	int fact = INDEX;

	for(int i = INDEX - 1; i > 0; i--)
		fact *= INDEX;

	return fact;
}

double rad_to_deg(const double RAD){
	return RAD * (180 / PI);
}

double deg_to_rad(const double DEG){
	return DEG * (PI / 180);
}
//returns 1 if positive, 0 if negative
int sign(const int NUM){
	return !(NUM & (1<<31));
}

double abs(const double NUM){
	return NUM * (!sign(NUM) ? -1 : 1);
}

double sin(wave_t * const WAVE, const double TIME){
	double sum = 0;

	for(int n = 0; n < TAYLOR_SERIES_ITERS; n++){
		sum += ((powdi(-1, n) / factorial(2 * n + 1)) * powdi(PI_2 * WAVE->frequency * TIME + WAVE->phase, 2 * n + 1));
	}

	return WAVE->amplitude * sum;
}

double cos(wave_t * const WAVE, const double TIME){
	double sum = 0;

	for(int n = 0; n < TAYLOR_SERIES_ITERS; n++){
		sum += ((powdi(-1, n) / factorial(2 * n)) * powdi(PI_2 * WAVE->frequency * TIME + WAVE->phase, 2 * n));
	}

	return WAVE->amplitude * sum;
}

double square(wave_t * const WAVE, const double TIME){
	return sign(sin(WAVE, TIME));
}

double triangle(wave_t * const WAVE, const double TIME){
	//todo: implementation
	return 0;
}

double sawtooth(wave_t * const WAVE, const double TIME){
	//todo: implementation
	return 0;
}
