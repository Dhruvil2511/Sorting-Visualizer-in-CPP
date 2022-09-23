# Sorting-Visualizer-in-CPP

This Visualizer Project was a part of my 2nd Sem Project.
Visualizing using an ancient library called graphics.h which is 32bit library.
I could have choose better or newer library but the time was comparitevly less in order to learn concepts of newer library .
In order to run the program one need to have 32 bit gcc compiler (you can install DEV/C++).
To install graphics.h library and to add linker.

Follow the steps given below:
1) First install Dev C++ on your Machine.
2) Install Graphics.h library from given below drive and Extract the file
https://drive.google.com/drive/folders/1OzQDPPc5URGI0W8eZN1OH0ccX8118w3w?usp=sharing

3) After extracting you must see the following files
 ![image](https://user-images.githubusercontent.com/91490304/191970221-317c5623-fea2-4f65-8604-ed26ed920d6a.png)
4) Copy "graphics.h" and "winbgim.h" files to "include" folder of Devc++ directory.
   Default location is ("C:\Program Files (x86)\DevC++\MinGW\include\")
5) Copy "libbgi.a" to file to "lib" folder of DevC++ directory.
   Default location is ("C:\Program Files (x86)\DevC++\MinGW\lib\")
6)  Important : Select 32 bit release compiler from top of dev c++ (image shown below) 





	![image](https://user-images.githubusercontent.com/91490304/191972362-2817c8e5-40a6-416c-beb7-82b74afbade9.png)
		  	  
7) After selecting Goto:  Tools -> Compiler Option -> General -> "Add the following commands when calling the linker" 
8) copy the text below and paste there
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
9) Press OK 


NOTE:
-> The graphics.h will work only in the program saved in ".cpp" format.
To check the graphics.h is working or not
Create a new console application in ".cpp" format and copy the codes given below, paste it in the
file you created and click "Build and Run" button or click "F9" key from your keyboard..

```
#include<graphics.h>
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    circle(200,200,100);
    getch();
}
```
This results in following output:


![image](https://user-images.githubusercontent.com/91490304/191973629-ec8526f3-6e20-4e6c-8cbc-682d28c2cdac.png)



Cheers! Now You are ready to run the visualizer
