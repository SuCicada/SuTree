#include <graphics.h> 

void fun(){
    int gdriver, gmode; 
    detectgraph(&gdriver, &gmode);     /*自动测试硬件*/ 
    printf("the graphics driver is %d, mode is %d\n", gdriver, gmode);   /*输出测试结果*/ 
    getch(); 
    initgraph(&gdriver, &gmode, ""); 
    /* 根据测试结果初始化图形*/ 
    bar3d(10, 10, 130, 250, 20, 1); 
    getch(); 
    closegraph(); 
    return 0; 
}

void fun1(){
    int gdriver=DETECT, gmode; 
    initgraph(&gdriver, &gmode, ""); 
    bar3d(10, 20, 3, 40, 50, 11); 
    getch(); 
    closegraph();
}
void fun2(){
    int gdriver=DETECT,gmode; 
    registerbgidriver(EGAVGA_driver); /*建立独立图形运行程序 */ 
    initgraph(&gdriver, &gmode,"dontcare"); 
    bar3d(50,50,250,150,20,1); 
    getch(); 
    closegraph(); 
}
void fun3(){ 
   int gdriver, gmode, i; 
   gdriver=DETECT; 
   registerbgidriver(EGAVGA_driver);/*建立独立图形运行程序*/ 
   initgraph(&gdriver, &gmode, "");/*图形初始化*/ 
   setbkcolor(0);        /*设置图形背景*/ 
   cleardevice(); 
   for(i=0; i<=15; i++) 
   { 
      setcolor(i);        /*设置不同作图色*/ 
      circle(320, 240, 20+i*10);     /*画半径不同的圆*/ 
      delay(1);         /*延迟100毫秒*/ 
   } 
   for(i=0; i<=15; i++) 
   { 
        setbkcolor(i%16);     /*设置不同背景色*/ 
        cleardevice(); 
        circle(320, 240, 20+i*10); 
        delay(1); 
   } 
   closegraph(); 
   return 0; 
} 
void fun4()
{ 
   int gdriver, gmode, i; 
   int arw[16]={200, 102, 300, 102, 300, 107, 330, 
     100, 300, 93, 300, 98, 200, 98, 200, 102}; 
   gdriver=DETECT; 
   registerbgidriver(EGAVGA_driver); 
   initgraph(&gdriver, &gmode, ""); 
   setbkcolor(BLUE); 
   cleardevice(); 
   setcolor(12);       /*设置作图颜色*/ 
   drawpoly(10, arw);   /*画一箭头*/ 
   getch(); 
   closegraph(); 
} 
void fun5(){
   int gdriver, gmode, i; 
   gdriver=DETECT; 
   registerbgidriver(EGAVGA_driver); 
   initgraph(&gdriver, &gmode, ""); 
   setbkcolor(BLUE); 
   cleardevice(); 
   setcolor(GREEN); 
   circle(320, 240, 98); 
   setlinestyle(0, 0, 1);   /*设置三点宽实线*/ 
   setcolor(2); 
   rectangle(220, 140, 420, 340); 
   setcolor(WHITE); 
   setlinestyle(4, 0xaaaa, 1);   /*设置一点宽用户定义线*/ 
   line(220, 240, 420, 240); 
   line(320, 140, 320, 340); 
   getch(); 
   closegraph(); 
}
void fun6(){
    char str[8]={0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff}; /*用户定义图模*/ 
    int gdriver,gmode,i; 
    struct fillsettingstype save; /*定义一个用来存储填充信息的结构变量*/ 
    gdriver=DETECT; 
    initgraph(&gdriver,&gmode,""); 
    setbkcolor(BLUE); 
    cleardevice(); 
    for(i=0;i<1;i++) 
    { 
        setcolor(i+3); 
        setfillstyle(i,2+i);      /* 设置填充类型 */ 
        bar(100,150,200,50);      /*画矩形并填充*/ 
        bar3d(300,100,500,200,70,1); /* 画长方体并填充*/ 
        pieslice(200, 300, 90, 180, 90);/*画扇形并填充*/ 
        sector(500,300,180,270,200,100);/*画椭圆扇形并填充*/ 
        delay(1);         /*延时1秒*/ 
     } 
    cleardevice(); 
    setcolor(14); 
    setfillpattern(str, RED); 
    bar(100,150,200,50); 
    bar3d(300,100,500,200,70,1); 
    pieslice(200,300,0,360,90); 
    sector(500,300,0,360,100,50); 
    getch(); 
    getfillsettings(&save);       /*获得用户定义的填充模式信息*/ 
    closegraph(); 
    clrscr(); 
    printf("The pattern is %d, The color of filling is %d", save.pattern, save.color);
    /*输出目前填充图模和颜色值*/ 
    getch();
}
void fun7(){
   int gdriver, gmode;
   struct fillsettingstype save; 
   gdriver=DETECT; 
   initgraph(&gdriver, &gmode, ""); 
   setbkcolor(BLUE); 
   cleardevice(); 
   getch();
   setcolor(LIGHTRED); 
   setlinestyle(0,0,3); 
   setfillstyle(1,14);           /*设置填充方式*/ 
   bar3d(100,200,400,350,200,1); /*画长方体并填充*/ 
   floodfill(450,300,LIGHTRED);  /*填充长方体另外两个面*/ 
   floodfill(250,150, LIGHTRED); 
    rectangle (450,400,500,450);    /*画一矩形*/ 
   floodfill(470,20, LIGHTRED); /*填充矩形*/ 
   getch(); 
   closegraph(); 
}
int main() 
{ 
    fun7();
} 