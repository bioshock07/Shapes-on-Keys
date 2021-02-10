#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<GL/glu.h>

GLint sqr,rect,tri,circle,x_coord1,y_coord1,x_coord2,y_coord2,x_coords1,y_coords1,x_coords2,y_coords2;
GLint screenClear=0,x_coordt1,y_coordt1,x_coordt2,y_coordt2,x_coordt3,R=1,G=1,B=1,zoom_in,zoom_out,radius;
int up,down,left,right;
float cx,cy;

void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);//sets background color
	glPointSize(5.0);//sets the pixel or point size
	glMatrixMode( GL_PROJECTION );//sets the mode for projection
	glLoadIdentity();//loads the Identity matrix
	gluOrtho2D(0,1350,0,750);	//L R B U for clipping Window
}

void draw_text(char *text,float x ,float y)
{
	int i;
	GLvoid *font_style=GLUT_BITMAP_TIMES_ROMAN_24;
	glRasterPos2f(x,y);
	for(i=0; text[i];i++)
		glutBitmapCharacter(font_style,text[i]);
}

void draw_circle(float cx,float cy,float r,float num_segments)
{
	int i;
	glBegin(GL_LINE_LOOP);
		for(i=0;i<num_segments;i++)
		{
			float theta = 2.0f * 3.1415926f * i/num_segments;//get the current angle
			float x = r *cos(theta);//calculate the x component
			float y = r *sin(theta);//calculate the y component
			glVertex2f(x + cx,y + cy);
		}
	glEnd();
}

/*void Zoom(unsigned char key,int x,int y)
{
	if(key=='i')
	{
		if(tri==1)
		{
			y_coordt1+=50;
			x_coordt2-=50;
			x_coordt3+=50;
		}
		
	}
	
	if(key=='o')
	{
		if(tri==1)
		{
			y_coordt1-=50;
			x_coordt2+=50;
			x_coordt3-=50;
		}
	}
	glutPostRedisplay();
}*/


void Keyboard(unsigned char key,int x,int y)
{
	if(key=='i')
	{
		if(tri==1)
		{
			y_coordt1+=50;
			x_coordt2-=50;
			x_coordt3+=50;
		}
		
		if(circle==1)
		{
			radius+=20;
		}
		
		if(rect==1)
		{
				x_coord1-=100;
				y_coord1+=50;
				x_coord2+=100;
				y_coord2-=50;
		}
		
		if(sqr==1)
		{
				x_coords1-=50;
				y_coords1+=50;
				x_coords2+=50;
				y_coords2-=50;
		}
	}
	
	if(key=='o')
	{
		if(tri==1)
		{
			y_coordt1-=50;
			x_coordt2+=50;
			x_coordt3-=50;
		}
		
		if(circle==1)
		{
			radius-=20;
		}
		
		if(rect==1)
		{
				x_coord1+=100;
				y_coord1-=50;
				x_coord2-=100;
				y_coord2+=50;
		}
		
		if(sqr==1)
		{
				x_coords1+=50;
				y_coords1-=50;
				x_coords2-=50;
				y_coords2+=50;
		}
	}
	
	
	if(key=='1')//circle
	{
		cx=400;
		cy=400;
		radius=100;
		
		circle=1;
		sqr=0;
		rect=0;
		tri=0;
	}
	else
	if(key=='2')//triangle
	{
		x_coordt1=400;
		y_coordt1=500;
		x_coordt2=300;
		y_coordt2=300;
		x_coordt3=500;
				
		circle=0;
		sqr=0;
		rect=0;
		tri=1;
	}
	else
	if(key=='3')//rect
	{
		x_coord1=300;
		y_coord1=500;
		x_coord2=800;
		y_coord2=300;
		
		circle=0;
		sqr=0;
		rect=1;
		tri=0;
	}
	else
	if(key=='4')//sqaure
	{
		x_coords1=300;
		y_coords1=500;
		x_coords2=600;
		y_coords2=200;
			
		circle=0;
		sqr=1;
		rect=0;
		tri=0;
	}
	
	
	glutPostRedisplay();
}


