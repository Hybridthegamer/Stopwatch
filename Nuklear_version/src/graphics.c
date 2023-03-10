/* StopWatch */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"
#include "nuklear.h"
#include "nuklear_glfw_gl3.h"

#include "timeFunctions.h"

/*#define NK_ASSERT*/


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 150

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024


/* ===============================================================
 *
 *                          Stopwatch
 *
 * ===============================================================*/

static void error_callback(int e, const char *d)
{printf("Error %d: %s\n", e, d);}

extern bool isStarted, isPaused;

void displayWindow(void)
{
    /* Platform */
    static GLFWwindow *win;
    int width = 0, height = 0;
    struct nk_context *ctx;
    

    /* GLFW */
    struct nk_glfw glfw = {0};
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Stopwatch", NULL, NULL);
    glfwMakeContextCurrent(win);
    glfwGetWindowSize(win, &width, &height);

    /* OpenGL or GLEW*/
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glewExperimental = 1;
    if (glewInit() != GLEW_OK) 
    {
        fprintf(stderr, "Failed to setup GLEW\n");
        exit(1);
    }

    /* Nuklear context initiation */
    ctx = nk_glfw3_init(&glfw, win, NK_GLFW3_INSTALL_CALLBACKS);

    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */
    {struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&glfw, &atlas);
    /*struct nk_font *droid = nk_font_atlas_add_from_file(atlas, "../../../extra_font/DroidSans.ttf", 14, NULL);*/
    nk_glfw3_font_stash_end(&glfw);
    /*nk_style_set_font(ctx, &droid->handle);*/}



    while (!glfwWindowShouldClose(win))
    {
        /* Time logic */
        /*date = getTimeAndDate();*/

        /* Input */
        glfwPollEvents();
        nk_glfw3_new_frame(&glfw);

        /* GUI */
        if (nk_begin(ctx, "Stopwatch", nk_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), 0))
        {
            /* Layout for clock time  */
            nk_layout_row_dynamic(ctx, 0, 1);
            nk_label(ctx, getTimeAndDate(), NK_TEXT_CENTERED);

            /* Layout for buttons */
            nk_layout_row_dynamic(ctx, 30, 2);
            if(isStarted == false) {
                if (nk_button_label(ctx, "Start")) {
                    /*fprintf(stdout, "Start\n");*/
                    stopWatchStart();
                }
            }
            else {
                if (nk_button_label(ctx, "Stop")) {
                    /*fprintf(stdout, "Stop\n");*/
                    stopWatchStop();
                }
            }

            if( isPaused == false) {
                if(nk_button_label(ctx, "Pause")) {
                    /*fprintf(stdout, "Pause\n");*/
                    stopWatchPause();
                }
            }
            else {
                if (nk_button_label(ctx, "Unpause")) {
                    /*fprintf(stdout, "Unpause");*/
                    stopWatchUnpause();
                }
            }
            
            /* Layout for stopWatch time */
            nk_layout_row_dynamic(ctx, 0, 1);
            nk_label(ctx, stopWatchUpdate(), NK_TEXT_CENTERED);
            
           
        }
        nk_end(ctx);

        /* Draw function calls for OpenGl */
        glfwGetWindowSize(win, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* IMPORTANT: `nk_glfw_render` modifies some global OpenGL state
         * with blending, scissor, face culling, depth test and viewport and
         * defaults everything back into a default state.
         * Make sure to either a.) save and restore or b.) reset your own state after
         * rendering the UI. */
        nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
        glfwSwapBuffers(win);
    }
    nk_glfw3_shutdown(&glfw);
    glfwTerminate();
}