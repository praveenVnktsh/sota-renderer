// #include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>


class HelloTriangleApp{

    public:
        void run(){
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }
    private:
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
        GLFWwindow* window;
        VkInstance instance;


        void initWindow(){
            glfwInit();
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
            window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        }
        void createInstance(){
            // optional stuff
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;
        }

        void initVulkan(){

            createInstance();

        }

        void mainLoop(){
            while (!glfwWindowShouldClose(window)){
                glfwPollEvents();
            }

        }

        void cleanup(){

            glfwDestroyWindow(window);
            glfwTerminate();

        }
};

int main(){
    HelloTriangleApp app;

    try{
        app.run();
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}