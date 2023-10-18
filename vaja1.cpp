#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

int main() {
    glm::vec4 result = 2.0f * glm::vec4(0.5f, 0.7f, 0.9f, 1.0f) * glm::mat4(
        glm::vec4(cos(glm::radians(30.0f)), 0.0f, 0.0f, 0.0f),
        glm::vec4(0.0f, 1.0f, sin(glm::radians(30.0f)), 0.0f),
        glm::vec4(0.0f, -sin(glm::radians(30.0f)), cos(glm::radians(30.0f)), 0.0f),
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );

    std::cout << "Result: " << result.x << " " << result.y << " " << result.z << " " << result.w << std::endl;

    //2
    float n = 2.0f;
    glm::vec4 vectorStart(2.0f * n, 4.0f * n, 8.0f * n, 16.0f * n);
    glm::vec4 vectorEnd(pow(n, 3), pow(n, 2), pow(n, 1), pow(n, 0));
    glm::mat4 forFirstBracket(0.0f);
    glm::mat4 forSecondBracket(0.0f);
    glm::mat4 forThirdBracket(0.0f);

    for (float i = 1; i <= std::pow(n, 4); i++) {
        glm::mat4 firstMatrix = glm::mat4(
            glm::vec4(0.5f, 0.0f, i, 0.0f),
            glm::vec4(0.0f, i, 0.0f, 0.0f),
            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
            glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );
        forFirstBracket += firstMatrix;
    }

    for (float i = 1; i <= std::pow(n, 2); i++) {
        glm::mat4 originalMatrix = glm::mat4(
            glm::vec4(1.0f, 0.0f, i, 0.0f),
            glm::vec4(0.0f, i, pow(i, 4), 0.0f),
            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
            glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );

        glm::mat4 invertedMatrix = glm::inverse(originalMatrix);
        forSecondBracket += invertedMatrix;
    }

    for (float i = 1; i <= n; i++) {
        glm::mat4 thirdMatrix = glm::mat4(
            glm::vec4(0.0f, i, 0.0f, 0.0f),
            glm::vec4(0.0f, pow(i, 1), 0.0f, 0.0f),
            glm::vec4(0.0f, 0.0f, std::pow(i, 2), 0.0f),
            glm::vec4(0.0f, i, 0.0f, pow(i, 3))
        );
        forThirdBracket *= thirdMatrix;
    }

    glm::vec4 intermediateResult;
    for (int i = 0; i < 4; i++) {
        intermediateResult[i] = glm::dot(forThirdBracket[i], vectorEnd);
    }

    glm::vec4 finalResult = vectorStart * intermediateResult;
    glm::vec4 result2 = finalResult;
    std::cout << "Results: " << glm::to_string(result2);

    return 0;
}

