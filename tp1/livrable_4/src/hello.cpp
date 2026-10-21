#include <iostream>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

//functions prototypes
//rgb2gray : the input is a RGB image, the ouput is a graylevel image
//a pixel gray level is the mean of its R,G and B values
CImg<unsigned char> rgb2gray(CImg<unsigned char>);
//rgb2grayw : the input is a RGB image, the ouput is a graylevel image
//a pixel gray level is a combination ot its R,G, and B values such as
//graylevel=(0.299*R + 0.587*G + 0.114*B);
CImg<unsigned char> rgb2grayw(CImg<unsigned char>);


int main(int argc,char **argv) {
    
 
    const char* file_i = cimg_option("-i","/home/jfab/vision/src/lena.jpg","Input image");
    CImg<unsigned char> image = CImg<>(file_i);
    CImgDisplay disp_original(image,"original");

    CImg<unsigned char> grayimg1 = rgb2gray(image);//conversion en niveaux de gris
    CImgDisplay disp1(grayimg1,"display");
    grayimg1.display(disp1);//affichage de l'image en niveaux de grix
    // //méthode 1, à partir de la classe CImg
    // CImg<float> imghisto = grayimg1.histogram(256);//calcul de l'histogramme
    // imghisto.display_graph(0,3);//affichage de l'histogramme, dans une fenêtre interactive, donc bloquante
    // //méthode 2, à partir de la classe CImgDisplay
    // CImgDisplay hist1;
    // image.display_graph(hist1,3,2,"gray levels",0,0,"count",0,0,false);//affichage de l'histogramme, encore dans une fenêtre interactive, bloquante, mais persistente
    // //méthode 3, avec draw_graph à partir de la classe CImg
    // CImg<unsigned char> visu(500,400,1,3,0);//on construit l'image
    // CImgDisplay draw_disp(visu,"histogramme");//on construit son display et on l'affiche
    // const unsigned char red[] = { 255,0,0 };//on définit une couleur
    // // visu.fill(0).draw_graph(grayimg.histogram(256),red,1,3,0,255,0).display(draw_disp);//ATTENTION ici on écrase l'image "grayimg" avec l'image de l'histogramme
    // //OU
    // visu.fill(0).draw_graph(grayimg.get_histogram(256).normalize(0,255),red,1,3,0,255,0).display(draw_disp);//ICI on n'écrase pas "grayimg", il faut cependant normaliser les valeurs retournées par "get_histogram


    CImg<unsigned char> grayimg2 = rgb2grayw(image);//conversion en niveaux de gris
    CImgDisplay disp2(grayimg2,"display");
    grayimg2.display(disp2);
    // CImg<float> imghisto2 = grayimg2.histogram(256);//calcul de l'histogramme
    // imghisto2.display_graph(0,3);
    
    while (!disp1.is_closed() && !disp2.is_closed()) {
        disp1.wait();
    }
    return 0;
}


//functions
//*******************************************************************
//rgb2gray : the input is a RGB image, the ouput is a graylevel image
CImg<unsigned char> rgb2gray(CImg<unsigned char> prem)
{
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    // for all pixels x,y in image
    cimg_forXY(prem,x,y) {
    // Separation of channels
    int R = (int)prem(x,y,0,0);
    int G = (int)prem(x,y,0,1);
    int B = (int)prem(x,y,0,2);
    // Arithmetic addition of channels for gray
    int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
    // Real weighted addition of channels for gray
    //int grayValueWeight = (int)(0.299*R + 0.587*G + 0.114*B);
    // saving píxel values into image information
    gray(x,y,0,0) = grayValue;
    //grayWeight(x,y,0,0) = grayValueWeight;
    }
    return gray;
}
//*******************************************************************
//********************************************************************
//rgb2grayw : the input is a RGB image, the ouput is a graylevel image
CImg<unsigned char> rgb2grayw(CImg<unsigned char> prem)
{
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    // for all pixels x,y in image
    cimg_forXY(prem,x,y) {
    // Separation of channels
    int R = (int)prem(x,y,0,0);
    int G = (int)prem(x,y,0,1);
    int B = (int)prem(x,y,0,2);
    // Arithmetic addition of channels for gray
    //int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
    // Real weighted addition of channels for gray
    int grayValue = (int)(0.299*R + 0.587*G + 0.114*B);
    // saving píxel values into image information
    gray(x,y,0,0) = grayValue;
    //grayWeight(x,y,0,0) = grayValueWeight;
    }
    return gray;
}