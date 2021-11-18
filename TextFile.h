#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "Markup.h"

using namespace std;

class TextFile
{
protected:
    const string FILE_NAME;
    bool isFileEmpty(CMarkup file);

public:
    TextFile(string fileName);

};

#endif // TEXTFILE_H
