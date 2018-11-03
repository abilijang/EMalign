#include <iostream>
#include <vector>
#include <complex>

using namespace std;

class Reconstructor{
public:
	std::string filename;
	complex * data;
	std::vector<complex> fimg;
	euler

public:
	Reconstructor() {}

	void read(int argc, char **argv);

	void reconstruct();

};
