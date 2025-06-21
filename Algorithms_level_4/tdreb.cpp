#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

int main()
{
    fstream MyAlgorithms;
    string FileName;
    for (int i = 1; i < 51; i++)
    {
        FileName = "problem_.cpp";
        FileName.insert(7, to_string(i));
        MyAlgorithms.open(FileName, ios::out);
        MyAlgorithms << "#include <iostream>\n#include <vector>\n#include <string>\n#include <cmath>\n#include <cctype>\n#include <fstream>\n#include \"D:/projects/C++_projects/MyLibrarys/MyLib.h\"\n#include \"D:/projects/C++_projects/MyLibrarys/MathLib.h\"\n#include \"D:/projects/C++_projects/MyLibrarys/InputLib.h\"";
        MyAlgorithms << "\n\nint main()\n{\n\n\treturn 0;\n}";
        MyAlgorithms.close();
    }
    
        
    return 0;
}
