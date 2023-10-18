#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <cmath>

void Menu()
{
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "=========== MENU ===========" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "1 ... MATRIX 1 CALCULATION" << std::endl;
    std::cout << "2 ... MATRIX 2 CALCULATION" << std::endl;
    std::cout << "0 ... EXIT" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Selection: ";
}

float degreesToRadians(float degrees)
{
    return glm::radians(degrees);
}

int main()
{
    bool running = 1;
    int selection = 0;

    do{
        Menu();
        std::cin >> selection;
        switch (selection)
        {
            case 1:
            {
                float n = 2.0f;
                glm::vec4 singleColumnVector(0.5f, 0.7f, 0.9f, 1.0f);
                glm::mat4 firstMatrix = glm::mat4(
                        glm::vec4(cos(degreesToRadians(30)), 0.0f, 0.0f, 0.0f),
                        glm::vec4(0.0f, 1.0f, sin(degreesToRadians(30)), 0.0f),
                        glm::vec4(0.0f, -sin(degreesToRadians(30)), cos(degreesToRadians(30)), 0.0f),
                        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
                );

                glm::vec4 result = n * (singleColumnVector * firstMatrix);

                const float *resultPtr = glm::value_ptr(result);

                std::cout << "Results: ";
                for (int i = 0; i < 4; i++)
                {
                    std::cout << resultPtr[i] << " ";
                }
                break;
            }
            case 2: {
                float n = 2.0f;

                glm::vec4 singleColumnVector(2.0f * n, 4.0f * n, 8.0f * n, 16.0f * n);

                glm::vec4 singleColumnVector2(pow(n, 3), pow(n, 2), pow(n, 1), pow(n, 0));

                glm::mat4 accumulatedMatrixSum1(0.0f);

                for (float i = 1; i <= std::pow(n, 4); i++)
                {
                    glm::mat4 firstMatrix = glm::mat4(
                            glm::vec4(0.5f, 0.0f, i, 0.0f),
                            glm::vec4(0.0f, i, 0.0f, 0.0f),
                            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
                            glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
                    );

                    accumulatedMatrixSum1 = accumulatedMatrixSum1 + firstMatrix;
                }
                std::cout << "matrix1: " << glm::to_string(accumulatedMatrixSum1) << std::endl;

                glm::mat4 accumulatedMatrixSum2(0.0f);

                for (float i = 1; i <= std::pow(n, 2); i++)
                {
                    glm::mat4 originalMatrix = glm::mat4(
                            glm::vec4(1.0f, 0.0f, i, 0.0f),
                            glm::vec4(0.0f, i, pow(i,4), 0.0f),
                            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
                            glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
                    );

                    glm::mat4 invertedMatrix = glm::inverse(originalMatrix);

                    accumulatedMatrixSum2 = accumulatedMatrixSum2 + invertedMatrix;
                }

                std::cout << "matrix2: " << glm::to_string(accumulatedMatrixSum2) << std::endl;

                glm::mat4 accumulatedMatrixProduct(1.0f);

                for (float i = 1; i <= n; i++)
                {
                    glm::mat4 firstMatrix = glm::mat4(
                            glm::vec4(0.0f, i, 0.0f, 0.0f),
                            glm::vec4(0.0f, pow(i, 1), 0.0f, 0.0f),
                            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
                            glm::vec4(0.0f, i, 0.0f, pow(i, 3))
                    );

                    accumulatedMatrixProduct = accumulatedMatrixProduct * firstMatrix;
                }

                std::cout << "matrix3: " << glm::to_string(accumulatedMatrixProduct) << std::endl;

                glm::vec4 resultLeft = singleColumnVector * accumulatedMatrixSum1;
                std::cout << "resultLeft: " << glm::to_string(resultLeft) << std::endl;

                glm::mat4 resultIn = accumulatedMatrixSum2 + accumulatedMatrixProduct;
                std::cout << "resultIn: " << glm::to_string(resultIn) << std::endl;

                glm::vec4 resultRight =  resultIn * singleColumnVector2;
                std::cout << "resultRight: " << glm::to_string(resultIn) << std::endl;

                glm::vec4 result = resultRight * resultLeft;
                std::cout << "result: " << glm::to_string(result);
            }
            case 0:
            {
                running = false;
                break;
            }
            default:
            {
                std::cout << "Wrong selection!" << std::endl;
                break;
            }
        }
    }while(running);

    return 0;
}

