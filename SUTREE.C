#include <graphics.h>
#include <stdarg.h>
#include <math.h>
int    GraphDriver;     /* The Graphics device driver       */
int    GraphMode;       /* The Graphics mode value      */
int    MaxX, MaxY;      /* The maximum resolution of the screen */
int    MaxColors;
int    ErrorCode;		/* Reports any graphics errors		*/
struct palettetype palette;		/* Used to read palette info	*/

/* 图像区域 */
typedef struct {
    int x;
    int y;
    int h;
    int w;
    int left;
    int top;
    int right;
    int bottom;
}Area;

void Initialize();
void DrawBorder(void);
void MainWindow( char *header );
void StatusLine(char *msg );
int gprintf( int *xloc, int *yloc, char *fmt, ... );
void Exit();

Area treeArea,textArea,inputArea;
void setArea(Area *area,int x,int y,int w,int h){
    area->x = x;
    area->y = y;
    area->h = h;
    area->w = w;
    area->left = area->x;
    area->top = area->y;
    area->right = area->x + area->w;
    area->bottom = area->y + area->h;
}
void setviewArea(Area *area,int i){
    setviewport( area->x, area->y, area->right, area->bottom , i);
}
void Initialize(){
    int height;

    GraphDriver = DETECT;
    registerbgidriver(EGAVGA_driver);/*建立独立图形运行程序*/
    initgraph(&GraphDriver, &GraphMode, "");/*图形初始化*/

    ErrorCode = graphresult();        /* Read result of initialization*/
    if( ErrorCode != grOk ){      /* Error occured during init    */
        printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
        exit( 1 );
    }
    getpalette( &palette );
    MaxColors = getmaxcolor() + 1;    /* Read maximum number of colors*/
    MaxX = getmaxx();
    MaxY = getmaxy();         /* Read size of screen      */

    height = textheight( "H" );
    setArea(&treeArea,  1, height+4, MaxX-2, MaxY-(height+4)-height*5-8);
    setArea(&textArea,  1, MaxY-height*5-4, MaxX-2, height*3);
    setArea(&inputArea, 1, MaxY-height*2 , MaxX-2, height*2);
}
void DrawBorder(void){
  struct viewporttype vp;
  setcolor( MaxColors - 1 );		/* Set current color to white	*/
  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
  getviewsettings( &vp );  /* 获得关于现行窗口的信息 */
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}
void MainWindow( char *header ){
    int height;
    cleardevice();            /* Clear graphics screen    */
    setcolor( MaxColors - 1 );        /* Set current color to white   */
    setviewport( 0, 0, MaxX, MaxY, 1 );   /* Open port to full screen */
    height = textheight( "H" );           /* Get basic text height        */
    /*changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );*/
    settextjustify( CENTER_TEXT, TOP_TEXT );
    outtextxy( MaxX/2, 2, header );
    setviewport( treeArea.x, treeArea.y, treeArea.right, treeArea.bottom , 1 );
    DrawBorder();

    setviewport( textArea.x, textArea.y, textArea.right, textArea.bottom , 1 );
    DrawBorder();

    setviewport( inputArea.x, inputArea.y, inputArea.right, inputArea.bottom , 1 );
    DrawBorder();
    setviewport( inputArea.x, inputArea.y, inputArea.right, inputArea.bottom , 1 );
}

void StatusLine(char *msg )
{
    int height;
    Area *area = &textArea;

    setviewArea(area,1);	/* Open port to full screen	*/
    clearviewport();
    DrawBorder();

    setcolor( MaxColors - 1 );		/* Set current color to white	*/
    /*changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );*/
    settextjustify( LEFT_TEXT, TOP_TEXT );
    /*setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
    setfillstyle( EMPTY_FILL, 0 );*/
    height = textheight( "H" );           /* Detemine current height      */
    /*bar( 0, MaxY-(height+4), MaxX, MaxY );*/
    /*rectangle( 0, MaxY-(height+4), MaxX, MaxY );*/
    /*printf("%s\n", msg);*/
    outtextxy( 4, 4, msg );
    /*setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );*/
}

int gprintf( int *xloc, int *yloc, char *fmt, ... )
{
    va_list  argptr;			/* Argument list pointer	*/
    char str[140];			/* Buffer to build sting into	*/
    int cnt;	  			/* Result of SPRINTF for return */
    settextjustify( LEFT_TEXT, TOP_TEXT );
    va_start( argptr, format );		/* Initialize va_ functions	*/
    cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
    outtextxy( *xloc, *yloc, str );	/* Send string in graphics mode */
    /**yloc += textheight( "H" ) + 2;*/
    /* Advance to next line         */
    /**xloc += cnt*textheight( "H" );*/
    va_end( argptr );			/* Close va_ functions		*/
    return( cnt );			/* Return the conversion count	*/
}

void Exit(){
    closegraph();
}
void StartMenu(){
    cleardevice();
    setcolor(GREEN);
    circle(320, 240, 98);

    circle(320, 240, 98);
    setlinestyle(0, 0, 1);   /*设置三点宽实线*/

    setcolor(2);
    rectangle(220, 140, 420, 340);
    setcolor(WHITE);
    setlinestyle(4, 0xaaaa, 1);   /*设置一点宽用户定义线*/
    line(220, 240, 420, 240);
    line(320, 140, 320, 340);
    delay(111);
}

int inputTop = 0;
char inputBuffer[80];

char* input(){
    char c;
    char *s;
    int x=4,y=4;
    settextjustify( LEFT_TEXT, TOP_TEXT );
    setcolor(15);

    memset(inputBuffer,0,sizeof(inputBuffer));
    inputTop = 0;
    while(1){
        /*s = gets();*/
        c = getch();
        if(c==8 && inputTop>0){
            inputTop--;
            inputBuffer[inputTop] = 0;
        }else if(c>=32 && c<=126 && inputTop<80){
            inputBuffer[inputTop] = c;
            inputTop++;
        }

        setviewArea(&inputArea,1);
        clearviewport();
        DrawBorder();
        if(c == 13){
            inputTop = 0;
            break;
        }
        gprintf(&x,&y,inputBuffer);
    }
    return inputBuffer;
}
void terminal(){
    char *s;
    while(1){
        s = input();
        if(strcmp(s,"exit")==0){
            break;
        }

        StatusLine("");
    }

}
main(){
    Initialize();
    StartMenu();
    StartMenu();
    MainWindow("SuTree");
    terminal();

    Exit();
}
