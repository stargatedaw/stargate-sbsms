#include <iostream>
#include "import.h"
#include "pcm.h"
#include <map>
#include <string>
#include "os.h"

using namespace std;

string lower(string strToConvert)
{
  for(unsigned int i=0;i<strToConvert.length();i++) {
    strToConvert[i] = tolower(strToConvert[i]);
  }
  return strToConvert;
}

AudioDecoder *import(const PATHCHAR *filename)
{
  int len = PATHLEN(filename);
  if(
#ifdef IS_WINDOWS
    (len >= 5 && !PATHCMP(&filename[len - 4], L".wav"))
    ||
    (len >= 5 && !PATHCMP(&filename[len - 4], L".aif"))
    ||
    (len >= 6 && !PATHCMP(&filename[len - 5], L".aiff"))
#else
    (len >= 5 && !PATHCMP(&filename[len - 4], ".wav"))
    ||
    (len >= 5 && !PATHCMP(&filename[len - 4], ".aif"))
    ||
    (len >= 6 && !PATHCMP(&filename[len - 5], ".aiff"))
#endif
  ){
    return new PcmReader(filename);
  } else {
    perror("Error importing file");
    return NULL;
  }
}
