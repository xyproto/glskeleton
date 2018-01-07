/**
 * glError.cpp
 * Contributors:
 *      * Arthur Sonzogni (author)
 * Licence:
 *      * MIT
 */
#include <iostream>
#include <string>

#include <GL/glew.h>

#include "glError.hpp"

using std::cerr;
using std::endl;
using std::string;

void glCheckError(const char* file, unsigned int line) {
  GLenum errorCode = glGetError();

  while (errorCode != GL_NO_ERROR) {
    string fileString(file);
    string error = "unknown error";

    switch (errorCode) {
      case GL_INVALID_ENUM:
        error = "GL_INVALID_ENUM";
        break;
      case GL_INVALID_VALUE:
        error = "GL_INVALID_VALUE";
        break;
      case GL_INVALID_OPERATION:
        error = "GL_INVALID_OPERATION";
        break;
      case GL_STACK_OVERFLOW:
        error = "GL_STACK_OVERFLOW";
        break;
      case GL_STACK_UNDERFLOW:
        error = "GL_STACK_UNDERFLOW";
        break;
      case GL_OUT_OF_MEMORY:
        error = "GL_OUT_OF_MEMORY";
        break;
    }

    cerr << "OpenglError : file=" << file << " line=" << line
         << " error:" << error << endl;
    errorCode = glGetError();
  }
}
