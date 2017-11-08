// EzInliner -- reading a text file - spitting a new one out
// formats as "[line minus whitespace here]" for dumping shader files into demo frameworks
// Comments left as is for now, may add a comment remover at a later date
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 

using namespace std;

int main(int argc, char* argv[])
{
	std::string line, fPth;
	cout << "--EzInliner shader formatting || csmnt 2017--\n\n";

	if (argc <= 1)
	{
		cout << "--Executed with no files--\n";
		system("pause");
		return 0;
	}
	else
	{
		for (int i(1); i < argc; ++i)
		{
			fPth = argv[i];
			ifstream inFile(fPth);
			if (inFile.is_open())
			{
				ofstream outFile("inline" + to_string(i) + ".txt");
				if (outFile)
				{
					while (getline(inFile, line))
					{
						if (!line.empty())
						{
							line.erase(std::remove_if(line.begin(), line.end(), [](char c) { return (c == '\r' || c == '\t' || c == ' ' || c == '\n'); }), line.end());
							if(line != "")
								outFile << "\"" << line << "\"\n";
						}
					}
					cout << "--All Done! Check \"inline" + to_string(i) + ".txt\".--\n";
				}
				else cout << "--Unable to write to file--\n";
				outFile.close();
			}
			else cout << "--Unable to open file--\n";
			inFile.close();
		}
	}
	system("pause");
	return 0;
}