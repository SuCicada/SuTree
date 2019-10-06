#include <graphics.h> 

int    GraphDriver;     /* The Graphics device driver       */
int    GraphMode;       /* The Graphics mode value      */
int    MaxX, MaxY;      /* The maximum resolution of the screen */
int    MaxColors;       

void Initialize(){
    GraphDriver = DETECT; 
    registerbgidriver(EGAVGA_driver);/*建立独立图形运行程序*/ 
    initgraph(&gdriver, &gmode, "");/*图形初始化*/ 

    ErrorCode = graphresult();        /* Read result of initialization*/
    if( ErrorCode != grOk ){      /* Error occured during init    */
        printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
        exit( 1 );
    }
    getpalette( &palette );
    MaxColors = getmaxcolor() + 1;    /* Read maximum number of colors*/
    MaxX = getmaxx();
    MaxY = getmaxy();         /* Read size of screen      */

}

void MainWindow( char *header )
{
  int height;

  cleardevice();            /* Clear graphics screen    */
  setcolor( MaxColors - 1 );        /* Set current color to white   */
  setviewport( 0, 0, MaxX, MaxY, 1 );   /* Open port to full screen */

  height = textheight( "H" );           /* Get basic text height        */

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  outtextxy( MaxX/2, 2, header );
  setviewport( 0, height+4, MaxX, MaxY-(height+4), 1 );
  DrawBorder();
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}
main(){
    Initialize();
    DrawPanle();

}