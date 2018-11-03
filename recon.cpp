/*
 * This class defines the writing behavior.
 */
typedef enum {
	WRITE_OVERWRITE, WRITE_APPEND, WRITE_REPLACE, WRITE_READONLY
} WriteMode;

class fImgHandler {
public:
	FILE* fimg;
	FILE* fhed;

	fImgHandler()
	{
		fimg=NULL;
		fhed=NULL;
	}
};
