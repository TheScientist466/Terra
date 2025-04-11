#include <SFML/Graphics.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

bool showDemoWindow = false;

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 900}), "Terra", sf::Style::Close);
    window.setFramerateLimit(60);
    if(!ImGui::SFML::Init(window)) {
        return -1;
    }
    
    sf::Clock deltaClock;
    while(window.isOpen()) {
        while(const std::optional event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        sf::Time deltaTime = deltaClock.restart();
        ImGui::SFML::Update(window, deltaTime);

        ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SetWindowSize({800, 200});
        ImGui::SetWindowPos({0, 700});
        ImGui::Checkbox("Show Debug Window", &showDemoWindow);
        ImGui::End();

        if(showDemoWindow) {
            ImGui::ShowDemoWindow();
        }

        window.clear();

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}
