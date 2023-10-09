// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				imageModifier.cpp
// Last Modification Date:	7/10/2023
// Author1 and ID and Group:	Ahmed Niazi 20220452
// Author2 and ID and Group:	Omer Tarek 20220438
// Author3 and ID and Group:
// Teaching Assistant:
// Purpose: Apply a variety of filters on grayscale bmp images


#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
/*#include <vector>
#include <fstream>*/

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];


void loadImage();
void saveImage();
/*------------------*/
void menu();
void menu1(string & s);
void menu2(string & s);
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
void detectImageEdges();
void enlargeImage(const string &quarter);
void shrinkImage(const string& shrink_by);
void mirrorHalfImage(const char & direction);
void shuffleImage(const int quarters[]);
void blurImage();
void cropImage(int x, int y, int l, int w);
void skewImageRight();
void skewImageUp();


int main()
{
    cout << "Welcome our Dear User :) \n\n";
    loadImage();
    menu();
    return 0;
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
    cout << "-----Under Development-----" << endl;
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
    cout << "-----end-----" << endl;
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
// Here we take the user's choice (ranging from 0-9) and apply the filter on the image.
void menu1(string & s) {
    string choice;
    int selection = stoi(s);
    switch (selection) {
        case 0:
            // Exit
            cout << "Thank you for using our program :)" << endl;
            break;
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
            if (ans == 'h')
                flipImageHorizontally();
            else if (ans == 'v')
                flipImageVertically();
            else if (ans == 'b')
                flipVerticalHorizontal();
            saveImage3();
            break;
        case 5:
            // Darken and Lighten Image
            char answer;
            cout << "Do you want to (d)arken or (l)ighten?\t";
            cin >> answer;
            cout << endl;
            if (answer == 'd')
                darkenImage();
            else if (answer == 'l')
                lightenImage();
            saveImage();
            break;
        case 6:
            // Rotate Image
            int answe;
            cout << "Rotate (90), (180) or (360) degrees?\t";
            cin >> answe;
            cout << endl;
            if (answe == 90)
                rotate90();
            else if (answe == 180)
                rotate180();
            else if (answe == 360)
                rotate360();
            saveImage3();
            break;
        case 7:
            // Detect Image Edges
            detectImageEdges();
            saveImage();
            break;
        case 8:
            // Enlarge Image
            cout << "Which quarter to enlarge 1, 2, 3 or 4?\t";
            cin >> choice;
            if(stoi(choice) >=1 && stoi(choice) <=4){
                enlargeImage(choice), saveImage3();
                break;}
            else {cout <<"Invalid number!\n";menu();}
        case 9:
            // Shrink Image
            cout << "Shrink to (1/2), (1/3) or (1/4)?\t";
            cin >> choice;
            shrinkImage(choice);
            saveImage3();
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
            mirrorHalfImage(direction), saveImage3();
        }else {
            cout << "Invalid direction!\n";
            menu();
        }
    }else if (s == "b") {
        // Shuffle Image
        int quarters[4];
        cout << "New order of quarters ?\t";
        cin >> quarters[0] >> quarters[1] >> quarters[2] >> quarters[3]; cout << endl;
        shuffleImage(quarters);
        saveImage3();
    }else if (s == "c") {
        // Blur Image
        blurImage();
        saveImage3();
    }else if (s == "d") {
        // Crop Image
        int x, y, l, w;
        cout << "Please enter x y l w: \t";
        cin >> x >> y >> l >> w; cout << endl;
        cropImage(x, y, l, w);
        saveImage3();
    }else if (s == "e") {
        // Skew Image Right
        cout << "Under Development\n";
        menu();
    }else if (s == "f") {
        // Skew Image Up
        cout << "Under Development\n";
        menu();
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
    readGSBMP(imageFileName, image);
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
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void blackWhiteImage() {
    // Here we reassign every pixel to either 0 or 255
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
    // Here we invert every pixel by subtracting a 100 from it and placing the value in an abs function to get the absolute value
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image [i][j] = abs(image[i][j]-100);
        }
    }
}
void mergeImageLoad() {
    char imageFileName[100];
    // Same as loadImage() but for the second image
    // Get gray scale image file name to merge
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to the merge image .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}
void mergeImage(){
    // Here we merge the two images by adding the values of the pixels of the two images and dividing by 2
    for(int i =0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image3[i][j] = (image[i][j] + image2[i][j])/2;
        }
    }
}
void saveImage3() {
    // Same as saveImage() but for the third image
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}
void flipImageHorizontally() {
    //Here we flip the given image horizontally by following a simple logic,
    //we will access the columns in a reversed order instead of rows.
    for(int i =SIZE-1; i >=0;i--) {
        for(int j =0; j < SIZE;j++){
            image3[i][j] = image[i][SIZE-1-j];
        }
    }
}
void flipImageVertically() {
    //Here we flip the given image vertically by following a simple logic,
    //we just need to access the rows in a reversed order with the first for loop's value.
    for(int i =0; i <SIZE;i++) {
        for(int j =SIZE-1; j >=0;j--){
            image3[i][j] = image[SIZE -1 -i][j];
        }
    }
}
void flipVerticalHorizontal(){
    //Here we flip the given image vertically and horizontally by following a simple logic,
    //we just need to access the rows and columns in a reversed order with the first and second for loop's value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j] = image[SIZE-i-1][SIZE-j-1];
        }
    }
}
void darkenImage() {
    // Here we darken the image by subtracting 100 bits from every pixel ,but we have a minimum of 0 bits ,so we check if the value is less than 0
    // if it is then we assign the value to 0.
    for(int i =0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++){
            if(image[i][j] -100 <0) {image[i][j] =0;}
            else {image[i][j] -= 100;}
        }
    }
}
void lightenImage() {
    // Here we lighten the image by adding 100 bits to every pixel ,but we have a maximum of 255 bits ,so we check if the value is greater than 255
    // if it is then we assign the value to 255.
    for(int i =0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(image[i][j] + 100 > 255) { image[i][j] = 255; }
            else { image[i][j] += 100; }
        }
    }
}
void rotate90(){
    // Here we rotate the image by 90 degrees by applying a simple logic,
    // To achieve rotation by 90 degrees, we need to access the first image flipped vertically
    // then we copy each row from the original flipped image to each column of our new image.
    int k =0, l=0;
    for(int i =SIZE; i >= SIZE/256-1; i--) {
        for(int j = SIZE/256-1; j < SIZE; j++) {
            image3[l][k] = image[i][j];
            l++;
        }
        l =0;
        k++;
    }
}
void rotate180(){
    // Here we rotate the image by 180 degrees by applying a simple logic,
    // we just need to access the rows and columns in a reversed order with the first and second for loop's value. (same as flipVerticalHorizontal())
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image3[i][j] = image[SIZE-i-1][SIZE-j-1];
        }
    }
}
void rotate360() {
    // Here we rotate the image by 360 degrees by copying the image to the new image as 360 degrees is the same as 0 degrees rotation.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = image[i][j];
        }
    }
}
void detectImageEdges() {
    for(int i = 1; i < SIZE-1;i++) {
        for(int j =1; j < SIZE-1; j++) {
            if(abs(image[i-1][j]-image[i][j])>=40)image[i-1][j]=0;
            else if(abs(image[i][j-1]-image[i][j])>=40)image[i][j]=0;
        }
    }
    for(auto & i : image) {
        for(int j = 0; j < SIZE; j++) {
            if(i[j] || (j+1 <SIZE && i[j] == i[j+1]))i[j] =255;
        }
    }
}
void enlargeImage(const string &quarter) {
    int l_start, k_start, val = stoi(quarter);
    l_start = (val >2?128:0);
    k_start = (val % 2 == 0?128:0);
    for (int i = 0, l = l_start, p = 2; i < SIZE; i++) {
        for (int j = 0, k = k_start, p2 = 0; j < SIZE; j++) {
            image3[i][j] = image[l][k];

            if (!p2) k++,p2 = 1;
            else p2--;

        }

        if (!p) l++,p = 1;
        else p--;

    }
}
void shrinkImage(const string& shrink_by){
    string last_char = shrink_by.substr(shrink_by.length()-1, 1);

    float shrink = stoi(last_char);

    int new_size = SIZE/shrink;
    for(int i =0, l = 0; i < new_size; i++, l += shrink)
    {
        for(int j = 0, k = 0; j < new_size; j++, k+= shrink)
        {
            image3[i][j] = image[l][k];
        }
    }
}
void mirrorHalfImage(const char & direction) {
    if(direction == 'l')
    {
        int add = 1, k=0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(j == SIZE/2)add=0;
                if(add)k++;
                else k--;
                if(!add && !k)add=1;
                image3[i][j] = image[i][k];
            }
        }
    }
    else if(direction == 'r')
    {
        int k = 255, minus = 1;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(j == SIZE/2)minus=0;
                if(minus)k--;
                else k++;
                if(!minus && k == 255)minus=1;
                image3[i][j] = image[i][k];
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
                image3[i][j] = image[l][j];
            }
        }
    }
    else
    {
        int l = 255, minus = 1;
        for(int i = 0; i < SIZE; i++) {
            if(i == SIZE/2)minus=0;
            if(minus)l--;
            else l++;
            if(!minus && l == 255)minus=1;
            for(int j = 0; j < SIZE; j++) {
                image3[i][j] = image[l][j];
            }
        }
    }
}
void shuffleImage(const int quarters[]) {
    for(int i =0, start = (quarters[0] >2?128:0); i < SIZE/2;i++, start ++) {
        for(int j =0, start2 = (quarters[0] %2 ==0?128:0); j <SIZE/2;j++, start2 ++) {
            image3[i][j] = image[start][start2];
        }
    }
    for(int i =0, start = (quarters[1] >2?128:0); i < SIZE/2;i++, start ++) {
        for(int j =128, start2 = (quarters[1] %2 ==0?128:0); j <SIZE;j++, start2 ++) {
            image3[i][j] = image[start][start2];
        }
    }
    for(int i =128, start = (quarters[2] >2?128:0); i < SIZE;i++, start ++) {
        for(int j =0, start2 = (quarters[2] %2 ==0?128:0); j <SIZE/2;j++, start2 ++) {
            image3[i][j] = image[start][start2];
        }
    }
    for(int i =128, start = (quarters[3] >2?128:0); i < SIZE;i++, start ++) {
        for(int j =128, start2 = (quarters[3] %2 ==0?128:0); j <SIZE;j++, start2 ++) {
            image3[i][j] = image[start][start2];
        }
    }
}
void blurImage() {
    for(int i =0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image3[i][j] = (image[i][j] + image[i+3][j] + image[i-3][j] + image[i][j+3] + image[i][j-3] + image[i+2][j+2] + image[i-2][j-2])/7;
        }
    }
}
void cropImage(int x, int y, int l, int w) {
    for (int i = x; i < x+l; i++) {
        for (int j = y; j < y+w; j++) {
            image3[i][j] = image[i][j];
        }
    }
}
//Under Development
void skewImageRight() {
    cout << "Under Development\n";
    menu();
}
void skewImageUp() {
    cout << "Under Development\n";
    menu();
}
