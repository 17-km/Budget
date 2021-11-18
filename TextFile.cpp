#include "TextFile.h"

TextFile::TextFile(string fileName)
    : FILE_NAME(fileName){}

bool TextFile::isFileEmpty(CMarkup file)
{
    if (file.GetDoc() == "")
        return true;
    else
        return false;
}
