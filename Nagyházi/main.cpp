#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>

#include "Marker.h"
#include "converter.h"
#include "engine.h"



int main() {
    engine mdEngine;
    std::vector<Converter*> converters;
    
// Initializing all converters and adding them to the vector
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
   
    
    // File paths for input and output
    std::string inputPath;
    std::string outputPath;
    
    std::cout << "Please enter the input Markdown (.md) file name or path: ";
    std::cin >> inputPath;
    
    std::cout << "Please enter the desired output HTML (.html) file name: ";
    std::cin >> outputPath;
    
    try {
        // Attempt to open the input file and read its contents
        std::ifstream inputFile(inputPath);
        if (!inputFile.is_open()) {
            throw MarkdownException("Could not open the specified input file: '" + inputPath + "'. Please check the file path and try again.");
        }
        // Read the entire file content into a string
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string text = buffer.str();
        inputFile.close();
        // Check if the file is empty
        if (text.empty()) {
            throw MarkdownException("The specified input file is empty!");
        }
        // Process the text with the engine
        mdEngine.createmap(text, converters);
        mdEngine.checkmap(); 
        // Attempt to create and write to the output file
        std::ofstream outputFile(outputPath);
        if (!outputFile.is_open()) {
            throw MarkdownException("Could not create the specified output file: '" + outputPath + "'. Please check the file path and try again.");
        }
        // Print the converted text to the output file
        mdEngine.print(text, outputFile);
        outputFile.close();
        // Inform the user of successful conversion and file creation
        std::cout << "Success! The converted text has been saved to the file: '" << outputPath << "'\n" << std::endl;
        
    } catch (const MarkdownException& e) {
        std::cerr << e.what() << "\n\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n\n";
    }
    
    // Clean up dynamically allocated converters
    for (Converter* c : converters) {
        delete c;
    }
    converters.clear();
    
    return 0;
}