void SpecialInput(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:

			if(tri==1)
			{
 				y_coordt1+=50;
        		y_coordt2+=50;
   			}
   			if( rect == 1)
   			{
        		y_coord1+=50;
        		y_coord2+=50;
        	}
			if( circle == 1)
			{
				//cx+=50;
				cy+=50;
			}
			if( sqr == 1)
			{
				y_coords1+=50;
				y_coords2+=50;
			}
			break;
		
		case GLUT_KEY_DOWN:

			if( rect == 1)
			{
        		y_coord1-=50;
        		y_coord2-=50;
    		}
		    if(tri==1)
		    {
		   		y_coordt1-=50;
				y_coordt2-=50;
			}
			if( circle == 1)
			{
				//cx-=50;
				cy-=50;
			}
			if( sqr == 1)
			{
				y_coords1-=50;
				y_coords2-=50;
			}
			break;
		
		case GLUT_KEY_LEFT:

			if(tri==1)
			{
 				x_coordt1-=50;
        		x_coordt2-=50;
        		x_coordt3-=50;
   			}
   			if( rect == 1)
   			{
        		x_coord1-=50;
        		x_coord2-=50;
        	}
			if( circle == 1)
			{
				cx-=50;
				//xy-=50;
			}
			if( sqr == 1)
			{
				x_coords1-=50;
				x_coords2-=50;
			}
			break;
		
		case GLUT_KEY_RIGHT:

			if(tri==1)
			{
 				x_coordt1+=50;
        		x_coordt2+=50;
        		x_coordt3+=50;
   			}
   			if( rect == 1)
   			{
        		x_coord1+=50;
        		x_coord2+=50;
        	}
			if( circle == 1)
			{
				cx+=50;
				//cy+=50;
			}
			if( sqr == 1)
			{
				x_coords1+=50;
				x_coords2+=50;
			}
			break;
	}
        
	glutPostRedisplay();
} 


void MyDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);//clear the color buffer
	glColor3ub(255,26,200);
	draw_text("TO GET OBJECTS",1000.0,730.0);
	glColor3ub(0,255,255);
	draw_text("Press '1' for Circle",950.0,700.0);
	glColor3ub(0,255,255);
	draw_text("Press '2' for triangle",950.0,670.0);
	glColor3ub(0,255,255);
	draw_text("Press '3' for rectangle ",950.0,640.0);
	glColor3ub(0,255,255);
	draw_text("Press '4' for square",950.0,610.0);
	glColor3ub(0,255,255);
	draw_text("Press up arrow  key for moving  up",950.0,580.0);
	glColor3ub(0,255,255);
	draw_text("Press down arrow key for moving down",950.0,550.0);
	glColor3ub(0,255,255);
	draw_text("Press left arrow key for moving left",950.0,520.0);
	glColor3ub(0,255,255);
	draw_text("Press right arrow key for moving right",950.0,490.0);
	glEnd();
	
	if(sqr==1)//SQUARE
	{
	
		glColor3ub(220,180,55);
		glBegin(GL_QUADS);
			glVertex2i(x_coords1,y_coords1);
			glVertex2i(x_coords2,y_coords1);
			glVertex2i(x_coords2,y_coords2);
			glVertex2i(x_coords1,y_coords2);
		glEnd();
		
		/*glColor3ub(0,0,255);//try blue colour here
		glBegin(GL_QUADS);
			glVertex2i(x_coords1+100,y_coords1-100);
			glVertex2i(x_coords2-100,y_coords1-100);
			glVertex2i(x_coords2-100,y_coords2+100);
			glVertex2i(x_coords1+100,y_coords2+100);
		glEnd();
		*/
		
		
	}
	else
	if(rect==1)
	{
	
		glColor3ub(20,60,190);
		glBegin(GL_QUADS);
			glVertex2i(x_coord1,y_coord1);
			glVertex2i(x_coord2,y_coord1);
			glVertex2i(x_coord2,y_coord2);
			glVertex2i(x_coord1,y_coord2);
		glEnd();
		
		/*glColor3ub(255,0,255);
		glBegin(GL_QUADS);
			glVertex2i(x_coord1+150,y_coord1-50);
			glVertex2i(x_coord2-150,y_coord1-50);
			glVertex2i(x_coord2-150,y_coord2+50);
			glVertex2i(x_coord1+150,y_coord2+50);
		glEnd();
		*/
		
		
	}
	else
	if(tri==1)
	{
		glColor3ub(25,150,149);
		glBegin(GL_TRIANGLES);
			glVertex2i(x_coordt1,y_coordt1);//400,500
			glVertex2i(x_coordt3,y_coordt2);//300,300
			glVertex2i(x_coordt2,y_coordt2);//300,300
		glEnd();
		
		/*glColor3ub(0,255,0);
		glBegin(GL_TRIANGLES);
			glVertex2i(x_coordt1,y_coordt1-75);
			glVertex2i(x_coordt2+150,y_coordt2+25);
			glVertex2i(x_coordt2+50,y_coordt2+25);
		glEnd();
		*/
		
	}
	else
	if(circle==1)
	{
		glColor3ub(255,0,255);
		glBegin(GL_POLYGON);
			draw_circle(cx,cy,radius,100);
		glEnd();
		
		/*glColor3ub(255,0,0);
		glBegin(GL_POLYGON);
			draw_circle(cx,cy,50,100);
		glEnd();
		*/
	}
		
	glFlush();
}

int main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1350,750);
	glutCreateWindow("Shapes on keys");
	glutDisplayFunc(MyDisplay);//specify display function
	glutKeyboardFunc(Keyboard);
	//glutKeyboardFunc(Zoom);
	glutSpecialFunc(SpecialInput);
	myinit();//calling function
	glutMainLoop();//executes events
	return (0);
}

