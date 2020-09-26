#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <iostream>

static void error_callback(int error, const char *description) {
  std::cerr << "Error: " << description << std::endl;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int, char **) {
  glm::vec3 a(1, 2, 3);
  glm::vec3 b(4, 5, 6);

  if (!glfwInit()) {
    std::cerr << "glfwInit failed!" << std::endl;
    std::cin.sync();
    std::cin.get();
    return EXIT_FAILURE;
  }

  GLFWwindow *window;
  GLuint vertex_buffer, normal_buffer, index_buffer, u_buffer;
  GLuint vertex_shader, fragment_shader, program;
  GLint mv_location, p_location, pos_location, normal_location, u_location;

  glfwSetErrorCallback(error_callback);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(1920, 1080, "Simple example", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  std::cout << "Hello, world!\n"
            << glm::dot(a, b);

  while (!glfwWindowShouldClose(window)) {
    int width, height;
    glm::mat4 m, v, p, mvp;

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}
