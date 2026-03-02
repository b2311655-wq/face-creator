#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function to draw the face based on user inputs
void drawFace(int eyePosX, int nosePosX, int nosePosY, int mouthPosX, int mouthPosY, int eyeSpacing, 
              char righteyeShape, char lefteyeShape, char noseShape, char mouthShape, 
              char rightearShape, char leftearShape) {
    // Create a 2D array for the face
    char face[10][20];

    // Initialize the face with spaces
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            face[i][j] = ' ';  // Fill the array with empty spaces
        }
    }

    // Draw side curves
    for (int i = 0; i < 9; i++) {
        // Left side curve
        if (i < 5) {
            face[i][0] = '/';
        } else {
            face[i][0] = '\\';
        }
        // Right side curve
        if (i < 5) {
            face[i][19] = '\\';
        } else {
            face[i][19] = '/';
        }
    }

    // Draw eyes
    if (eyePosX >= 0 && eyePosX < 10) {
        if (10 - eyeSpacing / 2 >= 0 && 10 - eyeSpacing / 2 < 20)
            face[eyePosX][10 - eyeSpacing / 2] = righteyeShape;
        if (10 + eyeSpacing / 2 >= 0 && 10 + eyeSpacing / 2 < 20)
            face[eyePosX][10 + eyeSpacing / 2] = lefteyeShape;
    }

    // Draw nose (Ensure it is only one character)
    if (nosePosX >= 0 && nosePosX < 10 && nosePosY >= 0 && nosePosY < 20)
        face[nosePosX][nosePosY] = noseShape;

    // Draw mouth
    for (int i = -2; i <= 2; i++) {
        if (mouthPosX >= 0 && mouthPosX < 10 && mouthPosY + i >= 0 && mouthPosY + i < 20)
            face[mouthPosX][mouthPosY + i] = mouthShape;
    }

    // Draw ears (Left and Right)
    if (eyePosX >= 0 && eyePosX < 10) {
        if (17 >= 0 && 17 < 20)
            face[eyePosX][17] = rightearShape;
        if (2 >= 0 && 2 < 20)
            face[eyePosX][2] = leftearShape;
    }

    // Print the face
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            cout << face[i][j];
        }
        cout << endl;
    }
}

// Function to check if the user input is valid
int errorCheck(int choice) {
    while (choice < 1 || choice > 3) {
        cout << "This is an invalid number. Please enter again (1, 2, or 3): ";
        cin >> choice;
    }
    return choice;
}

int main() {
    int eyePosX = 1;
    int nosePosX = 3;
    int nosePosY = 8;
    int mouthPosX = 6;
    int mouthPosY = 8;
    int eyeSpacing = 2;
    char righteyeShape, lefteyeShape, noseShape, mouthShape, rightearShape, leftearShape;

    int choice;

    // Get eye position
    cout << "Do you want eye position from the top to be (1: Up, 2: Middle, 3: Down): ";
    cin >> choice;
    choice = errorCheck(choice);
    eyePosX += (choice - 2);

    // Get nose position from the top
    cout << "Do you want nose position from the top to be (1: Up, 2: Middle, 3: Down): ";
    cin >> choice;
    choice = errorCheck(choice);
    nosePosX += (choice - 2);

    // Get nose position from the center
    cout << "Do you want nose position from the center to be (1: Right, 2: Center, 3: Left): ";
    cin >> choice;
    choice = errorCheck(choice);
    nosePosY += (choice - 2);

    // Get mouth position from the top
    cout << "Do you want mouth position from the top to be (1: Up, 2: Middle, 3: Down): ";
    cin >> choice;
    choice = errorCheck(choice);
    mouthPosX += (choice - 2);

    // Get mouth position from the center
    cout << "Do you want mouth position from the center to be (1: Center, 2: Right, 3: Left): ";
    cin >> choice;
    choice = errorCheck(choice);
    mouthPosY += (choice - 2);

    // Get eye spacing
    cout << "Do you want eye spacing to be (1: Narrow, 2: Normal, 3: Wide): ";
    cin >> choice;
    choice = errorCheck(choice);
    eyeSpacing += (choice - 2);

    // Get user inputs for the shapes of each part
    cout << "Enter the character to use for the right eye: ";
    cin >> righteyeShape;
    cout << "Enter the character to use for the left eye: ";
    cin >> lefteyeShape;
    cout << "Enter the character to use for the nose: ";
    cin >> noseShape;
    cout << "Enter the character to use for the mouth: ";
    cin >> mouthShape;
    cout << "Enter the character to use for the right ear: ";
    cin >> rightearShape;
    cout << "Enter the character to use for the left ear: ";
    cin >> leftearShape;

    // Draw the face with the provided characteristics
    drawFace(eyePosX, nosePosX, nosePosY, mouthPosX, mouthPosY, eyeSpacing, righteyeShape, 
             lefteyeShape, noseShape, mouthShape, rightearShape, leftearShape);

    return 0;
}