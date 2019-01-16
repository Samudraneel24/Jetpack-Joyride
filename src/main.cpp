#define GLM_ENABLE_EXPERIMENTAL
#include "main.h"
#include "timer.h"
#include "ball.h"
#include "circle.h"
#include "semicircle.h"
#include "rectangle.h"
#include "laser.h"
#include "fire.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Rectangle floorarr[20], Barry;
std::vector<Circle> Coinarr;
std::vector<Laser> L;
std::vector<Fire> F;
int busy = 0, counter = 0, lasercounter = 0, gameover = 0;
int lasercount = 0, firecount = 0;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float aspect_ratio = 1000.0/600.0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye (0, 0, 1);

    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    for(int i=0;i<20;i++)
        floorarr[i].draw(VP);
    Barry.draw(VP);
    for(int i=0;i<Coinarr.size();i++)
        Coinarr[i].draw(VP);
    if(busy == 1)
        L[0].draw(VP);
    if(busy == 2)
        F[0].draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    if (left) {
        // Do something
        if(Barry.position.x >= 0.0)
            Barry.position.x -= 0.1;
    }
    else if(right){
        if(Barry.position.x < 2.5)
            Barry.position.x += 0.1;
        else{
            for(int i=0;i<20;i++){
                floorarr[i].speedx = 0.2;
            }
        }
    }
    else if(up){
        Barry.speedy += 0.01;
    }
}

void tick_elements() {
    bounding_box_t Barrybound;
    Barrybound.x = Barry.position.x;
    Barrybound.y = Barry.position.y;
    Barrybound.height = Barry.width;
    Barrybound.width = Barry.len;
// Enemy
    counter = (counter + 1)%INT_MAX;
    lasercounter++;
    if(counter%600 == 0 && busy == 0 && 3*lasercount <= firecount){
        L.push_back(Laser(4.0 + rand()%5));
        lasercount++;
        busy = 1;
        lasercounter = 0;
    }
    else if(lasercounter == 500 && busy == 1){
        L.erase(L.begin());
        busy = 0;
    }
    if(busy == 1){
        if(L[0].y > Barry.position.y)
            L[0].tick(lasercounter, -1.0);
        else
            L[0].tick(lasercounter, 1.0);
        bounding_box_t Laserbound;
        Laserbound.x = L[0].left + 0.8;
        Laserbound.y = L[0].y;
        Laserbound.height = 0.4;
        Laserbound.width = 9.7;
        if(L[0].on == 1 && detect_collision(Laserbound, Barrybound))
            gameover = 1;
    }
    if(counter%100 == 0 && busy == 0 && firecount <= 3*lasercount){
        float lefty = 1.5 + rand()%3;
        float leftx = 12.0 + rand()%3;
        float rightx = leftx + 1 + rand()%4;
        float righty = lefty + 1 + rand()%4;
        F.push_back(Fire(leftx, lefty, rightx, righty, floorarr[0].speedx, floorarr[0].speedy));
        firecount++;
        busy = 2;
    }
    if(busy == 2){
        F[0].tick(floorarr[0].speedx, floorarr[0].speedy);
        if(F[0].rightx < -1.0){
            F.erase(F.begin());
            busy = 0;
        }
    }

// Floor
    for(int i=0;i<20;i++){
        floorarr[i].tick();
        if(floorarr[i].position.x < -1)
            floorarr[i].position.x += 20;
        if(floorarr[i].speedx > 0.08)
            floorarr[i].speedx -= 0.02;
    }

// Barry
    Barry.tick();
    if(Barry.position.y > 1)
        Barry.speedy -= 0.005;

// Coins
    if(Coinarr.size() == 0){
        float startx = 25 + rand()%5;
        float starty = 6 + rand()%4;
        float rows = 1 + rand()%4;
        float cols = 1 + rand()%8;
        for(int i=0;i<rows;i++)
            for(int j = 0;j<cols;j++){
                Coinarr.push_back(Circle( (startx + j)/2, (starty + i)/2 , 0.2, 0.0, 0.0, COLOR_GOLD));
            }
    }
    for(int i=0;i < Coinarr.size(); i++){
        bounding_box_t Coinbound;
        Coinbound.x = Coinarr[i].position.x-0.2;
        Coinbound.y = Coinarr[i].position.y-0.2;
        Coinbound.height = 0.4;
        Coinbound.width = 0.4;
        if(detect_collision(Coinbound, Barrybound)){
            Coinarr.erase(Coinarr.begin() + i);
            i--;
        }
    }
    for(int i=0;i<Coinarr.size();i++){
        Coinarr[i].speedx = floorarr[0].speedx;
        Coinarr[i].tick();
        if(Coinarr[i].position.x <= -1.0){
            Coinarr.erase(Coinarr.begin() + i);
            i--;
        }
    }
    // camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    float curx = 0.0;
    for(int i=0;i<20;i++){
        if(i%2==0){
            floorarr[i] = Rectangle(curx, 0.0, 1.0, 1.0, 0.0, 0.08, 0.0, COLOR_BLACK);
            curx += 1.0;
        }
        else{
            floorarr[i] = Rectangle(curx, 0.0, 1.0, 1.0, 0.0, 0.08, 0.0, COLOR_SILVER);
            curx += 1.0;
        }
    }
    Barry = Rectangle(2.5, 1.0, 0.5, 1.0, 0.0, 0.0, 0.0, COLOR_BLUE);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int height = 600;
    int width = (float(height)*aspect_ratio);

    window = initGLFW(width, height);

    initGL (window, width, height);
    /* Draw in loop */
    while (gameover == 0 && !glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            // cout<<gameover<<endl;
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 8 / screen_zoom;
    float bottom = screen_center_y;
    float left   = screen_center_x;
    float right  = screen_center_x + ((8*aspect_ratio) / screen_zoom);
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
