#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>

#define ORIG_WHITE '0'
#define ORIG_BLACK '1'
#define NEW_WHITE '2'
#define NEW_BLACK '3'
#define NEW_HOLE '4'


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

using namespace std;
bool is_bound(int i, int j, int height, int width){
    return i>=0 && j>=0 && j<width && i<height;
}
char get_letter(int hole_num){

    switch (hole_num) {
        case 0:
            return 'W';
        case 1:
            return 'A';
        case 2:
            return 'K';
        case 3:
            return 'J';
        case 4:
            return 'S';
        case 5:
            return 'D';
    }
}
string char2bin(char c) {
    switch (c) {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'a':
            return "1010";
        case 'b':
            return "1011";
        case 'c':
            return "1100";
        case 'd':
            return "1101";
        case 'e':
            return "1110";
        case 'f':
            return "1111";
        default:
            return "0";
    }
}
void paint_BG(vector<string>& image, int i, int j, int height, int width){
    if (!is_bound(i,j,height,width)) return;
    if(image[i][j]== ORIG_WHITE ){
        image[i][j]=NEW_WHITE;
    } else {
        return;
    }
    paint_BG(image,i+1,j,height,width);
    paint_BG(image,i-1,j,height,width);
    paint_BG(image,i,j+1,height,width);
    paint_BG(image,i,j-1,height,width);
}
void scan_hole(vector<string>& image, int i, int j, int height, int width){
    if (!is_bound(i,j,height,width)) return;
    if (image[i][j] == NEW_BLACK || image[i][j] == NEW_HOLE) return;
    if (image[i][j]==ORIG_WHITE){
        image[i][j]=NEW_HOLE;
        scan_hole(image,i+1,j,height,width);
        scan_hole(image,i-1,j,height,width);
        scan_hole(image,i,j+1,height,width);
        scan_hole(image,i,j-1,height,width);
    }
}
int scan_black(vector<string>& image, int i, int j, int height, int width) {
    int counter = 0;
    if (!is_bound(i, j, height, width)) return 0;
    if (image[i][j] == NEW_BLACK || image[i][j] == NEW_WHITE || image[i][j] == NEW_HOLE) return 0;
    if (image[i][j] == ORIG_BLACK){
        image[i][j] = NEW_BLACK;
    }
    if (image[i][j] == ORIG_WHITE){
        counter++;
        scan_hole(image,i,j,height,width);
    }
    counter += scan_black(image,i+1,j,height,width);
    counter += scan_black(image,i-1,j,height,width);
    counter += scan_black(image,i,j+1,height,width);
    counter += scan_black(image,i,j-1,height,width);
    return counter;
}

int main() {
    int width, height;
    int m=0;
    while (1) {
        char temp;
        cin >> height >> width;
        vector<string> image (height);

        if (height == 0 && width == 0) break;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cin >> temp;
                image[i] += char2bin(temp);
            }
        }
        /*for (int i = 0; i < height; i++) {
            for (int j = 0; j < width*4; j++) {
                cout<<image[i][j];
            }
            cout<<endl;
        }*/
        int hole_num=0;
        vector<char> out;
        char c,d;
        for(int i=0;i<height;i++){
            c = image[i][0];
            d = image[i][width*4-1];
            if(c == ORIG_WHITE){
                paint_BG(image, i, 0, height, width * 4);
            }
            if(d == ORIG_WHITE){
                paint_BG(image, i, width*4-1, height, width * 4);
            }
        }
        for(int j=0; j<width*4;j++){
            c = image[0][j];
            d = image[height-1][j];
            if(c == ORIG_WHITE){
                paint_BG(image, 0, j, height, width * 4);
            }
            if(d == ORIG_WHITE){
                paint_BG(image, height-1, j, height, width * 4);
            }
        }

        /*for (int i = 0; i < height; i++) {
            for (int j = 0; j < width*4; j++) {
                cout<<image[i][j];
            }
            cout<<endl;
        }*/
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width * 4; ++j) {
                c = image[i][j];
                if(c == ORIG_BLACK){
                    hole_num = scan_black(image,i,j,height,width*4);
                    if(hole_num >= 0 && hole_num <= 5){
                        out.push_back(get_letter(hole_num));
                    }
                }
            }
        }
        sort(out.begin(), out.end());
        m++;
        cout<<"Case "<<m<<": ";
        for(int k =0; k<out.size();k++){
            cout<<out[k];
        }
        cout<<endl;
    }
    return 0;
}