// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-20220452-20220438-A1-Part1.cpp
// Last Modification Date:	15/10/2023
// Author1 and ID and Group:	Ahmed Niazi 20220452  S17
// Author2 and ID and Group:	Omar Tarek 20220438  S17
// Author3 and ID and Group:
// Teaching Assistant:
// Purpose: Apply a variety of filters on RGB bmp images


#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];


void loadImage();
void saveImage();
/*------------------*/
void initialize();
void menu();
void menu1(string & s);
void menu2(string & s);
void convertToGrayscale_c();
void blackWhiteImage_c();
void invertImage_c();
void mergedImageLoad_c();
void mergeImage_c();
void saveImage3_c();
void flipImageHorizontally_c();
void flipImageVertically_c();
void flipVerticalHorizontal_c();
void darkenImage_c();
void lightenImage_c();
void rotate90_c();
void rotate180_c();
void rotate360_c();
void detectImageEdges_c();
void enlargeImage_c(const string &quarter);
void shrinkImage_c(const string& shrink_by);
void mirrorHalfImage_c(const char & direction);
void shuffleImage_c(const int quarters[]);
void blurImage_c();
void cropImage_c(const int & x,const int & y,const int & l,const int & w);
void skewImageRight_c(const double &degree);
void skewImageUp_c(const double &degree);


int main()
{
    initialize();
    loadImage();
    menu();
    return 0;
}


