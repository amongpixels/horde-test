/*
 * main.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: dragomir
 */

#include <irrlicht.h>

using namespace irr;

int main(int argc, char **argv) {

  IrrlichtDevice * device = createDevice(
      video::EDT_OPENGL, dimensions2d<unsigned int>(640, 480), 32, false, false, false, 0);

  if (!device) {
    return 1;
  }



}



