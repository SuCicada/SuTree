#include<graphics.h> 
int main() 
{ 
  int gdriver=DETECT,gmode; 
  registerbgidriver(EGAVGA_driver);
  initgraph( gdriver, gmode,""); 
  bar3d(50,50,250,150,20,1); 
  getch(); 
  closegraph(); 
  return 0; 
}