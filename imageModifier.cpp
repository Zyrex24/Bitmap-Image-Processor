// Program: ImageModifier.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
//          Program will display various filters and apply it for the specified image
// Author:  Mohamed El-Ramly
// Devs  :  Ahmed Niazi(20220452) & Omer Tarek(20220438)
// emails:  ahmedniazi24a.b@gmail.com & omertarek131@gmail.com
// Date:    5 Ocotber 2023
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];


void loadImage();
void saveImage();
/*------------------*/
void menu();
void blackWhiteImage();
void invertImage();
void mergeImageLoad();
void mergeImage();
void saveImage3();
void flipImageHorizontally();
void flipImageVertically();
void flipVerticalHorizontal();
void darkenImage();
void lightenImage();
void rotate90();
void rotate180();
void rotate360();


int main()
{
    cout << "Welcome our Dear User :) \n\n";
    loadImage();
    menu();
    cout << "The image has been processed successfully :)\n\n";
    return 0;
}


void menu() {
    int selection;
    cout << "Please select a filter to apply or 0 to exit:" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1.  Convert to Black and White" << endl;
    cout << "2.  Invert Filter" << endl;
    cout << "3.  Merge Filter" << endl;
    cout << "4.  Flip Image" << endl;
    cout << "5.  Darken and Lighten Image" << endl;
    cout << "6.  Rotate Image" << endl;
    cout << "-----Under Development-----" << endl;
    cout << "7.  Detect Image Edges" << endl;
    cout << "8.  Enlarge Image" << endl;
    cout << "9.  Shrink Image" << endl;
    cout << "10. Mirror 1/2 Image" << endl;
    cout << "11. Shuffle Image" << endl;
    cout << "12. Blur Image" << endl;
    cout << "13. Crop Image" << endl;
    cout << "14. Skew Image Right" << endl;
    cout << "15. Skew Image Up" << endl;
    cout << "16. Save the image to a file" << endl;
    cout << "-----end-----" << endl;
    cout << "0.  Exit" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> selection;

    switch (selection) {
        case 1:
            // Convert to Black and White
            blackWhiteImage();
            saveImage();
            break;
        case 2:
            // Invert Filter
            invertImage();
            saveImage();
            break;
        case 3:
            // Merge Filter
            mergeImageLoad();
            mergeImage();
            saveImage3();
            break;
        case 4:
            // Flip Image
            char ans;
            cout << "Flip (h)orizontally or (v)ertically or (b)oth?\t";
            cin >> ans;
            cout << endl;
            if(ans == 'h')
                flipImageHorizontally();
            else if(ans == 'v')
                flipImageVertically();
            else if(ans == 'b')
                flipVerticalHorizontal();
            saveImage3();
            break;
        case 5:
            // Darken and Lighten Image
            char answer;
            cout << "Do you want to (d)arken or (l)ighten?\t";
            cin >> answer;
            cout << endl;
            if(answer == 'd')
                darkenImage();
            else if(answer == 'l')
                lightenImage();
            saveImage();
            break;
        case 6:
            // Rotate Image
            int answe;
            cout << "Rotate (90), (180) or (360) degrees?\t";
            cin >> answe; cout << endl;
            if(answe == 90)
                rotate90();
            else if(answe == 180)
                rotate180();
            else if(answe == 360)
                rotate360();
            saveImage3();
            break;
        case 7:
            // Detect Image Edges
            break;
        case 8:
            // Enlarge Image
            break;
        case 9:
            // Shrink Image
            break;
        case 10:
            // Mirror 1/2 Image
            break;
        case 11:
            // Shuffle Image
            break;
        case 12:
            // Blur Image
            break;
        case 13:
            // Crop Image
            break;
        case 14:
            // Skew Image Right
            break;
        case 15:
            // Skew Image Up
            break;
        case 16:
            // Save the image to a file
            break;
        case 0:
            // Exit
            cout << "Thank you for using our program :)" << endl;
            break;
        default:
            int anns;
            cout << "Invalid choice, Please press 0 to exit or 1 to choose again from the menu: ";
            cin >> anns;
            cout << endl;
            if (anns == 0) {
                cout << "Thank you for using our program :)" << endl;
                break; }
            else if (anns == 1) {
                menu();}
    }
}

//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    cout << endl;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
//_________________________________________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void blackWhiteImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image [i][j] = abs(image[i][j]-100);
        }
    }
}
void mergeImageLoad() {
    char imageFileName[100];

    // Get gray scale image file name to merge
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to the merge image .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}
void mergeImage(){
    for(int i =0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image3[i][j] = (image[i][j] + image2[i][j])/2;
        }
    }
}
void saveImage3() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}
void flipImageHorizontally() {
    for(int i =SIZE-1; i >=0;i--) {
        for(int j =0; j < SIZE;j++){
            image3[i][j] = image[i][SIZE-1-j];
        }
    }
}
void flipImageVertically() {
    for(int i =0; i <SIZE;i++) {
        for(int j =SIZE-1; j >=0;j--){
            image3[i][j] = image[SIZE -1 -i][j];
        }
    }
}
void flipVerticalHorizontal(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j] = image[SIZE-i-1][SIZE-j-1];
        }
    }
}
void darkenImage() {
    for(int i =0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++){
            if(image[i][j] -100 <0) {image[i][j] =0;}
            else {image[i][j] -= 100;}
        }
    }
}
void lightenImage() {
    for(int i =0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(image[i][j] + 100 > 255) { image[i][j] = 255; }
            else { image[i][j] += 100; }
        }
    }
}
void rotate90(){
    int k =0, l=0;
    for(int i =SIZE; i >= SIZE/256-1; i--)
    {
        for(int j = SIZE/256-1; j < SIZE; j++)
        {
            image3[l][k] = image[i][j];
            l++;
        }
        l =0;
        k++;
    }
}
void rotate180(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j] = image[SIZE-i-1][SIZE-j-1];
        }
    }
}
void rotate360() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = image[i][j];
        }
    }
}



