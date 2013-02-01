#include <gtk-3.0/gtk/gtk.h>
#include <irrlicht.h>


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


void * run_interface ( void *ptr );

int main (int argc, char *argv[])
{

  IrrlichtDevice *device = createDevice( video::EDT_OPENGL, dimension2d<unsigned int>(640, 480), 32, false, false, false, 0);

  if (!device) {
    return 1;
  }

  pthread_t thread1;
  int iret1;
  char * chuj2 = "eloeelo";

  iret1 = pthread_create(&thread1, NULL, run_interface, (void*) &chuj2);

  IVideoDriver* driver = device->getVideoDriver();

  while(device->run())
  {
    driver->beginScene(true, true, SColor(255,100,101,140));

    driver->endScene();
  }

  pthread_join( thread1, 0);


  device->drop();

  return 0;
}

void * run_interface ( void *ptr ) {
  GtkWidget *window;

  gtk_init (0, 0);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_show (window);

  gtk_main ();

  return 0;
}
