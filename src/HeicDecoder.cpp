#include<libheif/heif.h>
#include<iostream>

void initialize_decoder()
{
	heif_init(nullptr);
	std::cout<< "HEIC Engine successfully powered on" << std::endl;
	heif_deinit();
}