void initialize() {
    // Here we initialize the image to white.
    fill (image[0][0], image[0][0] + SIZE*SIZE*RGB, 255);
    fill (image2[0][0], image2[0][0] + SIZE*SIZE*RGB, 255);
    fill (image3[0][0], image3[0][0] + SIZE*SIZE*RGB, 255);
    cout << "Welcome our Dear User :) \n\n";
}
void menu() {
    // Here we print the menu and take the user's choice.
    string selection;
    cout << "Please select a filter to apply or 0 to exit:" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1.  Convert to Black and White" << endl;
    cout << "2.  Invert Filter" << endl;
    cout << "3.  Merge Filter" << endl;
    cout << "4.  Flip Image" << endl;
    cout << "5.  Darken and Lighten Image" << endl;
    cout << "6.  Rotate Image" << endl;
    cout << "7.  Detect Image Edges" << endl;
    cout << "8.  Enlarge Image" << endl;
    cout << "9.  Shrink Image" << endl;
    cout << "a.  Mirror 1/2 Image" << endl;
    cout << "b.  Shuffle Image" << endl;
    cout << "c.  Blur Image" << endl;
    cout << "d.  Crop Image" << endl;
    cout << "e.  Skew Image Right" << endl;
    cout << "f.  Skew Image Up" << endl;
    cout << "s.  Save the image to a file" << endl;
    cout << "0.  Exit" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter your choice: ";    cin >> selection;
    cout << endl;

    if (selection == "0" || selection == "1" || selection == "2" || selection == "3" || selection == "4" || selection == "5" || selection == "6" || selection == "7" || selection == "8" || selection == "9")
        menu1(selection);
    else if (selection == "a" || selection == "b" || selection == "c" || selection == "d" || selection == "e" || selection == "f" || selection == "s")
        menu2(selection);
    else {
        int anns;
        cout << "Invalid choice, Please press 0 to exit or 1 to choose again from the menu: ";
        cin >> anns;
        cout << endl;
        if (anns == 0) {
            cout << "Thank you for using our program :)" << endl;
            return;
        } else if (anns == 1) {
            menu();
        }
    }
}
void menu1(string & s) {
    // Here we take the user's choice (ranging from 0-9) and apply the filter on the image.
    string choice;
    int selection = stoi(s);
    switch (selection) {
        case 0:
            // Exit
            cout << "Thank you for using our program :)" << endl;
            break;
        case 1:
            // Convert to Black and White
            convertToGrayscale_c();
            blackWhiteImage_c();
            saveImage();
            break;
        case 2:
            // Invert Filter
            invertImage_c();
            saveImage();
            break;
        case 3:
            // Merge Filter
            mergedImageLoad_c();
            mergeImage_c();
            saveImage3_c();
            break;
        case 4:
            // Flip Image
            char ans;
            cout << "Flip (h)orizontally or (v)ertically or (b)oth?\t";
            cin >> ans;
            cout << endl;
            if (ans == 'h')
                flipImageHorizontally_c();
            else if (ans == 'v')
                flipImageVertically_c();
            else if (ans == 'b')
                flipVerticalHorizontal_c();
            saveImage3_c();
            break;
        case 5:
            // Darken and Lighten Image
            char answer;
            cout << "Do you want to (d)arken or (l)ighten?\t";
            cin >> answer;
            cout << endl;
            if (answer == 'd')
                darkenImage_c();
            else if (answer == 'l')
                lightenImage_c();
            saveImage();
            break;
        case 6:
            // Rotate Image
            int answe;
            cout << "Rotate (90), (180) or (360) degrees?\t";
            cin >> answe;
            cout << endl;
            if (answe == 90)
                rotate90_c();
            else if (answe == 180)
                rotate180_c();
            else if (answe == 360)
                rotate360_c();
            saveImage3_c();
            break;
        case 7:
            // Detect Image Edges
            detectImageEdges_c();
            saveImage3_c();
            break;
        case 8:
            // Enlarge Image
            cout << "Which quarter to enlarge 1, 2, 3 or 4?\t";
            cin >> choice;
            if(stoi(choice) >=1 && stoi(choice) <=4){
                enlargeImage_c(choice), saveImage3_c();
                break;}
            else {cout <<"Invalid number!\n";menu();}
        case 9:
            // Shrink Image
            cout << "Shrink to (1/2), (1/3) or (1/4)?\t";
            cin >> choice;
            shrinkImage_c(choice);
            saveImage3_c();
            break;
        default:
            int anns;
            cout << "Invalid choice, Please press 0 to exit or 1 to choose again from the menu: ";
            cin >> anns;
            cout << endl;
            if (anns == 0) {
                cout << "Thank you for using our program :)" << endl;
                break;
            } else if (anns == 1) {
                menu();
            }
    }
}
void menu2(string & s) {
    // Here we take the user's choice (ranging from a-f,s) and apply the filter on the image.
    if (s == "a") {
        // Mirror 1/2 Image
        char direction;
        cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\t";
        cin >> direction;
        cout << endl;
        if (direction == 'l' || direction == 'r' || direction == 'u' || direction == 'd') {
            mirrorHalfImage_c(direction), saveImage3_c();
        }else {
            cout << "Invalid direction!\n";
            menu();
        }
    }else if (s == "b") {
        // Shuffle Image
        int quarters[4];
        cout << "New order of quarters ?\t";
        cin >> quarters[0] >> quarters[1] >> quarters[2] >> quarters[3]; cout << endl;
        shuffleImage_c(quarters);
        saveImage3_c();
    }else if (s == "c") {
        // Blur Image
        blurImage_c();
        saveImage3_c();
    }else if (s == "d") {
        // Crop Image
        int x, y, l, w;
        cout << "Please enter x y l w: \t";
        cin >> x >> y >> l >> w; cout << endl;
        cropImage_c(x, y, l, w);
        saveImage3_c();
    }else if (s == "e") {
        // Skew Image Up
        double degree;
        cout << "Please enter degree to skew right: \t";
        cin >> degree; cout << endl;
        skewImageRight_c(degree);
        saveImage3_c();
    }else if (s == "f") {
        // Skew Image Right
        cout << "Please enter degree to skew Up: \t";
        double degree;
        cin >> degree; cout << endl;
        skewImageUp_c(degree);
        saveImage3_c();
    }else if (s == "s") {
        // Save the image to a file
        saveImage();
    }else {
        int anns;
        cout << "Invalid choice, Please press 0 to exit or 1 to choose again from the menu: ";
        cin >> anns;
        cout << endl;
        if (anns == 0) {
            cout << "Thank you for using our program :)" << endl;
        }
        else if (anns == 1) {
            menu();
        }
    }
}
//_________________________________________
void loadImage() {
    // Here we load the image from the user's input.
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    cout << endl;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
//_________________________________________
void saveImage() {
    // Here we save the image to the user's input.
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
//_________________________________________
void convertToGrayscale_c() {
    // Here we convert the image to grayscale by using the formula.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            unsigned char togray = static_cast<unsigned char>(
                    0.299 * image[i][j][0] + 0.587 * image[i][j][1] + 0.114 * image[i][j][2]
            );
            image[i][j][0] = togray;
            image[i][j][1] = togray;
            image[i][j][2] = togray;
        }
    }
}
void blackWhiteImage_c() {
    // Here we convert the image to black and white by checking if the pixel value is greater than 127, we assign the pixels to white.
    // if the pixel value is less than 127, we assign the pixels to black.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            unsigned char togray = image[i][j][0]; // Assuming it's already grayscale
            if (togray > 127) {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }else{
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }
    }
}
void invertImage_c() {
    // Here we invert the image by subtracting each pixel from 255.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++) {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}
void mergedImageLoad_c() {
    // Here we load the image from the user's input.
    char imageFileName[100];

    // Get RGB image file name
    cout << "Enter the the name of the second image: ";
    cin >> imageFileName;
    cout << endl;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);
}
void mergeImage_c() {
    // Here we merge the image by taking the average of the two images.
    for(int i = 0; i < SIZE; i++)
        for (int j = 0 ; j < SIZE; j++)
        {
            image3[i][j][0] = (image[i][j][0]+image2[i][j][0])/2;
            image3[i][j][1] = (image[i][j][1]+image2[i][j][1])/2;
            image3[i][j][2] = (image[i][j][2]+image2[i][j][2])/2;
        }
}
void saveImage3_c() {
    // Here we save the image to the user's input.
    char imageFileName[100];

    // Get RGB image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image3);
}
void flipImageHorizontally_c() {
    //Here we flip the given image horizontally by following a simple logic,
    //we will access the columns in a reversed order instead of rows.
    for(int i =SIZE-1; i >=0;i--) {
        for(int j =0; j < SIZE;j++){
            image3[i][j][0] = image[i][SIZE-1-j][0];
            image3[i][j][1] = image[i][SIZE-1-j][1];
            image3[i][j][2] = image[i][SIZE-1-j][2];
        }
    }
}
void flipImageVertically_c() {
    //Here we flip the given image vertically by following a simple logic,
    //we just need to access the rows in a reversed order with the first for loop's value.
    for(int i =0; i <SIZE;i++) {
        for(int j =SIZE-1; j >=0;j--){
            image3[i][j][0] = image[SIZE -1 -i][j][0];
            image3[i][j][1] = image[SIZE -1 -i][j][1];
            image3[i][j][2] = image[SIZE -1 -i][j][2];
        }
    }
}
void flipVerticalHorizontal_c() {
    //Here we flip the given image vertically and horizontally by following a simple logic,
    //we just need to access the rows and columns in a reversed order with the first and second for loop's value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j][0] = image[SIZE-i-1][SIZE-j-1][0];
            image3[i][j][1] = image[SIZE-i-1][SIZE-j-1][1];
            image3[i][j][2] = image[SIZE-i-1][SIZE-j-1][2];

        }
    }
}
void darkenImage_c() {
    //Here we darken the image by subtracting 100 bits from every pixel ,but we have a minimum of 0 bits ,so we check if the value is less than 0
    // if it is then we assign the value to 0.
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                if (image[i][j][k] - 100 < 0) { image[i][j][k] = 0; }
                else { image[i][j][k] = image[i][j][k] - 100; }
            }
        }
    }
}
void lightenImage_c() {
    // Here we lighten the image by adding 100 bits to every pixel ,but we have a maximum of 255 bits ,so we check if the value is greater than 255
    // if it is then we assign the value to 255.
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                if (image[i][j][k] + 100 > 255) { image[i][j][k] = 255; }
                else { image[i][j][k] = image[i][j][k] + 100; }
            }
        }
    }
}
void rotate90_c() {
    //Here we rotate the given image 90 degrees clockwise by following a simple logic,
    //we just need to access the rows and columns in a reversed order with the first and second for loop's value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j][0] = image[SIZE-j-1][i][0];
            image3[i][j][1] = image[SIZE-j-1][i][1];
            image3[i][j][2] = image[SIZE-j-1][i][2];
        }
    }
}
void rotate180_c() {
    //Here we rotate by 180 degrees by flipping the given image vertically and horizontally by following a simple logic,
    //we just need to access the rows and columns in a reversed order with the first and second for loop's value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j][0] = image[SIZE-i-1][SIZE-j-1][0];
            image3[i][j][1] = image[SIZE-i-1][SIZE-j-1][1];
            image3[i][j][2] = image[SIZE-i-1][SIZE-j-1][2];
        }
    }
}
void rotate360_c() {
    // Here we rotate the image by 360 degrees by copying the image to the new image as 360 degrees is the same as 0 degrees rotation.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j][0] = image[i][j][0];
            image3[i][j][1] = image[i][j][1];
            image3[i][j][2] = image[i][j][2];
        }
    }
}
void detectImageEdges_c() {
    // Here we detect the edges of the image by using the sobel operator.
    // We use the min function to make sure that the pixel value doesn't go below 0.
    int kernelX[3][3] = {{-1, 0, 1},
                         {-2, 0, 2},
                         {-1, 0, 1}};
    int kernelY[3][3] = {{-1, -2, -1},
                         {0,  0,  0},
                         {1,  2,  1}};
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int gradX = 0;
            int gradY = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    gradX += image[i + k][j + l][0] * kernelX[k + 1][l + 1];
                    gradY += image[i + k][j + l][0] * kernelY[k + 1][l + 1];
                }
            }
            int size1 = sqrt(gradX * gradX + gradY * gradY);
            if (size1 > 255) size1 = 255;
            if (size1 < 0) size1 = 0;
            image3[i][j][0] = size1;
            image3[i][j][1] = size1;
            image3[i][j][2] = size1;
        }
    }
}
void enlargeImage_c(const string &quarter) {
    // Here we enlarge a specific quarter of the image by copying the pixels to the new image.
    int l_start, k_start, val = stoi(quarter);
    l_start = (val > 2 ? 128 : 0);
    k_start = (val % 2 == 0 ? 128 : 0);
    for (int i = 0, l = l_start, p = 2; i < SIZE; i++) {
        for (int j = 0, k = k_start, p2 = 0; j < SIZE; j++) {
            for (int m = 0; m < RGB; m++) {
                image3[i][j][m] = image[l][k][m];
            }
            if (!p2) k++, p2 = 1;
            else p2--;
        }
        if (!p) l++, p = 1;
        else p--;
    }
}
void shrinkImage_c(const string &shrink_by) {
    // Here we shrink the image by 2,3,4 times.
    string last_char = shrink_by.substr(shrink_by.length() - 1, 1);
    int shrink = stoi(last_char);
    int new_size = SIZE / shrink;
    for (int i = 0, l = 0; i < new_size; i++, l += shrink) {
        for (int j = 0, k = 0; j < new_size; j++, k += shrink) {
            for (int m = 0; m < RGB; m++) {
                image3[i][j][m] = image[l][k][m];
            }
        }
    }
}
void mirrorHalfImage_c(const char & direction) {
    // Here we mirror the image horizontally or vertically.
    if(direction == 'l') {
        int add = 1, k=0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(j == SIZE/2)add=0;
                if(add)k++;
                else k--;
                if(!add && !k)add=1;
                image3[i][j][0] = image[i][k][0];
                image3[i][j][1] = image[i][k][1];
                image3[i][j][2] = image[i][k][2];
            }
        }
    }
    else if(direction == 'r') {
        int k = 255, minus = 1;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(j == SIZE/2)minus=0;
                if(minus)k--;
                else k++;
                if(!minus && k == 255)minus=1;
                image3[i][j][0] = image[i][k][0];
                image3[i][j][1] = image[i][k][1];
                image3[i][j][2] = image[i][k][2];
            }
        }
    }
    else if(direction == 'u') {
        int add = 1, l = 0;
        for(int i = 0; i < SIZE ; i++) {
            if(i == SIZE/2)add=0;
            if(add)l++;
            else l--;
            if(!add && !l)add=1;
            for(int j = 0; j < SIZE; j++) {
                image3[i][j][0] = image[l][j][0];
                image3[i][j][1] = image[l][j][1];
                image3[i][j][2] = image[l][j][2];
            }
        }
    }else{
        int l = 255, minus = 1;
        for(int i = 0; i < SIZE; i++) {
            if(i == SIZE/2)minus=0;
            if(minus)l--;
            else l++;
            if(!minus && l == 255)minus=1;
            for(int j = 0; j < SIZE; j++) {
                image3[i][j][0] = image[l][j][0];
                image3[i][j][1] = image[l][j][1];
                image3[i][j][2] = image[l][j][2];
            }
        }
    }
}
void shuffleImage_c(const int quarters[]) {
    // Here we shuffle the image by copying the pixels of a quarter to the new image in a specific order.
    for(int i =0, start = (quarters[0] >2?128:0); i < SIZE/2;i++, start ++) {
        for(int j =0, start2 = (quarters[0] %2 ==0?128:0); j <SIZE/2;j++, start2 ++) {
            image3[i][j][0] = image[start][start2][0];
            image3[i][j][1] = image[start][start2][1];
            image3[i][j][2] = image[start][start2][2];
        }
    }
    for(int i =0, start = (quarters[1] >2?128:0); i < SIZE/2;i++, start ++) {
        for(int j =128, start2 = (quarters[1] %2 ==0?128:0); j <SIZE;j++, start2 ++) {
            image3[i][j][0] = image[start][start2][0];
            image3[i][j][1] = image[start][start2][1];
            image3[i][j][2] = image[start][start2][2];
        }
    }
    for(int i =128, start = (quarters[2] >2?128:0); i < SIZE;i++, start ++) {
        for(int j =0, start2 = (quarters[2] %2 ==0?128:0); j <SIZE/2;j++, start2 ++) {
            image3[i][j][0] = image[start][start2][0];
            image3[i][j][1] = image[start][start2][1];
            image3[i][j][2] = image[start][start2][2];
        }
    }
    for(int i =128, start = (quarters[3] >2?128:0); i < SIZE;i++, start ++) {
        for(int j =128, start2 = (quarters[3] %2 ==0?128:0); j <SIZE;j++, start2 ++) {
            image3[i][j][0] = image[start][start2][0];
            image3[i][j][1] = image[start][start2][1];
            image3[i][j][2] = image[start][start2][2];
        }
    }
}
void blurImage_c() {
    // Here we blur the image by using the rounding algorithm.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image3[i][j][k] = round(image[i][j][k] +
                                        (i - 2 >= 0 ? image[i - 2][j][k] : 0) +
                                        (i - 1 >= 0 ? image[i - 1][j][k] : 0) +
                                        (i + 1 < SIZE ? image[i + 1][j][k] : 0) +
                                        (i + 2 < SIZE ? image[i + 2][j][k] : 0) +
                                        (j - 2 >= 0 ? image[i][j - 2][k] : 0) +
                                        (j - 1 >= 0 ? image[i][j - 1][k] : 0) +
                                        (j + 1 < SIZE ? image[i][j + 1][k] : 0) +
                                        (j + 2 < SIZE ? image[i][j + 2][k] : 0) +
                                        (i - 2 >= 0 && j - 2 >= 0 ? image[i - 2][j - 2][k] : 0) +
                                        (i - 2 >= 0 && j - 1 >= 0 ? image[i - 2][j - 1][k] : 0) +
                                        (i - 2 >= 0 && j + 1 < SIZE ? image[i - 2][j + 1][k] : 0) +
                                        (i - 2 >= 0 && j + 2 < SIZE ? image[i - 2][j + 2][k] : 0) +
                                        (i - 1 >= 0 && j - 2 >= 0 ? image[i - 1][j - 2][k] : 0) +
                                        (i - 1 >= 0 && j + 2 < SIZE ? image[i - 1][j + 2][k] : 0) +
                                        (i + 1 < SIZE && j - 2 >= 0 ? image[i + 1][j - 2][k] : 0) +
                                        (i + 1 < SIZE && j + 2 < SIZE ? image[i + 1][j + 2][k] : 0) +
                                        (i + 2 < SIZE && j - 2 >= 0 ? image[i + 2][j - 2][k] : 0) +
                                        (i + 2 < SIZE && j - 1 >= 0 ? image[i + 2][j - 1][k] : 0) +
                                        (i + 2 < SIZE && j + 1 < SIZE ? image[i + 2][j + 1][k] : 0) +
                                        (i + 2 < SIZE && j + 2 < SIZE ? image[i + 2][j + 2][k] : 0)
                )/25;
            }
        }
    }
}
void cropImage_c(const int & x,const int & y,const int & l,const int & w) {
    // Here we crop the image by taking the user's input.
    for (int i = x; i < x+l; i++) {
        for (int j = y; j < y+w; j++) {
            image3[i][j][0] = image[i][j][0];
            image3[i][j][1] = image[i][j][1];
            image3[i][j][2] = image[i][j][2];
        }
    }
}
void skewImageRight_c(const double &degree) {
    // Here we skew the image to the right by taking the user's input(degree).
    const double pi = M_PI;
    auto new_size = 256 /(1+1/(tan(degree * pi /180)));
    int jump = floor(SIZE/ new_size);
    auto new_start = floor(SIZE - new_size);
    auto move = new_start / SIZE, copy = new_start;
    double white_img;
    for(int i = 0; i < SIZE; i++) {
        for(int j =0, k = 0; j < new_size; j++, k += jump) {
            for (int l = 0; l < RGB; l++) {
                image2[i][j][l] = image[i][k][l];
            }
        }
    }
    for(int i =0, l = int(new_start); i < SIZE;i++) {
        for(int j = 0 ; j <new_size;j++) {
            for (int k = 0; k < RGB; k++) {
                image3[i][j+int(new_start)][k] = image2[i][j][k];
                white_img = j + new_start;
            }
        }
        new_start-=move;
    }
}
void skewImageUp_c(const double &degree) {
    // Here we skew the image up by taking the user's input(degree).
    const double pi = M_PI;
    auto new_size = 256 /(1+1/(tan(degree * pi /180)));
    int jump = floor(SIZE/ new_size);
    auto new_start = floor(SIZE - new_size);
    auto move = new_start / SIZE, copy = new_start;

    for(int i = 0, l = 0; i < new_size; i++, l += jump) {
        for(int j =0; j < SIZE; j++) {
            image2[i][j][0] = image[l][j][0];
            image2[i][j][1] = image[l][j][1];
            image2[i][j][2] = image[l][j][2];
        }
    }
    for(int i =0; i < new_size;i++) {
        for(int j = 0 ; j < SIZE;j++) {
            image3[i+int(new_start)][j][0]= image2[i][j][0];
            image3[i+int(new_start)][j][1]= image2[i][j][1];
            image3[i+int(new_start)][j][2]= image2[i][j][2];
            new_start-=move;
        }
        new_start = copy;
    }
}
