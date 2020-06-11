/**
 *  Generates a folder with the name given in argument.
 *  The folder will always contain three files named
 *  - filename.html
 *  - filename.js
 *  - filename.css (in case you need to add css)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <regex>

using namespace std;

string readSampleHtml();
string modify_html(string filename, string buffer);
void create_html_file(string filename, string buffer);
void create_js_file(string filename);
void create_css_file(string filename);

int main(int argc, char **argv)
{
    // if no or more than one filename is given or the filename contains .
    if (argc != 2 || regex_match(argv[1], regex(".*\\..*")))
    {
        cout << "Please provide filename without extension." << endl;
        exit(1);
    }

    string filename = argv[1];

    // get the text from the sample html file
    string sampleHtmlBuffer = readSampleHtml();

    string modified_html_buffer = modify_html(filename, sampleHtmlBuffer);

    // create a folder named filename
    string folder_cmd = "mkdir " + filename; 
    system(folder_cmd.c_str());

    create_html_file(filename, modified_html_buffer);
    create_js_file(filename);
    create_css_file(filename);

    return 0;
}

string readSampleHtml()
{
    ifstream sample_html;
    sample_html.open("/mnt/DC84407A844058E2/CS/learning_cs/javascript/js_workspace/playground/htmljsgenerator/sample.html");

    if (!sample_html)
    {
        cout << "File cannot be created" << endl;
        exit(2);
    }

    string buffer;
    while(sample_html)
    {
        string line;
        getline(sample_html, line);
        buffer += line + '\n';
    }

    return buffer;
}


// creates a new html file with filename and content modified as for filename
void create_html_file(string filename, string buffer)
{
    string html_filename = filename + "/" + filename + ".html";
    ofstream html_file(html_filename);

    if (!html_file)
    {
        cout << "Html file cannot be created" << endl;
        exit(3);
    }

    html_file << buffer;
}

void create_js_file(string filename)
{
    string js_filename = filename + "/" + filename + ".js";
    ofstream js_file(js_filename);
    if (!js_file)
    {
        cout << "Javascript file cannot be created" << endl;
        exit(4);
    }
}

void create_css_file(string filename)
{
    string css_filename = filename + "/" + filename + ".css";
    ofstream css_file(css_filename);
}

// modifies the string to required format that is with title changed and script and stylesheet link changed
string modify_html(string filename, string buffer)
{
    string keyword = "filename";
    int keyword_len = keyword.length();

    int pos;
    while((pos = buffer.find(keyword)) != string :: npos)
    {
        buffer.replace(pos, keyword_len, filename);
    }

    return buffer;
}