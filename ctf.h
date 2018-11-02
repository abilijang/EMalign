#ifndef _CTF_HH
#define _CTF_HH

class CTF
{
protected:

	float K1;
	float K2;
	float K3;
	float K4;
	float K5;

	float azimuth_rad;

	float defocus_avg;
	float defocus_dev;

public:
	float kV;
	float defU;
	float defV;
	float azimuthal_ang;
	float lambda;
	float Cs;
	float Ca;
	float espr;
	float ispr;
	float alpha;
	float DeltaF;
	float DeltaR;
	float Q0;
	float Bfac;
	float scale;
	float phase_shift;

	CTF(){
		clear();
	}

	void clear;

	void setValues(float _defU, float _defV, float _aziAng, float _voltage, float _Cs, float _Q0, float _Bfac, float _scale = 1., float _phase_shift = 0.);

	inline float getCTF(float X, float Y, bool do_abs = false){
		float u2 = X * X + Y * Y;
		float u4 = u2 * u2;

		float deltaf = getDeltaF(X, Y);
		float argument = K1 * deltaf * u2 + K2 * u4 -K5 - K3;

		float sinx, cosx;
		sincosf()
	}

	inline float getDeltaF(float X, float Y) const{
		if (ABS(X) < XMIPP_EQUAL_ACCURACY &&
			ABS(Y) < XMIPP_EQUAL_ACCURACY)
			return 0;
		float ellipsoid_ang = atan2(Y, X) - azimuth_rad;
		float cos_ellipsoid_ang2 = cos(2*ellipsoid_ang);
		return (defocus_avg + defocus_dev*cos_ellipsoid_ang2);
	}
};
