#include <iostream>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

int main(int argc,char **argv) {
    
    // Read image filename from the command line (or set it to "lena.jpg" if option '-i' is not provided)
    const char* file_i = cimg_option("-i","/home/jfab/vision/src/lena.jpg","Input image");
    // Load an image
    CImg<unsigned char> image = CImg<>(file_i);
    
    cout << "original" << endl; 
    cout << "variance =" << image.variance(0) << endl;
    cout << "variance noise =" << image.variance_noise(0) << endl;

    CImgDisplay disp(image,"original");

    CImg<unsigned char> image_noised = image.noise(10,2);

    cout << "bruitage" << endl; 
    cout << "variance =" << image_noised.variance(0) << endl;
    cout << "variance noise =" << image_noised.variance_noise(0) << endl;

    CImg<unsigned char> image_median = image_noised;
    image_median.blur_median(5,0);
    cout << "filtre median" << endl; 
    cout << "variance =" << image_median.variance(0) << endl;
    cout << "variance noise =" << image_median.variance_noise(0) << endl;

    CImg<unsigned char> image_box = image_noised;
    image_box.blur_box(5);
    cout << "filtre box" << endl; 
    cout << "variance =" << image_box.variance(0) << endl;
    cout << "variance noise =" << image_box.variance_noise(0) << endl;

    CImg<unsigned char> image_anisotropic = image_noised;
    image_anisotropic.blur_anisotropic(5,0);
    cout << "filtre anisotrope" << endl; 
    cout << "variance =" << image_anisotropic.variance(0) << endl;
    cout << "variance noise =" << image_anisotropic.variance_noise(0) << endl;

    CImgDisplay disp_noise(image_noised,"noise");
    CImgDisplay disp_median(image_median,"median");
    CImgDisplay disp_box(image_box,"box");
    CImgDisplay disp_anisotropic(image_anisotropic,"anisotropic");

    cin.get();


    return 0;
}
