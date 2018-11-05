#include <iostream>

template<typename T>
class Image
{
public:
	float* 			data;

private:
	const char* 	filename;
	FILE*			fimg;
	FILE*			fhed;
	bool			mmapOn;
	unsigned long	offset;
	size_t			mappedSize;
	int 			mFd;

public:
	Image(){
		mmapOn = false;
		clear();
	}

	Image(long int Xdim, long int Ydim, long int Zdim = 1, long int Ndim = 1){

	}

	void clear(){
		if(mmapOn){
			munmap(data.data-offset, mappedSize);
			close(mFd);
			data.data = NULL;
		}
		else
			data.clear = NULL;
	}
};
