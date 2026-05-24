#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>

#include "Marker.h"
#include "converter.h"
#include "engine.h"

// CUSTOM EXCEPTION: Demonstrating inheritance and polymorphism
class MarkdownException : public std::exception {
private:
    std::string message;
public:
    MarkdownException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    engine mdEngine;
    std::vector<Converter*> converters;
    

    converters.push_back(new Bold_beg_conv());
    converters.push_back(new Bold_end_conv());
    converters.push_back(new Italic_beg_conv());
    converters.push_back(new Italic_end_conv());
    converters.push_back(new Strike_beg_conv());
    converters.push_back(new Strike_end_conv());
    converters.push_back(new H3_beg_conv());
    converters.push_back(new H3_end_conv());
    converters.push_back(new H2_beg_conv());
    converters.push_back(new H2_end_conv());
    converters.push_back(new H1_beg_conv());
    converters.push_back(new H1_end_conv());
    
    try {
        std::cout << "--- Starting Markdown Converter ---" << std::endl;
        
        // 1. FILE READING (File Management)
        std::ifstream inputFile("/Users/andrasvasko/megafeltoltes/prog/BME BOP2/Nagyházi/input.md");
        if (!inputFile.is_open()) {
            throw MarkdownException("Failed to open 'input.md'! (Create an input.md file in the folder!)");
        }
        
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string text = buffer.str();
        inputFile.close();
        
        if (text.empty()) {
            throw MarkdownException("The 'input.md' file is empty!");
        }

        // 2. TEXT PROCESSING
        mdEngine.createmap(text, converters);
        mdEngine.checkmap(); 
        
        // 3. FILE WRITING (File Management)
        std::ofstream outputFile("output.html");
        if (!outputFile.is_open()) {
            throw MarkdownException("Failed to create 'output.html' file!");
        }
        
        mdEngine.print(text, outputFile);
        outputFile.close();
        
        std::cout << "Success! The converted text has been saved to 'output.html'." << std::endl;
        
    } catch (const MarkdownException& e) {
        std::cerr << "\n[CUSTOM EXCEPTION CAUGHT] " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\n[SYSTEM ERROR] " << e.what() << "\n";
    }
    
    // DYNAMIC MEMORY DEALLOCATION (Mandatory requirement)
    for (Converter* c : converters) {
        delete c;
    }
    converters.clear();
    
    return 0;
}